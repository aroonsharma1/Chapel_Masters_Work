/**************************************************************************
  Copyright (c) 2004-2013, Cray Inc.  (See LICENSE file for more details)
**************************************************************************/


//
// scalarReplace
//
// This pass implements scalar replacement of aggregates.
//

#include "astutil.h"
#include "expr.h"
#include "optimizations.h"
#include "passes.h"
#include "stmt.h"
#include "stringutil.h"
#include "symbol.h"
#include "view.h"

static const bool debugScalarReplacement = false;

// statistics
static int srClass = 0;
static int srClassReplaced = 0;
static int srRecord = 0;
static int srRecordReplaced = 0;

//
// typeVec - a vector of candidate types for scalar replacement
// varSet - a set of candidate variables for scalar replacement
// typeOrder - topological ordering of candidate types
//              e.g. (int, (int, int)) before (int, int)
// typeVarMap - map from types to vectors of variables
// defMap - defMap for varSet
// useMap - useMap for varSet
//
static Vec<ClassType*> typeVec;
static Vec<Symbol*> varSet;
static Map<ClassType*,int> typeOrder;
static Map<ClassType*,Vec<Symbol*>*> typeVarMap;
static Map<Symbol*,Vec<SymExpr*>*> defMap;
static Map<Symbol*,Vec<SymExpr*>*> useMap;

typedef Map<ClassType*,Vec<Symbol*>*> ClassTypeToVecSymbolMap;
typedef MapElem<ClassType*,Vec<Symbol*>*> ClassTypeToVecSymbolMapElem;

//
// compute topological order for types; this functions assumes that
// there are no cycles and that the typeOrder map is initialized to -1
// for all class types
//
static int
computeOrder(ClassType* ct) {
  if (typeOrder.get(ct) != -1)
    return typeOrder.get(ct);

  typeOrder.put(ct, -2);
  int order = 0;
  for_fields(field, ct) {
    if (ClassType* fct = toClassType(field->type)) {
      int fieldOrder = computeOrder(fct);
      if (fieldOrder >= order)
        order = fieldOrder+1;
    }
  }
  typeOrder.put(ct, order);
  return order;
}

//
// comparison function for quick sort of types based on typeOrder map
//
static int
compareTypesByOrder(const void* v1, const void* v2) {
  ClassType* ct1 = *(ClassType**)v1;
  ClassType* ct2 = *(ClassType**)v2;
  int order1 = typeOrder.get(ct1);
  int order2 = typeOrder.get(ct2);
  if (order1 < order2)
    return 1;
  else if (order1 > order2)
    return -1;
  else
    return 0;
}

static bool
removeIdentityDefs(Symbol* sym) {
  bool change = false;

  for_defs(def, defMap, sym) {
    CallExpr* move = toCallExpr(def->parentExpr);
    if (move && move->isPrimitive(PRIM_MOVE)) {
      SymExpr* rhs = toSymExpr(move->get(2));
      if (rhs && def->var == rhs->var) {
        move->remove();
        change = true;
      }
    }
  }
  return change;
}

static bool
removeUnusedClassInstance(Symbol* sym) {
  bool change = false;
  bool unused = !useMap.get(sym) || useMap.get(sym)->n == 0;

  if (!unused) {
    unused = true;
    for_uses(use, useMap, sym) {
      if (use->parentSymbol)
        unused = false;
    }
  }

  if (unused) {
    for_defs(def, defMap, sym) {
      if (def->parentSymbol) {
        CallExpr* move = toCallExpr(def->parentExpr);
        if (move && move->isPrimitive(PRIM_MOVE)) {
          move->remove();
          change = true;
        }
      }
    }
  }
  return change;
}

