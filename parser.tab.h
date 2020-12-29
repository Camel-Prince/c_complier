/* A Bison parser, made by GNU Bison 2.3.  */
#include "abstract_syntax_tree/AstNode.h"
#include "symbol_table/symbol.h"
#include "intermidiate_code/interCode.h"
#include "asm/AsmCode.h"
#include "asm/AsmGenerate.h"

/* Skeleton interface for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     ASSIGN_OP = 258,
     OR = 259,
     AND = 260,
     SINGLAND = 261,
     NE_OP = 262,
     EQ_OP = 263,
     LE_OP = 264,
     GE_OP = 265,
     LT_OP = 266,
     GT_OP = 267,
     SUB = 268,
     ADD = 269,
     MOD = 270,
     DIV = 271,
     MUL = 272,
     POW = 273,
     NOT = 274,
     PRINTF = 275,
     SCANF = 276,
     IDENTIFIER = 277,
     CONST = 278,
     LOWER_THAN_ELSE = 279,
     EOL = 280,
     D_QUO = 281,
     S_QUO = 282,
     SEMI = 283,
     COMMA = 284,
     CONTINUE = 285,
     BREAK = 286,
     VOID = 287,
     INT = 288,
     RETURN = 289,
     THEN = 290,
     ELSE = 291,
     IF = 292,
     FOR = 293,
     WHILE = 294
   };
#endif
/* Tokens.  */
#define ASSIGN_OP 258
#define OR 259
#define AND 260
#define SINGLAND 261
#define NE_OP 262
#define EQ_OP 263
#define LE_OP 264
#define GE_OP 265
#define LT_OP 266
#define GT_OP 267
#define SUB 268
#define ADD 269
#define MOD 270
#define DIV 271
#define MUL 272
#define POW 273
#define NOT 274
#define PRINTF 275
#define SCANF 276
#define IDENTIFIER 277
#define CONST 278
#define LOWER_THAN_ELSE 279
#define EOL 280
#define D_QUO 281
#define S_QUO 282
#define SEMI 283
#define COMMA 284
#define CONTINUE 285
#define BREAK 286
#define VOID 287
#define INT 288
#define RETURN 289
#define THEN 290
#define ELSE 291
#define IF 292
#define FOR 293
#define WHILE 294




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 18 "parser.y"
{
  AbstractAstNode* ast;
  char* str;
}
/* Line 1529 of yacc.c.  */
#line 132 "parser.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

