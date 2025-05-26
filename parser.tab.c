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
#line 9 "parser.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern int yylex();
extern int yylineno;
extern FILE *yyin;
void yyerror(const char *s);

#define MAX_PARAMS 10
#define MAX_FUNCTIONS 100

typedef struct {
    char* name;
    char* return_type;
    char* param_types[MAX_PARAMS];
    int param_count;
} FunctionSignature;

FunctionSignature function_table[MAX_FUNCTIONS];
int function_count = 0;

int is_same_signature(FunctionSignature* f, const char* name, char* return_type, char** param_types, int count) {
    if (strcmp(f->name, name) != 0) return 0;
    if (f->param_count != count) return 0;
    for (int i = 0; i < count; i++) {
        if (strcmp(f->param_types[i], param_types[i]) != 0) return 0;
    }
    return 1;
}

int is_duplicate_signature(const char* name, char* return_type, char** param_types, int count) {
    for (int i = 0; i < function_count; i++) {
        if (is_same_signature(&function_table[i], name, return_type, param_types, count)) return 1;
    }
    return 0;
}

void register_function_signature(const char* name, char* return_type, char** param_types, int count) {
    if (function_count >= MAX_FUNCTIONS) {
        fprintf(stderr, "Demasiadas funciones registradas\n");
        exit(1);
    }
    if (is_duplicate_signature(name, return_type, param_types, count)) {
        fprintf(stderr, "Error: Redefinición de función '%s' con la misma firma en la línea %d\n", name, yylineno);
        exit(1);
    }
    FunctionSignature* f = &function_table[function_count++];
    f->name = strdup(name);
    f->return_type = strdup(return_type);
    f->param_count = count;
    for (int i = 0; i < count; i++) {
        f->param_types[i] = strdup(param_types[i]);
    }
}

char* param_type_buffer[MAX_PARAMS];
int param_type_count = 0;

#line 132 "parser.tab.c"

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
  YYSYMBOL_INT_LITERAL = 3,                /* INT_LITERAL  */
  YYSYMBOL_FLOAT_LITERAL = 4,              /* FLOAT_LITERAL  */
  YYSYMBOL_STRING_LITERAL = 5,             /* STRING_LITERAL  */
  YYSYMBOL_IDENTIFIER = 6,                 /* IDENTIFIER  */
  YYSYMBOL_BOOL_LITERAL = 7,               /* BOOL_LITERAL  */
  YYSYMBOL_INT = 8,                        /* INT  */
  YYSYMBOL_FLOAT = 9,                      /* FLOAT  */
  YYSYMBOL_BOOL = 10,                      /* BOOL  */
  YYSYMBOL_STRING = 11,                    /* STRING  */
  YYSYMBOL_VOID = 12,                      /* VOID  */
  YYSYMBOL_IF = 13,                        /* IF  */
  YYSYMBOL_ELSE = 14,                      /* ELSE  */
  YYSYMBOL_WHILE = 15,                     /* WHILE  */
  YYSYMBOL_FOR = 16,                       /* FOR  */
  YYSYMBOL_SWITCH = 17,                    /* SWITCH  */
  YYSYMBOL_CASE = 18,                      /* CASE  */
  YYSYMBOL_DEFAULT = 19,                   /* DEFAULT  */
  YYSYMBOL_BREAK = 20,                     /* BREAK  */
  YYSYMBOL_TRY = 21,                       /* TRY  */
  YYSYMBOL_CATCH = 22,                     /* CATCH  */
  YYSYMBOL_ASSERT = 23,                    /* ASSERT  */
  YYSYMBOL_RETURN = 24,                    /* RETURN  */
  YYSYMBOL_SUM = 25,                       /* SUM  */
  YYSYMBOL_PROD = 26,                      /* PROD  */
  YYSYMBOL_MAX = 27,                       /* MAX  */
  YYSYMBOL_MIN = 28,                       /* MIN  */
  YYSYMBOL_ASSIGN = 29,                    /* ASSIGN  */
  YYSYMBOL_REL_OP = 30,                    /* REL_OP  */
  YYSYMBOL_OR = 31,                        /* OR  */
  YYSYMBOL_AND = 32,                       /* AND  */
  YYSYMBOL_33_ = 33,                       /* '+'  */
  YYSYMBOL_34_ = 34,                       /* '-'  */
  YYSYMBOL_35_ = 35,                       /* '*'  */
  YYSYMBOL_36_ = 36,                       /* '/'  */
  YYSYMBOL_37_ = 37,                       /* '%'  */
  YYSYMBOL_LPAREN = 38,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 39,                    /* RPAREN  */
  YYSYMBOL_LBRACE = 40,                    /* LBRACE  */
  YYSYMBOL_RBRACE = 41,                    /* RBRACE  */
  YYSYMBOL_LBRACKET = 42,                  /* LBRACKET  */
  YYSYMBOL_RBRACKET = 43,                  /* RBRACKET  */
  YYSYMBOL_SEMICOLON = 44,                 /* SEMICOLON  */
  YYSYMBOL_COMMA = 45,                     /* COMMA  */
  YYSYMBOL_COLON = 46,                     /* COLON  */
  YYSYMBOL_UMINUS = 47,                    /* UMINUS  */
  YYSYMBOL_YYACCEPT = 48,                  /* $accept  */
  YYSYMBOL_program = 49,                   /* program  */
  YYSYMBOL_declaration_or_statement = 50,  /* declaration_or_statement  */
  YYSYMBOL_function_declaration = 51,      /* function_declaration  */
  YYSYMBOL_parameter_list = 52,            /* parameter_list  */
  YYSYMBOL_parameter = 53,                 /* parameter  */
  YYSYMBOL_type = 54,                      /* type  */
  YYSYMBOL_variable_declaration = 55,      /* variable_declaration  */
  YYSYMBOL_assignment = 56,                /* assignment  */
  YYSYMBOL_expression = 57,                /* expression  */
  YYSYMBOL_argument_list = 58,             /* argument_list  */
  YYSYMBOL_argument = 59,                  /* argument  */
  YYSYMBOL_list = 60,                      /* list  */
  YYSYMBOL_expr_list = 61,                 /* expr_list  */
  YYSYMBOL_matrix = 62,                    /* matrix  */
  YYSYMBOL_matrix_rows = 63,               /* matrix_rows  */
  YYSYMBOL_block = 64,                     /* block  */
  YYSYMBOL_assert_statement = 65,          /* assert_statement  */
  YYSYMBOL_control_structure = 66,         /* control_structure  */
  YYSYMBOL_if_statement = 67,              /* if_statement  */
  YYSYMBOL_while_statement = 68,           /* while_statement  */
  YYSYMBOL_for_statement = 69,             /* for_statement  */
  YYSYMBOL_for_init = 70,                  /* for_init  */
  YYSYMBOL_switch_statement = 71,          /* switch_statement  */
  YYSYMBOL_case_list = 72,                 /* case_list  */
  YYSYMBOL_try_statement = 73              /* try_statement  */
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
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   617

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  48
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  26
/* YYNRULES -- Number of rules.  */
#define YYNRULES  94
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  228

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   297


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
       2,     2,     2,     2,     2,     2,     2,    37,     2,     2,
       2,     2,    35,    33,     2,    34,     2,    36,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31,    32,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   106,   106,   108,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   124,   129,   134,   141,   143,   144,   148,
     152,   153,   154,   155,   156,   160,   161,   162,   166,   167,
     168,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   206,   211,   216,   219,   221,   222,   226,   227,   231,
     235,   236,   240,   244,   245,   249,   253,   257,   258,   259,
     260,   261,   265,   266,   267,   275,   276,   284,   288,   289,
     293,   297,   298,   299,   303
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
  "\"end of file\"", "error", "\"invalid token\"", "INT_LITERAL",
  "FLOAT_LITERAL", "STRING_LITERAL", "IDENTIFIER", "BOOL_LITERAL", "INT",
  "FLOAT", "BOOL", "STRING", "VOID", "IF", "ELSE", "WHILE", "FOR",
  "SWITCH", "CASE", "DEFAULT", "BREAK", "TRY", "CATCH", "ASSERT", "RETURN",
  "SUM", "PROD", "MAX", "MIN", "ASSIGN", "REL_OP", "OR", "AND", "'+'",
  "'-'", "'*'", "'/'", "'%'", "LPAREN", "RPAREN", "LBRACE", "RBRACE",
  "LBRACKET", "RBRACKET", "SEMICOLON", "COMMA", "COLON", "UMINUS",
  "$accept", "program", "declaration_or_statement", "function_declaration",
  "parameter_list", "parameter", "type", "variable_declaration",
  "assignment", "expression", "argument_list", "argument", "list",
  "expr_list", "matrix", "matrix_rows", "block", "assert_statement",
  "control_structure", "if_statement", "while_statement", "for_statement",
  "for_init", "switch_statement", "case_list", "try_statement", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-112)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-65)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -112,   212,  -112,  -112,  -112,  -112,    52,  -112,  -112,  -112,
    -112,  -112,  -112,   -30,   -29,    -5,    21,    30,    29,    41,
     126,    59,    69,    98,   101,   377,   377,  -112,  -112,     1,
      97,   105,    91,  -112,  -112,  -112,  -112,  -112,  -112,  -112,
     377,    57,   377,   287,   301,   180,   377,  -112,  -112,   121,
     377,    15,  -112,   408,    23,    25,    26,    35,  -112,   522,
      -4,   107,  -112,  -112,   337,   377,   377,   351,   377,   377,
     377,   377,  -112,   572,   116,   127,   572,    95,  -112,   438,
     118,   532,   122,   542,    -2,    46,  -112,  -112,   119,   552,
     248,   124,   562,   377,  -112,   132,   172,   133,   134,   155,
     156,   157,   168,   169,   170,   174,   187,   191,  -112,   377,
      27,    50,  -112,   147,   580,    82,  -112,   131,   131,  -112,
    -112,  -112,  -112,   377,  -112,   391,    13,    29,    29,    29,
      29,   377,   182,   377,   194,  -112,   193,   197,   452,  -112,
     377,   572,  -112,    55,    65,  -112,  -112,  -112,  -112,  -112,
    -112,  -112,  -112,  -112,  -112,  -112,   572,   192,    99,  -112,
     236,   214,   201,   572,  -112,   377,   377,  -112,   231,  -112,
    -112,   466,   423,  -112,   241,  -112,   206,  -112,   377,  -112,
     207,    29,    14,   193,  -112,   207,   256,   572,   480,    29,
      51,   260,    68,   228,   377,   572,  -112,  -112,  -112,  -112,
    -112,  -112,   249,   250,  -112,   377,   238,   377,   224,  -112,
      29,   494,   239,   377,   508,    29,   400,    29,  -112,  -112,
     207,  -112,   572,   250,  -112,    29,  -112,  -112
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       2,     0,     1,    31,    32,    33,    35,    34,    20,    21,
      22,    23,    24,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     3,    11,     0,
       0,     0,     0,    10,    12,    77,    78,    79,    80,    81,
       0,     0,     0,     0,     0,     0,     0,     9,     2,     0,
       0,    35,     8,     0,     0,     0,     0,     0,    63,     0,
       0,     0,     4,     5,     0,     0,     0,     0,     0,     0,
       0,     0,     6,    28,     0,    35,    67,     0,    65,     0,
       0,     0,     0,     0,     0,     0,    89,    88,     0,     0,
       0,     0,     0,     0,     7,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    46,     0,
       0,     0,    62,    43,    45,    44,    61,    38,    39,    40,
      41,    42,    60,     0,    59,     0,    36,     0,     0,     0,
       0,     0,     0,     0,     0,    75,     0,     0,     0,    49,
       0,    70,    73,     0,     0,    47,    48,    52,    50,    51,
      55,    53,    54,    58,    56,    57,    25,     0,     0,    17,
       0,     0,     0,    68,    66,     0,     0,    84,    82,    86,
      85,     0,     0,    93,     0,    76,    36,    69,     0,    72,
       0,     0,     0,     0,    19,     0,     0,    29,     0,     0,
       0,     0,     0,     0,     0,    71,    74,    14,    15,    13,
      18,    26,     0,    37,    83,     0,     0,     0,     0,    90,
       0,     0,     0,     0,     0,     0,     0,     0,    94,    37,
       0,    27,    30,     0,    87,     0,    92,    91
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -112,   232,  -112,  -112,  -112,   100,   -35,   240,   -44,   -20,
    -112,   159,   -43,  -112,   -53,  -112,  -111,  -112,  -112,  -112,
    -112,  -112,  -112,  -112,  -112,  -112
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,    27,    28,   158,   159,    29,    30,    31,    32,
      77,    78,   142,   143,    98,   144,    49,    33,    34,    35,
      36,    37,    88,    38,   192,    39
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      53,    87,   101,   104,   107,    58,    59,    60,    43,    44,
      85,    97,   100,   103,   106,   198,   167,   168,   169,   170,
      73,    76,    79,    81,    83,   109,    89,    40,   157,    95,
      92,    99,   102,    45,   110,     8,     9,    10,    11,    12,
     131,   105,   165,    61,   113,   114,   115,   117,   118,   119,
     120,   121,   132,    41,    48,   166,   161,    93,    74,    46,
       3,     4,     5,    75,     7,    96,   -16,    96,    96,    48,
     197,   199,   -16,   138,    47,   160,   141,    96,   204,    50,
     165,    40,    21,    22,    23,    24,   207,   208,    61,   156,
      41,    25,   162,   205,    42,    26,   -64,    54,   177,   218,
     178,   174,   -64,   163,   224,    76,   226,    55,   179,   209,
     180,   171,    64,   172,   227,    67,    68,    69,    70,    71,
     141,    64,    65,    66,    67,    68,    69,    70,    71,     3,
       4,     5,    51,     7,   124,    72,    56,   196,   182,    57,
     125,    62,   201,    91,   183,   187,   188,   206,   160,    63,
     111,    21,    22,    23,    24,   122,   123,   127,   195,   221,
      25,   129,   136,   133,    26,    41,    69,    70,    71,    93,
      52,   139,   145,   146,   211,     3,     4,     5,    51,     7,
      67,    68,    69,    70,    71,   214,    84,   216,     8,     9,
      10,    11,    12,   222,   147,   148,   149,    21,    22,    23,
      24,     8,     9,    10,    11,    12,    25,   150,   151,   152,
      26,   109,     2,   153,   140,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,   154,    14,    15,    16,
     155,   181,    17,    18,   173,    19,    20,    21,    22,    23,
      24,   175,   184,   185,   186,   189,    25,   193,   194,   140,
      26,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,   202,    14,    15,    16,    84,   210,    17,    18,
     217,    19,    20,    21,    22,    23,    24,   215,   212,   213,
      90,   220,    25,   200,   164,    86,    26,     0,    80,   135,
       3,     4,     5,    51,     7,     0,     0,     0,     0,     0,
       0,     0,    82,     0,     3,     4,     5,    51,     7,     0,
       0,     0,    21,    22,    23,    24,     0,     0,     0,     0,
       0,    25,     0,     0,     0,    26,    21,    22,    23,    24,
       0,     0,     0,     0,     0,    25,     0,     0,   112,    26,
       3,     4,     5,    51,     7,     0,     0,     0,     0,     0,
       0,     0,   116,     0,     3,     4,     5,    51,     7,     0,
       0,     0,    21,    22,    23,    24,     0,     0,     0,     0,
       0,    25,     0,     0,     0,    26,    21,    22,    23,    24,
       3,     4,     5,    51,     7,    25,     0,     0,     0,    26,
       0,     0,     0,     0,     3,     4,     5,    75,     7,     0,
       0,     0,    21,    22,    23,    24,     0,     0,     0,     0,
       0,    25,     0,     0,     0,    26,    21,    22,    23,    24,
       0,     0,     0,     0,     0,    25,     0,     0,     0,    26,
      64,    65,    66,    67,    68,    69,    70,    71,    64,    65,
      66,    67,    68,    69,    70,    71,   225,     0,     0,     0,
       0,     0,    94,    64,    65,    66,    67,    68,    69,    70,
      71,     0,     0,     0,     0,     0,     0,   191,    64,    65,
      66,    67,    68,    69,    70,    71,     0,     0,     0,     0,
       0,   126,    64,    65,    66,    67,    68,    69,    70,    71,
       0,     0,     0,     0,     0,   176,    64,    65,    66,    67,
      68,    69,    70,    71,     0,     0,     0,     0,     0,   190,
      64,    65,    66,    67,    68,    69,    70,    71,     0,     0,
       0,     0,     0,   203,    64,    65,    66,    67,    68,    69,
      70,    71,     0,     0,     0,     0,     0,   219,    64,    65,
      66,    67,    68,    69,    70,    71,     0,     0,     0,     0,
       0,   223,    64,    65,    66,    67,    68,    69,    70,    71,
       0,   108,    64,    65,    66,    67,    68,    69,    70,    71,
       0,   128,    64,    65,    66,    67,    68,    69,    70,    71,
       0,   130,    64,    65,    66,    67,    68,    69,    70,    71,
       0,   134,    64,    65,    66,    67,    68,    69,    70,    71,
       0,   137,    64,    65,    66,    67,    68,    69,    70,    71,
      64,     0,    66,    67,    68,    69,    70,    71
};