static bool
unifyClassInstances(Symbol* sym) {
  if (!defMap.get(sym))
    return false;

  SymExpr* rhs = NULL;

  for_defs(def, defMap, sym) {
    if (def->parentSymbol) {
      CallExpr* move = toCallExpr(def->parentExpr);
      if (!move || !move->isPrimitive(PRIM_MOVE))
        return false;
      SymExpr* se = toSymExpr(move->get(2));
      if (!se)
        return false;
      if (rhs && rhs->var != gNil && se->var != gNil)
        return false;
      if (!rhs || se->var != gNil)
        rhs = se;
    }
  }

  if (!rhs)
    return false;

  for_uses(se, useMap, sym) {
    se->var = rhs->var;
    addUse(useMap, se);
  }

  for_defs(def, defMap, sym) {
    def->parentExpr->remove();
  }

  sym->defPoint->remove();
  return true;
}

static bool
scalarReplaceClass(ClassType* ct, Symbol* sym) {

  if (fReportScalarReplace) srClass++;
  //
  // only scalar replace sym if it has exactly one def and that def is
  // an allocation primitive
  //
  Vec<SymExpr*>* defs = defMap.get(sym);
  if (!defs || defs->n != 1)
    return false;
  // As of r21945, if this variable is allocated in this scope, the
  // first definition is the cast to the appropriate type.  The
  // statement previous to that is the allocation.
  CallExpr* move = toCallExpr(defs->v[0]->parentExpr);
  if (!move || !move->isPrimitive(PRIM_MOVE))
    return false;
  CallExpr* cast = toCallExpr(move->get(2));
  if (!cast || !cast->isPrimitive(PRIM_CAST))
    return false;
  CallExpr* prevMove = toCallExpr(move->prev);
  if (!prevMove || !prevMove->isPrimitive(PRIM_MOVE))
    return false;
  CallExpr* alloc = toCallExpr(prevMove->get(2));
  if (!alloc)
    return false;
  if (!
      (alloc->isResolved() &&
       alloc->isResolved()->hasFlag(FLAG_ALLOCATOR)))
    return false;

  //
  // only scalar replace sym if all of the uses are handled primitives
  //
  for_uses(se, useMap, sym) {
    if (se->parentSymbol) {
      CallExpr* call = toCallExpr(se->parentExpr);
      if (!call)
        return false;

      // The use must appear as the first argument in the containing
      // expression.
      if (se != call->get(1))
        return false;
      // The use must be the first argument of one of the following
      // primitives or allocation functions.
      if (!(call->isPrimitive(PRIM_SET_MEMBER) ||
            call->isPrimitive(PRIM_GET_MEMBER) ||
            call->isPrimitive(PRIM_GET_MEMBER_VALUE) ||
            call->isPrimitive(PRIM_SETCID) ||
            // As of r21945, compiler inserted calls to
            // chpl_here_free() have as its first argument a void *
            call->isPrimitive(PRIM_CAST_TO_VOID_STAR) ||
            (call->isResolved() &&
             (call->isResolved()->hasFlag(FLAG_ALLOCATOR) ||
              // TODO: don't know this is necessary as the arg to free
              // is a void *
              call->isResolved()->hasFlag(FLAG_LOCALE_MODEL_FREE)))))
        return false;
    }
  }

  if (fReportScalarReplace) srClassReplaced++;
  //
  // okay, let's scalar replace sym; first, create vars for every
  // field in sym and compute fieldMap to map the fields to these new
  // vars
  //
  SymbolMap fieldMap;
  for_fields(field, ct) {
    SET_LINENO(sym);
    Symbol* var = new VarSymbol(astr(sym->name, "_", field->name), field->type);
    fieldMap.put(field, var);
    sym->defPoint->insertBefore(new DefExpr(var));
    if (sym->hasFlag(FLAG_TEMP))
      var->addFlag(FLAG_TEMP);
    if (ClassType* fct = toClassType(field->type))
      if (Vec<Symbol*>* varVec = typeVarMap.get(fct))
        varVec->add(var);
  }
  sym->defPoint->remove();

  //
  // remove the only def and the allocation
  //
  move->remove();
  prevMove->remove();

  //
  // replace uses of sym with new vars
  //
  for_uses(se, useMap, sym) {
    if (CallExpr* call = toCallExpr(se->parentExpr)) {
     if (call) {
      SET_LINENO(call);
      if (call->isPrimitive(PRIM_GET_MEMBER)) {
        SymExpr* member = toSymExpr(call->get(2));
        SymExpr* use = new SymExpr(fieldMap.get(member->var));
        call->replace(new CallExpr(PRIM_ADDR_OF, use));
        addUse(useMap, use);
      } else if (call->isPrimitive(PRIM_GET_MEMBER_VALUE)) {
        SymExpr* member = toSymExpr(call->get(2));
        SymExpr* use = new SymExpr(fieldMap.get(member->var));
        call->replace(use);
        addUse(useMap, use);
      } else if (call->isPrimitive(PRIM_SETCID) ||
                 // TODO: don't know if this is still needed.  The
                 // PRIM_CAST_TO_VOID_STAR case may take care of it.
                 (call->isResolved() &&
                  call->isResolved()->hasFlag(FLAG_LOCALE_MODEL_FREE))) {
        //
        // we can remove the setting of the cid because it is never
        // used and we are otherwise able to remove the class
        // reference; similarly, if we can otherwise remove the
        // class reference, we can remove the call to free it
        //
        call->remove();
      } else if (call->isPrimitive(PRIM_CAST_TO_VOID_STAR)) {
        CallExpr* parent = toCallExpr(call->parentExpr);
        INT_ASSERT(parent);
        CallExpr* parentNext = toCallExpr(parent->next);
        if (parentNext &&
            parentNext->isResolved() &&
            parentNext->isResolved()->hasFlag(FLAG_LOCALE_MODEL_FREE))
          parentNext->remove();
        parent->remove();
      } else if (call->isPrimitive(PRIM_SET_MEMBER)) {
        SymExpr* member = toSymExpr(call->get(2));
        call->primitive = primitives[PRIM_MOVE];
        call->get(2)->remove();
        call->get(1)->remove();
        SymExpr* def = new SymExpr(fieldMap.get(member->var));
        call->insertAtHead(def);
        addDef(defMap, def);
        if (call->get(1)->typeInfo() == call->get(2)->typeInfo()->refType)
          call->insertAtTail(new CallExpr(PRIM_ADDR_OF, call->get(2)->remove()));
      }
     }
    }
  }

  return true;
}

