/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 1



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




/* Copy the first part of user declarations.  */
#line 12 "chapel.ypp"


#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <stdint.h>
#include "lexyacc.h" // all #includes here, for make depend
#include "driver.h"

  static int query_uid = 1;
  int captureTokens;
  char captureString[1024];

 
#define YYLLOC_DEFAULT(Current, Rhs, N)                                 \
  if (N) {                                                              \
        (Current).first_line   = (Rhs)[1].first_line;                   \
        if ((Current).first_line) yystartlineno = (Current).first_line; \
        (Current).first_column = (Rhs)[1].first_column;                 \
        (Current).last_line    = (Rhs)[N].last_line;                    \
        (Current).last_column  = (Rhs)[N].last_column;                  \
        (Current).comment = NULL;                                       \
  } else  {                                                             \
    (Current) = yylloc;                                                 \
  }                                                                     \



/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

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
/* Line 193 of yacc.c.  */
#line 398 "chapel.tab.cpp"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

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


/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 423 "chapel.tab.cpp"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
	     && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss;
  YYSTYPE yyvs;
    YYLTYPE yyls;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   10990

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  129
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  101
/* YYNRULES -- Number of rules.  */
#define YYNRULES  406
/* YYNRULES -- Number of states.  */
#define YYNSTATES  766

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   383

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     6,     9,    11,    14,    16,    19,
      22,    26,    28,    30,    32,    34,    36,    38,    40,    42,
      44,    46,    49,    52,    56,    60,    64,    68,    72,    76,
      79,    83,    87,    90,    94,    98,   100,   105,   110,   115,
     120,   125,   130,   135,   140,   145,   150,   155,   160,   165,
     170,   175,   178,   182,   183,   185,   187,   190,   192,   195,
     199,   201,   203,   205,   207,   209,   211,   214,   220,   224,
     231,   238,   243,   249,   255,   259,   263,   270,   276,   282,
     286,   293,   300,   305,   310,   315,   319,   326,   332,   338,
     339,   342,   346,   349,   356,   364,   365,   367,   369,   371,
     373,   374,   377,   378,   381,   385,   391,   393,   396,   400,
     402,   406,   407,   408,   417,   418,   420,   422,   425,   427,
     430,   431,   432,   442,   446,   452,   454,   457,   459,   461,
     463,   465,   467,   469,   471,   473,   475,   477,   479,   481,
     483,   485,   487,   489,   491,   493,   495,   497,   499,   501,
     503,   505,   507,   509,   511,   513,   515,   517,   519,   521,
     523,   525,   527,   529,   530,   534,   538,   539,   541,   545,
     550,   555,   562,   569,   570,   572,   574,   576,   578,   581,
     584,   586,   588,   590,   591,   593,   595,   597,   598,   600,
     602,   604,   606,   608,   610,   612,   614,   617,   619,   620,
     622,   625,   628,   629,   632,   637,   643,   645,   649,   654,
     659,   662,   667,   668,   671,   674,   679,   684,   689,   690,
     692,   694,   696,   700,   704,   709,   715,   717,   719,   723,
     725,   728,   732,   733,   736,   737,   742,   743,   746,   749,
     751,   756,   761,   768,   770,   771,   773,   775,   779,   784,
     788,   793,   800,   801,   804,   807,   810,   813,   816,   819,
     821,   823,   827,   831,   833,   835,   837,   841,   845,   846,
     848,   850,   854,   858,   862,   866,   868,   870,   872,   874,
     876,   878,   880,   882,   885,   890,   895,   900,   906,   909,
     912,   919,   926,   931,   941,   951,   959,   966,   973,   978,
     988,   998,  1006,  1011,  1018,  1025,  1035,  1045,  1052,  1054,
    1056,  1058,  1060,  1062,  1064,  1066,  1068,  1072,  1073,  1078,
    1080,  1084,  1086,  1090,  1093,  1098,  1100,  1102,  1104,  1106,
    1108,  1110,  1112,  1114,  1119,  1123,  1127,  1130,  1133,  1135,
    1137,  1139,  1141,  1143,  1145,  1147,  1152,  1157,  1162,  1166,
    1170,  1174,  1178,  1183,  1187,  1189,  1191,  1193,  1195,  1199,
    1203,  1207,  1211,  1217,  1221,  1225,  1229,  1233,  1237,  1241,
    1245,  1249,  1253,  1257,  1261,  1265,  1269,  1273,  1277,  1281,
    1285,  1289,  1293,  1297,  1301,  1305,  1309,  1312,  1315,  1318,
    1321,  1324,  1327,  1331,  1335,  1339,  1343,  1347,  1351,  1355,
    1359,  1361,  1363,  1365,  1367,  1369,  1371
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     130,     0,    -1,   131,    -1,    -1,   131,   132,    -1,   135,
      -1,   134,   135,    -1,   132,    -1,   133,   132,    -1,    49,
       7,    -1,   134,    49,     7,    -1,   136,    -1,   137,    -1,
     142,    -1,   143,    -1,   146,    -1,   182,    -1,   144,    -1,
     147,    -1,   150,    -1,   141,    -1,   211,   114,    -1,    10,
     135,    -1,    11,   212,   135,    -1,    12,   138,   114,    -1,
      15,   212,   137,    -1,    19,   138,   114,    -1,    20,   217,
     114,    -1,    36,   139,   135,    -1,    39,   135,    -1,    44,
     217,   140,    -1,    58,   217,   140,    -1,    62,   135,    -1,
      67,   200,   114,    -1,    72,   217,   114,    -1,     1,    -1,
     218,    76,   217,   114,    -1,   218,    87,   217,   114,    -1,
     218,    84,   217,   114,    -1,   218,    86,   217,   114,    -1,
     218,    80,   217,   114,    -1,   218,    85,   217,   114,    -1,
     218,    81,   217,   114,    -1,   218,    77,   217,   114,    -1,
     218,    78,   217,   114,    -1,   218,    79,   217,   114,    -1,
     218,    89,   217,   114,    -1,   218,    88,   217,   114,    -1,
     218,   118,   217,   114,    -1,   218,    82,   217,   114,    -1,
     218,    83,   217,   114,    -1,   120,   121,    -1,   120,   133,
     121,    -1,    -1,   139,    -1,     3,    -1,    22,   135,    -1,
     137,    -1,    55,   114,    -1,    55,   217,   114,    -1,   114,
      -1,   163,    -1,   151,    -1,   156,    -1,   184,    -1,   187,
      -1,    27,     8,    -1,    22,   135,    71,   217,   114,    -1,
      71,   217,   140,    -1,    16,   217,    31,   217,   212,   140,
      -1,    16,   217,    31,   145,   212,   140,    -1,    16,   217,
     212,   140,    -1,    28,   217,    31,   217,   140,    -1,    28,
     217,    31,   145,   140,    -1,    28,   217,   140,    -1,    28,
     145,   140,    -1,    28,    47,   139,    31,   217,   140,    -1,
      29,   217,    31,   217,   140,    -1,    29,   217,    31,   145,
     140,    -1,    29,   217,   140,    -1,   124,   200,    31,   217,
     125,   135,    -1,   124,   200,    31,   145,   125,   135,    -1,
     124,   200,   125,   135,    -1,    73,   122,   200,   123,    -1,
      30,   217,    63,   135,    -1,    30,   217,   137,    -1,    30,
     217,    63,   135,    24,   135,    -1,    30,   217,   137,    24,
     135,    -1,    57,   217,   120,   148,   121,    -1,    -1,   148,
     149,    -1,    69,   200,   140,    -1,    45,   135,    -1,    64,
      57,   200,   120,   148,   121,    -1,   152,   153,   139,   154,
     120,   155,   121,    -1,    -1,    27,    -1,    14,    -1,    52,
      -1,    66,    -1,    -1,    94,   200,    -1,    -1,   155,   142,
      -1,   155,   134,   142,    -1,    25,   139,   120,   157,   121,
      -1,   158,    -1,   157,    95,    -1,   157,    95,   158,    -1,
     139,    -1,   139,    76,   217,    -1,    -1,    -1,    37,   160,
     169,   161,   175,   195,   181,   177,    -1,    -1,    33,    -1,
      26,    -1,    26,   139,    -1,    27,    -1,    27,   139,    -1,
      -1,    -1,   162,   174,   164,   166,   165,   175,   195,   181,
     176,    -1,   173,   167,   168,    -1,   173,   139,    97,   167,
     168,    -1,   139,    -1,    91,   139,    -1,    76,    -1,    90,
      -1,    92,    -1,    93,    -1,    91,    -1,   100,    -1,   110,
      -1,   106,    -1,   103,    -1,   105,    -1,   102,    -1,   112,
      -1,   107,    -1,   117,    -1,    96,    -1,   115,    -1,   116,
      -1,   108,    -1,   101,    -1,   109,    -1,    13,    -1,   104,
      -1,     9,    -1,    87,    -1,    84,    -1,    86,    -1,    80,
      -1,    85,    -1,    81,    -1,    77,    -1,    78,    -1,    79,
      -1,    89,    -1,    88,    -1,   118,    -1,   119,    -1,    -1,
     122,   170,   123,    -1,   122,   170,   123,    -1,    -1,   171,
      -1,   170,    95,   171,    -1,   172,   139,   199,   193,    -1,
     172,   139,   199,   180,    -1,   172,   122,   192,   123,   199,
     193,    -1,   172,   122,   192,   123,   199,   180,    -1,    -1,
      31,    -1,    34,    -1,    46,    -1,    18,    -1,    18,    31,
      -1,    18,    54,    -1,    47,    -1,    54,    -1,    64,    -1,
      -1,    47,    -1,    51,    -1,    35,    -1,    -1,    18,    -1,
      68,    -1,    47,    -1,    64,    -1,   114,    -1,   177,    -1,
     137,    -1,   141,    -1,   113,   139,    -1,   113,    -1,    -1,
     178,    -1,    99,   217,    -1,    99,   179,    -1,    -1,    70,
     217,    -1,   183,   139,   120,   121,    -1,   183,   139,   120,
     133,   121,    -1,    41,    -1,    64,   185,   114,    -1,    17,
      64,   185,   114,    -1,    27,    64,   185,   114,    -1,   139,
     186,    -1,   139,   186,    95,   185,    -1,    -1,    76,   207,
      -1,    76,   196,    -1,   188,    47,   189,   114,    -1,   188,
      18,   189,   114,    -1,   188,    68,   189,   114,    -1,    -1,
      17,    -1,    27,    -1,   190,    -1,   189,    95,   190,    -1,
     139,   195,   193,    -1,   139,   194,    74,   217,    -1,   122,
     192,   123,   195,   193,    -1,    65,    -1,   139,    -1,   122,
     192,   123,    -1,   191,    -1,   191,    95,    -1,   191,    95,
     192,    -1,    -1,    76,   217,    -1,    -1,    94,   124,   200,
     125,    -1,    -1,    94,   207,    -1,    94,   196,    -1,     1,
      -1,   124,   200,   125,   207,    -1,   124,   200,   125,   196,
      -1,   124,   200,    31,   217,   125,   207,    -1,     1,    -1,
      -1,   207,    -1,   178,    -1,   124,   125,   197,    -1,   124,
     200,   125,   197,    -1,   124,   125,   198,    -1,   124,   200,
     125,   198,    -1,   124,   200,    31,   217,   125,   197,    -1,
      -1,    94,   207,    -1,    94,   178,    -1,    94,    23,    -1,
      94,    59,    -1,    94,    62,    -1,    94,   198,    -1,   217,
      -1,   178,    -1,   200,    95,   217,    -1,   200,    95,   178,
      -1,    65,    -1,   217,    -1,   178,    -1,   201,    95,   201,
      -1,   202,    95,   201,    -1,    -1,   204,    -1,   205,    -1,
     204,    95,   205,    -1,   139,    76,   178,    -1,   139,    76,
     217,    -1,   139,    74,   217,    -1,   178,    -1,   217,    -1,
     139,    -1,   210,    -1,   218,    -1,   209,    -1,   226,    -1,
     225,    -1,    59,   217,    -1,    32,   122,   203,   123,    -1,
      23,   122,   203,   123,    -1,    61,   122,   203,   123,    -1,
      60,    61,   122,   203,   123,    -1,    10,   217,    -1,    62,
     217,    -1,    28,   217,    31,   217,    22,   217,    -1,    28,
     217,    31,   145,    22,   217,    -1,    28,   217,    22,   217,
      -1,    28,   217,    31,   217,    22,    30,   217,    63,   217,
      -1,    28,   217,    31,   145,    22,    30,   217,    63,   217,
      -1,    28,   217,    22,    30,   217,    63,   217,    -1,    29,
     217,    31,   217,    22,   217,    -1,    29,   217,    31,   145,
      22,   217,    -1,    29,   217,    22,   217,    -1,    29,   217,
      31,   217,    22,    30,   217,    63,   217,    -1,    29,   217,
      31,   145,    22,    30,   217,    63,   217,    -1,    29,   217,
      22,    30,   217,    63,   217,    -1,   124,   200,   125,   217,
      -1,   124,   200,    31,   217,   125,   217,    -1,   124,   200,
      31,   145,   125,   217,    -1,   124,   200,    31,   217,   125,
      30,   217,    63,   217,    -1,   124,   200,    31,   145,   125,
      30,   217,    63,   217,    -1,    30,   217,    63,   217,    24,
     217,    -1,    43,    -1,   210,    -1,   206,    -1,   221,    -1,
     220,    -1,   159,    -1,   215,    -1,   216,    -1,   214,   119,
     217,    -1,    -1,    54,   122,   213,   123,    -1,   206,    -1,
     213,    95,   206,    -1,   218,    -1,   214,   119,   217,    -1,
      42,   217,    -1,    38,   189,    31,   217,    -1,   223,    -1,
     207,    -1,   208,    -1,   227,    -1,   228,    -1,   159,    -1,
     215,    -1,   216,    -1,   122,    99,   217,   123,    -1,   217,
      94,   217,    -1,   217,    98,   217,    -1,   217,    98,    -1,
      98,   217,    -1,    98,    -1,   206,    -1,   220,    -1,   221,
      -1,   222,    -1,   218,    -1,   159,    -1,   219,   122,   203,
     123,    -1,   219,   124,   203,   125,    -1,    50,   122,   203,
     123,    -1,   217,    97,   139,    -1,   217,    97,    64,    -1,
     217,    97,    23,    -1,   122,   201,   123,    -1,   122,   201,
      95,   123,    -1,   122,   202,   123,    -1,     5,    -1,     6,
      -1,     4,    -1,     7,    -1,   120,   200,   121,    -1,   124,
     200,   125,    -1,   124,   224,   125,    -1,   217,    74,   217,
      -1,   224,    95,   217,    74,   217,    -1,   217,   112,   217,
      -1,   217,   107,   217,    -1,   217,   117,   217,    -1,   217,
      96,   217,    -1,   217,   115,   217,    -1,   217,   116,   217,
      -1,   217,   108,   217,    -1,   217,   100,   217,    -1,   217,
     110,   217,    -1,   217,   106,   217,    -1,   217,   103,   217,
      -1,   217,   105,   217,    -1,   217,   102,   217,    -1,   217,
      90,   217,    -1,   217,    92,   217,    -1,   217,    93,   217,
      -1,   217,    75,   217,    -1,   217,   111,   217,    -1,   217,
     101,   217,    -1,   217,    13,   217,    -1,   217,     9,   217,
      -1,   217,   104,   217,    -1,   217,    21,   217,    -1,   112,
     217,    -1,   107,   217,    -1,    40,   217,    -1,    48,   217,
      -1,   109,   217,    -1,    91,   217,    -1,   217,    53,   217,
      -1,   217,    53,   145,    -1,   229,    53,   217,    -1,   229,
      53,   145,    -1,   217,    56,   217,    -1,   217,    56,   145,
      -1,   229,    56,   217,    -1,   229,    56,   145,    -1,   112,
      -1,   117,    -1,    75,    -1,   111,    -1,    90,    -1,    92,
      -1,    93,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   185,   185,   190,   191,   196,   197,   202,   203,   208,
     209,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   267,   268,   272,   273,   277,   281,   282,   286,   287,
     291,   292,   293,   294,   295,   296,   300,   315,   316,   317,
     318,   319,   320,   321,   322,   323,   324,   325,   326,   327,
     328,   334,   340,   350,   354,   355,   356,   357,   361,   366,
     367,   371,   373,   378,   385,   391,   392,   396,   398,   400,
     404,   405,   410,   411,   413,   418,   428,   435,   439,   447,
     448,   453,   458,   452,   483,   484,   486,   488,   490,   493,
     499,   505,   498,   535,   544,   560,   561,   562,   563,   564,
     565,   566,   567,   568,   569,   570,   571,   572,   573,   574,
     575,   576,   577,   578,   579,   580,   581,   582,   583,   584,
     585,   586,   587,   588,   589,   590,   591,   592,   593,   594,
     595,   596,   597,   601,   602,   606,   610,   611,   612,   616,
     618,   620,   622,   627,   628,   629,   630,   631,   632,   633,
     634,   635,   636,   640,   641,   645,   646,   650,   651,   652,
     653,   654,   658,   659,   663,   664,   668,   670,   675,   676,
     680,   681,   685,   686,   690,   692,   697,   702,   704,   706,
     711,   718,   729,   730,   732,   737,   741,   745,   752,   753,
     754,   758,   759,   767,   769,   775,   780,   782,   784,   789,
     791,   793,   800,   801,   805,   806,   811,   812,   813,   814,
     834,   838,   842,   850,   854,   855,   856,   860,   862,   868,
     870,   872,   877,   878,   879,   880,   881,   882,   883,   889,
     890,   891,   892,   896,   897,   898,   902,   903,   907,   908,
     912,   913,   917,   918,   919,   920,   921,   925,   936,   937,
     938,   939,   940,   941,   943,   945,   947,   949,   951,   953,
     958,   960,   962,   964,   966,   968,   970,   972,   974,   976,
     978,   980,   982,   989,   995,  1001,  1007,  1016,  1021,  1029,
    1030,  1031,  1032,  1033,  1034,  1035,  1036,  1041,  1042,  1046,
    1047,  1051,  1052,  1057,  1062,  1070,  1071,  1072,  1073,  1074,
    1075,  1076,  1077,  1078,  1080,  1082,  1084,  1086,  1088,  1093,
    1094,  1095,  1096,  1107,  1108,  1112,  1113,  1114,  1118,  1119,
    1120,  1128,  1129,  1130,  1134,  1135,  1136,  1137,  1138,  1139,
    1140,  1147,  1148,  1152,  1153,  1154,  1155,  1156,  1157,  1158,
    1159,  1160,  1161,  1162,  1163,  1164,  1165,  1166,  1167,  1168,
    1169,  1170,  1171,  1172,  1173,  1174,  1178,  1179,  1180,  1181,
    1182,  1183,  1187,  1188,  1189,  1190,  1194,  1195,  1196,  1197,
    1202,  1203,  1204,  1205,  1206,  1207,  1208
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TIDENT", "IMAGLITERAL", "INTLITERAL",
  "REALLITERAL", "STRINGLITERAL", "EXTERNCODE", "TALIGN", "TATOMIC",
  "TBEGIN", "TBREAK", "TBY", "TCLASS", "TCOBEGIN", "TCOFORALL", "TCONFIG",
  "TCONST", "TCONTINUE", "TDELETE", "TDMAPPED", "TDO", "TDOMAIN", "TELSE",
  "TENUM", "TEXPORT", "TEXTERN", "TFOR", "TFORALL", "TIF", "TIN", "TINDEX",
  "TINLINE", "TINOUT", "TITER", "TLABEL", "TLAMBDA", "TLET", "TLOCAL",
  "TMINUSMINUS", "TMODULE", "TNEW", "TNIL", "TON", "TOTHERWISE", "TOUT",
  "TPARAM", "TPLUSPLUS", "TPRAGMA", "TPRIMITIVE", "TPROC", "TRECORD",
  "TREDUCE", "TREF", "TRETURN", "TSCAN", "TSELECT", "TSERIAL", "TSINGLE",
  "TSPARSE", "TSUBDOMAIN", "TSYNC", "TTHEN", "TTYPE", "TUNDERSCORE",
  "TUNION", "TUSE", "TVAR", "TWHEN", "TWHERE", "TWHILE", "TYIELD", "TZIP",
  "TALIAS", "TAND", "TASSIGN", "TASSIGNBAND", "TASSIGNBOR", "TASSIGNBXOR",
  "TASSIGNDIVIDE", "TASSIGNEXP", "TASSIGNLAND", "TASSIGNLOR",
  "TASSIGNMINUS", "TASSIGNMOD", "TASSIGNMULTIPLY", "TASSIGNPLUS",
  "TASSIGNSL", "TASSIGNSR", "TBAND", "TBNOT", "TBOR", "TBXOR", "TCOLON",
  "TCOMMA", "TDIVIDE", "TDOT", "TDOTDOT", "TDOTDOTDOT", "TEQUAL", "TEXP",
  "TGREATER", "TGREATEREQUAL", "THASH", "TLESS", "TLESSEQUAL", "TMINUS",
  "TMOD", "TNOT", "TNOTEQUAL", "TOR", "TPLUS", "TQUESTION", "TSEMI",
  "TSHIFTLEFT", "TSHIFTRIGHT", "TSTAR", "TSWAP", "TIO", "TLCBR", "TRCBR",
  "TLP", "TRP", "TLSBR", "TRSBR", "TNOELSE", "TUMINUS", "TUPLUS",
  "$accept", "program", "toplevel_stmt_ls", "toplevel_stmt", "stmt_ls",
  "pragma_ls", "stmt", "assignment_stmt", "block_stmt", "opt_ident",
  "ident", "do_stmt", "return_stmt", "class_level_stmt",
  "extern_block_stmt", "loop_stmt", "zippered_iterator", "if_stmt",
  "select_stmt", "when_stmt_ls", "when_stmt", "type_select_stmt",
  "class_decl_stmt", "opt_extern", "class_tag", "opt_inherit",
  "class_level_stmt_ls", "enum_decl_stmt", "enum_ls", "enum_item",
  "lambda_decl_expr", "@1", "@2", "linkage_spec", "fn_decl_stmt", "@3",
  "@4", "fn_decl_stmt_inner", "fn_ident", "opt_formal_ls", "req_formal_ls",
  "formal_ls", "formal", "opt_intent_tag", "opt_this_intent_tag",
  "proc_or_iter", "opt_ret_tag", "opt_function_body_stmt",
  "function_body_stmt", "query_expr", "opt_query_expr", "var_arg_expr",
  "opt_where_part", "module_decl_stmt", "module", "type_alias_decl_stmt",
  "type_alias_decl_stmt_inner", "opt_init_type", "var_decl_stmt",
  "opt_config", "var_decl_stmt_inner_ls", "var_decl_stmt_inner",
  "tuple_var_decl_component", "tuple_var_decl_stmt_inner_ls",
  "opt_init_expr", "opt_reindex_expr", "opt_type", "array_type",
  "opt_formal_array_elt_type", "formal_array_type", "opt_formal_type",
  "expr_ls", "tuple_component", "tuple_expr_ls", "opt_actual_ls",
  "actual_ls", "actual_expr", "ident_expr", "type_level_expr", "for_expr",
  "cond_expr", "nil_expr", "stmt_level_expr", "opt_ref_var_ls",
  "ref_var_ls", "io_expr", "new_expr", "let_expr", "expr", "lhs_expr",
  "fun_expr", "call_expr", "dot_expr", "parenthesized_expr",
  "literal_expr", "assoc_expr_ls", "binary_op_expr", "unary_op_expr",
  "reduce_expr", "scan_expr", "reduce_scan_op_expr", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,   373,   374,
     375,   376,   377,   378,   379,   380,   381,   382,   383
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   129,   130,   131,   131,   132,   132,   133,   133,   134,
     134,   135,   135,   135,   135,   135,   135,   135,   135,   135,
     135,   135,   135,   135,   135,   135,   135,   135,   135,   135,
     135,   135,   135,   135,   135,   135,   136,   136,   136,   136,
     136,   136,   136,   136,   136,   136,   136,   136,   136,   136,
     136,   137,   137,   138,   138,   139,   140,   140,   141,   141,
     142,   142,   142,   142,   142,   142,   143,   144,   144,   144,
     144,   144,   144,   144,   144,   144,   144,   144,   144,   144,
     144,   144,   144,   145,   146,   146,   146,   146,   147,   148,
     148,   149,   149,   150,   151,   152,   152,   153,   153,   153,
     154,   154,   155,   155,   155,   156,   157,   157,   157,   158,
     158,   160,   161,   159,   162,   162,   162,   162,   162,   162,
     164,   165,   163,   166,   166,   167,   167,   167,   167,   167,
     167,   167,   167,   167,   167,   167,   167,   167,   167,   167,
     167,   167,   167,   167,   167,   167,   167,   167,   167,   167,
     167,   167,   167,   167,   167,   167,   167,   167,   167,   167,
     167,   167,   167,   168,   168,   169,   170,   170,   170,   171,
     171,   171,   171,   172,   172,   172,   172,   172,   172,   172,
     172,   172,   172,   173,   173,   174,   174,   175,   175,   175,
     175,   175,   176,   176,   177,   177,   178,   178,   179,   179,
     180,   180,   181,   181,   182,   182,   183,   184,   184,   184,
     185,   185,   186,   186,   186,   187,   187,   187,   188,   188,
     188,   189,   189,   190,   190,   190,   191,   191,   191,   192,
     192,   192,   193,   193,   194,   194,   195,   195,   195,   195,
     196,   196,   196,   196,   197,   197,   197,   198,   198,   198,
     198,   198,   199,   199,   199,   199,   199,   199,   199,   200,
     200,   200,   200,   201,   201,   201,   202,   202,   203,   203,
     204,   204,   205,   205,   205,   205,   205,   206,   207,   207,
     207,   207,   207,   207,   207,   207,   207,   207,   207,   207,
     208,   208,   208,   208,   208,   208,   208,   208,   208,   208,
     208,   208,   208,   208,   208,   208,   208,   209,   210,   211,
     211,   211,   211,   211,   211,   211,   211,   212,   212,   213,
     213,   214,   214,   215,   216,   217,   217,   217,   217,   217,
     217,   217,   217,   217,   217,   217,   217,   217,   217,   218,
     218,   218,   218,   219,   219,   220,   220,   220,   221,   221,
     221,   222,   222,   222,   223,   223,   223,   223,   223,   223,
     223,   224,   224,   225,   225,   225,   225,   225,   225,   225,
     225,   225,   225,   225,   225,   225,   225,   225,   225,   225,
     225,   225,   225,   225,   225,   225,   226,   226,   226,   226,
     226,   226,   227,   227,   227,   227,   228,   228,   228,   228,
     229,   229,   229,   229,   229,   229,   229
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     0,     2,     1,     2,     1,     2,     2,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     2,     3,     3,     3,     3,     3,     3,     2,
       3,     3,     2,     3,     3,     1,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     2,     3,     0,     1,     1,     2,     1,     2,     3,
       1,     1,     1,     1,     1,     1,     2,     5,     3,     6,
       6,     4,     5,     5,     3,     3,     6,     5,     5,     3,
       6,     6,     4,     4,     4,     3,     6,     5,     5,     0,
       2,     3,     2,     6,     7,     0,     1,     1,     1,     1,
       0,     2,     0,     2,     3,     5,     1,     2,     3,     1,
       3,     0,     0,     8,     0,     1,     1,     2,     1,     2,
       0,     0,     9,     3,     5,     1,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     0,     3,     3,     0,     1,     3,     4,
       4,     6,     6,     0,     1,     1,     1,     1,     2,     2,
       1,     1,     1,     0,     1,     1,     1,     0,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     1,     0,     1,
       2,     2,     0,     2,     4,     5,     1,     3,     4,     4,
       2,     4,     0,     2,     2,     4,     4,     4,     0,     1,
       1,     1,     3,     3,     4,     5,     1,     1,     3,     1,
       2,     3,     0,     2,     0,     4,     0,     2,     2,     1,
       4,     4,     6,     1,     0,     1,     1,     3,     4,     3,
       4,     6,     0,     2,     2,     2,     2,     2,     2,     1,
       1,     3,     3,     1,     1,     1,     3,     3,     0,     1,
       1,     3,     3,     3,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     4,     4,     4,     5,     2,     2,
       6,     6,     4,     9,     9,     7,     6,     6,     4,     9,
       9,     7,     4,     6,     6,     9,     9,     6,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     0,     4,     1,
       3,     1,     3,     2,     4,     1,     1,     1,     1,     1,
       1,     1,     1,     4,     3,     3,     2,     2,     1,     1,
       1,     1,     1,     1,     1,     4,     4,     4,     3,     3,
       3,     3,     4,     3,     1,     1,     1,     1,     3,     3,
       3,     3,     5,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     2,     2,     2,     2,
       2,     2,     3,     3,     3,     3,     3,     3,     3,     3,
       1,     1,     1,     1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       3,     0,     0,     1,    35,    55,   356,   354,   355,   357,
       0,   317,    53,   317,     0,   219,    53,     0,     0,     0,
       0,   116,    96,     0,     0,     0,     0,   115,     0,   111,
       0,     0,     0,   206,     0,   308,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   402,   404,     0,   405,   406,   338,     0,     0,   403,
     400,    60,   401,     0,     0,     0,     4,     0,     5,    11,
      12,   277,    20,    13,    14,    17,    15,    18,    19,    62,
       0,    63,   330,     0,    61,    16,     0,    64,    65,     0,
     339,   326,   327,   280,   278,     0,     0,   331,   332,     0,
     279,     0,   340,   341,   342,   325,   282,   281,   328,   329,
       0,    22,   288,     0,     0,     0,    54,     0,     0,     0,
       0,     0,     0,     0,     0,   330,   339,   278,   331,   332,
     317,   279,   340,   341,     0,     0,     0,     0,   268,     0,
     117,    66,     0,   119,     0,     0,     0,     0,     0,     0,
     268,     0,     0,     0,     0,     0,   221,    29,   388,   323,
       0,   389,     9,   268,    58,     0,     0,     0,   283,     0,
     268,    32,   289,     0,   212,     0,   197,   260,     0,   259,
       0,     0,   391,   337,   387,   390,   386,    51,     7,     0,
       0,   263,     0,   265,     0,     0,   264,     0,   259,     0,
       0,     6,    97,    98,    99,     0,   186,   185,   120,     0,
       0,     0,     0,    21,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   336,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   268,   268,
       0,     0,     0,    23,    24,     0,    25,     0,     0,     0,
       0,     0,     0,     0,    26,    27,     0,   277,   275,     0,
     269,   270,   276,     0,     0,     0,     0,     0,    57,    75,
       0,     0,    74,     0,     0,    79,     0,    85,     0,    28,
     166,   112,   226,     0,   227,   229,     0,   239,     0,     0,
     232,     0,     0,    30,     0,    59,    89,    31,   268,     0,
       0,     0,   210,   207,   196,     0,    33,    68,    34,    52,
       8,   358,     0,     0,   351,     0,   353,     0,     0,     0,
       0,   360,    10,   100,   183,     0,     0,     0,     0,   316,
     383,   382,   385,   393,   392,   397,   396,   379,   376,   377,
     378,   334,   366,   350,   349,   348,   335,   370,   381,   375,
     373,   384,   374,   372,   364,   369,   371,   380,   363,   367,
     368,   365,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   395,
     394,   399,   398,   319,     0,     0,     0,     0,     0,     0,
       0,   359,   317,   317,    71,   208,     0,     0,     0,   285,
       0,   109,     0,   106,   209,     0,     0,    56,     0,   292,
       0,     0,     0,   298,     0,     0,    84,     0,     0,   284,
     177,   174,   175,   176,   180,   181,   182,     0,   167,     0,
     187,     0,   230,     0,   243,     0,   238,   326,     0,     0,
     223,   324,   222,   347,     0,     0,   286,    89,     0,   214,
     326,     0,   262,   261,   333,   352,   266,   267,     0,     0,
      82,   302,   361,     0,     0,     0,   184,   121,     0,   204,
       0,   216,   215,   217,    36,    43,    44,    45,    40,    42,
      49,    50,    38,    41,    39,    37,    47,    46,    48,   345,
     346,     0,   318,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    67,   274,   272,   273,   271,     0,   107,
     105,     0,    83,     0,     0,    73,     0,    72,     0,     0,
      78,     0,    77,     0,     0,    87,   178,   179,   173,   165,
       0,   252,   188,   190,   191,   189,     0,   228,   231,     0,
     232,     0,   224,   233,     0,     0,    88,    90,   287,     0,
       0,   211,     0,     0,     0,   101,   102,   187,   149,   147,
     127,   156,   157,   158,   153,   155,   151,   154,   152,   150,
     160,   159,   128,   131,   129,   130,   141,   132,   145,   137,
     135,   148,   136,   134,   139,   144,   146,   133,   138,   142,
     143,   140,   161,   162,   125,   163,   205,   320,     0,     0,
       0,     0,     0,     0,     0,     0,    70,    69,   110,   108,
      76,     0,     0,   291,     0,   290,     0,     0,   297,     0,
     296,    86,   307,   168,     0,     0,   232,   202,   225,     0,
       0,    92,     0,    93,     0,     0,    81,   304,     0,    80,
     303,   362,    95,     0,   126,     0,   166,   123,     0,     0,
       0,     0,     0,     0,     0,     0,   295,     0,     0,   301,
       0,     0,   252,   255,   256,   257,     0,   254,   258,   326,
     198,   170,   169,     0,     0,     0,   241,   326,    91,     0,
       0,    96,     0,    94,    95,   103,   202,   125,   163,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     232,   244,     0,   199,   201,   200,   203,   194,   195,   113,
       0,     0,     0,   104,     0,   124,   164,     0,     0,     0,
       0,     0,     0,   294,   293,   300,   299,   172,   171,   246,
     247,   249,   326,     0,   359,   326,   306,   305,   192,   122,
     193,     0,   248,   250,   244,   251
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,   188,   189,    67,   436,    69,    70,   115,
      71,   289,    72,    73,    74,    75,   519,    76,    77,   464,
     567,    78,    79,    80,   205,   485,   662,    81,   422,   423,
     125,   152,   450,    83,    84,   344,   577,   487,   615,   667,
     301,   447,   448,   449,   488,   208,   556,   759,   729,   177,
     724,   691,   694,    85,    86,    87,   175,   322,    88,    89,
     155,   156,   305,   306,   460,   309,   310,   456,   750,   688,
     646,   190,   194,   195,   279,   280,   281,   126,    91,    92,
      93,   127,    95,   114,   404,    96,   128,   129,    99,   131,
     101,   132,   133,   104,   105,   199,   106,   107,   108,   109,
     110
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -687
static const yytype_int16 yypact[] =
{
    -687,    83,  2187,  -687,  -687,  -687,  -687,  -687,  -687,  -687,
    3163,   137,    67,   137,  5681,   194,    67,  5681,  3163,   147,
      67,    67,   269,  4897,  5681,  5681,   153,  -687,    67,  -687,
      16,  3163,  5681,  -687,  5681,  -687,  5681,  5681,   191,   157,
    5093,  5681,  5681,  5681,   140,   180,  3163,   159,  5191,  5681,
    5681,  -687,  -687,  5681,  -687,  -687,  6563,  5681,  5681,  -687,
    5681,  -687,  -687,  2431,  4701,  5191,  -687,  3041,  -687,  -687,
    -687,  -687,  -687,  -687,  -687,  -687,  -687,  -687,  -687,  -687,
     248,  -687,   227,   142,  -687,  -687,    67,  -687,  -687,   250,
     150,  -687,  -687,  -687,   198,   199,   200,   228,   238, 10743,
    1595,    61,   240,   245,  -687,  -687,  -687,  -687,  -687,  -687,
      29,  -687, 10743,   252,  3163,   253,  -687,   255,  5681,  5681,
    5681,  5681,  5681,  5191,  5191,    68,  -687,  -687,  -687,  -687,
    8264,   141,  -687,  -687,    67,   262,  8529,   308,  5191,   260,
    -687,  -687,    67,  -687,    67,   264,     3,  7186,  7286,  7351,
    5191,  3163,   266,    14,    70,    20,  -687,  -687,   616,   287,
    7416,   616,  -687,  5191,  -687,  8594,  8131,  7416, 10743,   268,
    5191,  -687, 10743,  5191,   315,   279,    67,  -687,   164, 10743,
    7416,  8659,    40, 10873,   616,    40,   616,  -687,  -687,  2553,
     229,  -687,  5681,  -687,   -20,    63, 10743,   -28,  8724,    71,
     402,  -687,  -687,  -687,  -687,    67,  -687,  -687,  -687,   293,
      16,    16,    16,  -687,  5681,  5681,  5681,  5681,  5289,  5289,
    5681,  5681,  5681,  5681,  5681,  5681,    97,  6563,  5681,  5681,
    5681,  5681,  5681,  5681,  5681,  5681,  5681,  5681,  5681,  5681,
    5681,  5681,  5681,  5681,  5681,  5681,  5681,  5681,  5681,  5681,
    5681,  5681,  5681,  5681,  5681,  5681,  5681,  5681,  5191,  5191,
    5289,  5289,    67,  -687,  -687,  2675,  -687,  8364,  8464,  8791,
      31,  5289,     3,   300,  -687,  -687,  5681,   104,  -687,   294,
     321,  -687, 10743,    67,   306,   390,  5191,  3163,  -687,  -687,
    3285,  5289,  -687,  3407,  5289,  -687,  3163,   399,   301,  -687,
      26,  -687,  -687,    14,  -687,   331,   310,  -687,  1993,   360,
     359,  5681,    16,  -687,   313,  -687,  -687,  -687,  5191,   316,
     -31,  4505,   342,  -687,  -687,  5191,  -687,  -687,  -687,  -687,
    -687,  -687,  7086,  4799,  -687,  4995,  -687,  5289,  2309,  5681,
    5681,  -687,  -687,   346,   394,  2797,   208,   258,   263,  8196,
   10808, 10808,   173,  -687,   173,  -687,   173,  6756,  4354,  7219,
    8397,   287,    40,  -687,  -687,  -687, 10873,   851,   173,   491,
     491, 10808,   491,   491,   616,    40,   851,  1161,   616,   780,
     780,    40,  8856,  8921,  8986,  9051,  9116,  9181,  9246,  9311,
    9376,  9441,  9506,  9571,  9636,  9701,  9766,   319,   318,  -687,
     173,  -687,   173,  -687,    77,  5779,  5289,  5877,  5289,  5681,
    5289,  1920,   137,  9831,  -687,  -687,  9896,  5681,  5191,  -687,
    5191,   368,   236,  -687,  -687,  5681,    79,  -687,  5681, 10743,
      15,  7481,  5681, 10743,    27,  7546,   422,  9961,  3163,  -687,
      53,  -687,  -687,  -687,  -687,  -687,  -687,   162,  -687,    17,
     242,   327,    14,    73,  -687,  5191,  -687,   396,  5681,  5681,
    -687, 10808,  -687,  -687,     0,   330,  -687,  -687,  5191,  -687,
     267,    67,  -687, 10743,  -687,  -687,  -687,  -687,   332,  6826,
    -687, 10743, 10743, 10026,  5191,   335,  -687,  -687,  6715,  -687,
    2919,  -687,  -687,  -687,  -687,  -687,  -687,  -687,  -687,  -687,
    -687,  -687,  -687,  -687,  -687,  -687,  -687,  -687,  -687,  -687,
    -687,    67,  -687,  5681,   438, 10093,  5681,   440, 10158,   345,
    6891,     3,     3,  -687, 10743,  -687, 10743,  -687,  5681,    67,
    -687,  7416,  -687,  7611,  3529,  -687,  3651,  -687,  7676,  3773,
    -687,  3895,  -687,  3163,  5681,  -687,  -687,  -687,   314,  -687,
      14,   369,  -687,  -687,  -687,  -687,    22,  -687,  -687,  4505,
     359,    32, 10743, 10743,  3163,  5191,  -687,  -687,  -687,   134,
      56,  -687,  4017,  4139,  5681,   372,  -687,   242,  -687,  -687,
    -687,  -687,  -687,  -687,  -687,  -687,  -687,  -687,  -687,  -687,
    -687,  -687,  -687,    67,  -687,  -687,  -687,  -687,  -687,  -687,
    -687,  -687,  -687,  -687,  -687,  -687,  -687,  -687,  -687,  -687,
    -687,  -687,  -687,  -687,   374,   351,  -687,  -687, 10223,  5975,
    6073, 10288,  6171,  6269,  6367,  6465,  -687,  -687, 10743,  -687,
    -687,  3163,  5681, 10743,  5681, 10743,  3163,  5681, 10743,  5681,
   10743,  -687, 10743,  -687,   352,  5387,   -11,   406,  -687,  5289,
    4261,  -687,    34,  -687,  4383,  5681,  -687, 10743,  5681,  -687,
   10743, 10743,   338,    11,  -687,  6715,    26,  -687,  5681,  5681,
    5681,  5681,  5681,  5681,  5681,  5681,  9961,  7741,  7806,  9961,
    7871,  7936,   369,   147,  5681,  5681,  4603,  -687,  -687,    74,
    5191,  -687,  -687,  5681,    -3,  6956,  -687,   695,  -687,  8001,
    8066,   270,    67,  -687,   533,  -687,   406,  -687,   351,   176,
   10353, 10418, 10483, 10548, 10613, 10678,  3163,  3163,  3163,  3163,
     -11,  5485,    64,  -687,  -687, 10743, 10743,  -687,  -687,  -687,
    6465,  3163,  3163,  -687,     4,  -687,  -687,  5681,  5681,  5681,
    5681,  5681,  5681,  9961,  9961,  9961,  9961,  -687,  -687,  -687,
    -687,  -687,    76,  5289,  6661,   737,  9961,  9961,  -687,  -687,
    -687,  7021,  -687,  -687,  5583,  -687
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -687,  -687,  -687,    -1,   132,  -184,  1602,  -687,  1380,   463,
    1568,  -139,  -564,  -628,  -687,  -687,    75,  -687,  -687,    13,
    -687,  -687,  -687,  -687,  -687,  -687,  -687,  -687,  -687,   -47,
     401,  -687,  -687,  -687,  -687,  -687,  -687,  -687,  -181,  -223,
    -687,  -180,   -61,  -687,  -687,  -687,   -89,  -687,  -244,   723,
    -687,  -227,  -212,  -687,  -687,  -687,  -132,  -687,  -687,  -687,
     218,   183,  -687,  -297,  -544,  -687,  -411,  -310,  -686,  -663,
    -186,   -30,   -26,  -687,   -64,  -687,    78,   280,  -189,  -687,
    -687,   490,  -687,    -8,  -687,  -687,   757,   800,   -10,  1067,
    -687,  1121,  1156,  -687,  -687,  -687,  -687,  -687,  -687,  -687,
    -687
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -360
static const yytype_int16 yytable[] =
{
     112,    66,   273,   337,   130,   117,   451,   136,   292,   295,
     284,   469,   307,   147,   148,   149,   648,     5,   178,     5,
       5,   313,   158,   307,   159,   287,   160,   161,   317,  -173,
     165,   166,   167,   168,   705,   197,   172,   534,   179,   180,
     181,   327,   560,   182,   440,   564,   183,   184,   185,   539,
     186,   311,    40,   179,   196,   198,   287,   441,   751,    40,
     442,   217,   410,   649,   325,   459,  -236,   325,   762,   565,
       5,   307,   443,   444,   307,   333,   733,  -236,   765,   302,
     445,  -236,   260,     3,   546,   261,   298,   649,   690,   467,
     446,   763,  -236,   218,   270,   753,   219,   338,   146,   314,
       5,  -236,   692,   334,  -236,   559,   319,   547,   112,   267,
     268,   269,   172,   179,   198,   312,   559,   265,   758,   457,
     363,   566,   272,   265,   265,  -236,   325,   325,   282,   325,
     728,  -236,   470,   414,   224,   265,   303,   226,   153,   550,
     282,   229,  -236,   320,  -234,   647,  -236,   265,  -173,  -236,
    -253,   325,  -245,   282,   265,   558,   411,   650,   335,   325,
     282,   364,     5,   179,   308,  -236,   340,   559,  -236,  -253,
     728,  -245,   511,  -253,   325,  -245,   748,   206,   417,   564,
     418,   654,   332,   258,  -236,   259,   336,  -236,   330,   754,
    -344,   113,  -344,   207,   397,   398,   341,  -253,   162,  -245,
     512,   169,   532,   565,   349,   350,   351,   352,   354,   356,
     357,   358,   359,   360,   361,   362,   173,   366,   367,   368,
     369,   370,   371,   372,   373,   374,   375,   376,   377,   378,
     379,   380,   381,   382,   383,   384,   385,   386,   387,   388,
     389,   390,   391,   392,   393,   394,   395,   396,   282,   282,
     400,   402,   706,   644,   465,   653,   426,   548,   134,   325,
     552,   413,   202,  -343,  -310,  -343,   416,   224,   210,   138,
     226,   548,     5,     5,   229,   150,   179,   141,   326,   163,
     429,   431,    90,   433,   435,   549,   437,  -220,  -220,   553,
      90,   535,   537,   353,   355,   540,   542,   211,    90,   736,
     203,   461,   170,   312,  -118,  -118,   554,   476,   282,   477,
     555,    90,  -309,   213,   204,   473,  -220,  -220,   212,   214,
    -118,  -118,   491,   196,   325,   196,    90,   479,   481,   482,
     483,   529,   440,   142,   142,   399,   401,  -220,  -220,   571,
     696,  -313,  -314,    90,   696,   441,   412,    90,   442,  -344,
     331,  -344,  -315,   312,  -312,    15,  -218,   530,   312,  -311,
     443,   444,  -213,    20,    21,   701,   430,   264,   445,   434,
     457,    27,   492,  -114,   262,   265,   274,   493,   446,   276,
     283,  -213,   626,   627,   226,  -218,   286,    38,   300,  -114,
     318,   321,   630,   323,    90,   429,   515,   433,   518,   437,
     520,   481,   702,    82,   521,   522,  -218,   524,   526,   342,
     282,    82,   478,   345,   415,   531,   420,   419,   533,    82,
     424,   425,   538,   438,   439,   561,   452,  -237,   346,   347,
     348,    90,    82,   453,   458,   459,   463,   471,   570,   466,
     484,   486,   509,   510,   528,   198,   543,    82,   562,   563,
     557,  -237,    61,   568,   575,   576,   689,   572,   198,   703,
     619,   697,   622,   645,    82,   697,  -237,   325,    82,    90,
     624,   665,  -237,   666,   179,   682,   693,   490,   704,   135,
     569,   514,   629,   517,   708,   735,   709,   643,   663,   330,
     760,  -237,    94,   747,   734,   462,   720,     0,   527,     0,
      94,     0,     0,   618,     0,     0,   621,     0,    94,     0,
    -237,     0,   217,   698,     0,    82,  -237,     0,   628,     0,
       0,    94,     0,     0,   633,     0,   635,     0,     0,   638,
       0,   640,   752,     0,   642,   652,    94,     0,     0,     0,
       0,   755,   403,     0,   218,    90,     0,   219,     0,     0,
      15,  -218,    82,    94,     0,   179,     0,    94,    20,    21,
     701,     0,   657,   660,   661,   752,    27,    90,  -114,     0,
      90,     0,     0,    90,     0,   752,    90,     0,     0,     0,
    -218,     0,   200,     0,  -114,   224,     0,   225,   226,     0,
      82,     0,   229,     0,     0,     0,     0,   702,   235,   236,
       0,  -218,     0,   239,    94,     0,   240,   241,   242,   633,
     635,     0,   638,   640,   657,   660,     0,     0,    90,     0,
       0,   676,   677,     0,   678,    90,   679,   680,     0,   681,
       0,     0,     0,     0,     0,     0,     0,   217,     0,   695,
     481,    94,     0,     0,   481,   699,     0,    61,   700,     0,
       0,     0,     0,     0,     0,     0,   722,     0,   676,   710,
     711,   679,   712,   713,   714,   715,    82,     0,     0,   218,
       0,     0,   219,     0,   168,   172,   198,     0,     0,    94,
     725,     0,     0,   726,     0,     0,     0,     0,    82,     0,
       0,    82,     0,     0,    82,     0,     0,    82,     0,     0,
       0,     0,     0,     0,     0,     0,   743,   744,   745,   746,
     224,     0,   225,   226,     0,     0,     0,   229,    90,     0,
     660,   756,   757,     0,   236,     0,  -240,   743,   744,   745,
     746,   756,   757,   242,     0,     0,     0,     0,     0,    82,
       0,     0,     0,   761,   481,     0,    82,     0,     0,     0,
    -240,     0,     0,     0,   660,    94,     0,     0,     0,    97,
       0,     0,     0,     0,     0,  -240,     0,    97,  -242,     0,
      90,  -240,     0,     0,     0,    97,     0,    94,     0,     0,
      94,     0,     0,    94,     0,     0,    94,   193,    97,     0,
    -240,   617,  -242,     0,     0,     0,     0,     0,     0,     0,
       0,   217,    98,    97,     0,     0,     0,  -242,     0,  -240,
      98,     0,     0,  -242,    90,  -240,    90,     0,    98,    90,
      97,    90,     0,    90,    97,     0,     0,     0,    94,     0,
       0,    98,  -242,   218,     0,    94,   219,     0,     0,    82,
       0,     0,     0,     0,    90,     0,    98,     0,     0,     0,
       0,  -242,    90,    90,     0,     0,     0,  -242,     0,     0,
       0,   278,     0,    98,     0,     0,     0,    98,     0,     0,
       0,    97,   217,   278,   224,     0,   225,   226,     0,     0,
       0,   229,     0,     0,     0,     0,   278,   235,   236,     0,
       0,    82,   239,   278,     0,     0,     0,   242,     0,     0,
       0,     0,     0,     0,   218,     0,     0,   219,    97,     0,
       0,    90,     0,     0,    98,     0,    90,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    94,     0,
       0,     0,     0,     0,     0,    82,     0,    82,     0,     0,
      82,     0,    82,     0,    82,   224,    97,   225,   226,     0,
       0,    98,   229,   230,   231,     0,   233,   234,   235,   236,
       0,     0,     0,   239,     0,    82,   240,   241,   242,     0,
       0,     0,     0,    82,    82,     0,     0,     0,     0,     0,
      94,   278,   278,     0,     0,     0,     0,     0,     0,    98,
       0,     0,     0,     0,     0,     0,    90,    90,    90,    90,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    90,    90,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    97,     0,    94,     0,    94,     0,     0,    94,
       0,    94,    82,    94,     0,     0,     0,    82,     0,     0,
       0,   278,     0,     0,    97,     0,     0,    97,   472,     0,
      97,     0,     0,    97,    94,     0,   193,     0,   193,     0,
       0,     0,    94,    94,     0,    98,     0,     0,     0,   100,
       0,     0,     0,     0,     0,     0,     0,   100,     0,     0,
       0,     0,     0,     0,     0,   100,     0,    98,     0,     0,
      98,     0,     0,    98,     0,    97,    98,     0,   100,     0,
       0,     0,    97,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   100,     0,     0,     0,    82,    82,    82,
      82,    94,     0,   102,     0,     0,    94,     0,     0,     0,
     100,   102,    82,    82,   100,     0,     0,     0,    98,   102,
       0,   525,     0,   278,     0,    98,     0,     0,     0,     0,
       0,     0,   102,     0,     0,     0,     0,     0,   103,     0,
       0,     0,     0,     0,     0,     0,   103,   102,     0,     0,
       0,     0,     0,     0,   103,     0,     0,     0,     0,     0,
       0,   100,   217,     0,   102,     0,     0,   103,   102,     0,
       0,     0,     0,     0,     0,    97,     0,     0,     0,     0,
       0,     0,   103,     0,     0,     0,    94,    94,    94,    94,
       0,     0,     0,     0,   218,     0,     0,   219,   100,   103,
       0,    94,    94,   103,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   102,   220,     0,    98,     0,
       0,     0,     0,     0,     0,     0,     0,    97,     0,     0,
       0,   221,     0,   222,   223,   224,   100,   225,   226,     0,
       0,   228,   229,   230,   231,     0,   233,   234,   235,   236,
     103,   237,   102,   239,     0,     0,   240,   241,   242,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      98,    97,     0,    97,     0,     0,    97,     0,    97,     0,
      97,     0,     0,     0,     0,     0,     0,   103,     0,     0,
     102,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    97,     0,     0,     0,     0,     0,     0,     0,    97,
      97,     0,   100,     0,    98,     0,    98,     0,     0,    98,
       0,    98,     0,    98,     0,   103,     0,     0,     0,     0,
       0,     0,     0,     0,   100,     0,     0,   100,     0,     0,
     100,     0,     0,   100,    98,     0,     0,     0,   687,     0,
       0,     0,    98,    98,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   102,     0,    97,     0,
       0,     0,     0,    97,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   100,     0,     0,   102,     0,
       0,   102,   100,   723,   102,     0,     0,   102,     0,     0,
       0,   103,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    98,     0,     0,     0,     0,    98,     0,     0,     0,
       0,     0,     0,   103,   749,     0,   103,     0,     0,   103,
       0,     0,   103,     0,     0,     0,     0,     0,     0,   102,
       0,     0,     0,     0,     0,     0,   102,     0,     0,     0,
       0,     0,     0,    97,    97,    97,    97,   749,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   749,    97,    97,
       0,     0,     0,     0,   103,     0,     0,   266,     0,     0,
       0,   103,     0,     0,     0,   100,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    98,    98,    98,    98,
       0,     0,     0,     0,     0,     0,   288,   288,   288,   297,
       0,    98,    98,     0,     0,     0,     0,     0,     0,     0,
     288,     0,     0,     0,     0,     0,     0,   288,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   100,     0,   102,
     288,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     116,     0,     0,     0,   116,     0,     0,     0,   139,   140,
     143,     0,     0,     0,   103,     0,   151,     0,   154,     0,
       0,   100,     0,   100,    68,     0,   100,     0,   100,     0,
     100,   102,   111,     0,     0,   174,     0,     0,     0,     0,
     137,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   100,     0,   157,     0,     0,     0,     0,     0,   100,
     100,     0,     0,     0,     0,     0,   103,     0,   171,     0,
       0,     0,   288,     0,   209,   102,     0,   102,     0,     0,
     102,     0,   102,     0,   102,    68,     0,     0,     0,   201,
       0,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   102,     0,     0,     0,     0,
     103,     0,   103,   102,   102,   103,     0,   103,   100,   103,
       0,     0,   174,   100,     0,     0,   277,     0,     0,     0,
     174,     0,   285,   257,  -321,     0,   263,  -343,   277,  -343,
     103,   304,     0,     0,     0,     0,     0,     0,   103,   103,
       0,   277,     0,     0,     0,     0,     0,     0,   277,     0,
       0,     0,     0,     0,   324,     0,     0,     0,     0,     0,
       0,     0,   102,   299,     0,     0,     0,   102,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   343,     0,     0,     0,     0,   154,   154,
     154,     0,     0,   100,   100,   100,   100,   103,     0,     0,
       0,    68,   103,     0,   365,     0,     0,     0,   100,   100,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     288,   288,     0,     0,   288,   288,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   277,   277,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   102,   102,   102,
     102,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   421,   102,   102,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    68,     0,     0,
       0,   304,   103,   103,   103,   103,     0,     0,     0,     0,
     154,     0,     0,     0,     0,     0,   277,   103,   103,   427,
       0,     0,   427,     0,     0,   427,     0,     0,     0,     0,
       0,   288,   288,     0,     0,     0,     0,     0,     0,     0,
       0,   288,     0,   297,     0,     0,     0,     0,   297,     0,
       0,     0,     0,     5,     6,     7,     8,     9,     0,     0,
     118,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     480,     0,     0,    19,     0,     0,     0,    68,   119,   120,
     121,     0,    26,     0,     0,     0,     0,    29,    30,     0,
      32,     0,    34,    35,     0,     0,     0,     0,    37,     0,
      39,     0,     0,     0,     0,     0,     0,     0,     0,    43,
      44,    45,   122,     0,     0,     0,     0,     0,   277,     0,
       0,     0,     0,     0,   454,     0,     5,     6,     7,     8,
       9,     0,     0,   118,     0,     0,     0,     0,     0,     0,
       0,    53,     0,     0,     0,     0,    19,   551,     0,     0,
     304,   119,   120,   121,     0,    26,     0,     0,     0,    58,
      29,    30,   288,    32,     0,    34,    35,     0,     0,   174,
     545,    37,    64,    39,   124,     0,     0,     0,     0,     0,
       0,     0,    43,    44,    45,   122,   614,   297,   297,     0,
     297,   297,     0,     0,     0,     0,     0,     0,    51,     0,
       0,     0,     0,     0,   727,     0,     0,     0,     0,   297,
     297,     0,     0,    52,    53,    54,    55,     0,     0,     0,
       0,    56,    68,     0,     0,     0,     0,   421,     0,     0,
      57,     0,    58,     0,    59,    60,     0,     0,     0,     0,
      62,     0,     0,   123,   727,    64,     0,   455,   304,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   427,     0,   427,     0,
       0,   427,     0,   427,     0,   641,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   664,     0,     0,     0,     0,   651,     0,     0,     0,
       0,     0,     0,     0,   656,   659,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    -2,     4,     0,
       5,     6,     7,     8,     9,     0,     0,    10,    11,    12,
       0,   -95,    13,    14,    15,  -218,    16,    17,     0,    18,
      19,     0,    20,    21,    22,    23,    24,    25,     0,    26,
      27,     0,  -114,    28,    29,    30,    31,    32,    33,    34,
      35,    36,     0,   707,  -218,    37,    38,    39,  -114,   -95,
       0,     0,    40,     0,    41,    42,    43,    44,    45,    46,
       0,    47,     0,   -95,    48,  -218,     0,     0,    49,    50,
       0,     0,    51,     0,     0,     0,     0,     0,     0,   143,
     174,     0,     0,     0,     0,     0,     0,    52,    53,    54,
      55,     0,     0,     0,     0,    56,     0,     0,     0,     0,
       0,     0,     0,     0,    57,     0,    58,     0,    59,    60,
       0,    61,     0,     0,    62,     0,     0,    63,     0,    64,
       4,    65,     5,     6,     7,     8,     9,     0,  -359,    10,
      11,    12,  -359,   -95,    13,    14,    15,  -218,    16,    17,
    -359,    18,    19,  -359,    20,    21,    22,    23,    24,    25,
       0,    26,    27,     0,  -114,    28,    29,    30,    31,    32,
      33,    34,    35,    36,     0,     0,  -218,    37,     0,    39,
    -114,   -95,  -359,     0,    40,  -359,    41,    42,    43,    44,
      45,    46,     0,    47,     0,   -95,    48,  -218,     0,     0,
      49,    50,     0,     0,  -359,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  -359,
      53,  -359,  -359,  -359,  -359,  -359,  -359,  -359,     0,  -359,
    -359,  -359,  -359,  -359,  -359,  -359,  -359,  -359,    58,  -359,
    -359,  -359,     0,    61,  -359,  -359,  -359,     0,     0,    63,
    -359,    64,     4,    65,     5,     6,     7,     8,     9,     0,
       0,    10,    11,    12,     0,   -95,    13,    14,    15,  -218,
      16,    17,     0,    18,    19,     0,    20,    21,    22,    23,
      24,    25,     0,    26,    27,     0,  -114,    28,    29,    30,
      31,    32,    33,    34,    35,    36,     0,     0,  -218,    37,
      38,    39,  -114,   -95,     0,     0,    40,     0,    41,    42,
      43,    44,    45,    46,     0,    47,     0,   -95,    48,  -218,
       0,     0,    49,    50,     0,     0,    51,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    52,    53,    54,    55,     0,     0,     0,     0,    56,
       0,     0,     0,     0,     0,     0,     0,     0,    57,     0,
      58,     0,    59,    60,   176,    61,     0,     0,    62,     0,
       0,    63,   187,    64,     4,    65,     5,     6,     7,     8,
       9,     0,     0,    10,    11,    12,     0,   -95,    13,    14,
      15,  -218,    16,    17,     0,    18,    19,     0,    20,    21,
      22,    23,    24,    25,     0,    26,    27,     0,  -114,    28,
      29,    30,    31,    32,    33,    34,    35,    36,     0,     0,
    -218,    37,    38,    39,  -114,   -95,     0,     0,    40,     0,
      41,    42,    43,    44,    45,    46,     0,    47,     0,   -95,
      48,  -218,     0,     0,    49,    50,     0,     0,    51,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    52,    53,    54,    55,     0,     0,     0,
       0,    56,     0,     0,     0,     0,     0,     0,     0,     0,
      57,     0,    58,     0,    59,    60,     0,    61,     0,     0,
      62,     0,     0,    63,   329,    64,     4,    65,     5,     6,
       7,     8,     9,     0,     0,    10,    11,    12,     0,   -95,
      13,    14,    15,  -218,    16,    17,     0,    18,    19,     0,
      20,    21,    22,    23,    24,    25,     0,    26,    27,     0,
    -114,    28,    29,    30,    31,    32,    33,    34,    35,    36,
       0,     0,  -218,    37,    38,    39,  -114,   -95,     0,     0,
      40,     0,    41,    42,    43,    44,    45,    46,     0,    47,
       0,   -95,    48,  -218,     0,     0,    49,    50,     0,     0,
      51,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    52,    53,    54,    55,     0,
       0,     0,     0,    56,     0,     0,     0,     0,     0,     0,
       0,     0,    57,     0,    58,     0,    59,    60,     0,    61,
       0,     0,    62,     0,     0,    63,   187,    64,     4,    65,
       5,     6,     7,     8,     9,     0,     0,    10,    11,    12,
       0,   -95,    13,    14,    15,  -218,    16,    17,     0,    18,
      19,     0,    20,    21,    22,    23,    24,    25,     0,    26,
      27,     0,  -114,    28,    29,    30,    31,    32,    33,    34,
      35,    36,     0,     0,  -218,    37,    38,    39,  -114,   -95,
       0,     0,    40,     0,    41,    42,    43,    44,    45,    46,
       0,    47,     0,   -95,    48,  -218,     0,     0,    49,    50,
       0,     0,    51,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    52,    53,    54,
      55,     0,     0,     0,     0,    56,     0,     0,     0,     0,
       0,     0,     0,     0,    57,     0,    58,     0,    59,    60,
       0,    61,     0,     0,    62,     0,     0,    63,   489,    64,
       4,    65,     5,     6,     7,     8,     9,     0,     0,    10,
      11,    12,     0,   -95,    13,    14,    15,  -218,    16,    17,
       0,    18,    19,     0,    20,    21,    22,    23,    24,    25,
       0,    26,    27,     0,  -114,    28,    29,    30,    31,    32,
      33,    34,    35,    36,     0,     0,  -218,    37,    38,    39,
    -114,   -95,     0,     0,    40,     0,    41,    42,    43,    44,
      45,    46,     0,    47,     0,   -95,    48,  -218,     0,     0,
      49,    50,     0,     0,    51,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    52,
      53,    54,    55,     0,     0,     0,     0,    56,     0,     0,
       0,     0,     0,     0,     0,     0,    57,     0,    58,     0,
      59,    60,     0,    61,     0,     0,    62,     0,     0,    63,
     616,    64,     4,    65,     5,     6,     7,     8,     9,     0,
       0,    10,    11,    12,     0,   -95,    13,    14,    15,  -218,
      16,    17,     0,    18,    19,     0,    20,    21,    22,    23,
      24,    25,     0,    26,    27,     0,  -114,    28,    29,    30,
      31,    32,    33,    34,    35,    36,     0,     0,  -218,    37,
     200,    39,  -114,   -95,     0,     0,    40,     0,    41,    42,
      43,    44,    45,    46,     0,    47,     0,   -95,    48,  -218,
       0,     0,    49,    50,     0,     0,    51,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    52,    53,    54,    55,     0,     0,     0,     0,    56,
       0,     0,     0,     0,     0,     0,     0,     0,    57,     0,
      58,     0,    59,    60,     0,    61,     0,     0,    62,     0,
       0,    63,     0,    64,     4,    65,     5,     6,     7,     8,
       9,     0,     0,    10,    11,    12,     0,   -95,    13,    14,
      15,  -218,    16,    17,     0,    18,    19,     0,    20,    21,
      22,    23,    24,    25,     0,    26,    27,     0,  -114,    28,
      29,    30,    31,    32,    33,    34,    35,    36,     0,     0,
    -218,    37,     0,    39,  -114,   -95,     0,     0,    40,     0,
      41,    42,    43,    44,    45,    46,     0,    47,     0,   -95,
      48,  -218,     0,     0,    49,    50,     0,     0,    51,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    52,    53,    54,    55,     0,     0,     0,
       0,    56,     0,     0,     0,     0,     0,     0,     0,     0,
      57,     0,    58,     0,    59,    60,     0,    61,     0,     0,
      62,     0,     0,    63,     0,    64,     4,    65,     5,     6,
       7,     8,     9,     0,     0,    10,    11,    12,     0,   -95,
      13,    14,    15,  -218,    16,    17,     0,    18,    19,     0,
      20,    21,    22,    23,    24,   428,     0,    26,    27,     0,
    -114,    28,    29,    30,    31,    32,    33,    34,    35,    36,
       0,     0,  -218,    37,     0,    39,  -114,   -95,     0,     0,
      40,     0,    41,    42,    43,    44,    45,    46,     0,    47,
       0,   -95,    48,  -218,     0,     0,    49,    50,     0,     0,
      51,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    52,    53,    54,    55,     0,
       0,     0,     0,    56,     0,     0,     0,     0,     0,     0,
       0,     0,    57,     0,    58,     0,    59,    60,     0,    61,
       0,     0,    62,     0,     0,    63,     0,    64,     4,    65,
       5,     6,     7,     8,     9,     0,     0,    10,    11,    12,
       0,   -95,    13,    14,    15,  -218,    16,    17,     0,    18,
      19,     0,    20,    21,    22,    23,    24,   432,     0,    26,
      27,     0,  -114,    28,    29,    30,    31,    32,    33,    34,
      35,    36,     0,     0,  -218,    37,     0,    39,  -114,   -95,
       0,     0,    40,     0,    41,    42,    43,    44,    45,    46,
       0,    47,     0,   -95,    48,  -218,     0,     0,    49,    50,
       0,     0,    51,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    52,    53,    54,
      55,     0,     0,     0,     0,    56,     0,     0,     0,     0,
       0,     0,     0,     0,    57,     0,    58,     0,    59,    60,
       0,    61,     0,     0,    62,     0,     0,    63,     0,    64,
       4,    65,     5,     6,     7,     8,     9,     0,     0,    10,
      11,    12,     0,   -95,    13,    14,    15,  -218,    16,    17,
       0,    18,    19,     0,    20,    21,    22,    23,    24,   632,
       0,    26,    27,     0,  -114,    28,    29,    30,    31,    32,
      33,    34,    35,    36,     0,     0,  -218,    37,     0,    39,
    -114,   -95,     0,     0,    40,     0,    41,    42,    43,    44,
      45,    46,     0,    47,     0,   -95,    48,  -218,     0,     0,
      49,    50,     0,     0,    51,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    52,
      53,    54,    55,     0,     0,     0,     0,    56,     0,     0,
       0,     0,     0,     0,     0,     0,    57,     0,    58,     0,
      59,    60,     0,    61,     0,     0,    62,     0,     0,    63,
       0,    64,     4,    65,     5,     6,     7,     8,     9,     0,
       0,    10,    11,    12,     0,   -95,    13,    14,    15,  -218,
      16,    17,     0,    18,    19,     0,    20,    21,    22,    23,
      24,   634,     0,    26,    27,     0,  -114,    28,    29,    30,
      31,    32,    33,    34,    35,    36,     0,     0,  -218,    37,
       0,    39,  -114,   -95,     0,     0,    40,     0,    41,    42,
      43,    44,    45,    46,     0,    47,     0,   -95,    48,  -218,
       0,     0,    49,    50,     0,     0,    51,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    52,    53,    54,    55,     0,     0,     0,     0,    56,
       0,     0,     0,     0,     0,     0,     0,     0,    57,     0,
      58,     0,    59,    60,     0,    61,     0,     0,    62,     0,
       0,    63,     0,    64,     4,    65,     5,     6,     7,     8,
       9,     0,     0,    10,    11,    12,     0,   -95,    13,    14,
      15,  -218,    16,    17,     0,    18,    19,     0,    20,    21,
      22,    23,    24,   637,     0,    26,    27,     0,  -114,    28,
      29,    30,    31,    32,    33,    34,    35,    36,     0,     0,
    -218,    37,     0,    39,  -114,   -95,     0,     0,    40,     0,
      41,    42,    43,    44,    45,    46,     0,    47,     0,   -95,
      48,  -218,     0,     0,    49,    50,     0,     0,    51,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    52,    53,    54,    55,     0,     0,     0,
       0,    56,     0,     0,     0,     0,     0,     0,     0,     0,
      57,     0,    58,     0,    59,    60,     0,    61,     0,     0,
      62,     0,     0,    63,     0,    64,     4,    65,     5,     6,
       7,     8,     9,     0,     0,    10,    11,    12,     0,   -95,
      13,    14,    15,  -218,    16,    17,     0,    18,    19,     0,
      20,    21,    22,    23,    24,   639,     0,    26,    27,     0,
    -114,    28,    29,    30,    31,    32,    33,    34,    35,    36,
       0,     0,  -218,    37,     0,    39,  -114,   -95,     0,     0,
      40,     0,    41,    42,    43,    44,    45,    46,     0,    47,
       0,   -95,    48,  -218,     0,     0,    49,    50,     0,     0,
      51,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    52,    53,    54,    55,     0,
       0,     0,     0,    56,     0,     0,     0,     0,     0,     0,
       0,     0,    57,     0,    58,     0,    59,    60,     0,    61,
       0,     0,    62,     0,     0,    63,     0,    64,     4,    65,
       5,     6,     7,     8,     9,     0,     0,    10,    11,    12,
       0,   -95,    13,    14,    15,  -218,    16,    17,     0,    18,
      19,     0,    20,    21,    22,    23,    24,   655,     0,    26,
      27,     0,  -114,    28,    29,    30,    31,    32,    33,    34,
      35,    36,     0,     0,  -218,    37,     0,    39,  -114,   -95,
       0,     0,    40,     0,    41,    42,    43,    44,    45,    46,
       0,    47,     0,   -95,    48,  -218,     0,     0,    49,    50,
       0,     0,    51,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    52,    53,    54,
      55,     0,     0,     0,     0,    56,     0,     0,     0,     0,
       0,     0,     0,     0,    57,     0,    58,     0,    59,    60,
       0,    61,     0,     0,    62,     0,     0,    63,     0,    64,
       4,    65,     5,     6,     7,     8,     9,     0,     0,    10,
      11,    12,     0,   -95,    13,    14,    15,  -218,    16,    17,
       0,    18,    19,     0,    20,    21,    22,    23,    24,   658,
       0,    26,    27,     0,  -114,    28,    29,    30,    31,    32,
      33,    34,    35,    36,     0,     0,  -218,    37,     0,    39,
    -114,   -95,     0,     0,    40,     0,    41,    42,    43,    44,
      45,    46,     0,    47,     0,   -95,    48,  -218,     0,     0,
      49,    50,     0,     0,    51,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    52,
      53,    54,    55,     0,     0,     0,     0,    56,     0,     0,
       0,     0,     0,     0,     0,     0,    57,     0,    58,     0,
      59,    60,     0,    61,     0,     0,    62,     0,     0,    63,
       0,    64,   454,    65,     5,     6,     7,     8,     9,     0,
    -359,   118,     0,     0,  -359,     0,     0,     0,     0,     0,
       0,     0,  -359,     0,    19,     0,     0,     0,     0,   119,
     120,   121,     0,    26,     0,     0,     0,     0,    29,    30,
       0,    32,     0,    34,    35,     0,     0,     0,     0,    37,
       0,    39,     0,     0,  -359,     0,     0,  -359,     0,     0,
      43,    44,    45,   122,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  -235,  -359,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  -359,    53,  -359,  -359,  -359,     0,  -359,  -359,  -359,
       0,  -359,  -359,  -359,  -359,  -359,  -359,  -359,  -359,  -359,
      58,  -359,  -359,  -359,     0,   217,  -359,  -359,  -359,     0,
       0,   123,     0,    64,   454,   468,     5,     6,     7,     8,
       9,     0,  -359,   118,     0,     0,  -359,     0,     0,     0,
       0,     0,     0,     0,  -359,     0,    19,   218,     0,     0,
     219,   119,   120,   121,     0,    26,     0,     0,     0,     0,
      29,    30,     0,    32,     0,    34,    35,     0,     0,     0,
       0,    37,     0,    39,     0,     0,  -359,     0,     0,  -359,
       0,     0,    43,    44,    45,   122,     0,     0,   224,     0,
     225,   226,     0,     0,   228,   229,   230,   231,  -359,   233,
     234,   235,   236,     0,   237,     0,   239,     0,     0,   240,
     241,   242,     0,  -359,    53,  -359,  -359,  -359,     0,  -359,
    -359,  -359,     0,  -359,  -359,  -359,  -359,  -359,  -359,  -359,
    -359,  -359,    58,  -359,  -359,  -359,     0,     0,  -359,  -359,
    -359,     0,     0,   123,     0,    64,   454,   468,     5,     6,
       7,     8,     9,     0,     0,   118,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    19,     0,
       0,     0,     0,   119,   120,   121,     0,    26,     0,     0,
       0,     0,    29,    30,     0,    32,     0,    34,    35,     0,
       0,     0,     0,    37,     0,    39,     0,     0,     0,     0,
       0,     0,     0,     0,    43,    44,    45,   122,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      51,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    52,    53,    54,    55,     0,
       0,     0,     0,    56,     0,     0,     5,     6,     7,     8,
       9,     0,    57,   118,    58,     0,    59,    60,     0,     0,
       0,     0,    62,     0,     0,   123,    19,    64,     0,   468,
       0,   119,   120,   121,     0,    26,     0,     0,     0,     0,
      29,    30,     0,    32,     0,    34,    35,     0,     0,     0,
       0,    37,     0,    39,     0,     0,     0,     0,     0,     0,
       0,     0,    43,    44,    45,   122,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    51,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    52,    53,    54,    55,     0,     0,     0,
       0,    56,     0,     0,     5,     6,     7,     8,     9,     0,
      57,   118,    58,     0,    59,    60,   176,     0,     0,     0,
      62,     0,     0,   123,    19,    64,     0,   124,   721,   119,
     120,   121,     0,    26,     0,     0,     0,     0,    29,    30,
       0,    32,     0,    34,    35,     0,     0,     0,     0,    37,
       0,    39,     0,     0,     0,     0,     0,     0,     0,     0,
      43,    44,    45,   122,     0,     0,   191,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    51,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    52,    53,    54,    55,     0,     0,     0,     0,    56,
     192,     0,     5,     6,     7,     8,     9,     0,    57,   118,
      58,     0,    59,    60,   176,     0,     0,     0,    62,     0,
       0,   123,    19,    64,     0,   124,     0,   119,   120,   121,
       0,    26,     0,     0,     0,     0,    29,    30,     0,    32,
       0,    34,    35,     0,     0,     0,     0,    37,     0,    39,
       0,     0,     0,     0,     0,     0,     0,     0,    43,    44,
      45,   122,     0,     0,   191,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    51,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    52,
      53,    54,    55,     0,     0,     0,     0,    56,     0,     0,
       5,     6,     7,     8,     9,     0,    57,   118,    58,     0,
      59,    60,   176,     0,     0,     0,    62,     0,     0,   123,
      19,    64,   475,   124,     0,   119,   120,   121,     0,    26,
       0,     0,     0,     0,    29,    30,     0,    32,     0,    34,
      35,     0,     0,     0,   144,    37,     0,    39,     0,     0,
       0,     0,     0,     0,     0,     0,    43,    44,    45,   122,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     145,     0,    51,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    52,    53,    54,
      55,     0,     0,     0,     0,    56,     0,     0,     5,     6,
       7,     8,     9,     0,    57,   118,    58,     0,    59,    60,
       0,     0,     0,     0,    62,     0,     0,   123,    19,    64,
       0,   124,     0,   119,   120,   121,     0,    26,     0,     0,
       0,     0,    29,    30,     0,    32,     0,    34,    35,     0,
       0,     0,     0,    37,     0,    39,     0,     0,     0,     0,
       0,     0,     0,     0,    43,    44,    45,   122,     0,     0,
     191,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      51,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    52,    53,    54,    55,     0,
       0,     0,     0,    56,     0,     0,     5,     6,     7,     8,
       9,     0,    57,   118,    58,     0,    59,    60,   176,     0,
       0,     0,    62,     0,     0,   123,    19,    64,     0,   124,
       0,   119,   120,   121,     0,    26,     0,     0,     0,     0,
      29,    30,     0,    32,     0,    34,    35,     0,     0,     0,
       0,    37,     0,    39,     0,     0,     0,     0,     0,     0,
       0,     0,    43,    44,    45,   122,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    51,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    52,    53,    54,    55,     0,     0,     0,
       0,    56,     0,     0,     5,     6,     7,     8,     9,     0,
      57,   118,    58,     0,    59,    60,     0,   164,     0,     0,
      62,     0,     0,   123,    19,    64,     0,   124,     0,   119,
     120,   121,     0,    26,     0,     0,     0,     0,    29,    30,
       0,    32,     0,    34,    35,     0,     0,     0,     0,    37,
       0,    39,     0,     0,     0,     0,     0,     0,     0,     0,
      43,    44,    45,   122,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    51,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    52,    53,    54,    55,     0,     0,     0,     0,    56,
       0,     0,     5,     6,     7,     8,     9,     0,    57,   118,
      58,     0,    59,    60,   176,     0,     0,     0,    62,     0,
       0,   123,    19,    64,     0,   124,     0,   119,   120,   121,
       0,    26,     0,     0,     0,     0,    29,    30,     0,    32,
       0,    34,    35,     0,     0,     0,     0,    37,     0,    39,
       0,     0,     0,     0,     0,     0,     0,     0,    43,    44,
      45,   122,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   145,     0,    51,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    52,
      53,    54,    55,     0,     0,     0,     0,    56,     0,     0,
       5,     6,     7,     8,     9,     0,    57,   118,    58,     0,
      59,    60,     0,     0,     0,     0,    62,     0,     0,   123,
     683,    64,     0,   124,     0,   119,   120,   121,     0,    26,
       0,     0,     0,     0,    29,    30,     0,    32,     0,    34,
      35,     0,     0,     0,     0,    37,     0,    39,     0,     0,
       0,     0,     0,     0,     0,     0,   684,    44,    45,   685,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    51,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    52,    53,    54,
      55,     0,     0,     0,     0,    56,     0,     0,     5,     6,
       7,     8,     9,     0,    57,   118,    58,     0,    59,    60,
     176,     0,     0,     0,    62,     0,     0,   123,    19,    64,
       0,   686,     0,   119,   120,   121,     0,    26,     0,     0,
       0,     0,    29,    30,     0,    32,     0,    34,    35,     0,
       0,     0,     0,    37,     0,    39,     0,     0,     0,     0,
       0,     0,     0,     0,    43,    44,    45,   122,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      51,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    52,    53,    54,    55,     0,
       0,     0,     0,    56,     0,     0,     5,     6,     7,     8,
       9,     0,    57,   118,    58,     0,    59,    60,   176,     0,
       0,     0,    62,     0,     0,   123,    19,    64,     0,   686,
       0,   119,   120,   675,     0,    26,     0,     0,     0,     0,
      29,    30,     0,    32,     0,    34,    35,     0,     0,     0,
       0,    37,     0,    39,     0,     0,     0,     0,     0,     0,
       0,     0,    43,    44,    45,   122,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    51,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    52,    53,    54,    55,     0,     0,     0,
       0,    56,     0,     0,     5,     6,     7,     8,     9,     0,
      57,   118,    58,     0,    59,    60,   176,     0,     0,     0,
      62,     0,     0,   123,    19,    64,     0,   124,     0,   119,
     120,   121,     0,    26,     0,     0,     0,     0,    29,    30,
       0,    32,     0,    34,    35,     0,     0,     0,     0,    37,
       0,    39,     0,     0,     0,     0,     0,     0,     0,     0,
      43,    44,    45,   122,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    51,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    52,    53,    54,    55,     0,     0,     0,     0,    56,
       0,     0,     5,     6,     7,     8,     9,     0,    57,   118,
      58,     0,    59,    60,     0,     0,     0,     0,    62,     0,
       0,   123,    19,    64,     0,   124,     0,   119,   120,   513,
       0,    26,     0,     0,     0,     0,    29,    30,     0,    32,
       0,    34,    35,     0,     0,     0,     0,    37,     0,    39,
       0,     0,     0,     0,     0,     0,     0,     0,    43,    44,
      45,   122,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    51,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    52,
      53,    54,    55,     0,     0,     0,     0,    56,     0,     0,
       5,     6,     7,     8,     9,     0,    57,   118,    58,     0,
      59,    60,     0,     0,     0,     0,    62,     0,     0,   123,
      19,    64,     0,   124,     0,   119,   120,   516,     0,    26,
       0,     0,     0,     0,    29,    30,     0,    32,     0,    34,
      35,     0,     0,     0,     0,    37,     0,    39,     0,     0,
       0,     0,     0,     0,     0,     0,    43,    44,    45,   122,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    51,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    52,    53,    54,
      55,     0,     0,     0,     0,    56,     0,     0,     5,     6,
       7,     8,     9,     0,    57,   118,    58,     0,    59,    60,
       0,     0,     0,     0,    62,     0,     0,   123,    19,    64,
       0,   124,     0,   119,   120,   669,     0,    26,     0,     0,
       0,     0,    29,    30,     0,    32,     0,    34,    35,     0,
       0,     0,     0,    37,     0,    39,     0,     0,     0,     0,
       0,     0,     0,     0,    43,    44,    45,   122,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      51,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    52,    53,    54,    55,     0,
       0,     0,     0,    56,     0,     0,     5,     6,     7,     8,
       9,     0,    57,   118,    58,     0,    59,    60,     0,     0,
       0,     0,    62,     0,     0,   123,    19,    64,     0,   124,
       0,   119,   120,   670,     0,    26,     0,     0,     0,     0,
      29,    30,     0,    32,     0,    34,    35,     0,     0,     0,
       0,    37,     0,    39,     0,     0,     0,     0,     0,     0,
       0,     0,    43,    44,    45,   122,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    51,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    52,    53,    54,    55,     0,     0,     0,
       0,    56,     0,     0,     5,     6,     7,     8,     9,     0,
      57,   118,    58,     0,    59,    60,     0,     0,     0,     0,
      62,     0,     0,   123,    19,    64,     0,   124,     0,   119,
     120,   672,     0,    26,     0,     0,     0,     0,    29,    30,
       0,    32,     0,    34,    35,     0,     0,     0,     0,    37,
       0,    39,     0,     0,     0,     0,     0,     0,     0,     0,
      43,    44,    45,   122,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    51,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    52,    53,    54,    55,     0,     0,     0,     0,    56,
       0,     0,     5,     6,     7,     8,     9,     0,    57,   118,
      58,     0,    59,    60,     0,     0,     0,     0,    62,     0,
       0,   123,    19,    64,     0,   124,     0,   119,   120,   673,
       0,    26,     0,     0,     0,     0,    29,    30,     0,    32,
       0,    34,    35,     0,     0,     0,     0,    37,     0,    39,
       0,     0,     0,     0,     0,     0,     0,     0,    43,    44,
      45,   122,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    51,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    52,
      53,    54,    55,     0,     0,     0,     0,    56,     0,     0,
       5,     6,     7,     8,     9,     0,    57,   118,    58,     0,
      59,    60,     0,     0,     0,     0,    62,     0,     0,   123,
      19,    64,     0,   124,     0,   119,   120,   674,     0,    26,
       0,     0,     0,     0,    29,    30,     0,    32,     0,    34,
      35,     0,     0,     0,     0,    37,     0,    39,     0,     0,
       0,     0,     0,     0,     0,     0,    43,    44,    45,   122,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    51,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    52,    53,    54,
      55,     0,     0,     0,     0,    56,     0,     0,     5,     6,
       7,     8,     9,     0,    57,   118,    58,     0,    59,    60,
       0,     0,     0,     0,    62,     0,     0,   123,    19,    64,
       0,   124,     0,   119,   120,   675,     0,    26,     0,     0,
       0,     0,    29,    30,     0,    32,     0,    34,    35,     0,
       0,     0,     0,    37,     0,    39,     0,     0,     0,     0,
       0,     0,     0,     0,    43,    44,    45,   122,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      51,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    52,    53,    54,    55,     0,
       0,     0,     0,    56,     0,     0,     5,     6,     7,     8,
       9,     0,    57,   118,    58,     0,    59,    60,     0,     0,
       0,     0,    62,     0,     0,   123,    19,    64,     0,   124,
       0,   119,   120,   121,     0,    26,     0,     0,     0,     0,
      29,    30,     0,    32,     0,    34,    35,     0,     0,     0,
       0,    37,     0,    39,     0,     0,     0,     0,     0,     0,
       0,     0,    43,    44,    45,   122,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    51,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    52,    53,    54,    55,     0,     0,     0,
       0,     0,     0,     0,     5,     6,     7,     8,     9,     0,
      57,   118,    58,     0,    59,    60,     0,     0,     0,     0,
      62,     0,     0,   123,    19,    64,     0,   124,     0,   119,
     120,   121,     0,    26,     0,     0,     0,     0,    29,    30,
       0,    32,     0,    34,    35,     0,     0,     0,     0,    37,
       0,    39,     0,     0,     0,     0,     0,     0,     5,     0,
      43,    44,    45,   122,   578,     0,     0,     0,   579,     0,
       0,     0,     0,     0,     0,     0,     0,  -244,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    53,     0,     0,     0,  -244,     0,     0,     0,
    -244,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      58,     0,     0,     0,   176,     0,     0,   217,     0,     0,
       0,   123,     0,    64,  -244,   686,     0,     0,     0,     0,
       0,   580,   581,   582,   583,   584,   585,     0,     0,   586,
     587,   588,   589,   590,   591,   592,   593,   594,   595,   218,
       0,   596,   219,     0,     0,   597,   598,   599,   600,   601,
     602,   603,   604,   605,   606,   607,     0,   608,     0,     0,
     609,   610,   611,   612,   613,   215,     0,     0,     0,   216,
       0,     0,     0,     0,     0,     0,   221,   217,   222,   223,
     224,     0,   225,   226,     0,     0,   228,   229,   230,   231,
       0,   233,   234,   235,   236,     0,   237,     0,   239,     0,
       0,   240,   241,   242,     0,     0,     0,     0,     0,   218,
       0,     0,   219,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     215,   220,     0,     0,   216,     0,     0,     0,     0,     0,
       0,     0,   217,     0,     0,     0,   221,     0,   222,   223,
     224,     0,   225,   226,   227,     0,   228,   229,   230,   231,
     232,   233,   234,   235,   236,     0,   237,   238,   239,     0,
       0,   240,   241,   242,   218,     0,     0,   219,     0,     0,
       0,   573,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   215,   220,     0,     0,   216,
       0,     0,     0,     0,     0,     0,     0,   217,     0,     0,
       0,   221,     0,   222,   223,   224,     0,   225,   226,   227,
       0,   228,   229,   230,   231,   232,   233,   234,   235,   236,
       0,   237,   238,   239,     0,     0,   240,   241,   242,   218,
       0,     0,   219,     0,     0,     0,   625,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     215,   220,     0,     0,   216,     0,     0,     0,     0,     0,
       0,     0,   217,     0,     0,     0,   221,     0,   222,   223,
     224,     0,   225,   226,   227,     0,   228,   229,   230,   231,
     232,   233,   234,   235,   236,     0,   237,   238,   239,     0,
       0,   240,   241,   242,   218,     0,     0,   219,     0,     0,
       0,   730,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   215,   220,     0,     0,   216,
       0,     0,     0,     0,     0,     0,     0,   217,     0,     0,
       0,   221,     0,   222,   223,   224,     0,   225,   226,   227,
       0,   228,   229,   230,   231,   232,   233,   234,   235,   236,
       0,   237,   238,   239,     0,     0,   240,   241,   242,   218,
       0,     0,   219,     0,     0,     0,   764,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   220,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   221,     0,   222,   223,
     224,     0,   225,   226,   227,     0,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   215,   237,   238,   239,   216,
       0,   240,   241,   242,     0,     0,     0,   217,   290,   474,
       0,     0,     0,     0,     0,     0,     0,   291,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   218,
     217,     0,   219,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   220,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   218,     0,     0,   219,   221,     0,   222,   223,
     224,     0,   225,   226,   227,     0,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   215,   237,   238,   239,   216,
       0,   240,   241,   242,     0,     0,   265,   217,   293,   221,
       0,     0,   223,   224,     0,   225,   226,   294,     0,   228,
     229,   230,   231,     0,   233,   234,   235,   236,     0,   237,
       0,   239,     0,     0,   240,   241,   242,     0,     0,   218,
       0,     0,   219,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     215,   220,     0,     0,   216,     0,     0,     0,     0,     0,
       0,     0,   217,     0,     0,     0,   221,     0,   222,   223,
     224,     0,   225,   226,   227,     0,   228,   229,   230,   231,
     232,   233,   234,   235,   236,     0,   237,   238,   239,     0,
       0,   240,   241,   242,   218,     0,   265,   219,     0,     0,
       0,     0,     0,     0,   296,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   215,   220,     0,     0,   216,
       0,     0,     0,     0,     0,     0,     0,   217,   287,     0,
       0,   221,     0,   222,   223,   224,     0,   225,   226,   227,
       0,   228,   229,   230,   231,   232,   233,   234,   235,   236,
       0,   237,   238,   239,     0,     0,   240,   241,   242,   218,
       0,   265,   219,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     215,   220,     0,     0,   216,     0,     0,     0,     0,     0,
       0,     0,   217,   536,     0,     0,   221,     0,   222,   223,
     224,     0,   225,   226,   227,     0,   228,   229,   230,   231,
     232,   233,   234,   235,   236,     0,   237,   238,   239,     0,
       0,   240,   241,   242,   218,     0,   265,   219,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   215,   220,     0,     0,   216,
       0,     0,     0,     0,     0,     0,     0,   217,   541,     0,
       0,   221,     0,   222,   223,   224,     0,   225,   226,   227,
       0,   228,   229,   230,   231,   232,   233,   234,   235,   236,
       0,   237,   238,   239,     0,     0,   240,   241,   242,   218,
       0,   265,   219,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     215,   220,     0,     0,   216,     0,     0,     0,     0,     0,
       0,     0,   217,     0,     0,     0,   221,     0,   222,   223,
     224,     0,   225,   226,   227,     0,   228,   229,   230,   231,
     232,   233,   234,   235,   236,     0,   237,   238,   239,     0,
       0,   240,   241,   242,   218,     0,   265,   219,     0,     0,
       0,     0,     0,     0,   631,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   215,   220,     0,     0,   216,
       0,     0,     0,     0,     0,     0,     0,   217,     0,     0,
       0,   221,     0,   222,   223,   224,     0,   225,   226,   227,
       0,   228,   229,   230,   231,   232,   233,   234,   235,   236,
       0,   237,   238,   239,     0,     0,   240,   241,   242,   218,
       0,   265,   219,     0,     0,     0,     0,     0,     0,   636,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     215,   220,     0,     0,   216,     0,     0,     0,     0,     0,
       0,     0,   217,     0,     0,     0,   221,     0,   222,   223,
     224,     0,   225,   226,   227,     0,   228,   229,   230,   231,
     232,   233,   234,   235,   236,     0,   237,   238,   239,     0,
       0,   240,   241,   242,   218,     0,   265,   219,     0,     0,
       0,     0,     0,     0,   716,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   215,   220,     0,     0,   216,
       0,     0,     0,     0,     0,     0,     0,   217,     0,     0,
       0,   221,     0,   222,   223,   224,     0,   225,   226,   227,
       0,   228,   229,   230,   231,   232,   233,   234,   235,   236,
       0,   237,   238,   239,     0,     0,   240,   241,   242,   218,
       0,   265,   219,     0,     0,     0,     0,     0,     0,   717,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     215,   220,     0,     0,   216,     0,     0,     0,     0,     0,
       0,     0,   217,     0,     0,     0,   221,     0,   222,   223,
     224,     0,   225,   226,   227,     0,   228,   229,   230,   231,
     232,   233,   234,   235,   236,     0,   237,   238,   239,     0,
       0,   240,   241,   242,   218,     0,   265,   219,     0,     0,
       0,     0,     0,     0,   718,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   215,   220,     0,     0,   216,
       0,     0,     0,     0,     0,     0,     0,   217,     0,     0,
       0,   221,     0,   222,   223,   224,     0,   225,   226,   227,
       0,   228,   229,   230,   231,   232,   233,   234,   235,   236,
       0,   237,   238,   239,     0,     0,   240,   241,   242,   218,
       0,   265,   219,     0,     0,     0,     0,     0,     0,   719,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     215,   220,     0,     0,   216,     0,     0,     0,     0,     0,
       0,     0,   217,     0,     0,     0,   221,     0,   222,   223,
     224,     0,   225,   226,   227,     0,   228,   229,   230,   231,
     232,   233,   234,   235,   236,     0,   237,   238,   239,     0,
       0,   240,   241,   242,   218,     0,   265,   219,     0,     0,
       0,     0,     0,     0,   731,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   215,   220,     0,     0,   216,
       0,     0,     0,     0,     0,     0,     0,   217,     0,     0,
       0,   221,     0,   222,   223,   224,     0,   225,   226,   227,
       0,   228,   229,   230,   231,   232,   233,   234,   235,   236,
       0,   237,   238,   239,     0,     0,   240,   241,   242,   218,
       0,   265,   219,     0,     0,     0,     0,     0,     0,   732,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     215,   220,     0,     0,   216,     0,     0,     0,     0,     0,
       0,     0,   217,     0,     0,     0,   221,     0,   222,   223,
     224,     0,   225,   226,   227,     0,   228,   229,   230,   231,
     232,   233,   234,   235,   236,     0,   237,   238,   239,     0,
       0,   240,   241,   242,   218,     0,   265,   219,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   215,   220,     0,     0,   216,
       0,     0,     0,     0,     0,     0,     0,   217,     0,     0,
       0,   221,     0,   222,   223,   224,     0,   225,   226,   227,
       0,   228,   229,   230,   231,   232,   233,   234,   235,   236,
       0,   237,   238,   239,     0,     0,   240,   241,   242,   218,
       0,   316,   219,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   220,     0,   215,     0,     0,     0,   216,     0,     0,
       0,     0,     0,     0,     0,   217,   221,     0,   222,   223,
     224,     0,   225,   226,   227,   271,   228,   229,   230,   231,
     232,   233,   234,   235,   236,     0,   237,   238,   239,     0,
       0,   240,   241,   242,     0,  -322,     0,   218,   113,     0,
     219,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   220,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   221,     0,   222,   223,   224,     0,
     225,   226,   227,     0,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   215,   237,   238,   239,   216,     0,   240,
     241,   242,     0,     0,     0,   217,   405,     0,     0,     0,
       0,     0,     0,     0,     0,   406,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   218,   217,     0,
     219,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   220,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     218,     0,     0,   219,   221,     0,   222,   223,   224,     0,
     225,   226,   227,     0,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   215,   237,   238,   239,   216,     0,   240,
     241,   242,     0,     0,     0,   217,   407,   221,     0,     0,
       0,   224,     0,   225,   226,   408,     0,   228,   229,   230,
     231,     0,   233,   234,   235,   236,     0,   237,     0,   239,
       0,     0,   240,   241,   242,     0,     0,   218,     0,     0,
     219,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   215,   220,
       0,     0,   216,     0,     0,     0,     0,     0,     0,     0,
     217,     0,     0,     0,   221,     0,   222,   223,   224,     0,
     225,   226,   227,     0,   228,   229,   230,   231,   232,   233,
     234,   235,   236,     0,   237,   238,   239,     0,     0,   240,
     241,   242,   218,     0,     0,   219,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   215,   220,     0,     0,   216,     0,     0,
       0,     0,     0,     0,     0,   217,     0,     0,     0,   221,
       0,   222,   223,   224,     0,   225,   226,   227,     0,   228,
     229,   230,   231,   232,   233,   234,   235,   236,     0,   237,
     238,   239,     0,   275,   240,   241,   242,   218,     0,     0,
     219,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   215,   220,
       0,     0,   216,     0,     0,     0,     0,     0,     0,     0,
     217,     0,     0,     0,   221,     0,   222,   223,   224,     0,
     225,   226,   227,     0,   228,   229,   230,   231,   232,   233,
     234,   235,   236,     0,   237,   238,   239,     0,   315,   240,
     241,   242,   218,     0,     0,   219,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   215,   220,     0,     0,   216,     0,     0,
       0,     0,     0,     0,     0,   217,     0,     0,     0,   221,
       0,   222,   223,   224,     0,   225,   226,   227,     0,   228,
     229,   230,   231,   232,   233,   234,   235,   236,     0,   237,
     238,   239,     0,   328,   240,   241,   242,   218,     0,     0,
     219,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   339,   220,
     215,     0,     0,     0,   216,     0,     0,     0,     0,     0,
       0,     0,   217,     0,   221,     0,   222,   223,   224,     0,
     225,   226,   227,     0,   228,   229,   230,   231,   232,   233,
     234,   235,   236,     0,   237,   238,   239,     0,     0,   240,
     241,   242,     0,     0,   218,     0,     0,   219,     0,     0,
       0,     0,     0,     0,   409,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   215,   220,     0,     0,   216,
       0,     0,     0,     0,     0,     0,     0,   217,     0,     0,
       0,   221,     0,   222,   223,   224,     0,   225,   226,   227,
       0,   228,   229,   230,   231,   232,   233,   234,   235,   236,
       0,   237,   238,   239,     0,     0,   240,   241,   242,   218,
       0,     0,   219,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     215,   220,     0,     0,   216,     0,     0,     0,     0,     0,
       0,     0,   217,     0,     0,     0,   221,     0,   222,   223,
     224,     0,   225,   226,   227,     0,   228,   229,   230,   231,
     232,   233,   234,   235,   236,     0,   237,   238,   239,     0,
     494,   240,   241,   242,   218,     0,     0,   219,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   215,   220,     0,     0,   216,
       0,     0,     0,     0,     0,     0,     0,   217,     0,     0,
       0,   221,     0,   222,   223,   224,     0,   225,   226,   227,
       0,   228,   229,   230,   231,   232,   233,   234,   235,   236,
       0,   237,   238,   239,     0,   495,   240,   241,   242,   218,
       0,     0,   219,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     215,   220,     0,     0,   216,     0,     0,     0,     0,     0,
       0,     0,   217,     0,     0,     0,   221,     0,   222,   223,
     224,     0,   225,   226,   227,     0,   228,   229,   230,   231,
     232,   233,   234,   235,   236,     0,   237,   238,   239,     0,
     496,   240,   241,   242,   218,     0,     0,   219,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   215,   220,     0,     0,   216,
       0,     0,     0,     0,     0,     0,     0,   217,     0,     0,
       0,   221,     0,   222,   223,   224,     0,   225,   226,   227,
       0,   228,   229,   230,   231,   232,   233,   234,   235,   236,
       0,   237,   238,   239,     0,   497,   240,   241,   242,   218,
       0,     0,   219,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     215,   220,     0,     0,   216,     0,     0,     0,     0,     0,
       0,     0,   217,     0,     0,     0,   221,     0,   222,   223,
     224,     0,   225,   226,   227,     0,   228,   229,   230,   231,
     232,   233,   234,   235,   236,     0,   237,   238,   239,     0,
     498,   240,   241,   242,   218,     0,     0,   219,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   215,   220,     0,     0,   216,
       0,     0,     0,     0,     0,     0,     0,   217,     0,     0,
       0,   221,     0,   222,   223,   224,     0,   225,   226,   227,
       0,   228,   229,   230,   231,   232,   233,   234,   235,   236,
       0,   237,   238,   239,     0,   499,   240,   241,   242,   218,
       0,     0,   219,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     215,   220,     0,     0,   216,     0,     0,     0,     0,     0,
       0,     0,   217,     0,     0,     0,   221,     0,   222,   223,
     224,     0,   225,   226,   227,     0,   228,   229,   230,   231,
     232,   233,   234,   235,   236,     0,   237,   238,   239,     0,
     500,   240,   241,   242,   218,     0,     0,   219,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   215,   220,     0,     0,   216,
       0,     0,     0,     0,     0,     0,     0,   217,     0,     0,
       0,   221,     0,   222,   223,   224,     0,   225,   226,   227,
       0,   228,   229,   230,   231,   232,   233,   234,   235,   236,
       0,   237,   238,   239,     0,   501,   240,   241,   242,   218,
       0,     0,   219,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     215,   220,     0,     0,   216,     0,     0,     0,     0,     0,
       0,     0,   217,     0,     0,     0,   221,     0,   222,   223,
     224,     0,   225,   226,   227,     0,   228,   229,   230,   231,
     232,   233,   234,   235,   236,     0,   237,   238,   239,     0,
     502,   240,   241,   242,   218,     0,     0,   219,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   215,   220,     0,     0,   216,
       0,     0,     0,     0,     0,     0,     0,   217,     0,     0,
       0,   221,     0,   222,   223,   224,     0,   225,   226,   227,
       0,   228,   229,   230,   231,   232,   233,   234,   235,   236,
       0,   237,   238,   239,     0,   503,   240,   241,   242,   218,
       0,     0,   219,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     215,   220,     0,     0,   216,     0,     0,     0,     0,     0,
       0,     0,   217,     0,     0,     0,   221,     0,   222,   223,
     224,     0,   225,   226,   227,     0,   228,   229,   230,   231,
     232,   233,   234,   235,   236,     0,   237,   238,   239,     0,
     504,   240,   241,   242,   218,     0,     0,   219,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   215,   220,     0,     0,   216,
       0,     0,     0,     0,     0,     0,     0,   217,     0,     0,
       0,   221,     0,   222,   223,   224,     0,   225,   226,   227,
       0,   228,   229,   230,   231,   232,   233,   234,   235,   236,
       0,   237,   238,   239,     0,   505,   240,   241,   242,   218,
       0,     0,   219,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     215,   220,     0,     0,   216,     0,     0,     0,     0,     0,
       0,     0,   217,     0,     0,     0,   221,     0,   222,   223,
     224,     0,   225,   226,   227,     0,   228,   229,   230,   231,
     232,   233,   234,   235,   236,     0,   237,   238,   239,     0,
     506,   240,   241,   242,   218,     0,     0,   219,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   215,   220,     0,     0,   216,
       0,     0,     0,     0,     0,     0,     0,   217,     0,     0,
       0,   221,     0,   222,   223,   224,     0,   225,   226,   227,
       0,   228,   229,   230,   231,   232,   233,   234,   235,   236,
       0,   237,   238,   239,     0,   507,   240,   241,   242,   218,
       0,     0,   219,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     215,   220,     0,     0,   216,     0,     0,     0,     0,     0,
       0,     0,   217,     0,     0,     0,   221,     0,   222,   223,
     224,     0,   225,   226,   227,     0,   228,   229,   230,   231,
     232,   233,   234,   235,   236,     0,   237,   238,   239,     0,
     508,   240,   241,   242,   218,   113,     0,   219,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   215,   220,     0,     0,   216,
       0,     0,     0,     0,     0,     0,     0,   217,     0,     0,
       0,   221,     0,   222,   223,   224,     0,   225,   226,   227,
       0,   228,   229,   230,   231,   232,   233,   234,   235,   236,
       0,   237,   238,   239,     0,     0,   240,   241,   242,   218,
       0,     0,   219,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     215,   220,     0,     0,   216,     0,     0,     0,     0,     0,
       0,     0,   217,     0,     0,   544,   221,     0,   222,   223,
     224,     0,   225,   226,   227,     0,   228,   229,   230,   231,
     232,   233,   234,   235,   236,     0,   237,   238,   239,     0,
     523,   240,   241,   242,   218,     0,     0,   219,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   215,   220,     0,     0,   216,
       0,     0,     0,     0,     0,     0,     0,   217,     0,     0,
       0,   221,     0,   222,   223,   224,     0,   225,   226,   227,
       0,   228,   229,   230,   231,   232,   233,   234,   235,   236,
       0,   237,   238,   239,     0,     0,   240,   241,   242,   218,
       0,     0,   219,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     574,   220,   215,     0,     0,     0,   216,     0,     0,     0,
       0,     0,     0,     0,   217,   620,   221,     0,   222,   223,
     224,     0,   225,   226,   227,     0,   228,   229,   230,   231,
     232,   233,   234,   235,   236,     0,   237,   238,   239,     0,
       0,   240,   241,   242,     0,     0,   218,     0,     0,   219,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   215,   220,     0,
       0,   216,     0,     0,     0,     0,     0,     0,     0,   217,
     623,     0,     0,   221,     0,   222,   223,   224,     0,   225,
     226,   227,     0,   228,   229,   230,   231,   232,   233,   234,
     235,   236,     0,   237,   238,   239,     0,     0,   240,   241,
     242,   218,     0,     0,   219,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   215,   220,     0,     0,   216,     0,     0,     0,
       0,     0,     0,     0,   217,     0,     0,     0,   221,     0,
     222,   223,   224,     0,   225,   226,   227,     0,   228,   229,
     230,   231,   232,   233,   234,   235,   236,     0,   237,   238,
     239,     0,     0,   240,   241,   242,   218,     0,     0,   219,
       0,     0,     0,     0,     0,     0,   668,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   215,   220,     0,
       0,   216,     0,     0,     0,     0,     0,     0,     0,   217,
       0,     0,     0,   221,     0,   222,   223,   224,     0,   225,
     226,   227,     0,   228,   229,   230,   231,   232,   233,   234,
     235,   236,     0,   237,   238,   239,     0,     0,   240,   241,
     242,   218,     0,     0,   219,     0,     0,     0,     0,     0,
       0,   671,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   215,   220,     0,     0,   216,     0,     0,     0,
       0,     0,     0,     0,   217,     0,     0,     0,   221,     0,
     222,   223,   224,     0,   225,   226,   227,     0,   228,   229,
     230,   231,   232,   233,   234,   235,   236,     0,   237,   238,
     239,     0,     0,   240,   241,   242,   218,     0,     0,   219,
       0,     0,     0,     0,     0,     0,   737,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   215,   220,     0,
       0,   216,     0,     0,     0,     0,     0,     0,     0,   217,
       0,     0,     0,   221,     0,   222,   223,   224,     0,   225,
     226,   227,     0,   228,   229,   230,   231,   232,   233,   234,
     235,   236,     0,   237,   238,   239,     0,     0,   240,   241,
     242,   218,     0,     0,   219,     0,     0,     0,     0,     0,
       0,   738,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   215,   220,     0,     0,   216,     0,     0,     0,
       0,     0,     0,     0,   217,     0,     0,     0,   221,     0,
     222,   223,   224,     0,   225,   226,   227,     0,   228,   229,
     230,   231,   232,   233,   234,   235,   236,     0,   237,   238,
     239,     0,     0,   240,   241,   242,   218,     0,     0,   219,
       0,     0,     0,     0,     0,     0,   739,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   215,   220,     0,
       0,   216,     0,     0,     0,     0,     0,     0,     0,   217,
       0,     0,     0,   221,     0,   222,   223,   224,     0,   225,
     226,   227,     0,   228,   229,   230,   231,   232,   233,   234,
     235,   236,     0,   237,   238,   239,     0,     0,   240,   241,
     242,   218,     0,     0,   219,     0,     0,     0,     0,     0,
       0,   740,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   215,   220,     0,     0,   216,     0,     0,     0,
       0,     0,     0,     0,   217,     0,     0,     0,   221,     0,
     222,   223,   224,     0,   225,   226,   227,     0,   228,   229,
     230,   231,   232,   233,   234,   235,   236,     0,   237,   238,
     239,     0,     0,   240,   241,   242,   218,     0,     0,   219,
       0,     0,     0,     0,     0,     0,   741,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   215,   220,     0,
       0,   216,     0,     0,     0,     0,     0,     0,     0,   217,
       0,     0,     0,   221,     0,   222,   223,   224,     0,   225,
     226,   227,     0,   228,   229,   230,   231,   232,   233,   234,
     235,   236,     0,   237,   238,   239,     0,     0,   240,   241,
     242,   218,     0,     0,   219,     0,     0,     0,     0,     0,
       0,   742,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   215,   220,     0,     0,   216,     0,     0,     0,
       0,     0,     0,     0,   217,     0,     0,     0,   221,     0,
     222,   223,   224,     0,   225,   226,   227,     0,   228,   229,
     230,   231,   232,   233,   234,   235,   236,     0,   237,   238,
     239,     0,     0,   240,   241,   242,   218,     0,     0,   219,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   220,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   217,
       0,     0,     0,   221,     0,   222,   223,   224,     0,   225,
     226,   227,     0,   228,   229,   230,   231,   232,   233,   234,
     235,   236,     0,   237,   238,   239,     0,     0,   240,   241,
     242,   218,     0,     0,   219,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   220,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   217,     0,     0,     0,   221,     0,
     222,   223,   224,     0,   225,   226,   227,     0,   228,   229,
     230,   231,     0,   233,   234,   235,   236,     0,   237,   238,
     239,     0,     0,   240,   241,   242,   218,     0,     0,   219,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   220,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   221,     0,   222,   223,   224,     0,   225,
     226,     0,     0,   228,   229,   230,   231,     0,   233,   234,
     235,   236,     0,   237,   238,   239,     0,     0,   240,   241,
     242
};

static const yytype_int16 yycheck[] =
{
      10,     2,   134,    31,    14,    13,   303,    17,   147,   148,
     142,   321,     1,    23,    24,    25,   560,     3,    48,     3,
       3,   160,    32,     1,    34,    22,    36,    37,   167,     3,
      40,    41,    42,    43,   662,    65,    46,    22,    48,    49,
      50,   180,   453,    53,    18,    45,    56,    57,    58,    22,
      60,    31,    55,    63,    64,    65,    22,    31,   721,    55,
      34,    21,    31,    31,    95,    76,    55,    95,   754,    69,
       3,     1,    46,    47,     1,    95,   704,    55,   764,    65,
      54,    70,    53,     0,    31,    56,   150,    31,    99,   120,
      64,   754,    70,    53,   124,    31,    56,   125,    23,   163,
       3,    31,   646,   123,    31,    94,   170,    54,   118,   119,
     120,   121,   122,   123,   124,    95,    94,   120,   114,   308,
      23,   121,   130,   120,   120,   114,    95,    95,   138,    95,
     694,   120,   321,   272,    94,   120,   122,    97,   122,   122,
     150,   101,   120,   173,    74,   556,    76,   120,   122,    76,
      76,    95,    76,   163,   120,   452,   125,   125,    95,    95,
     170,    64,     3,   173,    94,    95,    95,    94,    95,    95,
     734,    95,    95,    99,    95,    99,   720,    35,    74,    45,
      76,   125,   192,   122,   114,   124,   123,   114,   189,   125,
     122,    54,   124,    51,   258,   259,   125,   123,     7,   123,
     123,    61,   123,    69,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,    57,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
     260,   261,   663,   550,   318,   121,   286,    95,    64,    95,
      18,   271,    14,   122,   114,   124,   276,    94,    18,   122,
      97,    95,     3,     3,   101,   122,   286,     8,   114,   122,
     290,   291,     2,   293,   294,   123,   296,    18,    18,    47,
      10,   430,   431,   218,   219,   434,   435,    47,    18,   123,
      52,   311,   122,    95,    35,    35,    64,   333,   318,   335,
      68,    31,   114,   114,    66,   325,    47,    47,    68,   119,
      51,    51,   114,   333,    95,   335,    46,   337,   338,   339,
     340,    95,    18,    64,    64,   260,   261,    68,    68,   471,
     650,   114,   114,    63,   654,    31,   271,    67,    34,   122,
     121,   124,   114,    95,   114,    17,    18,   121,    95,   114,
      46,    47,    95,    25,    26,    27,   291,   114,    54,   294,
     559,    33,   114,    35,   122,   120,   114,   114,    64,    71,
     120,   114,   521,   522,    97,    47,   122,    49,   122,    51,
     122,    76,   531,   114,   114,   405,   406,   407,   408,   409,
     410,   411,    64,     2,   412,   413,    68,   417,   418,     7,
     420,    10,   337,   120,   114,   425,    95,   123,   428,    18,
     114,    31,   432,    24,   123,   455,    95,    31,   210,   211,
     212,   151,    31,   123,    74,    76,   123,    95,   468,   123,
      94,    47,   123,   125,    76,   455,    24,    46,   458,   459,
     123,    55,   114,   123,   484,   120,   645,   125,   468,   121,
      22,   650,    22,    94,    63,   654,    70,    95,    67,   189,
     125,    97,    76,   122,   484,   123,    70,   345,   662,    16,
     467,   406,   529,   408,   665,   708,   666,   548,   577,   490,
     734,    95,     2,   720,   706,   312,   682,    -1,   420,    -1,
      10,    -1,    -1,   513,    -1,    -1,   516,    -1,    18,    -1,
     114,    -1,    21,   652,    -1,   114,   120,    -1,   528,    -1,
      -1,    31,    -1,    -1,   534,    -1,   536,    -1,    -1,   539,
      -1,   541,   721,    -1,   544,   565,    46,    -1,    -1,    -1,
      -1,   730,   262,    -1,    53,   265,    -1,    56,    -1,    -1,
      17,    18,   151,    63,    -1,   565,    -1,    67,    25,    26,
      27,    -1,   572,   573,   574,   754,    33,   287,    35,    -1,
     290,    -1,    -1,   293,    -1,   764,   296,    -1,    -1,    -1,
      47,    -1,    49,    -1,    51,    94,    -1,    96,    97,    -1,
     189,    -1,   101,    -1,    -1,    -1,    -1,    64,   107,   108,
      -1,    68,    -1,   112,   114,    -1,   115,   116,   117,   619,
     620,    -1,   622,   623,   624,   625,    -1,    -1,   338,    -1,
      -1,   631,   632,    -1,   634,   345,   636,   637,    -1,   639,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    21,    -1,   649,
     650,   151,    -1,    -1,   654,   655,    -1,   114,   658,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   686,    -1,   668,   669,
     670,   671,   672,   673,   674,   675,   265,    -1,    -1,    53,
      -1,    -1,    56,    -1,   684,   685,   686,    -1,    -1,   189,
     690,    -1,    -1,   693,    -1,    -1,    -1,    -1,   287,    -1,
      -1,   290,    -1,    -1,   293,    -1,    -1,   296,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   716,   717,   718,   719,
      94,    -1,    96,    97,    -1,    -1,    -1,   101,   438,    -1,
     730,   731,   732,    -1,   108,    -1,    31,   737,   738,   739,
     740,   741,   742,   117,    -1,    -1,    -1,    -1,    -1,   338,
      -1,    -1,    -1,   753,   754,    -1,   345,    -1,    -1,    -1,
      55,    -1,    -1,    -1,   764,   265,    -1,    -1,    -1,     2,
      -1,    -1,    -1,    -1,    -1,    70,    -1,    10,    31,    -1,
     490,    76,    -1,    -1,    -1,    18,    -1,   287,    -1,    -1,
     290,    -1,    -1,   293,    -1,    -1,   296,    64,    31,    -1,
      95,   511,    55,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    21,     2,    46,    -1,    -1,    -1,    70,    -1,   114,
      10,    -1,    -1,    76,   534,   120,   536,    -1,    18,   539,
      63,   541,    -1,   543,    67,    -1,    -1,    -1,   338,    -1,
      -1,    31,    95,    53,    -1,   345,    56,    -1,    -1,   438,
      -1,    -1,    -1,    -1,   564,    -1,    46,    -1,    -1,    -1,
      -1,   114,   572,   573,    -1,    -1,    -1,   120,    -1,    -1,
      -1,   138,    -1,    63,    -1,    -1,    -1,    67,    -1,    -1,
      -1,   114,    21,   150,    94,    -1,    96,    97,    -1,    -1,
      -1,   101,    -1,    -1,    -1,    -1,   163,   107,   108,    -1,
      -1,   490,   112,   170,    -1,    -1,    -1,   117,    -1,    -1,
      -1,    -1,    -1,    -1,    53,    -1,    -1,    56,   151,    -1,
      -1,   631,    -1,    -1,   114,    -1,   636,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   438,    -1,
      -1,    -1,    -1,    -1,    -1,   534,    -1,   536,    -1,    -1,
     539,    -1,   541,    -1,   543,    94,   189,    96,    97,    -1,
      -1,   151,   101,   102,   103,    -1,   105,   106,   107,   108,
      -1,    -1,    -1,   112,    -1,   564,   115,   116,   117,    -1,
      -1,    -1,    -1,   572,   573,    -1,    -1,    -1,    -1,    -1,
     490,   258,   259,    -1,    -1,    -1,    -1,    -1,    -1,   189,
      -1,    -1,    -1,    -1,    -1,    -1,   716,   717,   718,   719,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   731,   732,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   265,    -1,   534,    -1,   536,    -1,    -1,   539,
      -1,   541,   631,   543,    -1,    -1,    -1,   636,    -1,    -1,
      -1,   318,    -1,    -1,   287,    -1,    -1,   290,   325,    -1,
     293,    -1,    -1,   296,   564,    -1,   333,    -1,   335,    -1,
      -1,    -1,   572,   573,    -1,   265,    -1,    -1,    -1,     2,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    10,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    18,    -1,   287,    -1,    -1,
     290,    -1,    -1,   293,    -1,   338,   296,    -1,    31,    -1,
      -1,    -1,   345,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    46,    -1,    -1,    -1,   716,   717,   718,
     719,   631,    -1,     2,    -1,    -1,   636,    -1,    -1,    -1,
      63,    10,   731,   732,    67,    -1,    -1,    -1,   338,    18,
      -1,   418,    -1,   420,    -1,   345,    -1,    -1,    -1,    -1,
      -1,    -1,    31,    -1,    -1,    -1,    -1,    -1,     2,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    10,    46,    -1,    -1,
      -1,    -1,    -1,    -1,    18,    -1,    -1,    -1,    -1,    -1,
      -1,   114,    21,    -1,    63,    -1,    -1,    31,    67,    -1,
      -1,    -1,    -1,    -1,    -1,   438,    -1,    -1,    -1,    -1,
      -1,    -1,    46,    -1,    -1,    -1,   716,   717,   718,   719,
      -1,    -1,    -1,    -1,    53,    -1,    -1,    56,   151,    63,
      -1,   731,   732,    67,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   114,    75,    -1,   438,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   490,    -1,    -1,
      -1,    90,    -1,    92,    93,    94,   189,    96,    97,    -1,
      -1,   100,   101,   102,   103,    -1,   105,   106,   107,   108,
     114,   110,   151,   112,    -1,    -1,   115,   116,   117,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     490,   534,    -1,   536,    -1,    -1,   539,    -1,   541,    -1,
     543,    -1,    -1,    -1,    -1,    -1,    -1,   151,    -1,    -1,
     189,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   564,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   572,
     573,    -1,   265,    -1,   534,    -1,   536,    -1,    -1,   539,
      -1,   541,    -1,   543,    -1,   189,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   287,    -1,    -1,   290,    -1,    -1,
     293,    -1,    -1,   296,   564,    -1,    -1,    -1,   645,    -1,
      -1,    -1,   572,   573,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   265,    -1,   631,    -1,
      -1,    -1,    -1,   636,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   338,    -1,    -1,   287,    -1,
      -1,   290,   345,   690,   293,    -1,    -1,   296,    -1,    -1,
      -1,   265,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   631,    -1,    -1,    -1,    -1,   636,    -1,    -1,    -1,
      -1,    -1,    -1,   287,   721,    -1,   290,    -1,    -1,   293,
      -1,    -1,   296,    -1,    -1,    -1,    -1,    -1,    -1,   338,
      -1,    -1,    -1,    -1,    -1,    -1,   345,    -1,    -1,    -1,
      -1,    -1,    -1,   716,   717,   718,   719,   754,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   764,   731,   732,
      -1,    -1,    -1,    -1,   338,    -1,    -1,   117,    -1,    -1,
      -1,   345,    -1,    -1,    -1,   438,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   716,   717,   718,   719,
      -1,    -1,    -1,    -1,    -1,    -1,   146,   147,   148,   149,
      -1,   731,   732,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     160,    -1,    -1,    -1,    -1,    -1,    -1,   167,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   490,    -1,   438,
     180,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      12,    -1,    -1,    -1,    16,    -1,    -1,    -1,    20,    21,
      22,    -1,    -1,    -1,   438,    -1,    28,    -1,    30,    -1,
      -1,   534,    -1,   536,     2,    -1,   539,    -1,   541,    -1,
     543,   490,    10,    -1,    -1,    47,    -1,    -1,    -1,    -1,
      18,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   564,    -1,    31,    -1,    -1,    -1,    -1,    -1,   572,
     573,    -1,    -1,    -1,    -1,    -1,   490,    -1,    46,    -1,
      -1,    -1,   272,    -1,    86,   534,    -1,   536,    -1,    -1,
     539,    -1,   541,    -1,   543,    63,    -1,    -1,    -1,    67,
      -1,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,   564,    -1,    -1,    -1,    -1,
     534,    -1,   536,   572,   573,   539,    -1,   541,   631,   543,
      -1,    -1,   134,   636,    -1,    -1,   138,    -1,    -1,    -1,
     142,    -1,   144,   118,   119,    -1,   114,   122,   150,   124,
     564,   153,    -1,    -1,    -1,    -1,    -1,    -1,   572,   573,
      -1,   163,    -1,    -1,    -1,    -1,    -1,    -1,   170,    -1,
      -1,    -1,    -1,    -1,   176,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   631,   151,    -1,    -1,    -1,   636,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   205,    -1,    -1,    -1,    -1,   210,   211,
     212,    -1,    -1,   716,   717,   718,   719,   631,    -1,    -1,
      -1,   189,   636,    -1,   226,    -1,    -1,    -1,   731,   732,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     430,   431,    -1,    -1,   434,   435,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   258,   259,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   716,   717,   718,
     719,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   283,   731,   732,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   265,    -1,    -1,
      -1,   303,   716,   717,   718,   719,    -1,    -1,    -1,    -1,
     312,    -1,    -1,    -1,    -1,    -1,   318,   731,   732,   287,
      -1,    -1,   290,    -1,    -1,   293,    -1,    -1,    -1,    -1,
      -1,   521,   522,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   531,    -1,   533,    -1,    -1,    -1,    -1,   538,    -1,
      -1,    -1,    -1,     3,     4,     5,     6,     7,    -1,    -1,
      10,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     338,    -1,    -1,    23,    -1,    -1,    -1,   345,    28,    29,
      30,    -1,    32,    -1,    -1,    -1,    -1,    37,    38,    -1,
      40,    -1,    42,    43,    -1,    -1,    -1,    -1,    48,    -1,
      50,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    59,
      60,    61,    62,    -1,    -1,    -1,    -1,    -1,   420,    -1,
      -1,    -1,    -1,    -1,     1,    -1,     3,     4,     5,     6,
       7,    -1,    -1,    10,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    91,    -1,    -1,    -1,    -1,    23,   449,    -1,    -1,
     452,    28,    29,    30,    -1,    32,    -1,    -1,    -1,   109,
      37,    38,   652,    40,    -1,    42,    43,    -1,    -1,   471,
     438,    48,   122,    50,   124,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    59,    60,    61,    62,   488,   677,   678,    -1,
     680,   681,    -1,    -1,    -1,    -1,    -1,    -1,    75,    -1,
      -1,    -1,    -1,    -1,   694,    -1,    -1,    -1,    -1,   699,
     700,    -1,    -1,    90,    91,    92,    93,    -1,    -1,    -1,
      -1,    98,   490,    -1,    -1,    -1,    -1,   529,    -1,    -1,
     107,    -1,   109,    -1,   111,   112,    -1,    -1,    -1,    -1,
     117,    -1,    -1,   120,   734,   122,    -1,   124,   550,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   534,    -1,   536,    -1,
      -1,   539,    -1,   541,    -1,   543,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   593,    -1,    -1,    -1,    -1,   564,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   572,   573,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     0,     1,    -1,
       3,     4,     5,     6,     7,    -1,    -1,    10,    11,    12,
      -1,    14,    15,    16,    17,    18,    19,    20,    -1,    22,
      23,    -1,    25,    26,    27,    28,    29,    30,    -1,    32,
      33,    -1,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    -1,   665,    47,    48,    49,    50,    51,    52,
      -1,    -1,    55,    -1,    57,    58,    59,    60,    61,    62,
      -1,    64,    -1,    66,    67,    68,    -1,    -1,    71,    72,
      -1,    -1,    75,    -1,    -1,    -1,    -1,    -1,    -1,   701,
     702,    -1,    -1,    -1,    -1,    -1,    -1,    90,    91,    92,
      93,    -1,    -1,    -1,    -1,    98,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   107,    -1,   109,    -1,   111,   112,
      -1,   114,    -1,    -1,   117,    -1,    -1,   120,    -1,   122,
       1,   124,     3,     4,     5,     6,     7,    -1,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      -1,    32,    33,    -1,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    -1,    -1,    47,    48,    -1,    50,
      51,    52,    53,    -1,    55,    56,    57,    58,    59,    60,
      61,    62,    -1,    64,    -1,    66,    67,    68,    -1,    -1,
      71,    72,    -1,    -1,    75,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    -1,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,    -1,   114,   115,   116,   117,    -1,    -1,   120,
     121,   122,     1,   124,     3,     4,     5,     6,     7,    -1,
      -1,    10,    11,    12,    -1,    14,    15,    16,    17,    18,
      19,    20,    -1,    22,    23,    -1,    25,    26,    27,    28,
      29,    30,    -1,    32,    33,    -1,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    -1,    -1,    47,    48,
      49,    50,    51,    52,    -1,    -1,    55,    -1,    57,    58,
      59,    60,    61,    62,    -1,    64,    -1,    66,    67,    68,
      -1,    -1,    71,    72,    -1,    -1,    75,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    90,    91,    92,    93,    -1,    -1,    -1,    -1,    98,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   107,    -1,
     109,    -1,   111,   112,   113,   114,    -1,    -1,   117,    -1,
      -1,   120,   121,   122,     1,   124,     3,     4,     5,     6,
       7,    -1,    -1,    10,    11,    12,    -1,    14,    15,    16,
      17,    18,    19,    20,    -1,    22,    23,    -1,    25,    26,
      27,    28,    29,    30,    -1,    32,    33,    -1,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    -1,    -1,
      47,    48,    49,    50,    51,    52,    -1,    -1,    55,    -1,
      57,    58,    59,    60,    61,    62,    -1,    64,    -1,    66,
      67,    68,    -1,    -1,    71,    72,    -1,    -1,    75,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    90,    91,    92,    93,    -1,    -1,    -1,
      -1,    98,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     107,    -1,   109,    -1,   111,   112,    -1,   114,    -1,    -1,
     117,    -1,    -1,   120,   121,   122,     1,   124,     3,     4,
       5,     6,     7,    -1,    -1,    10,    11,    12,    -1,    14,
      15,    16,    17,    18,    19,    20,    -1,    22,    23,    -1,
      25,    26,    27,    28,    29,    30,    -1,    32,    33,    -1,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      -1,    -1,    47,    48,    49,    50,    51,    52,    -1,    -1,
      55,    -1,    57,    58,    59,    60,    61,    62,    -1,    64,
      -1,    66,    67,    68,    -1,    -1,    71,    72,    -1,    -1,
      75,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    90,    91,    92,    93,    -1,
      -1,    -1,    -1,    98,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   107,    -1,   109,    -1,   111,   112,    -1,   114,
      -1,    -1,   117,    -1,    -1,   120,   121,   122,     1,   124,
       3,     4,     5,     6,     7,    -1,    -1,    10,    11,    12,
      -1,    14,    15,    16,    17,    18,    19,    20,    -1,    22,
      23,    -1,    25,    26,    27,    28,    29,    30,    -1,    32,
      33,    -1,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    -1,    -1,    47,    48,    49,    50,    51,    52,
      -1,    -1,    55,    -1,    57,    58,    59,    60,    61,    62,
      -1,    64,    -1,    66,    67,    68,    -1,    -1,    71,    72,
      -1,    -1,    75,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    90,    91,    92,
      93,    -1,    -1,    -1,    -1,    98,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   107,    -1,   109,    -1,   111,   112,
      -1,   114,    -1,    -1,   117,    -1,    -1,   120,   121,   122,
       1,   124,     3,     4,     5,     6,     7,    -1,    -1,    10,
      11,    12,    -1,    14,    15,    16,    17,    18,    19,    20,
      -1,    22,    23,    -1,    25,    26,    27,    28,    29,    30,
      -1,    32,    33,    -1,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    -1,    -1,    47,    48,    49,    50,
      51,    52,    -1,    -1,    55,    -1,    57,    58,    59,    60,
      61,    62,    -1,    64,    -1,    66,    67,    68,    -1,    -1,
      71,    72,    -1,    -1,    75,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    90,
      91,    92,    93,    -1,    -1,    -1,    -1,    98,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   107,    -1,   109,    -1,
     111,   112,    -1,   114,    -1,    -1,   117,    -1,    -1,   120,
     121,   122,     1,   124,     3,     4,     5,     6,     7,    -1,
      -1,    10,    11,    12,    -1,    14,    15,    16,    17,    18,
      19,    20,    -1,    22,    23,    -1,    25,    26,    27,    28,
      29,    30,    -1,    32,    33,    -1,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    -1,    -1,    47,    48,
      49,    50,    51,    52,    -1,    -1,    55,    -1,    57,    58,
      59,    60,    61,    62,    -1,    64,    -1,    66,    67,    68,
      -1,    -1,    71,    72,    -1,    -1,    75,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    90,    91,    92,    93,    -1,    -1,    -1,    -1,    98,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   107,    -1,
     109,    -1,   111,   112,    -1,   114,    -1,    -1,   117,    -1,
      -1,   120,    -1,   122,     1,   124,     3,     4,     5,     6,
       7,    -1,    -1,    10,    11,    12,    -1,    14,    15,    16,
      17,    18,    19,    20,    -1,    22,    23,    -1,    25,    26,
      27,    28,    29,    30,    -1,    32,    33,    -1,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    -1,    -1,
      47,    48,    -1,    50,    51,    52,    -1,    -1,    55,    -1,
      57,    58,    59,    60,    61,    62,    -1,    64,    -1,    66,
      67,    68,    -1,    -1,    71,    72,    -1,    -1,    75,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    90,    91,    92,    93,    -1,    -1,    -1,
      -1,    98,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     107,    -1,   109,    -1,   111,   112,    -1,   114,    -1,    -1,
     117,    -1,    -1,   120,    -1,   122,     1,   124,     3,     4,
       5,     6,     7,    -1,    -1,    10,    11,    12,    -1,    14,
      15,    16,    17,    18,    19,    20,    -1,    22,    23,    -1,
      25,    26,    27,    28,    29,    30,    -1,    32,    33,    -1,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      -1,    -1,    47,    48,    -1,    50,    51,    52,    -1,    -1,
      55,    -1,    57,    58,    59,    60,    61,    62,    -1,    64,
      -1,    66,    67,    68,    -1,    -1,    71,    72,    -1,    -1,
      75,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    90,    91,    92,    93,    -1,
      -1,    -1,    -1,    98,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   107,    -1,   109,    -1,   111,   112,    -1,   114,
      -1,    -1,   117,    -1,    -1,   120,    -1,   122,     1,   124,
       3,     4,     5,     6,     7,    -1,    -1,    10,    11,    12,
      -1,    14,    15,    16,    17,    18,    19,    20,    -1,    22,
      23,    -1,    25,    26,    27,    28,    29,    30,    -1,    32,
      33,    -1,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    -1,    -1,    47,    48,    -1,    50,    51,    52,
      -1,    -1,    55,    -1,    57,    58,    59,    60,    61,    62,
      -1,    64,    -1,    66,    67,    68,    -1,    -1,    71,    72,
      -1,    -1,    75,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    90,    91,    92,
      93,    -1,    -1,    -1,    -1,    98,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   107,    -1,   109,    -1,   111,   112,
      -1,   114,    -1,    -1,   117,    -1,    -1,   120,    -1,   122,
       1,   124,     3,     4,     5,     6,     7,    -1,    -1,    10,
      11,    12,    -1,    14,    15,    16,    17,    18,    19,    20,
      -1,    22,    23,    -1,    25,    26,    27,    28,    29,    30,
      -1,    32,    33,    -1,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    -1,    -1,    47,    48,    -1,    50,
      51,    52,    -1,    -1,    55,    -1,    57,    58,    59,    60,
      61,    62,    -1,    64,    -1,    66,    67,    68,    -1,    -1,
      71,    72,    -1,    -1,    75,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    90,
      91,    92,    93,    -1,    -1,    -1,    -1,    98,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   107,    -1,   109,    -1,
     111,   112,    -1,   114,    -1,    -1,   117,    -1,    -1,   120,
      -1,   122,     1,   124,     3,     4,     5,     6,     7,    -1,
      -1,    10,    11,    12,    -1,    14,    15,    16,    17,    18,
      19,    20,    -1,    22,    23,    -1,    25,    26,    27,    28,
      29,    30,    -1,    32,    33,    -1,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    -1,    -1,    47,    48,
      -1,    50,    51,    52,    -1,    -1,    55,    -1,    57,    58,
      59,    60,    61,    62,    -1,    64,    -1,    66,    67,    68,
      -1,    -1,    71,    72,    -1,    -1,    75,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    90,    91,    92,    93,    -1,    -1,    -1,    -1,    98,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   107,    -1,
     109,    -1,   111,   112,    -1,   114,    -1,    -1,   117,    -1,
      -1,   120,    -1,   122,     1,   124,     3,     4,     5,     6,
       7,    -1,    -1,    10,    11,    12,    -1,    14,    15,    16,
      17,    18,    19,    20,    -1,    22,    23,    -1,    25,    26,
      27,    28,    29,    30,    -1,    32,    33,    -1,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    -1,    -1,
      47,    48,    -1,    50,    51,    52,    -1,    -1,    55,    -1,
      57,    58,    59,    60,    61,    62,    -1,    64,    -1,    66,
      67,    68,    -1,    -1,    71,    72,    -1,    -1,    75,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    90,    91,    92,    93,    -1,    -1,    -1,
      -1,    98,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     107,    -1,   109,    -1,   111,   112,    -1,   114,    -1,    -1,
     117,    -1,    -1,   120,    -1,   122,     1,   124,     3,     4,
       5,     6,     7,    -1,    -1,    10,    11,    12,    -1,    14,
      15,    16,    17,    18,    19,    20,    -1,    22,    23,    -1,
      25,    26,    27,    28,    29,    30,    -1,    32,    33,    -1,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      -1,    -1,    47,    48,    -1,    50,    51,    52,    -1,    -1,
      55,    -1,    57,    58,    59,    60,    61,    62,    -1,    64,
      -1,    66,    67,    68,    -1,    -1,    71,    72,    -1,    -1,
      75,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    90,    91,    92,    93,    -1,
      -1,    -1,    -1,    98,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   107,    -1,   109,    -1,   111,   112,    -1,   114,
      -1,    -1,   117,    -1,    -1,   120,    -1,   122,     1,   124,
       3,     4,     5,     6,     7,    -1,    -1,    10,    11,    12,
      -1,    14,    15,    16,    17,    18,    19,    20,    -1,    22,
      23,    -1,    25,    26,    27,    28,    29,    30,    -1,    32,
      33,    -1,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    -1,    -1,    47,    48,    -1,    50,    51,    52,
      -1,    -1,    55,    -1,    57,    58,    59,    60,    61,    62,
      -1,    64,    -1,    66,    67,    68,    -1,    -1,    71,    72,
      -1,    -1,    75,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    90,    91,    92,
      93,    -1,    -1,    -1,    -1,    98,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   107,    -1,   109,    -1,   111,   112,
      -1,   114,    -1,    -1,   117,    -1,    -1,   120,    -1,   122,
       1,   124,     3,     4,     5,     6,     7,    -1,    -1,    10,
      11,    12,    -1,    14,    15,    16,    17,    18,    19,    20,
      -1,    22,    23,    -1,    25,    26,    27,    28,    29,    30,
      -1,    32,    33,    -1,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    -1,    -1,    47,    48,    -1,    50,
      51,    52,    -1,    -1,    55,    -1,    57,    58,    59,    60,
      61,    62,    -1,    64,    -1,    66,    67,    68,    -1,    -1,
      71,    72,    -1,    -1,    75,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    90,
      91,    92,    93,    -1,    -1,    -1,    -1,    98,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   107,    -1,   109,    -1,
     111,   112,    -1,   114,    -1,    -1,   117,    -1,    -1,   120,
      -1,   122,     1,   124,     3,     4,     5,     6,     7,    -1,
       9,    10,    -1,    -1,    13,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    21,    -1,    23,    -1,    -1,    -1,    -1,    28,
      29,    30,    -1,    32,    -1,    -1,    -1,    -1,    37,    38,
      -1,    40,    -1,    42,    43,    -1,    -1,    -1,    -1,    48,
      -1,    50,    -1,    -1,    53,    -1,    -1,    56,    -1,    -1,
      59,    60,    61,    62,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    74,    75,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    90,    91,    92,    93,    94,    -1,    96,    97,    98,
      -1,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,    -1,    21,   115,   116,   117,    -1,
      -1,   120,    -1,   122,     1,   124,     3,     4,     5,     6,
       7,    -1,     9,    10,    -1,    -1,    13,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    21,    -1,    23,    53,    -1,    -1,
      56,    28,    29,    30,    -1,    32,    -1,    -1,    -1,    -1,
      37,    38,    -1,    40,    -1,    42,    43,    -1,    -1,    -1,
      -1,    48,    -1,    50,    -1,    -1,    53,    -1,    -1,    56,
      -1,    -1,    59,    60,    61,    62,    -1,    -1,    94,    -1,
      96,    97,    -1,    -1,   100,   101,   102,   103,    75,   105,
     106,   107,   108,    -1,   110,    -1,   112,    -1,    -1,   115,
     116,   117,    -1,    90,    91,    92,    93,    94,    -1,    96,
      97,    98,    -1,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,    -1,    -1,   115,   116,
     117,    -1,    -1,   120,    -1,   122,     1,   124,     3,     4,
       5,     6,     7,    -1,    -1,    10,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    23,    -1,
      -1,    -1,    -1,    28,    29,    30,    -1,    32,    -1,    -1,
      -1,    -1,    37,    38,    -1,    40,    -1,    42,    43,    -1,
      -1,    -1,    -1,    48,    -1,    50,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    59,    60,    61,    62,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      75,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    90,    91,    92,    93,    -1,
      -1,    -1,    -1,    98,    -1,    -1,     3,     4,     5,     6,
       7,    -1,   107,    10,   109,    -1,   111,   112,    -1,    -1,
      -1,    -1,   117,    -1,    -1,   120,    23,   122,    -1,   124,
      -1,    28,    29,    30,    -1,    32,    -1,    -1,    -1,    -1,
      37,    38,    -1,    40,    -1,    42,    43,    -1,    -1,    -1,
      -1,    48,    -1,    50,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    59,    60,    61,    62,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    75,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    90,    91,    92,    93,    -1,    -1,    -1,
      -1,    98,    -1,    -1,     3,     4,     5,     6,     7,    -1,
     107,    10,   109,    -1,   111,   112,   113,    -1,    -1,    -1,
     117,    -1,    -1,   120,    23,   122,    -1,   124,   125,    28,
      29,    30,    -1,    32,    -1,    -1,    -1,    -1,    37,    38,
      -1,    40,    -1,    42,    43,    -1,    -1,    -1,    -1,    48,
      -1,    50,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      59,    60,    61,    62,    -1,    -1,    65,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    75,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    90,    91,    92,    93,    -1,    -1,    -1,    -1,    98,
      99,    -1,     3,     4,     5,     6,     7,    -1,   107,    10,
     109,    -1,   111,   112,   113,    -1,    -1,    -1,   117,    -1,
      -1,   120,    23,   122,    -1,   124,    -1,    28,    29,    30,
      -1,    32,    -1,    -1,    -1,    -1,    37,    38,    -1,    40,
      -1,    42,    43,    -1,    -1,    -1,    -1,    48,    -1,    50,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    59,    60,
      61,    62,    -1,    -1,    65,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    75,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    90,
      91,    92,    93,    -1,    -1,    -1,    -1,    98,    -1,    -1,
       3,     4,     5,     6,     7,    -1,   107,    10,   109,    -1,
     111,   112,   113,    -1,    -1,    -1,   117,    -1,    -1,   120,
      23,   122,   123,   124,    -1,    28,    29,    30,    -1,    32,
      -1,    -1,    -1,    -1,    37,    38,    -1,    40,    -1,    42,
      43,    -1,    -1,    -1,    47,    48,    -1,    50,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    59,    60,    61,    62,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      73,    -1,    75,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    90,    91,    92,
      93,    -1,    -1,    -1,    -1,    98,    -1,    -1,     3,     4,
       5,     6,     7,    -1,   107,    10,   109,    -1,   111,   112,
      -1,    -1,    -1,    -1,   117,    -1,    -1,   120,    23,   122,
      -1,   124,    -1,    28,    29,    30,    -1,    32,    -1,    -1,
      -1,    -1,    37,    38,    -1,    40,    -1,    42,    43,    -1,
      -1,    -1,    -1,    48,    -1,    50,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    59,    60,    61,    62,    -1,    -1,
      65,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      75,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    90,    91,    92,    93,    -1,
      -1,    -1,    -1,    98,    -1,    -1,     3,     4,     5,     6,
       7,    -1,   107,    10,   109,    -1,   111,   112,   113,    -1,
      -1,    -1,   117,    -1,    -1,   120,    23,   122,    -1,   124,
      -1,    28,    29,    30,    -1,    32,    -1,    -1,    -1,    -1,
      37,    38,    -1,    40,    -1,    42,    43,    -1,    -1,    -1,
      -1,    48,    -1,    50,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    59,    60,    61,    62,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    75,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    90,    91,    92,    93,    -1,    -1,    -1,
      -1,    98,    -1,    -1,     3,     4,     5,     6,     7,    -1,
     107,    10,   109,    -1,   111,   112,    -1,   114,    -1,    -1,
     117,    -1,    -1,   120,    23,   122,    -1,   124,    -1,    28,
      29,    30,    -1,    32,    -1,    -1,    -1,    -1,    37,    38,
      -1,    40,    -1,    42,    43,    -1,    -1,    -1,    -1,    48,
      -1,    50,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      59,    60,    61,    62,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    75,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    90,    91,    92,    93,    -1,    -1,    -1,    -1,    98,
      -1,    -1,     3,     4,     5,     6,     7,    -1,   107,    10,
     109,    -1,   111,   112,   113,    -1,    -1,    -1,   117,    -1,
      -1,   120,    23,   122,    -1,   124,    -1,    28,    29,    30,
      -1,    32,    -1,    -1,    -1,    -1,    37,    38,    -1,    40,
      -1,    42,    43,    -1,    -1,    -1,    -1,    48,    -1,    50,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    59,    60,
      61,    62,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    73,    -1,    75,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    90,
      91,    92,    93,    -1,    -1,    -1,    -1,    98,    -1,    -1,
       3,     4,     5,     6,     7,    -1,   107,    10,   109,    -1,
     111,   112,    -1,    -1,    -1,    -1,   117,    -1,    -1,   120,
      23,   122,    -1,   124,    -1,    28,    29,    30,    -1,    32,
      -1,    -1,    -1,    -1,    37,    38,    -1,    40,    -1,    42,
      43,    -1,    -1,    -1,    -1,    48,    -1,    50,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    59,    60,    61,    62,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    75,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    90,    91,    92,
      93,    -1,    -1,    -1,    -1,    98,    -1,    -1,     3,     4,
       5,     6,     7,    -1,   107,    10,   109,    -1,   111,   112,
     113,    -1,    -1,    -1,   117,    -1,    -1,   120,    23,   122,
      -1,   124,    -1,    28,    29,    30,    -1,    32,    -1,    -1,
      -1,    -1,    37,    38,    -1,    40,    -1,    42,    43,    -1,
      -1,    -1,    -1,    48,    -1,    50,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    59,    60,    61,    62,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      75,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    90,    91,    92,    93,    -1,
      -1,    -1,    -1,    98,    -1,    -1,     3,     4,     5,     6,
       7,    -1,   107,    10,   109,    -1,   111,   112,   113,    -1,
      -1,    -1,   117,    -1,    -1,   120,    23,   122,    -1,   124,
      -1,    28,    29,    30,    -1,    32,    -1,    -1,    -1,    -1,
      37,    38,    -1,    40,    -1,    42,    43,    -1,    -1,    -1,
      -1,    48,    -1,    50,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    59,    60,    61,    62,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    75,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    90,    91,    92,    93,    -1,    -1,    -1,
      -1,    98,    -1,    -1,     3,     4,     5,     6,     7,    -1,
     107,    10,   109,    -1,   111,   112,   113,    -1,    -1,    -1,
     117,    -1,    -1,   120,    23,   122,    -1,   124,    -1,    28,
      29,    30,    -1,    32,    -1,    -1,    -1,    -1,    37,    38,
      -1,    40,    -1,    42,    43,    -1,    -1,    -1,    -1,    48,
      -1,    50,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      59,    60,    61,    62,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    75,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    90,    91,    92,    93,    -1,    -1,    -1,    -1,    98,
      -1,    -1,     3,     4,     5,     6,     7,    -1,   107,    10,
     109,    -1,   111,   112,    -1,    -1,    -1,    -1,   117,    -1,
      -1,   120,    23,   122,    -1,   124,    -1,    28,    29,    30,
      -1,    32,    -1,    -1,    -1,    -1,    37,    38,    -1,    40,
      -1,    42,    43,    -1,    -1,    -1,    -1,    48,    -1,    50,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    59,    60,
      61,    62,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    75,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    90,
      91,    92,    93,    -1,    -1,    -1,    -1,    98,    -1,    -1,
       3,     4,     5,     6,     7,    -1,   107,    10,   109,    -1,
     111,   112,    -1,    -1,    -1,    -1,   117,    -1,    -1,   120,
      23,   122,    -1,   124,    -1,    28,    29,    30,    -1,    32,
      -1,    -1,    -1,    -1,    37,    38,    -1,    40,    -1,    42,
      43,    -1,    -1,    -1,    -1,    48,    -1,    50,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    59,    60,    61,    62,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    75,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    90,    91,    92,
      93,    -1,    -1,    -1,    -1,    98,    -1,    -1,     3,     4,
       5,     6,     7,    -1,   107,    10,   109,    -1,   111,   112,
      -1,    -1,    -1,    -1,   117,    -1,    -1,   120,    23,   122,
      -1,   124,    -1,    28,    29,    30,    -1,    32,    -1,    -1,
      -1,    -1,    37,    38,    -1,    40,    -1,    42,    43,    -1,
      -1,    -1,    -1,    48,    -1,    50,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    59,    60,    61,    62,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      75,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    90,    91,    92,    93,    -1,
      -1,    -1,    -1,    98,    -1,    -1,     3,     4,     5,     6,
       7,    -1,   107,    10,   109,    -1,   111,   112,    -1,    -1,
      -1,    -1,   117,    -1,    -1,   120,    23,   122,    -1,   124,
      -1,    28,    29,    30,    -1,    32,    -1,    -1,    -1,    -1,
      37,    38,    -1,    40,    -1,    42,    43,    -1,    -1,    -1,
      -1,    48,    -1,    50,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    59,    60,    61,    62,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    75,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    90,    91,    92,    93,    -1,    -1,    -1,
      -1,    98,    -1,    -1,     3,     4,     5,     6,     7,    -1,
     107,    10,   109,    -1,   111,   112,    -1,    -1,    -1,    -1,
     117,    -1,    -1,   120,    23,   122,    -1,   124,    -1,    28,
      29,    30,    -1,    32,    -1,    -1,    -1,    -1,    37,    38,
      -1,    40,    -1,    42,    43,    -1,    -1,    -1,    -1,    48,
      -1,    50,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      59,    60,    61,    62,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    75,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    90,    91,    92,    93,    -1,    -1,    -1,    -1,    98,
      -1,    -1,     3,     4,     5,     6,     7,    -1,   107,    10,
     109,    -1,   111,   112,    -1,    -1,    -1,    -1,   117,    -1,
      -1,   120,    23,   122,    -1,   124,    -1,    28,    29,    30,
      -1,    32,    -1,    -1,    -1,    -1,    37,    38,    -1,    40,
      -1,    42,    43,    -1,    -1,    -1,    -1,    48,    -1,    50,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    59,    60,
      61,    62,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    75,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    90,
      91,    92,    93,    -1,    -1,    -1,    -1,    98,    -1,    -1,
       3,     4,     5,     6,     7,    -1,   107,    10,   109,    -1,
     111,   112,    -1,    -1,    -1,    -1,   117,    -1,    -1,   120,
      23,   122,    -1,   124,    -1,    28,    29,    30,    -1,    32,
      -1,    -1,    -1,    -1,    37,    38,    -1,    40,    -1,    42,
      43,    -1,    -1,    -1,    -1,    48,    -1,    50,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    59,    60,    61,    62,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    75,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    90,    91,    92,
      93,    -1,    -1,    -1,    -1,    98,    -1,    -1,     3,     4,
       5,     6,     7,    -1,   107,    10,   109,    -1,   111,   112,
      -1,    -1,    -1,    -1,   117,    -1,    -1,   120,    23,   122,
      -1,   124,    -1,    28,    29,    30,    -1,    32,    -1,    -1,
      -1,    -1,    37,    38,    -1,    40,    -1,    42,    43,    -1,
      -1,    -1,    -1,    48,    -1,    50,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    59,    60,    61,    62,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      75,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    90,    91,    92,    93,    -1,
      -1,    -1,    -1,    98,    -1,    -1,     3,     4,     5,     6,
       7,    -1,   107,    10,   109,    -1,   111,   112,    -1,    -1,
      -1,    -1,   117,    -1,    -1,   120,    23,   122,    -1,   124,
      -1,    28,    29,    30,    -1,    32,    -1,    -1,    -1,    -1,
      37,    38,    -1,    40,    -1,    42,    43,    -1,    -1,    -1,
      -1,    48,    -1,    50,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    59,    60,    61,    62,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    75,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    90,    91,    92,    93,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     3,     4,     5,     6,     7,    -1,
     107,    10,   109,    -1,   111,   112,    -1,    -1,    -1,    -1,
     117,    -1,    -1,   120,    23,   122,    -1,   124,    -1,    28,
      29,    30,    -1,    32,    -1,    -1,    -1,    -1,    37,    38,
      -1,    40,    -1,    42,    43,    -1,    -1,    -1,    -1,    48,
      -1,    50,    -1,    -1,    -1,    -1,    -1,    -1,     3,    -1,
      59,    60,    61,    62,     9,    -1,    -1,    -1,    13,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    76,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    91,    -1,    -1,    -1,    95,    -1,    -1,    -1,
      99,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     109,    -1,    -1,    -1,   113,    -1,    -1,    21,    -1,    -1,
      -1,   120,    -1,   122,   123,   124,    -1,    -1,    -1,    -1,
      -1,    76,    77,    78,    79,    80,    81,    -1,    -1,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    53,
      -1,    96,    56,    -1,    -1,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,    -1,   112,    -1,    -1,
     115,   116,   117,   118,   119,     9,    -1,    -1,    -1,    13,
      -1,    -1,    -1,    -1,    -1,    -1,    90,    21,    92,    93,
      94,    -1,    96,    97,    -1,    -1,   100,   101,   102,   103,
      -1,   105,   106,   107,   108,    -1,   110,    -1,   112,    -1,
      -1,   115,   116,   117,    -1,    -1,    -1,    -1,    -1,    53,
      -1,    -1,    56,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       9,    75,    -1,    -1,    13,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    21,    -1,    -1,    -1,    90,    -1,    92,    93,
      94,    -1,    96,    97,    98,    -1,   100,   101,   102,   103,
     104,   105,   106,   107,   108,    -1,   110,   111,   112,    -1,
      -1,   115,   116,   117,    53,    -1,    -1,    56,    -1,    -1,
      -1,   125,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     9,    75,    -1,    -1,    13,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    21,    -1,    -1,
      -1,    90,    -1,    92,    93,    94,    -1,    96,    97,    98,
      -1,   100,   101,   102,   103,   104,   105,   106,   107,   108,
      -1,   110,   111,   112,    -1,    -1,   115,   116,   117,    53,
      -1,    -1,    56,    -1,    -1,    -1,   125,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       9,    75,    -1,    -1,    13,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    21,    -1,    -1,    -1,    90,    -1,    92,    93,
      94,    -1,    96,    97,    98,    -1,   100,   101,   102,   103,
     104,   105,   106,   107,   108,    -1,   110,   111,   112,    -1,
      -1,   115,   116,   117,    53,    -1,    -1,    56,    -1,    -1,
      -1,   125,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     9,    75,    -1,    -1,    13,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    21,    -1,    -1,
      -1,    90,    -1,    92,    93,    94,    -1,    96,    97,    98,
      -1,   100,   101,   102,   103,   104,   105,   106,   107,   108,
      -1,   110,   111,   112,    -1,    -1,   115,   116,   117,    53,
      -1,    -1,    56,    -1,    -1,    -1,   125,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    75,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    90,    -1,    92,    93,
      94,    -1,    96,    97,    98,    -1,   100,   101,   102,   103,
     104,   105,   106,   107,   108,     9,   110,   111,   112,    13,
      -1,   115,   116,   117,    -1,    -1,    -1,    21,    22,   123,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    31,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    53,
      21,    -1,    56,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    75,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    53,    -1,    -1,    56,    90,    -1,    92,    93,
      94,    -1,    96,    97,    98,    -1,   100,   101,   102,   103,
     104,   105,   106,   107,   108,     9,   110,   111,   112,    13,
      -1,   115,   116,   117,    -1,    -1,   120,    21,    22,    90,
      -1,    -1,    93,    94,    -1,    96,    97,    31,    -1,   100,
     101,   102,   103,    -1,   105,   106,   107,   108,    -1,   110,
      -1,   112,    -1,    -1,   115,   116,   117,    -1,    -1,    53,
      -1,    -1,    56,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       9,    75,    -1,    -1,    13,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    21,    -1,    -1,    -1,    90,    -1,    92,    93,
      94,    -1,    96,    97,    98,    -1,   100,   101,   102,   103,
     104,   105,   106,   107,   108,    -1,   110,   111,   112,    -1,
      -1,   115,   116,   117,    53,    -1,   120,    56,    -1,    -1,
      -1,    -1,    -1,    -1,    63,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     9,    75,    -1,    -1,    13,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    21,    22,    -1,
      -1,    90,    -1,    92,    93,    94,    -1,    96,    97,    98,
      -1,   100,   101,   102,   103,   104,   105,   106,   107,   108,
      -1,   110,   111,   112,    -1,    -1,   115,   116,   117,    53,
      -1,   120,    56,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       9,    75,    -1,    -1,    13,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    21,    22,    -1,    -1,    90,    -1,    92,    93,
      94,    -1,    96,    97,    98,    -1,   100,   101,   102,   103,
     104,   105,   106,   107,   108,    -1,   110,   111,   112,    -1,
      -1,   115,   116,   117,    53,    -1,   120,    56,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     9,    75,    -1,    -1,    13,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    21,    22,    -1,
      -1,    90,    -1,    92,    93,    94,    -1,    96,    97,    98,
      -1,   100,   101,   102,   103,   104,   105,   106,   107,   108,
      -1,   110,   111,   112,    -1,    -1,   115,   116,   117,    53,
      -1,   120,    56,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       9,    75,    -1,    -1,    13,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    21,    -1,    -1,    -1,    90,    -1,    92,    93,
      94,    -1,    96,    97,    98,    -1,   100,   101,   102,   103,
     104,   105,   106,   107,   108,    -1,   110,   111,   112,    -1,
      -1,   115,   116,   117,    53,    -1,   120,    56,    -1,    -1,
      -1,    -1,    -1,    -1,    63,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     9,    75,    -1,    -1,    13,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    21,    -1,    -1,
      -1,    90,    -1,    92,    93,    94,    -1,    96,    97,    98,
      -1,   100,   101,   102,   103,   104,   105,   106,   107,   108,
      -1,   110,   111,   112,    -1,    -1,   115,   116,   117,    53,
      -1,   120,    56,    -1,    -1,    -1,    -1,    -1,    -1,    63,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       9,    75,    -1,    -1,    13,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    21,    -1,    -1,    -1,    90,    -1,    92,    93,
      94,    -1,    96,    97,    98,    -1,   100,   101,   102,   103,
     104,   105,   106,   107,   108,    -1,   110,   111,   112,    -1,
      -1,   115,   116,   117,    53,    -1,   120,    56,    -1,    -1,
      -1,    -1,    -1,    -1,    63,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     9,    75,    -1,    -1,    13,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    21,    -1,    -1,
      -1,    90,    -1,    92,    93,    94,    -1,    96,    97,    98,
      -1,   100,   101,   102,   103,   104,   105,   106,   107,   108,
      -1,   110,   111,   112,    -1,    -1,   115,   116,   117,    53,
      -1,   120,    56,    -1,    -1,    -1,    -1,    -1,    -1,    63,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       9,    75,    -1,    -1,    13,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    21,    -1,    -1,    -1,    90,    -1,    92,    93,
      94,    -1,    96,    97,    98,    -1,   100,   101,   102,   103,
     104,   105,   106,   107,   108,    -1,   110,   111,   112,    -1,
      -1,   115,   116,   117,    53,    -1,   120,    56,    -1,    -1,
      -1,    -1,    -1,    -1,    63,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     9,    75,    -1,    -1,    13,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    21,    -1,    -1,
      -1,    90,    -1,    92,    93,    94,    -1,    96,    97,    98,
      -1,   100,   101,   102,   103,   104,   105,   106,   107,   108,
      -1,   110,   111,   112,    -1,    -1,   115,   116,   117,    53,
      -1,   120,    56,    -1,    -1,    -1,    -1,    -1,    -1,    63,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       9,    75,    -1,    -1,    13,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    21,    -1,    -1,    -1,    90,    -1,    92,    93,
      94,    -1,    96,    97,    98,    -1,   100,   101,   102,   103,
     104,   105,   106,   107,   108,    -1,   110,   111,   112,    -1,
      -1,   115,   116,   117,    53,    -1,   120,    56,    -1,    -1,
      -1,    -1,    -1,    -1,    63,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     9,    75,    -1,    -1,    13,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    21,    -1,    -1,
      -1,    90,    -1,    92,    93,    94,    -1,    96,    97,    98,
      -1,   100,   101,   102,   103,   104,   105,   106,   107,   108,
      -1,   110,   111,   112,    -1,    -1,   115,   116,   117,    53,
      -1,   120,    56,    -1,    -1,    -1,    -1,    -1,    -1,    63,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       9,    75,    -1,    -1,    13,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    21,    -1,    -1,    -1,    90,    -1,    92,    93,
      94,    -1,    96,    97,    98,    -1,   100,   101,   102,   103,
     104,   105,   106,   107,   108,    -1,   110,   111,   112,    -1,
      -1,   115,   116,   117,    53,    -1,   120,    56,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     9,    75,    -1,    -1,    13,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    21,    -1,    -1,
      -1,    90,    -1,    92,    93,    94,    -1,    96,    97,    98,
      -1,   100,   101,   102,   103,   104,   105,   106,   107,   108,
      -1,   110,   111,   112,    -1,    -1,   115,   116,   117,    53,
      -1,   120,    56,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    75,    -1,     9,    -1,    -1,    -1,    13,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    21,    90,    -1,    92,    93,
      94,    -1,    96,    97,    98,    31,   100,   101,   102,   103,
     104,   105,   106,   107,   108,    -1,   110,   111,   112,    -1,
      -1,   115,   116,   117,    -1,   119,    -1,    53,    54,    -1,
      56,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    75,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    90,    -1,    92,    93,    94,    -1,
      96,    97,    98,    -1,   100,   101,   102,   103,   104,   105,
     106,   107,   108,     9,   110,   111,   112,    13,    -1,   115,
     116,   117,    -1,    -1,    -1,    21,    22,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    31,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    53,    21,    -1,
      56,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    75,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      53,    -1,    -1,    56,    90,    -1,    92,    93,    94,    -1,
      96,    97,    98,    -1,   100,   101,   102,   103,   104,   105,
     106,   107,   108,     9,   110,   111,   112,    13,    -1,   115,
     116,   117,    -1,    -1,    -1,    21,    22,    90,    -1,    -1,
      -1,    94,    -1,    96,    97,    31,    -1,   100,   101,   102,
     103,    -1,   105,   106,   107,   108,    -1,   110,    -1,   112,
      -1,    -1,   115,   116,   117,    -1,    -1,    53,    -1,    -1,
      56,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     9,    75,
      -1,    -1,    13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      21,    -1,    -1,    -1,    90,    -1,    92,    93,    94,    -1,
      96,    97,    98,    -1,   100,   101,   102,   103,   104,   105,
     106,   107,   108,    -1,   110,   111,   112,    -1,    -1,   115,
     116,   117,    53,    -1,    -1,    56,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     9,    75,    -1,    -1,    13,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    21,    -1,    -1,    -1,    90,
      -1,    92,    93,    94,    -1,    96,    97,    98,    -1,   100,
     101,   102,   103,   104,   105,   106,   107,   108,    -1,   110,
     111,   112,    -1,   114,   115,   116,   117,    53,    -1,    -1,
      56,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     9,    75,
      -1,    -1,    13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      21,    -1,    -1,    -1,    90,    -1,    92,    93,    94,    -1,
      96,    97,    98,    -1,   100,   101,   102,   103,   104,   105,
     106,   107,   108,    -1,   110,   111,   112,    -1,   114,   115,
     116,   117,    53,    -1,    -1,    56,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     9,    75,    -1,    -1,    13,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    21,    -1,    -1,    -1,    90,
      -1,    92,    93,    94,    -1,    96,    97,    98,    -1,   100,
     101,   102,   103,   104,   105,   106,   107,   108,    -1,   110,
     111,   112,    -1,   114,   115,   116,   117,    53,    -1,    -1,
      56,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    74,    75,
       9,    -1,    -1,    -1,    13,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    21,    -1,    90,    -1,    92,    93,    94,    -1,
      96,    97,    98,    -1,   100,   101,   102,   103,   104,   105,
     106,   107,   108,    -1,   110,   111,   112,    -1,    -1,   115,
     116,   117,    -1,    -1,    53,    -1,    -1,    56,    -1,    -1,
      -1,    -1,    -1,    -1,    63,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     9,    75,    -1,    -1,    13,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    21,    -1,    -1,
      -1,    90,    -1,    92,    93,    94,    -1,    96,    97,    98,
      -1,   100,   101,   102,   103,   104,   105,   106,   107,   108,
      -1,   110,   111,   112,    -1,    -1,   115,   116,   117,    53,
      -1,    -1,    56,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       9,    75,    -1,    -1,    13,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    21,    -1,    -1,    -1,    90,    -1,    92,    93,
      94,    -1,    96,    97,    98,    -1,   100,   101,   102,   103,
     104,   105,   106,   107,   108,    -1,   110,   111,   112,    -1,
     114,   115,   116,   117,    53,    -1,    -1,    56,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     9,    75,    -1,    -1,    13,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    21,    -1,    -1,
      -1,    90,    -1,    92,    93,    94,    -1,    96,    97,    98,
      -1,   100,   101,   102,   103,   104,   105,   106,   107,   108,
      -1,   110,   111,   112,    -1,   114,   115,   116,   117,    53,
      -1,    -1,    56,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       9,    75,    -1,    -1,    13,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    21,    -1,    -1,    -1,    90,    -1,    92,    93,
      94,    -1,    96,    97,    98,    -1,   100,   101,   102,   103,
     104,   105,   106,   107,   108,    -1,   110,   111,   112,    -1,
     114,   115,   116,   117,    53,    -1,    -1,    56,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     9,    75,    -1,    -1,    13,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    21,    -1,    -1,
      -1,    90,    -1,    92,    93,    94,    -1,    96,    97,    98,
      -1,   100,   101,   102,   103,   104,   105,   106,   107,   108,
      -1,   110,   111,   112,    -1,   114,   115,   116,   117,    53,
      -1,    -1,    56,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       9,    75,    -1,    -1,    13,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    21,    -1,    -1,    -1,    90,    -1,    92,    93,
      94,    -1,    96,    97,    98,    -1,   100,   101,   102,   103,
     104,   105,   106,   107,   108,    -1,   110,   111,   112,    -1,
     114,   115,   116,   117,    53,    -1,    -1,    56,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     9,    75,    -1,    -1,    13,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    21,    -1,    -1,
      -1,    90,    -1,    92,    93,    94,    -1,    96,    97,    98,
      -1,   100,   101,   102,   103,   104,   105,   106,   107,   108,
      -1,   110,   111,   112,    -1,   114,   115,   116,   117,    53,
      -1,    -1,    56,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       9,    75,    -1,    -1,    13,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    21,    -1,    -1,    -1,    90,    -1,    92,    93,
      94,    -1,    96,    97,    98,    -1,   100,   101,   102,   103,
     104,   105,   106,   107,   108,    -1,   110,   111,   112,    -1,
     114,   115,   116,   117,    53,    -1,    -1,    56,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     9,    75,    -1,    -1,    13,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    21,    -1,    -1,
      -1,    90,    -1,    92,    93,    94,    -1,    96,    97,    98,
      -1,   100,   101,   102,   103,   104,   105,   106,   107,   108,
      -1,   110,   111,   112,    -1,   114,   115,   116,   117,    53,
      -1,    -1,    56,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       9,    75,    -1,    -1,    13,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    21,    -1,    -1,    -1,    90,    -1,    92,    93,
      94,    -1,    96,    97,    98,    -1,   100,   101,   102,   103,
     104,   105,   106,   107,   108,    -1,   110,   111,   112,    -1,
     114,   115,   116,   117,    53,    -1,    -1,    56,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     9,    75,    -1,    -1,    13,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    21,    -1,    -1,
      -1,    90,    -1,    92,    93,    94,    -1,    96,    97,    98,
      -1,   100,   101,   102,   103,   104,   105,   106,   107,   108,
      -1,   110,   111,   112,    -1,   114,   115,   116,   117,    53,
      -1,    -1,    56,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       9,    75,    -1,    -1,    13,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    21,    -1,    -1,    -1,    90,    -1,    92,    93,
      94,    -1,    96,    97,    98,    -1,   100,   101,   102,   103,
     104,   105,   106,   107,   108,    -1,   110,   111,   112,    -1,
     114,   115,   116,   117,    53,    -1,    -1,    56,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     9,    75,    -1,    -1,    13,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    21,    -1,    -1,
      -1,    90,    -1,    92,    93,    94,    -1,    96,    97,    98,
      -1,   100,   101,   102,   103,   104,   105,   106,   107,   108,
      -1,   110,   111,   112,    -1,   114,   115,   116,   117,    53,
      -1,    -1,    56,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       9,    75,    -1,    -1,    13,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    21,    -1,    -1,    -1,    90,    -1,    92,    93,
      94,    -1,    96,    97,    98,    -1,   100,   101,   102,   103,
     104,   105,   106,   107,   108,    -1,   110,   111,   112,    -1,
     114,   115,   116,   117,    53,    -1,    -1,    56,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     9,    75,    -1,    -1,    13,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    21,    -1,    -1,
      -1,    90,    -1,    92,    93,    94,    -1,    96,    97,    98,
      -1,   100,   101,   102,   103,   104,   105,   106,   107,   108,
      -1,   110,   111,   112,    -1,   114,   115,   116,   117,    53,
      -1,    -1,    56,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       9,    75,    -1,    -1,    13,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    21,    -1,    -1,    -1,    90,    -1,    92,    93,
      94,    -1,    96,    97,    98,    -1,   100,   101,   102,   103,
     104,   105,   106,   107,   108,    -1,   110,   111,   112,    -1,
     114,   115,   116,   117,    53,    54,    -1,    56,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     9,    75,    -1,    -1,    13,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    21,    -1,    -1,
      -1,    90,    -1,    92,    93,    94,    -1,    96,    97,    98,
      -1,   100,   101,   102,   103,   104,   105,   106,   107,   108,
      -1,   110,   111,   112,    -1,    -1,   115,   116,   117,    53,
      -1,    -1,    56,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       9,    75,    -1,    -1,    13,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    21,    -1,    -1,    24,    90,    -1,    92,    93,
      94,    -1,    96,    97,    98,    -1,   100,   101,   102,   103,
     104,   105,   106,   107,   108,    -1,   110,   111,   112,    -1,
     114,   115,   116,   117,    53,    -1,    -1,    56,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     9,    75,    -1,    -1,    13,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    21,    -1,    -1,
      -1,    90,    -1,    92,    93,    94,    -1,    96,    97,    98,
      -1,   100,   101,   102,   103,   104,   105,   106,   107,   108,
      -1,   110,   111,   112,    -1,    -1,   115,   116,   117,    53,
      -1,    -1,    56,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      74,    75,     9,    -1,    -1,    -1,    13,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    21,    22,    90,    -1,    92,    93,
      94,    -1,    96,    97,    98,    -1,   100,   101,   102,   103,
     104,   105,   106,   107,   108,    -1,   110,   111,   112,    -1,
      -1,   115,   116,   117,    -1,    -1,    53,    -1,    -1,    56,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     9,    75,    -1,
      -1,    13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    21,
      22,    -1,    -1,    90,    -1,    92,    93,    94,    -1,    96,
      97,    98,    -1,   100,   101,   102,   103,   104,   105,   106,
     107,   108,    -1,   110,   111,   112,    -1,    -1,   115,   116,
     117,    53,    -1,    -1,    56,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     9,    75,    -1,    -1,    13,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    21,    -1,    -1,    -1,    90,    -1,
      92,    93,    94,    -1,    96,    97,    98,    -1,   100,   101,
     102,   103,   104,   105,   106,   107,   108,    -1,   110,   111,
     112,    -1,    -1,   115,   116,   117,    53,    -1,    -1,    56,
      -1,    -1,    -1,    -1,    -1,    -1,    63,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     9,    75,    -1,
      -1,    13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    21,
      -1,    -1,    -1,    90,    -1,    92,    93,    94,    -1,    96,
      97,    98,    -1,   100,   101,   102,   103,   104,   105,   106,
     107,   108,    -1,   110,   111,   112,    -1,    -1,   115,   116,
     117,    53,    -1,    -1,    56,    -1,    -1,    -1,    -1,    -1,
      -1,    63,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     9,    75,    -1,    -1,    13,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    21,    -1,    -1,    -1,    90,    -1,
      92,    93,    94,    -1,    96,    97,    98,    -1,   100,   101,
     102,   103,   104,   105,   106,   107,   108,    -1,   110,   111,
     112,    -1,    -1,   115,   116,   117,    53,    -1,    -1,    56,
      -1,    -1,    -1,    -1,    -1,    -1,    63,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     9,    75,    -1,
      -1,    13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    21,
      -1,    -1,    -1,    90,    -1,    92,    93,    94,    -1,    96,
      97,    98,    -1,   100,   101,   102,   103,   104,   105,   106,
     107,   108,    -1,   110,   111,   112,    -1,    -1,   115,   116,
     117,    53,    -1,    -1,    56,    -1,    -1,    -1,    -1,    -1,
      -1,    63,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     9,    75,    -1,    -1,    13,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    21,    -1,    -1,    -1,    90,    -1,
      92,    93,    94,    -1,    96,    97,    98,    -1,   100,   101,
     102,   103,   104,   105,   106,   107,   108,    -1,   110,   111,
     112,    -1,    -1,   115,   116,   117,    53,    -1,    -1,    56,
      -1,    -1,    -1,    -1,    -1,    -1,    63,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     9,    75,    -1,
      -1,    13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    21,
      -1,    -1,    -1,    90,    -1,    92,    93,    94,    -1,    96,
      97,    98,    -1,   100,   101,   102,   103,   104,   105,   106,
     107,   108,    -1,   110,   111,   112,    -1,    -1,   115,   116,
     117,    53,    -1,    -1,    56,    -1,    -1,    -1,    -1,    -1,
      -1,    63,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     9,    75,    -1,    -1,    13,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    21,    -1,    -1,    -1,    90,    -1,
      92,    93,    94,    -1,    96,    97,    98,    -1,   100,   101,
     102,   103,   104,   105,   106,   107,   108,    -1,   110,   111,
     112,    -1,    -1,   115,   116,   117,    53,    -1,    -1,    56,
      -1,    -1,    -1,    -1,    -1,    -1,    63,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     9,    75,    -1,
      -1,    13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    21,
      -1,    -1,    -1,    90,    -1,    92,    93,    94,    -1,    96,
      97,    98,    -1,   100,   101,   102,   103,   104,   105,   106,
     107,   108,    -1,   110,   111,   112,    -1,    -1,   115,   116,
     117,    53,    -1,    -1,    56,    -1,    -1,    -1,    -1,    -1,
      -1,    63,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     9,    75,    -1,    -1,    13,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    21,    -1,    -1,    -1,    90,    -1,
      92,    93,    94,    -1,    96,    97,    98,    -1,   100,   101,
     102,   103,   104,   105,   106,   107,   108,    -1,   110,   111,
     112,    -1,    -1,   115,   116,   117,    53,    -1,    -1,    56,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    75,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    21,
      -1,    -1,    -1,    90,    -1,    92,    93,    94,    -1,    96,
      97,    98,    -1,   100,   101,   102,   103,   104,   105,   106,
     107,   108,    -1,   110,   111,   112,    -1,    -1,   115,   116,
     117,    53,    -1,    -1,    56,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    75,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    21,    -1,    -1,    -1,    90,    -1,
      92,    93,    94,    -1,    96,    97,    98,    -1,   100,   101,
     102,   103,    -1,   105,   106,   107,   108,    -1,   110,   111,
     112,    -1,    -1,   115,   116,   117,    53,    -1,    -1,    56,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    75,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    90,    -1,    92,    93,    94,    -1,    96,
      97,    -1,    -1,   100,   101,   102,   103,    -1,   105,   106,
     107,   108,    -1,   110,   111,   112,    -1,    -1,   115,   116,
     117
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,   130,   131,     0,     1,     3,     4,     5,     6,     7,
      10,    11,    12,    15,    16,    17,    19,    20,    22,    23,
      25,    26,    27,    28,    29,    30,    32,    33,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    48,    49,    50,
      55,    57,    58,    59,    60,    61,    62,    64,    67,    71,
      72,    75,    90,    91,    92,    93,    98,   107,   109,   111,
     112,   114,   117,   120,   122,   124,   132,   134,   135,   136,
     137,   139,   141,   142,   143,   144,   146,   147,   150,   151,
     152,   156,   159,   162,   163,   182,   183,   184,   187,   188,
     206,   207,   208,   209,   210,   211,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   225,   226,   227,   228,
     229,   135,   217,    54,   212,   138,   139,   212,    10,    28,
      29,    30,    62,   120,   124,   159,   206,   210,   215,   216,
     217,   218,   220,   221,    64,   138,   217,   135,   122,   139,
     139,     8,    64,   139,    47,    73,   145,   217,   217,   217,
     122,   139,   160,   122,   139,   189,   190,   135,   217,   217,
     217,   217,     7,   122,   114,   217,   217,   217,   217,    61,
     122,   135,   217,    57,   139,   185,   113,   178,   200,   217,
     217,   217,   217,   217,   217,   217,   217,   121,   132,   133,
     200,    65,    99,   178,   201,   202,   217,   200,   217,   224,
      49,   135,    14,    52,    66,   153,    35,    51,   174,   139,
      18,    47,    68,   114,   119,     9,    13,    21,    53,    56,
      75,    90,    92,    93,    94,    96,    97,    98,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   110,   111,   112,
     115,   116,   117,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,   118,   122,   124,
      53,    56,   122,   135,   114,   120,   137,   217,   217,   217,
     200,    31,   212,   185,   114,   114,    71,   139,   178,   203,
     204,   205,   217,   120,   185,   139,   122,    22,   137,   140,
      22,    31,   140,    22,    31,   140,    63,   137,   203,   135,
     122,   169,    65,   122,   139,   191,   192,     1,    94,   194,
     195,    31,    95,   140,   203,   114,   120,   140,   122,   203,
     200,    76,   186,   114,   139,    95,   114,   140,   114,   121,
     132,   121,   217,    95,   123,    95,   123,    31,   125,    74,
      95,   125,     7,   139,   164,   120,   189,   189,   189,   217,
     217,   217,   217,   145,   217,   145,   217,   217,   217,   217,
     217,   217,   217,    23,    64,   139,   217,   217,   217,   217,
     217,   217,   217,   217,   217,   217,   217,   217,   217,   217,
     217,   217,   217,   217,   217,   217,   217,   217,   217,   217,
     217,   217,   217,   217,   217,   217,   217,   203,   203,   145,
     217,   145,   217,   206,   213,    22,    31,    22,    31,    63,
      31,   125,   145,   217,   140,   114,   217,    74,    76,   123,
      95,   139,   157,   158,   114,    31,   200,   135,    30,   217,
     145,   217,    30,   217,   145,   217,   135,   217,    24,   123,
      18,    31,    34,    46,    47,    54,    64,   170,   171,   172,
     161,   192,    95,   123,     1,   124,   196,   207,    74,    76,
     193,   217,   190,   123,   148,   203,   123,   120,   124,   196,
     207,    95,   178,   217,   123,   123,   201,   201,   145,   217,
     135,   217,   217,   217,    94,   154,    47,   166,   173,   121,
     133,   114,   114,   114,   114,   114,   114,   114,   114,   114,
     114,   114,   114,   114,   114,   114,   114,   114,   114,   123,
     125,    95,   123,    30,   145,   217,    30,   145,   217,   145,
     217,   212,   212,   114,   217,   178,   217,   205,    76,    95,
     121,   217,   123,   217,    22,   140,    22,   140,   217,    22,
     140,    22,   140,    24,    24,   135,    31,    54,    95,   123,
     122,   139,    18,    47,    64,    68,   175,   123,   192,    94,
     195,   200,   217,   217,    45,    69,   121,   149,   123,   148,
     200,   185,   125,   125,    74,   200,   120,   165,     9,    13,
      76,    77,    78,    79,    80,    81,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    96,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   112,   115,
     116,   117,   118,   119,   139,   167,   121,   206,   217,    22,
      22,   217,    22,    22,   125,   125,   140,   140,   217,   158,
     140,    63,    30,   217,    30,   217,    63,    30,   217,    30,
     217,   135,   217,   171,   192,    94,   199,   195,   193,    31,
     125,   135,   200,   121,   125,    30,   135,   217,    30,   135,
     217,   217,   155,   175,   139,    97,   122,   168,    63,    30,
      30,    63,    30,    30,    30,    30,   217,   217,   217,   217,
     217,   217,   123,    23,    59,    62,   124,   178,   198,   207,
      99,   180,   193,    70,   181,   217,   196,   207,   140,   217,
     217,    27,    64,   121,   134,   142,   195,   139,   167,   170,
     217,   217,   217,   217,   217,   217,    63,    63,    63,    63,
     199,   125,   200,   178,   179,   217,   217,   137,   141,   177,
     125,    63,    63,   142,   181,   168,   123,    63,    63,    63,
      63,    63,    63,   217,   217,   217,   217,   180,   193,   178,
     197,   198,   207,    31,   125,   207,   217,   217,   114,   176,
     177,   217,   197,   198,   125,   197
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value, Location); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
#endif
{
  if (!yyvaluep)
    return;
  YYUSE (yylocationp);
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep, yylocationp)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yylsp, yyrule)
    YYSTYPE *yyvsp;
    YYLTYPE *yylsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       , &(yylsp[(yyi + 1) - (yynrhs)])		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, yylsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
#else
static void
yydestruct (yymsg, yytype, yyvaluep, yylocationp)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
    YYLTYPE *yylocationp;
#endif
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;
/* Location data for the look-ahead symbol.  */
YYLTYPE yylloc;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;

  /* The location stack.  */
  YYLTYPE yylsa[YYINITDEPTH];
  YYLTYPE *yyls = yylsa;
  YYLTYPE *yylsp;
  /* The locations where the error started and ended.  */
  YYLTYPE yyerror_range[2];

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;
  yylsp = yyls;
#if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  /* Initialize the default location before parsing starts.  */
  yylloc.first_line   = yylloc.last_line   = 1;
  yylloc.first_column = yylloc.last_column = 0;
#endif

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;
	YYLTYPE *yyls1 = yyls;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yyls1, yysize * sizeof (*yylsp),
		    &yystacksize);
	yyls = yyls1;
	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);
	YYSTACK_RELOCATE (yyls);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;
  *++yylsp = yylloc;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];

  /* Default location.  */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 185 "chapel.ypp"
    { (void)(yylsp[(1) - (1)]).first_line; yyblock = (yyval.pblockstmt); ;}
    break;

  case 3:
#line 190 "chapel.ypp"
    { (yyval.pblockstmt) = new BlockStmt(); resetTempID(); ;}
    break;

  case 4:
#line 191 "chapel.ypp"
    { (yyvsp[(1) - (2)].pblockstmt)->insertAtTail((yyvsp[(2) - (2)].pblockstmt)); resetTempID(); ;}
    break;

  case 6:
#line 197 "chapel.ypp"
    { (yyval.pblockstmt) = buildPragmaStmt( (yyvsp[(1) - (2)].vpch), (yyvsp[(2) - (2)].pblockstmt) ); ;}
    break;

  case 7:
#line 202 "chapel.ypp"
    { (yyval.pblockstmt) = new BlockStmt(); (yyval.pblockstmt)->insertAtTail((yyvsp[(1) - (1)].pblockstmt)); ;}
    break;

  case 8:
#line 203 "chapel.ypp"
    { (yyvsp[(1) - (2)].pblockstmt)->insertAtTail((yyvsp[(2) - (2)].pblockstmt)); ;}
    break;

  case 9:
#line 208 "chapel.ypp"
    { (yyval.vpch) = new Vec<const char*>(); (yyval.vpch)->add(astr((yyvsp[(2) - (2)].pch))); ;}
    break;

  case 10:
#line 209 "chapel.ypp"
    { (yyvsp[(1) - (3)].vpch)->add(astr((yyvsp[(3) - (3)].pch))); ;}
    break;

  case 21:
