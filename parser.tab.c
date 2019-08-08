/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "parser.y" /* yacc.c:339  */

	#include <stdio.h>
	#include <string.h>
	#include <string>
	extern "C" void yyerror(char *s);
	extern int yylex(void);
	extern int yylineno;
	extern Program program_object;
	extern int scope;

	Symbol_Table* local_table = new Symbol_Table();
	Symbol_Table* global_table = new Symbol_Table();
	Procedure * procedure ;
	Symbol_Table* argument_list = new Symbol_Table();
	int arg_numbers = 0 ;
	list<Ast *> * param_list = new list<Ast*>();

	 // new Procedure(void_data_type, "main", yylineno);
	// Procedure * procedure = new Procedure(void_data_type, "main", yylineno);
	list<Ast *> * ast_list = new list<Ast*>();
	#define YYDEBUG 1


#line 90 "parser.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "parser.tab.h".  */
#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    INTEGER = 258,
    FLOAT = 259,
    ASSIGN = 260,
    VOID = 261,
    INTEGER_NUMBER = 262,
    DOUBLE_NUMBER = 263,
    NAME = 264,
    DO = 265,
    WHILE = 266,
    IF = 267,
    ELSE = 268,
    PRINT = 269,
    RETURN = 270,
    OR = 271,
    AND = 272,
    EQUAL = 273,
    NOT_EQUAL = 274,
    LESS_THAN = 275,
    LESS_THAN_EQUAL = 276,
    GREATER_THAN = 277,
    GREATER_THAN_EQUAL = 278,
    NOT = 280
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 41 "parser.y" /* yacc.c:355  */

	int integer_value;           
	double double_value;             
	string * string_value; 
	list<Ast *> * ast_list;
	Ast* ast;
	Symbol_Table * symbol_table;
	Symbol_Table_Entry * symbol_entry;
	Basic_Block * basic_block;
	Procedure * procedure;


#line 168 "parser.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 185 "parser.tab.c" /* yacc.c:358  */

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
#else
typedef signed char yytype_int8;
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
# elif ! defined YYSIZE_T
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
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
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
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
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
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   483

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  38
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  40
/* YYNRULES -- Number of rules.  */
#define YYNRULES  115
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  241

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   280

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      33,    34,    29,    27,    35,    28,     2,    30,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    18,    15,
       2,     2,     2,    17,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    36,     2,    37,     2,     2,     2,     2,
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
      16,    19,    20,    21,    22,    23,    24,    25,    26,    31,
      32
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    65,    65,    82,    83,    84,    89,    90,    93,    96,
     108,   121,   124,   134,   148,   165,   182,   199,   216,   233,
     256,   266,   275,   285,   296,   303,   313,   323,   334,   346,
     353,   356,   357,   363,   361,   424,   422,   487,   485,   562,
     580,   597,   602,   611,   612,   626,   634,   642,   651,   660,
     669,   678,   695,   714,   721,   722,   737,   745,   755,   763,
     772,   778,   787,   803,   820,   827,   837,   838,   841,   844,
     865,   886,   889,   907,   936,   951,   969,   974,   984,   995,
    1006,  1014,  1023,  1024,  1027,  1028,  1029,  1032,  1069,  1079,
    1099,  1106,  1111,  1116,  1121,  1126,  1131,  1137,  1143,  1149,
    1155,  1169,  1192,  1197,  1205,  1211,  1218,  1227,  1236,  1246,
    1255,  1261,  1265,  1269,  1273,  1277
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INTEGER", "FLOAT", "ASSIGN", "VOID",
  "INTEGER_NUMBER", "DOUBLE_NUMBER", "NAME", "DO", "WHILE", "IF", "ELSE",
  "PRINT", "';'", "RETURN", "'?'", "':'", "OR", "AND", "EQUAL",
  "NOT_EQUAL", "LESS_THAN", "LESS_THAN_EQUAL", "GREATER_THAN",
  "GREATER_THAN_EQUAL", "'+'", "'-'", "'*'", "'/'", "\"ter\"", "NOT",
  "'('", "')'", "','", "'{'", "'}'", "$accept", "program",
  "optional_declaration_list", "variable_declaration_global",
  "integer_declaration_global", "integer_variable_list_global",
  "float_declaration_global", "float_variable_list_global",
  "procedure_declaration", "argument_declaration",
  "argument_type_declaration", "procedure_definition_list",
  "procedure_definition_list_temp", "procedure_definition", "$@1", "$@2",
  "$@3", "procedure_call", "name_list", "declaration_list",
  "declaration_list_loop", "print_statement", "variable_declaration",
  "integer_declaration", "integer_variable_list", "float_declaration",
  "float_variable_list", "assignment_statement", "assign_expression",
  "expression", "value", "variable", "constant", "conditional_statement",
  "if_statement", "else_statement", "while_statement",
  "do_while_statement", "ternary_operator", "program_statements", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,    59,   270,    63,    58,   271,
     272,   273,   274,   275,   276,   277,   278,    43,    45,    42,
      47,   279,   280,    40,    41,    44,   123,   125
};
# endif

#define YYPACT_NINF -176

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-176)))