static const yytype_int16 yycheck[] =
{
      20,    45,    55,    56,    57,    25,    26,     6,    38,    38,
      45,    54,    55,    56,    57,     1,   127,   128,   129,   130,
      40,    41,    42,    43,    44,    29,    46,    29,     1,     6,
      50,     6,     6,    38,    38,     8,     9,    10,    11,    12,
      42,     6,    29,    42,    64,    65,    66,    67,    68,    69,
      70,    71,     6,    38,    40,    42,     6,    42,     1,    38,
       3,     4,     5,     6,     7,    42,    39,    42,    42,    40,
     181,   182,    45,    93,    44,   110,    96,    42,   189,    38,
      29,    29,    25,    26,    27,    28,    18,    19,    42,   109,
      38,    34,    42,    42,    42,    38,    39,    38,    43,   210,
      45,   136,    45,   123,   215,   125,   217,    38,    43,    41,
      45,   131,    30,   133,   225,    33,    34,    35,    36,    37,
     140,    30,    31,    32,    33,    34,    35,    36,    37,     3,
       4,     5,     6,     7,    39,    44,    38,   180,    39,    38,
      45,    44,   185,    22,    45,   165,   166,   191,   183,    44,
      43,    25,    26,    27,    28,    39,    29,    39,   178,   212,
      34,    39,    38,    44,    38,    38,    35,    36,    37,    42,
      44,    39,    39,    39,   194,     3,     4,     5,     6,     7,
      33,    34,    35,    36,    37,   205,     6,   207,     8,     9,
      10,    11,    12,   213,    39,    39,    39,    25,    26,    27,
      28,     8,     9,    10,    11,    12,    34,    39,    39,    39,
      38,    29,     0,    39,    42,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    39,    15,    16,    17,
      39,    39,    20,    21,    40,    23,    24,    25,    26,    27,
      28,    44,     6,    29,    43,    14,    34,     6,    42,    42,
      38,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,     6,    15,    16,    17,     6,    39,    20,    21,
      46,    23,    24,    25,    26,    27,    28,    39,    29,    29,
      48,    42,    34,   183,   125,    45,    38,    -1,     1,    41,
       3,     4,     5,     6,     7,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     1,    -1,     3,     4,     5,     6,     7,    -1,
      -1,    -1,    25,    26,    27,    28,    -1,    -1,    -1,    -1,
      -1,    34,    -1,    -1,    -1,    38,    25,    26,    27,    28,
      -1,    -1,    -1,    -1,    -1,    34,    -1,    -1,     1,    38,
       3,     4,     5,     6,     7,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     1,    -1,     3,     4,     5,     6,     7,    -1,
      -1,    -1,    25,    26,    27,    28,    -1,    -1,    -1,    -1,
      -1,    34,    -1,    -1,    -1,    38,    25,    26,    27,    28,
       3,     4,     5,     6,     7,    34,    -1,    -1,    -1,    38,
      -1,    -1,    -1,    -1,     3,     4,     5,     6,     7,    -1,
      -1,    -1,    25,    26,    27,    28,    -1,    -1,    -1,    -1,
      -1,    34,    -1,    -1,    -1,    38,    25,    26,    27,    28,
      -1,    -1,    -1,    -1,    -1,    34,    -1,    -1,    -1,    38,
      30,    31,    32,    33,    34,    35,    36,    37,    30,    31,
      32,    33,    34,    35,    36,    37,    46,    -1,    -1,    -1,
      -1,    -1,    44,    30,    31,    32,    33,    34,    35,    36,
      37,    -1,    -1,    -1,    -1,    -1,    -1,    44,    30,    31,
      32,    33,    34,    35,    36,    37,    -1,    -1,    -1,    -1,
      -1,    43,    30,    31,    32,    33,    34,    35,    36,    37,
      -1,    -1,    -1,    -1,    -1,    43,    30,    31,    32,    33,
      34,    35,    36,    37,    -1,    -1,    -1,    -1,    -1,    43,
      30,    31,    32,    33,    34,    35,    36,    37,    -1,    -1,
      -1,    -1,    -1,    43,    30,    31,    32,    33,    34,    35,
      36,    37,    -1,    -1,    -1,    -1,    -1,    43,    30,    31,
      32,    33,    34,    35,    36,    37,    -1,    -1,    -1,    -1,
      -1,    43,    30,    31,    32,    33,    34,    35,    36,    37,
      -1,    39,    30,    31,    32,    33,    34,    35,    36,    37,
      -1,    39,    30,    31,    32,    33,    34,    35,    36,    37,
      -1,    39,    30,    31,    32,    33,    34,    35,    36,    37,
      -1,    39,    30,    31,    32,    33,    34,    35,    36,    37,
      -1,    39,    30,    31,    32,    33,    34,    35,    36,    37,
      30,    -1,    32,    33,    34,    35,    36,    37
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    49,     0,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    15,    16,    17,    20,    21,    23,
      24,    25,    26,    27,    28,    34,    38,    50,    51,    54,
      55,    56,    57,    65,    66,    67,    68,    69,    71,    73,
      29,    38,    42,    38,    38,    38,    38,    44,    40,    64,
      38,     6,    44,    57,    38,    38,    38,    38,    57,    57,
       6,    42,    44,    44,    30,    31,    32,    33,    34,    35,
      36,    37,    44,    57,     1,     6,    57,    58,    59,    57,
       1,    57,     1,    57,     6,    54,    55,    56,    70,    57,
      49,    22,    57,    42,    44,     6,    42,    60,    62,     6,
      60,    62,     6,    60,    62,     6,    60,    62,    39,    29,
      38,    43,     1,    57,    57,    57,     1,    57,    57,    57,
      57,    57,    39,    29,    39,    45,    43,    39,    39,    39,
      39,    42,     6,    44,    39,    41,    38,    39,    57,    39,
      42,    57,    60,    61,    63,    39,    39,    39,    39,    39,
      39,    39,    39,    39,    39,    39,    57,     1,    52,    53,
      54,     6,    42,    57,    59,    29,    42,    64,    64,    64,
      64,    57,    57,    40,    54,    44,    43,    43,    45,    43,
      45,    39,    39,    45,     6,    29,    43,    57,    57,    14,
      43,    44,    72,     6,    42,    57,    60,    64,     1,    64,
      53,    60,     6,    43,    64,    42,    56,    18,    19,    41,
      39,    57,    29,    29,    57,    39,    57,    46,    64,    43,
      42,    62,    57,    43,    64,    46,    64,    64
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    48,    49,    49,    50,    50,    50,    50,    50,    50,
      50,    50,    50,    51,    51,    51,    52,    52,    52,    53,
      54,    54,    54,    54,    54,    55,    55,    55,    56,    56,
      56,    57,    57,    57,    57,    57,    57,    57,    57,    57,
      57,    57,    57,    57,    57,    57,    57,    57,    57,    57,
      57,    57,    57,    57,    57,    57,    57,    57,    57,    57,
      57,    57,    57,    57,    58,    58,    58,    59,    59,    60,
      61,    61,    62,    63,    63,    64,    65,    66,    66,    66,
      66,    66,    67,    67,    67,    68,    68,    69,    70,    70,
      71,    72,    72,    72,    73
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     2,     2,     2,     2,     3,     2,     2,
       1,     1,     1,     6,     6,     6,     0,     1,     3,     2,
       1,     1,     1,     1,     1,     4,     6,     8,     3,     6,
       9,     1,     1,     1,     1,     1,     4,     7,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     3,     3,     2,     0,     1,     3,     1,     3,     3,
       1,     3,     3,     1,     3,     3,     5,     1,     1,     1,
       1,     1,     5,     7,     5,     5,     5,     9,     1,     1,
       7,     5,     4,     0,     8
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
  case 13: /* function_declaration: type IDENTIFIER LPAREN parameter_list RPAREN block  */
#line 125 "parser.y"
    {
        register_function_signature((yyvsp[-4].sval), (yyvsp[-5].sval), param_type_buffer, param_type_count);
        param_type_count = 0;
    }
#line 1415 "parser.tab.c"
    break;

  case 14: /* function_declaration: type IDENTIFIER LPAREN error RPAREN block  */
#line 130 "parser.y"
    {
        yyerror("Error: lista de parámetros inválida en declaración de función");
        yyclearin; yyerrok;
    }
#line 1424 "parser.tab.c"
    break;

  case 15: /* function_declaration: type IDENTIFIER LPAREN parameter_list RPAREN error  */
#line 135 "parser.y"
    {
        yyerror("Error: bloque de función mal formado o faltante");
        yyclearin; yyerrok;
    }
#line 1433 "parser.tab.c"
    break;

  case 17: /* parameter_list: parameter  */
#line 143 "parser.y"
                { param_type_buffer[0] = strdup((yyvsp[0].sval)); param_type_count = 1; }
#line 1439 "parser.tab.c"
    break;

  case 18: /* parameter_list: parameter_list COMMA parameter  */
#line 144 "parser.y"
                                     { param_type_buffer[param_type_count++] = strdup((yyvsp[0].sval)); }
#line 1445 "parser.tab.c"
    break;

  case 19: /* parameter: type IDENTIFIER  */
#line 148 "parser.y"
                      { (yyval.sval) = (yyvsp[-1].sval); }
#line 1451 "parser.tab.c"
    break;

  case 20: /* type: INT  */
#line 152 "parser.y"
             { (yyval.sval) = "int"; }
#line 1457 "parser.tab.c"
    break;

  case 21: /* type: FLOAT  */
#line 153 "parser.y"
             { (yyval.sval) = "float"; }
#line 1463 "parser.tab.c"
    break;

  case 22: /* type: BOOL  */
#line 154 "parser.y"
             { (yyval.sval) = "bool"; }
#line 1469 "parser.tab.c"
    break;

  case 23: /* type: STRING  */
#line 155 "parser.y"
             { (yyval.sval) = "string"; }
#line 1475 "parser.tab.c"
    break;

  case 24: /* type: VOID  */
#line 156 "parser.y"
             { (yyval.sval) = "void"; }
#line 1481 "parser.tab.c"
    break;

  case 60: /* expression: IDENTIFIER LPAREN error RPAREN  */
#line 202 "parser.y"
    {
        yyerror("Error: argumentos inválidos en llamada a función");
        yyclearin; yyerrok;
    }
#line 1490 "parser.tab.c"
    break;

  case 61: /* expression: expression '+' error  */
#line 207 "parser.y"
    {
        yyerror("Error: expresión incompleta tras '+'");
        yyclearin; yyerrok;
    }
#line 1499 "parser.tab.c"
    break;

  case 62: /* expression: expression REL_OP error  */
#line 212 "parser.y"
    {
        yyerror("Error: lado derecho de comparación faltante");
        yyclearin; yyerrok;
    }
#line 1508 "parser.tab.c"
    break;

  case 68: /* argument: IDENTIFIER ASSIGN expression  */
#line 227 "parser.y"
                                   { printf("Parámetro nombrado: %s\n", (yyvsp[-2].sval)); }
#line 1514 "parser.tab.c"
    break;

  case 84: /* if_statement: IF LPAREN error RPAREN block  */
#line 268 "parser.y"
    {
        yyerror("Error: condición inválida en if");
        yyclearin; yyerrok;
    }
#line 1523 "parser.tab.c"
    break;

  case 86: /* while_statement: WHILE LPAREN error RPAREN block  */
#line 277 "parser.y"
    {
        yyerror("Error: condición inválida en while");
        yyclearin; yyerrok;
    }
#line 1532 "parser.tab.c"
    break;


#line 1536 "parser.tab.c"

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

#line 306 "parser.y"


void yyerror(const char *s) {
    fprintf(stderr, "Error en la línea %d: %s\n", yylineno, s);
}