#line 223 "chapel.ypp"
    { (yyval.pblockstmt) = buildChapelStmt((yyvsp[(1) - (2)].pexpr)); ;}
    break;

  case 22:
#line 224 "chapel.ypp"
    { (yyval.pblockstmt) = buildAtomicStmt((yyvsp[(2) - (2)].pblockstmt)); ;}
    break;

  case 23:
#line 225 "chapel.ypp"
    { (yyval.pblockstmt) = buildBeginStmt((yyvsp[(2) - (3)].pcallexpr), (yyvsp[(3) - (3)].pblockstmt)); ;}
    break;

  case 24:
#line 226 "chapel.ypp"
    { (yyval.pblockstmt) = buildGotoStmt(GOTO_BREAK, (yyvsp[(2) - (3)].pch)); ;}
    break;

  case 25:
#line 227 "chapel.ypp"
    { (yyval.pblockstmt) = buildCobeginStmt((yyvsp[(2) - (3)].pcallexpr), (yyvsp[(3) - (3)].pblockstmt));  ;}
    break;

  case 26:
#line 228 "chapel.ypp"
    { (yyval.pblockstmt) = buildGotoStmt(GOTO_CONTINUE, (yyvsp[(2) - (3)].pch)); ;}
    break;

  case 27:
#line 229 "chapel.ypp"
    { (yyval.pblockstmt) = buildPrimitiveStmt(PRIM_DELETE, (yyvsp[(2) - (3)].pexpr)); ;}
    break;

  case 28:
#line 230 "chapel.ypp"
    { (yyval.pblockstmt) = buildLabelStmt((yyvsp[(2) - (3)].pch), (yyvsp[(3) - (3)].pblockstmt)); ;}
    break;

  case 29:
#line 231 "chapel.ypp"
    { (yyval.pblockstmt) = buildLocalStmt((yyvsp[(2) - (2)].pblockstmt)); ;}
    break;

  case 30:
#line 232 "chapel.ypp"
    { (yyval.pblockstmt) = buildOnStmt((yyvsp[(2) - (3)].pexpr), (yyvsp[(3) - (3)].pblockstmt)); ;}
    break;

  case 31:
#line 233 "chapel.ypp"
    { (yyval.pblockstmt) = buildSerialStmt((yyvsp[(2) - (3)].pexpr), (yyvsp[(3) - (3)].pblockstmt)); ;}
    break;

  case 32:
#line 234 "chapel.ypp"
    { (yyval.pblockstmt) = buildSyncStmt((yyvsp[(2) - (2)].pblockstmt)); ;}
    break;

  case 33:
#line 235 "chapel.ypp"
    { (yyval.pblockstmt) = buildUseStmt((yyvsp[(2) - (3)].pcallexpr)); ;}
    break;

  case 34:
#line 236 "chapel.ypp"
    { (yyval.pblockstmt) = buildPrimitiveStmt(PRIM_YIELD, (yyvsp[(2) - (3)].pexpr)); ;}
    break;

  case 35:
#line 237 "chapel.ypp"
    { printf("syntax error"); clean_exit(1); ;}
    break;

  case 36:
#line 241 "chapel.ypp"
    { (yyval.pblockstmt) = buildAssignment((yyvsp[(1) - (4)].pexpr), (yyvsp[(3) - (4)].pexpr), "="); ;}
    break;

  case 37:
#line 242 "chapel.ypp"
    { (yyval.pblockstmt) = buildAssignment((yyvsp[(1) - (4)].pexpr), (yyvsp[(3) - (4)].pexpr), "+="); ;}
    break;

  case 38:
#line 243 "chapel.ypp"
    { (yyval.pblockstmt) = buildAssignment((yyvsp[(1) - (4)].pexpr), (yyvsp[(3) - (4)].pexpr), "-="); ;}
    break;

  case 39:
#line 244 "chapel.ypp"
    { (yyval.pblockstmt) = buildAssignment((yyvsp[(1) - (4)].pexpr), (yyvsp[(3) - (4)].pexpr), "*="); ;}
    break;

  case 40:
#line 245 "chapel.ypp"
    { (yyval.pblockstmt) = buildAssignment((yyvsp[(1) - (4)].pexpr), (yyvsp[(3) - (4)].pexpr), "/="); ;}
    break;

  case 41:
#line 246 "chapel.ypp"
    { (yyval.pblockstmt) = buildAssignment((yyvsp[(1) - (4)].pexpr), (yyvsp[(3) - (4)].pexpr), "%="); ;}
    break;

  case 42:
#line 247 "chapel.ypp"
    { (yyval.pblockstmt) = buildAssignment((yyvsp[(1) - (4)].pexpr), (yyvsp[(3) - (4)].pexpr), "**="); ;}
    break;

  case 43:
#line 248 "chapel.ypp"
    { (yyval.pblockstmt) = buildAssignment((yyvsp[(1) - (4)].pexpr), (yyvsp[(3) - (4)].pexpr), "&="); ;}
    break;

  case 44:
#line 249 "chapel.ypp"
    { (yyval.pblockstmt) = buildAssignment((yyvsp[(1) - (4)].pexpr), (yyvsp[(3) - (4)].pexpr), "|="); ;}
    break;

  case 45:
#line 250 "chapel.ypp"
    { (yyval.pblockstmt) = buildAssignment((yyvsp[(1) - (4)].pexpr), (yyvsp[(3) - (4)].pexpr), "^="); ;}
    break;

  case 46:
#line 251 "chapel.ypp"
    { (yyval.pblockstmt) = buildAssignment((yyvsp[(1) - (4)].pexpr), (yyvsp[(3) - (4)].pexpr), ">>="); ;}
    break;

  case 47:
#line 252 "chapel.ypp"
    { (yyval.pblockstmt) = buildAssignment((yyvsp[(1) - (4)].pexpr), (yyvsp[(3) - (4)].pexpr), "<<="); ;}
    break;

  case 48:
#line 253 "chapel.ypp"
    { (yyval.pblockstmt) = buildAssignment((yyvsp[(1) - (4)].pexpr), (yyvsp[(3) - (4)].pexpr), "<=>"); ;}
    break;

  case 49:
#line 254 "chapel.ypp"
    { (yyval.pblockstmt) = buildLAndAssignment((yyvsp[(1) - (4)].pexpr), (yyvsp[(3) - (4)].pexpr)); ;}
    break;

  case 50:
#line 255 "chapel.ypp"
    { (yyval.pblockstmt) = buildLOrAssignment((yyvsp[(1) - (4)].pexpr), (yyvsp[(3) - (4)].pexpr)); ;}
    break;

  case 51:
#line 267 "chapel.ypp"
    { (yyval.pblockstmt) = new BlockStmt(); ;}
    break;

  case 52:
#line 268 "chapel.ypp"
    { (yyval.pblockstmt) = (yyvsp[(2) - (3)].pblockstmt); ;}
    break;

  case 53:
#line 272 "chapel.ypp"
    { (yyval.pch) = NULL; ;}
    break;

  case 55:
#line 277 "chapel.ypp"
    { (yyval.pch) = astr(yytext); ;}
    break;

  case 56:
#line 281 "chapel.ypp"
    { (yyval.pblockstmt) = (yyvsp[(2) - (2)].pblockstmt); ;}
    break;

  case 57:
#line 282 "chapel.ypp"
    { (yyval.pblockstmt) = (yyvsp[(1) - (1)].pblockstmt); ;}
    break;

  case 58:
#line 286 "chapel.ypp"
    { (yyval.pblockstmt) = buildPrimitiveStmt(PRIM_RETURN, new SymExpr(gVoid)); ;}
    break;

  case 59:
#line 287 "chapel.ypp"
    { (yyval.pblockstmt) = buildPrimitiveStmt(PRIM_RETURN, (yyvsp[(2) - (3)].pexpr)); ;}
    break;

  case 60:
#line 291 "chapel.ypp"
    { (yyval.pblockstmt) = buildChapelStmt(new BlockStmt()); ;}
    break;

  case 66:
#line 301 "chapel.ypp"
    {
#ifdef HAVE_LLVM
      if (externC) {
        (yyval.pblockstmt) = buildExternBlockStmt(astr((yyvsp[(2) - (2)].pch)));
      } else {
        USR_FATAL(new BlockStmt(), "extern block syntax is turned off. Use --extern-c flag to turn on.");
      }
#else
      USR_FATAL(new BlockStmt(), "Chapel must be built with llvm in order to use the extern block syntax");
#endif
    ;}
    break;

  case 67:
#line 315 "chapel.ypp"
    { (yyval.pblockstmt) = buildDoWhileLoopStmt((yyvsp[(4) - (5)].pexpr), (yyvsp[(2) - (5)].pblockstmt)); ;}
    break;

  case 68:
#line 316 "chapel.ypp"
    { (yyval.pblockstmt) = buildWhileDoLoopStmt((yyvsp[(2) - (3)].pexpr), (yyvsp[(3) - (3)].pblockstmt)); ;}
    break;

  case 69:
#line 317 "chapel.ypp"
    { (yyval.pblockstmt) = buildCoforallLoopStmt((yyvsp[(2) - (6)].pexpr), (yyvsp[(4) - (6)].pexpr), (yyvsp[(5) - (6)].pcallexpr), (yyvsp[(6) - (6)].pblockstmt)); ;}
    break;

  case 70:
#line 318 "chapel.ypp"
    { (yyval.pblockstmt) = buildCoforallLoopStmt((yyvsp[(2) - (6)].pexpr), (yyvsp[(4) - (6)].pexpr), (yyvsp[(5) - (6)].pcallexpr), (yyvsp[(6) - (6)].pblockstmt), true); ;}
    break;

  case 71:
#line 319 "chapel.ypp"
    { (yyval.pblockstmt) = buildCoforallLoopStmt(NULL, (yyvsp[(2) - (4)].pexpr), (yyvsp[(3) - (4)].pcallexpr), (yyvsp[(4) - (4)].pblockstmt)); ;}
    break;

  case 72:
#line 320 "chapel.ypp"
    { (yyval.pblockstmt) = buildForLoopStmt((yyvsp[(2) - (5)].pexpr), (yyvsp[(4) - (5)].pexpr), (yyvsp[(5) - (5)].pblockstmt)); ;}
    break;

  case 73:
#line 321 "chapel.ypp"
    { (yyval.pblockstmt) = buildForLoopStmt((yyvsp[(2) - (5)].pexpr), (yyvsp[(4) - (5)].pexpr), (yyvsp[(5) - (5)].pblockstmt), false, true); ;}
    break;

  case 74:
#line 322 "chapel.ypp"
    { (yyval.pblockstmt) = buildForLoopStmt(NULL, (yyvsp[(2) - (3)].pexpr), (yyvsp[(3) - (3)].pblockstmt)); ;}
    break;

  case 75:
#line 323 "chapel.ypp"
    { (yyval.pblockstmt) = buildForLoopStmt(NULL, (yyvsp[(2) - (3)].pexpr), (yyvsp[(3) - (3)].pblockstmt), false, true); ;}
    break;

  case 76:
#line 324 "chapel.ypp"
    { (yyval.pblockstmt) = buildParamForLoopStmt((yyvsp[(3) - (6)].pch), (yyvsp[(5) - (6)].pexpr), (yyvsp[(6) - (6)].pblockstmt)); ;}
    break;

  case 77:
#line 325 "chapel.ypp"
    { (yyval.pblockstmt) = buildForallLoopStmt((yyvsp[(2) - (5)].pexpr), (yyvsp[(4) - (5)].pexpr), (yyvsp[(5) - (5)].pblockstmt)); ;}
    break;

  case 78:
#line 326 "chapel.ypp"
    { (yyval.pblockstmt) = buildForallLoopStmt((yyvsp[(2) - (5)].pexpr), (yyvsp[(4) - (5)].pexpr), (yyvsp[(5) - (5)].pblockstmt), true); ;}
    break;

  case 79:
#line 327 "chapel.ypp"
    { (yyval.pblockstmt) = buildForallLoopStmt(NULL, (yyvsp[(2) - (3)].pexpr), (yyvsp[(3) - (3)].pblockstmt)); ;}
    break;

  case 80:
#line 329 "chapel.ypp"
    {
      if ((yyvsp[(2) - (6)].pcallexpr)->argList.length != 1)
        USR_FATAL((yyvsp[(4) - (6)].pexpr), "invalid index expression");
      (yyval.pblockstmt) = buildForallLoopStmt((yyvsp[(2) - (6)].pcallexpr)->get(1)->remove(), (yyvsp[(4) - (6)].pexpr), new BlockStmt((yyvsp[(6) - (6)].pblockstmt)));
    ;}
    break;

  case 81:
#line 335 "chapel.ypp"
    {
      if ((yyvsp[(2) - (6)].pcallexpr)->argList.length != 1)
        USR_FATAL((yyvsp[(4) - (6)].pexpr), "invalid index expression");
      (yyval.pblockstmt) = buildForallLoopStmt((yyvsp[(2) - (6)].pcallexpr)->get(1)->remove(), (yyvsp[(4) - (6)].pexpr), new BlockStmt((yyvsp[(6) - (6)].pblockstmt)), true);
    ;}
    break;

  case 82:
#line 341 "chapel.ypp"
    {
      if ((yyvsp[(2) - (4)].pcallexpr)->argList.length > 1)
        (yyval.pblockstmt) = buildForallLoopStmt(NULL, new CallExpr("chpl__buildDomainExpr", (yyvsp[(2) - (4)].pcallexpr)), new BlockStmt((yyvsp[(4) - (4)].pblockstmt)));
      else
        (yyval.pblockstmt) = buildForallLoopStmt(NULL, (yyvsp[(2) - (4)].pcallexpr)->get(1)->remove(), new BlockStmt((yyvsp[(4) - (4)].pblockstmt)));
    ;}
    break;

  case 83:
#line 350 "chapel.ypp"
    { (yyval.pexpr) = new CallExpr("_build_tuple", (yyvsp[(3) - (4)].pcallexpr)); ;}
    break;

  case 84:
#line 354 "chapel.ypp"
    { (yyval.pblockstmt) = buildIfStmt((yyvsp[(2) - (4)].pexpr), (yyvsp[(4) - (4)].pblockstmt)); ;}
    break;

  case 85:
#line 355 "chapel.ypp"
    { (yyval.pblockstmt) = buildIfStmt((yyvsp[(2) - (3)].pexpr), (yyvsp[(3) - (3)].pblockstmt)); ;}
    break;

  case 86:
#line 356 "chapel.ypp"
    { (yyval.pblockstmt) = buildIfStmt((yyvsp[(2) - (6)].pexpr), (yyvsp[(4) - (6)].pblockstmt), (yyvsp[(6) - (6)].pblockstmt)); ;}
    break;

  case 87:
#line 357 "chapel.ypp"
    { (yyval.pblockstmt) = buildIfStmt((yyvsp[(2) - (5)].pexpr), (yyvsp[(3) - (5)].pblockstmt), (yyvsp[(5) - (5)].pblockstmt)); ;}
    break;

  case 88:
#line 362 "chapel.ypp"
    { (yyval.pblockstmt) = buildChapelStmt(buildSelectStmt((yyvsp[(2) - (5)].pexpr), (yyvsp[(4) - (5)].pblockstmt))); ;}
    break;

  case 89:
#line 366 "chapel.ypp"
    { (yyval.pblockstmt) = buildChapelStmt(); ;}
    break;

  case 90:
#line 367 "chapel.ypp"
    { (yyvsp[(1) - (2)].pblockstmt)->insertAtTail((yyvsp[(2) - (2)].pexpr)); ;}
    break;

  case 91:
#line 372 "chapel.ypp"
    { (yyval.pexpr) = new CondStmt(new CallExpr(PRIM_WHEN, (yyvsp[(2) - (3)].pcallexpr)), (yyvsp[(3) - (3)].pblockstmt)); ;}
    break;

  case 92:
#line 374 "chapel.ypp"
    { (yyval.pexpr) = new CondStmt(new CallExpr(PRIM_WHEN), (yyvsp[(2) - (2)].pblockstmt)); ;}
    break;

  case 93:
#line 379 "chapel.ypp"
    { (yyval.pblockstmt) = buildTypeSelectStmt((yyvsp[(3) - (6)].pcallexpr), (yyvsp[(5) - (6)].pblockstmt)); ;}
    break;

  case 94:
#line 386 "chapel.ypp"
    { (yyval.pblockstmt) = buildChapelStmt(buildClassDefExpr((yyvsp[(3) - (7)].pch), (yyvsp[(2) - (7)].ptype), (yyvsp[(4) - (7)].pcallexpr), (yyvsp[(6) - (7)].pblockstmt), (yyvsp[(1) - (7)].flag), (yylsp[(1) - (7)]).comment));
      yylloc.comment = NULL; ;}
    break;

  case 95:
#line 391 "chapel.ypp"
    { (yyval.flag) = FLAG_UNKNOWN; ;}
    break;

  case 96:
#line 392 "chapel.ypp"
    { (yyval.flag) = FLAG_EXTERN; (yyloc).comment = yylloc.comment; yylloc.comment = NULL;;}
    break;

  case 97:
#line 396 "chapel.ypp"
    { (yyval.ptype) = new ClassType(CLASS_CLASS); (yyloc).comment = yylloc.comment; 
             yylloc.comment = NULL;;}
    break;

  case 98:
#line 398 "chapel.ypp"
    { (yyval.ptype) = new ClassType(CLASS_RECORD); (yyloc).comment = yylloc.comment; 
             yylloc.comment = NULL;;}
    break;

  case 99:
#line 400 "chapel.ypp"
    { (yyval.ptype) = new ClassType(CLASS_UNION); ;}
    break;

  case 100:
#line 404 "chapel.ypp"
    { (yyval.pcallexpr) = NULL; ;}
    break;

  case 101:
#line 405 "chapel.ypp"
    { (yyval.pcallexpr) = (yyvsp[(2) - (2)].pcallexpr); ;}
    break;

  case 102:
#line 410 "chapel.ypp"
    { (yyval.pblockstmt) = new BlockStmt(); ;}
    break;

  case 103:
#line 412 "chapel.ypp"
    { (yyvsp[(1) - (2)].pblockstmt)->insertAtTail((yyvsp[(2) - (2)].pblockstmt)); ;}
    break;

  case 104:
#line 414 "chapel.ypp"
    { (yyvsp[(1) - (3)].pblockstmt)->insertAtTail(buildPragmaStmt((yyvsp[(2) - (3)].vpch), (yyvsp[(3) - (3)].pblockstmt))); ;}
    break;

  case 105:
#line 419 "chapel.ypp"
    {
      EnumType* pdt = (yyvsp[(4) - (5)].penumtype);
      TypeSymbol* pst = new TypeSymbol((yyvsp[(2) - (5)].pch), pdt);
      (yyvsp[(4) - (5)].penumtype)->symbol = pst;
      (yyval.pblockstmt) = buildChapelStmt(new DefExpr(pst));
    ;}
    break;

  case 106:
#line 429 "chapel.ypp"
    {
      (yyval.penumtype) = new EnumType();
      (yyvsp[(1) - (1)].pdefexpr)->sym->type = (yyval.penumtype);
      (yyval.penumtype)->constants.insertAtTail((yyvsp[(1) - (1)].pdefexpr));
      (yyval.penumtype)->defaultValue = (yyvsp[(1) - (1)].pdefexpr)->sym;
    ;}
    break;

  case 107:
#line 436 "chapel.ypp"
    {
      (yyval.penumtype) = (yyvsp[(1) - (2)].penumtype);
    ;}
    break;

  case 108:
#line 440 "chapel.ypp"
    {
      (yyvsp[(1) - (3)].penumtype)->constants.insertAtTail((yyvsp[(3) - (3)].pdefexpr));
      (yyvsp[(3) - (3)].pdefexpr)->sym->type = (yyvsp[(1) - (3)].penumtype);
    ;}
    break;

  case 109:
#line 447 "chapel.ypp"
    { (yyval.pdefexpr) = new DefExpr(new EnumSymbol((yyvsp[(1) - (1)].pch))); ;}
    break;

  case 110:
#line 448 "chapel.ypp"
    { (yyval.pdefexpr) = new DefExpr(new EnumSymbol((yyvsp[(1) - (3)].pch)), (yyvsp[(3) - (3)].pexpr)); ;}
    break;

  case 111:
#line 453 "chapel.ypp"
    {
      captureTokens = 1;
      captureString[0] = '\0';
    ;}
    break;

  case 112:
#line 458 "chapel.ypp"
    {
      captureTokens = 0;
      (yyvsp[(3) - (3)].pfnsymbol)->userString = astr(captureString);
    ;}
    break;

  case 113:
#line 463 "chapel.ypp"
    {
      (yyvsp[(3) - (8)].pfnsymbol)->retTag = (yyvsp[(5) - (8)].retTag);
      if ((yyvsp[(5) - (8)].retTag) == RET_VAR)
        USR_FATAL("'var' return types are not allowed in lambdas");
      if ((yyvsp[(5) - (8)].retTag) == RET_PARAM)
        USR_FATAL("'param' return types are not allowed in lambdas");
      if ((yyvsp[(5) - (8)].retTag) == RET_TYPE)
        USR_FATAL("'type' return types are not allowed in lambdas");
      if ((yyvsp[(6) - (8)].pexpr))
        (yyvsp[(3) - (8)].pfnsymbol)->retExprType = new BlockStmt((yyvsp[(6) - (8)].pexpr), BLOCK_SCOPELESS);
      if ((yyvsp[(7) - (8)].pexpr))
        (yyvsp[(3) - (8)].pfnsymbol)->where = new BlockStmt((yyvsp[(7) - (8)].pexpr));
      (yyvsp[(3) - (8)].pfnsymbol)->insertAtTail((yyvsp[(8) - (8)].pblockstmt));
      (yyval.pexpr) = new DefExpr(buildLambda((yyvsp[(3) - (8)].pfnsymbol)));
    ;}
    break;

  case 114:
#line 483 "chapel.ypp"
    { (yyval.pfnsymbol) = new FnSymbol(""); ;}
    break;

  case 115:
#line 484 "chapel.ypp"
    { (yyval.pfnsymbol) = new FnSymbol(""); (yyval.pfnsymbol)->addFlag(FLAG_INLINE); 
                  (yyloc).comment = yylloc.comment; yylloc.comment = NULL;;}
    break;

  case 116:
#line 486 "chapel.ypp"
    { (yyval.pfnsymbol) = new FnSymbol(""); (yyval.pfnsymbol)->addFlag(FLAG_EXPORT);  
                  (yyloc).comment = yylloc.comment; yylloc.comment = NULL;;}
    break;

  case 117:
#line 488 "chapel.ypp"
    { (yyval.pfnsymbol) = new FnSymbol((yyvsp[(2) - (2)].pch)); (yyval.pfnsymbol)->addFlag(FLAG_EXPORT);  
                  (yyloc).comment = yylloc.comment; yylloc.comment = NULL;;}
    break;

  case 118:
#line 490 "chapel.ypp"
    { (yyval.pfnsymbol) = new FnSymbol(""); (yyval.pfnsymbol)->addFlag(FLAG_EXTERN);
                  (yyval.pfnsymbol)->addFlag(FLAG_LOCAL_ARGS);
                  (yyloc).comment = yylloc.comment; yylloc.comment = NULL;;}
    break;

  case 119:
#line 493 "chapel.ypp"
    { (yyval.pfnsymbol) = new FnSymbol((yyvsp[(2) - (2)].pch)); (yyval.pfnsymbol)->addFlag(FLAG_EXTERN);  
                  (yyval.pfnsymbol)->addFlag(FLAG_LOCAL_ARGS);
                  (yyloc).comment = yylloc.comment; yylloc.comment = NULL;;}
    break;

  case 120:
#line 499 "chapel.ypp"
    {
      // Sets up to capture tokens while parsing the next grammar nonterminal.
      captureTokens = 1;
      captureString[0] = '\0';
    ;}
    break;

  case 121:
#line 505 "chapel.ypp"
    {
      // Stop capturing and save the result.
      captureTokens = 0;

      (yyvsp[(4) - (4)].pfnsymbol)->userString = astr(captureString);
    ;}
    break;

  case 122:
#line 512 "chapel.ypp"
    {
      FnSymbol* fn = (yyvsp[(4) - (9)].pfnsymbol);

      fn->copyFlags((yyvsp[(1) - (9)].pfnsymbol));
      // The user explicitly named this function (controls mangling).
      if ((yyvsp[(1) - (9)].pfnsymbol)->hasFlag(FLAG_EXPORT) || (yyvsp[(1) - (9)].pfnsymbol)->hasFlag(FLAG_EXTERN))
        fn->addFlag(FLAG_USER_NAMED);
      if (*(yyvsp[(1) - (9)].pfnsymbol)->name)
        fn->cname = (yyvsp[(1) - (9)].pfnsymbol)->name;

      if ((yyvsp[(2) - (9)].procIter) == ProcIter_ITER)
      {
        if (fn->hasFlag(FLAG_EXTERN))
          USR_FATAL_CONT(fn, "'iter' is not legal with 'extern'");
        fn->addFlag(FLAG_ITERATOR_FN);
      }

      (yyval.pblockstmt) = buildFunctionDecl((yyvsp[(4) - (9)].pfnsymbol), (yyvsp[(6) - (9)].retTag), (yyvsp[(7) - (9)].pexpr), (yyvsp[(8) - (9)].pexpr), (yyvsp[(9) - (9)].pblockstmt), (yylsp[(1) - (9)]).comment);
      yylloc.comment = NULL;
    ;}
    break;

  case 123:
#line 536 "chapel.ypp"
    {
      (yyval.pfnsymbol) = (yyvsp[(3) - (3)].pfnsymbol);
      (yyval.pfnsymbol)->thisTag = (yyvsp[(1) - (3)].pt);
      (yyval.pfnsymbol)->name = astr((yyvsp[(2) - (3)].pch));
      (yyval.pfnsymbol)->cname = (yyval.pfnsymbol)->name;
      if ((yyvsp[(2) - (3)].pch)[0] == '~' && (yyvsp[(2) - (3)].pch)[1] != '\0')
        (yyval.pfnsymbol)->addFlag(FLAG_DESTRUCTOR);
    ;}
    break;

  case 124:
#line 545 "chapel.ypp"
    {
      (yyval.pfnsymbol) = (yyvsp[(5) - (5)].pfnsymbol);
      (yyval.pfnsymbol)->thisTag = (yyvsp[(1) - (5)].pt);
      (yyval.pfnsymbol)->name = astr((yyvsp[(4) - (5)].pch));
      (yyval.pfnsymbol)->cname = (yyval.pfnsymbol)->name;
      if ((yyvsp[(4) - (5)].pch)[0] == '~' && (yyvsp[(4) - (5)].pch)[1] != '\0')
        (yyval.pfnsymbol)->addFlag(FLAG_DESTRUCTOR);
      (yyval.pfnsymbol)->_this = new ArgSymbol((yyvsp[(1) - (5)].pt), "this", dtUnknown, new UnresolvedSymExpr((yyvsp[(2) - (5)].pch)));
      (yyval.pfnsymbol)->_this->addFlag(FLAG_ARG_THIS);
      (yyval.pfnsymbol)->insertFormalAtHead(new DefExpr((yyval.pfnsymbol)->_this));
      (yyval.pfnsymbol)->insertFormalAtHead(new DefExpr(new ArgSymbol(INTENT_BLANK, "_mt", dtMethodToken)));
    ;}
    break;

  case 126:
#line 561 "chapel.ypp"
    { (yyval.pch) = astr("~", (yyvsp[(2) - (2)].pch)); ;}
    break;

  case 127:
#line 562 "chapel.ypp"
    { (yyval.pch) = "="; ;}
    break;

  case 128:
#line 563 "chapel.ypp"
    { (yyval.pch) = "&"; ;}
    break;

  case 129:
#line 564 "chapel.ypp"
    { (yyval.pch) = "|"; ;}
    break;

  case 130:
#line 565 "chapel.ypp"
    { (yyval.pch) = "^"; ;}
    break;

  case 131:
#line 566 "chapel.ypp"
    { (yyval.pch) = "~"; ;}
    break;

  case 132:
#line 567 "chapel.ypp"
    { (yyval.pch) = "=="; ;}
    break;

  case 133:
#line 568 "chapel.ypp"
    { (yyval.pch) = "!="; ;}
    break;

  case 134:
#line 569 "chapel.ypp"
    { (yyval.pch) = "<="; ;}
    break;

  case 135:
#line 570 "chapel.ypp"
    { (yyval.pch) = ">="; ;}
    break;

  case 136:
#line 571 "chapel.ypp"
    { (yyval.pch) = "<"; ;}
    break;

  case 137:
#line 572 "chapel.ypp"
    { (yyval.pch) = ">"; ;}
    break;

  case 138:
#line 573 "chapel.ypp"
    { (yyval.pch) = "+"; ;}
    break;

  case 139:
#line 574 "chapel.ypp"
    { (yyval.pch) = "-"; ;}
    break;

  case 140:
#line 575 "chapel.ypp"
    { (yyval.pch) = "*"; ;}
    break;

  case 141:
#line 576 "chapel.ypp"
    { (yyval.pch) = "/"; ;}
    break;

  case 142:
#line 577 "chapel.ypp"
    { (yyval.pch) = "<<"; ;}
    break;

  case 143:
#line 578 "chapel.ypp"
    { (yyval.pch) = ">>"; ;}
    break;

  case 144:
#line 579 "chapel.ypp"
    { (yyval.pch) = "%"; ;}
    break;

  case 145:
#line 580 "chapel.ypp"
    { (yyval.pch) = "**"; ;}
    break;

  case 146:
#line 581 "chapel.ypp"
    { (yyval.pch) = "!"; ;}
    break;

  case 147:
#line 582 "chapel.ypp"
    { (yyval.pch) = "by"; ;}
    break;

  case 148:
#line 583 "chapel.ypp"
    { (yyval.pch) = "#"; ;}
    break;

  case 149:
#line 584 "chapel.ypp"
    { (yyval.pch) = "align"; ;}
    break;

  case 150:
#line 585 "chapel.ypp"
    { (yyval.pch) = "+="; ;}
    break;

  case 151:
#line 586 "chapel.ypp"
    { (yyval.pch) = "-="; ;}
    break;

  case 152:
#line 587 "chapel.ypp"
    { (yyval.pch) = "*="; ;}
    break;

  case 153:
#line 588 "chapel.ypp"
    { (yyval.pch) = "/="; ;}
    break;

  case 154:
#line 589 "chapel.ypp"
    { (yyval.pch) = "%="; ;}
    break;

  case 155:
#line 590 "chapel.ypp"
    { (yyval.pch) = "**="; ;}
    break;

  case 156:
#line 591 "chapel.ypp"
    { (yyval.pch) = "&="; ;}
    break;

  case 157:
#line 592 "chapel.ypp"
    { (yyval.pch) = "|="; ;}
    break;

  case 158:
#line 593 "chapel.ypp"
    { (yyval.pch) = "^="; ;}
    break;

  case 159:
#line 594 "chapel.ypp"
    { (yyval.pch) = ">>="; ;}
    break;

  case 160:
#line 595 "chapel.ypp"
    { (yyval.pch) = "<<="; ;}
    break;

  case 161:
#line 596 "chapel.ypp"
    { (yyval.pch) = "<=>"; ;}
    break;

  case 162:
#line 597 "chapel.ypp"
    { (yyval.pch) = "<~>"; ;}
    break;

  case 163:
#line 601 "chapel.ypp"
    { (yyval.pfnsymbol) = new FnSymbol("_"); (yyval.pfnsymbol)->addFlag(FLAG_NO_PARENS); ;}
    break;

  case 164:
#line 602 "chapel.ypp"
    { (yyval.pfnsymbol) = (yyvsp[(2) - (3)].pfnsymbol); ;}
    break;

  case 165:
#line 606 "chapel.ypp"
    { (yyval.pfnsymbol) = (yyvsp[(2) - (3)].pfnsymbol); ;}
    break;

  case 166:
#line 610 "chapel.ypp"
    { (yyval.pfnsymbol) = buildFunctionFormal(NULL, NULL); ;}
    break;

  case 167:
#line 611 "chapel.ypp"
    { (yyval.pfnsymbol) = buildFunctionFormal(NULL, (yyvsp[(1) - (1)].pdefexpr)); ;}
    break;

  case 168:
#line 612 "chapel.ypp"
    { (yyval.pfnsymbol) = buildFunctionFormal((yyvsp[(1) - (3)].pfnsymbol), (yyvsp[(3) - (3)].pdefexpr)); ;}
    break;

  case 169:
#line 617 "chapel.ypp"
    { (yyval.pdefexpr) = buildArgDefExpr((yyvsp[(1) - (4)].pt), (yyvsp[(2) - (4)].pch), (yyvsp[(3) - (4)].pexpr), (yyvsp[(4) - (4)].pexpr), NULL); ;}
    break;

  case 170:
#line 619 "chapel.ypp"
    { (yyval.pdefexpr) = buildArgDefExpr((yyvsp[(1) - (4)].pt), (yyvsp[(2) - (4)].pch), (yyvsp[(3) - (4)].pexpr), NULL, (yyvsp[(4) - (4)].pexpr)); ;}
    break;

  case 171:
#line 621 "chapel.ypp"
    { (yyval.pdefexpr) = buildTupleArgDefExpr((yyvsp[(1) - (6)].pt), (yyvsp[(3) - (6)].pblockstmt), (yyvsp[(5) - (6)].pexpr), (yyvsp[(6) - (6)].pexpr)); ;}
    break;

  case 172:
#line 623 "chapel.ypp"
    { USR_FATAL("variable-length argument may not be grouped in a tuple"); ;}
    break;

  case 173:
#line 627 "chapel.ypp"
    { (yyval.pt) = INTENT_BLANK; ;}
    break;

  case 174:
#line 628 "chapel.ypp"
    { (yyval.pt) = INTENT_IN; ;}
    break;

  case 175:
#line 629 "chapel.ypp"
    { (yyval.pt) = INTENT_INOUT; ;}
    break;

  case 176:
#line 630 "chapel.ypp"
    { (yyval.pt) = INTENT_OUT; ;}
    break;

  case 177:
#line 631 "chapel.ypp"
    { (yyval.pt) = INTENT_CONST; ;}
    break;

  case 178:
#line 632 "chapel.ypp"
    { (yyval.pt) = INTENT_CONST_IN; ;}
    break;

  case 179:
#line 633 "chapel.ypp"
    { (yyval.pt) = INTENT_CONST_REF; ;}
    break;

  case 180:
#line 634 "chapel.ypp"
    { (yyval.pt) = INTENT_PARAM; ;}
    break;

  case 181:
#line 635 "chapel.ypp"
    { (yyval.pt) = INTENT_REF; ;}
    break;

  case 182:
#line 636 "chapel.ypp"
    { (yyval.pt) = INTENT_TYPE; ;}
    break;

  case 183:
#line 640 "chapel.ypp"
    { (yyval.pt) = INTENT_BLANK; ;}
    break;

  case 184:
#line 641 "chapel.ypp"
    { (yyval.pt) = INTENT_PARAM; ;}
    break;

  case 185:
#line 645 "chapel.ypp"
    { (yyval.procIter) = ProcIter_PROC; ;}
    break;

  case 186:
#line 646 "chapel.ypp"
    { (yyval.procIter) = ProcIter_ITER; ;}
    break;

  case 187:
#line 650 "chapel.ypp"
    { (yyval.retTag) = RET_VALUE; ;}
    break;

  case 188:
#line 651 "chapel.ypp"
    { (yyval.retTag) = RET_VALUE; ;}
    break;

  case 189:
#line 652 "chapel.ypp"
    { (yyval.retTag) = RET_VAR; ;}
    break;

  case 190:
#line 653 "chapel.ypp"
    { (yyval.retTag) = RET_PARAM; ;}
    break;

  case 191:
#line 654 "chapel.ypp"
    { (yyval.retTag) = RET_TYPE; ;}
    break;

  case 192:
#line 658 "chapel.ypp"
    { (yyval.pblockstmt) = NULL; ;}
    break;

  case 195:
#line 664 "chapel.ypp"
    { (yyval.pblockstmt) = new BlockStmt((yyvsp[(1) - (1)].pblockstmt)); ;}
    break;

  case 196:
#line 669 "chapel.ypp"
    { (yyval.pdefexpr) = new DefExpr(new VarSymbol((yyvsp[(2) - (2)].pch))); ;}
    break;

  case 197:
#line 671 "chapel.ypp"
    { (yyval.pdefexpr) = new DefExpr(new VarSymbol(astr("chpl__query", istr(query_uid++)))); ;}
    break;

  case 198:
#line 675 "chapel.ypp"
    { (yyval.pdefexpr) = new DefExpr(new VarSymbol(astr("chpl__query", istr(query_uid++)))); ;}
    break;

  case 200:
#line 680 "chapel.ypp"
    { (yyval.pexpr) = (yyvsp[(2) - (2)].pexpr); ;}
    break;

  case 201:
#line 681 "chapel.ypp"
    { (yyvsp[(2) - (2)].pdefexpr)->sym->addFlag(FLAG_PARAM); (yyval.pexpr) = (yyvsp[(2) - (2)].pdefexpr); ;}
    break;

  case 202:
#line 685 "chapel.ypp"
    { (yyval.pexpr) = NULL; ;}
    break;

  case 203:
#line 686 "chapel.ypp"
    { (yyval.pexpr) = (yyvsp[(2) - (2)].pexpr); ;}
    break;

  case 204:
#line 691 "chapel.ypp"
    { (yyval.pblockstmt) = buildChapelStmt(new DefExpr(buildModule((yyvsp[(2) - (4)].pch), new BlockStmt(), yyfilename, (yylsp[(1) - (4)]).comment))); ;}
    break;

  case 205:
#line 693 "chapel.ypp"
    { (yyval.pblockstmt) = buildChapelStmt(new DefExpr(buildModule((yyvsp[(2) - (5)].pch), (yyvsp[(4) - (5)].pblockstmt), yyfilename, (yylsp[(1) - (5)]).comment))); ;}
    break;

  case 206:
#line 698 "chapel.ypp"
    {(yyloc).comment = yylloc.comment; yylloc.comment = NULL;;}
    break;

  case 207:
#line 703 "chapel.ypp"
    { (yyval.pblockstmt) = (yyvsp[(2) - (3)].pblockstmt); ;}
    break;

  case 208:
#line 705 "chapel.ypp"
    { (yyval.pblockstmt) = handleConfigTypes((yyvsp[(3) - (4)].pblockstmt)); ;}
    break;

  case 209:
#line 707 "chapel.ypp"
    { (yyval.pblockstmt) = convertTypesToExtern((yyvsp[(3) - (4)].pblockstmt)); ;}
    break;

  case 210:
#line 712 "chapel.ypp"
    {
      VarSymbol* var = new VarSymbol((yyvsp[(1) - (2)].pch));
      var->addFlag(FLAG_TYPE_VARIABLE);
      DefExpr* def = new DefExpr(var, (yyvsp[(2) - (2)].pexpr));
      (yyval.pblockstmt) = buildChapelStmt(def);
    ;}
    break;

  case 211:
#line 719 "chapel.ypp"
    {
      VarSymbol* var = new VarSymbol((yyvsp[(1) - (4)].pch));
      var->addFlag(FLAG_TYPE_VARIABLE);
      DefExpr* def = new DefExpr(var, (yyvsp[(2) - (4)].pexpr));
      (yyvsp[(4) - (4)].pblockstmt)->insertAtHead(def);
      (yyval.pblockstmt) = buildChapelStmt((yyvsp[(4) - (4)].pblockstmt));
    ;}
    break;

  case 212:
#line 729 "chapel.ypp"
    { (yyval.pexpr) = NULL; ;}
    break;

  case 213:
#line 731 "chapel.ypp"
    { (yyval.pexpr) = (yyvsp[(2) - (2)].pexpr); ;}
    break;

  case 214:
#line 733 "chapel.ypp"
    { (yyval.pexpr) = buildForallLoopExprFromArrayType((yyvsp[(2) - (2)].pcallexpr)); ;}
    break;

  case 215:
#line 738 "chapel.ypp"
    {
      (yyval.pblockstmt) = buildVarDecls((yyvsp[(3) - (4)].pblockstmt), (yyvsp[(1) - (4)].flag), FLAG_PARAM, (yylsp[(1) - (4)]).comment);
    ;}
    break;

  case 216:
#line 742 "chapel.ypp"
    {
      (yyval.pblockstmt) = buildVarDecls((yyvsp[(3) - (4)].pblockstmt), (yyvsp[(1) - (4)].flag), FLAG_CONST, (yylsp[(1) - (4)]).comment);
    ;}
    break;

  case 217:
#line 746 "chapel.ypp"
    {
      (yyval.pblockstmt) = buildVarDecls((yyvsp[(3) - (4)].pblockstmt), (yyvsp[(1) - (4)].flag), FLAG_UNKNOWN, (yylsp[(1) - (4)]).comment);
    ;}
    break;

  case 218:
#line 752 "chapel.ypp"
    { (yyval.flag) = FLAG_UNKNOWN; (yyloc).comment = yylloc.comment; yylloc.comment = NULL;;}
    break;

  case 219:
#line 753 "chapel.ypp"
    { (yyval.flag) = FLAG_CONFIG; (yyloc).comment = yylloc.comment; yylloc.comment = NULL;;}
    break;

  case 220:
#line 754 "chapel.ypp"
    { (yyval.flag) = FLAG_EXTERN; (yyloc).comment = yylloc.comment; yylloc.comment = NULL;;}
    break;

  case 222:
#line 760 "chapel.ypp"
    {
      for_alist(expr, (yyvsp[(3) - (3)].pblockstmt)->body)
        (yyvsp[(1) - (3)].pblockstmt)->insertAtTail(expr->remove());
    ;}
    break;

  case 223:
#line 768 "chapel.ypp"
    { (yyval.pblockstmt) = buildChapelStmt(new DefExpr(new VarSymbol((yyvsp[(1) - (3)].pch)), (yyvsp[(3) - (3)].pexpr), (yyvsp[(2) - (3)].pexpr))); ;}
    break;

  case 224:
#line 770 "chapel.ypp"
    {
      VarSymbol* var = new VarSymbol((yyvsp[(1) - (4)].pch));
      var->addFlag(FLAG_ARRAY_ALIAS);
      (yyval.pblockstmt) = buildChapelStmt(new DefExpr(var, (yyvsp[(4) - (4)].pexpr), (yyvsp[(2) - (4)].pexpr)));
    ;}
    break;

  case 225:
#line 776 "chapel.ypp"
    { (yyval.pblockstmt) = buildTupleVarDeclStmt((yyvsp[(2) - (5)].pblockstmt), (yyvsp[(4) - (5)].pexpr), (yyvsp[(5) - (5)].pexpr)); ;}
    break;

  case 226:
#line 781 "chapel.ypp"
    { (yyval.pexpr) = new DefExpr(new VarSymbol("chpl__tuple_blank")); ;}
    break;

  case 227:
#line 783 "chapel.ypp"
    { (yyval.pexpr) = new DefExpr(new VarSymbol((yyvsp[(1) - (1)].pch))); ;}
    break;

  case 228:
#line 785 "chapel.ypp"
    { (yyval.pexpr) = (yyvsp[(2) - (3)].pblockstmt); ;}
    break;

  case 229:
#line 790 "chapel.ypp"
    { (yyval.pblockstmt) = buildChapelStmt((yyvsp[(1) - (1)].pexpr)); ;}
    break;

  case 230:
#line 792 "chapel.ypp"
    { (yyval.pblockstmt) = buildChapelStmt((yyvsp[(1) - (2)].pexpr)); ;}
    break;

  case 231:
#line 794 "chapel.ypp"
    { (yyval.pblockstmt) = ((yyvsp[(3) - (3)].pblockstmt)->insertAtHead((yyvsp[(1) - (3)].pexpr)), (yyvsp[(3) - (3)].pblockstmt)); ;}
    break;

  case 232:
#line 800 "chapel.ypp"
    { (yyval.pexpr) = NULL; ;}
    break;

  case 233:
#line 801 "chapel.ypp"
    { (yyval.pexpr) = (yyvsp[(2) - (2)].pexpr); ;}
    break;

  case 234:
#line 805 "chapel.ypp"
    { (yyval.pexpr) = NULL; ;}
    break;

  case 235:
#line 807 "chapel.ypp"
    { (yyval.pexpr) = new CallExpr("chpl__buildDomainExpr", (yyvsp[(3) - (4)].pcallexpr)); ;}
    break;

  case 236:
#line 811 "chapel.ypp"
    { (yyval.pexpr) = NULL; ;}
    break;

  case 237:
#line 812 "chapel.ypp"
    { (yyval.pexpr) = (yyvsp[(2) - (2)].pexpr); ;}
    break;

  case 238:
#line 813 "chapel.ypp"
    { (yyval.pexpr) = (yyvsp[(2) - (2)].pcallexpr); ;}
    break;

  case 239:
#line 814 "chapel.ypp"
    {printf("bad type specification"); ;}
    break;

  case 240:
#line 835 "chapel.ypp"
    { (yyval.pcallexpr) = new CallExpr("chpl__buildArrayRuntimeType",
             new CallExpr("chpl__buildDomainExpr", (yyvsp[(2) - (4)].pcallexpr)), (yyvsp[(4) - (4)].pexpr)); 
    ;}
    break;

  case 241:
#line 839 "chapel.ypp"
    { (yyval.pcallexpr) = new CallExpr("chpl__buildArrayRuntimeType",
             new CallExpr("chpl__buildDomainExpr", (yyvsp[(2) - (4)].pcallexpr)), (yyvsp[(4) - (4)].pcallexpr)); 
    ;}
    break;

  case 242:
#line 843 "chapel.ypp"
    { 
      if ((yyvsp[(2) - (6)].pcallexpr)->argList.length != 1)
        USR_FATAL((yyvsp[(4) - (6)].pexpr), "invalid index expression");
      (yyval.pcallexpr) = new CallExpr("chpl__buildArrayRuntimeType",
             new CallExpr("chpl__buildDomainExpr", (yyvsp[(4) - (6)].pexpr)), (yyvsp[(6) - (6)].pexpr), (yyvsp[(2) - (6)].pcallexpr)->get(1)->remove(),
             new CallExpr("chpl__buildDomainExpr", (yyvsp[(4) - (6)].pexpr)->copy()));
    ;}
    break;

  case 243:
#line 850 "chapel.ypp"
    {printf("bad array type specification"); clean_exit(1); ;}
    break;

  case 244:
#line 854 "chapel.ypp"
    { (yyval.pexpr) = NULL; ;}
    break;

  case 245:
#line 855 "chapel.ypp"
    { (yyval.pexpr) = (yyvsp[(1) - (1)].pexpr); ;}
    break;

  case 246:
#line 856 "chapel.ypp"
    { (yyval.pexpr) = (yyvsp[(1) - (1)].pdefexpr); ;}
    break;

  case 247:
#line 861 "chapel.ypp"
    { (yyval.pexpr) = new CallExpr("chpl__buildArrayRuntimeType", gNil, (yyvsp[(3) - (3)].pexpr)); ;}
    break;

  case 248:
#line 863 "chapel.ypp"
    { (yyval.pexpr) = buildFormalArrayType((yyvsp[(2) - (4)].pcallexpr), (yyvsp[(4) - (4)].pexpr)); ;}
    break;

  case 249:
#line 869 "chapel.ypp"
    { (yyval.pexpr) = new CallExpr("chpl__buildArrayRuntimeType", gNil, (yyvsp[(3) - (3)].pexpr)); ;}
    break;

  case 250:
#line 871 "chapel.ypp"
    { (yyval.pexpr) = buildFormalArrayType((yyvsp[(2) - (4)].pcallexpr), (yyvsp[(4) - (4)].pexpr)); ;}
    break;

  case 251:
#line 873 "chapel.ypp"
    { (yyval.pexpr) = buildFormalArrayType((yyvsp[(4) - (6)].pexpr), (yyvsp[(6) - (6)].pexpr), (yyvsp[(2) - (6)].pcallexpr)); ;}
    break;

  case 252:
#line 877 "chapel.ypp"
    { (yyval.pexpr) = NULL; ;}
    break;

  case 253:
#line 878 "chapel.ypp"
    { (yyval.pexpr) = (yyvsp[(2) - (2)].pexpr); ;}
    break;

  case 254:
#line 879 "chapel.ypp"
    { (yyval.pexpr) = (yyvsp[(2) - (2)].pdefexpr); ;}
    break;

  case 255:
#line 880 "chapel.ypp"
    { (yyval.pexpr) = new UnresolvedSymExpr("_domain"); ;}
    break;

  case 256:
#line 881 "chapel.ypp"
    { (yyval.pexpr) = new UnresolvedSymExpr( "_singlevar"); ;}
    break;

  case 257:
#line 882 "chapel.ypp"
    { (yyval.pexpr) = new UnresolvedSymExpr( "_syncvar"); ;}
    break;

  case 258:
#line 883 "chapel.ypp"
    { (yyval.pexpr) = (yyvsp[(2) - (2)].pexpr); ;}
    break;

  case 259:
#line 889 "chapel.ypp"
    { (yyval.pcallexpr) = new CallExpr(PRIM_ACTUALS_LIST, (yyvsp[(1) - (1)].pexpr)); ;}
    break;

  case 260:
#line 890 "chapel.ypp"
    { (yyval.pcallexpr) = new CallExpr(PRIM_ACTUALS_LIST, (yyvsp[(1) - (1)].pdefexpr)); ;}
    break;

  case 261:
#line 891 "chapel.ypp"
    { (yyvsp[(1) - (3)].pcallexpr)->insertAtTail((yyvsp[(3) - (3)].pexpr)); ;}
    break;

  case 262:
#line 892 "chapel.ypp"
    { (yyvsp[(1) - (3)].pcallexpr)->insertAtTail((yyvsp[(3) - (3)].pdefexpr)); ;}
    break;

  case 263:
#line 896 "chapel.ypp"
    { (yyval.pexpr) = new UnresolvedSymExpr("chpl__tuple_blank"); ;}
    break;

  case 264:
#line 897 "chapel.ypp"
    { (yyval.pexpr) = (yyvsp[(1) - (1)].pexpr); ;}
    break;

  case 265:
#line 898 "chapel.ypp"
    { (yyval.pexpr) = (yyvsp[(1) - (1)].pdefexpr); ;}
    break;

  case 266:
#line 902 "chapel.ypp"
    { (yyval.pcallexpr) = new CallExpr(PRIM_ACTUALS_LIST, (yyvsp[(1) - (3)].pexpr), (yyvsp[(3) - (3)].pexpr)); ;}
    break;

  case 267:
#line 903 "chapel.ypp"
    { (yyvsp[(1) - (3)].pcallexpr)->insertAtTail((yyvsp[(3) - (3)].pexpr)); ;}
    break;

  case 268:
#line 907 "chapel.ypp"
    { (yyval.pcallexpr) = new CallExpr(PRIM_ACTUALS_LIST); ;}
    break;

  case 270:
#line 912 "chapel.ypp"
    { (yyval.pcallexpr) = new CallExpr(PRIM_ACTUALS_LIST, (yyvsp[(1) - (1)].pexpr)); ;}
    break;

  case 271:
#line 913 "chapel.ypp"
    { (yyvsp[(1) - (3)].pcallexpr)->insertAtTail((yyvsp[(3) - (3)].pexpr)); ;}
    break;

  case 272:
#line 917 "chapel.ypp"
    { (yyval.pexpr) = buildNamedActual((yyvsp[(1) - (3)].pch), (yyvsp[(3) - (3)].pdefexpr)); ;}
    break;

  case 273:
#line 918 "chapel.ypp"
    { (yyval.pexpr) = buildNamedActual((yyvsp[(1) - (3)].pch), (yyvsp[(3) - (3)].pexpr)); ;}
    break;

  case 274:
#line 919 "chapel.ypp"
    { (yyval.pexpr) = buildNamedAliasActual((yyvsp[(1) - (3)].pch), (yyvsp[(3) - (3)].pexpr)); ;}
    break;

  case 275:
#line 920 "chapel.ypp"
    { (yyval.pexpr) = (yyvsp[(1) - (1)].pdefexpr); ;}
    break;

  case 277:
#line 925 "chapel.ypp"
    { (yyval.pexpr) = new UnresolvedSymExpr((yyvsp[(1) - (1)].pch)); ;}
    break;

  case 283:
#line 942 "chapel.ypp"
    { (yyval.pexpr) = new CallExpr( "_singlevar", (yyvsp[(2) - (2)].pexpr)); ;}
    break;

  case 284:
#line 944 "chapel.ypp"
    { (yyval.pexpr) = new CallExpr("chpl__buildIndexType", (yyvsp[(3) - (4)].pcallexpr)); ;}
    break;

  case 285:
#line 946 "chapel.ypp"
    { (yyval.pexpr) = new CallExpr("chpl__buildDomainRuntimeType", new UnresolvedSymExpr("defaultDist"), (yyvsp[(3) - (4)].pcallexpr)); ;}
    break;

  case 286:
#line 948 "chapel.ypp"
    { (yyval.pexpr) = new CallExpr("chpl__buildSubDomainType", (yyvsp[(3) - (4)].pcallexpr)); ;}
    break;

  case 287:
#line 950 "chapel.ypp"
    { (yyval.pexpr) = new CallExpr("chpl__buildSparseDomainRuntimeType", new UnresolvedSymExpr("defaultDist"), (yyvsp[(4) - (5)].pcallexpr)); ;}
    break;

  case 288:
#line 952 "chapel.ypp"
    { (yyval.pexpr) = new CallExpr("chpl__atomicType", (yyvsp[(2) - (2)].pexpr)); ;}
    break;

  case 289:
#line 954 "chapel.ypp"
    { (yyval.pexpr) = new CallExpr( "_syncvar", (yyvsp[(2) - (2)].pexpr)); ;}
    break;

  case 290:
#line 959 "chapel.ypp"
    { (yyval.pexpr) = buildForLoopExpr((yyvsp[(2) - (6)].pexpr), (yyvsp[(4) - (6)].pexpr), (yyvsp[(6) - (6)].pexpr)); ;}
    break;

  case 291:
#line 961 "chapel.ypp"
    { (yyval.pexpr) = buildForLoopExpr((yyvsp[(2) - (6)].pexpr), (yyvsp[(4) - (6)].pexpr), (yyvsp[(6) - (6)].pexpr), NULL, false, true); ;}
    break;

  case 292:
#line 963 "chapel.ypp"
    { (yyval.pexpr) = buildForLoopExpr(NULL, (yyvsp[(2) - (4)].pexpr), (yyvsp[(4) - (4)].pexpr)); ;}
    break;

  case 293:
#line 965 "chapel.ypp"
    { (yyval.pexpr) = buildForLoopExpr((yyvsp[(2) - (9)].pexpr), (yyvsp[(4) - (9)].pexpr), (yyvsp[(9) - (9)].pexpr), (yyvsp[(7) - (9)].pexpr)); ;}
    break;

  case 294:
#line 967 "chapel.ypp"
    { (yyval.pexpr) = buildForLoopExpr((yyvsp[(2) - (9)].pexpr), (yyvsp[(4) - (9)].pexpr), (yyvsp[(9) - (9)].pexpr), (yyvsp[(7) - (9)].pexpr), false, true); ;}
    break;

  case 295:
#line 969 "chapel.ypp"
    { (yyval.pexpr) = buildForLoopExpr(NULL, (yyvsp[(2) - (7)].pexpr), (yyvsp[(7) - (7)].pexpr), (yyvsp[(5) - (7)].pexpr)); ;}
    break;

  case 296:
#line 971 "chapel.ypp"
    { (yyval.pexpr) = buildForallLoopExpr((yyvsp[(2) - (6)].pexpr), (yyvsp[(4) - (6)].pexpr), (yyvsp[(6) - (6)].pexpr)); ;}
    break;

  case 297:
#line 973 "chapel.ypp"
    { (yyval.pexpr) = buildForallLoopExpr((yyvsp[(2) - (6)].pexpr), (yyvsp[(4) - (6)].pexpr), (yyvsp[(6) - (6)].pexpr), NULL, false, true); ;}
    break;

  case 298:
#line 975 "chapel.ypp"
    { (yyval.pexpr) = buildForallLoopExpr(NULL, (yyvsp[(2) - (4)].pexpr), (yyvsp[(4) - (4)].pexpr)); ;}
    break;

  case 299:
#line 977 "chapel.ypp"
    { (yyval.pexpr) = buildForallLoopExpr((yyvsp[(2) - (9)].pexpr), (yyvsp[(4) - (9)].pexpr), (yyvsp[(9) - (9)].pexpr), (yyvsp[(7) - (9)].pexpr)); ;}
    break;

  case 300:
#line 979 "chapel.ypp"
    { (yyval.pexpr) = buildForallLoopExpr((yyvsp[(2) - (9)].pexpr), (yyvsp[(4) - (9)].pexpr), (yyvsp[(9) - (9)].pexpr), (yyvsp[(7) - (9)].pexpr), false, true); ;}
    break;

  case 301:
#line 981 "chapel.ypp"
    { (yyval.pexpr) = buildForallLoopExpr(NULL, (yyvsp[(2) - (7)].pexpr), (yyvsp[(7) - (7)].pexpr), (yyvsp[(5) - (7)].pexpr)); ;}
    break;

  case 302:
#line 983 "chapel.ypp"
    {
      if ((yyvsp[(2) - (4)].pcallexpr)->argList.length > 1)
        (yyval.pexpr) = buildForallLoopExpr(NULL, new CallExpr("chpl__buildDomainExpr", (yyvsp[(2) - (4)].pcallexpr)), (yyvsp[(4) - (4)].pexpr), NULL, true);
      else
        (yyval.pexpr) = buildForallLoopExpr(NULL, (yyvsp[(2) - (4)].pcallexpr)->get(1)->remove(), (yyvsp[(4) - (4)].pexpr), NULL, true);
    ;}
    break;

  case 303:
#line 990 "chapel.ypp"
    {
      if ((yyvsp[(2) - (6)].pcallexpr)->argList.length != 1)
        USR_FATAL((yyvsp[(4) - (6)].pexpr), "invalid index expression");
      (yyval.pexpr) = buildForallLoopExpr((yyvsp[(2) - (6)].pcallexpr)->get(1)->remove(), (yyvsp[(4) - (6)].pexpr), (yyvsp[(6) - (6)].pexpr), NULL, true);
    ;}
    break;

  case 304:
#line 996 "chapel.ypp"
    {
      if ((yyvsp[(2) - (6)].pcallexpr)->argList.length != 1)
        USR_FATAL((yyvsp[(4) - (6)].pexpr), "invalid index expression");
      (yyval.pexpr) = buildForallLoopExpr((yyvsp[(2) - (6)].pcallexpr)->get(1)->remove(), (yyvsp[(4) - (6)].pexpr), (yyvsp[(6) - (6)].pexpr), NULL, false, true);
    ;}
    break;

  case 305:
#line 1002 "chapel.ypp"
    {
      if ((yyvsp[(2) - (9)].pcallexpr)->argList.length != 1)
        USR_FATAL((yyvsp[(4) - (9)].pexpr), "invalid index expression");
      (yyval.pexpr) = buildForallLoopExpr((yyvsp[(2) - (9)].pcallexpr)->get(1)->remove(), (yyvsp[(4) - (9)].pexpr), (yyvsp[(9) - (9)].pexpr), (yyvsp[(7) - (9)].pexpr));
    ;}
    break;

  case 306:
#line 1008 "chapel.ypp"
    {
      if ((yyvsp[(2) - (9)].pcallexpr)->argList.length != 1)
        USR_FATAL((yyvsp[(4) - (9)].pexpr), "invalid index expression");
      (yyval.pexpr) = buildForallLoopExpr((yyvsp[(2) - (9)].pcallexpr)->get(1)->remove(), (yyvsp[(4) - (9)].pexpr), (yyvsp[(9) - (9)].pexpr), (yyvsp[(7) - (9)].pexpr), false, true);
    ;}
    break;

  case 307:
#line 1017 "chapel.ypp"
    { (yyval.pexpr) = new CallExpr(new DefExpr(buildIfExpr((yyvsp[(2) - (6)].pexpr), (yyvsp[(4) - (6)].pexpr), (yyvsp[(6) - (6)].pexpr)))); ;}
    break;

  case 308:
#line 1021 "chapel.ypp"
    { (yyval.pexpr) = new SymExpr(gNil); ;}
    break;

  case 316:
#line 1037 "chapel.ypp"
    { (yyval.pexpr) = new CallExpr("<~>", (yyvsp[(1) - (3)].pexpr), (yyvsp[(3) - (3)].pexpr)); ;}
    break;

  case 317:
#line 1041 "chapel.ypp"
    { (yyval.pcallexpr) = NULL; ;}
    break;

  case 318:
#line 1042 "chapel.ypp"
    { (yyval.pcallexpr) = (yyvsp[(3) - (4)].pcallexpr);   ;}
    break;

  case 319:
#line 1046 "chapel.ypp"
    { (yyval.pcallexpr) = new CallExpr(PRIM_ACTUALS_LIST, (yyvsp[(1) - (1)].pexpr)); ;}
    break;

  case 320:
#line 1047 "chapel.ypp"
    { (yyvsp[(1) - (3)].pcallexpr)->insertAtTail((yyvsp[(3) - (3)].pexpr)); ;}
    break;

  case 322:
#line 1053 "chapel.ypp"
    { (yyval.pexpr) = new CallExpr("<~>", (yyvsp[(1) - (3)].pexpr), (yyvsp[(3) - (3)].pexpr)); ;}
    break;

  case 323:
#line 1058 "chapel.ypp"
    { (yyval.pexpr) = new CallExpr(PRIM_NEW, (yyvsp[(2) - (2)].pexpr)); ;}
    break;

  case 324:
#line 1063 "chapel.ypp"
    { (yyval.pexpr) = buildLetExpr((yyvsp[(2) - (4)].pblockstmt), (yyvsp[(4) - (4)].pexpr)); ;}
    break;

  case 333:
#line 1079 "chapel.ypp"
    { (yyval.pexpr) = new CallExpr(PRIM_TUPLE_EXPAND, (yyvsp[(3) - (4)].pexpr)); ;}
    break;

  case 334:
#line 1081 "chapel.ypp"
    { (yyval.pexpr) = new CallExpr("_cast", (yyvsp[(3) - (3)].pexpr), (yyvsp[(1) - (3)].pexpr)); ;}
    break;

  case 335:
#line 1083 "chapel.ypp"
    { (yyval.pexpr) = new CallExpr("_build_range", (yyvsp[(1) - (3)].pexpr), (yyvsp[(3) - (3)].pexpr)); ;}
    break;

  case 336:
#line 1085 "chapel.ypp"
    { (yyval.pexpr) = new CallExpr("_build_range", buildDotExpr("BoundedRangeType", "boundedLow"), (yyvsp[(1) - (2)].pexpr)); ;}
    break;

  case 337:
#line 1087 "chapel.ypp"
    { (yyval.pexpr) = new CallExpr("_build_range", buildDotExpr("BoundedRangeType", "boundedHigh"), (yyvsp[(2) - (2)].pexpr)); ;}
    break;

  case 338:
#line 1089 "chapel.ypp"
    { (yyval.pexpr) = new CallExpr("_build_range", buildDotExpr("BoundedRangeType", "boundedNone")); ;}
    break;

  case 345:
#line 1112 "chapel.ypp"
    { (yyval.pexpr) = new CallExpr((yyvsp[(1) - (4)].pexpr), (yyvsp[(3) - (4)].pcallexpr)); ;}
    break;

  case 346:
#line 1113 "chapel.ypp"
    { (yyval.pexpr) = buildSquareCallExpr((yyvsp[(1) - (4)].pexpr), (yyvsp[(3) - (4)].pcallexpr)); ;}
    break;

  case 347:
#line 1114 "chapel.ypp"
    { (yyval.pexpr) = buildPrimitiveExpr((yyvsp[(3) - (4)].pcallexpr)); ;}
    break;

  case 348:
#line 1118 "chapel.ypp"
    { (yyval.pexpr) = buildDotExpr((yyvsp[(1) - (3)].pexpr), (yyvsp[(3) - (3)].pch)); ;}
    break;

  case 349:
#line 1119 "chapel.ypp"
    { (yyval.pexpr) = new CallExpr(PRIM_TYPEOF, (yyvsp[(1) - (3)].pexpr)); ;}
    break;

  case 350:
#line 1120 "chapel.ypp"
    { (yyval.pexpr) = buildDotExpr((yyvsp[(1) - (3)].pexpr), "_dom"); ;}
    break;

  case 351:
#line 1128 "chapel.ypp"
    { (yyval.pexpr) = (yyvsp[(2) - (3)].pexpr); ;}
    break;

  case 352:
#line 1129 "chapel.ypp"
    { (yyval.pexpr) = buildOneTuple((yyvsp[(2) - (4)].pexpr)); ;}
    break;

  case 353:
#line 1130 "chapel.ypp"
    { (yyval.pexpr) = buildTuple((yyvsp[(2) - (3)].pcallexpr)); ;}
    break;

  case 354:
#line 1134 "chapel.ypp"
    { (yyval.pexpr) = buildIntLiteral(yytext); ;}
    break;

  case 355:
#line 1135 "chapel.ypp"
    { (yyval.pexpr) = buildRealLiteral(yytext); ;}
    break;

  case 356:
#line 1136 "chapel.ypp"
    { (yyval.pexpr) = buildImagLiteral(yytext); ;}
    break;

  case 357:
#line 1137 "chapel.ypp"
    { (yyval.pexpr) = buildStringLiteral((yyvsp[(1) - (1)].pch)); ;}
    break;

  case 358:
#line 1138 "chapel.ypp"
    { (yyval.pexpr) = new CallExpr("chpl__buildDomainExpr", (yyvsp[(2) - (3)].pcallexpr)); ;}
    break;

  case 359:
#line 1139 "chapel.ypp"
    { (yyval.pexpr) = new CallExpr("chpl__buildArrayExpr", (yyvsp[(2) - (3)].pcallexpr)); ;}
    break;

  case 360:
#line 1141 "chapel.ypp"
    {
      (yyval.pexpr) = new CallExpr("chpl__buildAssociativeArrayExpr", (yyvsp[(2) - (3)].pcallexpr));
    ;}
    break;

  case 361:
#line 1147 "chapel.ypp"
    { (yyval.pcallexpr) = new CallExpr(PRIM_ACTUALS_LIST, (yyvsp[(1) - (3)].pexpr), (yyvsp[(3) - (3)].pexpr)); ;}
    break;

  case 362:
#line 1148 "chapel.ypp"
    { (yyvsp[(1) - (5)].pcallexpr)->insertAtTail((yyvsp[(3) - (5)].pexpr)); (yyvsp[(1) - (5)].pcallexpr)->insertAtTail((yyvsp[(5) - (5)].pexpr)); ;}
    break;

  case 363:
#line 1152 "chapel.ypp"
    { (yyval.pexpr) = new CallExpr("+", (yyvsp[(1) - (3)].pexpr), (yyvsp[(3) - (3)].pexpr)); ;}
    break;

  case 364:
#line 1153 "chapel.ypp"
    { (yyval.pexpr) = new CallExpr("-", (yyvsp[(1) - (3)].pexpr), (yyvsp[(3) - (3)].pexpr)); ;}
    break;

  case 365:
#line 1154 "chapel.ypp"
    { (yyval.pexpr) = new CallExpr("*", (yyvsp[(1) - (3)].pexpr), (yyvsp[(3) - (3)].pexpr)); ;}
    break;

  case 366:
#line 1155 "chapel.ypp"
    { (yyval.pexpr) = new CallExpr("/", (yyvsp[(1) - (3)].pexpr), (yyvsp[(3) - (3)].pexpr)); ;}
    break;

  case 367:
#line 1156 "chapel.ypp"
    { (yyval.pexpr) = new CallExpr("<<", (yyvsp[(1) - (3)].pexpr), (yyvsp[(3) - (3)].pexpr)); ;}
    break;

  case 368:
#line 1157 "chapel.ypp"
    { (yyval.pexpr) = new CallExpr(">>", (yyvsp[(1) - (3)].pexpr), (yyvsp[(3) - (3)].pexpr)); ;}
    break;

  case 369:
#line 1158 "chapel.ypp"
    { (yyval.pexpr) = new CallExpr("%", (yyvsp[(1) - (3)].pexpr), (yyvsp[(3) - (3)].pexpr)); ;}
    break;

  case 370:
#line 1159 "chapel.ypp"
    { (yyval.pexpr) = new CallExpr("==", (yyvsp[(1) - (3)].pexpr), (yyvsp[(3) - (3)].pexpr)); ;}
    break;

  case 371:
#line 1160 "chapel.ypp"
    { (yyval.pexpr) = new CallExpr("!=", (yyvsp[(1) - (3)].pexpr), (yyvsp[(3) - (3)].pexpr)); ;}
    break;

  case 372:
#line 1161 "chapel.ypp"
    { (yyval.pexpr) = new CallExpr("<=", (yyvsp[(1) - (3)].pexpr), (yyvsp[(3) - (3)].pexpr)); ;}
    break;

  case 373:
#line 1162 "chapel.ypp"
    { (yyval.pexpr) = new CallExpr(">=", (yyvsp[(1) - (3)].pexpr), (yyvsp[(3) - (3)].pexpr)); ;}
    break;

  case 374:
#line 1163 "chapel.ypp"
    { (yyval.pexpr) = new CallExpr("<", (yyvsp[(1) - (3)].pexpr), (yyvsp[(3) - (3)].pexpr)); ;}
    break;

  case 375:
#line 1164 "chapel.ypp"
    { (yyval.pexpr) = new CallExpr(">", (yyvsp[(1) - (3)].pexpr), (yyvsp[(3) - (3)].pexpr)); ;}
    break;

  case 376:
#line 1165 "chapel.ypp"
    { (yyval.pexpr) = new CallExpr("&", (yyvsp[(1) - (3)].pexpr), (yyvsp[(3) - (3)].pexpr)); ;}
    break;

  case 377:
#line 1166 "chapel.ypp"
    { (yyval.pexpr) = new CallExpr("|", (yyvsp[(1) - (3)].pexpr), (yyvsp[(3) - (3)].pexpr)); ;}
    break;

  case 378:
#line 1167 "chapel.ypp"
    { (yyval.pexpr) = new CallExpr("^", (yyvsp[(1) - (3)].pexpr), (yyvsp[(3) - (3)].pexpr)); ;}
    break;

  case 379:
#line 1168 "chapel.ypp"
    { (yyval.pexpr) = buildLogicalAndExpr((yyvsp[(1) - (3)].pexpr), (yyvsp[(3) - (3)].pexpr)); ;}
    break;

  case 380:
#line 1169 "chapel.ypp"
    { (yyval.pexpr) = buildLogicalOrExpr((yyvsp[(1) - (3)].pexpr), (yyvsp[(3) - (3)].pexpr)); ;}
    break;

  case 381:
#line 1170 "chapel.ypp"
    { (yyval.pexpr) = new CallExpr("**", (yyvsp[(1) - (3)].pexpr), (yyvsp[(3) - (3)].pexpr)); ;}
    break;

  case 382:
#line 1171 "chapel.ypp"
    { (yyval.pexpr) = new CallExpr("by", (yyvsp[(1) - (3)].pexpr), (yyvsp[(3) - (3)].pexpr)); ;}
    break;

  case 383:
#line 1172 "chapel.ypp"
    { (yyval.pexpr) = new CallExpr("align", (yyvsp[(1) - (3)].pexpr), (yyvsp[(3) - (3)].pexpr)); ;}
    break;

  case 384:
#line 1173 "chapel.ypp"
    { (yyval.pexpr) = new CallExpr("#", (yyvsp[(1) - (3)].pexpr), (yyvsp[(3) - (3)].pexpr)); ;}
    break;

  case 385:
#line 1174 "chapel.ypp"
    { (yyval.pexpr) = new CallExpr("chpl__distributed", (yyvsp[(3) - (3)].pexpr), (yyvsp[(1) - (3)].pexpr)); ;}
    break;

  case 386:
#line 1178 "chapel.ypp"
    { (yyval.pexpr) = new CallExpr("+", (yyvsp[(2) - (2)].pexpr)); ;}
    break;

  case 387:
#line 1179 "chapel.ypp"
    { (yyval.pexpr) = new CallExpr("-", (yyvsp[(2) - (2)].pexpr)); ;}
    break;

  case 388:
#line 1180 "chapel.ypp"
    { (yyval.pexpr) = buildPreDecIncWarning((yyvsp[(2) - (2)].pexpr), '-'); ;}
    break;

  case 389:
#line 1181 "chapel.ypp"
    { (yyval.pexpr) = buildPreDecIncWarning((yyvsp[(2) - (2)].pexpr), '+'); ;}
    break;

  case 390:
#line 1182 "chapel.ypp"
    { (yyval.pexpr) = new CallExpr("!", (yyvsp[(2) - (2)].pexpr)); ;}
    break;

  case 391:
#line 1183 "chapel.ypp"
    { (yyval.pexpr) = new CallExpr("~", (yyvsp[(2) - (2)].pexpr)); ;}
    break;

  case 392:
#line 1187 "chapel.ypp"
    { (yyval.pexpr) = buildReduceExpr((yyvsp[(1) - (3)].pexpr), (yyvsp[(3) - (3)].pexpr)); ;}
    break;

  case 393:
#line 1188 "chapel.ypp"
    { (yyval.pexpr) = buildReduceExpr((yyvsp[(1) - (3)].pexpr), (yyvsp[(3) - (3)].pexpr), true); ;}
    break;

  case 394:
#line 1189 "chapel.ypp"
    { (yyval.pexpr) = buildReduceExpr((yyvsp[(1) - (3)].pexpr), (yyvsp[(3) - (3)].pexpr)); ;}
    break;

  case 395:
#line 1190 "chapel.ypp"
    { (yyval.pexpr) = buildReduceExpr((yyvsp[(1) - (3)].pexpr), (yyvsp[(3) - (3)].pexpr), true); ;}
    break;

  case 396:
#line 1194 "chapel.ypp"
    { (yyval.pexpr) = buildScanExpr((yyvsp[(1) - (3)].pexpr), (yyvsp[(3) - (3)].pexpr)); ;}
    break;

  case 397:
#line 1195 "chapel.ypp"
    { (yyval.pexpr) = buildScanExpr((yyvsp[(1) - (3)].pexpr), (yyvsp[(3) - (3)].pexpr), true); ;}
    break;

  case 398:
#line 1196 "chapel.ypp"
    { (yyval.pexpr) = buildScanExpr((yyvsp[(1) - (3)].pexpr), (yyvsp[(3) - (3)].pexpr)); ;}
    break;

  case 399:
#line 1197 "chapel.ypp"
    { (yyval.pexpr) = buildScanExpr((yyvsp[(1) - (3)].pexpr), (yyvsp[(3) - (3)].pexpr), true); ;}
    break;

  case 400:
#line 1202 "chapel.ypp"
    { (yyval.pexpr) = new UnresolvedSymExpr("SumReduceScanOp"); ;}
    break;

  case 401:
#line 1203 "chapel.ypp"
    { (yyval.pexpr) = new UnresolvedSymExpr("ProductReduceScanOp"); ;}
    break;

  case 402:
#line 1204 "chapel.ypp"
    { (yyval.pexpr) = new UnresolvedSymExpr("LogicalAndReduceScanOp"); ;}
    break;

  case 403:
#line 1205 "chapel.ypp"
    { (yyval.pexpr) = new UnresolvedSymExpr("LogicalOrReduceScanOp"); ;}
    break;

  case 404:
#line 1206 "chapel.ypp"
    { (yyval.pexpr) = new UnresolvedSymExpr("BitwiseAndReduceScanOp"); ;}
    break;

  case 405:
#line 1207 "chapel.ypp"
    { (yyval.pexpr) = new UnresolvedSymExpr("BitwiseOrReduceScanOp"); ;}
    break;

  case 406:
#line 1208 "chapel.ypp"
    { (yyval.pexpr) = new UnresolvedSymExpr("BitwiseXorReduceScanOp"); ;}
    break;


/* Line 1267 of yacc.c.  */
#line 6378 "chapel.tab.cpp"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;
  *++yylsp = yyloc;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }

  yyerror_range[0] = yylloc;

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval, &yylloc);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse look-ahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  yyerror_range[0] = yylsp[1-yylen];
  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;

      yyerror_range[0] = *yylsp;
      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;

  yyerror_range[1] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the look-ahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, (yyerror_range - 1), 2);
  *++yylsp = yyloc;

  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval, &yylloc);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp, yylsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 1211 "chapel.ypp"


