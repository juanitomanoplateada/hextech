/* ============================================================================
 * parser.y - Analizador sintáctico para lenguaje científico modular
 * Cumple con: Tipado explícito, operaciones de reducción, estructuras de control,
 * funciones con sobrecarga, parámetros nombrados, funciones anidadas,
 * manejo de errores sintácticos específicos y excepciones try-catch.
 * ========================================================================== */

/* parser.y */
%{
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

%}

%union {
    int    ival;
    double fval;
    char  *sval;
    int    bval;
}

%token <ival> INT_LITERAL
%token <fval> FLOAT_LITERAL
%token <sval> STRING_LITERAL
%token <sval> IDENTIFIER
%token <bval> BOOL_LITERAL

%token INT FLOAT BOOL STRING VOID
%token IF ELSE WHILE FOR SWITCH CASE DEFAULT BREAK
%token TRY CATCH ASSERT RETURN
%token SUM PROD MAX MIN

%token ASSIGN REL_OP
%token OR AND
%token '+' '-' '*' '/' '%'
%token LPAREN RPAREN LBRACE RBRACE LBRACKET RBRACKET
%token SEMICOLON COMMA COLON

%type <sval> type parameter

%left OR
%left AND
%left REL_OP
%left '+' '-'
%left '*' '/' '%'
%right UMINUS
%right ASSIGN

%%

program:
      declaration_or_statement_list
;

declaration_or_statement_list:
      declaration_or_statement
    | declaration_or_statement_list declaration_or_statement
;

declaration_or_statement:
      variable_declaration SEMICOLON
    | assignment SEMICOLON
    | expression SEMICOLON
    | RETURN expression SEMICOLON
    | RETURN SEMICOLON
    | BREAK SEMICOLON
    | assert_statement
    | function_declaration
    | control_structure
    | block
;

function_declaration:
    type IDENTIFIER LPAREN parameter_list RPAREN block
    {
        register_function_signature($2, $1, param_type_buffer, param_type_count);
        param_type_count = 0;
    }
  | type IDENTIFIER LPAREN error RPAREN block
    {
        yyerror("Error: lista de parámetros inválida en declaración de función");
        yyclearin; yyerrok;
    }
  | type IDENTIFIER LPAREN parameter_list RPAREN error
    {
        yyerror("Error: bloque de función mal formado o faltante");
        yyclearin; yyerrok;
    }
  ;

parameter_list:
      /* vacío */
    | parameter { param_type_buffer[0] = strdup($1); param_type_count = 1; }
    | parameter_list COMMA parameter { param_type_buffer[param_type_count++] = strdup($3); }
    ;

parameter:
      type IDENTIFIER { $$ = $1; }
    ;

type:
      INT    { $$ = "int"; }
    | FLOAT  { $$ = "float"; }
    | BOOL   { $$ = "bool"; }
    | STRING { $$ = "string"; }
    | VOID   { $$ = "void"; }
    ;

variable_declaration:
      type IDENTIFIER ASSIGN expression
      {
          register_variable($2, $1);
      }
    | type LBRACKET RBRACKET IDENTIFIER ASSIGN list
      {
          register_variable($4, $1); // arreglo unidimensional
      }
    | type LBRACKET RBRACKET LBRACKET RBRACKET IDENTIFIER ASSIGN matrix
      {
          register_variable($6, $1); // matriz
      }
;

assignment:
      IDENTIFIER ASSIGN expression
    | IDENTIFIER LBRACKET expression RBRACKET ASSIGN expression
    | IDENTIFIER LBRACKET expression RBRACKET LBRACKET expression RBRACKET ASSIGN expression
    ;

expression:
      INT_LITERAL
    | FLOAT_LITERAL
    | STRING_LITERAL
    | BOOL_LITERAL
    | IDENTIFIER
    | IDENTIFIER LBRACKET expression RBRACKET
    | IDENTIFIER LBRACKET expression RBRACKET LBRACKET expression RBRACKET
    | expression '+' expression
    | expression '-' expression
    | expression '*' expression
    | expression '/' expression
    | expression '%' expression
    | expression REL_OP expression
    | expression AND expression
    | expression OR expression
    | LPAREN expression RPAREN
    | SUM LPAREN list RPAREN
    | SUM LPAREN matrix RPAREN
    | SUM LPAREN IDENTIFIER RPAREN
    | PROD LPAREN list RPAREN
    | PROD LPAREN matrix RPAREN
    | PROD LPAREN IDENTIFIER RPAREN
    | MAX LPAREN list RPAREN
    | MAX LPAREN matrix RPAREN
    | MAX LPAREN IDENTIFIER RPAREN
    | MIN LPAREN list RPAREN
    | MIN LPAREN matrix RPAREN
    | MIN LPAREN IDENTIFIER RPAREN
    | IDENTIFIER LPAREN argument_list RPAREN
    | IDENTIFIER LPAREN error RPAREN
    {
        yyerror("Error: argumentos inválidos en llamada a función");
        yyclearin; yyerrok;
    }
    | expression '+' error
    {
        yyerror("Error: expresión incompleta tras '+'");
        yyclearin; yyerrok;
    }
    | expression REL_OP error
    {
        yyerror("Error: lado derecho de comparación faltante");
        yyclearin; yyerrok;
    }
    | '-' expression    %prec UMINUS
    ;

argument_list:
      /* vacío */
    | argument
    | argument_list COMMA argument
    ;

argument:
      expression
    | IDENTIFIER ASSIGN expression { printf("Parámetro nombrado: %s\n", $1); }   
    ;

list:
      LBRACKET expr_list RBRACKET
    ;

expr_list:
      expression
    | expr_list COMMA expression
    ;

matrix:
      LBRACKET matrix_rows RBRACKET
    ;

matrix_rows:
      list
    | matrix_rows COMMA list
    ;

assert_statement: ASSERT LPAREN expression RPAREN SEMICOLON
    ;

control_structure:
      if_statement
    | while_statement
    | for_statement
    | switch_statement
    | try_statement
    ;

if_statement:
    IF LPAREN expression RPAREN block
  | IF LPAREN expression RPAREN block ELSE block
  | IF LPAREN error RPAREN block
    {
        yyerror("Error: condición inválida en if");
        yyclearin; yyerrok;
    }
;

block:
    {
        enter_scope();
    }
    LBRACE declaration_or_statement_list RBRACE
    {
        exit_scope();
    }
;

while_statement:
    WHILE LPAREN expression RPAREN block
  | WHILE LPAREN error RPAREN block
    {
        yyerror("Error: condición inválida en while");
        yyclearin; yyerrok;
    }
  ;

for_statement:
      FOR LPAREN for_init SEMICOLON expression SEMICOLON assignment RPAREN block
    ;

for_init:
      assignment
    | variable_declaration
    ;

switch_statement:
      SWITCH LPAREN expression RPAREN LBRACE case_list RBRACE
    ;

case_list:
      case_list CASE expression COLON block
    | case_list DEFAULT COLON block
    | /* vacío */
    ;

try_statement:
      TRY block CATCH LPAREN type IDENTIFIER RPAREN block
    ;

%%

void yyerror(const char *s) {
    fprintf(stderr, "Error en la línea %d: %s\n", yylineno, s);
}

