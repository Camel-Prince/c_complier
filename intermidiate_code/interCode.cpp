#include "interCode.h"
#include <typeinfo>
#include <sstream>
#include <string>

/***
 * 
 * 以下quad_item_type为1-3的为：
 * result为变量；
 * op为双目运算符；
 * ***/
// 常量运算后赋值给变量；
QuadItem:: QuadItem(Symbol* result, OpType op, int arg1, int arg2){
   this->result.var = result;
   this->op = op;
   this->arg1.target = arg1;
   this->arg2.target = arg2;
   this->quad_item_type = 1;
}

// 常量和变量运算后赋值给变量-1；
QuadItem:: QuadItem(Symbol* result, OpType op, Symbol* arg1, int arg2){
   this->result.var = result;
   this->op = op;
   this->arg1.var = arg1;
   this->arg2.target = arg2;
   this->quad_item_type = 2;
}

// 常量和变量运算后赋值给变量-2；
QuadItem:: QuadItem(Symbol* result, OpType op, int arg1, Symbol* arg2){
   this->result.var = result;
   this->op = op;
   this->arg1.target = arg1;
   this->arg2.var = arg2;
   this->quad_item_type = 2;
}

// 变量和变量运算后赋值给变量
QuadItem:: QuadItem(Symbol* result, OpType op, Symbol* arg1, Symbol* arg2){
   this->result.var = result;
   this->op = op;
   this->arg1.var = arg1;
   this->arg2.var = arg2;
   this->quad_item_type = 3;
}

/**
 * 
 * 打印出一个四元式；根据op、arg1/2以及result的类型类确定输出格式；
 * 
*/
void QuadItem:: printItemInfor(){
    OpType op_type = this->op;
    int type = this->quad_item_type;
    switch (op)
    {
    case addtion:
        if(type == 3){
            std::cout<<this->result.var->getIDName()
            <<" := "
            <<this->arg1.var->getIDName()
            <<" ADD "
            <<this->arg2.var->getIDName()
            <<std::endl;
        }
        break;
    case substract:
        if(type == 3){
            std::cout<<this->result.var->getIDName()
            <<" := "
            <<this->arg1.var->getIDName()
            <<" SUB "
            <<this->arg2.var->getIDName()
            <<std::endl;
        }
        // }
        break;
    case multiply:
        if(type == 3){
            std::cout<<this->result.var->getIDName()
            <<" := "
            <<this->arg1.var->getIDName()
            <<" MUL "
            <<this->arg2.var->getIDName()
            <<std::endl;
        }
        break;
    case divide:
        if(type == 3){
            std::cout<<this->result.var->getIDName()
            <<" := "
            <<this->arg1.var->getIDName()
            <<" DIV "
            <<this->arg2.var->getIDName()
            <<std::endl;
        }
        break;
    
    default:
        break;
    }
}

InterCode:: InterCode(){

}

InterCode:: InterCode(AbstractAstNode* root){
    this->root = root;
    this->rootTable = new SymbolTable(false);
}

void InterCode:: Root_Generate(){
    std::cout<<"Gen "<<root->content<<std::endl;
    Generate(this->root);
    int len = this->quad_list.size();
    int i=0;
    while(i < len){
        quad_list[i]->printItemInfor();
         i++;
    }
}

Symbol* InterCode:: Generate(AbstractAstNode* node){
    if(node == NULL){
        std::cout<<"Empty Pointer!"<<std::endl;
        exit(1);
    }
    std::string node_content = node->content;
    int type = static_cast<int>(node->nodeType);
    switch(type){
        case static_cast<int>(AstNodeType::DEFINITION):{
            if(node_content == "Single_ID"){
                Symbol* re = new Symbol(node->getFirstChild()->content);
                return re;
            }
        }
            break;
        case static_cast<int>(AstNodeType::OPERATION):{
            // 注意，先generate完子节点， 再生成result的tempVar；
            Symbol* arg1 = Generate(node->getFirstChild());
            Symbol* arg2 = Generate(node->getFirstChild()->getNextSibling());
            Symbol* re = new Symbol("t"+std::to_string(quad_list.size()));
            OpType op;
            if (node_content == "Addition"){
                op = addtion;
            }else if (node_content == "Substraction"){
                op = substract;
            }else if (node_content == "Multiply"){
                op = multiply;
            }else if (node_content == "Divide"){
                op = divide;
            }else if(node_content == "()"){
                node->getFirstChild()->printNodeInfo();
                Symbol* re = Generate(node->getFirstChild());
                return re;
            }
            QuadItem* quad;
            if (arg1 != NULL && arg2 != NULL){
                quad = new QuadItem(re, op, arg1, arg2);
            }
            this->quad_list.push_back(quad);
            // std::cout<<"quad_list Size: "<<quad_list.size()<<std::endl;
            return re;
        }
            break;
        case static_cast<int>(AstNodeType::ID):{
            std::cout<<"Dealt by Father_node"<<std::endl;
        }
            break;
        case static_cast<int>(AstNodeType::EXPRESSION): // EXPRESSION
        {
            if(node_content == "Const_Exp"){
                Symbol* re = new Symbol(node->getFirstChild()->content);
                return re;
            }else if(node_content == "ID_Exp"){
                Symbol* re = Generate(node->getFirstChild());
                return re;
            }
        }
            break;
        case static_cast<int>(AstNodeType::ROOT):
            {
                AbstractAstNode* child = node->getFirstChild();
                child->printNodeInfo();
                while(child != NULL){
                    std::cout<<"Gen "<<child->content<<std::endl;
                    Generate(child);
                    child = child->getNextSibling();
                }
            }
            break;

        default:
            std::cout<<"No such AstNodeType!"<<std::endl; 
        exit(1);
    }
}
