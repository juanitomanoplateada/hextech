/* ============================================================================
 * lexer.l - Analizador léxico para lenguaje científico modular
 * Detecta tipos explícitos, estructuras de control, operadores aritméticos
 * y de reducción, soporte para parámetros nombrados, vectores, matrices,
 * control de errores, y tokens personalizados para análisis sintáctico.
 * ========================================================================== */

%option noyywrap
%{
#include "parser.tab.h"
#include <stdlib.h>
#include <string.h>
%}

%%
[ \t\r]+                ;
\n                      { yylineno++; }

"//".*                  ;
"/*"([^*]|\*+[^*/])*"*/" ;

"confluir"              { return SUM; }
"produzcar"             { return PROD; }
"maxar"                 { return MAX; }
"minar"                 { return MIN; }

"runa_cronoentera"      { return INT; }
"runa_etérflotante"     { return FLOAT; }
"runa_umbralbooleana"   { return BOOL; }
"runa_arcadenal"        { return STRING; }
"runa_vicvoid"          { return VOID; }

"amanecer_arcano_si"    { return IF; }
"entonces_ocaso_arcano" { return ELSE; }
"vórtice_insano"        { return WHILE; }
"espiral_arcana"        { return FOR; }
"oráculo"               { return SWITCH; }
"visión"                { return CASE; }
"eco"                   { return DEFAULT; }
"hexbreak"              { return BREAK; }
"gloriosa_evolución"    { return TRY; }
"catarsis_arcana"       { return CATCH; }
"axioma_evolutivo"      { return ASSERT; }
"evolucionar"           { return RETURN; }

"=="                    { return REL_OP; }
"!="                    { return REL_OP; }
"<="                    { return REL_OP; }
">="                    { return REL_OP; }
"<"                     { return REL_OP; }
">"                     { return REL_OP; }

"="                     { return ASSIGN; }
"||"                    { return OR; }
"&&"                    { return AND; }

"\+"                    { return '+'; }
"-"                     { return '-'; }
"\*"                    { return '*'; }
"/"                     { return '/'; }
"%"                     { return '%'; }

"\("                    { return LPAREN; }
"\)"                    { return RPAREN; }
"\{"                    { return LBRACE; }
"\}"                    { return RBRACE; }
"\["                    { return LBRACKET; }
"\]"                    { return RBRACKET; }
"?"                     { return SEMICOLON; }
","                     { return COMMA; }
":"                     { return COLON; }

[0-9]+                  { yylval.ival = atoi(yytext); return INT_LITERAL; }
[0-9]+\.[0-9]+          { yylval.fval = atof(yytext); return FLOAT_LITERAL; }
"cargada"               { yylval.bval = 1; return BOOL_LITERAL; }
"agotada"               { yylval.bval = 0; return BOOL_LITERAL; }
"\""([^\"]|\\\")*"\""   { yylval.sval = strdup(yytext); return STRING_LITERAL; }
[a-zA-Z_][a-zA-Z_0-9]*  { yylval.sval = strdup(yytext); return IDENTIFIER; }

%%

