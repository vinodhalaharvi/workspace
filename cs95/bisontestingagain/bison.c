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
#define YYFINAL  47
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   582

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  65
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  104
/* YYNRULES -- Number of rules.  */
#define YYNRULES  207
/* YYNRULES -- Number of states.  */
#define YYNSTATES  289

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
     105,   111,   113,   115,   117,   119,   121,   123,   126,   130,
     132,   134,   136,   139,   141,   143,   145,   149,   154,   156,
     160,   162,   164,   172,   174,   178,   180,   182,   184,   186,
     190,   193,   201,   205,   210,   215,   218,   221,   225,   233,
     239,   242,   244,   246,   248,   252,   254,   256,   258,   260,
     262,   264,   266,   270,   272,   276,   279,   281,   285,   287,
     291,   293,   295,   297,   299,   301,   304,   307,   309,   310,
     312,   314,   315,   317,   318,   320,   321,   323,   324,   326,
     327,   329,   330,   332,   333,   335,   336,   338,   340,   341,
     343,   344,   346,   348,   352,   354,   358,   360,   363,   366,
     369,   371,   373,   375,   377,   379,   382,   385,   388,   390,
     392,   394,   396,   400,   402,   404,   406,   408,   412,   414,
     418,   420,   422,   424,   427,   430,   434,   436,   439,   441,
     443,   446,   449,   453,   455,   457,   459,   461,   463,   465,
     467,   469,   471,   473,   475,   480,   482,   484,   486,   489,
     492,   494,   496,   498,   500,   502,   504,   506,   508,   510,
     512,   514,   517,   520,   524,   527,   531,   533
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     160,     0,    -1,   142,    -1,   137,    92,    -1,   120,    -1,
      67,    68,   120,    -1,    38,    -1,    36,    -1,    27,    78,
      -1,    93,    23,   128,    24,    -1,    82,    -1,   163,    72,
      71,    -1,    32,    -1,    59,    -1,    56,    -1,    46,    -1,
      61,    -1,    58,    -1,    53,    -1,    50,    -1,    45,    -1,
      47,    -1,    62,    -1,    95,    -1,    73,    27,    95,    -1,
      42,    78,    -1,    76,    -1,    75,    43,    76,    -1,    73,
      -1,    76,    29,    73,    -1,     5,    39,    -1,   163,    -1,
      21,   161,    22,    78,    -1,     6,    -1,    17,     6,    -1,
      18,     6,    -1,    71,    -1,    80,    31,    71,    -1,    25,
     129,    26,    -1,   119,    -1,   119,    41,    97,    30,    82,
      -1,   108,    -1,   107,    -1,   136,    -1,   127,    -1,   138,
      -1,    82,    -1,     7,    39,    -1,    90,   112,    39,    -1,
      87,    -1,   157,    -1,    88,    -1,    89,    88,    -1,   162,
      -1,   143,    -1,    93,    -1,    21,    66,    22,    -1,   131,
      23,   128,    24,    -1,   156,    -1,    21,    91,    22,    -1,
     103,    -1,    70,    -1,     8,   157,    20,    21,    97,    22,
      39,    -1,   150,    -1,    95,    96,   150,    -1,    48,    -1,
      49,    -1,    80,    -1,    71,    -1,    98,    31,    71,    -1,
      97,    39,    -1,    21,   134,    39,   132,    39,   132,    22,
      -1,    10,   100,   157,    -1,   145,    21,   133,    22,    -1,
      93,    21,   140,    22,    -1,   105,    81,    -1,   130,    91,
      -1,    11,   122,    39,    -1,    12,    21,    97,    22,   157,
       9,   157,    -1,    12,    21,    97,    22,   157,    -1,    28,
      78,    -1,    97,    -1,    91,    -1,   111,    -1,   112,    31,
     111,    -1,   155,    -1,   166,    -1,    79,    -1,   168,    -1,
      94,    -1,   101,    -1,   122,    -1,   115,    30,   157,    -1,
      75,    -1,   117,    44,    75,    -1,    33,    78,    -1,   117,
      -1,   119,    63,   117,    -1,    78,    -1,   120,   121,    78,
      -1,    28,    -1,    40,    -1,    37,    -1,     3,    -1,    39,
      -1,    90,    91,    -1,    90,   126,    -1,    84,    -1,    -1,
      66,    -1,    64,    -1,    -1,    85,    -1,    -1,    89,    -1,
      -1,    90,    -1,    -1,    92,    -1,    -1,    97,    -1,    -1,
      98,    -1,    -1,   110,    -1,    -1,    13,    -1,    64,    -1,
      -1,   142,    -1,    -1,     4,    -1,   124,    -1,   139,    31,
     124,    -1,   139,    -1,    21,    97,    22,    -1,    28,    -1,
      28,   142,    -1,   142,    93,    -1,   145,    57,    -1,   149,
      -1,   158,    -1,   102,    -1,   146,    -1,   144,    -1,   145,
      60,    -1,    57,   163,    -1,    60,   163,    -1,     3,    -1,
     125,    -1,   141,    -1,   153,    -1,   150,   151,   153,    -1,
      35,    -1,    53,    -1,    34,    -1,    50,    -1,    15,   132,
      39,    -1,    67,    -1,   153,   154,    67,    -1,    54,    -1,
      51,    -1,    16,    -1,    16,    13,    -1,    17,    16,    -1,
      17,    16,    13,    -1,    13,    -1,    17,    13,    -1,    17,
      -1,    14,    -1,    14,    13,    -1,    17,    14,    -1,    17,
      14,    13,    -1,     3,    -1,    99,    -1,   116,    -1,    81,
      -1,    83,    -1,   114,    -1,    77,    -1,    86,    -1,   152,
      -1,   106,    -1,   123,    -1,   145,    23,    97,    24,    -1,
      87,    -1,   104,    -1,   159,    -1,   160,   159,    -1,    90,
     126,    -1,   113,    -1,   167,    -1,   145,    -1,   164,    -1,
     165,    -1,   118,    -1,    74,    -1,    69,    -1,   109,    -1,
     148,    -1,   147,    -1,    36,    78,    -1,    38,    78,    -1,
      18,    16,   135,    -1,    18,   135,    -1,    18,    14,   135,
      -1,    19,    -1,    20,    21,    97,    22,   157,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    50,    50,    51,    55,    56,    60,    61,    65,    69,
      73,    74,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    92,    93,    97,   101,   102,   106,   107,
     111,   115,   116,   120,   121,   122,   126,   127,   131,   135,
     136,   140,   141,   145,   146,   147,   151,   155,   161,   166,
     167,   171,   172,   176,   180,   181,   186,   187,   192,   193,
     194,   195,   199,   205,   206,   210,   211,   215,   219,   220,
     224,   228,   232,   236,   240,   244,   248,   252,   256,   260,
     265,   269,   273,   277,   278,   283,   284,   285,   289,   290,
     291,   295,   299,   303,   304,   308,   312,   313,   317,   318,
     320,   321,   322,   326,   330,   334,   335,   341,   343,   344,
     347,   349,   350,   352,   353,   355,   356,   358,   359,   361,
     362,   364,   365,   367,   368,   370,   371,   373,   375,   376,
     378,   379,   387,   388,   392,   396,   400,   401,   405,   409,
     413,   414,   415,   416,   417,   421,   425,   429,   434,   435,
     436,   440,   441,   443,   444,   445,   446,   450,   454,   455,
     457,   458,   462,   463,   464,   465,   466,   467,   468,   469,
     470,   471,   472,   476,   480,   481,   482,   483,   484,   485,
     486,   487,   488,   489,   493,   497,   498,   502,   503,   508,
     511,   512,   515,   516,   517,   518,   519,   520,   521,   522,
     523,   527,   531,   535,   536,   537,   541,   545
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
  "conditional_expr", "conditional_statement", "constant", "constant_expr",
  "continue_statement", "decl", "declaration_or_statement",
  "declaration_or_statement_list", "declaration_specifiers", "declarator",
  "direct_abstract_declarator", "direct_declarator", "do_statement",
  "equality_expr", "equality_op", "expr", "expression_list",
  "expression_statement", "for_expr", "for_statement", "function_call",
  "function_declarator", "function_definition", "function_def_specifier",
  "goto_statement", "if_else_statement", "if_statement",
  "indirection_expr", "initial_clause", "initialized_declarator",
  "initialized_declarator_list", "integer_type_specifier",
  "iterative_statement", "label", "labeled_statement", "logical_and_expr",
  "logical_negation_expr", "logical_or_expr", "multiplicative_expr",
  "mult_op", "named_label", "null_statement", "parameter_decl", "CONSTANT",
  "abstract_declarator_opt", "character_constant", "constant_expr_opt",
  "declaration_or_statement_list_opt", "declaration_specifiers_opt",
  "direct_abstract_declarator_opt", "expr_opt", "expression_list_opt",
  "initial_clause_opt", "int_t_opt", "integer_constant", "pointer_opt",
  "string_constant", "parameter_list", "parameter_type_list",
  "parenthesized_expr", "pointer", "pointer_declarator",
  "postdecrement_expr", "postfix_expr", "postincrement_expr",
  "predecrement_expr", "preincrement_expr", "primary_expr",
  "relational_expr", "relational_op", "return_statement", "shift_expr",
  "shift_op", "signed_type_specifier", "simple_declarator", "statement",
  "subscript_expr", "top_level_decl", "translation_unit", "type_name",
  "type_specifier", "unary_expr", "unary_minus_expr", "unary_plus_expr",
  "unsigned_type_specifier", "void_type_specifier", "while_statement", 0
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
      82,    83,    83,    84,    84,    84,    85,    86,    87,    88,
      88,    89,    89,    90,    91,    91,    92,    92,    93,    93,
      93,    93,    94,    95,    95,    96,    96,    97,    98,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   112,   113,   113,   113,   114,   114,
     114,   115,   116,   117,   117,   118,   119,   119,   120,   120,
     121,   121,   121,   122,   123,   124,   124,   125,   126,   126,
     127,   128,   128,   129,   129,   130,   130,   131,   131,   132,
     132,   133,   133,   134,   134,   135,   135,   136,   137,   137,
     138,   138,   139,   139,   140,   141,   142,   142,   143,   144,
     145,   145,   145,   145,   145,   146,   147,   148,   149,   149,
     149,   150,   150,   151,   151,   151,   151,   152,   153,   153,
     154,   154,   155,   155,   155,   155,   155,   155,   155,   155,
     155,   155,   155,   156,   157,   157,   157,   157,   157,   157,
     157,   157,   157,   157,   158,   159,   159,   160,   160,   161,
     162,   162,   163,   163,   163,   163,   163,   163,   163,   163,
     163,   164,   165,   166,   166,   166,   167,   168
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     3,     1,     1,     2,     4,
       1,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     2,     1,     3,     1,     3,
       2,     1,     4,     1,     2,     2,     1,     3,     3,     1,
       5,     1,     1,     1,     1,     1,     1,     2,     3,     1,
       1,     1,     2,     1,     1,     1,     3,     4,     1,     3,
       1,     1,     7,     1,     3,     1,     1,     1,     1,     3,
       2,     7,     3,     4,     4,     2,     2,     3,     7,     5,
       2,     1,     1,     1,     3,     1,     1,     1,     1,     1,
       1,     1,     3,     1,     3,     2,     1,     3,     1,     3,
       1,     1,     1,     1,     1,     2,     2,     1,     0,     1,
       1,     0,     1,     0,     1,     0,     1,     0,     1,     0,
       1,     0,     1,     0,     1,     0,     1,     1,     0,     1,
       0,     1,     1,     3,     1,     3,     1,     2,     2,     2,
       1,     1,     1,     1,     1,     2,     2,     2,     1,     1,
       1,     1,     3,     1,     1,     1,     1,     3,     1,     3,
       1,     1,     1,     2,     2,     3,     1,     2,     1,     1,
       2,     2,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     4,     1,     1,     1,     2,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     2,     3,     2,     3,     1,     5
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
     115,    33,   166,   169,   162,   168,   125,   206,    87,   185,
       0,   186,     0,   190,     0,    85,   187,   115,    53,    86,
     191,   170,   163,    34,   167,   171,   164,    35,   126,   125,
     125,   204,   173,     0,   136,    61,    82,    55,    60,    83,
       0,     0,    54,    58,   130,    75,    76,     1,   188,   172,
     165,   205,   203,     0,   137,     0,   130,     0,    48,   138,
     148,   131,     0,     0,   130,     0,     0,     0,   130,     0,
     130,   130,   130,   130,   130,   130,   104,   130,   130,   130,
     110,   158,   197,    36,    28,   196,    93,    26,   179,    98,
      67,   176,    10,   177,   107,   180,    49,    51,   130,     0,
      89,    23,     0,   174,    90,   142,   182,    42,    41,   198,
     178,     0,   175,    96,   195,    39,     4,    91,   183,   149,
      44,     0,    43,    45,   150,   144,   192,   143,   200,   199,
     140,    63,   181,   151,    50,   141,    31,   193,   194,    88,
      59,   108,   132,   134,     0,   148,    46,   112,     0,    31,
      84,    30,    47,     0,   130,   130,   103,     0,   130,   120,
       0,   130,   128,     0,     0,     8,    80,    95,   201,   202,
      25,   130,   146,   147,     7,     6,   130,   130,   130,   130,
     130,    52,    65,    66,   130,    70,   130,   130,   130,   130,
     100,   102,   101,   130,    38,   130,   130,   139,   145,   155,
     153,   156,   154,   130,   161,   160,   130,    12,    20,    15,
      21,    19,    18,    14,    17,    13,    16,    22,   130,   109,
     105,   106,   117,     2,     0,    74,     9,     0,    81,   124,
       0,    72,    77,     0,   157,     0,   189,   129,   135,   130,
       5,    24,    27,    29,    37,    64,    92,    94,     0,    97,
      99,    68,   122,     0,     0,   152,   159,    11,   128,     3,
       0,   133,   130,   130,   130,   130,    32,   130,   130,    73,
     184,     0,   130,     0,     0,    79,   207,    40,    69,    56,
       0,     0,   130,   130,    57,    62,     0,    78,    71
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,   219,    81,   176,    82,    35,    83,   218,    84,    85,
      86,    87,    88,    89,     8,    90,    91,    92,    93,    94,
     147,    95,     9,    97,    98,    10,    36,   259,    37,   100,
     101,   184,   102,   252,   103,   155,   104,   105,    38,    11,
      12,   106,   107,   108,   109,   229,    39,    40,    13,   110,
     111,   112,   113,   114,   115,   116,   193,   117,   118,   142,
     119,   221,   120,   148,   121,    14,   260,   160,   253,   230,
      31,   122,   222,   123,   143,   144,   124,    41,    42,   125,
     126,   127,   128,   129,   130,   131,   203,   132,   133,   206,
      15,    43,   134,   135,    16,    17,   164,    18,   136,   137,
     138,    19,    20,   139
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -173
static const yytype_int16 yypact[] =
{
     192,  -173,  -173,    26,    97,     0,    65,  -173,  -173,  -173,
      94,  -173,    93,  -173,    94,  -173,  -173,   162,  -173,  -173,
    -173,  -173,  -173,  -173,  -173,   108,   111,  -173,  -173,   112,
     112,  -173,  -173,    94,   120,  -173,  -173,    28,  -173,  -173,
       6,    80,  -173,  -173,    49,  -173,  -173,  -173,  -173,  -173,
    -173,  -173,  -173,   117,  -173,   192,   131,    94,  -173,    28,
     119,  -173,   114,   124,   265,   129,   148,   145,   334,   149,
     314,   478,   478,   478,   478,   478,  -173,   478,   518,   518,
    -173,    48,  -173,  -173,   144,  -173,   134,   143,  -173,  -173,
     151,  -173,  -173,  -173,  -173,  -173,  -173,  -173,   224,    94,
    -173,    24,   135,  -173,  -173,  -173,  -173,  -173,  -173,  -173,
    -173,   153,  -173,   146,  -173,   -29,    10,  -173,  -173,  -173,
    -173,   161,  -173,  -173,  -173,  -173,   -16,  -173,  -173,  -173,
    -173,    92,  -173,   -11,  -173,  -173,    58,  -173,  -173,  -173,
    -173,   133,  -173,   158,   170,  -173,  -173,  -173,   172,  -173,
    -173,  -173,  -173,   174,   354,   265,  -173,   160,   478,  -173,
     168,   478,    20,   175,   178,  -173,  -173,  -173,  -173,  -173,
    -173,   478,  -173,  -173,  -173,  -173,   478,   478,   478,   478,
     478,  -173,  -173,  -173,   478,  -173,   265,   478,   478,   478,
    -173,  -173,  -173,   478,  -173,   398,   478,  -173,  -173,  -173,
    -173,  -173,  -173,   478,  -173,  -173,   478,  -173,  -173,  -173,
    -173,  -173,  -173,  -173,  -173,  -173,  -173,  -173,   478,  -173,
    -173,  -173,   191,    77,   192,  -173,  -173,   193,  -173,  -173,
     176,  -173,  -173,   194,  -173,   195,  -173,   197,  -173,   478,
      10,    24,   143,   144,  -173,    92,  -173,   134,   203,   146,
    -173,  -173,   215,   200,   201,   -11,    48,  -173,   120,   225,
     230,  -173,   478,   334,   265,   265,  -173,   478,   478,  -173,
    -173,   232,   131,   233,   208,   247,  -173,  -173,  -173,  -173,
     234,   220,   438,   265,  -173,  -173,   239,  -173,  -173
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -173,     7,    61,  -173,  -173,  -173,  -172,  -173,    85,  -173,
      84,    96,  -173,   -53,  -173,  -173,   266,   -54,  -173,  -173,
    -173,  -173,    -9,   181,  -173,   -40,     3,  -173,   -38,  -173,
     105,  -173,   -59,  -173,  -173,  -173,  -173,  -173,  -173,  -173,
    -173,  -173,  -173,  -173,  -173,  -173,   226,  -173,  -173,  -173,
    -173,  -173,    98,  -173,  -173,   113,  -173,   228,  -173,    67,
    -173,   137,  -173,    23,  -173,  -173,  -173,  -117,  -173,  -173,
      64,  -173,  -173,  -173,  -173,  -173,  -173,   -34,  -173,  -173,
    -173,  -173,  -173,  -173,  -173,   116,  -173,  -173,    99,  -173,
    -173,  -173,   -63,  -173,   279,  -173,  -173,  -173,   -46,  -173,
    -173,  -173,  -173,  -173
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -130
static const yytype_int16 yytable[] =
{
      54,   153,   146,    59,    99,   195,    23,   196,   244,   159,
     149,   163,   188,    24,    25,   141,    26,    46,   165,   166,
     167,   168,   169,   251,   170,   149,   149,   149,   149,   149,
     162,   149,   172,   173,   189,    96,    53,    57,   190,    21,
     204,   197,  -108,   205,   198,    58,   257,   191,    34,    55,
     192,    56,    60,    61,    62,     1,    63,    64,    99,    65,
      66,    67,     2,     3,    68,     4,     5,     6,     7,    69,
      70,    27,   182,   183,    44,  -113,    71,    72,    28,    29,
      32,    30,    73,    32,   174,    74,   175,    75,    76,    96,
     207,    77,   231,    51,    52,   228,   278,    32,    33,   233,
    -129,    33,   235,   208,   209,   210,    78,   223,   211,    79,
      22,   212,   163,    80,   213,    33,   214,   215,    44,   216,
     217,    49,    34,   246,    50,    28,   199,   200,   237,   248,
     149,   149,   149,   149,   145,    61,    32,   254,   149,   140,
     250,   149,   201,   149,   220,   202,   274,   149,    34,  -103,
     154,   156,    70,   151,    33,  -111,  -128,   149,    71,    72,
     149,    34,    47,   152,    73,   286,   158,    74,     1,    75,
     161,   177,   179,    77,   185,     2,     3,   178,     4,     5,
       6,     7,   180,   186,   141,    59,   266,   194,    78,   224,
     187,    79,   225,   149,   227,    80,   226,   238,     1,   232,
     239,   275,   276,   273,   159,     2,     3,   234,     4,     5,
       6,     7,   258,   277,   262,   263,   264,   265,   146,    -2,
     287,   149,   269,   159,   237,   270,   149,    60,    61,    62,
       1,    63,    64,   267,    65,    66,    67,     2,     3,    68,
       4,     5,     6,     7,    69,    70,   268,   282,  -118,    44,
    -114,    71,    72,   272,   279,   281,   283,    73,   284,   285,
      74,   288,    75,    76,   243,   271,    77,   256,    60,    61,
      62,   247,    63,    64,   242,    65,    66,    67,    45,   181,
      68,    78,   241,   150,    79,    69,    70,   249,    80,   240,
      44,   261,    71,    72,   157,   280,    48,     0,    73,   236,
     245,    74,   255,    75,    76,     0,     0,    77,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   145,    61,     0,
       1,     0,    78,     0,     0,    79,     0,     2,     3,    80,
       4,     5,     6,     7,     0,    70,     0,   145,    61,     0,
       0,    71,    72,     0,     0,     0,     0,    73,     0,     0,
      74,     0,    75,     0,     0,    70,    77,   145,    61,     0,
       0,    71,    72,     0,     0,     0,     0,    73,     0,     0,
      74,    78,    75,  -119,    79,    70,    77,     0,    80,     0,
       0,    71,    72,     0,     0,     0,     0,    73,     0,     0,
      74,    78,    75,  -123,    79,     0,    77,     0,    80,     0,
       0,   145,    61,     0,     0,     0,     0,     0,     0,     0,
       0,    78,     0,     0,    79,     0,     0,     0,    80,    70,
    -121,     0,     0,     0,     0,    71,    72,     0,     0,     0,
       0,    73,     0,     0,    74,     0,    75,     0,     0,     0,
      77,   145,    61,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    78,     0,     0,    79,    70,
    -119,     0,    80,     0,     0,    71,    72,     0,     0,     0,
       0,    73,     0,     0,    74,     0,    75,     0,     0,     0,
      77,   145,    61,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    78,     0,     0,    79,    70,
       0,     0,    80,     0,     0,    71,    72,     0,     0,     0,
       0,    73,     0,     0,    74,     0,    75,     0,     0,     0,
      77,   145,    61,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    78,     0,     0,    79,   171,
       0,     0,    80,     0,     0,    71,    72,     0,     0,     0,
       0,    73,     0,     0,    74,     0,    75,     0,     0,     0,
      77,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    78,     0,     0,    79,     0,
       0,     0,    80
};

#define yypact_value_is_default(yystate) \
  ((yystate) == (-173))

#define yytable_value_is_error(yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
      34,    64,    56,    41,    44,    21,     6,    23,   180,    68,
      56,    70,    41,    13,    14,    55,    16,    14,    71,    72,
      73,    74,    75,   195,    77,    71,    72,    73,    74,    75,
      70,    77,    78,    79,    63,    44,    33,    31,    28,    13,
      51,    57,    22,    54,    60,    39,   218,    37,    28,    21,
      40,    23,     3,     4,     5,     6,     7,     8,    98,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,     6,    48,    49,    25,    26,    27,    28,    13,    14,
       3,    16,    33,     3,    36,    36,    38,    38,    39,    98,
      32,    42,   155,    29,    30,   154,   268,     3,    21,   158,
      23,    21,   161,    45,    46,    47,    57,   141,    50,    60,
      13,    53,   171,    64,    56,    21,    58,    59,    25,    61,
      62,    13,    28,   186,    13,    13,    34,    35,   162,   188,
     176,   177,   178,   179,     3,     4,     3,   196,   184,    22,
     193,   187,    50,   189,   141,    53,   263,   193,    28,    30,
      21,     3,    21,    39,    21,    24,    23,   203,    27,    28,
     206,    28,     0,    39,    33,   282,    21,    36,     6,    38,
      21,    27,    29,    42,    39,    13,    14,    43,    16,    17,
      18,    19,    31,    30,   224,   223,   239,    26,    57,    31,
      44,    60,    22,   239,    20,    64,    24,    22,     6,    39,
      22,   264,   265,   262,   263,    13,    14,    39,    16,    17,
      18,    19,    21,   267,    21,    39,    22,    22,   272,    22,
     283,   267,    22,   282,   258,    24,   272,     3,     4,     5,
       6,     7,     8,    30,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    31,    39,    23,    25,
      26,    27,    28,    23,    22,    22,     9,    33,    24,    39,
      36,    22,    38,    39,   179,   258,    42,   206,     3,     4,
       5,   187,     7,     8,   178,    10,    11,    12,    12,    98,
      15,    57,   177,    57,    60,    20,    21,   189,    64,   176,
      25,   224,    27,    28,    66,   272,    17,    -1,    33,   162,
     184,    36,   203,    38,    39,    -1,    -1,    42,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,    -1,
       6,    -1,    57,    -1,    -1,    60,    -1,    13,    14,    64,
      16,    17,    18,    19,    -1,    21,    -1,     3,     4,    -1,
      -1,    27,    28,    -1,    -1,    -1,    -1,    33,    -1,    -1,
      36,    -1,    38,    -1,    -1,    21,    42,     3,     4,    -1,
      -1,    27,    28,    -1,    -1,    -1,    -1,    33,    -1,    -1,
      36,    57,    38,    39,    60,    21,    42,    -1,    64,    -1,
      -1,    27,    28,    -1,    -1,    -1,    -1,    33,    -1,    -1,
      36,    57,    38,    39,    60,    -1,    42,    -1,    64,    -1,
      -1,     3,     4,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    57,    -1,    -1,    60,    -1,    -1,    -1,    64,    21,
      22,    -1,    -1,    -1,    -1,    27,    28,    -1,    -1,    -1,
      -1,    33,    -1,    -1,    36,    -1,    38,    -1,    -1,    -1,
      42,     3,     4,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    57,    -1,    -1,    60,    21,
      22,    -1,    64,    -1,    -1,    27,    28,    -1,    -1,    -1,
      -1,    33,    -1,    -1,    36,    -1,    38,    -1,    -1,    -1,
      42,     3,     4,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    57,    -1,    -1,    60,    21,
      -1,    -1,    64,    -1,    -1,    27,    28,    -1,    -1,    -1,
      -1,    33,    -1,    -1,    36,    -1,    38,    -1,    -1,    -1,
      42,     3,     4,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    57,    -1,    -1,    60,    21,
      -1,    -1,    64,    -1,    -1,    27,    28,    -1,    -1,    -1,
      -1,    33,    -1,    -1,    36,    -1,    38,    -1,    -1,    -1,
      42,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    57,    -1,    -1,    60,    -1,
      -1,    -1,    64
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     6,    13,    14,    16,    17,    18,    19,    79,    87,
      90,   104,   105,   113,   130,   155,   159,   160,   162,   166,
     167,    13,    13,     6,    13,    14,    16,     6,    13,    14,
      16,   135,     3,    21,    28,    70,    91,    93,   103,   111,
     112,   142,   143,   156,    25,    81,    91,     0,   159,    13,
      13,   135,   135,    91,   142,    21,    23,    31,    39,    93,
       3,     4,     5,     7,     8,    10,    11,    12,    15,    20,
      21,    27,    28,    33,    36,    38,    39,    42,    57,    60,
      64,    67,    69,    71,    73,    74,    75,    76,    77,    78,
      80,    81,    82,    83,    84,    86,    87,    88,    89,    90,
      94,    95,    97,    99,   101,   102,   106,   107,   108,   109,
     114,   115,   116,   117,   118,   119,   120,   122,   123,   125,
     127,   129,   136,   138,   141,   144,   145,   146,   147,   148,
     149,   150,   152,   153,   157,   158,   163,   164,   165,   168,
      22,    90,   124,   139,   140,     3,    82,    85,   128,   163,
     111,    39,    39,   157,    21,   100,     3,   122,    21,    97,
     132,    21,    90,    97,   161,    78,    78,    78,    78,    78,
      78,    21,   163,   163,    36,    38,    68,    27,    43,    29,
      31,    88,    48,    49,    96,    39,    30,    44,    41,    63,
      28,    37,    40,   121,    26,    21,    23,    57,    60,    34,
      35,    50,    53,   151,    51,    54,   154,    32,    45,    46,
      47,    50,    53,    56,    58,    59,    61,    62,    72,    66,
      91,   126,   137,   142,    31,    22,    24,    20,    97,   110,
     134,   157,    39,    97,    39,    97,   126,   142,    22,    22,
     120,    95,    76,    73,    71,   150,   157,    75,    97,   117,
      78,    71,    98,   133,    97,   153,    67,    71,    21,    92,
     131,   124,    21,    39,    22,    22,    78,    30,    31,    22,
      24,    66,    23,    97,   132,   157,   157,    82,    71,    22,
     128,    22,    39,     9,    24,    39,   132,   157,    22
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
#line 1811 "bison.c"
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
#line 547 "test.y"

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


