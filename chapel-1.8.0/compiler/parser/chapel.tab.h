/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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
/* Tokens.  */
#define TIDENT 258
#define IMAGLITERAL 259
#define INTLITERAL 260
#define REALLITERAL 261
#define STRINGLITERAL 262
#define EXTERNCODE 263
#define TALIGN 264
#define TATOMIC 265
#define TBEGIN 266
#define TBREAK 267
#define TBY 268
#define TCLASS 269
#define TCOBEGIN 270
#define TCOFORALL 271
#define TCONFIG 272
#define TCONST 273
#define TCONTINUE 274
#define TDELETE 275
#define TDMAPPED 276
#define TDO 277
#define TDOMAIN 278
#define TELSE 279
#define TENUM 280
#define TEXPORT 281
#define TEXTERN 282
#define TFOR 283
#define TFORALL 284
#define TIF 285
#define TIN 286
#define TINDEX 287
#define TINLINE 288
#define TINOUT 289
#define TITER 290
#define TLABEL 291
#define TLAMBDA 292
#define TLET 293
#define TLOCAL 294
#define TMINUSMINUS 295
#define TMODULE 296
#define TNEW 297
#define TNIL 298
#define TON 299
#define TOTHERWISE 300
#define TOUT 301
#define TPARAM 302
#define TPLUSPLUS 303
#define TPRAGMA 304
#define TPRIMITIVE 305
#define TPROC 306
#define TRECORD 307
#define TREDUCE 308
#define TREF 309
#define TRETURN 310
#define TSCAN 311
#define TSELECT 312
#define TSERIAL 313
#define TSINGLE 314
#define TSPARSE 315
#define TSUBDOMAIN 316
#define TSYNC 317
#define TTHEN 318
#define TTYPE 319
#define TUNDERSCORE 320
#define TUNION 321
#define TUSE 322
#define TVAR 323
#define TWHEN 324
#define TWHERE 325
#define TWHILE 326
#define TYIELD 327
#define TZIP 328
#define TALIAS 329
#define TAND 330
#define TASSIGN 331
#define TASSIGNBAND 332
#define TASSIGNBOR 333
#define TASSIGNBXOR 334
#define TASSIGNDIVIDE 335
#define TASSIGNEXP 336
#define TASSIGNLAND 337
#define TASSIGNLOR 338
#define TASSIGNMINUS 339
#define TASSIGNMOD 340
#define TASSIGNMULTIPLY 341
#define TASSIGNPLUS 342
#define TASSIGNSL 343
#define TASSIGNSR 344
#define TBAND 345
#define TBNOT 346
#define TBOR 347
#define TBXOR 348
#define TCOLON 349
#define TCOMMA 350
#define TDIVIDE 351
#define TDOT 352
#define TDOTDOT 353
#define TDOTDOTDOT 354
#define TEQUAL 355
#define TEXP 356
#define TGREATER 357
#define TGREATEREQUAL 358
#define THASH 359
#define TLESS 360
#define TLESSEQUAL 361
#define TMINUS 362
#define TMOD 363
#define TNOT 364
#define TNOTEQUAL 365
#define TOR 366
#define TPLUS 367
#define TQUESTION 368
#define TSEMI 369
#define TSHIFTLEFT 370
#define TSHIFTRIGHT 371
#define TSTAR 372
#define TSWAP 373
#define TIO 374
#define TLCBR 375
#define TRCBR 376
#define TLP 377
#define TRP 378
#define TLSBR 379
#define TRSBR 380
#define TNOELSE 381
#define TUMINUS 382
#define TUPLUS 383




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 42 "chapel.ypp"
{
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
}
/* Line 1529 of yacc.c.  */
#line 323 "chapel.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
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
