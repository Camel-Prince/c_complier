%{
#include "./abstract_syntax_tree/AstNode.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
#include "./symbol_table/symbol.h"
#include "./intermidiate_code/interCode.h"
#include "./asm/AsmGenerate.h"
extern char *yytext;
extern int yylex();
extern void yyerror(char* s);
extern FILE * yyin;
AbstractAstNode* root;
std::stack<SymbolTable*> SymbolTableList;
%}

%union {
  AbstractAstNode* ast;
  char* str;
}


/* declare tokens */
%right <str> ASSIGN_OP /* 赋值号 */
%left <ast> OR // 逻辑或
%left <ast> AND 
%left <ast> SINGLAND
%left <str> EQ_OP NE_OP //等于、 不等于
%left <str> GT_OP LT_OP GE_OP LE_OP //大于、less_than ,
%left <ast> ADD SUB
%left <ast> MUL DIV MOD
%left <ast> POW
%right <ast> NOT
%left  <str> '(' ')'
%left  <str> '[' ']'
%token <str> PRINTF 
%token <str> SCANF
%token <str> IDENTIFIER
%token <str> CONST 
// %token <str> INT
// %token <str> VOID
%nonassoc LOWER_THAN_ELSE
// %token <str> RETURN



%token EOL // 结束符号；
%nonassoc COMMA SEMI S_QUO D_QUO //，；' "
%nonassoc WHILE FOR IF ELSE THEN '{' '}' RETURN INT VOID BREAK CONTINUE



%type <ast> Program
%type <ast> BlockList
%type <ast> Block
%type <ast> Vardef
%type <ast> Descriptor
%type <ast> Func
%type <ast> VarList
%type <ast> Param
%type <ast> Body
%type <ast> StmtList
%type <ast> Stmt
%type <ast> Def
%type <ast> DefList
%type <ast> Var
%type <ast> Fordef
%type <ast> Exp
%type <ast> Args
%type <ast> Consts
%type <ast> IDList

%%
//start of program
Program:
    /*全部代码，语句块列表*/
    BlockList{
        root = new AbstractAstNode(AstNodeType::ROOT,"Program");
        root->addFirstChild($1);
        printAst(root);
    }
  ;
//a program is one or more blocks
BlockList:
    /*单个语句块*/
    Block{
      // printf("Blocklist->block \n");
        AbstractAstNode* node = new AbstractAstNode(AstNodeType::STATEMENT,"Single_Block");
        node->addFirstChild($1);
        $$ = node;
    }
    /*多个语句块*/
  | BlockList Block{
    // printf("blocklist->blocklist block \n");
        AbstractAstNode* node = new AbstractAstNode(AstNodeType::STATEMENT,"Some_Block");
        node->addFirstChild($1);
        $1->addNextSibling($2);
        $$=node;
    }
  ;
//definition of one block,including definition of variable|function
Block:
    /*全局变量定义*/
    Descriptor DefList SEMI{
      // printf("blcok->Descriptor Vardef SEMI \n");
        AbstractAstNode* node = new AbstractAstNode(AstNodeType::DEFINITION,"Def_Var_Block");        
        node->addFirstChild($1);        
        $1->addNextSibling($2);        
        $$ = node;
    }
    /*函数定义，包含函数体*/
  | Descriptor Func Body{
    // printf("block->Descriptor Func Body \n");
        AbstractAstNode* node = new AbstractAstNode(AstNodeType::DEFINITION,"Def_Func_Body_Block");
        node->addFirstChild($1);
        $1->addNextSibling($2);
        $2->addNextSibling($3);
        $$ = node;
    }
    /*无函数体函数定义*/
  | Descriptor Func SEMI{
    // printf("block->Descriptor Func SEMI \n");
        AbstractAstNode* node = new AbstractAstNode(AstNodeType::DEFINITION,"Def_Func_NBody_Block");
        node->addFirstChild($1);
        $1->addNextSibling($2);
        $$ = node;
    }
  ;
