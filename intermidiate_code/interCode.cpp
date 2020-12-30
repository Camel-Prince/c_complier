#include "interCode.h"
#include <typeinfo>
#include <sstream>
#include <string>
#include <iostream>
#include<list>

bool isNumber(std::string str){
    int len = str.length();
    for(int i=0; i<len; i++){
        if(! isnumber(str[i])) return false; 
    }
    return true;
}

QuadItem:: QuadItem(Symbol* result, OpType op, int arg1, int arg2){
   this->result.var = result;
   this->op = op;
   this->arg1.target = arg1;
   this->arg2.target = arg2;
   this->quad_item_type = 4;
}

// 常量和变量运算后赋值给变量-1；
QuadItem:: QuadItem(Symbol* result, OpType op, Symbol* arg1, int arg2){
   this->result.var = result;
   this->op = op;
   this->arg1.var = arg1;
   this->arg2.target = arg2;
   this->quad_item_type = 5;
}

// 常量和变量运算后赋值给变量-2；
QuadItem:: QuadItem(Symbol* result, OpType op, int arg1, Symbol* arg2){
   this->result.var = result;
   this->op = op;
   this->arg1.target = arg1;
   this->arg2.var = arg2;
   this->quad_item_type = 6;
}

// 变量和变量运算后赋值给变量
QuadItem:: QuadItem(Symbol* result, OpType op, Symbol* arg1, Symbol* arg2){
   this->result.var = result;
   this->op = op;
   this->arg1.var = arg1;
   this->arg2.var = arg2;
   this->quad_item_type = 7;
}

/***
 * 
 * 以下quad_item_type为4的为：
 * result为变量；
 * op为单目运算符；
 * ***/
QuadItem:: QuadItem(Symbol* result, OpType op, Symbol* arg1){
    this->result.var = result;
    this->op = op;
    this->arg1.var = arg1;
    this->quad_item_type = 7;
}
QuadItem:: QuadItem(Symbol* result, OpType op, int arg1){
    this->result.var = result;
    this->op = op;
    this->arg1.target = arg1;
    this->quad_item_type = 6;
}
QuadItem::QuadItem(int result,OpType op)
{
    this->op = op;
    this->arg1.var = NULL;
    this->arg2.var = NULL;
    this->result.target = result;
    this->quad_item_type = 3;
}
QuadItem::QuadItem(int result,OpType op, Symbol* arg1, Symbol* arg2)
{
    this->op = op;
    this->arg1.var = arg1;
    this->arg2.var = arg2;
    this->result.target = result;
    this->quad_item_type = 3;
}

