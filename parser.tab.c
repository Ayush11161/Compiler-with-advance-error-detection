/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function declarations
void yyerror(const char* s);
int yylex(void);
extern int line_num;
extern FILE *yyin;

// Symbol table structure
typedef struct {
    char* name;
    int type;
    int scope;
    int is_initialized;
    int is_used;
} Symbol;

#define MAX_SYMBOLS 1000
Symbol symbol_table[MAX_SYMBOLS];
int symbol_count = 0;

// Error tracking
int error_count = 0;
void report_error(const char* msg, int line, int col);

// Function to add symbol to table
void add_symbol(char* name, int type, int scope) {
    if (symbol_count >= MAX_SYMBOLS) {
        report_error("Symbol table overflow", 0, 0);
        return;
    }
    symbol_table[symbol_count].name = strdup(name);
    symbol_table[symbol_count].type = type;
    symbol_table[symbol_count].scope = scope;
    symbol_table[symbol_count].is_initialized = 0;
    symbol_table[symbol_count].is_used = 0;
    symbol_count++;
}

// Function to find symbol
Symbol* find_symbol(char* name, int scope) {
    for (int i = symbol_count - 1; i >= 0; i--) {
        if (strcmp(symbol_table[i].name, name) == 0 && 
            symbol_table[i].scope <= scope) {
            return &symbol_table[i];
        }
    }
    return NULL;
}