//ok
Vardef:
    /*单个变量*/
    IDENTIFIER{
      // printf("vardef->identifier \n");
        AbstractAstNode* node = new AbstractAstNode(AstNodeType::DEFINITION,"Block_Single_Vardef");
        AbstractAstNode* var_node = new AbstractAstNode(AstNodeType::ID, $1);
        node->addFirstChild(var_node);
        $$ = node;
    }
  //array,like a[10]
  | IDENTIFIER '[' CONST ']'{//id[10]
    // printf("vardef->identifier[const] \n");
        AbstractAstNode* node = new AbstractAstNode(AstNodeType::ARRAY,"array_id[const]");
        AbstractAstNode* const_node = new AbstractAstNode(AstNodeType::CONST_INT, $3);
        AbstractAstNode* var_node = new AbstractAstNode(AstNodeType::ID, $1);
        node->addFirstChild(var_node);
        var_node->addNextSibling(const_node);
        $$ = node;
    }
  | IDENTIFIER '[' Exp ']'{
    // printf("vardef->identifier[exp] \n");
      AbstractAstNode* node = new AbstractAstNode(AstNodeType::ARRAY,"array_id[exp]");
      AbstractAstNode* var_node = new AbstractAstNode(AstNodeType::ID, $1);
      node->addFirstChild(var_node);
      var_node->addNextSibling($3);
      $$ = node;
  }
  | IDENTIFIER '[' ']'{//id[]
    // printf("vardef->identifier[] \n");
        AbstractAstNode* node = new AbstractAstNode(AstNodeType::ARRAY,"array_id[]");
        AbstractAstNode* var_node = new AbstractAstNode(AstNodeType::ID, $1);
        node->addFirstChild(var_node);
        $$ = node;
    }
  | MUL IDENTIFIER{
    // printf("vardef->*identifier \n");
        AbstractAstNode* node = new AbstractAstNode(AstNodeType::ARRAY,"array_*id");
        AbstractAstNode* var_node = new AbstractAstNode(AstNodeType::ID, $2);
        node->addFirstChild(var_node);
        $$ = node;
  }
  ;
  Consts:
    Consts COMMA CONST{
    // printf("consts->consts const \n");
      AbstractAstNode* node = new AbstractAstNode(AstNodeType::EXPRESSION,"consts_array");
      AbstractAstNode* const_node = new AbstractAstNode(AstNodeType::CONST_INT, $3);
      node->addFirstChild($1);
      $1->addNextSibling(const_node);
      $$ = node;
    }
  | CONST{
      // printf("consts->const \n");
      AbstractAstNode* node = new AbstractAstNode(AstNodeType::EXPRESSION,"const_array");
      AbstractAstNode* const_node = new AbstractAstNode(AstNodeType::CONST_INT, $1);
      node->addFirstChild(const_node);
      $$ = node;

    }
  ;

//
Descriptor:
    INT{
        // printf("descriptor->int \n");
        AbstractAstNode* node = new AbstractAstNode(AstNodeType::MODIFY,"INT_TYPE");
        $$ = node;
    }
  | VOID{
        // printf("descriptor->void \n");
        AbstractAstNode* node = new AbstractAstNode(AstNodeType::MODIFY,"VOID_TYPE");
        $$ = node;
    }
  | INT MUL{//int*
        // printf("descriptor->int mul \n");
        AbstractAstNode* node = new AbstractAstNode(AstNodeType::MODIFY,"INT*_TYPE");
        $$ = node;
    }
  ;
//
Func:
    /*无参函数*/
    IDENTIFIER '('  ')'{
      // printf("func->identfier() \n");
        AbstractAstNode* node = new AbstractAstNode(AstNodeType::DEFINITION,"Func_NParam");
        AbstractAstNode* id_node = new AbstractAstNode(AstNodeType::ID, $1);
        node->addFirstChild(id_node);
        $$ = node;
    }
  | /*含参函数*/
    IDENTIFIER '(' VarList ')'{
      // printf("func->identifier(varlist) \n");
        AbstractAstNode* node = new AbstractAstNode(AstNodeType::DEFINITION,"Func_Params");
        AbstractAstNode* id_node = new AbstractAstNode(AstNodeType::ID, $1);
        //node->addFirstChild(id_node);
        /////////////////?
        //$1->addNextSibling($3);
        //id_node->addNextSibling($3);
        $$ = node;
    }
  ;
//with param->descriptor cannot
VarList:
    /*多个参数*/
    VarList COMMA Param{
      // printf("varlist->varlist,param \n");
        AbstractAstNode* node = new AbstractAstNode(AstNodeType::DEFINITION,"Some_Param");
        node->addFirstChild($1);
        $1->addNextSibling($3);
        $$ = node;
    }
    /*单个参数*/
  | Param{
    // printf("varlist->param \n");
        AbstractAstNode* node = new AbstractAstNode(AstNodeType::DEFINITION,"Single_Param");
        node->addFirstChild($1);
        $$ = node;
    }
  ;