/**
 * 
 * 打印出一个四元式；根据op、arg1/2以及result的类型类确定输出格式；
 * 
*/
void QuadItem:: printItemInfor(int i){
    OpType op_type = this->op;
    int type = this->quad_item_type;
    std::cout<<"Type: "<<type<<"  ";
    switch (op)
    {
    case addtion:
        if(type == 7){
            std::cout<<"L"<<i+1<<":  "
            <<this->result.var->getIDName()
            <<" := "
            <<this->arg1.var->getIDName()
            <<" ADD "
            <<this->arg2.var->getIDName()
            <<std::endl;
        }
        else if(type == 6)
        {
            std::cout<<"L"<<i+1<<":  "
            <<this->result.var->getIDName()
            <<" := "
            <<this->arg1.target
            <<" ADD "
            <<this->arg2.var->getIDName()
            <<std::endl;
        }
        else if(type == 5)
        {
             std::cout<<"L"<<i+1<<":  "
            <<this->result.var->getIDName()
            <<" := "
            <<this->arg1.var->getIDName()
            <<" ADD "
            <<this->arg2.target
            <<std::endl;
        }
        else if(type == 4){
             std::cout<<"L"<<i+1<<":  "
            <<this->result.var->getIDName()
            <<" := "
            <<this->arg1.target
            <<" ADD "
            <<this->arg2.target
            <<std::endl;
        }
        break;
    case substract:
        if(type == 7)
        {
            std::cout<<"L"<<i+1<<":  "
            <<this->result.var->getIDName()
            <<" := "
            <<this->arg1.var->getIDName()
            <<" SUB "
            <<this->arg2.var->getIDName()
            <<std::endl;
        }
        else if(type == 6)
        {
            std::cout<<"L"<<i+1<<":  "
            <<this->result.var->getIDName()
            <<" := "
            <<this->arg1.target
            <<" SUB "
            <<this->arg2.var->getIDName()
            <<std::endl;
        }
        else if(type == 5)
        {
             std::cout<<"L"<<i+1<<":  "
            <<this->result.var->getIDName()
            <<" := "
            <<this->arg1.var->getIDName()
            <<" SUB "
            <<this->arg2.target
            <<std::endl;
        }
        else if(type == 4)
        {
             std::cout<<"L"<<i+1<<":  "
            <<this->result.var->getIDName()
            <<" := "
            <<this->arg1.target
            <<" SUB "
            <<this->arg2.target
            <<std::endl;
        }
        break;
    case multiply:
        if(type == 7)
        {
            std::cout<<"L"<<i+1<<":  "
            <<this->result.var->getIDName()
            <<" := "
            <<this->arg1.var->getIDName()
            <<" MUL "
            <<this->arg2.var->getIDName()
            <<std::endl;
        }
        else if(type == 6)
        {
            std::cout<<"L"<<i+1<<":  "
            <<this->result.var->getIDName()
            <<" := "
            <<this->arg1.target
            <<" MUL "
            <<this->arg2.var->getIDName()
            <<std::endl;
        }
        else if(type == 5)
        {
             std::cout<<"L"<<i+1<<":  "
            <<this->result.var->getIDName()
            <<" := "
            <<this->arg1.var->getIDName()
            <<" MUL "
            <<this->arg2.target
            <<std::endl;
        }
        else if(type == 4)
        {
             std::cout<<"L"<<i+1<<":  "
            <<this->result.var->getIDName()
            <<" := "
            <<this->arg1.target
            <<" MUL "
            <<this->arg2.target
            <<std::endl;
        }
        break;
    case divide:
        if(type == 7)
        {
            std::cout<<"L"<<i+1<<":  "
            <<this->result.var->getIDName()
            <<" := "
            <<this->arg1.var->getIDName()
            <<" DIV "
            <<this->arg2.var->getIDName()
            <<std::endl;
        }
        else if(type == 6)
        {
            std::cout<<"L"<<i+1<<":  "
            <<this->result.var->getIDName()
            <<" := "
            <<this->arg1.target
            <<" DIV "
            <<this->arg2.var->getIDName()
            <<std::endl;
        }
        else if(type == 5)
        {
             std::cout<<"L"<<i+1<<":  "
            <<this->result.var->getIDName()
            <<" := "
            <<this->arg1.var->getIDName()
            <<" DIV "
            <<this->arg2.target
            <<std::endl;
        }
        else if(type == 4)
        {
             std::cout<<"L"<<i+1<<":  "
            <<this->result.var->getIDName()
            <<" := "
            <<this->arg1.target
            <<" DIV "
            <<this->arg2.target
            <<std::endl;
        }
        break;
    case mod:
        if(type == 7)
        {
            std::cout<<"L"<<i+1<<":  "
            <<this->result.var->getIDName()
            <<" := "
            <<this->arg1.var->getIDName()
            <<" MOD "
            <<this->arg2.var->getIDName()
            <<std::endl;
        }
        else if(type == 6)
        {
            std::cout<<"L"<<i+1<<":  "
            <<this->result.var->getIDName()
            <<" := "
            <<this->arg1.target
            <<" MOD "
            <<this->arg2.var->getIDName()
            <<std::endl;
        }
        else if(type == 5)
        {
             std::cout<<"L"<<i+1<<":  "
            <<this->result.var->getIDName()
            <<" := "
            <<this->arg1.var->getIDName()
            <<" MOD "
            <<this->arg2.target
            <<std::endl;
        }
        else if(type == 4)
        {
             std::cout<<"L"<<i+1<<":  "
            <<this->result.var->getIDName()
            <<" := "
            <<this->arg1.target
            <<" MOD "
            <<this->arg2.target
            <<std::endl;
        }
        break;
    case power:
        if(type == 7)
        {
            std::cout<<"L"<<i+1<<":  "
            <<this->result.var->getIDName()
            <<" := "
            <<this->arg1.var->getIDName()
            <<" POW "
            <<this->arg2.var->getIDName()
            <<std::endl;
        }
        else if(type == 6)
        {
            std::cout<<"L"<<i+1<<":  "
            <<this->result.var->getIDName()
            <<" := "
            <<this->arg1.target
            <<" POW "
            <<this->arg2.var->getIDName()
            <<std::endl;
        }
        else if(type == 5)
        {
             std::cout<<"L"<<i+1<<":  "
            <<this->result.var->getIDName()
            <<" := "
            <<this->arg1.var->getIDName()
            <<" POW "
            <<this->arg2.target
            <<std::endl;
        }
        else if(type == 4)
        {
             std::cout<<"L"<<i+1<<":  "
            <<this->result.var->getIDName()
            <<" := "
            <<this->arg1.target
            <<" POW "
            <<this->arg2.target
            <<std::endl;
        }
        break;
    case assign:{
        if (type == 6)
        {
            std::cout<<"L"<<i+1<<":  "
            <<this->result.var->getIDName()
            <<" := "
            <<this->arg1.target
            <<std::endl;
        }
        else if(type == 7)
        {
            std::cout<<"L"<<i+1<<":  "
            <<this->result.var->getIDName() <<" := "
            <<this->arg1.var->getIDName()<<std::endl;
        }
    }
    break;
    case JUMP_LT:
        std::cout<<"L"<<i+1<<":  "<<"if "
        <<this->arg1.var->getIDName()
        <<" < "
        <<this->arg2.var->getIDName()
        <<" goto "
        <<"L"
        <<this->result.target+1
        <<std::endl;
    break;
    case JUMP_LE:
        std::cout<<"L"<<i+1<<":  "<<"if "
        <<this->arg1.var->getIDName()
        <<" <= "
        <<this->arg2.var->getIDName()
        <<" goto "
        <<"L"
        <<this->result.target+1
        <<std::endl;
    break;
    case JUMP_GT:
        std::cout<<"L"<<i+1<<":  "<<"if "
        <<this->arg1.var->getIDName()
        <<" > "
        <<this->arg2.var->getIDName()
        <<" goto "
        <<"L"
        <<this->result.target+1
        <<std::endl;
    break;
    case JUMP_GE:
        std::cout<<"L"<<i+1<<":  "<<"if "
        <<this->arg1.var->getIDName()
        <<" >= "
        <<this->arg2.var->getIDName()
        <<" goto "
        <<"L"
        <<this->result.target+1
        <<std::endl;
    break;
    case JUMP_EQ:
        std::cout<<"L"<<i+1<<":  "<<"if "
        <<this->arg1.var->getIDName()
        <<" == "
        <<this->arg2.var->getIDName()
        <<" goto "
        <<"L"
        <<this->result.target+1
        <<std::endl;
    break;
    case JUMP_NE:
        std::cout<<"L"<<i+1<<":  "<<"if "
        <<this->arg1.var->getIDName()
        <<" != "
        <<this->arg2.var->getIDName()
        <<" goto "
        <<"L"
        <<this->result.target+1
        <<std::endl;
    break;
    case JUMP:
        std::cout<<"L"<<i+1<<":  "
        <<" goto "
        <<"L"
        <<this->result.target+1
        <<std::endl;
    break;
    
    default:
    break;
     }
}