#line 125 "parser.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "parser.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_IDENTIFIER = 3,                 /* IDENTIFIER  */
  YYSYMBOL_INTEGER_LITERAL = 4,            /* INTEGER_LITERAL  */
  YYSYMBOL_FLOAT_LITERAL = 5,              /* FLOAT_LITERAL  */
  YYSYMBOL_CHAR_LITERAL = 6,               /* CHAR_LITERAL  */
  YYSYMBOL_STRING_LITERAL = 7,             /* STRING_LITERAL  */
  YYSYMBOL_INT = 8,                        /* INT  */
  YYSYMBOL_CHAR = 9,                       /* CHAR  */
  YYSYMBOL_VOID = 10,                      /* VOID  */
  YYSYMBOL_FLOAT_TYPE = 11,                /* FLOAT_TYPE  */
  YYSYMBOL_IF = 12,                        /* IF  */
  YYSYMBOL_ELSE = 13,                      /* ELSE  */
  YYSYMBOL_WHILE = 14,                     /* WHILE  */
  YYSYMBOL_FOR = 15,                       /* FOR  */
  YYSYMBOL_RETURN = 16,                    /* RETURN  */
  YYSYMBOL_STRUCT = 17,                    /* STRUCT  */
  YYSYMBOL_TYPEDEF = 18,                   /* TYPEDEF  */
  YYSYMBOL_CONST = 19,                     /* CONST  */
  YYSYMBOL_STATIC = 20,                    /* STATIC  */
  YYSYMBOL_EXTERN = 21,                    /* EXTERN  */
  YYSYMBOL_SIZEOF = 22,                    /* SIZEOF  */
  YYSYMBOL_PLUS = 23,                      /* PLUS  */
  YYSYMBOL_MINUS = 24,                     /* MINUS  */
  YYSYMBOL_MULTIPLY = 25,                  /* MULTIPLY  */
  YYSYMBOL_DIVIDE = 26,                    /* DIVIDE  */
  YYSYMBOL_MODULO = 27,                    /* MODULO  */
  YYSYMBOL_ASSIGN = 28,                    /* ASSIGN  */
  YYSYMBOL_EQUAL = 29,                     /* EQUAL  */
  YYSYMBOL_NOT_EQUAL = 30,                 /* NOT_EQUAL  */
  YYSYMBOL_LESS = 31,                      /* LESS  */
  YYSYMBOL_LESS_EQUAL = 32,                /* LESS_EQUAL  */
  YYSYMBOL_GREATER = 33,                   /* GREATER  */
  YYSYMBOL_GREATER_EQUAL = 34,             /* GREATER_EQUAL  */
  YYSYMBOL_AND = 35,                       /* AND  */
  YYSYMBOL_OR = 36,                        /* OR  */
  YYSYMBOL_NOT = 37,                       /* NOT  */
  YYSYMBOL_BITWISE_AND = 38,               /* BITWISE_AND  */
  YYSYMBOL_BITWISE_OR = 39,                /* BITWISE_OR  */
  YYSYMBOL_BITWISE_XOR = 40,               /* BITWISE_XOR  */
  YYSYMBOL_BITWISE_NOT = 41,               /* BITWISE_NOT  */
  YYSYMBOL_LEFT_SHIFT = 42,                /* LEFT_SHIFT  */
  YYSYMBOL_RIGHT_SHIFT = 43,               /* RIGHT_SHIFT  */
  YYSYMBOL_INCREMENT = 44,                 /* INCREMENT  */
  YYSYMBOL_DECREMENT = 45,                 /* DECREMENT  */
  YYSYMBOL_ARROW = 46,                     /* ARROW  */
  YYSYMBOL_DOT = 47,                       /* DOT  */
  YYSYMBOL_SEMICOLON = 48,                 /* SEMICOLON  */
  YYSYMBOL_COMMA = 49,                     /* COMMA  */
  YYSYMBOL_LEFT_PAREN = 50,                /* LEFT_PAREN  */
  YYSYMBOL_RIGHT_PAREN = 51,               /* RIGHT_PAREN  */
  YYSYMBOL_LEFT_BRACE = 52,                /* LEFT_BRACE  */
  YYSYMBOL_RIGHT_BRACE = 53,               /* RIGHT_BRACE  */
  YYSYMBOL_LEFT_BRACKET = 54,              /* LEFT_BRACKET  */
  YYSYMBOL_RIGHT_BRACKET = 55,             /* RIGHT_BRACKET  */
  YYSYMBOL_COLON = 56,                     /* COLON  */
  YYSYMBOL_QUESTION = 57,                  /* QUESTION  */
  YYSYMBOL_YYACCEPT = 58,                  /* $accept  */
  YYSYMBOL_program = 59,                   /* program  */
  YYSYMBOL_external_declaration = 60,      /* external_declaration  */
  YYSYMBOL_function_definition = 61,       /* function_definition  */
  YYSYMBOL_parameter_list = 62,            /* parameter_list  */
  YYSYMBOL_parameter_declaration = 63,     /* parameter_declaration  */
  YYSYMBOL_type_specifier = 64,            /* type_specifier  */
  YYSYMBOL_declaration = 65,               /* declaration  */
  YYSYMBOL_compound_statement = 66,        /* compound_statement  */
  YYSYMBOL_declaration_list = 67,          /* declaration_list  */
  YYSYMBOL_statement_list = 68,            /* statement_list  */
  YYSYMBOL_statement = 69,                 /* statement  */
  YYSYMBOL_expression_statement = 70,      /* expression_statement  */
  YYSYMBOL_selection_statement = 71,       /* selection_statement  */
  YYSYMBOL_iteration_statement = 72,       /* iteration_statement  */
  YYSYMBOL_jump_statement = 73,            /* jump_statement  */
  YYSYMBOL_expression = 74,                /* expression  */
  YYSYMBOL_assignment_expression = 75,     /* assignment_expression  */
  YYSYMBOL_logical_or_expression = 76,     /* logical_or_expression  */
  YYSYMBOL_logical_and_expression = 77,    /* logical_and_expression  */
  YYSYMBOL_equality_expression = 78,       /* equality_expression  */
  YYSYMBOL_relational_expression = 79,     /* relational_expression  */
  YYSYMBOL_additive_expression = 80,       /* additive_expression  */
  YYSYMBOL_multiplicative_expression = 81, /* multiplicative_expression  */
  YYSYMBOL_unary_expression = 82,          /* unary_expression  */
  YYSYMBOL_postfix_expression = 83,        /* postfix_expression  */
  YYSYMBOL_primary_expression = 84,        /* primary_expression  */
  YYSYMBOL_argument_expression_list = 85   /* argument_expression_list  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

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


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
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

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
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
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  10
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   267

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  58
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  28
/* YYNRULES -- Number of rules.  */
#define YYNRULES  81
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  141

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   312


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
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
      55,    56,    57
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   118,   118,   119,   123,   124,   128,   142,   143,   144,
     148,   156,   157,   158,   159,   163,   174,   191,   195,   196,
     197,   201,   202,   203,   207,   208,   209,   210,   211,   215,
     216,   220,   221,   225,   226,   227,   231,   232,   236,   237,
     241,   242,   256,   257,   261,   262,   266,   267,   268,   272,
     273,   274,   275,   276,   280,   281,   282,   286,   287,   288,
     289,   293,   294,   295,   296,   297,   301,   302,   303,   304,
     305,   306,   307,   311,   325,   326,   327,   328,   329,   333,
     334,   335
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "IDENTIFIER",
  "INTEGER_LITERAL", "FLOAT_LITERAL", "CHAR_LITERAL", "STRING_LITERAL",
  "INT", "CHAR", "VOID", "FLOAT_TYPE", "IF", "ELSE", "WHILE", "FOR",
  "RETURN", "STRUCT", "TYPEDEF", "CONST", "STATIC", "EXTERN", "SIZEOF",
  "PLUS", "MINUS", "MULTIPLY", "DIVIDE", "MODULO", "ASSIGN", "EQUAL",
  "NOT_EQUAL", "LESS", "LESS_EQUAL", "GREATER", "GREATER_EQUAL", "AND",
  "OR", "NOT", "BITWISE_AND", "BITWISE_OR", "BITWISE_XOR", "BITWISE_NOT",
  "LEFT_SHIFT", "RIGHT_SHIFT", "INCREMENT", "DECREMENT", "ARROW", "DOT",
  "SEMICOLON", "COMMA", "LEFT_PAREN", "RIGHT_PAREN", "LEFT_BRACE",
  "RIGHT_BRACE", "LEFT_BRACKET", "RIGHT_BRACKET", "COLON", "QUESTION",
  "$accept", "program", "external_declaration", "function_definition",
  "parameter_list", "parameter_declaration", "type_specifier",
  "declaration", "compound_statement", "declaration_list",
  "statement_list", "statement", "expression_statement",
  "selection_statement", "iteration_statement", "jump_statement",
  "expression", "assignment_expression", "logical_or_expression",
  "logical_and_expression", "equality_expression", "relational_expression",
  "additive_expression", "multiplicative_expression", "unary_expression",
  "postfix_expression", "primary_expression", "argument_expression_list", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-101)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      81,  -101,  -101,  -101,  -101,    86,  -101,  -101,     5,  -101,
    -101,  -101,   -27,   189,  -101,    81,     8,  -101,  -101,  -101,
    -101,   217,   217,   217,   217,   189,    34,  -101,    -4,     6,
     107,    83,   127,    23,  -101,   102,  -101,   -31,  -101,    49,
     189,  -101,  -101,  -101,  -101,  -101,     4,  -101,   189,   217,
     217,   217,   217,   217,   217,   217,   217,   217,   217,   217,
     217,   217,  -101,  -101,    56,    58,   189,   189,    81,    22,
    -101,  -101,  -101,  -101,     6,   107,    83,    83,   127,   127,
     127,   127,    23,    23,  -101,  -101,  -101,  -101,  -101,  -101,
      29,    -9,  -101,    81,  -101,   189,  -101,  -101,    76,  -101,
      61,  -101,   -19,    37,    53,    60,   167,  -101,  -101,  -101,
      10,  -101,  -101,  -101,  -101,  -101,   106,   189,   189,   177,
    -101,   110,  -101,  -101,  -101,    50,    57,   177,  -101,   116,
     116,   138,    87,  -101,   116,    84,   116,  -101,   116,  -101,
    -101
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    11,    12,    13,    14,     0,     2,     4,     0,     5,
       1,     3,     0,     0,    15,     9,    73,    74,    75,    76,
      77,     0,     0,     0,     0,     0,     0,    38,    40,    42,
      44,    46,    49,    54,    57,    61,    66,     0,     7,     0,
       0,    73,    62,    63,    64,    65,     0,    16,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    71,    72,     0,     0,    81,     0,     0,     0,
      10,    41,    78,    39,    43,    45,    47,    48,    50,    52,
      51,    53,    55,    56,    58,    59,    60,    70,    69,    79,
       0,     0,     8,    20,     6,     0,    68,    67,     0,    18,
      23,    80,     0,     0,     0,     0,     0,    30,    19,    25,
       0,    21,    24,    26,    27,    28,     0,     0,     0,     0,
      37,     0,    17,    22,    29,     0,     0,     0,    36,     0,
       0,     0,    31,    33,     0,     0,     0,    34,     0,    32,
      35
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -101,  -101,   124,  -101,  -101,    39,   -12,   -55,    43,  -101,
    -101,   -99,  -100,  -101,  -101,  -101,   -13,   -38,  -101,    85,
      88,   125,    71,   128,   -17,  -101,  -101,  -101
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     5,     6,     7,    37,    38,     8,     9,   109,   100,
     110,   111,   112,   113,   114,   115,   116,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    90
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      26,    13,    71,    39,    42,    43,    44,    45,    12,    13,
      73,   123,    46,    16,    17,    18,    19,    20,    68,   127,
      69,    14,   103,    15,   104,   105,   106,   131,    89,    14,
     132,   133,    49,    21,    22,   137,    40,   139,    99,   140,
      48,    50,    84,    85,    86,   108,    97,    23,    59,    60,
      61,    24,    70,    48,    91,    72,    39,   101,   107,    87,
      25,    88,    93,   122,    16,    17,    18,    19,    20,     1,
       2,     3,     4,   103,    93,   104,   105,   106,    95,   102,
      96,    98,    47,    48,    21,    22,    10,   117,    98,     1,
       2,     3,     4,   121,     1,     2,     3,     4,    23,    48,
     136,   129,    24,   118,   125,   126,    48,    92,   130,   107,
     119,    25,    94,    93,    53,    54,    55,    56,   135,    16,
      17,    18,    19,    20,    78,    79,    80,    81,   103,    11,
     104,   105,   106,    48,    74,   138,    51,    52,    75,    21,
      22,    16,    17,    18,    19,    20,    62,    63,    64,    65,
      57,    58,    66,    23,   124,    48,    67,    24,   128,    48,
       0,    21,    22,     0,   107,     0,    25,     0,    93,     0,
      16,    17,    18,    19,    20,    23,    76,    77,     0,    24,
      16,    17,    18,    19,    20,    82,    83,     0,    25,   134,
      21,    22,    16,    17,    18,    19,    20,     0,     0,     0,
      21,    22,     0,     0,    23,     0,     0,     0,    24,     0,
       0,     0,    21,    22,    23,   120,     0,    25,    24,     0,
      41,    17,    18,    19,    20,   107,    23,    25,     0,     0,
      24,     0,     0,     0,     0,     0,     0,     0,     0,    25,
      21,    22,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    23,     0,     0,     0,    24,     0,
       0,     0,     0,     0,     0,     0,     0,    25
};