Param:
    Descriptor IDENTIFIER{
      // printf("param->descriptor identifier \n");
        AbstractAstNode* node = new AbstractAstNode(AstNodeType::DEFINITION,"Param_ID");
        AbstractAstNode* id_node = new AbstractAstNode(AstNodeType::ID, $2);
        node->addFirstChild($1);
        $1->addNextSibling(id_node);
        $$ = node;
    }
  | Descriptor IDENTIFIER '[' ']'{
      // printf("param->descriptor identifier[] \n");
        AbstractAstNode* node = new AbstractAstNode(AstNodeType::DEFINITION,"Param_ID[]");
        AbstractAstNode* id_node = new AbstractAstNode(AstNodeType::ID, $2);
        node->addFirstChild($1);
        $1->addNextSibling(id_node);
        $$ = node;
    }
  | Descriptor IDENTIFIER '[' CONST ']'{
      // printf("param->descriptor identifier[const] \n");
        AbstractAstNode* node = new AbstractAstNode(AstNodeType::DEFINITION,"Param_ID[const]");
        AbstractAstNode* id_node = new AbstractAstNode(AstNodeType::ID, $2);
        AbstractAstNode* const_node = new AbstractAstNode(AstNodeType::CONST_INT, $4);
        node->addFirstChild($1);
        $1->addNextSibling(id_node);
        id_node->addNextSibling(const_node);
        $$ = node;
    }
  | Descriptor SINGLAND IDENTIFIER{
    // printf("param->&identifier \n");
        AbstractAstNode* node = new AbstractAstNode(AstNodeType::ARRAY,"array_&id");
        AbstractAstNode* var_node = new AbstractAstNode(AstNodeType::ID, $3);
        node->addFirstChild($1);
        $1->addNextSibling(var_node);
        $$ = node;
    }
  | Descriptor MUL IDENTIFIER{
    // printf("param->*identifier \n");
        AbstractAstNode* node = new AbstractAstNode(AstNodeType::ARRAY,"array_*id");
        AbstractAstNode* var_node = new AbstractAstNode(AstNodeType::ID, $3);
        node->addFirstChild($1);
        $1->addNextSibling(var_node);
        $$ = node;
  }
  | Descriptor {
    // printf("param->descriptor \n");
        AbstractAstNode* node = new AbstractAstNode(AstNodeType::DEFINITION,"Param_NID");
        node->addFirstChild($1);
        $$ = node;
    }
  ;
//func body {s}
Body:
    '{'StmtList'}'{
      // printf("body->{stmtlist} \n");
        AbstractAstNode* node = new AbstractAstNode(AstNodeType::BODY,"Body");
        node->addFirstChild($2);
        $$ = node;
    }
    ;
//
StmtList:
    /*语句*/
	StmtList Stmt{
    // printf("stmtlist->stmtlist stmt \n");
	    AbstractAstNode* node = new AbstractAstNode(AstNodeType::STATEMENT,"Some_Stmt");
	    if ($1 == NULL) {
	        node->addFirstChild($2);
	    } else {
	        node->addFirstChild($1);
            $1->addNextSibling($2);
        }
        $$ = node;
	}
	/*空*/
  | {
      $$ = NULL;
    }
  ;
//
Stmt:
    /*表达式语句*/
    Exp SEMI{
      // printf("stmt->exp; \n");
        AbstractAstNode* node = new AbstractAstNode(AstNodeType::STATEMENT,"Exp_Stmt");
        node->addFirstChild($1);
        $$ = node;
    }
    /*声明语句*/
  | Def SEMI{
    // printf("stmt->def; \n");
        AbstractAstNode* node = new AbstractAstNode(AstNodeType::STATEMENT,"Def_Stmt");
        node->addFirstChild($1);
        $$ = node;

    }
    /*函数体{}*/
  | Body{
    // printf("stmt->body \n");
        AbstractAstNode* node = new AbstractAstNode(AstNodeType::STATEMENT,"Body_Stmt");
        node->addFirstChild($1);
        $$ = node;
    }
  | RETURN Exp SEMI{
    // printf("stmt->return exp ; \n");
        AbstractAstNode* node = new AbstractAstNode(AstNodeType::STATEMENT,"Return_Exp");
        // AbstractAstNode* return_node = new AbstractAstNode(AstNodeType::RETURN,$1);
        // node->addFirstChild(return_node);
        // $1->addNextSibling($2);
        node->addFirstChild($2);
        $$ = node;
    }
  | RETURN SEMI{
    // printf("stmt->return ; \n");
        AbstractAstNode* node = new AbstractAstNode(AstNodeType::STATEMENT,"Return_Void");
        // AbstractAstNode* return_node = new AbstractAstNode(AstNodeType::RETURN,$1);
        // node->addFirstChild(return_node);
        $$ = node;
    }
  | IF '(' Exp ')' Stmt {
    // printf("stmt->if(exp)stmt \n");
        AbstractAstNode* node = new AbstractAstNode(AstNodeType::STATEMENT,"If");
        // AbstractAstNode* if_node = new AbstractAstNode(AstNodeType::SELECT,$1);
        // node->addFirstChild(if_node);
        // $1->addNextSibling($3);
        node->addFirstChild($3);
        $3->addNextSibling($5);
        $$ = node;
    }
  | IF '(' Exp ')' Stmt ELSE Stmt %prec LOWER_THAN_ELSE{
    // printf("stmt->if(exp)stmt else stmt \n");
        AbstractAstNode* node = new AbstractAstNode(AstNodeType::STATEMENT,"If_Else");
        node->addFirstChild($3);
        $3->addNextSibling($5);
        $5->addNextSibling($7);
        $$ = node;
    }
  | WHILE '(' Exp ')' Stmt{
    // printf("stmt->while ( exp) stmt \n");
        AbstractAstNode* node = new AbstractAstNode(AstNodeType::STATEMENT,"While");
        node->addFirstChild($3);
        $3->addNextSibling($5);
        $$ = node;
    }
  | FOR '(' SEMI SEMI ')' Stmt{
    // printf("stmt->for ( ;; \n");
        AbstractAstNode* node = new AbstractAstNode(AstNodeType::STATEMENT,"For_SEMI_SEMI");
        node->addFirstChild($6);
        $$ = node;
    }
  | FOR '(' Fordef SEMI SEMI ')' Stmt{
    // printf("stmt->for(fordef;;)stmt \n");
        AbstractAstNode* node = new AbstractAstNode(AstNodeType::STATEMENT,"For_Def_SEMI_SEMI");
        node->addFirstChild($3);
        $3->addNextSibling($7);
        $$ = node;
    }
  | FOR '(' SEMI Exp SEMI')' Stmt{
        AbstractAstNode* node = new AbstractAstNode(AstNodeType::STATEMENT,"For_SEMI_Exp_SEMI");
        node->addFirstChild($4);
        $4->addNextSibling($7);
        $$ = node;
    }
  | FOR '(' SEMI SEMI Exp ')' Stmt{
        AbstractAstNode* node = new AbstractAstNode(AstNodeType::STATEMENT,"For_SEMI_SEMI_Exp");
        node->addFirstChild($5);
        $5->addNextSibling($7);
        $$ = node;
    }
  | FOR '(' Fordef SEMI Exp SEMI Exp ')' Stmt{
        AbstractAstNode* node = new AbstractAstNode(AstNodeType::STATEMENT,"For_Def_SEMI_Exp_SEMI_Exp");
        node->addFirstChild($3);
        $3->addNextSibling($5);
        $5->addNextSibling($7);
        $7->addNextSibling($9);
        $$ = node;
    }
  | FOR '(' Fordef SEMI Exp SEMI ')'Stmt{
        AbstractAstNode* node = new AbstractAstNode(AstNodeType::STATEMENT,"For_Def_SEMI_Exp_SEMI");
        node->addFirstChild($3);
        $3->addNextSibling($5);
        $5->addNextSibling($8);
        $$ = node;
    }
  | FOR '(' Fordef SEMI SEMI Exp ')' Stmt{
        AbstractAstNode* node = new AbstractAstNode(AstNodeType::STATEMENT,"For_Def_SEMI_SEMI_Exp");
        node->addFirstChild($3);
        $3->addNextSibling($6);
        $6->addNextSibling($8);
        $$ = node;
    }
  | FOR '(' SEMI Exp SEMI Exp ')' Stmt{
        AbstractAstNode* node = new AbstractAstNode(AstNodeType::STATEMENT,"For_SEMI_Exp_SEMI_Exp");
        node->addFirstChild($4);
        $4->addNextSibling($6);
        $6->addNextSibling($8);
        $$ = node;
    }
  | BREAK SEMI{
        AbstractAstNode* node = new AbstractAstNode(AstNodeType::STATEMENT,"Break_Stmt"); 
        $$ = node;
    }
  | CONTINUE SEMI{
        AbstractAstNode* node = new AbstractAstNode(AstNodeType::STATEMENT,"Continue_Stmt"); 
        $$ = node;
    }
  | PRINTF '(' D_QUO Exp D_QUO ')' SEMI{
        AbstractAstNode* node = new AbstractAstNode(AstNodeType::STATEMENT,"Print_String");
        node->addFirstChild($4);
        $$ = node;

    }
  | PRINTF '(' Exp ')' SEMI{
        AbstractAstNode* node = new AbstractAstNode(AstNodeType::STATEMENT,"Print_Exp");
        node->addFirstChild($3);
        $$ = node;
    }
  | SCANF'('IDENTIFIER')' SEMI{
      AbstractAstNode* node = new AbstractAstNode(AstNodeType::STATEMENT,"scanf_id");
      AbstractAstNode* id_node = new AbstractAstNode(AstNodeType::ID, $3);
      node->addFirstChild(id_node);
      $$ = node;

  }
  ;
//with descriptor cannot
Def:
    Descriptor DefList{//!!
      // printf("def->descriptor deflist \n");
        AbstractAstNode* node = new AbstractAstNode(AstNodeType::DEFINITION,"Def_Var");
        node->addFirstChild($1);
        $1->addNextSibling($2);
        $$=node;
    }
  ;
//ok
DefList:
    /*单变量声明*/
    Var{//ok
    // printf("deflist->var \n");
        AbstractAstNode* node = new AbstractAstNode(AstNodeType::DEFINITION,"Def_Single_Var");
        node->addFirstChild($1);
        $$ = node;
    }
    /*多变量声明*/
  | Var COMMA DefList{//ok
    // printf("deflist->var ,deflist \n");
        AbstractAstNode* node = new AbstractAstNode(AstNodeType::DEFINITION,"Def_Some_Var");
        node->addFirstChild($1);
        $1->addNextSibling($3);
        $$ = node;
    }
  ;
//ok
Var:
    /*仅声明*/
    Vardef{//ok
      // printf("var->vardef \n");
        AbstractAstNode* node = new AbstractAstNode(AstNodeType::DEFINITION,"Var_ONLY");
        node->addFirstChild($1);
        $$=node;
    }
    /*声明且赋值*/
  | Vardef ASSIGN_OP Exp{//ok a,b=c
    // printf("var->vardef = exp \n");
        AbstractAstNode* node = new AbstractAstNode(AstNodeType::DEFINITION,"Var_ASSIGN");
        node->addFirstChild($1);
        $1->addNextSibling($3);
        $$=node;
    }
  ;
/*for语句中第一句，可能是表达式或声明赋值语句*/
//with def->descriptor not test
Fordef:
    Def{
      // printf("fordef->def \n");
        AbstractAstNode* node = new AbstractAstNode(AstNodeType::DEFINITION,"For_Def");
        node->addFirstChild($1);
        $$=node;
    }
  | Exp{//a=1 ok
    // printf("fordef->exp \n");
        AbstractAstNode* node = new AbstractAstNode(AstNodeType::DEFINITION,"For_Exp");
        node->addFirstChild($1);
        $$=node;
    }
  ;
//expression
Exp:
    CONST {
        // printf("exp->const \n");
        AbstractAstNode* node = new AbstractAstNode(AstNodeType::EXPRESSION,"Const_Exp");
        AbstractAstNode* const_node = new AbstractAstNode(AstNodeType::CONST_INT, $1);
        node->addFirstChild(const_node);
        $$ = node;
    }
  | /*IDENTIFIER {
        // printf("exp->identfier \n");
        AbstractAstNode* node = new AbstractAstNode(AstNodeType::EXPRESSION,"ID_Exp");
        AbstractAstNode* id_node = new AbstractAstNode(AstNodeType::ID, $1);
        node->addFirstChild(id_node);
        $$ = node;
    }*/
    IDList {
        AbstractAstNode* node = new AbstractAstNode(AstNodeType::EXPRESSION,"ID_Exp");
        node->addFirstChild($1);
        $$ = node;
    }
  | Exp ASSIGN_OP Exp {
        AbstractAstNode* node = new AbstractAstNode(AstNodeType::OPERATION, "Assign");
        node->addFirstChild($1);
        $1->addNextSibling($3);
        $$ = node;
  }
  | Exp ADD Exp {
        AbstractAstNode* node = new AbstractAstNode(AstNodeType::OPERATION, "Addition");
        node->addFirstChild($1);
        $1->addNextSibling($3);
        $$ = node;
  }
  | Exp SUB Exp {
        AbstractAstNode* node = new AbstractAstNode(AstNodeType::OPERATION, "Substraction");
        node->addFirstChild($1);
        $1->addNextSibling($3);
        $$ = node;
    }
  | Exp MUL Exp {
        AbstractAstNode* node = new AbstractAstNode(AstNodeType::OPERATION, "Multiply");
        node->addFirstChild($1);
        $1->addNextSibling($3);
        $$ = node;
  }
  | Exp DIV Exp {
        AbstractAstNode* node = new AbstractAstNode(AstNodeType::OPERATION, "Divide");
        node->addFirstChild($1);
        $1->addNextSibling($3);
        $$ = node;
    }
  | Exp MOD Exp {
        AbstractAstNode* node = new AbstractAstNode(AstNodeType::OPERATION, "Mod");
        node->addFirstChild($1);
        $1->addNextSibling($3);
        $$ = node;
    }
  | Exp POW Exp {
        AbstractAstNode* node = new AbstractAstNode(AstNodeType::OPERATION, "Power");
        node->addFirstChild($1);
        $1->addNextSibling($3);
        $$ = node;
    }
  | '(' Exp ')'{
        AbstractAstNode* node = new AbstractAstNode(AstNodeType::OPERATION, "Parentheses");
        node->addFirstChild($2);
        $$ = node;
    }
  /*负号*/
  | SUB Exp {
        AbstractAstNode* node = new AbstractAstNode(AstNodeType::OPERATION, "Negative");
        node->addFirstChild($2);
        $$=node;
    }
  /*&&*/
  | Exp AND Exp {
        AbstractAstNode* node = new AbstractAstNode(AstNodeType::OPERATION, "AND");
        node->addFirstChild($1);
        $1->addNextSibling($3);
        $$=node;
    }
  /*||*/
  | Exp OR Exp {
        AbstractAstNode* node = new AbstractAstNode(AstNodeType::OPERATION, "OR");
        node->addFirstChild($1);
        $1->addNextSibling($3);
        $$=node;
    }
  /*！*/
  | NOT Exp{
        AbstractAstNode* node = new AbstractAstNode(AstNodeType::OPERATION, "NOT");
        node->addFirstChild($2);
        $$=node;
    }
  | '{' Consts '}'{//{1,2,3}
    // printf("expr->{consts}\n");
    AbstractAstNode* node = new AbstractAstNode(AstNodeType::ARRAY,"{consts}");
    node->addFirstChild($2);
    $$=node;
    }
  | Exp EQ_OP Exp {
        AbstractAstNode* node = new AbstractAstNode(AstNodeType::OPERATION, "EQ_OP");
        node->addFirstChild($1);
        $1->addNextSibling($3);
        $$=node;
    }
  | Exp NE_OP Exp {
        AbstractAstNode* node = new AbstractAstNode(AstNodeType::OPERATION, "NE_OP");
        node->addFirstChild($1);
        $1->addNextSibling($3);
        $$=node;
    }
  | Exp GT_OP Exp {
        AbstractAstNode* node = new AbstractAstNode(AstNodeType::OPERATION, "GT_OP");
        node->addFirstChild($1);
        $1->addNextSibling($3);
        $$=node;
    }
  | Exp LT_OP Exp {
        AbstractAstNode* node = new AbstractAstNode(AstNodeType::OPERATION, "LT_OP");
        node->addFirstChild($1);
        $1->addNextSibling($3);
        $$=node;
    }
  | Exp GE_OP Exp {
        AbstractAstNode* node = new AbstractAstNode(AstNodeType::OPERATION, "GE_OP");
        node->addFirstChild($1);
        $1->addNextSibling($3);
        $$=node;
    }
  | Exp LE_OP Exp {
        AbstractAstNode* node = new AbstractAstNode(AstNodeType::OPERATION, "LE_OP");
        node->addFirstChild($1);
        $1->addNextSibling($3);
        $$=node;
    }
    
  | IDENTIFIER '(' Args ')' {
    // printf("exp->id '(' Args ')' \n");
        AbstractAstNode* node = new AbstractAstNode(AstNodeType::CALL, "Call_Args_Func");
        AbstractAstNode* id_node = new AbstractAstNode(AstNodeType::ID, $1);
        node->addFirstChild(id_node);
        id_node->addNextSibling($3);
        $$ = node;
    }
  | IDENTIFIER '(' ')' {
    // printf("exp->id '('  ')' \n");
        AbstractAstNode* node = new AbstractAstNode(AstNodeType::CALL, "Call_NArgs_Func");
        AbstractAstNode* id_node = new AbstractAstNode(AstNodeType::ID, $1);
        node->addFirstChild(id_node);
        $$ = node;
    }
  | MUL IDENTIFIER{//*id
      AbstractAstNode* node = new AbstractAstNode(AstNodeType::OPERATION,"*id");
      AbstractAstNode* id_node = new AbstractAstNode(AstNodeType::ID, $2);
      node->addFirstChild(id_node);
      $$ = node;
  }
  | IDENTIFIER '[' Exp ']'{//like a[2+3]
      AbstractAstNode* node = new AbstractAstNode(AstNodeType::OPERATION,"id[exp]");
      AbstractAstNode* id_node = new AbstractAstNode(AstNodeType::ID, $1);
      node->addFirstChild(id_node);
      id_node->addNextSibling($3);
      $$=node;
    }
  | SINGLAND IDENTIFIER {
        AbstractAstNode* node = new AbstractAstNode(AstNodeType::OPERATION,"&id");
        AbstractAstNode* id_node = new AbstractAstNode(AstNodeType::ID, $2);
        node->addFirstChild(id_node);
        $$ = node;
    }
  ;
