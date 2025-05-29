/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    INT_LITERAL = 258,             /* INT_LITERAL  */
    FLOAT_LITERAL = 259,           /* FLOAT_LITERAL  */
    STRING_LITERAL = 260,          /* STRING_LITERAL  */
    IDENTIFIER = 261,              /* IDENTIFIER  */
    BOOL_LITERAL = 262,            /* BOOL_LITERAL  */
    INT = 263,                     /* INT  */
    FLOAT = 264,                   /* FLOAT  */
    BOOL = 265,                    /* BOOL  */
    STRING = 266,                  /* STRING  */
    VOID = 267,                    /* VOID  */
    IF = 268,                      /* IF  */
    ELSE = 269,                    /* ELSE  */
    WHILE = 270,                   /* WHILE  */
    FOR = 271,                     /* FOR  */
    SWITCH = 272,                  /* SWITCH  */
    CASE = 273,                    /* CASE  */
    DEFAULT = 274,                 /* DEFAULT  */
    BREAK = 275,                   /* BREAK  */
    TRY = 276,                     /* TRY  */
    CATCH = 277,                   /* CATCH  */
    ASSERT = 278,                  /* ASSERT  */
    RETURN = 279,                  /* RETURN  */
    SUM = 280,                     /* SUM  */
    PROD = 281,                    /* PROD  */
    MAX = 282,                     /* MAX  */
    MIN = 283,                     /* MIN  */
    ASSIGN = 284,                  /* ASSIGN  */
    REL_OP = 285,                  /* REL_OP  */
    OR = 286,                      /* OR  */
    AND = 287,                     /* AND  */
    LPAREN = 288,                  /* LPAREN  */
    RPAREN = 289,                  /* RPAREN  */
    LBRACE = 290,                  /* LBRACE  */
    RBRACE = 291,                  /* RBRACE  */
    LBRACKET = 292,                /* LBRACKET  */
    RBRACKET = 293,                /* RBRACKET  */
    SEMICOLON = 294,               /* SEMICOLON  */
    COMMA = 295,                   /* COMMA  */
    COLON = 296,                   /* COLON  */
    UMINUS = 297                   /* UMINUS  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 127 "parser.y"

    int    ival;
    double fval;
    char  *sval;
    int    bval;

#line 113 "parser.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */
