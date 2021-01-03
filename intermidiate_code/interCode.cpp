#include "interCode.h"
#include <typeinfo>
#include <sstream>
#include <string>
#include <iostream>
#include<list>
std::vector<QuadItem*> reduceUnusedSymbol(std::vector<QuadItem* > quad_list){
    int len = quad_list.size();
    int i=0;
    while(i < len){
        QuadItem* quad = quad_list[i];
        if(quad->getOpType() == OpType::assign){
            Symbol* re = quad->result.var;
            if(re->getIsUsed() == false){
                std::cout<<re->getIDName()<<" is not used!"<<std::endl;
                quad_list.erase(quad_list.begin()+i);
                continue;
            }
        }
        i++;
    }
    return quad_list;
}
char isnumber(char ch){
    if(ch>='0' && ch<= '9'){
        return true;
    }return false;
}
bool isNumber(std::string str){
    int len = str.length();
    for(int i=0; i<len; i++){
        if(! isnumber(str[i])) return false; 
    }
    return true;
}
QuadItem::QuadItem(int result, OpType op, int arg1, int arg2)
{
    this->op = op;
    this->arg1.target = arg1;
    this->arg2.target = arg2;
    this->result.target = result;
    this->quad_item_type = 0;
}

QuadItem::QuadItem(int result, OpType op, Symbol* arg1, int arg2)
{
    this->op = op;
    this->arg1.var = arg1;
    this->arg2.target = arg2;
    this->result.target = result;
    this->quad_item_type = 1;
}

QuadItem::QuadItem(int result, OpType op, int arg1, Symbol* arg2)
{
    this->op = op;
    this->arg1.target = arg1;
    this->arg2.var = arg2;
    this->result.target = result;
    this->quad_item_type = 2;
}

