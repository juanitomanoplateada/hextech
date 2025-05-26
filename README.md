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
