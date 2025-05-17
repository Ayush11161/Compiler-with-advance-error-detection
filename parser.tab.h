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
    IDENTIFIER = 258,              /* IDENTIFIER  */
    INTEGER_LITERAL = 259,         /* INTEGER_LITERAL  */
    FLOAT_LITERAL = 260,           /* FLOAT_LITERAL  */
    CHAR_LITERAL = 261,            /* CHAR_LITERAL  */
    STRING_LITERAL = 262,          /* STRING_LITERAL  */
    INT = 263,                     /* INT  */
    CHAR = 264,                    /* CHAR  */
    VOID = 265,                    /* VOID  */
    FLOAT_TYPE = 266,              /* FLOAT_TYPE  */
    IF = 267,                      /* IF  */
    ELSE = 268,                    /* ELSE  */
    WHILE = 269,                   /* WHILE  */
    FOR = 270,                     /* FOR  */
    RETURN = 271,                  /* RETURN  */
    STRUCT = 272,                  /* STRUCT  */
    TYPEDEF = 273,                 /* TYPEDEF  */
    CONST = 274,                   /* CONST  */
    STATIC = 275,                  /* STATIC  */
    EXTERN = 276,                  /* EXTERN  */
    SIZEOF = 277,                  /* SIZEOF  */
    PLUS = 278,                    /* PLUS  */
    MINUS = 279,                   /* MINUS  */
    MULTIPLY = 280,                /* MULTIPLY  */
    DIVIDE = 281,                  /* DIVIDE  */
    MODULO = 282,                  /* MODULO  */
    ASSIGN = 283,                  /* ASSIGN  */
    EQUAL = 284,                   /* EQUAL  */
    NOT_EQUAL = 285,               /* NOT_EQUAL  */
    LESS = 286,                    /* LESS  */
    LESS_EQUAL = 287,              /* LESS_EQUAL  */
    GREATER = 288,                 /* GREATER  */
    GREATER_EQUAL = 289,           /* GREATER_EQUAL  */
    AND = 290,                     /* AND  */
    OR = 291,                      /* OR  */
    NOT = 292,                     /* NOT  */
    BITWISE_AND = 293,             /* BITWISE_AND  */
    BITWISE_OR = 294,              /* BITWISE_OR  */
    BITWISE_XOR = 295,             /* BITWISE_XOR  */
    BITWISE_NOT = 296,             /* BITWISE_NOT  */
    LEFT_SHIFT = 297,              /* LEFT_SHIFT  */
    RIGHT_SHIFT = 298,             /* RIGHT_SHIFT  */
    INCREMENT = 299,               /* INCREMENT  */
    DECREMENT = 300,               /* DECREMENT  */
    ARROW = 301,                   /* ARROW  */
    DOT = 302,                     /* DOT  */
    SEMICOLON = 303,               /* SEMICOLON  */
    COMMA = 304,                   /* COMMA  */
    LEFT_PAREN = 305,              /* LEFT_PAREN  */
    RIGHT_PAREN = 306,             /* RIGHT_PAREN  */
    LEFT_BRACE = 307,              /* LEFT_BRACE  */
    RIGHT_BRACE = 308,             /* RIGHT_BRACE  */
    LEFT_BRACKET = 309,            /* LEFT_BRACKET  */
    RIGHT_BRACKET = 310,           /* RIGHT_BRACKET  */
    COLON = 311,                   /* COLON  */
    QUESTION = 312                 /* QUESTION  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 55 "parser.y"

    int int_val;
    float float_val;
    char char_val;
    char* string_val;

#line 128 "parser.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */
