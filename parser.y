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
  root = new AbstractAstNode(AstNodeType::ROOT,"Program");
  root->addFirstChild($1);
  printAst(root);
}
  | 
  ;
Exp: CONST {
  // 注意token和type的不同；token需要构造出来节点对象；
   printf("CONST Reduced!\n");
  AbstractAstNode* node = new AbstractAstNode(AstNodeType::EXPRESSION,"Exp");
  $1 = new AbstractAstNode(AstNodeType::CONST_INT, "Const");
  node->addFirstChild($1);
  $$ = node;
  }
  |  IDENTIFIER {
     printf("ID Reduced!\n");
    // $$ = new AbstractAstNode(AstNodeType::ID, "ID");
    // $$->addFirstChild($1);
    }
  | Exp ASSIGN_OP Exp {
    printf("Assign_Sentence Reduced!\n");
    // AbstractAstNode* node = new AbstractAstNode(AstNodeType::OPERATION, "ASSIGN");
    // node->addFirstChild($1);
    // $1->addNextSibling($3);
    // $$ = node;
  }
  | Exp ADD Exp {
    printf("And_Sentence Reduced!\n");
    AbstractAstNode* node = new AbstractAstNode(AstNodeType::OPERATION, "ADD");
    node->addFirstChild($1);
    $1->addNextSibling($3);
    $$ = node;
  }
  | Exp SUB Exp {printf("Substract_Sentence Reduced!\n");}
  | Exp MUL Exp {
    printf("Multiply_Sentence Reduced!\n");
    AbstractAstNode* node = new AbstractAstNode(AstNodeType::OPERATION, "Multipliy");
    node->addFirstChild($1);
    $1->addNextSibling($3);
    $$ = node;
  }
  | Exp DIV Exp {printf("Divide_Sentence Reduced!\n");}
  | Exp MOD Exp {printf("Mod_Sentence Reduced!\n");}
  | Exp POW Exp {printf("Power_Sentence Reduced!\n");}
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