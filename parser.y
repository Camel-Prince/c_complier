%{
# include <stdio.h>
# include <stdlib.h>
# include "./abstract_syntax_tree/AstNode.h"
#include <iostream>

extern char *yytext;
extern int yylex();
extern void yyerror(char* s);
extern FILE * yyin;
AbstractAstNode* root;
%}

%union {
  AbstractAstNode* ast;
  // int ast;
  char* str;
}


/* declare tokens */
%right <str> ASSIGN_OP
%left <ast> OR
%left <ast> AND
%left <str> EQ_OP NE_OP
%left <str> GT_OP LT_OP GE_OP LE_OP 
%left <ast> ADD SUB
%left <ast> MUL DIV MOD
%left <ast> POW
%right <ast> NOT
%token <str> PRINTF 
%token <str> SCANF
%token <str> INT
%token <ast> IDENTIFIER
%token <ast> CONST 

%token EOL
%nonassoc COMMA SEMI S_QUO D_QUO
%nonassoc WHILE FOR IF ELSE THEN

%type <ast> Exp

%%
Program: Exp {
  root = new AbstractAstNode(AstNodeType::ROOT,"Root");
  $1 = new AbstractAstNode(AstNodeType::EXPRESSION, "Exp");
  root->addFirstChild($1);
  printAst(root);
}
        | 
        ;
Exp: CONST {$1 = new AbstractAstNode(AstNodeType::CONST_INT,"Const");}
  |  IDENTIFIER
  | Exp ASSIGN_OP Exp {printf("This is an Assign_Sentence!\n");}
  | Exp ADD Exp {printf("This is an And_Sentence!\n");}
  | Exp SUB Exp {printf("This is a Substract_Sentence!\n");}
  | Exp MUL Exp {printf("This is a Multiply_Sentence!\n");}
  | Exp DIV Exp {printf("This is a Divide_Sentence!\n");}
  | Exp MOD Exp {printf("This is a Mod_Sentence!\n");}
  | Exp POW Exp {printf("This is a Power_Sentence!\n");}
  ;



%%
int  main(int argc, char** agrv)
{
  printf("> "); 
  yyparse();
  return 0;
}

void yyerror(char *s)
{
  // fprintf(stderr, "error: %s\n", s);
}