InterCode:: InterCode(AbstractAstNode* root){
    this->root = root;
    this->rootTable = new SymbolTable(false);
}

void InterCode:: Root_Generate(){
    std::cout<<"Gen "<<root->content<<std::endl;
    Generate(this->root, this->rootTable);
    int len = this->quad_list.size();
    int i=0;
    while(i < len){
        quad_list[i]->printItemInfor(i);
        i++;
    }
}

void InterCode:: Generate(AbstractAstNode* node, SymbolTable* symbol_table) {
    if (node == NULL ){
        std::cout<<"Null Node"<<std::endl;
        exit(1);
    }
    std::string node_content = node->content;
    int type = static_cast<int>(node->nodeType);
    switch (type){
        case static_cast<int>(AstNodeType::ROOT):
                {
                    AbstractAstNode* child = node->getFirstChild();
                    while(child != NULL){
                        std::cout<<"Gen "<<child->content<<std::endl;
                        Generate(child, symbol_table);
                        child = child->getNextSibling();
                    }
                }
        break;
        case static_cast<int>(AstNodeType::STATEMENT ):
        {
            if(node_content == "Single_Block" || "Some_Block")
            {
                AbstractAstNode* child = node->getFirstChild();
                    while(child != NULL){
                        std::cout<<"Gen "<<child->content<<std::endl;
                        Generate(child, symbol_table);
                        child = child->getNextSibling();
                    }
            }
        }
        break;
        case static_cast<int>(AstNodeType::DEFINITION ):{
            if (node_content == "Def_Func_Body_Block"){
                AbstractAstNode* child = node->getFirstChild();
                    while(child != NULL){
                        std::cout<<"Gen "<<child->content<<std::endl;
                        Generate(child, symbol_table);
                        child = child->getNextSibling();
                    }
            }else if(node_content == "Func_NParam"){
                AbstractAstNode* child = node->getFirstChild();
                    while(child != NULL){
                        std::cout<<"Gen "<<child->content<<std::endl;
                        Generate(child, symbol_table);
                        child = child->getNextSibling();
                    }
            }else if(node_content == "Def_Var_Block"){
                AbstractAstNode* child = node->getFirstChild();
                bool is_modify_int = false;
                if(child->content == "INT_TYPE") is_modify_int = true;
                while(child != NULL){
                    std::cout<<"Gen "<<child->content<<std::endl;
                    Body_Generate(child, symbol_table);
                    child = child->getNextSibling();
                }


            }
        }
        break;
        case static_cast<int>(AstNodeType::MODIFY):
                {
                    AbstractAstNode* child = node->getFirstChild();
                    while(child != NULL){
                        std::cout<<"Gen "<<child->content<<std::endl;
                        Generate(child, symbol_table);
                        child = child->getNextSibling();
                    }
                }
        break;
        case static_cast<int>(AstNodeType::ID):
                {
                    AbstractAstNode* child = node->getFirstChild();
                    // child->printNodeInfo();
                    while(child != NULL){
                        std::cout<<"Gen "<<child->content<<std::endl;
                        Generate(child, symbol_table);
                        child = child->getNextSibling();
                    }
                }
        break;
        case static_cast<int>(AstNodeType::BODY):
                {
                    if(node->getParent()->getFirstChild()->getNextSibling()->getFirstChild()->content == "main"){
                        // 进入了main 函数的body：
                        SymbolTable* main_symbol_table = symbol_table->addChildTable(false);
                        Body_Generate(node, main_symbol_table);
                    }
                }
        break;

        default:
            std::cout<<"No such AstNodeType!"<<std::endl; 
            exit(1);
        break;
    }
}

Symbol* InterCode:: Exp_Stmt_Generate(AbstractAstNode* node, SymbolTable* symbol_table){
    if(node == NULL){
        std::cout<<"Empty Pointer!"<<std::endl;
        exit(1);
    }
    std::string node_content = node->content;
    int type = static_cast<int>(node->nodeType);
    switch(type){
        case static_cast<int>(AstNodeType::DEFINITION):{
            if(node_content == "Single_ID"){                
                std::string ID_name = node->getFirstChild()->content;
                Symbol* re = symbol_table->findSymbolLocally(ID_name);
                if(re == NULL){
                    // 未定义使用在findSymbolGlobally中定义；
                    re = symbol_table->findSymbolGlobally(ID_name);
                }
                return re;
            }
        }
            break;
        case static_cast<int>(AstNodeType::OPERATION):{
            if(node_content == "Parentheses"){
                // node->getFirstChild()->printNodeInfo();
                Symbol* re = Exp_Stmt_Generate(node->getFirstChild(), symbol_table);
                return re;
            }else if(node_content == "Addition" ||
                node_content == "Substraction" ||
                node_content == "Multiply" || 
                node_content == "Divide" || 
                node_content == "Mod" || 
                node_content == "Power"){
                        // 注意，先generate完子节点， 再生成result的tempVar；
                Symbol* arg1 = Exp_Stmt_Generate(node->getFirstChild(), symbol_table);
                Symbol* arg2 = Exp_Stmt_Generate(node->getFirstChild()->getNextSibling(), symbol_table); 
                Symbol* re = new Symbol("t"+std::to_string(temp_list.size()), SymbolType::temp_var, 4);
                temp_list.push_back(re);
                OpType op;
                if (node_content == "Addition"){
                    op = addtion;
                }else if (node_content == "Substraction"){
                    op = substract;
                }else if (node_content == "Multiply"){
                    op = multiply;
                }else if (node_content == "Divide"){
                    op = divide;
                }else if (node_content == "Mod"){
                    op = mod;
                }else if (node_content == "Power"){
                    op = power;
                }
                QuadItem* quad;
                if (isNumber(arg1->getIDName()) && isNumber(arg2->getIDName())){
                    quad = new QuadItem(re, op, atoi(arg1->getIDName().c_str()), atoi(arg2->getIDName().c_str()) );
                }else if(isNumber(arg1->getIDName()) && !isNumber(arg2->getIDName())){
                    quad = new QuadItem(re, op, atoi(arg1->getIDName().c_str()), arg2 );
                }else if(!isNumber(arg1->getIDName()) && isNumber(arg2->getIDName())){
                    quad = new QuadItem(re, op, arg1, atoi(arg2->getIDName().c_str()) );
                }else if(!isNumber(arg1->getIDName()) && !isNumber(arg2->getIDName())){
                    quad = new QuadItem(re, op, arg1, arg2);
                }
                this->quad_list.push_back(quad);
                return re;
            } else if(node_content == "Assign"){
                OpType op = assign;
                Symbol* re = Exp_Stmt_Generate(node->getFirstChild(), symbol_table);
                Symbol* arg1 = Exp_Stmt_Generate(node->getFirstChild()->getNextSibling(), symbol_table);

                QuadItem* quad;
                if(isNumber(arg1->getIDName())){
                    std::cout<<arg1->getIDName()<<" is a number!!"<<std::endl;
                    quad = new QuadItem(re, op, atoi(arg1->getIDName().c_str()));
                }else {
                    quad = new QuadItem(re, op, arg1);
                }
                this->quad_list.push_back(quad);
                std::cout<<"quad_list Size: "<<quad_list.size()
                <<"quad type: "<<quad->getItemType()<<std::endl;
                return re;
            } else if(node_content == "EQ_OP" ||
                node_content == "NE_OP" ||
                node_content == "GT_OP" ||
                node_content == "LT_OP" ||
                node_content == "GE_OP" ||
                node_content == "LE_OP" ){
                Symbol* arg1 = Exp_Stmt_Generate(node->getFirstChild(), symbol_table);
                Symbol* arg2 = Exp_Stmt_Generate(node->getFirstChild()->getNextSibling(), symbol_table); 
                OpType op;
                if (node_content == "EQ_OP"){
                    op = JUMP_EQ;
                }else if (node_content == "NE_OP"){
                    op = JUMP_NE;
                }else if (node_content == "GT_OP"){
                    op = JUMP_GT;
                }else if (node_content == "LT_OP"){
                    op = JUMP_LT;
                }else if (node_content == "GE_OP"){
                    op = JUMP_GE;
                }else if (node_content == "LE_OP"){
                    op = JUMP_LE;
                }
                QuadItem* T;
                if (isNumber(arg1->getIDName())||isNumber(arg2->getIDName())){
                    if (isNumber(arg1->getIDName())) T=new QuadItem(int(NULL),op,atoi(arg1->getIDName().c_str()),arg2);
                    if (isNumber(arg2->getIDName())) T=new QuadItem(int(NULL),op,arg1,atoi(arg2->getIDName().c_str()));
                }else if (arg1 != NULL && arg2 != NULL){
                    T = new QuadItem(int(NULL), op, arg1, arg2);
                }
                if (arg1 != NULL && arg2 != NULL){
                    QuadItem *T = new QuadItem(int(NULL),op,arg1,arg2);
                }
                else {
                    std::cout<<"Error! Argument NULL exception in Compare_Expression"<<std::endl;
                    exit(1);
                }
                QuadItem *F = new QuadItem(int(NULL),OpType::JUMP);
                std::list<int> trueL; 
                int len = quad_list.size();
                trueL.push_back(len);
                this->quad_list.push_back(T);
                std::list<int> falseL; 
                len = quad_list.size();
                falseL.push_back(len);
                this->quad_list.push_back(F);
                trueList.push(trueL);
                falseList.push(falseL);

            }else if(node_content == "AND" || node_content == "OR" || node_content == "NOT"){
                if (node_content == "AND"){
                    AbstractAstNode *child = node->getFirstChild();
                    Exp_Stmt_Generate(child, symbol_table);
                    logic.push(quad_list.size());
                    Exp_Stmt_Generate(child->getNextSibling(), symbol_table);
                    std::list<int> leftTrue, rightTrue, leftFalse, rightFalse;
                    rightTrue = trueList.top();
                    trueList.pop();
                    leftTrue = trueList.top();
                    trueList.pop();
                    rightFalse = falseList.top();
                    falseList.pop();
                    leftFalse = falseList.top();
                    falseList.pop();
                    leftFalse.merge(rightFalse);
                    falseList.push(leftFalse);
                    trueList.push(rightTrue);
                    backpatch(&leftTrue, logic.top());
                    logic.pop();
                    break;
                }else if (node_content == "OR"){
                    AbstractAstNode *child = node->getFirstChild();
                    Exp_Stmt_Generate(child, symbol_table);
                    logic.push(quad_list.size());
                    Exp_Stmt_Generate(child->getNextSibling(), symbol_table);
                    std::list<int> leftTrue, rightTrue, leftFalse, rightFalse;
                    rightTrue = trueList.top();
                    trueList.pop();
                    leftTrue = trueList.top();
                    trueList.pop();
                    rightFalse = falseList.top();
                    falseList.pop();
                    leftFalse = falseList.top();
                    falseList.pop();
                    leftTrue.merge(rightTrue);
                    trueList.push(leftTrue);
                    falseList.push(rightFalse);
                    backpatch(&leftFalse, logic.top());
                    logic.pop();
                    break;                    
                }else if (node_content == "NOT"){
                    AbstractAstNode *child = node->getFirstChild();
                    while (child != NULL){
                        Exp_Stmt_Generate(child, symbol_table);
                        child = child->getNextSibling();
                    }
                    std::list<int> trueL, falseL;
                    trueL = trueList.top();
                    trueList.pop();
                    falseL = falseList.top();
                    falseList.pop();
                    trueList.push(falseL);
                    falseList.push(trueL);
                    break;                   
                }
            }
                
            
        }
            break;
        case static_cast<int>(AstNodeType::ID):{
            // std::cout<<"Dealt by Father_node"<<std::endl;
        }
            break;
        case static_cast<int>(AstNodeType::EXPRESSION): // EXPRESSION
        {
            if(node_content == "Const_Exp"){
                Symbol* re = new Symbol(node->getFirstChild()->content);
                return re;
            }else if(node_content == "ID_Exp"){
                Symbol* re = Exp_Stmt_Generate(node->getFirstChild(), symbol_table);
                return re;
            }
            else if(node_content == "For_Exp"){
                Exp_Stmt_Generate(node->getFirstChild(),symbol_table);
            }
        }
            break;

        default:
            std::cout<<"No such AstNodeType!"<<std::endl; 
        exit(1);
    }
}

