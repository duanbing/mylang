/* A Bison parser, made by GNU Bison 1.875c.  */

/* Skeleton parser for Yacc-like parsing with Bison,
   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003 Free Software Foundation, Inc.

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
   Foundation, Inc., 59 Temple Place - Suite 330,
   Boston, MA 02111-1307, USA.  */

/* As a special exception, when this file is copied by Bison into a
   Bison output file, you may use that output file without restriction.
   This special exception was added by the Free Software Foundation
   in version 1.24 of Bison.  */

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     ERROR_TOKEN = 258,
     IF = 259,
     ELSE = 260,
     PRINT = 261,
     INPUT = 262,
     ASSIGN = 263,
     EQUAL = 264,
     CONCAT = 265,
     END_STMT = 266,
     OPEN_PAR = 267,
     CLOSE_PAR = 268,
     BEGIN_CS = 269,
     END_CS = 270,
     ID = 271,
     STRING = 272
   };
#endif
#define ERROR_TOKEN 258
#define IF 259
#define ELSE 260
#define PRINT 261
#define INPUT 262
#define ASSIGN 263
#define EQUAL 264
#define CONCAT 265
#define END_STMT 266
#define OPEN_PAR 267
#define CLOSE_PAR 268
#define BEGIN_CS 269
#define END_CS 270
#define ID 271
#define STRING 272




#if ! defined (YYSTYPE) && ! defined (YYSTYPE_IS_DECLARED)
#line 17 "string.y"
typedef union YYSTYPE {
    char str[256];
    SymDesc *symbol;
    struct TreeNode *tnode;
} YYSTYPE;
/* Line 1275 of yacc.c.  */
#line 77 "string.tab.h"
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;



