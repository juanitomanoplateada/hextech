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

## Detalles del Analizador Léxico (`lexer.l`)

El archivo `lexer.l` define los patrones léxicos del lenguaje. Utiliza expresiones regulares para identificar los siguientes tipos de tokens:

- **Palabras clave**: como `si`, `sino`, `mientras`, `repetir`, etc.
- **Identificadores**: variables que empiezan con una letra y pueden contener letras, dígitos o guiones bajos.
- **Literales numéricos**: números enteros y flotantes, incluyendo notación decimal.
- **Cadenas de texto**: delimitadas por comillas dobles, admiten secuencias de escape como `\n`, `\t`.
- **Operadores**: aritméticos (`+`, `-`, `*`, `/`), lógicos (`&&`, `||`, `!`), de comparación (`==`, `!=`, `<`, `>`, `<=`, `>=`).
- **Comentarios**: línea (`// comentario`) o bloque (`/* comentario */`), ignorados por el analizador.
- **Delimitadores**: paréntesis, corchetes, punto y coma, coma, llaves, etc.

Cada token reconocido es enviado al parser con `return TOKEN;`, donde `TOKEN` es un valor definido por el parser (`parser.y`).

Además, se incluye manejo de errores léxicos con retroalimentación al usuario indicando línea y columna.


## Detalles del Analizador Sintáctico (`parser.y`)

El archivo `parser.y` define la gramática del lenguaje y las reglas de producción que validan la estructura del programa.

### Componentes clave:

- **%token**: Define todos los tokens que el lexer puede retornar.
- **%start**: Define el símbolo inicial (ej. `programa` o `inicio`).
- **Reglas de producción**: Describe cómo se forman instrucciones válidas combinando tokens.

### Ejemplos de reglas implementadas:

- **Declaraciones**: Reglas para definir variables o constantes.
- **Expresiones**: Aritméticas, booleanas y comparaciones, con precedencia y asociatividad adecuadas.
- **Sentencias de control**: `if-else`, `while`, `for`, `switch`, entre otras.
- **Bloques**: Agrupación de instrucciones con llaves `{ ... }`.
- **Funciones**: Definición y llamada de funciones con parámetros.
- **Errores sintácticos**: Manejados con la directiva `error` para recuperar el análisis y mostrar mensajes amigables.

El parser está diseñado para construir el árbol sintáctico y validar estructuras válidas, notificando errores con contexto detallado.

