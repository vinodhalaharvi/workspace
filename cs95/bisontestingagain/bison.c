/* A Bison parser, made by GNU Bison 2.5.  */

/* Bison implementation for Yacc-like parsers in C
   
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
#define YYBISON_VERSION "2.5"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 268 of yacc.c  */
#line 1 "test.y"

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "node.h"

int yylex();
extern int yylineno;
void yyerror(char *s);
#define YYSTYPE struct node *
#define YYERROR_VERBOSE
void print_node(struct node * node);
void print_tree(struct node * node);
extern struct node *root_node;



/* Line 268 of yacc.c  */
#line 90 "bison.c"

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


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     IDENTIFIER = 258,
     STRING = 259,
     BREAK = 260,
     CHAR = 261,
     CONTINUE = 262,
     DO = 263,
     ELSE = 264,
     FOR = 265,
     GOTO = 266,
     IF = 267,
     INT = 268,
     LONG = 269,
     RETURN = 270,
     SHORT = 271,
     SIGNED = 272,
     UNSIGNED = 273,
     VOID = 274,
     WHILE = 275,
     LEFT_PAREN = 276,
     RIGHT_PAREN = 277,
     LEFT_SQUARE = 278,
     RIGHT_SQUARE = 279,
     LEFT_CURLY = 280,
     RIGHT_CURLY = 281,
     AMPERSAND = 282,
     ASTERISK = 283,
     CARET = 284,
     COLON = 285,
     COMMA = 286,
     EQUAL = 287,
     EXCLAMATION = 288,
     GREATER = 289,
     LESS = 290,
     MINUS = 291,
     PERCENT = 292,
     PLUS = 293,
     SEMICOLON = 294,
     SLASH = 295,
     QUESTION = 296,
     TILDE = 297,
     VBAR = 298,
     AMPERSAND_AMPERSAND = 299,
     AMPERSAND_EQUAL = 300,
     ASTERISK_EQUAL = 301,
     CARET_EQUAL = 302,
     EQUAL_EQUAL = 303,
     EXCLAMATION_EQUAL = 304,
     GREATER_EQUAL = 305,
     GREATER_GREATER = 306,
     GREATER_GREATER_EQUAL = 307,
     LESS_EQUAL = 308,
     LESS_LESS = 309,
     LESS_LESS_EQUAL = 310,
     MINUS_EQUAL = 311,
     MINUS_MINUS = 312,
     PERCENT_EQUAL = 313,
     PLUS_EQUAL = 314,
     PLUS_PLUS = 315,
     SLASH_EQUAL = 316,
     VBAR_EQUAL = 317,
     VBAR_VBAR = 318,
     NUMBER = 319
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 343 of yacc.c  */
#line 196 "bison.c"

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
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
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
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
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
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
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
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  46
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   383

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  65
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  99
/* YYNRULES -- Number of rules.  */
#define YYNRULES  198
/* YYNRULES -- Number of states.  */
#define YYNSTATES  281

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   319

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
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     8,    10,    14,    16,    18,    21,
      26,    28,    32,    34,    36,    38,    40,    42,    44,    46,
      48,    50,    52,    54,    56,    60,    63,    65,    69,    71,
      75,    78,    80,    85,    87,    90,    93,    95,    99,   103,
     105,   111,   113,   115,   118,   122,   124,   126,   128,   131,
     133,   135,   137,   141,   146,   148,   152,   154,   156,   164,
     166,   170,   172,   174,   176,   178,   182,   185,   193,   197,
     202,   207,   210,   213,   217,   225,   231,   234,   236,   238,
     240,   244,   246,   248,   250,   252,   254,   256,   258,   262,
     264,   268,   271,   273,   277,   279,   283,   285,   287,   289,
     291,   293,   296,   299,   300,   301,   303,   304,   306,   307,
     309,   310,   312,   313,   315,   316,   318,   319,   321,   322,
     324,   325,   326,   328,   330,   334,   336,   340,   342,   345,
     348,   351,   353,   355,   357,   359,   361,   364,   367,   370,
     372,   374,   376,   378,   382,   384,   386,   388,   390,   394,
     396,   400,   402,   404,   406,   409,   412,   416,   418,   421,
     423,   425,   428,   431,   435,   437,   439,   441,   443,   445,
     447,   449,   451,   453,   455,   457,   462,   464,   466,   468,
     471,   474,   476,   478,   480,   482,   484,   486,   488,   490,
     492,   494,   496,   499,   502,   506,   509,   513,   515
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     155,     0,    -1,   137,    -1,   133,    90,    -1,   118,    -1,
      67,    68,   118,    -1,    38,    -1,    36,    -1,    27,    78,
      -1,    91,    23,   125,    24,    -1,    82,    -1,   158,    72,
      71,    -1,    32,    -1,    59,    -1,    56,    -1,    46,    -1,
      61,    -1,    58,    -1,    53,    -1,    50,    -1,    45,    -1,
      47,    -1,    62,    -1,    93,    -1,    73,    27,    93,    -1,
      42,    78,    -1,    76,    -1,    75,    43,    76,    -1,    73,
      -1,    76,    29,    73,    -1,     5,    39,    -1,   158,    -1,
      21,   156,    22,    78,    -1,     6,    -1,    17,     6,    -1,
      18,     6,    -1,    71,    -1,    80,    31,    71,    -1,    25,
     126,    26,    -1,   117,    -1,   117,    41,    95,    30,    82,
      -1,   106,    -1,   105,    -1,     7,    39,    -1,    88,   110,
      39,    -1,    85,    -1,   152,    -1,    86,    -1,    87,    86,
      -1,   157,    -1,   138,    -1,    91,    -1,    21,    66,    22,
      -1,   128,    23,   125,    24,    -1,   151,    -1,    21,    89,
      22,    -1,   101,    -1,    70,    -1,     8,   152,    20,    21,
      95,    22,    39,    -1,   145,    -1,    93,    94,   145,    -1,
      48,    -1,    49,    -1,    80,    -1,    71,    -1,    96,    31,
      71,    -1,    95,    39,    -1,    21,   131,    39,   129,    39,
     129,    22,    -1,    10,    98,   152,    -1,   140,    21,   130,
      22,    -1,    91,    21,   135,    22,    -1,   103,    81,    -1,
     127,    89,    -1,    11,   120,    39,    -1,    12,    21,    95,
      22,   152,     9,   152,    -1,    12,    21,    95,    22,   152,
      -1,    28,    78,    -1,    95,    -1,    89,    -1,   109,    -1,
     110,    31,   109,    -1,   150,    -1,   161,    -1,    79,    -1,
     163,    -1,    92,    -1,    99,    -1,   120,    -1,   113,    30,
     152,    -1,    75,    -1,   115,    44,    75,    -1,    33,    78,
      -1,   115,    -1,   117,    63,   115,    -1,    78,    -1,   118,
     119,    78,    -1,    28,    -1,    40,    -1,    37,    -1,     3,
      -1,    39,    -1,    88,    89,    -1,    88,   124,    -1,    -1,
      -1,    66,    -1,    -1,    82,    -1,    -1,    87,    -1,    -1,
      88,    -1,    -1,    90,    -1,    -1,    95,    -1,    -1,    96,
      -1,    -1,   108,    -1,    -1,    -1,   137,    -1,   122,    -1,
     134,    31,   122,    -1,   134,    -1,    21,    95,    22,    -1,
      28,    -1,    28,   137,    -1,   137,    91,    -1,   140,    57,
      -1,   144,    -1,   153,    -1,   100,    -1,   141,    -1,   139,
      -1,   140,    60,    -1,    57,   158,    -1,    60,   158,    -1,
       3,    -1,   123,    -1,   136,    -1,   148,    -1,   145,   146,
     148,    -1,    35,    -1,    53,    -1,    34,    -1,    50,    -1,
      15,   129,    39,    -1,    67,    -1,   148,   149,    67,    -1,
      54,    -1,    51,    -1,    16,    -1,    16,    13,    -1,    17,
      16,    -1,    17,    16,    13,    -1,    13,    -1,    17,    13,
      -1,    17,    -1,    14,    -1,    14,    13,    -1,    17,    14,
      -1,    17,    14,    13,    -1,     3,    -1,    97,    -1,   114,
      -1,    81,    -1,    83,    -1,   112,    -1,    77,    -1,    84,
      -1,   147,    -1,   104,    -1,   121,    -1,   140,    23,    95,
      24,    -1,    85,    -1,   102,    -1,   154,    -1,   155,   154,
      -1,    88,   124,    -1,   111,    -1,   162,    -1,   140,    -1,
     159,    -1,   160,    -1,   116,    -1,    74,    -1,    69,    -1,
     107,    -1,   143,    -1,   142,    -1,    36,    78,    -1,    38,
      78,    -1,    18,    16,   132,    -1,    18,   132,    -1,    18,
      14,   132,    -1,    19,    -1,    20,    21,    95,    22,   152,
      -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    38,    38,    39,    43,    44,    48,    49,    53,    57,
      61,    62,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    80,    81,    85,    89,    90,    94,    95,
      99,   103,   104,   108,   109,   110,   114,   115,   119,   123,
     124,   128,   129,   143,   149,   154,   155,   159,   160,   164,
     168,   169,   174,   175,   180,   181,   182,   183,   187,   193,
     194,   198,   199,   203,   207,   208,   212,   216,   220,   224,
     228,   232,   236,   240,   244,   248,   253,   257,   261,   265,
     266,   271,   272,   273,   277,   278,   279,   283,   287,   291,
     292,   296,   300,   301,   305,   306,   308,   309,   310,   314,
     318,   322,   323,   328,   330,   331,   336,   337,   339,   340,
     342,   343,   345,   346,   348,   349,   351,   352,   354,   355,
     357,   362,   363,   373,   374,   378,   382,   386,   387,   391,
     395,   399,   400,   401,   402,   403,   407,   411,   415,   420,
     421,   422,   426,   427,   429,   430,   431,   432,   436,   440,
     441,   443,   444,   448,   449,   450,   451,   452,   453,   454,
     455,   456,   457,   458,   462,   466,   467,   468,   469,   470,
     471,   472,   473,   474,   475,   479,   483,   484,   488,   489,
     494,   497,   498,   501,   502,   503,   504,   505,   506,   507,
     508,   509,   513,   517,   521,   522,   523,   527,   531
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IDENTIFIER", "STRING", "BREAK", "CHAR",
  "CONTINUE", "DO", "ELSE", "FOR", "GOTO", "IF", "INT", "LONG", "RETURN",
  "SHORT", "SIGNED", "UNSIGNED", "VOID", "WHILE", "LEFT_PAREN",
  "RIGHT_PAREN", "LEFT_SQUARE", "RIGHT_SQUARE", "LEFT_CURLY",
  "RIGHT_CURLY", "AMPERSAND", "ASTERISK", "CARET", "COLON", "COMMA",
  "EQUAL", "EXCLAMATION", "GREATER", "LESS", "MINUS", "PERCENT", "PLUS",
  "SEMICOLON", "SLASH", "QUESTION", "TILDE", "VBAR", "AMPERSAND_AMPERSAND",
  "AMPERSAND_EQUAL", "ASTERISK_EQUAL", "CARET_EQUAL", "EQUAL_EQUAL",
  "EXCLAMATION_EQUAL", "GREATER_EQUAL", "GREATER_GREATER",
  "GREATER_GREATER_EQUAL", "LESS_EQUAL", "LESS_LESS", "LESS_LESS_EQUAL",
  "MINUS_EQUAL", "MINUS_MINUS", "PERCENT_EQUAL", "PLUS_EQUAL", "PLUS_PLUS",
  "SLASH_EQUAL", "VBAR_EQUAL", "VBAR_VBAR", "NUMBER", "$accept",
  "abstract_declarator", "additive_expr", "add_op", "address_expr",
  "array_declarator", "assignment_expr", "assignment_op",
  "bitwise_and_expr", "bitwise_negation_expr", "bitwise_or_expr",
  "bitwise_xor_expr", "break_statement", "cast_expr",
  "character_type_specifier", "comma_expr", "compound_statement",
  "conditional_expr", "conditional_statement", "continue_statement",
  "decl", "declaration_or_statement", "declaration_or_statement_list",
  "declaration_specifiers", "declarator", "direct_abstract_declarator",
  "direct_declarator", "do_statement", "equality_expr", "equality_op",
  "expr", "expression_list", "expression_statement", "for_expr",
  "for_statement", "function_call", "function_declarator",
  "function_definition", "function_def_specifier", "goto_statement",
  "if_else_statement", "if_statement", "indirection_expr",
  "initial_clause", "initialized_declarator",
  "initialized_declarator_list", "integer_type_specifier",
  "iterative_statement", "label", "labeled_statement", "logical_and_expr",
  "logical_negation_expr", "logical_or_expr", "multiplicative_expr",
  "mult_op", "named_label", "null_statement", "parameter_decl", "CONSTANT",
  "abstract_declarator_opt", "constant_expr_opt",
  "declaration_or_statement_list_opt", "declaration_specifiers_opt",
  "direct_abstract_declarator_opt", "expr_opt", "expression_list_opt",
  "initial_clause_opt", "int_t_opt", "pointer_opt", "parameter_list",
  "parameter_type_list", "parenthesized_expr", "pointer",
  "pointer_declarator", "postdecrement_expr", "postfix_expr",
  "postincrement_expr", "predecrement_expr", "preincrement_expr",
  "primary_expr", "relational_expr", "relational_op", "return_statement",
  "shift_expr", "shift_op", "signed_type_specifier", "simple_declarator",
  "statement", "subscript_expr", "top_level_decl", "translation_unit",
  "type_name", "type_specifier", "unary_expr", "unary_minus_expr",
  "unary_plus_expr", "unsigned_type_specifier", "void_type_specifier",
  "while_statement", 0
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
     315,   316,   317,   318,   319
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    65,    66,    66,    67,    67,    68,    68,    69,    70,
      71,    71,    72,    72,    72,    72,    72,    72,    72,    72,
      72,    72,    72,    73,    73,    74,    75,    75,    76,    76,
      77,    78,    78,    79,    79,    79,    80,    80,    81,    82,
      82,    83,    83,    84,    85,    86,    86,    87,    87,    88,
      89,    89,    90,    90,    91,    91,    91,    91,    92,    93,
      93,    94,    94,    95,    96,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     110,   111,   111,   111,   112,   112,   112,   113,   114,   115,
     115,   116,   117,   117,   118,   118,   119,   119,   119,   120,
     121,   122,   122,   123,   124,   124,   125,   125,   126,   126,
     127,   127,   128,   128,   129,   129,   130,   130,   131,   131,
     132,   133,   133,   134,   134,   135,   136,   137,   137,   138,
     139,   140,   140,   140,   140,   140,   141,   142,   143,   144,
     144,   144,   145,   145,   146,   146,   146,   146,   147,   148,
     148,   149,   149,   150,   150,   150,   150,   150,   150,   150,
     150,   150,   150,   150,   151,   152,   152,   152,   152,   152,
     152,   152,   152,   152,   152,   153,   154,   154,   155,   155,
     156,   157,   157,   158,   158,   158,   158,   158,   158,   158,
     158,   158,   159,   160,   161,   161,   161,   162,   163
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     3,     1,     1,     2,     4,
       1,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     2,     1,     3,     1,     3,
       2,     1,     4,     1,     2,     2,     1,     3,     3,     1,
       5,     1,     1,     2,     3,     1,     1,     1,     2,     1,
       1,     1,     3,     4,     1,     3,     1,     1,     7,     1,
       3,     1,     1,     1,     1,     3,     2,     7,     3,     4,
       4,     2,     2,     3,     7,     5,     2,     1,     1,     1,
       3,     1,     1,     1,     1,     1,     1,     1,     3,     1,
       3,     2,     1,     3,     1,     3,     1,     1,     1,     1,
       1,     2,     2,     0,     0,     1,     0,     1,     0,     1,
       0,     1,     0,     1,     0,     1,     0,     1,     0,     1,
       0,     0,     1,     1,     3,     1,     3,     1,     2,     2,
       2,     1,     1,     1,     1,     1,     2,     2,     2,     1,
       1,     1,     1,     3,     1,     1,     1,     1,     3,     1,
       3,     1,     1,     1,     2,     2,     3,     1,     2,     1,
       1,     2,     2,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     4,     1,     1,     1,     2,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     2,     3,     2,     3,     1,     5
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
     110,    33,   157,   160,   153,   159,   120,   197,    83,   176,
       0,   177,     0,   181,     0,    81,   178,   110,    49,    82,
     182,   161,   154,    34,   158,   162,   155,    35,   120,   120,
     195,   164,     0,   127,    57,    78,    51,    56,    79,     0,
       0,    50,    54,   103,    71,    72,     1,   179,   163,   156,
     196,   194,     0,   128,     0,   103,     0,    44,   129,   139,
       0,     0,   103,     0,     0,     0,   103,     0,   103,   103,
     103,   103,   103,   103,   100,   103,   103,   103,   149,   188,
      36,    28,   187,    89,    26,   170,    94,    63,   167,    10,
     168,   171,    45,    47,   103,     0,    85,    23,     0,   165,
      86,   133,   173,    42,    41,   189,   169,     0,   166,    92,
     186,    39,     4,    87,   174,   140,     0,   141,   135,   183,
     134,   191,   190,   131,    59,   172,   142,    46,   132,    31,
     184,   185,    84,    55,   104,   123,   125,     0,   139,   107,
       0,    31,    80,    30,    43,     0,   103,   103,    99,     0,
     103,   115,     0,   103,   121,     0,     0,     8,    76,    91,
     192,   193,    25,   103,   137,   138,     7,     6,   103,   103,
     103,   103,   103,    48,    61,    62,   103,    66,   103,   103,
     103,   103,    96,    98,    97,   103,    38,   103,   103,   130,
     136,   146,   144,   147,   145,   103,   152,   151,   103,    12,
      20,    15,    21,    19,    18,    14,    17,    13,    16,    22,
     103,   105,   101,   102,   112,     2,     0,    70,     9,     0,
      77,   119,     0,    68,    73,     0,   148,     0,   180,   122,
     126,   103,     5,    24,    27,    29,    37,    60,    88,    90,
       0,    93,    95,    64,   117,     0,     0,   143,   150,    11,
     121,     3,     0,   124,   103,   103,   103,   103,    32,   103,
     103,    69,   175,     0,   103,     0,     0,    75,   198,    40,
      65,    52,     0,     0,   103,   103,    53,    58,     0,    74,
      67
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,   211,    78,   168,    79,    34,    80,   210,    81,    82,
      83,    84,    85,    86,     8,    87,    88,    89,    90,    91,
       9,    93,    94,    10,    35,   251,    36,    96,    97,   176,
      98,   244,    99,   147,   100,   101,    37,    11,    12,   102,
     103,   104,   105,   221,    38,    39,    13,   106,   107,   108,
     109,   110,   111,   112,   185,   113,   114,   135,   115,   213,
     140,   116,    14,   252,   152,   245,   222,    30,   214,   136,
     137,   117,    40,    41,   118,   119,   120,   121,   122,   123,
     124,   195,   125,   126,   198,    15,    42,   127,   128,    16,
      17,   156,    18,   129,   130,   131,    19,    20,   132
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -207
static const yytype_int16 yypact[] =
{
     170,  -207,  -207,     6,    50,   196,    74,  -207,  -207,  -207,
      41,  -207,    57,  -207,    41,  -207,  -207,    94,  -207,  -207,
    -207,  -207,  -207,  -207,  -207,    62,    72,  -207,  -207,  -207,
    -207,  -207,    41,    67,  -207,  -207,   -17,  -207,  -207,   -18,
       7,  -207,  -207,   216,  -207,  -207,  -207,  -207,  -207,  -207,
    -207,  -207,    76,  -207,   170,   117,    41,  -207,   -17,    85,
      65,    90,    45,   110,   103,   116,   117,   119,   303,   117,
     117,   117,   117,   117,  -207,   117,   323,   323,    78,  -207,
    -207,   105,  -207,    98,   113,  -207,  -207,   115,  -207,  -207,
    -207,  -207,  -207,  -207,   272,    41,  -207,    70,   108,  -207,
    -207,  -207,  -207,  -207,  -207,  -207,  -207,   118,  -207,   121,
    -207,   -30,    39,  -207,  -207,  -207,   128,  -207,  -207,    -6,
    -207,  -207,  -207,  -207,    11,  -207,    23,  -207,  -207,   111,
    -207,  -207,  -207,  -207,    19,  -207,   129,   140,  -207,  -207,
     139,  -207,  -207,  -207,  -207,   146,   117,    45,  -207,   132,
     117,  -207,   136,   117,    75,   157,   159,  -207,  -207,  -207,
    -207,  -207,  -207,   117,  -207,  -207,  -207,  -207,   117,   117,
     117,   117,   117,  -207,  -207,  -207,   117,  -207,    45,   117,
     117,   117,  -207,  -207,  -207,   117,  -207,   117,   117,  -207,
    -207,  -207,  -207,  -207,  -207,   117,  -207,  -207,   117,  -207,
    -207,  -207,  -207,  -207,  -207,  -207,  -207,  -207,  -207,  -207,
     117,  -207,  -207,  -207,   147,    68,   170,  -207,  -207,   161,
    -207,  -207,   151,  -207,  -207,   169,  -207,   171,  -207,   172,
    -207,   117,    39,    70,   113,   105,  -207,    11,  -207,    98,
     162,   121,  -207,  -207,   167,   177,   179,    23,    78,  -207,
      67,   181,   182,  -207,   117,   117,    45,    45,  -207,   117,
     117,  -207,  -207,   185,   117,   186,   176,   207,  -207,  -207,
    -207,  -207,   201,   199,   117,    45,  -207,  -207,   217,  -207,
    -207
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -207,   -10,    47,  -207,  -207,  -207,  -167,  -207,    77,  -207,
      71,    81,  -207,   -34,  -207,  -207,   234,   -53,  -207,  -207,
     -35,   153,  -207,   -36,     2,  -207,   -37,  -207,    84,  -207,
     -54,  -207,  -207,  -207,  -207,  -207,  -207,  -207,  -207,  -207,
    -207,  -207,  -207,  -207,   200,  -207,  -207,  -207,  -207,  -207,
      79,  -207,  -207,    89,  -207,   195,  -207,    46,  -207,   107,
      -1,  -207,  -207,  -207,  -206,  -207,  -207,    99,  -207,  -207,
    -207,  -207,   -33,  -207,  -207,  -207,  -207,  -207,  -207,  -207,
      88,  -207,  -207,    73,  -207,  -207,  -207,   -61,  -207,   248,
    -207,  -207,  -207,   -46,  -207,  -207,  -207,  -207,  -207
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -123
static const yytype_int16 yytable[] =
{
      53,   145,   139,    58,    54,   236,    55,    95,    92,   141,
      31,   180,   151,    56,   155,   187,    45,   188,   134,    21,
     243,    57,    31,   141,   141,   141,   141,   141,    32,   141,
     164,   165,   154,   181,    52,   157,   158,   159,   160,   161,
      32,   162,  -121,   249,    31,   191,   192,    33,    59,   266,
      60,   189,    61,    62,   190,    63,    64,    65,    95,    92,
      66,   193,    32,    22,   194,    67,    68,   182,   278,    33,
      43,    31,    69,    70,   196,    48,   183,   197,    71,   184,
      27,    72,    43,    73,    74,    49,   223,    75,    28,    32,
      29,  -122,   220,   270,    46,    33,   225,  -104,   133,   227,
       1,   215,    76,    33,   143,    77,   148,     2,     3,   155,
       4,     5,     6,     7,   166,   -99,   167,   238,   174,   175,
     138,   229,   141,   141,   141,   141,   240,    50,    51,   144,
     141,   146,   169,   141,   246,   141,   212,   150,    68,   141,
     153,   170,   171,   199,    69,    70,   172,   177,   178,   141,
      71,   242,   141,    72,   186,    73,   200,   201,   202,    75,
     216,   203,   217,   218,   204,   179,   219,   205,   250,   206,
     207,   224,   208,   209,    76,   226,     1,    77,    58,   230,
     134,   231,   254,     2,     3,   141,     4,     5,     6,     7,
     255,   256,   259,   257,    -2,   267,   268,   258,   260,   261,
     265,   151,    23,   262,  -113,   264,   269,   271,   273,    24,
      25,   139,    26,   141,   279,   274,   275,   229,   141,    59,
     151,    60,     1,    61,    62,   276,    63,    64,    65,     2,
       3,    66,     4,     5,     6,     7,    67,    68,   277,   280,
     263,    43,  -108,    69,    70,   248,    44,   173,   235,    71,
     239,   234,    72,   233,    73,    74,   142,   232,    75,   149,
     241,   228,   253,   272,   237,    47,     0,     0,   247,     0,
       0,     0,     0,    76,     0,    59,    77,    60,     1,    61,
      62,     0,    63,    64,    65,     2,     3,    66,     4,     5,
       6,     7,    67,    68,     0,     0,     0,    43,  -109,    69,
      70,     0,     0,     0,     0,    71,   138,     0,    72,     1,
      73,    74,     0,     0,    75,     0,     2,     3,     0,     4,
       5,     6,     7,     0,    68,     0,   138,     0,     0,    76,
      69,    70,    77,     0,     0,     0,    71,     0,     0,    72,
       0,    73,     0,     0,   163,    75,     0,     0,     0,     0,
      69,    70,     0,     0,     0,     0,    71,     0,     0,    72,
      76,    73,     0,    77,     0,    75,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      76,     0,     0,    77
};

#define yypact_value_is_default(yystate) \
  ((yystate) == (-207))

#define yytable_value_is_error(yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
      33,    62,    55,    40,    21,   172,    23,    43,    43,    55,
       3,    41,    66,    31,    68,    21,    14,    23,    54,    13,
     187,    39,     3,    69,    70,    71,    72,    73,    21,    75,
      76,    77,    68,    63,    32,    69,    70,    71,    72,    73,
      21,    75,    23,   210,     3,    34,    35,    28,     3,   255,
       5,    57,     7,     8,    60,    10,    11,    12,    94,    94,
      15,    50,    21,    13,    53,    20,    21,    28,   274,    28,
      25,     3,    27,    28,    51,    13,    37,    54,    33,    40,
       6,    36,    25,    38,    39,    13,   147,    42,    14,    21,
      16,    23,   146,   260,     0,    28,   150,    22,    22,   153,
       6,   134,    57,    28,    39,    60,     3,    13,    14,   163,
      16,    17,    18,    19,    36,    30,    38,   178,    48,    49,
       3,   154,   168,   169,   170,   171,   180,    28,    29,    39,
     176,    21,    27,   179,   188,   181,   134,    21,    21,   185,
      21,    43,    29,    32,    27,    28,    31,    39,    30,   195,
      33,   185,   198,    36,    26,    38,    45,    46,    47,    42,
      31,    50,    22,    24,    53,    44,    20,    56,    21,    58,
      59,    39,    61,    62,    57,    39,     6,    60,   215,    22,
     216,    22,    21,    13,    14,   231,    16,    17,    18,    19,
      39,    22,    30,    22,    22,   256,   257,   231,    31,    22,
     254,   255,     6,    24,    23,    23,   259,    22,    22,    13,
      14,   264,    16,   259,   275,    39,     9,   250,   264,     3,
     274,     5,     6,     7,     8,    24,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    39,    22,
     250,    25,    26,    27,    28,   198,    12,    94,   171,    33,
     179,   170,    36,   169,    38,    39,    56,   168,    42,    64,
     181,   154,   216,   264,   176,    17,    -1,    -1,   195,    -1,
      -1,    -1,    -1,    57,    -1,     3,    60,     5,     6,     7,
       8,    -1,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    -1,    -1,    -1,    25,    26,    27,
      28,    -1,    -1,    -1,    -1,    33,     3,    -1,    36,     6,
      38,    39,    -1,    -1,    42,    -1,    13,    14,    -1,    16,
      17,    18,    19,    -1,    21,    -1,     3,    -1,    -1,    57,
      27,    28,    60,    -1,    -1,    -1,    33,    -1,    -1,    36,
      -1,    38,    -1,    -1,    21,    42,    -1,    -1,    -1,    -1,
      27,    28,    -1,    -1,    -1,    -1,    33,    -1,    -1,    36,
      57,    38,    -1,    60,    -1,    42,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      57,    -1,    -1,    60
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     6,    13,    14,    16,    17,    18,    19,    79,    85,
      88,   102,   103,   111,   127,   150,   154,   155,   157,   161,
     162,    13,    13,     6,    13,    14,    16,     6,    14,    16,
     132,     3,    21,    28,    70,    89,    91,   101,   109,   110,
     137,   138,   151,    25,    81,    89,     0,   154,    13,    13,
     132,   132,    89,   137,    21,    23,    31,    39,    91,     3,
       5,     7,     8,    10,    11,    12,    15,    20,    21,    27,
      28,    33,    36,    38,    39,    42,    57,    60,    67,    69,
      71,    73,    74,    75,    76,    77,    78,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    92,    93,    95,    97,
      99,   100,   104,   105,   106,   107,   112,   113,   114,   115,
     116,   117,   118,   120,   121,   123,   126,   136,   139,   140,
     141,   142,   143,   144,   145,   147,   148,   152,   153,   158,
     159,   160,   163,    22,    88,   122,   134,   135,     3,    82,
     125,   158,   109,    39,    39,   152,    21,    98,     3,   120,
      21,    95,   129,    21,    88,    95,   156,    78,    78,    78,
      78,    78,    78,    21,   158,   158,    36,    38,    68,    27,
      43,    29,    31,    86,    48,    49,    94,    39,    30,    44,
      41,    63,    28,    37,    40,   119,    26,    21,    23,    57,
      60,    34,    35,    50,    53,   146,    51,    54,   149,    32,
      45,    46,    47,    50,    53,    56,    58,    59,    61,    62,
      72,    66,    89,   124,   133,   137,    31,    22,    24,    20,
      95,   108,   131,   152,    39,    95,    39,    95,   124,   137,
      22,    22,   118,    93,    76,    73,    71,   145,   152,    75,
      95,   115,    78,    71,    96,   130,    95,   148,    67,    71,
      21,    90,   128,   122,    21,    39,    22,    22,    78,    30,
      31,    22,    24,    66,    23,    95,   129,   152,   152,    82,
      71,    22,   125,    22,    39,     9,    24,    39,   129,   152,
      22
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
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
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


/* This macro is provided for backward compatibility. */

#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
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
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
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
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
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

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (0, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  YYSIZE_T yysize1;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = 0;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                yysize1 = yysize + yytnamerr (0, yytname[yyx]);
                if (! (yysize <= yysize1
                       && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                  return 2;
                yysize = yysize1;
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  yysize1 = yysize + yystrlen (yyformat);
  if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
    return 2;
  yysize = yysize1;

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
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


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
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
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

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
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
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

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
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
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
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
      

/* Line 1806 of yacc.c  */
#line 1764 "bison.c"
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
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
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
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

  /* Else will try to reuse lookahead token after shifting the error
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
      if (!yypact_value_is_default (yyn))
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

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
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



/* Line 2067 of yacc.c  */
#line 533 "test.y"

void print_node(struct node *node){
	assert(node != NULL); 
	if (node->kind == NODE_BINARY_OPERATION) { 
		printf("Node at 0x%p left_operand: 0x%p, right_operand:0x%p\n", 
			node, node->data.binary_operation.left_operand, 
				node->data.binary_operation.right_operand); 
	} else {
		printf("Node at 0x%p has value %lu\n" , node, node->data.number.value); 
	}
}

void print_tree(struct node * node){
	if (node == NULL)
		return; 
	if (node->kind == NODE_BINARY_OPERATION)
	{ 
		print_node(node); 
		print_node(node->data.binary_operation.left_operand); 
		print_node(node->data.binary_operation.right_operand); 
	} else { 
		print_node(node); 
	}
	return; 
}

void yyerror(char *s) {
  fprintf(stderr, "%s\n", s);
}

int main(int argc, const char *argv[])
{
	printf(">> "); 
	yyparse(); 
	return 0;
}


