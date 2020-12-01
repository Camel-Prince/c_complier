%{
# include <stdio.h>
# include <stdlib.h>
# include "AST.h"
%}

%union {
  strcut ast *ast_node;
  int number;
}


/* declare tokens */
%token WHILE FOR IF ELSE THEN
%token PRINTF SCANF
%token INT
%token IDENTIFIER
%token <number> CONST 
%token ADD SUB MUL DIV POW MOD
%token EQ_OP GT_OP LT_OP GE_OP  LE_OP NE_OP
%token AND OR NOT
%token EOL
%token COMMA SEMI S_QUO D_QUO

%type <ast>
%type <ast>
%%

calclist: /* nothing */
 | calclist exp EOL { printf("= %d\n> ", $2); }
 | calclist EOL { printf("> "); } /* blank line or a comment */
 ;

exp: factor
 | exp ADD exp { $$ = $1 + $3; }
 | exp SUB factor { $$ = $1 - $3; } 
 ;

factor: term
 | factor MUL term { $$ = $1 * $3; }
 | factor DIV term { $$ = $1 / $3; }
 ;

term: CONST
 | '(' exp ')' { $$ = $2; }
 ;


%%
main(int argc, char** agrv)
{
  printf("> "); 
  yyparse();
}

yyerror(char *s)
{
  fprintf(stderr, "error: %s\n", s);
}