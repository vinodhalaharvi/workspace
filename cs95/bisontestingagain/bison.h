/* A Bison parser, made by GNU Bison 2.3.  */

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
     IDENTIFIER = 258,
     STRING = 259,
     BREAK = 260,
     CHAR = 261,
     CONTINUE = 262,
     DO = 263,
     ELSE = 264,
     FOR = 265,
     GOTO = 266,
     IF = 267,
     INT = 268,
     LONG = 269,
     RETURN = 270,
     SHORT = 271,
     SIGNED = 272,
     UNSIGNED = 273,
     VOID = 274,
     WHILE = 275,
     LEFT_PAREN = 276,
     RIGHT_PAREN = 277,
     LEFT_SQUARE = 278,
     RIGHT_SQUARE = 279,
     LEFT_CURLY = 280,
     RIGHT_CURLY = 281,
     AMPERSAND = 282,
     ASTERISK = 283,
     CARET = 284,
     COLON = 285,
     COMMA = 286,
     EQUAL = 287,
     EXCLAMATION = 288,
     GREATER = 289,
     LESS = 290,
     MINUS = 291,
     PERCENT = 292,
     PLUS = 293,
     SEMICOLON = 294,
     SLASH = 295,
     QUESTION = 296,
     TILDE = 297,
     VBAR = 298,
     AMPERSAND_AMPERSAND = 299,
     AMPERSAND_EQUAL = 300,
     ASTERISK_EQUAL = 301,
     CARET_EQUAL = 302,
     EQUAL_EQUAL = 303,
     EXCLAMATION_EQUAL = 304,
     GREATER_EQUAL = 305,
     GREATER_GREATER = 306,
     GREATER_GREATER_EQUAL = 307,
     LESS_EQUAL = 308,
     LESS_LESS = 309,
     LESS_LESS_EQUAL = 310,
     MINUS_EQUAL = 311,
     MINUS_MINUS = 312,
     PERCENT_EQUAL = 313,
     PLUS_EQUAL = 314,
     PLUS_PLUS = 315,
     SLASH_EQUAL = 316,
     VBAR_EQUAL = 317,
     VBAR_VBAR = 318,
     NUMBER = 319
   };
#endif
/* Tokens.  */
#define IDENTIFIER 258
#define STRING 259
#define BREAK 260
#define CHAR 261
#define CONTINUE 262
#define DO 263
#define ELSE 264
#define FOR 265
#define GOTO 266
#define IF 267
#define INT 268
#define LONG 269
#define RETURN 270
#define SHORT 271
#define SIGNED 272
#define UNSIGNED 273
#define VOID 274
#define WHILE 275
#define LEFT_PAREN 276
#define RIGHT_PAREN 277
#define LEFT_SQUARE 278
#define RIGHT_SQUARE 279
#define LEFT_CURLY 280
#define RIGHT_CURLY 281
#define AMPERSAND 282
#define ASTERISK 283
#define CARET 284
#define COLON 285
#define COMMA 286
#define EQUAL 287
#define EXCLAMATION 288
#define GREATER 289
#define LESS 290
#define MINUS 291
#define PERCENT 292
#define PLUS 293
#define SEMICOLON 294
#define SLASH 295
#define QUESTION 296
#define TILDE 297
#define VBAR 298
#define AMPERSAND_AMPERSAND 299
#define AMPERSAND_EQUAL 300
#define ASTERISK_EQUAL 301
#define CARET_EQUAL 302
#define EQUAL_EQUAL 303
#define EXCLAMATION_EQUAL 304
#define GREATER_EQUAL 305
#define GREATER_GREATER 306
#define GREATER_GREATER_EQUAL 307
#define LESS_EQUAL 308
#define LESS_LESS 309
#define LESS_LESS_EQUAL 310
#define MINUS_EQUAL 311
#define MINUS_MINUS 312
#define PERCENT_EQUAL 313
#define PLUS_EQUAL 314
#define PLUS_PLUS 315
#define SLASH_EQUAL 316
#define VBAR_EQUAL 317
#define VBAR_VBAR 318
#define NUMBER 319




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 29 "test.y"
{
	 union { 
		 int kind;
		  int line_number;
		  struct ir_section *ir;
		  union {
		    struct {
		      unsigned long value;
		      bool overflow;
		      struct result result;
		    } number;
		    struct {
		      char name[MAX_IDENTIFIER_LENGTH + 1];
		      struct symbol *symbol;
		    } identifier;
		    struct {
		      int operation;
		      struct node *left_operand;
		      struct node *right_operand;
		      struct result result;
		    } binary_operation;
		    struct {
		      struct node *expression;
		    } expression_statement;
		    struct {
		      struct node *init;
		      struct node *statement;
		    } statement_list;
		  } data;
		} node; 
	}
/* Line 1529 of yacc.c.  */
#line 209 "bison.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

