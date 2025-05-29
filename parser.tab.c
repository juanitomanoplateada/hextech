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

#define MAX_VARIABLES 1000

typedef struct {
    char* name;
    char* type;
    int scope_level;
} Variable;

#define MAX_SCOPE_DEPTH 1000
int scope_stack[MAX_SCOPE_DEPTH];
int scope_depth = 0;
int scope_counter = 1;

int current_scope() {
    if (scope_depth == 0) return 0;
    return scope_stack[scope_depth - 1];
}

void enter_scope() {
    scope_stack[scope_depth++] = scope_counter++;
}

void exit_scope() {
    if (scope_depth > 0) scope_depth--;
}

Variable variable_table[MAX_VARIABLES];
int variable_count = 0;

int is_same_variable_in_scope(const char* name, const char* type, int scope) {
    for (int i = 0; i < variable_count; i++) {
        if (variable_table[i].scope_level == scope &&
            strcmp(variable_table[i].name, name) == 0 &&
            strcmp(variable_table[i].type, type) == 0) {
            return 1;
        }
    }
    return 0;
}

void register_variable(const char* name, const char* type) {
    int scope = current_scope();
    for (int i = 0; i < variable_count; i++) {
        if (variable_table[i].scope_level == scope &&
            strcmp(variable_table[i].name, name) == 0 &&
            strcmp(variable_table[i].type, type) == 0) {
            fprintf(stderr, "Error: Redefinición de variable '%s' con el mismo tipo en el mismo ámbito en la línea %d\n", name, yylineno);
            exit(1);
        }
    }
    variable_table[variable_count].name = strdup(name);
    variable_table[variable_count].type = strdup(type);
    variable_table[variable_count].scope_level = scope;
    variable_count++;
}


