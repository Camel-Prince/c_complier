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
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     ASSIGN_OP = 258,
     OR = 259,
     AND = 260,
     SINGLAND = 261,
     NE_OP = 262,
     EQ_OP = 263,
     LE_OP = 264,
     GE_OP = 265,
     LT_OP = 266,
     GT_OP = 267,
     SUB = 268,
     ADD = 269,
     MOD = 270,
     DIV = 271,
     MUL = 272,
     POW = 273,
     NOT = 274,
     PRINTF = 275,
     SCANF = 276,
     IDENTIFIER = 277,
     CONST = 278,
     LOWER_THAN_ELSE = 279,
     EOL = 280,
     D_QUO = 281,
     S_QUO = 282,
     SEMI = 283,
     COMMA = 284,
     CONTINUE = 285,
     BREAK = 286,
     VOID = 287,
     INT = 288,
     RETURN = 289,
     THEN = 290,
     ELSE = 291,
     IF = 292,
     FOR = 293,
     WHILE = 294
   };
#endif
/* Tokens.  */
#define ASSIGN_OP 258
#define OR 259
#define AND 260
#define SINGLAND 261
#define NE_OP 262
#define EQ_OP 263
#define LE_OP 264
#define GE_OP 265
#define LT_OP 266
#define GT_OP 267
#define SUB 268
#define ADD 269
#define MOD 270
#define DIV 271
#define MUL 272
#define POW 273
#define NOT 274
#define PRINTF 275
#define SCANF 276
#define IDENTIFIER 277
#define CONST 278
#define LOWER_THAN_ELSE 279
#define EOL 280
#define D_QUO 281
#define S_QUO 282
#define SEMI 283
#define COMMA 284
#define CONTINUE 285
#define BREAK 286
#define VOID 287
#define INT 288
#define RETURN 289
#define THEN 290
#define ELSE 291
#define IF 292
#define FOR 293
#define WHILE 294




/* Copy the first part of user declarations.  */
#line 1 "parser.y"

#include "./abstract_syntax_tree/AstNode.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
#include "./symbol_table/symbol.h"
#include "./intermidiate_code/interCode.h"
extern char *yytext;
extern int yylex();
extern void yyerror(char* s);
extern FILE * yyin;
AbstractAstNode* root;
std::stack<SymbolTable*> SymbolTableList;


/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
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
#line 17 "parser.y"
{
  AbstractAstNode* ast;
  char* str;
}
/* Line 193 of yacc.c.  */
#line 195 "parser.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 208 "parser.tab.c"

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
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

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
#define YYFINAL  8
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   717

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  46
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  20
/* YYNRULES -- Number of rules.  */
#define YYNRULES  88
/* YYNRULES -- Number of states.  */
#define YYNSTATES  189

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   294

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      20,    21,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    22,     2,    23,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    34,     2,    35,     2,     2,     2,     2,
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
      15,    16,    17,    18,    19,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     7,    10,    14,    18,    22,    24,
      29,    34,    38,    41,    45,    47,    49,    51,    54,    58,
      63,    67,    69,    72,    77,    83,    87,    91,    93,    97,
     100,   101,   104,   107,   109,   113,   116,   122,   130,   136,
     143,   151,   159,   167,   177,   186,   195,   204,   207,   210,
     218,   224,   230,   233,   235,   239,   241,   245,   247,   249,
     251,   253,   257,   261,   265,   269,   273,   277,   281,   285,
     288,   292,   296,   299,   303,   307,   311,   315,   319,   323,
     327,   332,   336,   339,   344,   347,   349,   353,   355
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      47,     0,    -1,    48,    -1,    49,    -1,    48,    49,    -1,
      52,    60,    32,    -1,    52,    53,    56,    -1,    52,    53,
      32,    -1,    26,    -1,    26,    22,    27,    23,    -1,    26,
      22,    63,    23,    -1,    26,    22,    23,    -1,    17,    26,
      -1,    51,    33,    27,    -1,    27,    -1,    39,    -1,    38,
      -1,    39,    17,    -1,    26,    20,    21,    -1,    26,    20,
      54,    21,    -1,    54,    33,    55,    -1,    55,    -1,    52,
      26,    -1,    52,    26,    22,    23,    -1,    52,    26,    22,
      27,    23,    -1,    52,     6,    26,    -1,    52,    17,    26,
      -1,    52,    -1,    34,    57,    35,    -1,    57,    58,    -1,
      -1,    63,    32,    -1,    59,    32,    -1,    56,    -1,    40,
      63,    32,    -1,    40,    32,    -1,    43,    20,    63,    21,
      58,    -1,    43,    20,    63,    21,    58,    42,    58,    -1,
      45,    20,    63,    21,    58,    -1,    44,    20,    32,    32,
      21,    58,    -1,    44,    20,    62,    32,    32,    21,    58,
      -1,    44,    20,    32,    63,    32,    21,    58,    -1,    44,
      20,    32,    32,    63,    21,    58,    -1,    44,    20,    62,
      32,    63,    32,    63,    21,    58,    -1,    44,    20,    62,
      32,    63,    32,    21,    58,    -1,    44,    20,    62,    32,
      32,    63,    21,    58,    -1,    44,    20,    32,    63,    32,
      63,    21,    58,    -1,    37,    32,    -1,    36,    32,    -1,
      24,    20,    30,    63,    30,    21,    32,    -1,    24,    20,
      63,    21,    32,    -1,    25,    20,    26,    21,    32,    -1,
      52,    60,    -1,    61,    -1,    61,    33,    60,    -1,    50,
      -1,    50,     3,    63,    -1,    59,    -1,    63,    -1,    27,
      -1,    65,    -1,    63,     3,    63,    -1,    63,    14,    63,
      -1,    63,    13,    63,    -1,    63,    17,    63,    -1,    63,
      16,    63,    -1,    63,    15,    63,    -1,    63,    18,    63,
      -1,    20,    63,    21,    -1,    13,    63,    -1,    63,     5,
      63,    -1,    63,     4,    63,    -1,    19,    63,    -1,    34,
      51,    35,    -1,    63,     8,    63,    -1,    63,     7,    63,
      -1,    63,    12,    63,    -1,    63,    11,    63,    -1,    63,
      10,    63,    -1,    63,     9,    63,    -1,    26,    20,    64,
      21,    -1,    26,    20,    21,    -1,    17,    26,    -1,    26,
      22,    63,    23,    -1,     6,    26,    -1,    63,    -1,    64,
      33,    63,    -1,    26,    -1,    65,    26,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    77,    77,    86,    93,   104,   112,   121,   132,   154,
     163,   171,   178,   197,   205,   217,   224,   231,   242,   250,
     264,   272,   280,   288,   296,   306,   314,   322,   331,   341,
     353,   360,   367,   375,   381,   390,   397,   407,   418,   427,
     435,   444,   452,   460,   470,   479,   488,   497,   501,   505,
     511,   516,   526,   537,   544,   555,   562,   573,   579,   588,
     602,   607,   613,   619,   625,   631,   637,   643,   649,   655,
     661,   668,   675,   680,   686,   692,   698,   704,   710,   716,
     723,   731,   738,   744,   751,   759,   764,   772,   779
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ASSIGN_OP", "OR", "AND", "SINGLAND",
  "NE_OP", "EQ_OP", "LE_OP", "GE_OP", "LT_OP", "GT_OP", "SUB", "ADD",
  "MOD", "DIV", "MUL", "POW", "NOT", "'('", "')'", "'['", "']'", "PRINTF",
  "SCANF", "IDENTIFIER", "CONST", "LOWER_THAN_ELSE", "EOL", "D_QUO",
  "S_QUO", "SEMI", "COMMA", "'{'", "'}'", "CONTINUE", "BREAK", "VOID",
  "INT", "RETURN", "THEN", "ELSE", "IF", "FOR", "WHILE", "$accept",
  "Program", "BlockList", "Block", "Vardef", "Consts", "Descriptor",
  "Func", "VarList", "Param", "Body", "StmtList", "Stmt", "Def", "DefList",
  "Var", "Fordef", "Exp", "Args", "IDList", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
      40,    41,    91,    93,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,   123,   125,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    46,    47,    48,    48,    49,    49,    49,    50,    50,
      50,    50,    50,    51,    51,    52,    52,    52,    53,    53,
      54,    54,    55,    55,    55,    55,    55,    55,    56,    57,
      57,    58,    58,    58,    58,    58,    58,    58,    58,    58,
      58,    58,    58,    58,    58,    58,    58,    58,    58,    58,
      58,    58,    59,    60,    60,    61,    61,    62,    62,    63,
      63,    63,    63,    63,    63,    63,    63,    63,    63,    63,
      63,    63,    63,    63,    63,    63,    63,    63,    63,    63,
      63,    63,    63,    63,    63,    64,    64,    65,    65
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     2,     3,     3,     3,     1,     4,
       4,     3,     2,     3,     1,     1,     1,     2,     3,     4,
       3,     1,     2,     4,     5,     3,     3,     1,     3,     2,
       0,     2,     2,     1,     3,     2,     5,     7,     5,     6,
       7,     7,     7,     9,     8,     8,     8,     2,     2,     7,
       5,     5,     2,     1,     3,     1,     3,     1,     1,     1,
       1,     3,     3,     3,     3,     3,     3,     3,     3,     2,
       3,     3,     2,     3,     3,     3,     3,     3,     3,     3,
       4,     3,     2,     4,     2,     1,     3,     1,     2
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    16,    15,     0,     2,     3,     0,    17,     1,     4,
       0,     8,    55,     0,     0,    53,    12,     0,     0,     0,
       7,    30,     6,     5,     0,    18,    27,     0,    21,     0,
       0,     0,     0,     0,    11,    87,    59,     0,     0,    60,
      59,    56,     0,     8,    54,     0,     0,    22,    19,     0,
      84,    69,    82,    72,     0,     0,     0,     9,    14,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    10,    88,     0,     0,    30,
      28,     0,     0,     0,     0,     0,     0,     0,    33,    29,
       0,     0,    25,    26,     0,    20,    68,    81,    85,     0,
       0,     0,    73,    61,    71,    70,    75,    74,    79,    78,
      77,    76,    63,    62,    66,    65,    64,    67,     0,     0,
      48,    47,    35,     0,     0,     0,     0,    52,    32,    31,
      23,     0,    80,     0,    83,    13,     0,     0,     0,    34,
       0,     0,    57,     0,    58,     0,    24,    86,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    50,    51,    36,
       0,     0,     0,     0,     0,    38,     0,     0,    39,     0,
       0,     0,     0,     0,     0,    49,    37,    42,    41,     0,
      40,     0,     0,     0,    46,    45,    44,     0,    43
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,     4,     5,    12,    59,    87,    13,    27,    28,
      88,    42,    89,    90,    14,    15,   143,    91,    99,    39
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -51
static const yytype_int16 yypact[] =
{
      -4,   -51,   -51,     7,    -4,   -51,    10,   -51,   -51,   -51,
      -3,   -14,    37,    27,    30,     8,   -51,   -19,     5,   435,
     -51,   -51,   -51,   -51,    43,   -51,     4,   -17,   -51,    41,
     435,    47,   435,   435,   -51,    52,    40,    65,   487,    67,
     -51,   673,    51,    76,   -51,    77,    78,    80,   -51,    -4,
     -51,    96,   -51,   -51,   521,   291,   435,   -51,   -51,    64,
     435,   435,   435,   435,   435,   435,   435,   435,   435,   435,
     435,   435,   435,   435,   435,   -51,   -51,    89,   101,    65,
     -51,    84,    92,   307,   105,   106,   107,    43,   -51,   -51,
      98,   199,   -51,   -51,     6,   -51,   -51,   -51,   673,   -16,
     504,   108,   -51,   673,   687,   699,   209,   209,    66,    66,
      66,    66,    96,    96,   110,   110,   110,   -51,   323,   112,
     -51,   -51,   -51,   225,   435,   162,   435,   -51,   -51,   -51,
     -51,   117,   -51,   435,   -51,   -51,   435,   540,   120,   -51,
     559,   339,   -51,   111,   673,   578,   -51,   673,   463,   115,
     116,   133,   355,   251,   371,   133,   121,   -51,   -51,    91,
     133,   597,   387,   403,   277,   -51,   119,   133,   -51,   133,
     133,   616,   133,   635,   419,   -51,   -51,   -51,   -51,   133,
     -51,   133,   133,   654,   -51,   -51,   -51,   133,   -51
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -51,   -51,   -51,   145,   -51,   -51,     9,   -51,   -51,   113,
     141,   -51,   -50,    36,   -21,   -51,   -51,   -18,   -51,   -51
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      38,    41,    25,    44,    48,   132,    17,     8,    18,     6,
      45,    29,    51,     6,    53,    54,    49,   133,    30,     1,
       2,    46,    31,    16,    32,    33,    26,    10,    34,   130,
      47,    35,    36,   131,     1,     2,    11,    98,   100,    37,
      19,    24,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,    29,    26,    20,
      10,    21,    23,    57,    30,   123,   127,    50,    31,    43,
      32,    33,    55,    52,    56,    77,    78,    35,    40,    69,
      70,    71,    72,    73,    74,    79,    80,    81,    82,     1,
       2,    83,    58,    76,    84,    85,    86,   101,    18,   102,
     137,   159,    94,    92,    93,   165,   140,   144,   145,   118,
     168,    71,    72,    73,    74,   147,   120,   176,   148,   177,
     178,   119,   180,   153,   121,   124,   125,   126,    74,   184,
     128,   185,   186,   167,   161,   135,   164,   188,   138,    29,
     146,   150,   166,   154,   171,   173,    30,   157,   158,     9,
      31,   175,    32,    33,    22,     0,   183,    77,    78,    35,
      40,   142,    95,     0,     0,     0,     0,    79,    29,    81,
      82,     1,     2,    83,     0,    30,    84,    85,    86,    31,
       0,    32,    33,     0,     0,     0,     0,     0,    35,    40,
       0,     0,     0,     0,   141,     0,    37,     0,     0,     0,
       1,     2,    60,    61,    62,     0,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    60,    61,
      62,   129,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    60,    61,    62,   139,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      60,    61,    62,   162,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,     0,    29,     0,     0,
       0,     0,     0,     0,    30,     0,     0,     0,    31,   174,
      32,    33,    97,    29,     0,     0,     0,    35,    40,     0,
      30,     0,     0,     0,    31,    37,    32,    33,     0,    29,
       0,     0,     0,    35,    40,     0,    30,     0,     0,   122,
      31,    37,    32,    33,     0,    29,     0,     0,     0,    35,
      40,     0,    30,   136,     0,     0,    31,    37,    32,    33,
       0,    29,     0,     0,     0,    35,    40,     0,    30,     0,
       0,   152,    31,    37,    32,    33,   160,    29,     0,     0,
       0,    35,    40,     0,    30,     0,     0,     0,    31,    37,
      32,    33,     0,    29,     0,     0,     0,    35,    40,     0,
      30,     0,     0,   163,    31,    37,    32,    33,   170,    29,
       0,     0,     0,    35,    40,     0,    30,     0,     0,     0,
      31,    37,    32,    33,   172,    29,     0,     0,     0,    35,
      40,     0,    30,     0,     0,     0,    31,    37,    32,    33,
     182,    29,     0,     0,     0,    35,    40,     0,    30,     0,
       0,     0,    31,    37,    32,    33,     0,     0,     0,     0,
       0,    35,    40,     0,     0,     0,    60,    61,    62,    37,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,     0,     0,     0,     0,     0,     0,     0,     0,
      60,    61,    62,   156,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,     0,    60,    61,    62,
      75,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,     0,    60,    61,    62,   134,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
       0,     0,    96,    60,    61,    62,     0,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,     0,
       0,   149,    60,    61,    62,     0,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,     0,     0,
     151,    60,    61,    62,     0,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,     0,     0,   155,
      60,    61,    62,     0,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,     0,     0,   169,    60,
      61,    62,     0,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,     0,     0,   179,    60,    61,
      62,     0,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,     0,     0,   181,    60,    61,    62,
       0,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,     0,     0,   187,    60,    61,    62,     0,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    62,     0,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74
};