#define YYTABLE_NINF -83

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -176,     8,    80,  -176,    37,    60,    66,  -176,    74,    76,
    -176,  -176,   113,    64,    83,    93,    99,   108,  -176,  -176,
      90,   140,   144,  -176,   113,    41,   147,    41,   152,    41,
     130,   133,   138,  -176,   168,   182,    43,    95,  -176,   105,
     149,  -176,   151,   248,   195,   195,   195,  -176,  -176,     2,
     209,   180,   224,    25,   191,    27,   205,   168,   182,   250,
     315,   340,  -176,  -176,   184,   199,  -176,  -176,  -176,  -176,
    -176,  -176,  -176,  -176,  -176,   186,   188,   201,  -176,  -176,
    -176,  -176,  -176,    84,   164,   178,   226,   240,   218,    40,
     220,   223,   255,   319,  -176,  -176,   242,  -176,  -176,   256,
     263,  -176,   261,  -176,  -176,  -176,  -176,  -176,  -176,  -176,
     235,  -176,   245,   304,  -176,  -176,   336,   336,   336,  -176,
    -176,  -176,   443,  -176,   281,  -176,    36,  -176,  -176,  -176,
     453,   292,   336,   336,  -176,   302,  -176,   377,  -176,  -176,
     193,  -176,  -176,  -176,   336,   310,   313,  -176,   350,   443,
    -176,  -176,   419,   145,   207,   336,   336,   336,   336,   336,
     336,   336,   336,   336,   336,   336,   336,   336,   290,   339,
     343,  -176,  -176,  -176,   393,  -176,  -176,  -176,   336,  -176,
    -176,   333,  -176,   320,   324,  -176,  -176,  -176,  -176,  -176,
    -176,   443,   443,   443,   443,   443,   443,   212,   212,  -176,
    -176,   433,   334,  -176,   336,   282,   288,  -176,   443,  -176,
     409,   222,   348,  -176,   336,   359,  -176,  -176,  -176,   322,
    -176,  -176,   336,   443,   331,   236,   251,   297,  -176,   363,
    -176,  -176,   322,  -176,  -176,  -176,   342,  -176,   265,  -176,
    -176
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       5,     0,     0,     1,     0,     0,     0,     3,     0,     0,
       4,     2,    32,     9,     8,    12,    11,     0,     6,     7,
       0,     0,     0,    30,    32,    24,     0,    24,     0,    24,
       0,     0,     0,    31,    27,    28,     0,     0,    10,     0,
       0,    13,     0,     0,    24,    24,    24,    22,    23,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    18,    35,     0,     0,    15,    25,    26,    19,
      37,    16,    17,    33,    14,     0,     0,     0,    53,    20,
      21,    53,    53,     0,     0,     0,     0,     0,    87,     0,
       0,     0,     0,     0,    53,    36,     0,    49,    43,     0,
       0,    44,     0,    75,    46,    45,    47,    38,    34,    69,
      68,    72,    71,     0,    88,    89,     0,     0,     0,    64,
      86,   115,     0,    83,    84,    85,     0,   111,   112,   113,
     114,     0,     0,     0,    87,     0,    52,     0,    84,    82,
       0,    50,    66,    67,     0,     0,     0,    40,     0,    42,
      81,    98,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    65,    51,    48,     0,    70,    73,    39,     0,    76,
      99,     0,    64,     0,     0,    60,    54,    55,    57,    56,
      58,    94,    95,    91,    90,    92,    93,    79,    80,    78,
      77,     0,    96,    97,     0,     0,     0,    74,    41,    63,
       0,     0,     0,    61,     0,     0,    64,   107,    64,   105,
      62,    59,     0,   110,     0,     0,     0,     0,   101,     0,
     109,   106,   105,    64,   102,   104,     0,   100,     0,   108,
     103
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -176,  -176,  -176,  -176,  -176,  -176,  -176,  -176,  -176,   326,
      -9,  -176,   362,   365,  -176,  -176,  -176,   -80,  -176,    31,
    -175,   -61,   -48,  -176,  -176,  -176,  -176,   -73,  -176,   -54,
    -176,   -83,  -176,   -52,   -70,   155,   -58,   -55,   -68,  -173
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,     7,     8,    14,     9,    16,    10,    36,
      37,    11,    23,    24,    82,    78,    81,   120,   148,    83,
     154,   185,   186,    99,   110,   100,   112,   187,   102,   122,
     123,   138,   125,   126,   188,   228,   189,   190,   139,   131
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     103,   103,   103,    96,    96,    96,   124,   211,     3,   135,
     101,   101,   101,   104,   104,   104,   121,    62,    40,   127,
      43,   130,    97,    97,    97,   105,   105,   105,   106,   106,
     106,   128,   217,   219,   129,    98,    98,    98,    63,   137,
      69,   225,    72,   226,    34,    35,    13,   114,   115,    88,
      89,    90,    91,   165,   235,   166,   167,   103,   238,   149,
      96,    70,   150,    73,   152,   151,   153,   101,   116,    15,
     104,   103,   117,   118,   184,    17,   119,    49,    50,    97,
     169,   170,   105,     4,     5,   106,     6,    86,    87,    18,
     174,    19,    98,    88,    89,    90,    91,    25,    92,    30,
      93,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,    84,    85,   202,   203,    20,    21,    26,    22,
      94,    95,   124,   124,   208,   140,    27,   210,   103,    51,
      52,   184,   121,   121,    28,   127,   127,   130,   130,    53,
      50,    29,   103,   103,   124,   184,   184,   128,   128,    31,
     129,   129,   215,    32,   121,   103,    38,   234,   184,   130,
     223,    41,   165,    44,   166,   167,    45,    86,    87,   128,
     229,    46,   129,    88,    89,    90,    91,    47,    92,   180,
      93,    86,    87,    54,    52,    55,    50,    88,    89,    90,
      91,    48,    92,    79,    93,    66,    86,    87,    57,    58,
      94,   107,    88,    89,    90,    91,    71,    92,    80,    93,
      86,    87,    64,    65,    94,   108,    88,    89,    90,    91,
      74,    92,    63,   181,    70,    86,    87,    67,    68,    94,
     173,    88,    89,    90,    91,   109,    92,    73,   181,    86,
      87,   163,   164,   182,   183,    88,    89,    90,    91,   111,
      92,   113,   181,   132,    86,    87,   133,   141,   182,   221,
      88,    89,    90,    91,   134,    92,   144,   181,    86,    87,
     145,   142,   182,   231,    88,    89,    90,    91,   143,    92,
     146,   181,    56,    52,    75,    50,   -75,   182,   232,   114,
     115,    88,    89,    90,    91,   114,   115,    88,    89,    90,
      91,   182,   240,   168,   114,   115,    88,    89,    90,    91,
     116,   114,   115,    88,   117,   118,   116,   171,   216,   175,
     117,   118,   176,   204,   218,   116,   114,   115,    88,   117,
     118,   212,   116,   233,   136,   227,   117,   118,   147,   213,
     114,   115,    88,   114,   115,    88,   230,   116,   209,    76,
      50,   117,   118,    39,   167,    42,   165,   239,   166,   167,
     165,   116,   166,   167,   116,   117,   118,    12,   117,   118,
      59,    60,    61,   205,    77,    50,   165,   206,   166,   167,
     165,   222,   166,   167,   177,   178,    33,   237,     0,     0,
       0,     0,   172,   224,     0,     0,     0,   236,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   207,     0,
       0,     0,     0,     0,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   220,     0,     0,     0,     0,     0,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
       0,   214,     0,   179,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   -82,   -82,   -82,   -82,   -82,   -82,
     -82,   -82,   -82,   -82
};