#line 189 "parser.tab.c"

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
  YYSYMBOL_declaration_or_statement_list = 50, /* declaration_or_statement_list  */
  YYSYMBOL_declaration_or_statement = 51,  /* declaration_or_statement  */
  YYSYMBOL_function_declaration = 52,      /* function_declaration  */
  YYSYMBOL_parameter_list = 53,            /* parameter_list  */
  YYSYMBOL_parameter = 54,                 /* parameter  */
  YYSYMBOL_type = 55,                      /* type  */
  YYSYMBOL_variable_declaration = 56,      /* variable_declaration  */
  YYSYMBOL_assignment = 57,                /* assignment  */
  YYSYMBOL_expression = 58,                /* expression  */
  YYSYMBOL_argument_list = 59,             /* argument_list  */
  YYSYMBOL_argument = 60,                  /* argument  */
  YYSYMBOL_list = 61,                      /* list  */
  YYSYMBOL_expr_list = 62,                 /* expr_list  */
  YYSYMBOL_matrix = 63,                    /* matrix  */
  YYSYMBOL_matrix_rows = 64,               /* matrix_rows  */
  YYSYMBOL_assert_statement = 65,          /* assert_statement  */
  YYSYMBOL_control_structure = 66,         /* control_structure  */
  YYSYMBOL_if_statement = 67,              /* if_statement  */
  YYSYMBOL_block = 68,                     /* block  */
  YYSYMBOL_69_1 = 69,                      /* $@1  */
  YYSYMBOL_while_statement = 70,           /* while_statement  */
  YYSYMBOL_for_statement = 71,             /* for_statement  */
  YYSYMBOL_for_init = 72,                  /* for_init  */
  YYSYMBOL_switch_statement = 73,          /* switch_statement  */
  YYSYMBOL_case_list = 74,                 /* case_list  */
  YYSYMBOL_try_statement = 75              /* try_statement  */
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
#define YYFINAL  61
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   649

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  48
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  28
/* YYNRULES -- Number of rules.  */
#define YYNRULES  97
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  232

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
       0,   164,   164,   168,   169,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   186,   191,   196,   203,   205,
     206,   210,   214,   215,   216,   217,   218,   222,   226,   230,
     237,   238,   239,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
     260,   261,   262,   263,   264,   265,   266,   267,   268,   269,
     270,   271,   272,   277,   282,   287,   290,   292,   293,   297,
     298,   302,   306,   307,   311,   315,   316,   319,   323,   324,
     325,   326,   327,   331,   332,   333,   341,   341,   351,   352,
     360,   364,   365,   369,   373,   374,   375,   379
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
  "$accept", "program", "declaration_or_statement_list",
  "declaration_or_statement", "function_declaration", "parameter_list",
  "parameter", "type", "variable_declaration", "assignment", "expression",
  "argument_list", "argument", "list", "expr_list", "matrix",
  "matrix_rows", "assert_statement", "control_structure", "if_statement",
  "block", "$@1", "while_statement", "for_statement", "for_init",
  "switch_statement", "case_list", "try_statement", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-53)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-87)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     406,   -53,   -53,   -53,    69,   -53,   -53,   -53,   -53,   -53,
     -53,   -18,    -3,    57,    75,    22,   -53,    81,   153,    89,
      96,   100,   103,   432,   432,   146,   282,   -53,   -53,     9,
     104,   106,    56,   -53,   -53,   -53,   -53,   107,   -53,   -53,
     -53,   -53,   432,    37,   432,    98,   320,   322,   432,   -53,
     129,   432,    91,   -53,   348,    19,    28,    31,    66,   -53,
     554,   -53,   -53,   -12,   109,   -53,   -53,   334,   432,   432,
     370,   432,   432,   432,   432,   -53,   406,   604,   114,   101,
     604,   -29,   -53,   470,   122,   564,   123,   574,   -10,    68,
     -53,   -53,   119,   584,   127,   594,   432,   -53,   137,   203,
     143,   145,   147,   149,   150,   151,   154,   156,   160,   161,
     162,   -53,   432,    38,    79,   -53,   239,   612,   138,   -53,
      43,    43,   -53,   -53,   -53,   243,   -53,   432,   -53,   446,
      67,   -53,   -53,   -53,   -53,   432,   163,   432,   126,   303,
     141,   484,   -53,   432,   604,   -53,    24,    92,   -53,   -53,
     -53,   -53,   -53,   -53,   -53,   -53,   -53,   -53,   -53,   604,
     165,   -21,   -53,   205,   183,   171,   -53,   604,   -53,   432,
     432,   -53,   201,   -53,   -53,   498,   455,   -53,   218,   -53,
     184,   -53,   432,   -53,   185,   -53,    20,   303,   -53,   185,
     219,   604,   512,   -53,   102,   227,     4,   195,   432,   604,
     -53,   -53,   -53,   -53,   -53,   -53,   206,   207,   -53,   432,
     199,   432,   193,   -53,   -53,   526,   198,   432,   540,   -53,
     186,   -53,   -53,   -53,   185,   -53,   604,   207,   -53,   -53,
     -53,   -53
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
      86,    33,    34,    35,    37,    36,    22,    23,    24,    25,
      26,     0,     0,     0,     0,     0,    86,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     2,     3,    12,     0,
       0,     0,     0,    11,    13,    78,    14,     0,    79,    80,
      81,    82,     0,     0,     0,     0,     0,     0,     0,    10,
       0,     0,    37,     9,     0,     0,     0,     0,     0,    65,
       0,     1,     4,     0,     0,     5,     6,     0,     0,     0,
       0,     0,     0,     0,     0,     7,    86,    30,     0,    37,
      69,     0,    67,     0,     0,     0,     0,     0,     0,     0,
      92,    91,     0,     0,     0,     0,     0,     8,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    48,     0,     0,     0,    64,    45,    47,    46,    63,
      40,    41,    42,    43,    44,    86,    62,     0,    61,     0,
      38,    86,    86,    86,    86,     0,     0,     0,     0,     0,
       0,     0,    51,     0,    72,    75,     0,     0,    49,    50,
      54,    52,    53,    57,    55,    56,    60,    58,    59,    27,
       0,     0,    19,     0,     0,     0,    87,    70,    68,     0,
       0,    85,    83,    89,    88,     0,     0,    96,     0,    77,
      38,    71,     0,    74,     0,    86,     0,     0,    21,     0,
       0,    31,     0,    86,     0,     0,     0,     0,     0,    73,
      76,    16,    17,    15,    20,    28,     0,    39,    84,     0,
       0,     0,     0,    93,    86,     0,     0,     0,     0,    86,
       0,    86,    97,    39,     0,    29,    32,     0,    90,    86,
      95,    94
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -53,   -53,   166,   -19,   -53,   -53,    70,   -45,   196,   -46,
     -15,   -53,   115,   -44,   -53,   -52,   -53,   -53,   -53,   -53,
     -16,   -53,   -53,   -53,   -53,   -53,   -53,   -53
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,    25,    26,    27,    28,   161,   162,    29,    30,    31,
      32,    81,    82,   145,   146,   101,   147,    33,    34,    35,
      36,    37,    38,    39,    92,    40,   196,    41
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      50,    91,    89,    54,   104,   107,   110,    62,    59,    60,
     128,   100,   103,   106,   109,    63,   129,   112,   186,    42,
      45,   202,   211,   212,   187,    98,   113,    77,    80,    83,
      85,    87,   135,    93,   102,    46,    95,   105,    78,   160,
       1,     2,     3,    79,     5,   213,     6,     7,     8,     9,
      10,    64,   116,   117,   118,   120,   121,   122,   123,   124,
     -86,    99,    19,    20,    21,    22,    49,   181,   163,   182,
      99,    23,   108,    99,   136,    24,   -66,   -18,    72,    73,
      74,   141,   -66,   -18,   144,   164,    67,    68,    69,    70,
      71,    72,    73,    74,   178,    47,   169,   159,    42,    84,
      75,     1,     2,     3,    52,     5,    62,    43,    99,   170,
      64,    44,   167,    48,    80,   171,   172,   173,   174,    51,
     175,   165,   176,    19,    20,    21,    22,    55,   144,    43,
     127,   169,    23,    96,    56,   183,    24,   184,    57,    43,
     200,    58,   163,    96,   209,   205,    61,    76,    65,   210,
      66,    94,   114,   126,   191,   192,     1,     2,     3,    52,
       5,   131,   133,   137,   225,   139,   177,   199,    67,   201,
     203,    70,    71,    72,    73,    74,   142,   208,    19,    20,
      21,    22,   148,   215,   149,   179,   150,    23,   151,   152,
     153,    24,   112,   154,   218,   155,   220,    53,   222,   156,
     157,   158,   226,   228,   185,   230,     1,     2,     3,    52,
       5,   188,   189,   231,   190,   193,    67,    68,    69,    70,
      71,    72,    73,    74,   197,   206,   198,   143,    19,    20,
      21,    22,   229,    88,   214,   216,   217,    23,   219,   221,
     224,    24,   125,    90,   168,   143,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,   204,    12,    13,
      14,     0,     0,    15,    16,     0,    17,    18,    19,    20,
      21,    22,    70,    71,    72,    73,    74,    23,     0,     0,
       0,    24,     0,     0,   166,     1,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,     0,    12,    13,    14,
       0,     0,    15,    16,     0,    17,    18,    19,    20,    21,
      22,     6,     7,     8,     9,    10,    23,     0,     0,     0,
      24,    86,   -86,     1,     2,     3,    52,     5,    88,     0,
       6,     7,     8,     9,    10,   115,     0,     1,     2,     3,
      52,     5,     0,     0,     0,    19,    20,    21,    22,     0,
       0,     0,     0,     0,    23,     0,     0,     0,    24,    19,
      20,    21,    22,     0,     0,     0,     0,     0,    23,     0,
       0,   119,    24,     1,     2,     3,    52,     5,    67,    68,
      69,    70,    71,    72,    73,    74,     0,     0,     0,     0,
       0,     0,    97,     0,     0,    19,    20,    21,    22,     0,
       0,     0,     0,     0,    23,     0,     0,     0,    24,     1,
       2,     3,     4,     5,     6,     7,     8,     9,    10,    11,
       0,    12,    13,    14,     0,     0,    15,    16,     0,    17,
      18,    19,    20,    21,    22,     1,     2,     3,    52,     5,
      23,     0,     0,     0,    24,     0,     0,     0,     0,     1,
       2,     3,    79,     5,     0,     0,     0,    19,    20,    21,
      22,     0,     0,     0,     0,     0,    23,     0,     0,     0,
      24,    19,    20,    21,    22,     0,     0,     0,     0,     0,
      23,     0,     0,     0,    24,    67,    68,    69,    70,    71,
      72,    73,    74,     0,     0,     0,     0,     0,     0,   195,
      67,    68,    69,    70,    71,    72,    73,    74,     0,     0,
       0,     0,     0,   130,    67,    68,    69,    70,    71,    72,
      73,    74,     0,     0,     0,     0,     0,   180,    67,    68,
      69,    70,    71,    72,    73,    74,     0,     0,     0,     0,
       0,   194,    67,    68,    69,    70,    71,    72,    73,    74,
       0,     0,     0,     0,     0,   207,    67,    68,    69,    70,
      71,    72,    73,    74,     0,     0,     0,     0,     0,   223,
      67,    68,    69,    70,    71,    72,    73,    74,     0,     0,
       0,     0,     0,   227,    67,    68,    69,    70,    71,    72,
      73,    74,     0,   111,    67,    68,    69,    70,    71,    72,
      73,    74,     0,   132,    67,    68,    69,    70,    71,    72,
      73,    74,     0,   134,    67,    68,    69,    70,    71,    72,
      73,    74,     0,   138,    67,    68,    69,    70,    71,    72,
      73,    74,     0,   140,    67,    68,    69,    70,    71,    72,
      73,    74,    67,     0,    69,    70,    71,    72,    73,    74
};

static const yytype_int16 yycheck[] =
{
      16,    47,    47,    18,    56,    57,    58,    26,    23,    24,
      39,    55,    56,    57,    58,     6,    45,    29,    39,    29,
      38,     1,    18,    19,    45,     6,    38,    42,    43,    44,
      45,    46,    42,    48,     6,    38,    51,     6,     1,     1,
       3,     4,     5,     6,     7,    41,     8,     9,    10,    11,
      12,    42,    67,    68,    69,    70,    71,    72,    73,    74,
      40,    42,    25,    26,    27,    28,    44,    43,   113,    45,
      42,    34,     6,    42,     6,    38,    39,    39,    35,    36,
      37,    96,    45,    45,    99,     6,    30,    31,    32,    33,
      34,    35,    36,    37,   139,    38,    29,   112,    29,     1,
      44,     3,     4,     5,     6,     7,   125,    38,    42,    42,
      42,    42,   127,    38,   129,   131,   132,   133,   134,    38,
     135,    42,   137,    25,    26,    27,    28,    38,   143,    38,
      29,    29,    34,    42,    38,    43,    38,    45,    38,    38,
     184,    38,   187,    42,    42,   189,     0,    40,    44,   195,
      44,    22,    43,    39,   169,   170,     3,     4,     5,     6,
       7,    39,    39,    44,   216,    38,    40,   182,    30,   185,
     186,    33,    34,    35,    36,    37,    39,   193,    25,    26,
      27,    28,    39,   198,    39,    44,    39,    34,    39,    39,
      39,    38,    29,    39,   209,    39,   211,    44,   214,    39,
      39,    39,   217,   219,    39,   221,     3,     4,     5,     6,
       7,     6,    29,   229,    43,    14,    30,    31,    32,    33,
      34,    35,    36,    37,     6,     6,    42,    42,    25,    26,
      27,    28,    46,     6,    39,    29,    29,    34,    39,    46,
      42,    38,    76,    47,   129,    42,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,   187,    15,    16,
      17,    -1,    -1,    20,    21,    -1,    23,    24,    25,    26,
      27,    28,    33,    34,    35,    36,    37,    34,    -1,    -1,
      -1,    38,    -1,    -1,    41,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    -1,    15,    16,    17,
      -1,    -1,    20,    21,    -1,    23,    24,    25,    26,    27,
      28,     8,     9,    10,    11,    12,    34,    -1,    -1,    -1,
      38,     1,    40,     3,     4,     5,     6,     7,     6,    -1,
       8,     9,    10,    11,    12,     1,    -1,     3,     4,     5,
       6,     7,    -1,    -1,    -1,    25,    26,    27,    28,    -1,
      -1,    -1,    -1,    -1,    34,    -1,    -1,    -1,    38,    25,
      26,    27,    28,    -1,    -1,    -1,    -1,    -1,    34,    -1,
      -1,     1,    38,     3,     4,     5,     6,     7,    30,    31,
      32,    33,    34,    35,    36,    37,    -1,    -1,    -1,    -1,
      -1,    -1,    44,    -1,    -1,    25,    26,    27,    28,    -1,
      -1,    -1,    -1,    -1,    34,    -1,    -1,    -1,    38,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      -1,    15,    16,    17,    -1,    -1,    20,    21,    -1,    23,
      24,    25,    26,    27,    28,     3,     4,     5,     6,     7,
      34,    -1,    -1,    -1,    38,    -1,    -1,    -1,    -1,     3,
       4,     5,     6,     7,    -1,    -1,    -1,    25,    26,    27,
      28,    -1,    -1,    -1,    -1,    -1,    34,    -1,    -1,    -1,
      38,    25,    26,    27,    28,    -1,    -1,    -1,    -1,    -1,
      34,    -1,    -1,    -1,    38,    30,    31,    32,    33,    34,
      35,    36,    37,    -1,    -1,    -1,    -1,    -1,    -1,    44,
      30,    31,    32,    33,    34,    35,    36,    37,    -1,    -1,
      -1,    -1,    -1,    43,    30,    31,    32,    33,    34,    35,
      36,    37,    -1,    -1,    -1,    -1,    -1,    43,    30,    31,
      32,    33,    34,    35,    36,    37,    -1,    -1,    -1,    -1,
      -1,    43,    30,    31,    32,    33,    34,    35,    36,    37,
      -1,    -1,    -1,    -1,    -1,    43,    30,    31,    32,    33,
      34,    35,    36,    37,    -1,    -1,    -1,    -1,    -1,    43,
      30,    31,    32,    33,    34,    35,    36,    37,    -1,    -1,
      -1,    -1,    -1,    43,    30,    31,    32,    33,    34,    35,
      36,    37,    -1,    39,    30,    31,    32,    33,    34,    35,
      36,    37,    -1,    39,    30,    31,    32,    33,    34,    35,
      36,    37,    -1,    39,    30,    31,    32,    33,    34,    35,
      36,    37,    -1,    39,    30,    31,    32,    33,    34,    35,
      36,    37,    -1,    39,    30,    31,    32,    33,    34,    35,
      36,    37,    30,    -1,    32,    33,    34,    35,    36,    37
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    15,    16,    17,    20,    21,    23,    24,    25,
      26,    27,    28,    34,    38,    49,    50,    51,    52,    55,
      56,    57,    58,    65,    66,    67,    68,    69,    70,    71,
      73,    75,    29,    38,    42,    38,    38,    38,    38,    44,
      68,    38,     6,    44,    58,    38,    38,    38,    38,    58,
      58,     0,    51,     6,    42,    44,    44,    30,    31,    32,
      33,    34,    35,    36,    37,    44,    40,    58,     1,     6,
      58,    59,    60,    58,     1,    58,     1,    58,     6,    55,
      56,    57,    72,    58,    22,    58,    42,    44,     6,    42,
      61,    63,     6,    61,    63,     6,    61,    63,     6,    61,
      63,    39,    29,    38,    43,     1,    58,    58,    58,     1,
      58,    58,    58,    58,    58,    50,    39,    29,    39,    45,
      43,    39,    39,    39,    39,    42,     6,    44,    39,    38,
      39,    58,    39,    42,    58,    61,    62,    64,    39,    39,
      39,    39,    39,    39,    39,    39,    39,    39,    39,    58,
       1,    53,    54,    55,     6,    42,    41,    58,    60,    29,
      42,    68,    68,    68,    68,    58,    58,    40,    55,    44,
      43,    43,    45,    43,    45,    39,    39,    45,     6,    29,
      43,    58,    58,    14,    43,    44,    74,     6,    42,    58,
      61,    68,     1,    68,    54,    61,     6,    43,    68,    42,
      57,    18,    19,    41,    39,    58,    29,    29,    58,    39,
      58,    46,    68,    43,    42,    63,    58,    43,    68,    46,
      68,    68
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    48,    49,    50,    50,    51,    51,    51,    51,    51,
      51,    51,    51,    51,    51,    52,    52,    52,    53,    53,
      53,    54,    55,    55,    55,    55,    55,    56,    56,    56,
      57,    57,    57,    58,    58,    58,    58,    58,    58,    58,
      58,    58,    58,    58,    58,    58,    58,    58,    58,    58,
      58,    58,    58,    58,    58,    58,    58,    58,    58,    58,
      58,    58,    58,    58,    58,    58,    59,    59,    59,    60,
      60,    61,    62,    62,    63,    64,    64,    65,    66,    66,
      66,    66,    66,    67,    67,    67,    69,    68,    70,    70,
      71,    72,    72,    73,    74,    74,    74,    75
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     2,     2,     2,     3,     2,
       2,     1,     1,     1,     1,     6,     6,     6,     0,     1,
       3,     2,     1,     1,     1,     1,     1,     4,     6,     8,
       3,     6,     9,     1,     1,     1,     1,     1,     4,     7,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     3,     3,     2,     0,     1,     3,     1,
       3,     3,     1,     3,     3,     1,     3,     5,     1,     1,
       1,     1,     1,     5,     7,     5,     0,     4,     5,     5,
       9,     1,     1,     7,     5,     4,     0,     8
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
  case 15: /* function_declaration: type IDENTIFIER LPAREN parameter_list RPAREN block  */
#line 187 "parser.y"
    {
        register_function_signature((yyvsp[-4].sval), (yyvsp[-5].sval), param_type_buffer, param_type_count);
        param_type_count = 0;
    }
#line 1484 "parser.tab.c"
    break;

  case 16: /* function_declaration: type IDENTIFIER LPAREN error RPAREN block  */
#line 192 "parser.y"
    {
        yyerror("Error: lista de parámetros inválida en declaración de función");
        yyclearin; yyerrok;
    }
#line 1493 "parser.tab.c"
    break;

  case 17: /* function_declaration: type IDENTIFIER LPAREN parameter_list RPAREN error  */
#line 197 "parser.y"
    {
        yyerror("Error: bloque de función mal formado o faltante");
        yyclearin; yyerrok;
    }
#line 1502 "parser.tab.c"
    break;

  case 19: /* parameter_list: parameter  */
#line 205 "parser.y"
                { param_type_buffer[0] = strdup((yyvsp[0].sval)); param_type_count = 1; }
#line 1508 "parser.tab.c"
    break;

  case 20: /* parameter_list: parameter_list COMMA parameter  */
#line 206 "parser.y"
                                     { param_type_buffer[param_type_count++] = strdup((yyvsp[0].sval)); }
#line 1514 "parser.tab.c"
    break;

  case 21: /* parameter: type IDENTIFIER  */
#line 210 "parser.y"
                      { (yyval.sval) = (yyvsp[-1].sval); }
#line 1520 "parser.tab.c"
    break;

  case 22: /* type: INT  */
#line 214 "parser.y"
             { (yyval.sval) = "int"; }
#line 1526 "parser.tab.c"
    break;

  case 23: /* type: FLOAT  */
#line 215 "parser.y"
             { (yyval.sval) = "float"; }
#line 1532 "parser.tab.c"
    break;

  case 24: /* type: BOOL  */
#line 216 "parser.y"
             { (yyval.sval) = "bool"; }
#line 1538 "parser.tab.c"
    break;

  case 25: /* type: STRING  */
#line 217 "parser.y"
             { (yyval.sval) = "string"; }
#line 1544 "parser.tab.c"
    break;

  case 26: /* type: VOID  */
#line 218 "parser.y"
             { (yyval.sval) = "void"; }
#line 1550 "parser.tab.c"
    break;

  case 27: /* variable_declaration: type IDENTIFIER ASSIGN expression  */
#line 223 "parser.y"
      {
          register_variable((yyvsp[-2].sval), (yyvsp[-3].sval));
      }
#line 1558 "parser.tab.c"
    break;

  case 28: /* variable_declaration: type LBRACKET RBRACKET IDENTIFIER ASSIGN list  */
#line 227 "parser.y"
      {
          register_variable((yyvsp[-2].sval), (yyvsp[-5].sval)); // arreglo unidimensional
      }
#line 1566 "parser.tab.c"
    break;

  case 29: /* variable_declaration: type LBRACKET RBRACKET LBRACKET RBRACKET IDENTIFIER ASSIGN matrix  */
#line 231 "parser.y"
      {
          register_variable((yyvsp[-2].sval), (yyvsp[-7].sval)); // matriz
      }
#line 1574 "parser.tab.c"
    break;

  case 62: /* expression: IDENTIFIER LPAREN error RPAREN  */
#line 273 "parser.y"
    {
        yyerror("Error: argumentos inválidos en llamada a función");
        yyclearin; yyerrok;
    }
#line 1583 "parser.tab.c"
    break;

  case 63: /* expression: expression '+' error  */
#line 278 "parser.y"
    {
        yyerror("Error: expresión incompleta tras '+'");
        yyclearin; yyerrok;
    }
#line 1592 "parser.tab.c"
    break;

  case 64: /* expression: expression REL_OP error  */
#line 283 "parser.y"
    {
        yyerror("Error: lado derecho de comparación faltante");
        yyclearin; yyerrok;
    }
#line 1601 "parser.tab.c"
    break;

  case 70: /* argument: IDENTIFIER ASSIGN expression  */
#line 298 "parser.y"
                                   { printf("Parámetro nombrado: %s\n", (yyvsp[-2].sval)); }
#line 1607 "parser.tab.c"
    break;

  case 85: /* if_statement: IF LPAREN error RPAREN block  */
#line 334 "parser.y"
    {
        yyerror("Error: condición inválida en if");
        yyclearin; yyerrok;
    }
#line 1616 "parser.tab.c"
    break;

  case 86: /* $@1: %empty  */
#line 341 "parser.y"
    {
        enter_scope();
    }
#line 1624 "parser.tab.c"
    break;

  case 87: /* block: $@1 LBRACE declaration_or_statement_list RBRACE  */
#line 345 "parser.y"
    {
        exit_scope();
    }
#line 1632 "parser.tab.c"
    break;

  case 89: /* while_statement: WHILE LPAREN error RPAREN block  */
#line 353 "parser.y"
    {
        yyerror("Error: condición inválida en while");
        yyclearin; yyerrok;
    }
#line 1641 "parser.tab.c"
    break;


#line 1645 "parser.tab.c"

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

#line 382 "parser.y"


void yyerror(const char *s) {
    fprintf(stderr, "Error en la línea %d: %s\n", yylineno, s);
}

