# Analizador Léxico y Sintáctico con Flex y Bison

Este proyecto implementa un analizador léxico y sintáctico en C utilizando **Flex** y **Bison**. El programa procesa archivos `.raaa` que contienen código fuente en un lenguaje personalizado.

## Estructura del Proyecto

- `lexer.l` — Archivo de definición léxica (Flex).
- `parser.y` — Archivo de definición sintáctica (Bison).
- `main.c` — Función principal del analizador.
- `test.raaa`, `test1.raaa`, ... — Archivos de prueba de entrada.
- `Makefile` — Sistema de construcción automático.
- `README.md` — Este archivo.

## Requisitos

- `gcc`
- `flex`
- `bison`
- `make`

## Compilación

Ejecuta el siguiente comando en terminal:

```bash
make
```

Esto genera los archivos intermedios y el ejecutable `parser`.

## Uso

Puedes ejecutar el analizador sobre un archivo `.raaa` con:

```bash
make test
```

Este comando ejecutará el analizador con todos los archivos de prueba especificados en el `Makefile`.

También puedes ejecutarlo directamente:

```bash
./parser < test.raaa
```

## Limpieza

Para eliminar todos los archivos generados:

```bash
make clean
```

## Autor

Proyecto desarrollado para fines académicos o experimentales.

---

## Detalles del Analizador Léxico (`lexer.l`)

Este archivo define los patrones para reconocer los siguientes tokens del lenguaje:

- **SUM**: Detectado con el patrón `confluir`
- **PROD**: Detectado con el patrón `produzcar`
- **MAX**: Detectado con el patrón `maxar`
- **MIN**: Detectado con el patrón `minar`
- **INT**: Detectado con el patrón `runa_cronoentera`
- **FLOAT**: Detectado con el patrón `runa_et`
- **BOOL**: Detectado con el patrón `runa_umbralbooleana`
- **STRING**: Detectado con el patrón `runa_arcadenal`
- **VOID**: Detectado con el patrón `runa_vicvoid`
- **IF**: Detectado con el patrón `amanecer_arcano_si`
- **ELSE**: Detectado con el patrón `entonces_ocaso_arcano`
- **WHILE**: Detectado con el patrón `v`
- **FOR**: Detectado con el patrón `espiral_arcana`
- **SWITCH**: Detectado con el patrón `or`
- **CASE**: Detectado con el patrón `visi`
- **DEFAULT**: Detectado con el patrón `eco`
- **BREAK**: Detectado con el patrón `hexbreak`
- **TRY**: Detectado con el patrón `gloriosa_evoluci`
- **CATCH**: Detectado con el patrón `catarsis_arcana`
- **ASSERT**: Detectado con el patrón `axioma_evolutivo`
- **RETURN**: Detectado con el patrón `evolucionar`
- **INT_LITERAL**: Detectado con el patrón `yylval`
- **FLOAT_LITERAL**: Detectado con el patrón `yylval`
- **BOOL_LITERAL**: Detectado con el patrón `cargada`
- **BOOL_LITERAL**: Detectado con el patrón `agotada`
- **STRING_LITERAL**: Detectado con el patrón `yylval`
- **IDENTIFIER**: Detectado con el patrón `a`
- **CADENA**: Reconoce textos entre comillas dobles, incluyendo secuencias de escape como `\n`, `\t`.
- **COMENTARIOS**: Soporta comentarios de línea (`//`) y de bloque (`/* ... */`), que son ignorados.


---

## Detalles del Analizador Sintáctico (`parser.y`)

Este archivo define la gramática del lenguaje, incluyendo tokens, reglas de producción y el símbolo inicial.

### Tokens declarados:

- `INT`
- `FLOAT`
- `BOOL`
- `STRING`
- `VOID`
- `IF`
- `ELSE`
- `WHILE`
- `FOR`
- `SWITCH`
- `CASE`
- `DEFAULT`
- `BREAK`
- `TRY`
- `CATCH`
- `ASSERT`
- `RETURN`
- `SUM`
- `PROD`
- `MAX`
- `MIN`
- `ASSIGN`
- `REL_OP`
- `OR`
- `AND`
- `LPAREN`
- `RPAREN`
- `LBRACE`
- `RBRACE`
- `LBRACKET`
- `RBRACKET`
- `SEMICOLON`
- `COMMA`
- `COLON`

### Reglas de producción definidas:

- `argument`
- `argument_list`
- `assert_statement`
- `assignment`
- `block`
- `case_list`
- `control_structure`
- `declaration_or_statement`
- `expr_list`
- `expression`
- `for_init`
- `for_statement`
- `function_declaration`
- `if_statement`
- `list`
- `matrix`
- `matrix_rows`
- `parameter`
- `parameter_list`
- `program`
- `switch_statement`
- `try_statement`
- `type`
- `variable_declaration`
- `while_statement`

También se incluye manejo de errores sintácticos con la directiva especial `error`, que permite capturar y reportar errores gramaticales durante el análisis.