SymbolTable* InterCode:: Body_Generate(AbstractAstNode* node, SymbolTable* symbol_table){
    if (node == NULL ){
        std::cout<<"Null Node"<<std::endl;
        exit(1);
    }
    std::string node_content = node->content;
    int type = static_cast<int>(node->nodeType);
    switch(type){
        case static_cast<int>(AstNodeType:: BODY):{
            AbstractAstNode* child = node->getFirstChild();
                    // child->printNodeInfo();
                    int i=0;
                    while(child != NULL){
                        std::cout<<"Body_Gen "<<child->content<<std::endl;
                        Body_Generate(child, symbol_table);
                        child = child->getNextSibling();
                    }
        }
        break;

        case static_cast<int>(AstNodeType:: STATEMENT):{
            if(node_content == "Exp_Stmt")
            {
                Exp_Stmt_Generate(node->getFirstChild(), symbol_table);
            }
            else if(node_content == "Some_Stmt" || 
                node_content == "Def_Stmt" || 
                node_content == "Body_Stmt")
            {
                AbstractAstNode* child = node->getFirstChild();
                while(child != NULL){
                        std::cout<<"Body_Gen "<<child->content<<std::endl;
                        Body_Generate(child, symbol_table);
                        child = child->getNextSibling();
                    }
            }
            else if(node_content == "If")
            {
                std::cout<<"IF BEGIN GEN!!!!!!"<<std::endl;
                Exp_Stmt_Generate(node->getFirstChild(), symbol_table); 
                std::cout<<"IF_EXPRESSION GEN OK!!!!!!"<<std::endl;
                AbstractAstNode* child = node->getFirstChild(); 
                int start = quad_list.size();
                std::list<int> JudgeTrue = trueList.top();
                std::list<int> JudgeFalse = falseList.top();
                trueList.pop(); 
                falseList.pop();              
                backpatch(&JudgeTrue, start);
                SymbolTable* if_symbol_table = new SymbolTable(false);
                if_symbol_table->setParentTable(symbol_table);
                if (symbol_table->firstChildTable == NULL){
                    symbol_table->firstChildTable = if_symbol_table;
                }else {
                    SymbolTable* temp = symbol_table->firstChildTable;
                    while(temp->nextSiblingTable != NULL){
                        temp = temp->nextSiblingTable;
                    }
                temp->addNextSiblingTable(symbol_table);
                }
                Body_Generate(child ->getNextSibling(), if_symbol_table);                 
                int end = quad_list.size();        
                backpatch(&JudgeFalse, end);         
            }
            else if(node_content == "If_Else")
            {                 
                Exp_Stmt_Generate(node->getFirstChild(), symbol_table);                 
                AbstractAstNode* child = node->getFirstChild()->getNextSibling();                 
                int start = quad_list.size();                 
                std::list<int> JudgeTrue = trueList.top();                 
                std::list<int> JudgeFalse = falseList.top();                 
                trueList.pop();                 
                falseList.pop();                 
                backpatch(&JudgeTrue, start);     

                SymbolTable* if_symbol_table = new SymbolTable(false);
                if_symbol_table->setParentTable(symbol_table);
                if (symbol_table->firstChildTable == NULL){
                    symbol_table->firstChildTable = if_symbol_table;
                }else {
                    SymbolTable* temp = symbol_table->firstChildTable;
                    while(temp->nextSiblingTable != NULL){
                        temp = temp->nextSiblingTable;
                    }
                temp->addNextSiblingTable(symbol_table);
                }          

                Body_Generate(child, if_symbol_table);                 
                child = child->getNextSibling();        
                QuadItem *temp =new QuadItem( (int)NULL,OpType::JUMP);                 
                this->quad_list.push_back(temp);                 
                temp = quad_list.back();                 
                int elseStart = quad_list.size();

                SymbolTable* else_symbol_table = new SymbolTable(false);
                else_symbol_table->setParentTable(symbol_table);
                if (symbol_table->firstChildTable == NULL){
                    symbol_table->firstChildTable = else_symbol_table;
                }else {
                    SymbolTable* temp = symbol_table->firstChildTable;
                    while(temp->nextSiblingTable != NULL){
                        temp = temp->nextSiblingTable;
                    }
                temp->addNextSiblingTable(symbol_table);
                }          

                Body_Generate(child, else_symbol_table);                 
                backpatch(&JudgeFalse, elseStart);                 
                int end = quad_list.size();                 
                temp->backpatch(end);             
            }
            else if(node_content == "While"){
                AbstractAstNode *child=node->getFirstChild();
                int start = quad_list.size();
                Exp_Stmt_Generate(child, symbol_table);
                std::list<int> JudgeTrue = trueList.top();                
                std::list<int> JudgeFalse = falseList.top(); 
                trueList.pop();
                falseList.pop(); 
                backpatch(&JudgeTrue, JudgeTrue.back() + 2);
                child=child->getNextSibling();
                while (child != NULL){ 
                    SymbolTable* while_symbol_table = symbol_table->addChildTable(false);
                    Body_Generate(child, while_symbol_table);
                    child = child->getNextSibling();
                }
                int end = quad_list.size();
                QuadItem *temp = new QuadItem(start,OpType::JUMP);
                this->quad_list.push_back(temp);                
                backpatch(&JudgeFalse, end+1);
            }
            else if(node_content == "For_Def_SEMI_Exp_SEMI_Exp"){
                std::cout<<"======FOR FROM HERE!=============="<<std::endl;
                AbstractAstNode *child=node->getFirstChild();
                AbstractAstNode *for_body=child->getNextSibling()->getNextSibling()->getNextSibling();                
                SymbolTable *for_symbol_table = symbol_table->addChildTable(false);
                Exp_Stmt_Generate(child, for_symbol_table);
                int start = quad_list.size();
                //first operation
                child = child->getNextSibling();
                Exp_Stmt_Generate(child, for_symbol_table);
                std::list<int> JudgeTrue = trueList.top();
                std::list<int> JudgeFalse = falseList.top();
                trueList.pop();
                falseList.pop();
                backpatch(&JudgeTrue, JudgeTrue.back() + 2);                
                Body_Generate(for_body, for_symbol_table);
                Exp_Stmt_Generate(child->getNextSibling(), for_symbol_table);
                int end = quad_list.size();
                QuadItem *temp = new QuadItem(start,OpType::JUMP);
                this->quad_list.push_back(temp);                
                backpatch(&JudgeFalse, end+1);
            }
            else if(node_content == "Return_Exp"){
                AbstractAstNode *child=node->getFirstChild();
                Exp_Stmt_Generate(child,symbol_table);

            }

        }
        break;

        case static_cast<int>(AstNodeType:: DEFINITION): {
            if(node_content == "Def_Var" || node_content == "Def_Var_Block"){
                // 默认类型声明的类型为 int；
                int varType = static_cast<int>(SymbolType:: integer);
                AbstractAstNode* mod_node = node->getFirstChild();
                if(mod_node->content == "INT_TYPE"){
                    // varType不变;
                }else {
                    // varType 不是int，则需要重新定义之；
                }
                AbstractAstNode* child = mod_node->getNextSibling();
                while(child != NULL){
                    std::cout<<"Body_Gen "<<child->content<<std::endl;
                    Body_Generate(child, symbol_table);
                    child = child->getNextSibling();
                }
            }else if(node_content == "Def_Single_Var" || node_content == "Def_Some_Var"){
                AbstractAstNode* child = node->getFirstChild();
                AbstractAstNode* mod_node = node->getParent()->getFirstChild();
                if (child->content == "Var_ASSIGN"){
                    std::string var_name;
                    std::string const_value;
                    var_name = child->getFirstChild()->getFirstChild()->content;
                    const_value = child->getFirstChild()->getNextSibling()->getFirstChild()->content;
                    Symbol* var = new Symbol(var_name, SymbolType:: var, 4, const_value);
                    var->setSymOffset(symbol_table->getOffset()+var->getWidth());
                    symbol_table->setOffset(symbol_table->getOffset()+var->getWidth()); 
                    var->setSymOffset(symbol_table->getOffset());
                    symbol_table->addSymbol(var);
                    Symbol* arg1 = new Symbol(const_value);
                    QuadItem* quad;
                    if(isNumber(arg1->getIDName())){
                        std::cout<<"arg1 is a number: "<< atoi(arg1->getIDName().c_str())<<std::endl;
                        quad = new QuadItem(var, assign, atoi(arg1->getIDName().c_str()));
                    }else {
                        quad = new QuadItem(var, assign, arg1);
                    }
                    this->quad_list.push_back(quad);
                }
                else if(child->content == "Var_ONLY"){
                    if(child->getFirstChild()->content == "array_id[const]"){
                        std::string var_name = child->getFirstChild()->getFirstChild()->content;
                        std::string size_str = child->getFirstChild()->getFirstChild()->getNextSibling()->content;
                        int size = atoi(size_str.c_str());
                        Symbol* var = new Symbol(var_name, SymbolType::array, size*4);
                        symbol_table->setOffset(symbol_table->getOffset()+var->getWidth());
                        var->setSymOffset(symbol_table->getOffset());
                        symbol_table->addSymbol(var);
                        // std::cout<<"Add Symbol "<<var_name<<" into SymbolTable!"<<std::endl;
                    }else{
                        std::string var_name;
                        var_name = child->getFirstChild()->getFirstChild()->content;
                        Symbol* var = new Symbol(var_name, SymbolType:: var, 4);
                        symbol_table->setOffset(symbol_table->getOffset()+var->getWidth()); 
                        var->setSymOffset(symbol_table->getOffset());
                        symbol_table->addSymbol(var);
                        // std::cout<<"Add Symbol "<<var_name<<" into SymbolTable!"<<std::endl;
                    }
                   
                }
                if(node_content == "Def_Some_Var"){
                    AbstractAstNode* child = node->getFirstChild()->getNextSibling();
                    while(child != NULL){
                        Body_Generate(child, symbol_table);
                        child = child->getFirstChild()->getNextSibling();
                    }
                }
            }
        }
        break;
        case static_cast<int>(AstNodeType:: OPERATION):{
            std::cout<<"+++++++++Here!!!!++++++++++++"<<std::endl; 
            Exp_Stmt_Generate(node,symbol_table);
        }
        break;
        default:
            std::cout<<"No such AstNodeType!"<<std::endl; 
            exit(1);
        break;
    }

}


//content of 3 function for 3backpatch
//I dont know where to use the first 2
std::list<int> *InterCode::makelist(int index)
{
    std::list<int> *jumpList = new std::list<int>();
    jumpList->push_back(index);
    return jumpList;
}
std::list<int> *InterCode::merge(std::list<int> *list1, std::list<int> *list2)
{
    list1->merge(*list2);
    return list1;
}
void InterCode::backpatch(std::list<int> *backList, int target)
{
    std::list<int>::iterator it;
    std::cout<<"====backlist_begin====="<<*(backList->begin())<<"=========="<<std::endl;
    std::cout<<"====backlist_end====="<<*(backList->end())<<"=========="<<std::endl;
    std::cout<<"====target====="<<target<<"=========="<<std::endl;
    for (it = backList->begin(); it != backList->end(); it++)
    {
        quad_list[*it]->backpatch(target);
    }
    return;
}