static bool
scalarReplaceRecord(ClassType* ct, Symbol* sym) {

  if (fReportScalarReplace) srRecord++;
  //
  // only scalar replace sym if all of the defs are handled primitives
  //
  for_defs(se, defMap, sym) {
    if (se->parentSymbol) {
      CallExpr* call = toCallExpr(se->parentExpr);
      if (!call ||
          !call->isPrimitive(PRIM_MOVE) ||
          !(isSymExpr(call->get(2)) ||
            toCallExpr(call->get(2))->isPrimitive(PRIM_GET_MEMBER_VALUE))) {
        return false;
      }
    }
  }

  //
  // only scalar replace sym if all of the uses are handled primitives
  //
  for_uses(se, useMap, sym) {
    if (se->parentSymbol) {
      CallExpr* call = toCallExpr(se->parentExpr);
      if (!call ||
          !((call->isPrimitive(PRIM_SET_MEMBER) && call->get(1) == se) ||
            call->isPrimitive(PRIM_GET_MEMBER) ||
            call->isPrimitive(PRIM_GET_MEMBER_VALUE) ||
            call->isPrimitive(PRIM_MOVE)))
        return false;
    }
  }

  if (fReportScalarReplace) srRecordReplaced++;
  //
  // okay, let's scalar replace sym; first, create vars for every
  // field in sym and compute fieldMap to map the fields to these new
  // vars
  //
  SymbolMap fieldMap;
  for_fields(field, ct) {
    SET_LINENO(sym);
    Symbol* var = new VarSymbol(astr(sym->name, "_", field->name), field->type);
    fieldMap.put(field, var);
    sym->defPoint->insertBefore(new DefExpr(var));
    if (sym->hasFlag(FLAG_TEMP))
      var->addFlag(FLAG_TEMP);
    if (ClassType* fct = toClassType(field->type))
      if (Vec<Symbol*>* varVec = typeVarMap.get(fct))
        varVec->add(var);
  }

  //
  // replace defs of sym with new vars
  //
  for_defs(se, defMap, sym) {
    if (CallExpr* call = toCallExpr(se->parentExpr)) {
      if (call) {
        SET_LINENO(sym);
        INT_ASSERT(call->isPrimitive(PRIM_MOVE));
        Symbol *rhs;
        if (isSymExpr(call->get(2))) {
          rhs = toSymExpr(call->get(2))->var;
        } else if (isCallExpr(call->get(2))) {
          // rhs is a tuple in a record
          CallExpr* oldrhs = toCallExpr(call->get(2));
          INT_ASSERT(toCallExpr(call->get(2))->isPrimitive(PRIM_GET_MEMBER_VALUE));
          SymExpr *a1 = toSymExpr(oldrhs->get(1))->copy();
          SymExpr *a2 = toSymExpr(oldrhs->get(2))->copy();

          // create a temporary to hold a reference to the tuple field
          rhs = newTemp(astr(sym->name, "_"),
                        oldrhs->typeInfo()->symbol->type->refType);
          sym->defPoint->insertBefore(new DefExpr(rhs));

          // get the reference to the field to use for the rhs
          SymExpr *a3 = new SymExpr(rhs);
          call->insertBefore(new CallExpr(PRIM_MOVE, a3,
                               new CallExpr(PRIM_GET_MEMBER, a1, a2)));
          addUse(useMap, a1);
          addUse(useMap, a2);
          addDef(defMap, a3);
        } else {
          rhs = NULL; // to silence compiler warnings
          INT_ASSERT(false);
        }
        for_fields(field, ct) {
          SymExpr* rhsCopy = new SymExpr(rhs);
          SymExpr* use = new SymExpr(fieldMap.get(field));
          call->insertBefore(
            new CallExpr(PRIM_MOVE, use,
              new CallExpr(PRIM_GET_MEMBER_VALUE, rhsCopy, field)));
          addDef(defMap, use);
          addUse(useMap, rhsCopy);
        }
        call->remove();
      }
    }
  }
  sym->defPoint->remove();

  //
  // replace uses of sym with new vars
  //
  for_uses(se, useMap, sym) {
    if (CallExpr* call = toCallExpr(se->parentExpr)) {
      SET_LINENO(sym);
      if (call && call->isPrimitive(PRIM_MOVE)) {
        SymExpr* lhs = toSymExpr(call->get(1));
        for_fields(field, ct) {
          SymExpr* lhsCopy = lhs->copy();
          SymExpr* use = new SymExpr(fieldMap.get(field));
          call->insertBefore(
            new CallExpr(PRIM_SET_MEMBER, lhsCopy, field, use));
          addUse(useMap, use);
          addUse(useMap, lhsCopy);
        }
        call->remove();
      } else if (call && call->isPrimitive(PRIM_GET_MEMBER)) {
        SymExpr* member = toSymExpr(call->get(2));
        SymExpr* use = new SymExpr(fieldMap.get(member->var));
        call->replace(new CallExpr(PRIM_ADDR_OF, use));
        addUse(useMap, use);
      } else if (call && call->isPrimitive(PRIM_GET_MEMBER_VALUE)) {
        SymExpr* member = toSymExpr(call->get(2));
        SymExpr* use = new SymExpr(fieldMap.get(member->var));
        call->replace(use);
        addUse(useMap, use);
      } else if (call && call->isPrimitive(PRIM_SET_MEMBER)) {
        SymExpr* member = toSymExpr(call->get(2));
        call->primitive = primitives[PRIM_MOVE];
        call->get(2)->remove();
        call->get(1)->remove();
        SymExpr* def = new SymExpr(fieldMap.get(member->var));
        call->insertAtHead(def);
        addDef(defMap, def);
        if (call->get(1)->typeInfo() == call->get(2)->typeInfo()->refType)
          call->insertAtTail(new CallExpr(PRIM_ADDR_OF, call->get(2)->remove()));
      }
    }
  }

  return true;
}