static const yytype_int16 yycheck[] =
{
      13,    28,    40,    15,    21,    22,    23,    24,     3,    28,
      48,   110,    25,     3,     4,     5,     6,     7,    49,   119,
      51,    48,    12,    50,    14,    15,    16,   127,    66,    48,
     129,   130,    36,    23,    24,   134,    28,   136,    93,   138,
      49,    35,    59,    60,    61,   100,    55,    37,    25,    26,
      27,    41,     3,    49,    67,    51,    68,    95,    48,     3,
      50,     3,    52,    53,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    52,    14,    15,    16,    49,     3,
      51,    93,    48,    49,    23,    24,     0,    50,   100,     8,
       9,    10,    11,   106,     8,     9,    10,    11,    37,    49,
      13,    51,    41,    50,   117,   118,    49,    68,    51,    48,
      50,    50,    69,    52,    31,    32,    33,    34,   131,     3,
       4,     5,     6,     7,    53,    54,    55,    56,    12,     5,
      14,    15,    16,    49,    49,    51,    29,    30,    50,    23,
      24,     3,     4,     5,     6,     7,    44,    45,    46,    47,
      23,    24,    50,    37,    48,    49,    54,    41,    48,    49,
      -1,    23,    24,    -1,    48,    -1,    50,    -1,    52,    -1,
       3,     4,     5,     6,     7,    37,    51,    52,    -1,    41,
       3,     4,     5,     6,     7,    57,    58,    -1,    50,    51,
      23,    24,     3,     4,     5,     6,     7,    -1,    -1,    -1,
      23,    24,    -1,    -1,    37,    -1,    -1,    -1,    41,    -1,
      -1,    -1,    23,    24,    37,    48,    -1,    50,    41,    -1,
       3,     4,     5,     6,     7,    48,    37,    50,    -1,    -1,
      41,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    50,
      23,    24,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    37,    -1,    -1,    -1,    41,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    50
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     8,     9,    10,    11,    59,    60,    61,    64,    65,
       0,    60,     3,    28,    48,    50,     3,     4,     5,     6,
       7,    23,    24,    37,    41,    50,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    62,    63,    64,
      28,     3,    82,    82,    82,    82,    74,    48,    49,    36,
      35,    29,    30,    31,    32,    33,    34,    23,    24,    25,
      26,    27,    44,    45,    46,    47,    50,    54,    49,    51,
       3,    75,    51,    75,    77,    78,    79,    79,    80,    80,
      80,    80,    81,    81,    82,    82,    82,     3,     3,    75,
      85,    74,    63,    52,    66,    49,    51,    55,    64,    65,
      67,    75,     3,    12,    14,    15,    16,    48,    65,    66,
      68,    69,    70,    71,    72,    73,    74,    50,    50,    50,
      48,    74,    53,    69,    48,    74,    74,    70,    48,    51,
      51,    70,    69,    69,    51,    74,    13,    69,    51,    69,
      69
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    58,    59,    59,    60,    60,    61,    62,    62,    62,
      63,    64,    64,    64,    64,    65,    65,    66,    67,    67,
      67,    68,    68,    68,    69,    69,    69,    69,    69,    70,
      70,    71,    71,    72,    72,    72,    73,    73,    74,    74,
      75,    75,    76,    76,    77,    77,    78,    78,    78,    79,
      79,    79,    79,    79,    80,    80,    80,    81,    81,    81,
      81,    82,    82,    82,    82,    82,    83,    83,    83,    83,
      83,    83,    83,    84,    84,    84,    84,    84,    84,    85,
      85,    85
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     6,     1,     3,     0,
       2,     1,     1,     1,     1,     3,     5,     4,     1,     2,
       0,     1,     2,     0,     1,     1,     1,     1,     1,     2,
       1,     5,     7,     5,     6,     7,     3,     2,     1,     3,
       1,     3,     1,     3,     1,     3,     1,     3,     3,     1,
       3,     3,     3,     3,     1,     3,     3,     1,     3,     3,
       3,     1,     2,     2,     2,     2,     1,     4,     4,     3,
       3,     2,     2,     1,     1,     1,     1,     1,     3,     1,
       3,     0
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
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

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


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




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
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
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
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
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
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
  case 2: /* program: external_declaration  */
#line 118 "parser.y"
                           { (yyval.int_val) = (yyvsp[0].int_val); }
#line 1328 "parser.tab.c"
    break;

  case 3: /* program: program external_declaration  */
#line 119 "parser.y"
                                   { (yyval.int_val) = (yyvsp[0].int_val); }
#line 1334 "parser.tab.c"
    break;

  case 4: /* external_declaration: function_definition  */
#line 123 "parser.y"
                          { (yyval.int_val) = (yyvsp[0].int_val); }
#line 1340 "parser.tab.c"
    break;

  case 5: /* external_declaration: declaration  */
#line 124 "parser.y"
                  { (yyval.int_val) = (yyvsp[0].int_val); }
#line 1346 "parser.tab.c"
    break;

  case 6: /* function_definition: type_specifier IDENTIFIER LEFT_PAREN parameter_list RIGHT_PAREN compound_statement  */
#line 129 "parser.y"
    {
        // Check for function redefinition
        Symbol* sym = find_symbol((yyvsp[-4].string_val), 0);
        if (sym != NULL) {
            report_error("Function redefinition", line_num, 0);
        } else {
            add_symbol((yyvsp[-4].string_val), (yyvsp[-5].int_val), 0);
        }
        (yyval.int_val) = (yyvsp[-5].int_val);
    }
#line 1361 "parser.tab.c"
    break;

  case 7: /* parameter_list: parameter_declaration  */
#line 142 "parser.y"
                            { (yyval.int_val) = (yyvsp[0].int_val); }
#line 1367 "parser.tab.c"
    break;

  case 8: /* parameter_list: parameter_list COMMA parameter_declaration  */
#line 143 "parser.y"
                                                 { (yyval.int_val) = (yyvsp[0].int_val); }
#line 1373 "parser.tab.c"
    break;

  case 9: /* parameter_list: %empty  */
#line 144 "parser.y"
                  { (yyval.int_val) = 0; }
#line 1379 "parser.tab.c"
    break;

  case 10: /* parameter_declaration: type_specifier IDENTIFIER  */
#line 149 "parser.y"
    {
        add_symbol((yyvsp[0].string_val), (yyvsp[-1].int_val), 1);  // Add parameter to symbol table
        (yyval.int_val) = (yyvsp[-1].int_val);
    }
#line 1388 "parser.tab.c"
    break;

  case 11: /* type_specifier: INT  */
#line 156 "parser.y"
              { (yyval.int_val) = 1; }
#line 1394 "parser.tab.c"
    break;

  case 12: /* type_specifier: CHAR  */
#line 157 "parser.y"
              { (yyval.int_val) = 2; }
#line 1400 "parser.tab.c"
    break;

  case 13: /* type_specifier: VOID  */
#line 158 "parser.y"
              { (yyval.int_val) = 3; }
#line 1406 "parser.tab.c"
    break;

  case 14: /* type_specifier: FLOAT_TYPE  */
#line 159 "parser.y"
                 { (yyval.int_val) = 4; }
#line 1412 "parser.tab.c"
    break;

  case 15: /* declaration: type_specifier IDENTIFIER SEMICOLON  */
#line 164 "parser.y"
    {
        // Check for variable redefinition
        Symbol* sym = find_symbol((yyvsp[-1].string_val), 0);
        if (sym != NULL) {
            report_error("Variable redefinition", line_num, 0);
        } else {
            add_symbol((yyvsp[-1].string_val), (yyvsp[-2].int_val), 0);
        }
        (yyval.int_val) = (yyvsp[-2].int_val);
    }
#line 1427 "parser.tab.c"
    break;

  case 16: /* declaration: type_specifier IDENTIFIER ASSIGN expression SEMICOLON  */
#line 175 "parser.y"
    {
        // Check for variable redefinition and type compatibility
        Symbol* sym = find_symbol((yyvsp[-3].string_val), 0);
        if (sym != NULL) {
            report_error("Variable redefinition", line_num, 0);
        } else {
            add_symbol((yyvsp[-3].string_val), (yyvsp[-4].int_val), 0);
            if ((yyvsp[-4].int_val) != (yyvsp[-1].int_val)) {
                report_error("Type mismatch in assignment", line_num, 0);
            }
        }
        (yyval.int_val) = (yyvsp[-4].int_val);
    }
#line 1445 "parser.tab.c"
    break;

  case 17: /* compound_statement: LEFT_BRACE declaration_list statement_list RIGHT_BRACE  */
#line 191 "parser.y"
                                                             { (yyval.int_val) = 0; }
#line 1451 "parser.tab.c"
    break;

  case 18: /* declaration_list: declaration  */
#line 195 "parser.y"
                  { (yyval.int_val) = (yyvsp[0].int_val); }
#line 1457 "parser.tab.c"
    break;

  case 19: /* declaration_list: declaration_list declaration  */
#line 196 "parser.y"
                                   { (yyval.int_val) = (yyvsp[0].int_val); }
#line 1463 "parser.tab.c"
    break;

  case 20: /* declaration_list: %empty  */
#line 197 "parser.y"
                  { (yyval.int_val) = 0; }
#line 1469 "parser.tab.c"
    break;

  case 21: /* statement_list: statement  */
#line 201 "parser.y"
                { (yyval.int_val) = (yyvsp[0].int_val); }
#line 1475 "parser.tab.c"
    break;

  case 22: /* statement_list: statement_list statement  */
#line 202 "parser.y"
                               { (yyval.int_val) = (yyvsp[0].int_val); }
#line 1481 "parser.tab.c"
    break;

  case 23: /* statement_list: %empty  */
#line 203 "parser.y"
                  { (yyval.int_val) = 0; }
#line 1487 "parser.tab.c"
    break;

  case 24: /* statement: expression_statement  */
#line 207 "parser.y"
                           { (yyval.int_val) = (yyvsp[0].int_val); }
#line 1493 "parser.tab.c"
    break;

  case 25: /* statement: compound_statement  */
#line 208 "parser.y"
                         { (yyval.int_val) = (yyvsp[0].int_val); }
#line 1499 "parser.tab.c"
    break;

  case 26: /* statement: selection_statement  */
#line 209 "parser.y"
                          { (yyval.int_val) = (yyvsp[0].int_val); }
#line 1505 "parser.tab.c"
    break;

  case 27: /* statement: iteration_statement  */
#line 210 "parser.y"
                          { (yyval.int_val) = (yyvsp[0].int_val); }
#line 1511 "parser.tab.c"
    break;

  case 28: /* statement: jump_statement  */
#line 211 "parser.y"
                     { (yyval.int_val) = (yyvsp[0].int_val); }
#line 1517 "parser.tab.c"
    break;

  case 29: /* expression_statement: expression SEMICOLON  */
#line 215 "parser.y"
                           { (yyval.int_val) = (yyvsp[-1].int_val); }
#line 1523 "parser.tab.c"
    break;

  case 30: /* expression_statement: SEMICOLON  */
#line 216 "parser.y"
                { (yyval.int_val) = 0; }
#line 1529 "parser.tab.c"
    break;

  case 31: /* selection_statement: IF LEFT_PAREN expression RIGHT_PAREN statement  */
#line 220 "parser.y"
                                                     { (yyval.int_val) = (yyvsp[-2].int_val); }
#line 1535 "parser.tab.c"
    break;

  case 32: /* selection_statement: IF LEFT_PAREN expression RIGHT_PAREN statement ELSE statement  */
#line 221 "parser.y"
                                                                    { (yyval.int_val) = (yyvsp[-4].int_val); }
#line 1541 "parser.tab.c"
    break;

  case 33: /* iteration_statement: WHILE LEFT_PAREN expression RIGHT_PAREN statement  */
#line 225 "parser.y"
                                                        { (yyval.int_val) = (yyvsp[-2].int_val); }
#line 1547 "parser.tab.c"
    break;

  case 34: /* iteration_statement: FOR LEFT_PAREN expression_statement expression_statement RIGHT_PAREN statement  */
#line 226 "parser.y"
                                                                                     { (yyval.int_val) = 0; }
#line 1553 "parser.tab.c"
    break;

  case 35: /* iteration_statement: FOR LEFT_PAREN expression_statement expression_statement expression RIGHT_PAREN statement  */
#line 227 "parser.y"
                                                                                                { (yyval.int_val) = (yyvsp[-2].int_val); }
#line 1559 "parser.tab.c"
    break;

  case 36: /* jump_statement: RETURN expression SEMICOLON  */
#line 231 "parser.y"
                                  { (yyval.int_val) = (yyvsp[-1].int_val); }
#line 1565 "parser.tab.c"
    break;

  case 37: /* jump_statement: RETURN SEMICOLON  */
#line 232 "parser.y"
                       { (yyval.int_val) = 0; }
#line 1571 "parser.tab.c"
    break;

  case 38: /* expression: assignment_expression  */
#line 236 "parser.y"
                            { (yyval.int_val) = (yyvsp[0].int_val); }
#line 1577 "parser.tab.c"
    break;

  case 39: /* expression: expression COMMA assignment_expression  */
#line 237 "parser.y"
                                             { (yyval.int_val) = (yyvsp[0].int_val); }
#line 1583 "parser.tab.c"
    break;

  case 40: /* assignment_expression: logical_or_expression  */
#line 241 "parser.y"
                            { (yyval.int_val) = (yyvsp[0].int_val); }
#line 1589 "parser.tab.c"
    break;

  case 41: /* assignment_expression: IDENTIFIER ASSIGN assignment_expression  */
#line 243 "parser.y"
    {
        // Check if variable is declared and initialized
        Symbol* sym = find_symbol((yyvsp[-2].string_val), 0);
        if (sym == NULL) {
            report_error("Undefined variable", line_num, 0);
        } else {
            sym->is_initialized = 1;
        }
        (yyval.int_val) = (yyvsp[0].int_val);
    }
#line 1604 "parser.tab.c"
    break;

  case 42: /* logical_or_expression: logical_and_expression  */
#line 256 "parser.y"
                             { (yyval.int_val) = (yyvsp[0].int_val); }
#line 1610 "parser.tab.c"
    break;

  case 43: /* logical_or_expression: logical_or_expression OR logical_and_expression  */
#line 257 "parser.y"
                                                      { (yyval.int_val) = (yyvsp[-2].int_val); }
#line 1616 "parser.tab.c"
    break;

  case 44: /* logical_and_expression: equality_expression  */
#line 261 "parser.y"
                          { (yyval.int_val) = (yyvsp[0].int_val); }
#line 1622 "parser.tab.c"
    break;

  case 45: /* logical_and_expression: logical_and_expression AND equality_expression  */
#line 262 "parser.y"
                                                     { (yyval.int_val) = (yyvsp[-2].int_val); }
#line 1628 "parser.tab.c"
    break;

  case 46: /* equality_expression: relational_expression  */
#line 266 "parser.y"
                            { (yyval.int_val) = (yyvsp[0].int_val); }
#line 1634 "parser.tab.c"
    break;

  case 47: /* equality_expression: equality_expression EQUAL relational_expression  */
#line 267 "parser.y"
                                                      { (yyval.int_val) = (yyvsp[-2].int_val); }
#line 1640 "parser.tab.c"
    break;

  case 48: /* equality_expression: equality_expression NOT_EQUAL relational_expression  */
#line 268 "parser.y"
                                                          { (yyval.int_val) = (yyvsp[-2].int_val); }
#line 1646 "parser.tab.c"
    break;

  case 49: /* relational_expression: additive_expression  */
#line 272 "parser.y"
                          { (yyval.int_val) = (yyvsp[0].int_val); }
#line 1652 "parser.tab.c"
    break;

  case 50: /* relational_expression: relational_expression LESS additive_expression  */
#line 273 "parser.y"
                                                     { (yyval.int_val) = (yyvsp[-2].int_val); }
#line 1658 "parser.tab.c"
    break;

  case 51: /* relational_expression: relational_expression GREATER additive_expression  */
#line 274 "parser.y"
                                                        { (yyval.int_val) = (yyvsp[-2].int_val); }
#line 1664 "parser.tab.c"
    break;

  case 52: /* relational_expression: relational_expression LESS_EQUAL additive_expression  */
#line 275 "parser.y"
                                                           { (yyval.int_val) = (yyvsp[-2].int_val); }
#line 1670 "parser.tab.c"
    break;

  case 53: /* relational_expression: relational_expression GREATER_EQUAL additive_expression  */
#line 276 "parser.y"
                                                              { (yyval.int_val) = (yyvsp[-2].int_val); }
#line 1676 "parser.tab.c"
    break;

  case 54: /* additive_expression: multiplicative_expression  */
#line 280 "parser.y"
                                { (yyval.int_val) = (yyvsp[0].int_val); }
#line 1682 "parser.tab.c"
    break;

  case 55: /* additive_expression: additive_expression PLUS multiplicative_expression  */
#line 281 "parser.y"
                                                         { (yyval.int_val) = (yyvsp[-2].int_val); }
#line 1688 "parser.tab.c"
    break;

  case 56: /* additive_expression: additive_expression MINUS multiplicative_expression  */
#line 282 "parser.y"
                                                          { (yyval.int_val) = (yyvsp[-2].int_val); }
#line 1694 "parser.tab.c"
    break;

  case 57: /* multiplicative_expression: unary_expression  */
#line 286 "parser.y"
                       { (yyval.int_val) = (yyvsp[0].int_val); }
#line 1700 "parser.tab.c"
    break;

  case 58: /* multiplicative_expression: multiplicative_expression MULTIPLY unary_expression  */
#line 287 "parser.y"
                                                          { (yyval.int_val) = (yyvsp[-2].int_val); }
#line 1706 "parser.tab.c"
    break;

  case 59: /* multiplicative_expression: multiplicative_expression DIVIDE unary_expression  */
#line 288 "parser.y"
                                                        { (yyval.int_val) = (yyvsp[-2].int_val); }
#line 1712 "parser.tab.c"
    break;

  case 60: /* multiplicative_expression: multiplicative_expression MODULO unary_expression  */
#line 289 "parser.y"
                                                        { (yyval.int_val) = (yyvsp[-2].int_val); }
#line 1718 "parser.tab.c"
    break;

  case 61: /* unary_expression: postfix_expression  */
#line 293 "parser.y"
                         { (yyval.int_val) = (yyvsp[0].int_val); }
#line 1724 "parser.tab.c"
    break;

  case 62: /* unary_expression: PLUS unary_expression  */
#line 294 "parser.y"
                            { (yyval.int_val) = (yyvsp[0].int_val); }
#line 1730 "parser.tab.c"
    break;

  case 63: /* unary_expression: MINUS unary_expression  */
#line 295 "parser.y"
                             { (yyval.int_val) = (yyvsp[0].int_val); }
#line 1736 "parser.tab.c"
    break;

  case 64: /* unary_expression: NOT unary_expression  */
#line 296 "parser.y"
                           { (yyval.int_val) = (yyvsp[0].int_val); }
#line 1742 "parser.tab.c"
    break;

  case 65: /* unary_expression: BITWISE_NOT unary_expression  */
#line 297 "parser.y"
                                   { (yyval.int_val) = (yyvsp[0].int_val); }
#line 1748 "parser.tab.c"
    break;

  case 66: /* postfix_expression: primary_expression  */
#line 301 "parser.y"
                         { (yyval.int_val) = (yyvsp[0].int_val); }
#line 1754 "parser.tab.c"
    break;

  case 67: /* postfix_expression: postfix_expression LEFT_BRACKET expression RIGHT_BRACKET  */
#line 302 "parser.y"
                                                               { (yyval.int_val) = (yyvsp[-3].int_val); }
#line 1760 "parser.tab.c"
    break;

  case 68: /* postfix_expression: postfix_expression LEFT_PAREN argument_expression_list RIGHT_PAREN  */
#line 303 "parser.y"
                                                                         { (yyval.int_val) = (yyvsp[-3].int_val); }
#line 1766 "parser.tab.c"
    break;

  case 69: /* postfix_expression: postfix_expression DOT IDENTIFIER  */
#line 304 "parser.y"
                                        { (yyval.int_val) = (yyvsp[-2].int_val); }
#line 1772 "parser.tab.c"
    break;

  case 70: /* postfix_expression: postfix_expression ARROW IDENTIFIER  */
#line 305 "parser.y"
                                          { (yyval.int_val) = (yyvsp[-2].int_val); }
#line 1778 "parser.tab.c"
    break;

  case 71: /* postfix_expression: postfix_expression INCREMENT  */
#line 306 "parser.y"
                                   { (yyval.int_val) = (yyvsp[-1].int_val); }
#line 1784 "parser.tab.c"
    break;

  case 72: /* postfix_expression: postfix_expression DECREMENT  */
#line 307 "parser.y"
                                   { (yyval.int_val) = (yyvsp[-1].int_val); }
#line 1790 "parser.tab.c"
    break;

  case 73: /* primary_expression: IDENTIFIER  */
#line 312 "parser.y"
    {
        // Check if variable is declared and initialized
        Symbol* sym = find_symbol((yyvsp[0].string_val), 0);
        if (sym == NULL) {
            report_error("Undefined variable", line_num, 0);
        } else {
            sym->is_used = 1;
            if (!sym->is_initialized) {
                report_error("Uninitialized variable", line_num, 0);
            }
        }
        (yyval.int_val) = sym ? sym->type : 0;
    }
#line 1808 "parser.tab.c"
    break;

  case 74: /* primary_expression: INTEGER_LITERAL  */
#line 325 "parser.y"
                      { (yyval.int_val) = 1; }
#line 1814 "parser.tab.c"
    break;

  case 75: /* primary_expression: FLOAT_LITERAL  */
#line 326 "parser.y"
                    { (yyval.int_val) = 4; }
#line 1820 "parser.tab.c"
    break;

  case 76: /* primary_expression: CHAR_LITERAL  */
#line 327 "parser.y"
                   { (yyval.int_val) = 2; }
#line 1826 "parser.tab.c"
    break;

  case 77: /* primary_expression: STRING_LITERAL  */
#line 328 "parser.y"
                     { (yyval.int_val) = 2; }
#line 1832 "parser.tab.c"
    break;

  case 78: /* primary_expression: LEFT_PAREN expression RIGHT_PAREN  */
#line 329 "parser.y"
                                        { (yyval.int_val) = (yyvsp[-1].int_val); }
#line 1838 "parser.tab.c"
    break;

  case 79: /* argument_expression_list: assignment_expression  */
#line 333 "parser.y"
                            { (yyval.int_val) = (yyvsp[0].int_val); }
#line 1844 "parser.tab.c"
    break;

  case 80: /* argument_expression_list: argument_expression_list COMMA assignment_expression  */
#line 334 "parser.y"
                                                           { (yyval.int_val) = (yyvsp[0].int_val); }
#line 1850 "parser.tab.c"
    break;

  case 81: /* argument_expression_list: %empty  */
#line 335 "parser.y"
                  { (yyval.int_val) = 0; }
#line 1856 "parser.tab.c"
    break;


#line 1860 "parser.tab.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
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
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 338 "parser.y"


void report_error(const char* msg, int line, int col) {
    fprintf(stderr, "Error at line %d: %s\n", line, msg);
    error_count++;
}

void yyerror(const char* s) {
    fprintf(stderr, "Error: %s\n", s);
    error_count++;
}

int main(int argc, char** argv) {
    if (argc > 1) {
        if (!(yyin = fopen(argv[1], "r"))) {
            perror(argv[1]);
            return 1;
        }
    }
    
    yyparse();
    
    // Report unused variables
    for (int i = 0; i < symbol_count; i++) {
        if (!symbol_table[i].is_used) {
            fprintf(stderr, "Warning: Unused variable '%s'\n", symbol_table[i].name);
        }
    }
    
    return error_count;
} 