static const yytype_int16 yycheck[] =
{
      83,    84,    85,    83,    84,    85,    89,   182,     0,    92,
      83,    84,    85,    83,    84,    85,    89,    15,    27,    89,
      29,    89,    83,    84,    85,    83,    84,    85,    83,    84,
      85,    89,   205,   206,    89,    83,    84,    85,    36,    93,
      15,   216,    15,   218,     3,     4,     9,     7,     8,     9,
      10,    11,    12,    17,   227,    19,    20,   140,   233,   113,
     140,    36,   116,    36,   118,   117,   118,   140,    28,     9,
     140,   154,    32,    33,   154,     9,    36,    34,    35,   140,
     132,   133,   140,     3,     4,   140,     6,     3,     4,    15,
     144,    15,   140,     9,    10,    11,    12,    33,    14,     9,
      16,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,    81,    82,   166,   167,     3,     4,    35,     6,
      36,    37,   205,   206,   178,    94,    33,   181,   211,    34,
      35,   211,   205,   206,    35,   205,   206,   205,   206,    34,
      35,    33,   225,   226,   227,   225,   226,   205,   206,     9,
     205,   206,   204,     9,   227,   238,     9,   227,   238,   227,
     214,     9,    17,    33,    19,    20,    33,     3,     4,   227,
     222,    33,   227,     9,    10,    11,    12,     9,    14,    34,
      16,     3,     4,    34,    35,    34,    35,     9,    10,    11,
      12,     9,    14,     9,    16,    15,     3,     4,     3,     4,
      36,    37,     9,    10,    11,    12,    15,    14,     9,    16,
       3,     4,     3,     4,    36,    37,     9,    10,    11,    12,
      15,    14,    36,    16,    36,     3,     4,     3,     4,    36,
      37,     9,    10,    11,    12,     9,    14,    36,    16,     3,
       4,    29,    30,    36,    37,     9,    10,    11,    12,     9,
      14,    33,    16,    33,     3,     4,    33,    15,    36,    37,
       9,    10,    11,    12,     9,    14,     5,    16,     3,     4,
      35,    15,    36,    37,     9,    10,    11,    12,    15,    14,
      35,    16,    34,    35,    34,    35,     5,    36,    37,     7,
       8,     9,    10,    11,    12,     7,     8,     9,    10,    11,
      12,    36,    37,    11,     7,     8,     9,    10,    11,    12,
      28,     7,     8,     9,    32,    33,    28,    15,    36,     9,
      32,    33,     9,    33,    36,    28,     7,     8,     9,    32,
      33,    11,    28,    36,    15,    13,    32,    33,    34,    15,
       7,     8,     9,     7,     8,     9,    15,    28,    15,    34,
      35,    32,    33,    27,    20,    29,    17,    15,    19,    20,
      17,    28,    19,    20,    28,    32,    33,     2,    32,    33,
      44,    45,    46,    34,    34,    35,    17,    34,    19,    20,
      17,    33,    19,    20,    34,    35,    24,   232,    -1,    -1,
      -1,    -1,    15,    34,    -1,    -1,    -1,    34,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    15,    -1,
      -1,    -1,    -1,    -1,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    15,    -1,    -1,    -1,    -1,    -1,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      -1,    18,    -1,    34,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    39,    40,     0,     3,     4,     6,    41,    42,    44,
      46,    49,    51,     9,    43,     9,    45,     9,    15,    15,
       3,     4,     6,    50,    51,    33,    35,    33,    35,    33,
       9,     9,     9,    50,     3,     4,    47,    48,     9,    47,
      48,     9,    47,    48,    33,    33,    33,     9,     9,    34,
      35,    34,    35,    34,    34,    34,    34,     3,     4,    47,
      47,    47,    15,    36,     3,     4,    15,     3,     4,    15,
      36,    15,    15,    36,    15,    34,    34,    34,    53,     9,
       9,    54,    52,    57,    57,    57,     3,     4,     9,    10,
      11,    12,    14,    16,    36,    37,    55,    59,    60,    61,
      63,    65,    66,    69,    72,    74,    75,    37,    37,     9,
      62,     9,    64,    33,     7,     8,    28,    32,    33,    36,
      55,    65,    67,    68,    69,    70,    71,    72,    74,    75,
      76,    77,    33,    33,     9,    69,    15,    67,    69,    76,
      57,    15,    15,    15,     5,    35,    35,    34,    56,    67,
      67,    71,    67,    71,    58,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    17,    19,    20,    11,    71,
      71,    15,    15,    37,    67,     9,     9,    34,    35,    34,
      34,    16,    36,    37,    55,    59,    60,    65,    72,    74,
      75,    67,    67,    67,    67,    67,    67,    67,    67,    67,
      67,    67,    71,    71,    33,    34,    34,    15,    67,    15,
      67,    58,    11,    15,    18,    71,    36,    77,    36,    77,
      15,    37,    33,    67,    34,    58,    58,    13,    73,    71,
      15,    37,    37,    36,    72,    77,    34,    73,    58,    15,
      37
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    38,    39,    40,    40,    40,    41,    41,    42,    43,
      43,    44,    45,    45,    46,    46,    46,    46,    46,    46,
      47,    47,    47,    47,    47,    48,    48,    48,    48,    48,
      49,    50,    50,    52,    51,    53,    51,    54,    51,    55,
      55,    56,    56,    57,    57,    57,    57,    57,    57,    57,
      57,    57,    57,    57,    58,    58,    58,    58,    58,    58,
      58,    58,    58,    58,    58,    59,    60,    60,    61,    62,
      62,    63,    64,    64,    65,    66,    67,    67,    67,    67,
      67,    67,    67,    67,    68,    68,    68,    69,    70,    70,
      71,    71,    71,    71,    71,    71,    71,    71,    71,    71,
      72,    72,    73,    73,    73,    73,    74,    74,    75,    75,
      76,    77,    77,    77,    77,    77
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     2,     2,     0,     2,     2,     2,     1,
       3,     2,     1,     3,     6,     6,     6,     6,     6,     6,
       4,     4,     2,     2,     0,     3,     3,     1,     1,     0,
       2,     2,     0,     0,     9,     0,     9,     0,     9,     4,
       3,     3,     1,     2,     2,     2,     2,     2,     4,     2,
       3,     4,     3,     0,     2,     2,     2,     2,     2,     4,
       2,     3,     4,     3,     0,     3,     2,     2,     2,     1,
       3,     2,     1,     3,     4,     1,     3,     3,     3,     3,
       3,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       3,     3,     3,     3,     3,     3,     3,     3,     2,     3,
       8,     6,     2,     4,     2,     0,     7,     5,     9,     7,
       5,     1,     1,     1,     1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

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
#ifndef YYINITDEPTH
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
static YYSIZE_T
yystrlen (const char *yystr)
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
static char *
yystpcpy (char *yydest, const char *yysrc)
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
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
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
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
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

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

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

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
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
  int yytoken = 0;
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

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
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
      yychar = yylex ();
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
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
     '$$ = $1'.

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
#line 66 "parser.y" /* yacc.c:1646  */
    {
					// cout<< "Reached Finally";
					if(! program_object.is_procedure_exists("main") ||
						program_object.get_procedure_prototype("main")->get_return_type() != void_data_type)
					{
						cerr << "cs316: Error Main should be defined and it's type should be void\n";
						exit(-1);
					}
					global_table->set_table_scope(global);
					program_object.set_global_table(*global_table);
					// program_object.set_global_table(*global_table);

				}
#line 1492 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 97 "parser.y" /* yacc.c:1646  */
    {
		string b = *(yyvsp[0].string_value) + "_";
		
		Symbol_Table_Entry* symbol = new Symbol_Table_Entry(b, int_data_type, yylineno);
		// printf("int: %d\n", scope);

		symbol->set_symbol_scope(global);
		global_table->push_symbol(symbol);
		// program_object.set_global_table(*global_table);
		
	}
#line 1508 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 109 "parser.y" /* yacc.c:1646  */
    {
		string b = *(yyvsp[0].string_value) + "_";
		Symbol_Table_Entry* symbol = new Symbol_Table_Entry(b, int_data_type, yylineno);
		// printf("int: %d\n", scope);


		symbol->set_symbol_scope(global);
		global_table->push_symbol(symbol);
		// program_object.set_global_table(*global_table);
	}
#line 1523 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 125 "parser.y" /* yacc.c:1646  */
    {
		string b = *(yyvsp[0].string_value) + "_";
		Symbol_Table_Entry* symbol = new Symbol_Table_Entry(b, double_data_type, yylineno);
		// printf("float: IN GLOBAL");
		symbol->set_symbol_scope(global);
		global_table->push_symbol(symbol);
		// program_object.set_global_table(*global_table);

	}
#line 1537 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 135 "parser.y" /* yacc.c:1646  */
    {
		string b = *(yyvsp[0].string_value) + "_";
		Symbol_Table_Entry* symbol = new Symbol_Table_Entry(b, double_data_type, yylineno);
		// printf("float: %d\n", scope);
		symbol->set_symbol_scope(global);
		global_table->push_symbol(symbol);
		// program_object.set_global_table(*global_table);
	}
#line 1550 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 149 "parser.y" /* yacc.c:1646  */
    {	
		string s =  *(yyvsp[-4].string_value)+ "_";
		// Procedure * new_procedure;
		if(program_object.variable_in_proc_map_check(s) && program_object.get_procedure_prototype(s)->is_proc_defined())
		{
			std::cerr << "cs316: Error in line: "<< yylineno<<", redefinition of function: " << s<<"\n";
			exit(-1);
		}
		else
		{
			procedure =  new Procedure(void_data_type, s, yylineno);
		}
		procedure->set_formal_param_list(*argument_list);
		program_object.set_proc_to_map(s, procedure);

	}
#line 1571 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 166 "parser.y" /* yacc.c:1646  */
    {	
		string s =  *(yyvsp[-4].string_value)+ "_";
		// Procedure * new_procedure;
		if(program_object.variable_in_proc_map_check(s) && program_object.get_procedure_prototype(s)->is_proc_defined())
		{
			std::cerr << "cs316: Error in line: "<< yylineno<<", redefinition of function: " << s<<"\n";
			exit(-1);
		}
		else
		{
			procedure =  new Procedure(int_data_type, s, yylineno);
		}
		procedure->set_formal_param_list(*argument_list);
		program_object.set_proc_to_map(s, procedure);

	}
#line 1592 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 183 "parser.y" /* yacc.c:1646  */
    {	
		string s =  *(yyvsp[-4].string_value)+ "_";
		// Procedure * new_procedure;
		if(program_object.variable_in_proc_map_check(s) && program_object.get_procedure_prototype(s)->is_proc_defined())
		{
			std::cerr << "cs316: Error in line: "<< yylineno<<", redefinition of function: " << s<<"\n";
			exit(-1);
		}
		else
		{
			procedure =  new Procedure(double_data_type, s, yylineno);
		}
		procedure->set_formal_param_list(*argument_list);
		program_object.set_proc_to_map(s, procedure);

	}
#line 1613 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 200 "parser.y" /* yacc.c:1646  */
    {	
		string s =  *(yyvsp[-4].string_value)+ "_";
		// Procedure * new_procedure;
		if(program_object.variable_in_proc_map_check(s) && program_object.get_procedure_prototype(s)->is_proc_defined())
		{
			std::cerr << "cs316: Error in line: "<< yylineno<<", redefinition of function: " << s<<"\n";
			exit(-1);
		}
		else
		{
			procedure =  new Procedure(void_data_type, s, yylineno);
		}
		procedure->set_formal_param_list(*argument_list);
		program_object.set_proc_to_map(s, procedure);

	}
#line 1634 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 217 "parser.y" /* yacc.c:1646  */
    {	
		string s =  *(yyvsp[-4].string_value)+ "_";
		// Procedure * new_procedure;
		if(program_object.variable_in_proc_map_check(s) && program_object.get_procedure_prototype(s)->is_proc_defined())
		{
			std::cerr << "cs316: Error in line: "<< yylineno<<", redefinition of function: " << s<<"\n";
			exit(-1);
		}
		else
		{
			procedure =  new Procedure(int_data_type, s, yylineno);
		}
		procedure->set_formal_param_list(*argument_list);
		program_object.set_proc_to_map(s, procedure);

	}
#line 1655 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 234 "parser.y" /* yacc.c:1646  */
    {	
		string s =  *(yyvsp[-4].string_value)+ "_";
		// Procedure * new_procedure;
		if(program_object.variable_in_proc_map_check(s) && program_object.get_procedure_prototype(s)->is_proc_defined())
		{
			std::cerr << "cs316: Error in line: "<< yylineno<<", redefinition of function: " << s<<"\n";
			exit(-1);
		}
		else
		{
			procedure =  new Procedure(double_data_type, s, yylineno);
		}
		procedure->set_formal_param_list(*argument_list);
		program_object.set_proc_to_map(s, procedure);

	}
#line 1676 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 257 "parser.y" /* yacc.c:1646  */
    {
		string b = *(yyvsp[0].string_value) + "_";
		// cout << "in int1: " << b;
		Symbol_Table_Entry* symbol = new Symbol_Table_Entry(b, int_data_type, yylineno);
		symbol->set_symbol_scope(local);

		argument_list->push_symbol(symbol);
		// $$ = argument_list;
	}
#line 1690 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 267 "parser.y" /* yacc.c:1646  */
    {
		string b = *(yyvsp[0].string_value) + "_";
		Symbol_Table_Entry* symbol = new Symbol_Table_Entry(b, double_data_type, yylineno);
		symbol->set_symbol_scope(local);

		argument_list->push_symbol(symbol);
		// $$ = argument_list;
	}
#line 1703 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 276 "parser.y" /* yacc.c:1646  */
    {
		string b = *(yyvsp[0].string_value) + "_";
		// cout << "in int: " << b;
		Symbol_Table_Entry* symbol = new Symbol_Table_Entry(b, int_data_type, yylineno);
		symbol->set_symbol_scope(local);
		argument_list = new Symbol_Table();
		argument_list->push_symbol(symbol);
		// $$ = argument_list;
	}
#line 1717 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 286 "parser.y" /* yacc.c:1646  */
    {	
		string b = *(yyvsp[0].string_value) + "_";
		Symbol_Table_Entry* symbol = new Symbol_Table_Entry(b, double_data_type, yylineno);
		symbol->set_symbol_scope(local);

		argument_list = new Symbol_Table();
		argument_list->push_symbol(symbol);
		// $$ = argument_list;
	}
#line 1731 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 296 "parser.y" /* yacc.c:1646  */
    {

		argument_list = new Symbol_Table();
		// $$ = argument_list;
	}
#line 1741 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 304 "parser.y" /* yacc.c:1646  */
    {
		arg_numbers  += 1;
		string b = "dummy" + to_string(arg_numbers);
		Symbol_Table_Entry* symbol = new Symbol_Table_Entry(b, int_data_type, yylineno);
		symbol->set_symbol_scope(local);

		argument_list->push_symbol(symbol);
		// $$ = argument_list;
	}
#line 1755 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 314 "parser.y" /* yacc.c:1646  */
    {
		arg_numbers  += 1;
		string b = "dummy" + to_string(arg_numbers);
		Symbol_Table_Entry* symbol = new Symbol_Table_Entry(b, double_data_type, yylineno);
		symbol->set_symbol_scope(local);

		argument_list->push_symbol(symbol);
		// $$ = argument_list;
	}
#line 1769 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 324 "parser.y" /* yacc.c:1646  */
    {
		arg_numbers = 1;
		string b = "dummy" + to_string(arg_numbers);
		Symbol_Table_Entry* symbol = new Symbol_Table_Entry(b, int_data_type, yylineno);
		symbol->set_symbol_scope(local);

		argument_list = new Symbol_Table();
		argument_list->push_symbol(symbol);
		// $$ = argument_list;
	}
#line 1784 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 335 "parser.y" /* yacc.c:1646  */
    {
		arg_numbers = 1;
		string b = "dummy" + to_string(arg_numbers);
		Symbol_Table_Entry* symbol = new Symbol_Table_Entry(b, double_data_type, yylineno);
		symbol->set_symbol_scope(local);

		argument_list = new Symbol_Table();
		argument_list->push_symbol(symbol);
		// $$ = argument_list;
	}
#line 1799 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 346 "parser.y" /* yacc.c:1646  */
    {
		arg_numbers = 0;
		argument_list = new Symbol_Table();
		// $$ = argument_list;
	}
#line 1809 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 363 "parser.y" /* yacc.c:1646  */
    {	
		ast_list->clear();
		local_table = new Symbol_Table();
		// string s =  *$2 + "_";
		string s;
		if (*(yyvsp[-4].string_value) == "main"){
			s = *(yyvsp[-4].string_value);
		}
		else{
			s =  *(yyvsp[-4].string_value) + "_";
		}
		// Procedure * new_procedure;
		// cout << "parsing func: " << *$2 ;
		if(program_object.variable_in_proc_map_check(s))
		{	
			// cout << "void func already exist: " << s ;
			procedure = program_object.get_procedure_prototype(s);
		}
		else
		{
			procedure =  new Procedure(void_data_type, s, yylineno);
		}

		if(procedure->is_proc_defined())
		{
			std::cerr << "cs316: Error in line: "<< yylineno<<", redefinition of function: " << s<<"\n";
			exit(-1);
		}
		else
		{
			procedure->set_formal_param_list(*argument_list);
			program_object.set_proc_to_map(s, procedure);

		}

	}
#line 1850 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 401 "parser.y" /* yacc.c:1646  */
    {	

		// printf("IN VOID FUNC00");
		// string s =  *$2 + "_";
		string s;
		if (*(yyvsp[-7].string_value) == "main"){
			s = *(yyvsp[-7].string_value);
		}
		else{
			s =  *(yyvsp[-7].string_value) + "_";
		}

		local_table->set_table_scope(local);
		procedure->set_local_list(*local_table);
		/*program_object.set_procedure(procedure, yylineno); */
		program_object.set_proc_to_map(s, procedure);
		procedure->set_proc_is_defined();

		(yyval.ast) = (yyvsp[-1].ast);
	}
#line 1875 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 424 "parser.y" /* yacc.c:1646  */
    {	
		// Procedure * new_procedure;
		// printf ("HHHEELLL ");
		ast_list->clear();
		// string s =  *$2+ "_";
		string s;
		if (*(yyvsp[-4].string_value) == "main"){
			s = *(yyvsp[-4].string_value);
		}
		else{
			s =  *(yyvsp[-4].string_value) + "_";
		}

		if(program_object.variable_in_proc_map_check(s))
		{
			procedure = program_object.get_procedure_prototype(s);
		}
		else
		{
			procedure =  new Procedure(int_data_type, s, yylineno);
		}

		if(procedure->is_proc_defined())
		{
			std::cerr << "cs316: Error in line: "<< yylineno<<", redefinition of function: " << s<<"\n";
			exit(-1);
		}
		else
		{
			procedure->set_formal_param_list(*argument_list);
			program_object.set_proc_to_map(s, procedure);

		}

	}
#line 1915 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 462 "parser.y" /* yacc.c:1646  */
    {	

		// string s =  *$2+ "_";
		string s;
		if (*(yyvsp[-7].string_value) == "main"){
			s = *(yyvsp[-7].string_value);
		}
		else{
			s =  *(yyvsp[-7].string_value) + "_";
		}
		// printf("IN INT FUNC00");
/*		Return_Ast* return_ast ;
		return_ast = new Return_Ast($10, s, yylineno);
		ast_list->push_back(return_ast);
		procedure->set_ast_list(*ast_list);*/
		// cout << "line 431";
		local_table->set_table_scope(local);
		procedure->set_local_list(*local_table);
		/*program_object.set_procedure(procedure, yylineno); */
		program_object.set_proc_to_map(s, procedure);
		procedure->set_proc_is_defined();
		(yyval.ast) = (yyvsp[-1].ast);
	}
#line 1943 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 487 "parser.y" /* yacc.c:1646  */
    {	
		// Procedure * new_procedure;
		ast_list->clear();
		// string s =  *$2+ "_";

		string s;
		if (*(yyvsp[-4].string_value) == "main"){
			s = *(yyvsp[-4].string_value);
		}
		else{
			s =  *(yyvsp[-4].string_value) + "_";
		}

		if(program_object.variable_in_proc_map_check(s))
		{
			procedure = program_object.get_procedure_prototype(s);
		}
		else
		{
			procedure =  new Procedure(double_data_type, s, yylineno);
		}

		if(procedure->is_proc_defined())
		{
			std::cerr << "cs316: Error in line: "<< yylineno<<", redefinition of function: " << s<<"\n";
			exit(-1);
		}
		else
		{
			procedure->set_formal_param_list(*argument_list);
			program_object.set_proc_to_map(s, procedure);

		}

	}
#line 1983 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 526 "parser.y" /* yacc.c:1646  */
    {	
		// string s =  *$2+ "_";

		string s;
		if (*(yyvsp[-7].string_value) == "main"){
			s = *(yyvsp[-7].string_value);
		}
		else{
			s =  *(yyvsp[-7].string_value) + "_";
		}
		// printf("IN FLOAT FUNC00");
		// Return_Ast* return_ast ;
		// return_ast = new Return_Ast($10, s, yylineno);
		// ast_list->push_back(return_ast);
		// procedure->set_ast_list(*ast_list);
		local_table->set_table_scope(local);
		procedure->set_local_list(*local_table);
		/*program_object.set_procedure(procedure, yylineno); */
		program_object.set_proc_to_map(s, procedure);
		procedure->set_proc_is_defined();
		(yyval.ast) = (yyvsp[-1].ast);
	}
#line 2010 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 563 "parser.y" /* yacc.c:1646  */
    {	
				string s = *(yyvsp[-3].string_value) + "_";
				if(!program_object.is_procedure_exists(s))
				{
					std::cerr << "cs316: Error in line: "<< yylineno<<", Procedure corresponding to the name: " << s << " is not found\n";
					exit(-1);
				}

				Call_Ast * call_ast = new Call_Ast(s, yylineno);
				// cout<< " param_list size during call "<< param_list->size()<<endl;
				call_ast->set_actual_param_list(*param_list);
				param_list->clear();



				(yyval.ast) = call_ast;
			}
#line 2032 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 581 "parser.y" /* yacc.c:1646  */
    {
				string s = *(yyvsp[-2].string_value);

				if(!program_object.is_procedure_exists(s))
				{
					std::cerr << "cs316: Error in line: "<< yylineno<<", Procedure corresponding to the name: " << s << " is not found\n";
					exit(-1);
				}

				Call_Ast * call_ast = new Call_Ast(s, yylineno);
				param_list->clear();
				call_ast->set_actual_param_list(*param_list);
				(yyval.ast) = call_ast;
			}
#line 2051 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 598 "parser.y" /* yacc.c:1646  */
    {
				param_list->push_back((yyvsp[0].ast));
				// cout<< "param_list size "<<param_list->size()<<endl;
			}
#line 2060 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 603 "parser.y" /* yacc.c:1646  */
    {
			// param_list->clear();
			param_list->push_back((yyvsp[0].ast));
			// cout<< "param_list size"<<" "<<param_list->size()<<endl;
		}
#line 2070 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 613 "parser.y" /* yacc.c:1646  */
    {	

		ast_list->push_back((yyvsp[0].ast));
		procedure->set_ast_list(*ast_list);
		// printf("pushing ast in list \n");
		// cout <<"assign here\n";

		Sequence_Ast* seq_ast = (Sequence_Ast*)(yyvsp[-1].ast);
		seq_ast->ast_push_back((yyvsp[0].ast));
		(yyval.ast) = seq_ast;
		
	}
#line 2087 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 627 "parser.y" /* yacc.c:1646  */
    {
		ast_list->push_back((yyvsp[0].ast));
		procedure->set_ast_list(*ast_list);
		Sequence_Ast* seq_ast = (Sequence_Ast*)(yyvsp[-1].ast);
		seq_ast->ast_push_back((yyvsp[0].ast));
		(yyval.ast) = seq_ast;
	}
#line 2099 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 635 "parser.y" /* yacc.c:1646  */
    {
		ast_list->push_back((yyvsp[0].ast));
		procedure->set_ast_list(*ast_list);
		Sequence_Ast* seq_ast = (Sequence_Ast*)(yyvsp[-1].ast);
		seq_ast->ast_push_back((yyvsp[0].ast));
		(yyval.ast) = seq_ast;
	}
#line 2111 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 643 "parser.y" /* yacc.c:1646  */
    {
		ast_list->push_back((yyvsp[0].ast));
		procedure->set_ast_list(*ast_list);
		Sequence_Ast* seq_ast = (Sequence_Ast*)(yyvsp[-1].ast);
		seq_ast->ast_push_back((yyvsp[0].ast));
		(yyval.ast) = seq_ast;
	}
#line 2123 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 652 "parser.y" /* yacc.c:1646  */
    {
		Sequence_Ast* seq_ast = (Sequence_Ast*)(yyvsp[-3].ast);
		// Return_Ast* return_Ast = new Return_Ast(yylineno);
		// seq_ast->ast_push_back(return_Ast);
		seq_ast->ast_push_back((yyvsp[-1].ast));
		// cout << "braces Here\n";
		(yyval.ast) = seq_ast;
	}
#line 2136 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 661 "parser.y" /* yacc.c:1646  */
    {
		ast_list->push_back((yyvsp[0].ast));
		procedure->set_ast_list(*ast_list);
		
		Sequence_Ast* seq_ast = (Sequence_Ast*)(yyvsp[-1].ast);
		seq_ast->ast_push_back((yyvsp[0].ast));
		(yyval.ast) = seq_ast;
	}
#line 2149 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 670 "parser.y" /* yacc.c:1646  */
    {
		ast_list->push_back((yyvsp[-1].ast));
		procedure->set_ast_list(*ast_list);
		
		Sequence_Ast* seq_ast = (Sequence_Ast*)(yyvsp[-2].ast);
		seq_ast->ast_push_back((yyvsp[-1].ast));
		(yyval.ast) = seq_ast;
	}
#line 2162 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 679 "parser.y" /* yacc.c:1646  */
    {
		if ((yyvsp[-1].ast)->get_data_type() != procedure->get_return_type())
		{
			std::cerr << "cs316: Error in line: "<< yylineno<<", procedure: " << procedure->get_proc_name()<<" return type not matching.\n";
			exit(-1);
		}

		Return_Ast* return_ast ;
		return_ast = new Return_Ast((yyvsp[-1].ast), procedure->get_proc_name(), yylineno);
		ast_list->push_back(return_ast);
		procedure->set_ast_list(*ast_list);
		
		Sequence_Ast* seq_ast = (Sequence_Ast*)(yyvsp[-3].ast);
		seq_ast->ast_push_back(return_ast);
		(yyval.ast) = seq_ast;
	}
#line 2183 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 696 "parser.y" /* yacc.c:1646  */
    {

		if (procedure->get_return_type() != void_data_type)
		{
			std::cerr << "cs316: Error in line: "<< yylineno<<", procedure: " << procedure->get_proc_name()<<" return type not matching.\n";
			exit(-1);
		}

		Return_Ast* return_ast ;
		return_ast = new Return_Ast((Ast *)(NULL), procedure->get_proc_name(), yylineno);
		ast_list->push_back(return_ast);
		procedure->set_ast_list(*ast_list);
		Sequence_Ast* seq_ast = (Sequence_Ast*)(yyvsp[-2].ast);
		seq_ast->ast_push_back(return_ast);
		(yyval.ast) = seq_ast;
	}
#line 2204 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 714 "parser.y" /* yacc.c:1646  */
    {
		Sequence_Ast* seq_ast = new Sequence_Ast(yylineno);
		(yyval.ast) = seq_ast;
	}
#line 2213 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 723 "parser.y" /* yacc.c:1646  */
    {	

		// ast_list->push_back($2);
		// procedure->set_ast_list(*ast_list);
		// printf("pushing ast in list \n");
		// cout <<"assign here\n";


		Sequence_Ast* seq_ast = (Sequence_Ast*)(yyvsp[-1].ast);
		seq_ast->ast_push_back((yyvsp[0].ast));
		(yyval.ast) = seq_ast;
		
	}
#line 2231 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 738 "parser.y" /* yacc.c:1646  */
    {
		// ast_list->push_back($2);
		// procedure->set_ast_list(*ast_list);
		Sequence_Ast* seq_ast = (Sequence_Ast*)(yyvsp[-1].ast);
		seq_ast->ast_push_back((yyvsp[0].ast));
		(yyval.ast) = seq_ast;
	}
#line 2243 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 746 "parser.y" /* yacc.c:1646  */
    {
		// ast_list->push_back($2);
		// procedure->set_ast_list(*ast_list);
		Sequence_Ast* seq_ast = (Sequence_Ast*)(yyvsp[-1].ast);
		seq_ast->ast_push_back((yyvsp[0].ast));
		// cout <<"if here\n";

		(yyval.ast) = seq_ast;
	}
#line 2257 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 756 "parser.y" /* yacc.c:1646  */
    {
		// ast_list->push_back($2);
		// procedure->set_ast_list(*ast_list);
		Sequence_Ast* seq_ast = (Sequence_Ast*)(yyvsp[-1].ast);
		seq_ast->ast_push_back((yyvsp[0].ast));
		(yyval.ast) = seq_ast;
	}
#line 2269 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 764 "parser.y" /* yacc.c:1646  */
    {
		Sequence_Ast* seq_ast = (Sequence_Ast*)(yyvsp[-3].ast);
		// Return_Ast* return_Ast = new Return_Ast(yylineno);
		// seq_ast->ast_push_back(return_Ast);
		seq_ast->ast_push_back((yyvsp[-1].ast));
		// cout << "braces Here\n";
		(yyval.ast) = seq_ast;
	}
#line 2282 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 773 "parser.y" /* yacc.c:1646  */
    {
		Sequence_Ast* seq_ast = (Sequence_Ast*)(yyvsp[-1].ast);
		seq_ast->ast_push_back((yyvsp[0].ast));
		(yyval.ast) = seq_ast;
	}
#line 2292 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 779 "parser.y" /* yacc.c:1646  */
    {
		// ast_list->push_back($2);
		// procedure->set_ast_list(*ast_list);
		
		Sequence_Ast* seq_ast = (Sequence_Ast*)(yyvsp[-2].ast);
		seq_ast->ast_push_back((yyvsp[-1].ast));
		(yyval.ast) = seq_ast;
	}
#line 2305 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 788 "parser.y" /* yacc.c:1646  */
    {

		if ((yyvsp[-1].ast)->get_data_type() != procedure->get_return_type())
		{
			std::cerr << "cs316: Error in line: "<< yylineno<<", procedure: " << procedure->get_proc_name()<<" return type not matching.\n";
			exit(-1);
		}

		Return_Ast* return_ast ;
		return_ast = new Return_Ast((yyvsp[-1].ast), procedure->get_proc_name(), yylineno);
		
		Sequence_Ast* seq_ast = (Sequence_Ast*)(yyvsp[-3].ast);
		seq_ast->ast_push_back(return_ast);
		(yyval.ast) = seq_ast;
	}
#line 2325 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 804 "parser.y" /* yacc.c:1646  */
    {

		if (procedure->get_return_type() != void_data_type)
		{
			std::cerr << "cs316: Error in line: "<< yylineno<<", procedure: " << procedure->get_proc_name()<<" return type not matching.\n";
			exit(-1);
		}

		Return_Ast* return_ast ;
		return_ast = new Return_Ast((Ast *)(NULL), procedure->get_proc_name(), yylineno);
		
		Sequence_Ast* seq_ast = (Sequence_Ast*)(yyvsp[-2].ast);
		seq_ast->ast_push_back(return_ast);
		(yyval.ast) = seq_ast;
	}
#line 2345 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 820 "parser.y" /* yacc.c:1646  */
    {
		Sequence_Ast* seq_ast = new Sequence_Ast(yylineno);
		(yyval.ast) = seq_ast;
	}
#line 2354 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 828 "parser.y" /* yacc.c:1646  */
    {
		// string b = *$2 + "_";
		Print_Ast * print_ast = new Print_Ast((yyvsp[-1].ast), yylineno);
		// cout << "print ast";
		(yyval.ast) = print_ast;
	}
#line 2365 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 845 "parser.y" /* yacc.c:1646  */
    {
		string b = *(yyvsp[0].string_value) + "_";
		
		Symbol_Table_Entry* symbol = new Symbol_Table_Entry(b, int_data_type, yylineno);
		// printf("int: %d\n", scope);

		// if (scope) 
		// {
		// 	symbol->set_symbol_scope(global);
		// 	global_table->push_symbol(symbol);
		// 	// program_object.set_global_table(*global_table);
		// }
		// else 
		// {
		symbol->set_symbol_scope(local);
		local_table->push_symbol(symbol);
			// procedure->set_local_list(*local_table);
		// }
		
	}
#line 2390 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 866 "parser.y" /* yacc.c:1646  */
    {
		string b = *(yyvsp[0].string_value) + "_";
		Symbol_Table_Entry* symbol = new Symbol_Table_Entry(b, int_data_type, yylineno);
		// printf("int: %d\n", scope);

		// if (scope) 
		// {
		// 	symbol->set_symbol_scope(global);
		// 	global_table->push_symbol(symbol);
		// 	// program_object.set_global_table(*global_table);
		// }
		// else 
		// {
		symbol->set_symbol_scope(local);
		local_table->push_symbol(symbol);
			// procedure->set_local_list(*local_table);
		// }
	}
#line 2413 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 890 "parser.y" /* yacc.c:1646  */
    {
		string b = *(yyvsp[0].string_value) + "_";
		Symbol_Table_Entry* symbol = new Symbol_Table_Entry(b, double_data_type, yylineno);
		// printf("float: %d\n", scope);
		// if (scope) 
		// {
		// 	symbol->set_symbol_scope(global);
		// 	global_table->push_symbol(symbol);
		// 	// program_object.set_global_table(*global_table);
		// }
		// else 
		// {
		symbol->set_symbol_scope(local);
		local_table->push_symbol(symbol);
			// procedure->set_local_list(*local_table);
		// }
	}
#line 2435 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 908 "parser.y" /* yacc.c:1646  */
    {
		string b = *(yyvsp[0].string_value) + "_";
		Symbol_Table_Entry* symbol = new Symbol_Table_Entry(b, double_data_type, yylineno);
		// printf("float: %d\n", scope);

		// if (scope) 
		// {
		// 	symbol->set_symbol_scope(global);
		// 	global_table->push_symbol(symbol);
		// 	// program_object.set_global_table(*global_table);
		// }
		// else 
		// {
		symbol->set_symbol_scope(local);
		local_table->push_symbol(symbol);
			// procedure->set_local_list(*local_table);
		// }
	}
#line 2458 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 937 "parser.y" /* yacc.c:1646  */
    {		
		// printf("creating ASSIGN ast\n");
		Assignment_Ast* assignment_ast =  new Assignment_Ast((yyvsp[-3].ast), (yyvsp[-1].ast), yylineno);
		//assignment_ast->set_data_type($3->get_data_type());

		(yyval.ast) = assignment_ast;
		(yyval.ast)->check_ast();

	}
#line 2472 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 970 "parser.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[-1].ast);
	}