static void
debugScalarReplacementFailure(Symbol* var) {
  printf("failed to scalar replace %s[%d]\n", var->cname, var->id);
  printf("defs:\n");
  for_defs(def, defMap, var) {
    if (def->parentSymbol)
      nprint_view(def->getStmtExpr());
  }
  printf("uses:\n");
  for_uses(use, useMap, var) {
    if (use->parentSymbol)
      nprint_view(use->getStmtExpr());
  }
}


void
scalarReplace() {
  if (!fNoScalarReplacement) {

    //
    // initialize typeOrder map and identify types that are candidates
    // for scalar replacement
    //
    forv_Vec(TypeSymbol, ts, gTypeSymbols) {
      ClassType* ct = toClassType(ts->type);
      if (ct) {
        typeOrder.put(ct, -1);
        if (ts->hasFlag(FLAG_ITERATOR_CLASS) ||
            ts->hasFlag(FLAG_ITERATOR_RECORD) ||
            (ts->hasFlag(FLAG_TUPLE) &&
             (ct->fields.length<=scalar_replace_limit))) {
          typeVec.add(ct);
          typeVarMap.put(ct, new Vec<Symbol*>());
          if (ClassType* rct = toClassType(ct->refType))
            typeVarMap.put(rct, new Vec<Symbol*>());
        }
      }
    }

    //
    // compute topological order of types
    //
    forv_Vec(ClassType, ct, typeVec) {
      computeOrder(ct);
    }

    //
    // sort types based on topological order
    //
    qsort(typeVec.v, typeVec.n, sizeof(typeVec.v[0]), compareTypesByOrder);

    //
    // compute typeVarMap and varSet
    //
    forv_Vec(VarSymbol, var, gVarSymbols) {
      if (ClassType* ct = toClassType(var->type)) {
        if (Vec<Symbol*>* varVec = typeVarMap.get(ct)) {
          if (isFnSymbol(var->defPoint->parentSymbol)) {
            varSet.set_add(var);
            varVec->add(var);
          }
        }
      }
    }

    //
    // build def/use maps for candidate variables
    //
    buildDefUseMaps(varSet, defMap, useMap);

    //
    // scalar replace vars as possible and in topological order
    //
    if (debugScalarReplacement)
      printf("\n");
    if (fReportScalarReplace) {
      printf("SCALAR REPLACEMENT (limit=%d): %d types\n",
             scalar_replace_limit, typeVec.n);
    }
    forv_Vec(ClassType, ct, typeVec) {
      if (debugScalarReplacement)
        printf("%d: %s:\n", typeOrder.get(ct), ct->symbol->cname);
      if (ClassType* rct = toClassType(ct->refType)) {
        Vec<Symbol*>* refVec = typeVarMap.get(rct);
        forv_Vec(Symbol, var, *refVec) {
          eliminateSingleAssignmentReference(defMap, useMap, var);
        }
      }
      Vec<Symbol*>* varVec = typeVarMap.get(ct);
      if (isRecord(ct)) {
        forv_Vec(Symbol, var, *varVec) {
          if (var->defPoint->parentSymbol) {
            bool result = scalarReplaceRecord(ct, var);
            if (debugScalarReplacement && !result)
              debugScalarReplacementFailure(var);
          }
        }
      } else {
        bool change;
        do {
          change = false;
          forv_Vec(Symbol, var, *varVec) {
            change |= removeIdentityDefs(var);
            change |= removeUnusedClassInstance(var);
            change |= unifyClassInstances(var);
          }
        } while (change);
        forv_Vec(Symbol, var, *varVec) {
          if (var->defPoint->parentSymbol) {
            bool result = scalarReplaceClass(ct, var);
            if (debugScalarReplacement && !result)
              debugScalarReplacementFailure(var);
          }
        }
      }
    }

    //
    // cleanup
    //
    typeVec.clear();
    varSet.clear();
    typeOrder.clear();
    form_Map(ClassTypeToVecSymbolMapElem, e, typeVarMap) {
      delete e->value;
    }
    typeVarMap.clear();
    freeDefUseMaps(defMap, useMap);

    if (fReportScalarReplace) {
      printf("\tReplaced %d of %d records\n", srRecordReplaced, srRecord);
      printf("\tReplaced %d of %d classes\n", srClassReplaced, srClass);
    }
  }
}