Args: 
    Exp {
        AbstractAstNode* node = new AbstractAstNode(AstNodeType::ID,"Func_Single_Arg");
        node->addFirstChild($1);
        $$ = node;
    }
  | Args COMMA Exp {
        AbstractAstNode* node = new AbstractAstNode(AstNodeType::DEFINITION,"Func_Some_Args");
        node->addFirstChild($1);
        $1->addNextSibling($3);
        $$ = node;
    }
  ;
IDList:
    IDENTIFIER{
        AbstractAstNode* node = new AbstractAstNode(AstNodeType::DEFINITION,"Single_ID");
        AbstractAstNode* id_node = new AbstractAstNode(AstNodeType::ID,$1);
        node->addFirstChild(id_node);
        $$ = node;

    }
  | IDList IDENTIFIER{
        AbstractAstNode* node = new AbstractAstNode(AstNodeType::DEFINITION,"Single_ID");
        AbstractAstNode* id_node = new AbstractAstNode(AstNodeType::ID,$2);
        node->addFirstChild($1);
        $1->addNextSibling(id_node);
        $$ = node;

    }
  ;

%%
int  main(int argc, char** argv)
{
  if ( argc > 1 ) {
    if (! (yyin = fopen(argv[1], "r" ) )){
      perror(argv[1]);
      return 1;
    }
    printf("[i]>>>Read data from file:%s \n",argv[1]);
  }else{
    printf("[I]>>>Read data from stdin.\n");
  }
  do {
		yyparse();
	} while(!feof(yyin));
  InterCode interCode = InterCode(root);
  interCode.Root_Generate();
  SymbolTable* root_table = interCode.getTable();
  root_table->getfirstChildTable()->showSymbols();
  //AsmGenerate* asmgenerate = new AsmGenerate(interCode.getQuadlist(), interCode.getTempVars(), interCode.getTable(), interCode.getFuncTable());
  AsmGenerate* asmgenerate = new AsmGenerate(interCode.getQuadlist(),  interCode.getTable());
  
  asmgenerate->generate();
  return 0;

}

void yyerror(char *s)
{
  fprintf(stderr, "error: %s\n", s);
}