#line 2480 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 975 "parser.y" /* yacc.c:1646  */
    { //$$ = $1 / $3; 
		// printf("creating / ARITHOP ast\n");
		Divide_Ast* divide_ast = new Divide_Ast((yyvsp[-2].ast), (yyvsp[0].ast), yylineno);
		// divide_ast->set_data_type($3->get_data_type());
		(yyval.ast) = divide_ast;
		(yyval.ast)->check_ast();

	}
#line 2493 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 985 "parser.y" /* yacc.c:1646  */
    { //$$ = $1 * $3;
		// printf("creating * ARITHOP ast\n");
		//Symbol_Table_Entry symbol = program_object.get_symbol_table_entry(*$3);
		Mult_Ast* mlus_ast = new Mult_Ast((yyvsp[-2].ast), (yyvsp[0].ast), yylineno);
		// mlus_ast->set_data_type($3->get_data_type());
		(yyval.ast) = mlus_ast;
		(yyval.ast)->check_ast();

	}
#line 2507 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 996 "parser.y" /* yacc.c:1646  */
    { //$$ = $1 + $3;
		// printf("creating + ARITHOP ast\n");
		//Symbol_Table_Entry symbol = program_object.get_symbol_table_entry(*$3);
		Plus_Ast* plus_ast = new Plus_Ast((yyvsp[-2].ast), (yyvsp[0].ast), yylineno);
		(yyval.ast) = plus_ast;
		(yyval.ast)->check_ast();

	}