QuadItem::QuadItem(int result,OpType op, Symbol* arg1, Symbol* arg2)
{
    this->op = op;
    this->arg1.var = arg1;
    this->arg2.var = arg2;
    this->result.target = result;
    this->quad_item_type = 3;
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
 * 
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

// for print_int
QuadItem:: QuadItem(Symbol* result, OpType op){
    this->op = op;
    this->arg1.var = NULL;
    this->arg2.var = NULL;
    this->result.var = result;
    this->quad_item_type = 10;
}

/**
 * 
 * 打印出一个四元式；根据op、arg1/2以及result的类型类确定输出格式；
 * 
*/
void QuadItem:: printItemInfor(int i)
{
    OpType op_type = this->op;
    int type = this->quad_item_type;
    // std::cout<<"Quad-Type: "<<type<<"  ";
    // std::cout<<"Op_Type: "<<static_cast<int>(op_type)<<std::endl;
    switch (op)
    {
    case addtion:
        if(type == 7){
            std::cout<<"L"<<i<<":  "
            <<this->result.var->getIDName()
            <<" := "
            <<this->arg1.var->getIDName()
            <<" ADD "
            <<this->arg2.var->getIDName()
            <<std::endl;
        }
        else if(type == 6)
        {
            std::cout<<"L"<<i<<":  "
            <<this->result.var->getIDName()
            <<" := "
            <<this->arg1.target
            <<" ADD "
            <<this->arg2.var->getIDName()
            <<std::endl;
        }
        else if(type == 5)
        {
             std::cout<<"L"<<i<<":  "
            <<this->result.var->getIDName()
            <<" := "
            <<this->arg1.var->getIDName()
            <<" ADD "
            <<this->arg2.target
            <<std::endl;
        }
        else if(type == 4){
            std::cout<<"L"<<i<<":  "
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
           std::cout<<"L"<<i<<":  "
            <<this->result.var->getIDName()
            <<" := "
            <<this->arg1.var->getIDName()
            <<" SUB "
            <<this->arg2.var->getIDName()
            <<std::endl;
        }
        else if(type == 6)
        {
           std::cout<<"L"<<i<<":  "
            <<this->result.var->getIDName()
            <<" := "
            <<this->arg1.target
            <<" SUB "
            <<this->arg2.var->getIDName()
            <<std::endl;
        }
        else if(type == 5)
        {
            std::cout<<"L"<<i<<":  "
            <<this->result.var->getIDName()
            <<" := "
            <<this->arg1.var->getIDName()
            <<" SUB "
            <<this->arg2.target
            <<std::endl;
        }
        else if(type == 4)
        {
            std::cout<<"L"<<i<<":  "
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
           std::cout<<"L"<<i<<":  "
            <<this->result.var->getIDName()
            <<" := "
            <<this->arg1.var->getIDName()
            <<" MUL "
            <<this->arg2.var->getIDName()
            <<std::endl;
        }
        else if(type == 6)
        {
           std::cout<<"L"<<i<<":  "
            <<this->result.var->getIDName()
            <<" := "
            <<this->arg1.target
            <<" MUL "
            <<this->arg2.var->getIDName()
            <<std::endl;
        }
        else if(type == 5)
        {
            std::cout<<"L"<<i<<":  "
            <<this->result.var->getIDName()
            <<" := "
            <<this->arg1.var->getIDName()
            <<" MUL "
            <<this->arg2.target
            <<std::endl;
        }
        else if(type == 4)
        {
            std::cout<<"L"<<i<<":  "
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
           std::cout<<"L"<<i<<":  "
            <<this->result.var->getIDName()
            <<" := "
            <<this->arg1.var->getIDName()
            <<" DIV "
            <<this->arg2.var->getIDName()
            <<std::endl;
        }
        else if(type == 6)
        {
           std::cout<<"L"<<i<<":  "
            <<this->result.var->getIDName()
            <<" := "
            <<this->arg1.target
            <<" DIV "
            <<this->arg2.var->getIDName()
            <<std::endl;
        }
        else if(type == 5)
        {
            std::cout<<"L"<<i<<":  "
            <<this->result.var->getIDName()
            <<" := "
            <<this->arg1.var->getIDName()
            <<" DIV "
            <<this->arg2.target
            <<std::endl;
        }
        else if(type == 4)
        {
            std::cout<<"L"<<i<<":  "
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
           std::cout<<"L"<<i<<":  "
            <<this->result.var->getIDName()
            <<" := "
            <<this->arg1.var->getIDName()
            <<" MOD "
            <<this->arg2.var->getIDName()
            <<std::endl;
        }
        else if(type == 6)
        {
           std::cout<<"L"<<i<<":  "
            <<this->result.var->getIDName()
            <<" := "
            <<this->arg1.target
            <<" MOD "
            <<this->arg2.var->getIDName()
            <<std::endl;
        }
        else if(type == 5)
        {
            std::cout<<"L"<<i<<":  "
            <<this->result.var->getIDName()
            <<" := "
            <<this->arg1.var->getIDName()
            <<" MOD "
            <<this->arg2.target
            <<std::endl;
        }
        else if(type == 4)
        {
            std::cout<<"L"<<i<<":  "
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
           std::cout<<"L"<<i<<":  "
            <<this->result.var->getIDName()
            <<" := "
            <<this->arg1.var->getIDName()
            <<" POW "
            <<this->arg2.var->getIDName()
            <<std::endl;
        }
        else if(type == 6)
        {
           std::cout<<"L"<<i<<":  "
            <<this->result.var->getIDName()
            <<" := "
            <<this->arg1.target
            <<" POW "
            <<this->arg2.var->getIDName()
            <<std::endl;
        }
        else if(type == 5)
        {
            std::cout<<"L"<<i<<":  "
            <<this->result.var->getIDName()
            <<" := "
            <<this->arg1.var->getIDName()
            <<" POW "
            <<this->arg2.target
            <<std::endl;
        }
        else if(type == 4)
        {
            std::cout<<"L"<<i<<":  "
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
           std::cout<<"L"<<i<<":  "
            <<this->result.var->getIDName()
            <<" := "
            <<this->arg1.target
            <<std::endl;
        }
        else if(type == 7)
        {
           std::cout<<"L"<<i<<":  "
            <<this->result.var->getIDName() <<" := "
            <<this->arg1.var->getIDName()<<std::endl;
            // std::cout<<result.var->getIDName()<<" offset: "<<result.var->getSymOffset()<<std::endl;
            // std::cout<<arg1.var->getIDName()<<" offset: "<<arg1.var->getSymOffset()<<std::endl;
        }
    }
    break;
    case JUMP_LT:
        if(type == 3)
        {
           std::cout<<"L"<<i<<":  "<<"if "
            <<this->arg1.var->getIDName()
            <<" < "
            <<this->arg2.var->getIDName()
            <<" goto "
            <<"L"
            <<this->result.target
            <<std::endl;
        }
        else if(type == 2)
        {
           std::cout<<"L"<<i<<":  "<<"if "
            <<this->arg1.target
            <<" < "
            <<this->arg2.var->getIDName()
            <<" goto "
            <<"L"
            <<this->result.target
            <<std::endl;
        }
        else if(type == 1)
        {
           std::cout<<"L"<<i<<":  "<<"if "
            <<this->arg1.var->getIDName()
            <<" < "
            <<this->arg2.target
            <<" goto "
            <<"L"
            <<this->result.target
            <<std::endl;
        }
        else if(type == 0)
        {
           std::cout<<"L"<<i<<":  "<<"if "
            <<this->arg1.target
            <<" < "
            <<this->arg2.target
            <<" goto "
            <<"L"
            <<this->result.target
            <<std::endl;
        }
        
    break;
    case JUMP_LE:
         if(type == 3)
        {
           std::cout<<"L"<<i<<":  "<<"if "
            <<this->arg1.var->getIDName()
            <<" <= "
            <<this->arg2.var->getIDName()
            <<" goto "
            <<"L"
            <<this->result.target
            <<std::endl;
        }
        else if(type == 2)
        {
           std::cout<<"L"<<i<<":  "<<"if "
            <<this->arg1.target
            <<" <= "
            <<this->arg2.var->getIDName()
            <<" goto "
            <<"L"
            <<this->result.target
            <<std::endl;
        }
        else if(type == 1)
        {
           std::cout<<"L"<<i<<":  "<<"if "
            <<this->arg1.var->getIDName()
            <<" <= "
            <<this->arg2.target
            <<" goto "
            <<"L"
            <<this->result.target
            <<std::endl;
        }
        else if(type == 0)
        {
           std::cout<<"L"<<i<<":  "<<"if "
            <<this->arg1.target
            <<" <= "
            <<this->arg2.target
            <<" goto "
            <<"L"
            <<this->result.target
            <<std::endl;
        }
        
    break;
    case JUMP_GT:
         if(type == 3)
        {
           std::cout<<"L"<<i<<":  "<<"if "
            <<this->arg1.var->getIDName()
            <<" > "
            <<this->arg2.var->getIDName()
            <<" goto "
            <<"L"
            <<this->result.target
            <<std::endl;
        }
        else if(type == 2)
        {
           std::cout<<"L"<<i<<":  "<<"if "
            <<this->arg1.target
            <<" > "
            <<this->arg2.var->getIDName()
            <<" goto "
            <<"L"
            <<this->result.target
            <<std::endl;
        }
        else if(type == 1)
        {
           std::cout<<"L"<<i<<":  "<<"if "
            <<this->arg1.var->getIDName()
            <<" > "
            <<this->arg2.target
            <<" goto "
            <<"L"
            <<this->result.target
            <<std::endl;
        }
        else if(type == 0)
        {
           std::cout<<"L"<<i<<":  "<<"if "
            <<this->arg1.target
            <<" > "
            <<this->arg2.target
            <<" goto "
            <<"L"
            <<this->result.target
            <<std::endl;
        }
        
    break;
    case JUMP_GE:
        if(type == 3)
        {
           std::cout<<"L"<<i<<":  "<<"if "
            <<this->arg1.var->getIDName()
            <<" >= "
            <<this->arg2.var->getIDName()
            <<" goto "
            <<"L"
            <<this->result.target
            <<std::endl;
        }
        else if(type == 2)
        {
           std::cout<<"L"<<i<<":  "<<"if "
            <<this->arg1.target
            <<" >= "
            <<this->arg2.var->getIDName()
            <<" goto "
            <<"L"
            <<this->result.target
            <<std::endl;
        }
        else if(type == 1)
        {
           std::cout<<"L"<<i<<":  "<<"if "
            <<this->arg1.var->getIDName()
            <<" >="
            <<this->arg2.target
            <<" goto "
            <<"L"
            <<this->result.target
            <<std::endl;
        }
        else if(type == 0)
        {
           std::cout<<"L"<<i<<":  "<<"if "
            <<this->arg1.target
            <<" >= "
            <<this->arg2.target
            <<" goto "
            <<"L"
            <<this->result.target
            <<std::endl;
        }
        
    break;
    case JUMP_EQ:
         if(type == 3)
        {
           std::cout<<"L"<<i<<":  "<<"if "
            <<this->arg1.var->getIDName()
            <<" == "
            <<this->arg2.var->getIDName()
            <<" goto "
            <<"L"
            <<this->result.target
            <<std::endl;
        }
        else if(type == 2)
        {
           std::cout<<"L"<<i<<":  "<<"if "
            <<this->arg1.target
            <<" == "
            <<this->arg2.var->getIDName()
            <<" goto "
            <<"L"
            <<this->result.target
            <<std::endl;
        }
        else if(type == 1)
        {
           std::cout<<"L"<<i<<":  "<<"if "
            <<this->arg1.var->getIDName()
            <<" == "
            <<this->arg2.target
            <<" goto "
            <<"L"
            <<this->result.target
            <<std::endl;
        }
        else if(type == 0)
        {
           std::cout<<"L"<<i<<":  "<<"if "
            <<this->arg1.target
            <<" == "
            <<this->arg2.target
            <<" goto "
            <<"L"
            <<this->result.target
            <<std::endl;
        }
        
    break;
    case JUMP_NE:
        if(type == 3)
        {
           std::cout<<"L"<<i<<":  "<<"if "
            <<this->arg1.var->getIDName()
            <<" != "
            <<this->arg2.var->getIDName()
            <<" goto "
            <<"L"
            <<this->result.target
            <<std::endl;
        }
        else if(type == 2)
        {
           std::cout<<"L"<<i<<":  "<<"if "
            <<this->arg1.target
            <<" != "
            <<this->arg2.var->getIDName()
            <<" goto "
            <<"L"
            <<this->result.target
            <<std::endl;
        }
        else if(type == 1)
        {
           std::cout<<"L"<<i<<":  "<<"if "
            <<this->arg1.var->getIDName()
            <<" != "
            <<this->arg2.target
            <<" goto "
            <<"L"
            <<this->result.target
            <<std::endl;
        }
        else if(type == 0)
        {
           std::cout<<"L"<<i<<":  "<<"if "
            <<this->arg1.target
            <<" != "
            <<this->arg2.target
            <<" goto "
            <<"L"
            <<this->result.target
            <<std::endl;
        }
        
    break;
    case JUMP:
       std::cout<<"L"<<i<<":  "
        <<" goto "
        <<"L"
        <<this->result.target
        <<std::endl;
    break;
    case PRINT:
        std::cout<<"L"<<i<<":  "
        <<"print_int "
        <<this->result.var->getIDName()<<std::endl;
    break;
    
    default:
    //    std::cout<<"\033[31m Error! No such quad! \033[0m"<<std::endl;
       
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
    // this->quad_list = reduceUnusedSymbol(this->quad_list);
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
            if(node_content == "Parentheses")
            {
                Symbol* re = Exp_Stmt_Generate(node->getFirstChild(), symbol_table);
                re->setIsUsed();
                return re;
            }
            else if(node_content == "Addition" ||
                node_content == "Substraction" ||
                node_content == "Multiply" || 
                node_content == "Divide" || 
                node_content == "Mod" || 
                node_content == "Power")
            {
                        // 注意，先generate完子节点， 再生成result的tempVar；
                Symbol* arg1 = Exp_Stmt_Generate(node->getFirstChild(), symbol_table); arg1->setIsUsed();
                Symbol* arg2 = Exp_Stmt_Generate(node->getFirstChild()->getNextSibling(), symbol_table); arg2->setIsUsed();
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
            } 
            else if(node_content == "Assign")
            {
                OpType op = assign;
                Symbol* re = Exp_Stmt_Generate(node->getFirstChild(), symbol_table); re->setIsUsed();
                Symbol* arg1 = Exp_Stmt_Generate(node->getFirstChild()->getNextSibling(), symbol_table); arg1->setIsUsed();
                // 进行类型检查；type的值是枚举类型symbolType决定的；
                int re_symbol_type = static_cast<int>(re->getSymbolType());
                int arg1_symbol_type = static_cast<int>(arg1->getSymbolType());
                if(re_symbol_type == 4 && arg1_symbol_type == 4){
                    std::cout<<arg1->getIDName()<<" offset "<<arg1->getSymOffset()<<std::endl;
                    re->setSymOffset(arg1->getSymOffset());
                }
                if(arg1_symbol_type== 2 && re_symbol_type == 5 || 
                    arg1_symbol_type== 2 && re_symbol_type == 4)
                {
                    std::cout<<"\033[31m warning: incompatible integer to pointer conversion assigning to 'int *' from 'int'; take the address with & \033[0m"<<std::endl;
                }
                else if(arg1_symbol_type== 5 && re_symbol_type == 2 ||
                        arg1_symbol_type== 4 && re_symbol_type == 2)
                {
                    std::cout<<"\033[31m warning: incompatible pointer to integer conversion assigning to 'int' from 'int *'; dereference with *\n\033[0m"<<std::endl;
                }
                QuadItem* quad;
                if(isNumber(arg1->getIDName())){
                    std::cout<<arg1->getIDName()<<" is a number!!"<<std::endl;
                    quad = new QuadItem(re, op, atoi(arg1->getIDName().c_str()));
                }else {
                    quad = new QuadItem(re, op, arg1);
                }
                this->quad_list.push_back(quad);
                // std::cout<<"quad_list Size: "<<quad_list.size()
                // <<"quad type: "<<quad->getItemType()<<std::endl;
                return re;
            } 
            else if(node_content == "EQ_OP" ||
                node_content == "NE_OP" ||
                node_content == "GT_OP" ||
                node_content == "LT_OP" ||
                node_content == "GE_OP" ||
                node_content == "LE_OP" )
            {
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
                if (isNumber(arg1->getIDName())&& isNumber(arg2->getIDName())){
                   T = new QuadItem(int(NULL), op, atoi(arg1->getIDName().c_str()), atoi(arg2->getIDName().c_str()) );
                }else if (!isNumber(arg1->getIDName())&& isNumber(arg2->getIDName())){
                   T = new QuadItem(int(NULL), op, arg1, atoi(arg2->getIDName().c_str()) );
                }else if (isNumber(arg1->getIDName())&& !isNumber(arg2->getIDName())){
                   T = new QuadItem(int(NULL), op, atoi(arg1->getIDName().c_str()), arg2 );
                }else if (!isNumber(arg1->getIDName())&& !isNumber(arg2->getIDName())){
                   T = new QuadItem(int(NULL), op, arg1, arg2);
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

            }
            else if(node_content == "AND" || node_content == "OR" || node_content == "NOT")
            {
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
            else if(node_content == "id[exp]")// a[i]
            {   
                // * quads for b = a[i]      b is int && a is array(int)
                // * t1 = i*4
                // * t2 = a[t1]
                // * b = t2
                // * 
                
                std::string array_name = node->getFirstChild()->content;
                AbstractAstNode* index_exp_astNode = node->getFirstChild()->getNextSibling();
                // index_symbol 在Exp_Stmt_Generate时候已经进入符号表中了；
                Symbol* index_symbol = Exp_Stmt_Generate(index_exp_astNode, symbol_table);
                std::string index_content = index_symbol->getIDName();
                Symbol* re = new Symbol(array_name+"["+index_content+"]", SymbolType::var, 4);
                return re;
            }
            else if(node_content == "&id")
            {
                // &b是类型为pointer的Symbol；它不进入符号表和temp_list,只是作为offset的传递者以及中间代生成的工具symbol；
                // &b的偏移量就是b的偏移量；
                std::string var_name = node->getFirstChild()->content;
                Symbol* var = symbol_table->findSymbolLocally(var_name);
                if(var == NULL){
                    var = symbol_table->findSymbolGlobally(var_name);
                }
                int offset = var->getSymOffset();
                Symbol* addr_var = new Symbol("&"+var_name, SymbolType::pointer);
                addr_var->setSymOffset(offset);
                // std::cout<<"in &id, "<<addr_var->getIDName()<<" offset is "<<addr_var->getSymOffset();
                return addr_var;
            }
            else if(node_content == "*id")
            {
                std::string pointer_name = node->getFirstChild()->content;
                Symbol* pointer = symbol_table->findSymbolLocally(pointer_name);
                if(pointer == NULL){
                    pointer = symbol_table->findSymbolGlobally(pointer_name);
                }
                int offset = pointer->getSymOffset();
                Symbol* star_pointer = new Symbol("*"+pointer_name, SymbolType::var);
                star_pointer->setSymOffset(offset);
                return star_pointer;
            }
        }
            break;
        case static_cast<int>(AstNodeType::CALL):
        {
            if(node_content == "Call_Args_Func"){
                AbstractAstNode* child = node->getFirstChild();
                if(child->content == "print_int"){
                    std::string var_name = child->getNextSibling()->getFirstChild()->getFirstChild()->getFirstChild()->content;
                    Symbol* var = symbol_table->findSymbolLocally(var_name);
                    if(var == NULL){
                        var = symbol_table->findSymbolGlobally(var_name);
                    }

                    QuadItem* quad = new QuadItem(var, OpType::PRINT);
                    this->quad_list.push_back(quad);
                }
            }
        }
            break;
        case static_cast<int>(AstNodeType::EXPRESSION): // EXPRESSION
        {
            if(node_content == "Const_Exp")
            {
                Symbol* re = new Symbol(node->getFirstChild()->content);
                return re;
            }
            else if(node_content == "ID_Exp")
            {
                Symbol* re = Exp_Stmt_Generate(node->getFirstChild(), symbol_table);
                return re;
            }
            else if(node_content == "For_Exp")
            {
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
                Exp_Stmt_Generate(node->getFirstChild(), symbol_table); 
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
                // std::cout<<"======FOR FROM HERE!=============="<<std::endl;
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
                    if(child->getFirstChild()->content == "Block_Single_Vardef"){
                        std::string var_name = child->getFirstChild()->getFirstChild()->content;
                        Symbol* dup_check = symbol_table->findSymbolLocally(var_name);
                        if(dup_check!= NULL && static_cast<int>(dup_check->getSymbolType()) == 2 )
                        {
                            std::cout<<"\033[31m Error!  Duplicate defination for Variable_name  \033[0m"<<var_name<<std::endl;
                            exit(1);
                        }

                        Symbol* arg1;
                        AbstractAstNode* arg1_astNode = child->getFirstChild()->getNextSibling();
                        arg1 = Exp_Stmt_Generate(arg1_astNode, symbol_table);
                        std::string arg1_content = arg1->getIDName();
                        
                        Symbol* var = new Symbol(var_name, SymbolType:: var, 4);
                        int var_symbol_type = static_cast<int>(var->getSymbolType());
                        int arg1_symbol_type = static_cast<int>(arg1->getSymbolType());
                        if(var_symbol_type == 2 && arg1_symbol_type == 2){
                            symbol_table->setOffset(symbol_table->getOffset()+var->getWidth()); 
                            var->setSymOffset(symbol_table->getOffset());
                            symbol_table->addSymbol(var);
                        }
                        QuadItem* quad;
                        if(isNumber(arg1_content))
                        {
                            // std::cout<<"arg1 is a number: "<< atoi(arg1->getIDName().c_str())<<std::endl;
                            quad = new QuadItem(var, assign, atoi(arg1->getIDName().c_str()));
                        }
                        else 
                        {
                            quad = new QuadItem(var, assign, arg1);
                        }
                        this->quad_list.push_back(quad);

                    }
                    else if(child->getFirstChild()->content == "array_*id"){
                        // int* a = &b;
                        
                        std::string var_name = child->getFirstChild()->getFirstChild()->content;
                        Symbol* dup_check = symbol_table->findSymbolLocally(var_name);
                        if(dup_check!= NULL && static_cast<int>(dup_check->getSymbolType()) == 4 )
                        {
                            std::cout<<"\033[31m  Error! Duplicate defination for Variable_name \033[0m"<<var_name<<std::endl;
                            exit(1);
                        }
                        
                        Symbol* var = new Symbol(var_name, SymbolType::pointer);
                        Symbol* addr_var = Exp_Stmt_Generate( child->getFirstChild()->getNextSibling(),symbol_table);
                        var->setSymOffset(addr_var->getSymOffset());
                        symbol_table->addSymbol(var);
                        QuadItem* quad = new QuadItem(var, assign, addr_var);
                        quad_list.push_back(quad);
                    }
                }
                else if(child->content == "Var_ONLY"){
                    if(child->getFirstChild()->content == "array_id[const]")
                    {
                        std::string var_name = child->getFirstChild()->getFirstChild()->content;
                        Symbol* dup_check = symbol_table->findSymbolLocally(var_name);
                        if(dup_check != NULL && static_cast<int>(dup_check->getSymbolType()) == 5)
                        {
                            std::cout<<"\033[31m Error! Duplicate defination for Array_name \033[0m"<<var_name<<std::endl;
                            exit(1);
                        }
                        std::string size_str = child->getFirstChild()->getFirstChild()->getNextSibling()->content;
                        int size = atoi(size_str.c_str());
                        Symbol* var = new Symbol(var_name, SymbolType::array, size*4);
                        symbol_table->setOffset(symbol_table->getOffset()+var->getWidth());
                        var->setSymOffset(symbol_table->getOffset());
                        symbol_table->addSymbol(var);
                        // std::cout<<"Add Symbol "<<var_name<<" into SymbolTable!"<<std::endl;
                    }
                    else if(child->getFirstChild()->content == "array_*id"){
                        std::string pointer_name = child->getFirstChild()->getFirstChild()->content;
                        Symbol* pointer_var = new Symbol(pointer_name, SymbolType::pointer, 4);
                        pointer_var->setSymOffset(-1); // 偏移量为-1的指针是野指针；
                        // 指针加入符号表，但是不会影响符号表的总偏移量；
                        symbol_table->addSymbol(pointer_var); 
                    }
                    else if(child->getFirstChild()->content == "Block_Single_Vardef"){
                        std::string var_name;
                        var_name = child->getFirstChild()->getFirstChild()->content;
                        Symbol* dup_check = symbol_table->findSymbolLocally(var_name);
                        if(dup_check!= NULL && static_cast<int>(dup_check->getSymbolType()) == 2 )
                        {
                            std::cout<<"\033[31m Error! Duplicate defination for Variable_name \033[0m"<<var_name<<std::endl;
                            exit(1);
                        }
                        Symbol* var = new Symbol(var_name, SymbolType:: var, 4);
                        symbol_table->setOffset(symbol_table->getOffset()+var->getWidth()); 
                        var->setSymOffset(symbol_table->getOffset());
                        symbol_table->addSymbol(var);
                        // std::cout<<"Add Symbol "<<var_name<<" into SymbolTable!"<<std::endl;
                    }
                   
                }
                if(node_content == "Def_Some_Var"){
                    AbstractAstNode* child = node->getFirstChild()->getNextSibling();
                        Body_Generate(child, symbol_table);
                }
            }
        }
        break;
        case static_cast<int>(AstNodeType:: OPERATION):{
            // std::cout<<"+++++++++Here!!!!++++++++++++"<<std::endl; 
            Exp_Stmt_Generate(node,symbol_table);
        }
        break;
        default:
            std::cout<<"No such AstNodeType!"<<std::endl; 
            exit(1);
        break;
    }

}


// 3 function for 3backpatch
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