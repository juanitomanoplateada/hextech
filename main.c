/* ============================================================================
 * main.c - Programa principal para ejecutar el analizador léxico y sintáctico
 * Compilación: bison -d parser.y && flex lexer.l && gcc lex.yy.c parser.tab.c main.c -o parser -lm
 * Uso: ./parser archivo_entrada
 * ========================================================================== */

#include <stdio.h>

extern int yyparse();
extern FILE *yyin;

int main(int argc, char **argv) {
    if (argc > 1) {
        yyin = fopen(argv[1], "r");
        if (!yyin) {
            perror("No se pudo abrir el archivo");
            return 1;
        }
    }

    if (yyparse() == 0) {
        printf("Entrada válida.\n");
    } else {
        printf("Entrada no válida.\n");
    }

    return 0;
}