#line 2520 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 1007 "parser.y" /* yacc.c:1646  */
    {// $$ = $1 - $3;
		// printf("creating - ARITHOP ast\n");
		Minus_Ast* minus_ast = new Minus_Ast((yyvsp[-2].ast), (yyvsp[0].ast), yylineno);
		(yyval.ast) = minus_ast;
		(yyval.ast)->check_ast();

	}
#line 2532 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 1015 "parser.y" /* yacc.c:1646  */
    {
			UMinus_Ast* un_ast = new UMinus_Ast((yyvsp[0].ast), NULL, yylineno);
			// un_ast->set_data_type($2->get_data_type());
			(yyval.ast) = un_ast;
			(yyval.ast)->check_ast();


		}
#line 2545 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 1033 "parser.y" /* yacc.c:1646  */
    { 
		// printf("creating NAME ast\n");
		Name_Ast* name_ast;
		string b = *(yyvsp[0].string_value) + "_";
		Symbol_Table_Entry* symbol = new Symbol_Table_Entry();
		// if(scope){
		// name_ast = new Name_Ast(b, global_table->get_symbol_table_entry(b), yylineno);
		// }
		// else{
		if(local_table->variable_in_symbol_list_check(b))
		{
			// *symbol = local_table->get_symbol_table_entry(b);
			name_ast = new Name_Ast(b, local_table->get_symbol_table_entry(b), yylineno);
		}
		else if (global_table->variable_in_symbol_list_check(b))
		{
			// *symbol = global_table->get_symbol_table_entry(b);
			name_ast = new Name_Ast(b, global_table->get_symbol_table_entry(b), yylineno);
		}
		else if (argument_list->variable_in_symbol_list_check(b)) 
		{
			name_ast = new Name_Ast(b, procedure->get_formal_param_list().get_symbol_table_entry(b), yylineno);
		}
		else
		{
			std::cerr << "cs316: Error in line: "<< yylineno<<", " << *yyval.string_value<<" Symbol not found in global_table-\n";
			exit(-1);
		} 

		// }
		// Name_Ast* name_ast = new Name_Ast(*$1, *symbol, yylineno);
		// name_ast->set_data_type(void_data_type);	
		(yyval.ast) = name_ast;
	}
