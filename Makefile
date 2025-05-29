# Herramientas
LEX = flex
YACC = bison
CC = cc
EXEC = parser

# Archivos
LEX_FILE = lexer.l
YACC_FILE = parser.y
MAIN_FILE = main.c

# Archivos generados
LEX_C = lex.yy.c
YACC_C = parser.tab.c
YACC_H = parser.tab.h

# Regla principal
all: $(EXEC)

$(EXEC): $(LEX_C) $(YACC_C) $(MAIN_FILE)
	$(CC) $(LEX_C) $(YACC_C) $(MAIN_FILE) -o $(EXEC) -lm

$(LEX_C): $(LEX_FILE) $(YACC_H)
	$(LEX) $(LEX_FILE)

$(YACC_C) $(YACC_H): $(YACC_FILE)
	$(YACC) -d $(YACC_FILE)

# Ejecutar el parser con varios archivos de prueba
test: $(EXEC)
	./$(EXEC) < test.raaa
	./$(EXEC) < test1.raaa
	./$(EXEC) < test2.raaa
	./$(EXEC) < test3.raaa
	./$(EXEC) < test4.raaa
	./$(EXEC) < test5.raaa

test_errors: $(EXEC)
	./$(EXEC) < test_errors.raaa
	
# Limpiar archivos generados
clean:
	rm -f $(LEX_C) $(YACC_C) $(YACC_H) $(EXEC)
