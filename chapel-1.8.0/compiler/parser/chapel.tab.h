/* A Bison parser, made by GNU Bison 2.5.  */

/* Bison interface for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2011 Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     TIDENT = 258,
     IMAGLITERAL = 259,
     INTLITERAL = 260,
     REALLITERAL = 261,
     STRINGLITERAL = 262,
     EXTERNCODE = 263,
     TALIGN = 264,
     TATOMIC = 265,
     TBEGIN = 266,
     TBREAK = 267,
     TBY = 268,
     TCLASS = 269,
     TCOBEGIN = 270,
     TCOFORALL = 271,
     TCONFIG = 272,
     TCONST = 273,
     TCONTINUE = 274,
     TDELETE = 275,
     TDMAPPED = 276,
     TDO = 277,
     TDOMAIN = 278,
     TELSE = 279,
     TENUM = 280,
     TEXPORT = 281,
     TEXTERN = 282,
     TFOR = 283,
     TFORALL = 284,
     TIF = 285,
     TIN = 286,
     TINDEX = 287,
     TINLINE = 288,
     TINOUT = 289,
     TITER = 290,
     TLABEL = 291,
     TLAMBDA = 292,
     TLET = 293,
     TLOCAL = 294,
     TMINUSMINUS = 295,
     TMODULE = 296,
     TNEW = 297,
     TNIL = 298,
     TON = 299,
     TOTHERWISE = 300,
     TOUT = 301,
     TPARAM = 302,
     TPLUSPLUS = 303,
     TPRAGMA = 304,
     TPRIMITIVE = 305,
     TPROC = 306,
     TRECORD = 307,
     TREDUCE = 308,
     TREF = 309,
     TRETURN = 310,
     TSCAN = 311,
     TSELECT = 312,
     TSERIAL = 313,
     TSINGLE = 314,
     TSPARSE = 315,
     TSUBDOMAIN = 316,
     TSYNC = 317,
     TTHEN = 318,
     TTYPE = 319,
     TUNDERSCORE = 320,
     TUNION = 321,
     TUSE = 322,
     TVAR = 323,
     TWHEN = 324,
     TWHERE = 325,
     TWHILE = 326,
     TYIELD = 327,
     TZIP = 328,
     TALIAS = 329,
     TAND = 330,
     TASSIGN = 331,
     TASSIGNBAND = 332,
     TASSIGNBOR = 333,
     TASSIGNBXOR = 334,
     TASSIGNDIVIDE = 335,
     TASSIGNEXP = 336,
     TASSIGNLAND = 337,
     TASSIGNLOR = 338,
     TASSIGNMINUS = 339,
     TASSIGNMOD = 340,
     TASSIGNMULTIPLY = 341,
     TASSIGNPLUS = 342,
     TASSIGNSL = 343,
     TASSIGNSR = 344,
     TBAND = 345,
     TBNOT = 346,
     TBOR = 347,
     TBXOR = 348,
     TCOLON = 349,
     TCOMMA = 350,
     TDIVIDE = 351,
     TDOT = 352,
     TDOTDOT = 353,
     TDOTDOTDOT = 354,
     TEQUAL = 355,
     TEXP = 356,
     TGREATER = 357,
     TGREATEREQUAL = 358,
     THASH = 359,
     TLESS = 360,
     TLESSEQUAL = 361,
     TMINUS = 362,
     TMOD = 363,
     TNOT = 364,
     TNOTEQUAL = 365,
     TOR = 366,
     TPLUS = 367,
     TQUESTION = 368,
     TSEMI = 369,
     TSHIFTLEFT = 370,
     TSHIFTRIGHT = 371,
     TSTAR = 372,
     TSWAP = 373,
     TIO = 374,
     TLCBR = 375,
     TRCBR = 376,
     TLP = 377,
     TRP = 378,
     TLSBR = 379,
     TRSBR = 380,
     TNOELSE = 381,
     TUMINUS = 382,
     TUPLUS = 383
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 2068 of yacc.c  */
#line 47 "chapel.ypp"

  const char* pch;
  Vec<const char*>* vpch;
  RetTag retTag;
  bool b;
  IntentTag pt;
  Expr* pexpr;
  DefExpr* pdefexpr;
  CallExpr* pcallexpr;
  BlockStmt* pblockstmt;
  Type* ptype;
  EnumType* penumtype;
  FnSymbol* pfnsymbol;
  Flag flag;
  ProcIter procIter;
  FlagSet* flagSet;



/* Line 2068 of yacc.c  */
#line 198 "chapel.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;

#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
} YYLTYPE;
# define yyltype YYLTYPE /* obsolescent; will be withdrawn */
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif

extern YYLTYPE yylloc;