#line 2584 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 1070 "parser.y" /* yacc.c:1646  */
    {	
		// printf("creating INT ast\n");
		Number_Ast<int>* number_ast = new Number_Ast<int>((yyvsp[0].integer_value), int_data_type, yylineno);
		number_ast->set_data_type(int_data_type);

		(yyval.ast) = number_ast;
		// $$->check_ast();

	}
#line 2598 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 1080 "parser.y" /* yacc.c:1646  */
    {	
		// printf("creating FLOAT ast\n");
		Number_Ast<double>* number_ast = new Number_Ast<double>((yyvsp[0].double_value), double_data_type, yylineno);
		number_ast->set_data_type(double_data_type);
		(yyval.ast) = number_ast;
		// $$->check_ast();

	}
#line 2611 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 1100 "parser.y" /* yacc.c:1646  */
    {
						// printf("HERE LESS_THAN_EQUAL");

						Relational_Expr_Ast* relational_expr_ast = new Relational_Expr_Ast((yyvsp[-2].ast), less_equalto, (yyvsp[0].ast),yylineno);
						(yyval.ast) = relational_expr_ast;
					}
#line 2622 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 1107 "parser.y" /* yacc.c:1646  */
    {
						Relational_Expr_Ast* relational_expr_ast = new Relational_Expr_Ast((yyvsp[-2].ast), less_than, (yyvsp[0].ast),yylineno);
						(yyval.ast) = relational_expr_ast;
					}