static const yytype_int16 yycheck[] =
{
      18,    19,    21,    24,    21,    21,    20,     0,    22,     0,
       6,     6,    30,     4,    32,    33,    33,    33,    13,    38,
      39,    17,    17,    26,    19,    20,    17,    17,    23,    23,
      26,    26,    27,    27,    38,    39,    26,    55,    56,    34,
       3,    33,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,     6,    49,    32,
      17,    34,    32,    23,    13,    83,    87,    26,    17,    26,
      19,    20,    20,    26,    22,    24,    25,    26,    27,    13,
      14,    15,    16,    17,    18,    34,    35,    36,    37,    38,
      39,    40,    27,    26,    43,    44,    45,    33,    22,    35,
     118,   151,    22,    26,    26,   155,   124,   125,   126,    20,
     160,    15,    16,    17,    18,   133,    32,   167,   136,   169,
     170,    20,   172,   141,    32,    20,    20,    20,    18,   179,
      32,   181,   182,    42,   152,    27,   154,   187,    26,     6,
      23,    21,    21,    32,   162,   163,    13,    32,    32,     4,
      17,    32,    19,    20,    13,    -1,   174,    24,    25,    26,
      27,   125,    49,    -1,    -1,    -1,    -1,    34,     6,    36,
      37,    38,    39,    40,    -1,    13,    43,    44,    45,    17,
      -1,    19,    20,    -1,    -1,    -1,    -1,    -1,    26,    27,
      -1,    -1,    -1,    -1,    32,    -1,    34,    -1,    -1,    -1,
      38,    39,     3,     4,     5,    -1,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,     3,     4,
       5,    32,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     3,     4,     5,    32,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       3,     4,     5,    32,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    -1,     6,    -1,    -1,
      -1,    -1,    -1,    -1,    13,    -1,    -1,    -1,    17,    32,
      19,    20,    21,     6,    -1,    -1,    -1,    26,    27,    -1,
      13,    -1,    -1,    -1,    17,    34,    19,    20,    -1,     6,
      -1,    -1,    -1,    26,    27,    -1,    13,    -1,    -1,    32,
      17,    34,    19,    20,    -1,     6,    -1,    -1,    -1,    26,
      27,    -1,    13,    30,    -1,    -1,    17,    34,    19,    20,
      -1,     6,    -1,    -1,    -1,    26,    27,    -1,    13,    -1,
      -1,    32,    17,    34,    19,    20,    21,     6,    -1,    -1,
      -1,    26,    27,    -1,    13,    -1,    -1,    -1,    17,    34,
      19,    20,    -1,     6,    -1,    -1,    -1,    26,    27,    -1,
      13,    -1,    -1,    32,    17,    34,    19,    20,    21,     6,
      -1,    -1,    -1,    26,    27,    -1,    13,    -1,    -1,    -1,
      17,    34,    19,    20,    21,     6,    -1,    -1,    -1,    26,
      27,    -1,    13,    -1,    -1,    -1,    17,    34,    19,    20,
      21,     6,    -1,    -1,    -1,    26,    27,    -1,    13,    -1,
      -1,    -1,    17,    34,    19,    20,    -1,    -1,    -1,    -1,
      -1,    26,    27,    -1,    -1,    -1,     3,     4,     5,    34,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       3,     4,     5,    30,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    -1,     3,     4,     5,
      23,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    -1,     3,     4,     5,    23,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      -1,    -1,    21,     3,     4,     5,    -1,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    -1,
      -1,    21,     3,     4,     5,    -1,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    -1,    -1,
      21,     3,     4,     5,    -1,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    -1,    -1,    21,
       3,     4,     5,    -1,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    -1,    -1,    21,     3,
       4,     5,    -1,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    -1,    -1,    21,     3,     4,
       5,    -1,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    -1,    -1,    21,     3,     4,     5,
      -1,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    -1,    -1,    21,     3,     4,     5,    -1,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,     5,    -1,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    38,    39,    47,    48,    49,    52,    17,     0,    49,
      17,    26,    50,    53,    60,    61,    26,    20,    22,     3,
      32,    34,    56,    32,    33,    21,    52,    54,    55,     6,
      13,    17,    19,    20,    23,    26,    27,    34,    63,    65,
      27,    63,    57,    26,    60,     6,    17,    26,    21,    33,
      26,    63,    26,    63,    63,    20,    22,    23,    27,    51,
       3,     4,     5,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    23,    26,    24,    25,    34,
      35,    36,    37,    40,    43,    44,    45,    52,    56,    58,
      59,    63,    26,    26,    22,    55,    21,    21,    63,    64,
      63,    33,    35,    63,    63,    63,    63,    63,    63,    63,
      63,    63,    63,    63,    63,    63,    63,    63,    20,    20,
      32,    32,    32,    63,    20,    20,    20,    60,    32,    32,
      23,    27,    21,    33,    23,    27,    30,    63,    26,    32,
      63,    32,    59,    62,    63,    63,    23,    63,    63,    21,
      21,    21,    32,    63,    32,    21,    30,    32,    32,    58,
      21,    63,    32,    32,    63,    58,    21,    42,    58,    21,
      21,    63,    21,    63,    32,    32,    58,    58,    58,    21,
      58,    21,    21,    63,    58,    58,    58,    21,    58
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
		  Type, Value); \
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
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
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
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
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
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
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
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
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
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

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



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


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


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),

		    &yystacksize);

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

#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;


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


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 77 "parser.y"
    {
        root = new AbstractAstNode(AstNodeType::ROOT,"Program");
        root->addFirstChild((yyvsp[(1) - (1)].ast));
        printAst(root);
    ;}
    break;

  case 3:
#line 86 "parser.y"
    {
      printf("Blocklist->block \n");
        AbstractAstNode* node = new AbstractAstNode(AstNodeType::STATEMENT,"Single_Block");
        node->addFirstChild((yyvsp[(1) - (1)].ast));
        (yyval.ast) = node;
    ;}
    break;

  case 4:
#line 93 "parser.y"
    {
    printf("blocklist->blocklist block \n");
        AbstractAstNode* node = new AbstractAstNode(AstNodeType::STATEMENT,"Some_Block");
        node->addFirstChild((yyvsp[(1) - (2)].ast));
        (yyvsp[(1) - (2)].ast)->addNextSibling((yyvsp[(2) - (2)].ast));
        (yyval.ast)=node;
    ;}
    break;

  case 5:
#line 104 "parser.y"
    {
      printf("blcok->Descriptor Vardef SEMI \n");
        AbstractAstNode* node = new AbstractAstNode(AstNodeType::DEFINITION,"Def_Var_Block");        
        node->addFirstChild((yyvsp[(1) - (3)].ast));        
        (yyvsp[(1) - (3)].ast)->addNextSibling((yyvsp[(2) - (3)].ast));        
        (yyval.ast) = node;
    ;}
    break;

  case 6:
#line 112 "parser.y"
    {
    printf("block->Descriptor Func Body \n");
        AbstractAstNode* node = new AbstractAstNode(AstNodeType::DEFINITION,"Def_Func_Body_Block");
        node->addFirstChild((yyvsp[(1) - (3)].ast));
        (yyvsp[(1) - (3)].ast)->addNextSibling((yyvsp[(2) - (3)].ast));
        (yyvsp[(2) - (3)].ast)->addNextSibling((yyvsp[(3) - (3)].ast));
        (yyval.ast) = node;
    ;}
    break;

  case 7:
#line 121 "parser.y"
    {
    printf("block->Descriptor Func SEMI \n");
        AbstractAstNode* node = new AbstractAstNode(AstNodeType::DEFINITION,"Def_Func_NBody_Block");
        node->addFirstChild((yyvsp[(1) - (3)].ast));
        (yyvsp[(1) - (3)].ast)->addNextSibling((yyvsp[(2) - (3)].ast));
        (yyval.ast) = node;
    ;}
    break;

  case 8:
#line 132 "parser.y"
    {//a ok
      printf("vardef->identifier \n");
        AbstractAstNode* node = new AbstractAstNode(AstNodeType::DEFINITION,"Block_Single_Vardef");
        AbstractAstNode* var_node = new AbstractAstNode(AstNodeType::ID, (yyvsp[(1) - (1)].str));
        node->addFirstChild(var_node);
        (yyval.ast) = node;

        // SymbolTable* this_scope = SymbolTableList.top();
        // printf("Get the ID's Scope\n");
        // printf("*********\n");
        // Symbol* syn = new Symbol($1);
        // bool result = this_scope->addSymbol(syn);
        // if(result == true){
        //   printf("add ID success!\n");
        // }
        // else {
        //   printf("Duplicate define!\n");
        //   exit(1);
        // }
        // printf("result: %d\n", result);
    ;}
    break;

  case 9:
#line 154 "parser.y"
    {//id[10]
    printf("vardef->identifier[const] \n");
        AbstractAstNode* node = new AbstractAstNode(AstNodeType::ARRAY,"array_id[const]");
        AbstractAstNode* const_node = new AbstractAstNode(AstNodeType::CONST_INT, (yyvsp[(3) - (4)].str));
        AbstractAstNode* var_node = new AbstractAstNode(AstNodeType::ID, (yyvsp[(1) - (4)].str));
        node->addFirstChild(var_node);
        var_node->addNextSibling(const_node);
        (yyval.ast) = node;
    ;}
    break;

  case 10:
#line 163 "parser.y"
    {//id[n] in function(param)
    printf("vardef->identifier[exp] \n");
      AbstractAstNode* node = new AbstractAstNode(AstNodeType::ARRAY,"array_id[exp]");
      AbstractAstNode* var_node = new AbstractAstNode(AstNodeType::ID, (yyvsp[(1) - (4)].str));
      node->addFirstChild(var_node);
      var_node->addNextSibling((yyvsp[(3) - (4)].ast));
      (yyval.ast) = node;
  ;}
    break;

  case 11:
#line 171 "parser.y"
    {//id[]
    printf("vardef->identifier[] \n");
        AbstractAstNode* node = new AbstractAstNode(AstNodeType::ARRAY,"array_id[]");
        AbstractAstNode* var_node = new AbstractAstNode(AstNodeType::ID, (yyvsp[(1) - (3)].str));
        node->addFirstChild(var_node);
        (yyval.ast) = node;
    ;}
    break;

  case 12:
#line 178 "parser.y"
    {
    printf("vardef->*identifier \n");
        AbstractAstNode* node = new AbstractAstNode(AstNodeType::ARRAY,"array_*id");
        AbstractAstNode* var_node = new AbstractAstNode(AstNodeType::ID, (yyvsp[(2) - (2)].str));
        node->addFirstChild(var_node);
        (yyval.ast) = node;

        // SymbolTable* this_scope = SymbolTableList.top();
        // Symbol* s = new Symbol($2, SymbolType::pointer);
        // bool result = this_scope->addSymbol(s);
        // if(result == false){
        //   printf("Duplicate definition");
        //   exit(1);
        // }else{
        //   printf("Add A Pointer\n");
        // }
  ;}
    break;

  case 13:
#line 197 "parser.y"
    {
    printf("consts->consts const \n");
      AbstractAstNode* node = new AbstractAstNode(AstNodeType::EXPRESSION,"consts_array");
      AbstractAstNode* const_node = new AbstractAstNode(AstNodeType::CONST_INT, (yyvsp[(3) - (3)].str));
      node->addFirstChild((yyvsp[(1) - (3)].ast));
      (yyvsp[(1) - (3)].ast)->addNextSibling(const_node);
      (yyval.ast) = node;
    ;}
    break;

  case 14:
#line 205 "parser.y"
    {
      printf("consts->const \n");
      AbstractAstNode* node = new AbstractAstNode(AstNodeType::EXPRESSION,"const_array");
      AbstractAstNode* const_node = new AbstractAstNode(AstNodeType::CONST_INT, (yyvsp[(1) - (1)].str));
      node->addFirstChild(const_node);
      (yyval.ast) = node;

    ;}
    break;

  case 15:
#line 217 "parser.y"
    {
        printf("descriptor->int \n");
        AbstractAstNode* node = new AbstractAstNode(AstNodeType::MODIFY,"INT_TYPE");
        // AbstractAstNode* int_node=new AbstractAstNode(AstNodeType::TYPE,$1);
        // node->addFirstChild(int_node);
        (yyval.ast) = node;
    ;}
    break;

  case 16:
#line 224 "parser.y"
    {
        printf("descriptor->void \n");
        AbstractAstNode* node = new AbstractAstNode(AstNodeType::MODIFY,"VOID_TYPE");
        // AbstractAstNode* void_node = new AbstractAstNode(AstNodeType::TYPE,$1);
        // node->addFirstChild(void_node);
        (yyval.ast) = node;
    ;}
    break;

  case 17:
#line 231 "parser.y"
    {//int*
        printf("descriptor->int mul \n");
        AbstractAstNode* node = new AbstractAstNode(AstNodeType::MODIFY,"INT*_TYPE");
        // AbstractAstNode* int_node = new AbstractAstNode(AstNodeType::TYPE,$1);
        // node->addFirstChild(int_node);
        (yyval.ast) = node;
    ;}
    break;

  case 18:
#line 242 "parser.y"
    {
      printf("func->identfier() \n");
        AbstractAstNode* node = new AbstractAstNode(AstNodeType::DEFINITION,"Func_NParam");
        AbstractAstNode* id_node = new AbstractAstNode(AstNodeType::ID, (yyvsp[(1) - (3)].str));
        node->addFirstChild(id_node);
        (yyval.ast) = node;
    ;}
    break;

  case 19:
#line 250 "parser.y"
    {
      printf("func->identifier(varlist) \n");
        AbstractAstNode* node = new AbstractAstNode(AstNodeType::DEFINITION,"Func_Params");
        AbstractAstNode* id_node = new AbstractAstNode(AstNodeType::ID, (yyvsp[(1) - (4)].str));
        //node->addFirstChild(id_node);
        /////////////////?
        //$1->addNextSibling($3);
        //id_node->addNextSibling($3);
        (yyval.ast) = node;
    ;}
    break;

  case 20:
#line 264 "parser.y"
    {
      printf("varlist->varlist,param \n");
        AbstractAstNode* node = new AbstractAstNode(AstNodeType::DEFINITION,"Some_Param");
        node->addFirstChild((yyvsp[(1) - (3)].ast));
        (yyvsp[(1) - (3)].ast)->addNextSibling((yyvsp[(3) - (3)].ast));
        (yyval.ast) = node;
    ;}
    break;

  case 21:
#line 272 "parser.y"
    {
    printf("varlist->param \n");
        AbstractAstNode* node = new AbstractAstNode(AstNodeType::DEFINITION,"Single_Param");
        node->addFirstChild((yyvsp[(1) - (1)].ast));
        (yyval.ast) = node;
    ;}
    break;

  case 22:
#line 280 "parser.y"
    {
      printf("param->descriptor identifier \n");
        AbstractAstNode* node = new AbstractAstNode(AstNodeType::DEFINITION,"Param_ID");
        AbstractAstNode* id_node = new AbstractAstNode(AstNodeType::ID, (yyvsp[(2) - (2)].str));
        node->addFirstChild((yyvsp[(1) - (2)].ast));
        (yyvsp[(1) - (2)].ast)->addNextSibling(id_node);
        (yyval.ast) = node;
    ;}
    break;

  case 23:
#line 288 "parser.y"
    {
      printf("param->descriptor identifier[] \n");
        AbstractAstNode* node = new AbstractAstNode(AstNodeType::DEFINITION,"Param_ID[]");
        AbstractAstNode* id_node = new AbstractAstNode(AstNodeType::ID, (yyvsp[(2) - (4)].str));
        node->addFirstChild((yyvsp[(1) - (4)].ast));
        (yyvsp[(1) - (4)].ast)->addNextSibling(id_node);
        (yyval.ast) = node;
    ;}
    break;

  case 24:
#line 296 "parser.y"
    {
      printf("param->descriptor identifier[const] \n");
        AbstractAstNode* node = new AbstractAstNode(AstNodeType::DEFINITION,"Param_ID[const]");
        AbstractAstNode* id_node = new AbstractAstNode(AstNodeType::ID, (yyvsp[(2) - (5)].str));
        AbstractAstNode* const_node = new AbstractAstNode(AstNodeType::CONST_INT, (yyvsp[(4) - (5)].str));
        node->addFirstChild((yyvsp[(1) - (5)].ast));
        (yyvsp[(1) - (5)].ast)->addNextSibling(id_node);
        id_node->addNextSibling(const_node);
        (yyval.ast) = node;
    ;}
    break;

  case 25:
#line 306 "parser.y"
    {
    printf("param->&identifier \n");
        AbstractAstNode* node = new AbstractAstNode(AstNodeType::ARRAY,"array_&id");
        AbstractAstNode* var_node = new AbstractAstNode(AstNodeType::ID, (yyvsp[(3) - (3)].str));
        node->addFirstChild((yyvsp[(1) - (3)].ast));
        (yyvsp[(1) - (3)].ast)->addNextSibling(var_node);
        (yyval.ast) = node;
    ;}
    break;

  case 26:
#line 314 "parser.y"
    {
    printf("param->*identifier \n");
        AbstractAstNode* node = new AbstractAstNode(AstNodeType::ARRAY,"array_*id");
        AbstractAstNode* var_node = new AbstractAstNode(AstNodeType::ID, (yyvsp[(3) - (3)].str));
        node->addFirstChild((yyvsp[(1) - (3)].ast));
        (yyvsp[(1) - (3)].ast)->addNextSibling(var_node);
        (yyval.ast) = node;
  ;}
    break;

  case 27:
#line 322 "parser.y"
    {
    printf("param->descriptor \n");
        AbstractAstNode* node = new AbstractAstNode(AstNodeType::DEFINITION,"Param_NID");
        node->addFirstChild((yyvsp[(1) - (1)].ast));
        (yyval.ast) = node;
    ;}
    break;

  case 28:
#line 331 "parser.y"
    {
      printf("body->{stmtlist} \n");
        AbstractAstNode* node = new AbstractAstNode(AstNodeType::BODY,"Body");
        node->addFirstChild((yyvsp[(2) - (3)].ast));
        (yyval.ast) = node;
    ;}
    break;

  case 29:
#line 341 "parser.y"
    {
    printf("stmtlist->stmtlist stmt \n");
	    AbstractAstNode* node = new AbstractAstNode(AstNodeType::STATEMENT,"Some_Stmt");
	    if ((yyvsp[(1) - (2)].ast) == NULL) {
	        node->addFirstChild((yyvsp[(2) - (2)].ast));
	    } else {
	        node->addFirstChild((yyvsp[(1) - (2)].ast));
            (yyvsp[(1) - (2)].ast)->addNextSibling((yyvsp[(2) - (2)].ast));
        }
        (yyval.ast) = node;
	;}
    break;

  case 30:
#line 353 "parser.y"
    {
      (yyval.ast) = NULL;
    ;}
    break;

  case 31:
#line 360 "parser.y"
    {
      printf("stmt->exp; \n");
        AbstractAstNode* node = new AbstractAstNode(AstNodeType::STATEMENT,"Exp_Stmt");
        node->addFirstChild((yyvsp[(1) - (2)].ast));
        (yyval.ast) = node;
    ;}
    break;

  case 32:
#line 367 "parser.y"
    {
    printf("stmt->def; \n");
        AbstractAstNode* node = new AbstractAstNode(AstNodeType::STATEMENT,"Def_Stmt");
        node->addFirstChild((yyvsp[(1) - (2)].ast));
        (yyval.ast) = node;

    ;}
    break;

  case 33:
#line 375 "parser.y"
    {
    printf("stmt->body \n");
        AbstractAstNode* node = new AbstractAstNode(AstNodeType::STATEMENT,"Body_Stmt");
        node->addFirstChild((yyvsp[(1) - (1)].ast));
        (yyval.ast) = node;
    ;}
    break;

  case 34:
#line 381 "parser.y"
    {
    printf("stmt->return exp ; \n");
        AbstractAstNode* node = new AbstractAstNode(AstNodeType::STATEMENT,"Return_Exp");
        // AbstractAstNode* return_node = new AbstractAstNode(AstNodeType::RETURN,$1);
        // node->addFirstChild(return_node);
        // $1->addNextSibling($2);
        node->addFirstChild((yyvsp[(2) - (3)].ast));
        (yyval.ast) = node;
    ;}
    break;

  case 35:
#line 390 "parser.y"
    {
    printf("stmt->return ; \n");
        AbstractAstNode* node = new AbstractAstNode(AstNodeType::STATEMENT,"Return_Void");
        // AbstractAstNode* return_node = new AbstractAstNode(AstNodeType::RETURN,$1);
        // node->addFirstChild(return_node);
        (yyval.ast) = node;
    ;}
    break;

  case 36:
#line 397 "parser.y"
    {
    printf("stmt->if(exp)stmt \n");
        AbstractAstNode* node = new AbstractAstNode(AstNodeType::STATEMENT,"If");
        // AbstractAstNode* if_node = new AbstractAstNode(AstNodeType::SELECT,$1);
        // node->addFirstChild(if_node);
        // $1->addNextSibling($3);
        node->addFirstChild((yyvsp[(3) - (5)].ast));
        (yyvsp[(3) - (5)].ast)->addNextSibling((yyvsp[(5) - (5)].ast));
        (yyval.ast) = node;
    ;}
    break;

  case 37:
#line 407 "parser.y"
    {
    printf("stmt->if(exp)stmt else stmt \n");
        AbstractAstNode* node = new AbstractAstNode(AstNodeType::STATEMENT,"If_Else");
        // AbstractAstNode* if_node = new AbstractAstNode(AstNodeType::SELECT,$1);
        // AbstractAstNode* else_node = new AbstractAstNode(AstNodeType::SELECT,$6);
        // node->addFirstChild(if_node);
        node->addFirstChild((yyvsp[(3) - (7)].ast));
        (yyvsp[(3) - (7)].ast)->addNextSibling((yyvsp[(5) - (7)].ast));
        (yyvsp[(5) - (7)].ast)->addNextSibling((yyvsp[(7) - (7)].ast));
        (yyval.ast) = node;
    ;}
    break;

  case 38:
#line 418 "parser.y"
    {
    printf("stmt->while ( exp) stmt \n");
        AbstractAstNode* node = new AbstractAstNode(AstNodeType::STATEMENT,"While");
        // AbstractAstNode* while_node = new AbstractAstNode(AstNodeType::LOOP,$1);
        // node->addFirstChild(while_node);
        node->addFirstChild((yyvsp[(3) - (5)].ast));
        (yyvsp[(3) - (5)].ast)->addNextSibling((yyvsp[(5) - (5)].ast));
        (yyval.ast) = node;
    ;}
    break;

  case 39:
#line 427 "parser.y"
    {
    printf("stmt->for ( ;; \n");
        AbstractAstNode* node = new AbstractAstNode(AstNodeType::STATEMENT,"For_SEMI_SEMI");
        // AbstractAstNode* for_node = new AbstractAstNode(AstNodeType::LOOP,$1);
        // node->addFirstChild(for_node);
        node->addFirstChild((yyvsp[(6) - (6)].ast));
        (yyval.ast) = node;
    ;}
    break;

  case 40:
#line 435 "parser.y"
    {
    printf("stmt->for(fordef;;)stmt \n");
        AbstractAstNode* node = new AbstractAstNode(AstNodeType::STATEMENT,"For_Def_SEMI_SEMI");
        // AbstractAstNode* for_node = new AbstractAstNode(AstNodeType::LOOP,$1);
        // node->addFirstChild(for_node);
        node->addFirstChild((yyvsp[(3) - (7)].ast));
        (yyvsp[(3) - (7)].ast)->addNextSibling((yyvsp[(7) - (7)].ast));
        (yyval.ast) = node;
    ;}
    break;

  case 41:
#line 444 "parser.y"
    {
        AbstractAstNode* node = new AbstractAstNode(AstNodeType::STATEMENT,"For_SEMI_Exp_SEMI");
        // AbstractAstNode* for_node = new AbstractAstNode(AstNodeType::LOOP,$1);
        // node->addFirstChild(for_node);
        node->addFirstChild((yyvsp[(4) - (7)].ast));
        (yyvsp[(4) - (7)].ast)->addNextSibling((yyvsp[(7) - (7)].ast));
        (yyval.ast) = node;
    ;}
    break;

  case 42:
#line 452 "parser.y"
    {
        AbstractAstNode* node = new AbstractAstNode(AstNodeType::STATEMENT,"For_SEMI_SEMI_Exp");
        // AbstractAstNode* for_node = new AbstractAstNode(AstNodeType::LOOP,$1);
        // node->addFirstChild(for_node);
        node->addFirstChild((yyvsp[(5) - (7)].ast));
        (yyvsp[(5) - (7)].ast)->addNextSibling((yyvsp[(7) - (7)].ast));
        (yyval.ast) = node;
    ;}
    break;

  case 43:
#line 460 "parser.y"
    {
        AbstractAstNode* node = new AbstractAstNode(AstNodeType::STATEMENT,"For_Def_SEMI_Exp_SEMI_Exp");
        // AbstractAstNode* for_node = new AbstractAstNode(AstNodeType::LOOP,$1);
        // node->addFirstChild(for_node);
        node->addFirstChild((yyvsp[(3) - (9)].ast));
        (yyvsp[(3) - (9)].ast)->addNextSibling((yyvsp[(5) - (9)].ast));
        (yyvsp[(5) - (9)].ast)->addNextSibling((yyvsp[(7) - (9)].ast));
        (yyvsp[(7) - (9)].ast)->addNextSibling((yyvsp[(9) - (9)].ast));
        (yyval.ast) = node;
    ;}
    break;

  case 44:
#line 470 "parser.y"
    {
        AbstractAstNode* node = new AbstractAstNode(AstNodeType::STATEMENT,"For_Def_SEMI_Exp_SEMI");
        // AbstractAstNode* for_node = new AbstractAstNode(AstNodeType::LOOP,$1);
        // node->addFirstChild(for_node);
        node->addFirstChild((yyvsp[(3) - (8)].ast));
        (yyvsp[(3) - (8)].ast)->addNextSibling((yyvsp[(5) - (8)].ast));
        (yyvsp[(5) - (8)].ast)->addNextSibling((yyvsp[(8) - (8)].ast));
        (yyval.ast) = node;
    ;}
    break;

  case 45:
#line 479 "parser.y"
    {
        AbstractAstNode* node = new AbstractAstNode(AstNodeType::STATEMENT,"For_Def_SEMI_SEMI_Exp");
        // AbstractAstNode* for_node = new AbstractAstNode(AstNodeType::LOOP,$1);
        // node->addFirstChild(for_node);
        node->addFirstChild((yyvsp[(3) - (8)].ast));
        (yyvsp[(3) - (8)].ast)->addNextSibling((yyvsp[(6) - (8)].ast));
        (yyvsp[(6) - (8)].ast)->addNextSibling((yyvsp[(8) - (8)].ast));
        (yyval.ast) = node;
    ;}
    break;

  case 46:
#line 488 "parser.y"
    {
        AbstractAstNode* node = new AbstractAstNode(AstNodeType::STATEMENT,"For_SEMI_Exp_SEMI_Exp");
        // AbstractAstNode* for_node = new AbstractAstNode(AstNodeType::LOOP,$1);
        // node->addFirstChild(for_node);
        node->addFirstChild((yyvsp[(4) - (8)].ast));
        (yyvsp[(4) - (8)].ast)->addNextSibling((yyvsp[(6) - (8)].ast));
        (yyvsp[(6) - (8)].ast)->addNextSibling((yyvsp[(8) - (8)].ast));
        (yyval.ast) = node;
    ;}
    break;

  case 47:
#line 497 "parser.y"
    {
        AbstractAstNode* node = new AbstractAstNode(AstNodeType::STATEMENT,"Break_Stmt"); 
        (yyval.ast) = node;
    ;}
    break;

  case 48:
#line 501 "parser.y"
    {
        AbstractAstNode* node = new AbstractAstNode(AstNodeType::STATEMENT,"Continue_Stmt"); 
        (yyval.ast) = node;
    ;}
    break;

  case 49:
#line 505 "parser.y"
    {
        AbstractAstNode* node = new AbstractAstNode(AstNodeType::STATEMENT,"Print_String");
        node->addFirstChild((yyvsp[(4) - (7)].ast));
        (yyval.ast) = node;

    ;}
    break;

  case 50:
#line 511 "parser.y"
    {
        AbstractAstNode* node = new AbstractAstNode(AstNodeType::STATEMENT,"Print_Exp");
        node->addFirstChild((yyvsp[(3) - (5)].ast));
        (yyval.ast) = node;
    ;}
    break;

  case 51:
#line 516 "parser.y"
    {
      AbstractAstNode* node = new AbstractAstNode(AstNodeType::STATEMENT,"scanf_id");
      AbstractAstNode* id_node = new AbstractAstNode(AstNodeType::ID, (yyvsp[(3) - (5)].str));
      node->addFirstChild(id_node);
      (yyval.ast) = node;

  ;}
    break;

  case 52:
#line 526 "parser.y"
    {//!!
      printf("def->descriptor deflist \n");
        AbstractAstNode* node = new AbstractAstNode(AstNodeType::DEFINITION,"Def_Var");
        node->addFirstChild((yyvsp[(1) - (2)].ast));
        (yyvsp[(1) - (2)].ast)->addNextSibling((yyvsp[(2) - (2)].ast));
        (yyval.ast)=node;
    ;}
    break;

  case 53:
#line 537 "parser.y"
    {//ok
    printf("deflist->var \n");
        AbstractAstNode* node = new AbstractAstNode(AstNodeType::DEFINITION,"Def_Single_Var");
        node->addFirstChild((yyvsp[(1) - (1)].ast));
        (yyval.ast) = node;
    ;}
    break;

  case 54:
#line 544 "parser.y"
    {//ok
    printf("deflist->var ,deflist \n");
        AbstractAstNode* node = new AbstractAstNode(AstNodeType::DEFINITION,"Def_Some_Var");
        node->addFirstChild((yyvsp[(1) - (3)].ast));
        (yyvsp[(1) - (3)].ast)->addNextSibling((yyvsp[(3) - (3)].ast));
        (yyval.ast) = node;
    ;}
    break;

  case 55:
#line 555 "parser.y"
    {//ok
      printf("var->vardef \n");
        AbstractAstNode* node = new AbstractAstNode(AstNodeType::DEFINITION,"Var_ONLY");
        node->addFirstChild((yyvsp[(1) - (1)].ast));
        (yyval.ast)=node;
    ;}
    break;

  case 56:
#line 562 "parser.y"
    {//ok a,b=c
    printf("var->vardef = exp \n");
        AbstractAstNode* node = new AbstractAstNode(AstNodeType::DEFINITION,"Var_ASSIGN");
        node->addFirstChild((yyvsp[(1) - (3)].ast));
        (yyvsp[(1) - (3)].ast)->addNextSibling((yyvsp[(3) - (3)].ast));
        (yyval.ast)=node;
    ;}
    break;

  case 57:
#line 573 "parser.y"
    {
      printf("fordef->def \n");
        AbstractAstNode* node = new AbstractAstNode(AstNodeType::DEFINITION,"For_Def");
        node->addFirstChild((yyvsp[(1) - (1)].ast));
        (yyval.ast)=node;
    ;}
    break;

  case 58:
#line 579 "parser.y"
    {//a=1 ok
    printf("fordef->exp \n");
        AbstractAstNode* node = new AbstractAstNode(AstNodeType::DEFINITION,"For_Exp");
        node->addFirstChild((yyvsp[(1) - (1)].ast));
        (yyval.ast)=node;
    ;}
    break;

  case 59:
#line 588 "parser.y"
    {
        // printf("exp->const \n");
        AbstractAstNode* node = new AbstractAstNode(AstNodeType::EXPRESSION,"Const_Exp");
        AbstractAstNode* const_node = new AbstractAstNode(AstNodeType::CONST_INT, (yyvsp[(1) - (1)].str));
        node->addFirstChild(const_node);
        (yyval.ast) = node;
    ;}
    break;

  case 60:
#line 602 "parser.y"
    {
        AbstractAstNode* node = new AbstractAstNode(AstNodeType::EXPRESSION,"ID_Exp");
        node->addFirstChild((yyvsp[(1) - (1)].ast));
        (yyval.ast) = node;
    ;}
    break;

  case 61:
#line 607 "parser.y"
    {
        AbstractAstNode* node = new AbstractAstNode(AstNodeType::OPERATION, "Assign");
        node->addFirstChild((yyvsp[(1) - (3)].ast));
        (yyvsp[(1) - (3)].ast)->addNextSibling((yyvsp[(3) - (3)].ast));
        (yyval.ast) = node;
  ;}
    break;

  case 62:
#line 613 "parser.y"
    {
        AbstractAstNode* node = new AbstractAstNode(AstNodeType::OPERATION, "Addition");
        node->addFirstChild((yyvsp[(1) - (3)].ast));
        (yyvsp[(1) - (3)].ast)->addNextSibling((yyvsp[(3) - (3)].ast));
        (yyval.ast) = node;
  ;}
    break;

  case 63:
#line 619 "parser.y"
    {
        AbstractAstNode* node = new AbstractAstNode(AstNodeType::OPERATION, "Substraction");
        node->addFirstChild((yyvsp[(1) - (3)].ast));
        (yyvsp[(1) - (3)].ast)->addNextSibling((yyvsp[(3) - (3)].ast));
        (yyval.ast) = node;
    ;}
    break;

  case 64:
#line 625 "parser.y"
    {
        AbstractAstNode* node = new AbstractAstNode(AstNodeType::OPERATION, "Multiply");
        node->addFirstChild((yyvsp[(1) - (3)].ast));
        (yyvsp[(1) - (3)].ast)->addNextSibling((yyvsp[(3) - (3)].ast));
        (yyval.ast) = node;
  ;}
    break;

  case 65:
#line 631 "parser.y"
    {
        AbstractAstNode* node = new AbstractAstNode(AstNodeType::OPERATION, "Divide");
        node->addFirstChild((yyvsp[(1) - (3)].ast));
        (yyvsp[(1) - (3)].ast)->addNextSibling((yyvsp[(3) - (3)].ast));
        (yyval.ast) = node;
    ;}
    break;

  case 66:
#line 637 "parser.y"
    {
        AbstractAstNode* node = new AbstractAstNode(AstNodeType::OPERATION, "Mod");
        node->addFirstChild((yyvsp[(1) - (3)].ast));
        (yyvsp[(1) - (3)].ast)->addNextSibling((yyvsp[(3) - (3)].ast));
        (yyval.ast) = node;
    ;}
    break;

  case 67:
#line 643 "parser.y"
    {
        AbstractAstNode* node = new AbstractAstNode(AstNodeType::OPERATION, "Power");
        node->addFirstChild((yyvsp[(1) - (3)].ast));
        (yyvsp[(1) - (3)].ast)->addNextSibling((yyvsp[(3) - (3)].ast));
        (yyval.ast) = node;
    ;}
    break;

  case 68:
#line 649 "parser.y"
    {
        AbstractAstNode* node = new AbstractAstNode(AstNodeType::OPERATION, "Parentheses");
        node->addFirstChild((yyvsp[(2) - (3)].ast));
        (yyval.ast) = node;
    ;}
    break;

  case 69:
#line 655 "parser.y"
    {
        AbstractAstNode* node = new AbstractAstNode(AstNodeType::OPERATION, "Negative");
        node->addFirstChild((yyvsp[(2) - (2)].ast));
        (yyval.ast)=node;
    ;}
    break;

  case 70:
#line 661 "parser.y"
    {
        AbstractAstNode* node = new AbstractAstNode(AstNodeType::OPERATION, "AND");
        node->addFirstChild((yyvsp[(1) - (3)].ast));
        (yyvsp[(1) - (3)].ast)->addNextSibling((yyvsp[(3) - (3)].ast));
        (yyval.ast)=node;
    ;}
    break;

  case 71:
#line 668 "parser.y"
    {
        AbstractAstNode* node = new AbstractAstNode(AstNodeType::OPERATION, "OR");
        node->addFirstChild((yyvsp[(1) - (3)].ast));
        (yyvsp[(1) - (3)].ast)->addNextSibling((yyvsp[(3) - (3)].ast));
        (yyval.ast)=node;
    ;}
    break;

  case 72:
#line 675 "parser.y"
    {
        AbstractAstNode* node = new AbstractAstNode(AstNodeType::OPERATION, "NOT");
        node->addFirstChild((yyvsp[(2) - (2)].ast));
        (yyval.ast)=node;
    ;}
    break;

  case 73:
#line 680 "parser.y"
    {//{1,2,3}
    printf("expr->{consts}\n");
    AbstractAstNode* node = new AbstractAstNode(AstNodeType::ARRAY,"{consts}");
    node->addFirstChild((yyvsp[(2) - (3)].ast));
    (yyval.ast)=node;
    ;}
    break;

  case 74:
#line 686 "parser.y"
    {
        AbstractAstNode* node = new AbstractAstNode(AstNodeType::OPERATION, "EQ_OP");
        node->addFirstChild((yyvsp[(1) - (3)].ast));
        (yyvsp[(1) - (3)].ast)->addNextSibling((yyvsp[(3) - (3)].ast));
        (yyval.ast)=node;
    ;}
    break;

  case 75:
#line 692 "parser.y"
    {
        AbstractAstNode* node = new AbstractAstNode(AstNodeType::OPERATION, "NE_OP");
        node->addFirstChild((yyvsp[(1) - (3)].ast));
        (yyvsp[(1) - (3)].ast)->addNextSibling((yyvsp[(3) - (3)].ast));
        (yyval.ast)=node;
    ;}
    break;

  case 76:
#line 698 "parser.y"
    {
        AbstractAstNode* node = new AbstractAstNode(AstNodeType::OPERATION, "GT_OP");
        node->addFirstChild((yyvsp[(1) - (3)].ast));
        (yyvsp[(1) - (3)].ast)->addNextSibling((yyvsp[(3) - (3)].ast));
        (yyval.ast)=node;
    ;}
    break;

  case 77:
#line 704 "parser.y"
    {
        AbstractAstNode* node = new AbstractAstNode(AstNodeType::OPERATION, "LT_OP");
        node->addFirstChild((yyvsp[(1) - (3)].ast));
        (yyvsp[(1) - (3)].ast)->addNextSibling((yyvsp[(3) - (3)].ast));
        (yyval.ast)=node;
    ;}
    break;

  case 78:
#line 710 "parser.y"
    {
        AbstractAstNode* node = new AbstractAstNode(AstNodeType::OPERATION, "GE_OP");
        node->addFirstChild((yyvsp[(1) - (3)].ast));
        (yyvsp[(1) - (3)].ast)->addNextSibling((yyvsp[(3) - (3)].ast));
        (yyval.ast)=node;
    ;}
    break;

  case 79:
#line 716 "parser.y"
    {
        AbstractAstNode* node = new AbstractAstNode(AstNodeType::OPERATION, "LE_OP");
        node->addFirstChild((yyvsp[(1) - (3)].ast));
        (yyvsp[(1) - (3)].ast)->addNextSibling((yyvsp[(3) - (3)].ast));
        (yyval.ast)=node;
    ;}
    break;

  case 80:
#line 723 "parser.y"
    {
    printf("exp->id '(' Args ')' \n");
        AbstractAstNode* node = new AbstractAstNode(AstNodeType::CALL, "Call_Args_Func");
        AbstractAstNode* id_node = new AbstractAstNode(AstNodeType::ID, (yyvsp[(1) - (4)].str));
        node->addFirstChild(id_node);
        id_node->addNextSibling((yyvsp[(3) - (4)].ast));
        (yyval.ast) = node;
    ;}
    break;

  case 81:
#line 731 "parser.y"
    {
    printf("exp->id '('  ')' \n");
        AbstractAstNode* node = new AbstractAstNode(AstNodeType::CALL, "Call_NArgs_Func");
        AbstractAstNode* id_node = new AbstractAstNode(AstNodeType::ID, (yyvsp[(1) - (3)].str));
        node->addFirstChild(id_node);
        (yyval.ast) = node;
    ;}
    break;

  case 82:
#line 738 "parser.y"
    {//*id
      AbstractAstNode* node = new AbstractAstNode(AstNodeType::OPERATION,"*id");
      AbstractAstNode* id_node = new AbstractAstNode(AstNodeType::ID, (yyvsp[(2) - (2)].str));
      node->addFirstChild(id_node);
      (yyval.ast) = node;
  ;}
    break;

  case 83:
#line 744 "parser.y"
    {//like a[2+3]
      AbstractAstNode* node = new AbstractAstNode(AstNodeType::OPERATION,"id[exp]");
      AbstractAstNode* id_node = new AbstractAstNode(AstNodeType::ID, (yyvsp[(1) - (4)].str));
      node->addFirstChild(id_node);
      id_node->addNextSibling((yyvsp[(3) - (4)].ast));
      (yyval.ast)=node;
    ;}
    break;

  case 84:
#line 751 "parser.y"
    {
        AbstractAstNode* node = new AbstractAstNode(AstNodeType::OPERATION,"&id");
        AbstractAstNode* id_node = new AbstractAstNode(AstNodeType::ID, (yyvsp[(2) - (2)].str));
        node->addFirstChild(id_node);
        (yyval.ast) = node;
    ;}
    break;

  case 85:
#line 759 "parser.y"
    {
        AbstractAstNode* node = new AbstractAstNode(AstNodeType::ID,"Func_Single_Arg");
        node->addFirstChild((yyvsp[(1) - (1)].ast));
        (yyval.ast) = node;
    ;}
    break;

  case 86:
#line 764 "parser.y"
    {
        AbstractAstNode* node = new AbstractAstNode(AstNodeType::DEFINITION,"Func_Some_Args");
        node->addFirstChild((yyvsp[(1) - (3)].ast));
        (yyvsp[(1) - (3)].ast)->addNextSibling((yyvsp[(3) - (3)].ast));
        (yyval.ast) = node;
    ;}
    break;

  case 87:
#line 772 "parser.y"
    {
        AbstractAstNode* node = new AbstractAstNode(AstNodeType::DEFINITION,"Single_ID");
        AbstractAstNode* id_node = new AbstractAstNode(AstNodeType::ID,(yyvsp[(1) - (1)].str));
        node->addFirstChild(id_node);
        (yyval.ast) = node;

    ;}
    break;

  case 88:
#line 779 "parser.y"
    {
        AbstractAstNode* node = new AbstractAstNode(AstNodeType::DEFINITION,"Single_ID");
        AbstractAstNode* id_node = new AbstractAstNode(AstNodeType::ID,(yyvsp[(2) - (2)].str));
        node->addFirstChild((yyvsp[(1) - (2)].ast));
        (yyvsp[(1) - (2)].ast)->addNextSibling(id_node);
        (yyval.ast) = node;

    ;}
    break;


/* Line 1267 of yacc.c.  */
#line 2641 "parser.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


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
		      yytoken, &yylval);
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


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


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
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
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


#line 789 "parser.y"

int  main(int argc, char** argv)
{
  if ( argc > 1 ) {
    if (! (yyin = fopen(argv[1], "r" ) )){
      perror(argv[1]);
      return 1;
    }
    printf("[i]>>>Read data from file:%s \n",argv[1]);
  }else{
    printf("[I]>>>Read data from stdin.\n");
  }
  do {
		yyparse();
	} while(!feof(yyin));
  InterCode interCode = InterCode(root);
  interCode.Root_Generate();
  return 0;

}

void yyerror(char *s)
{
  // fprintf(stderr, "error: %s\n", s);
}
