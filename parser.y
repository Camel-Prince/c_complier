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
%token <str> IDENTIFIER
%token <str> CONST 

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
  printf("CONST Reduced To Exp!\n");
  AbstractAstNode* node = new AbstractAstNode(AstNodeType::EXPRESSION,"Const_Exp");
  AbstractAstNode* const_node = new AbstractAstNode(AstNodeType::CONST_INT, $1);
  node->addFirstChild(const_node);
  $$ = node;
  }
  |  IDENTIFIER {
    printf("ID Reduced To Exp!\n");
    AbstractAstNode* node = new AbstractAstNode(AstNodeType::EXPRESSION,"ID_Exp");
    AbstractAstNode* id_node = new AbstractAstNode(AstNodeType::ID, $1);
    node->addFirstChild(id_node);
    $$ = node;
    }
  | Exp ASSIGN_OP Exp {
    printf("Assign_Sentence Reduced!\n");
    AbstractAstNode* node = new AbstractAstNode(AstNodeType::OPERATION, "Assign");
    node->addFirstChild($1);
    $1->addNextSibling($3);
    $$ = node;
  }
  | Exp ADD Exp {
    printf("And_Sentence Reduced!\n");
    AbstractAstNode* node = new AbstractAstNode(AstNodeType::OPERATION, "Addition");
    node->addFirstChild($1);
    $1->addNextSibling($3);
    $$ = node;
  }
  | Exp SUB Exp {
    printf("Substract_Sentence Reduced!\n");
    AbstractAstNode* node = new AbstractAstNode(AstNodeType::OPERATION, "Substraction");
    node->addFirstChild($1);
    $1->addNextSibling($3);
    $$ = node;
    }
  | Exp MUL Exp {
    printf("Multiply_Sentence Reduced!\n");
    AbstractAstNode* node = new AbstractAstNode(AstNodeType::OPERATION, "Multipliy");
    node->addFirstChild($1);
    $1->addNextSibling($3);
    $$ = node;
  }
  | Exp DIV Exp {
    printf("Divide_Sentence Reduced!\n");
    AbstractAstNode* node = new AbstractAstNode(AstNodeType::OPERATION, "Divide");
    node->addFirstChild($1);
    $1->addNextSibling($3);
    $$ = node;
    }
  | Exp MOD Exp {
    printf("Mod_Sentence Reduced!\n");
    AbstractAstNode* node = new AbstractAstNode(AstNodeType::OPERATION, "Mod");
    node->addFirstChild($1);
    $1->addNextSibling($3);
    $$ = node;
    }
  | Exp POW Exp {
    printf("Power_Sentence Reduced!\n");
    AbstractAstNode* node = new AbstractAstNode(AstNodeType::OPERATION, "Power");
    node->addFirstChild($1);
    $1->addNextSibling($3);
    $$ = node;
    }
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