#line 2631 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 1112 "parser.y" /* yacc.c:1646  */
    {
						Relational_Expr_Ast* relational_expr_ast = new Relational_Expr_Ast((yyvsp[-2].ast), greater_than, (yyvsp[0].ast),yylineno);
						(yyval.ast) = relational_expr_ast;
					}
#line 2640 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 1117 "parser.y" /* yacc.c:1646  */
    {
						Relational_Expr_Ast* relational_expr_ast = new Relational_Expr_Ast((yyvsp[-2].ast), greater_equalto, (yyvsp[0].ast),yylineno);
						(yyval.ast) = relational_expr_ast;
					}
#line 2649 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 1122 "parser.y" /* yacc.c:1646  */
    {
						Relational_Expr_Ast* relational_expr_ast = new Relational_Expr_Ast((yyvsp[-2].ast), equalto, (yyvsp[0].ast),yylineno);
						(yyval.ast) = relational_expr_ast;
					}
#line 2658 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 1127 "parser.y" /* yacc.c:1646  */
    {
						Relational_Expr_Ast* relational_expr_ast = new Relational_Expr_Ast((yyvsp[-2].ast), not_equalto, (yyvsp[0].ast),yylineno);
						(yyval.ast) = relational_expr_ast;
					}
#line 2667 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 1132 "parser.y" /* yacc.c:1646  */
    {
						Logical_Expr_Ast* logical_expr_ast = new Logical_Expr_Ast((yyvsp[-2].ast), _logical_or, (yyvsp[0].ast), yylineno);
						logical_expr_ast->set_data_type(void_data_type);
						(yyval.ast) = logical_expr_ast;
					}
#line 2677 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 1138 "parser.y" /* yacc.c:1646  */
    {
						Logical_Expr_Ast* logical_expr_ast = new Logical_Expr_Ast((yyvsp[-2].ast), _logical_and, (yyvsp[0].ast), yylineno);
						logical_expr_ast->set_data_type(void_data_type);
						(yyval.ast) = logical_expr_ast;
					}
#line 2687 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 1144 "parser.y" /* yacc.c:1646  */
    {
						Logical_Expr_Ast* logical_expr_ast = new Logical_Expr_Ast(NULL, _logical_not, (yyvsp[0].ast), yylineno);
						logical_expr_ast->set_data_type(void_data_type);
						(yyval.ast) = logical_expr_ast;
					}
#line 2697 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 1150 "parser.y" /* yacc.c:1646  */
    {
						(yyval.ast) = (yyvsp[-1].ast);
					}
#line 2705 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 1160 "parser.y" /* yacc.c:1646  */
    {
				Selection_Statement_Ast* if_statement_exp = new Selection_Statement_Ast((yyvsp[-5].ast), (yyvsp[-2].ast), (yyvsp[0].ast), yylineno);
				(yyval.ast) = if_statement_exp;
				/*{
					code
				} */

			}
#line 2718 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 1172 "parser.y" /* yacc.c:1646  */
    {
				Selection_Statement_Ast* if_statement_exp = new Selection_Statement_Ast((yyvsp[-3].ast), (yyvsp[-1].ast), (yyvsp[0].ast), yylineno);
				(yyval.ast) = if_statement_exp;
				/*{
					code
				} */

			}
#line 2731 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 1193 "parser.y" /* yacc.c:1646  */
    {
						(yyval.ast) = (yyvsp[0].ast);
					}
#line 2739 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 1201 "parser.y" /* yacc.c:1646  */
    {
						(yyval.ast) = (yyvsp[-1].ast);
					}
#line 2747 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 1207 "parser.y" /* yacc.c:1646  */
    {
						(yyval.ast) = (yyvsp[0].ast);
					}
#line 2755 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 1211 "parser.y" /* yacc.c:1646  */
    {
						(yyval.ast) = NULL;
					}
#line 2763 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 1222 "parser.y" /* yacc.c:1646  */
    {
						Iteration_Statement_Ast *while_stat = new Iteration_Statement_Ast((yyvsp[-4].ast), (yyvsp[-1].ast), yylineno, false);
						(yyval.ast) = while_stat;
					}
#line 2772 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 1229 "parser.y" /* yacc.c:1646  */
    {
						Iteration_Statement_Ast *while_stat = new Iteration_Statement_Ast((yyvsp[-2].ast), (yyvsp[0].ast), yylineno, false);
						(yyval.ast) = while_stat;
					}
#line 2781 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 1241 "parser.y" /* yacc.c:1646  */
    {
						Iteration_Statement_Ast *while_stat = new Iteration_Statement_Ast((yyvsp[-2].ast), (yyvsp[-6].ast), yylineno, true);
						(yyval.ast) = while_stat;
					}
#line 2790 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 1249 "parser.y" /* yacc.c:1646  */
    {
						Iteration_Statement_Ast *while_stat = new Iteration_Statement_Ast((yyvsp[-2].ast), (yyvsp[-5].ast), yylineno, true);
						(yyval.ast) = while_stat;
					}
#line 2799 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 1256 "parser.y" /* yacc.c:1646  */
    {
						Conditional_Expression_Ast *cond_expr_ast = new Conditional_Expression_Ast((yyvsp[-4].ast), (yyvsp[-2].ast), (yyvsp[0].ast), yylineno);
						(yyval.ast) = cond_expr_ast;
					}
#line 2808 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 1262 "parser.y" /* yacc.c:1646  */
    {
						(yyval.ast) = (yyvsp[0].ast);
					}
#line 2816 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 1266 "parser.y" /* yacc.c:1646  */
    {
						(yyval.ast) = (yyvsp[0].ast);
					}
#line 2824 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 1270 "parser.y" /* yacc.c:1646  */
    {
						(yyval.ast) = (yyvsp[0].ast);
					}
#line 2832 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 1274 "parser.y" /* yacc.c:1646  */
    {
						(yyval.ast) = (yyvsp[0].ast);
					}
#line 2840 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 115:
#line 1278 "parser.y" /* yacc.c:1646  */
    {
						(yyval.ast) = (yyvsp[0].ast);
					}
#line 2848 "parser.tab.c" /* yacc.c:1646  */
    break;


#line 2852 "parser.tab.c" /* yacc.c:1646  */
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

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
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

  /* Do not reclaim the symbols of the rule whose action triggered
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
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

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

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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

#if !defined yyoverflow || YYERROR_VERBOSE
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
  /* Do not reclaim the symbols of the rule whose action triggered
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
  return yyresult;
}
#line 1283 "parser.y" /* yacc.c:1906  */



void yyerror( char * s){
	fflush(stdout);
	fprintf(stderr,"cs316: Error in line: %d, %s\n", yylineno,s);
	// exit(-1);
}
					
