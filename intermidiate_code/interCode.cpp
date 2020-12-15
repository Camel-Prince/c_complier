#include "interCode.h"
#include <typeinfo>

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
   this->arg1.literal = arg1;
   this->arg2.literal = arg2;
   this->quad_item_type = 1;
}

// 常量和变量运算后赋值给变量-1；
QuadItem:: QuadItem(Symbol* result, OpType op, Symbol* arg1, int arg2){
   this->result.var = result;
   this->op = op;
   this->arg1.var = arg1;
   this->arg2.literal = arg2;
   this->quad_item_type = 2;
}

// 常量和变量运算后赋值给变量-2；
QuadItem:: QuadItem(Symbol* result, OpType op, int arg1, Symbol* arg2){
   this->result.var = result;
   this->op = op;
   this->arg1.literal = arg1;
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
        }else if(type == 1){
            std::cout<<this->result.var->getIDName()
            <<" := "
            <<this->arg1.literal
            <<" ADD "
            <<this->arg2.literal<<std::endl;
        }
        else if(type == 2){
            std::cout<<this->result.var->getIDName()
            <<" := ";
            if(this->arg1.var == NULL){
                std::cout<<this->arg1.literal
                <<" ADD "
                <<this->arg2.var->getIDName()<<std::endl;
            }else {
                std::cout<<this->arg1.var->getIDName()
                <<" ADD "
                <<this->arg2.literal<<std::endl;
            }  
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
        }else if(type == 1){
            std::cout<<this->result.var->getIDName()
            <<" := "
            <<this->arg1.literal
            <<" SUB "
            <<this->arg2.literal<<std::endl;
        }
        else if(type == 2){
            std::cout<<this->result.var->getIDName()
            <<" := ";
            if(this->arg1.var == NULL){
                std::cout<<this->arg1.literal
                <<" SUB "
                <<this->arg2.var->getIDName()<<std::endl;
            }else {
                std::cout<<this->arg1.var->getIDName()
                <<" SUB "
                <<this->arg2.literal<<std::endl;
            }  
        }
        break;
    case multiply:
        if(type == 3){
            std::cout<<this->result.var->getIDName()
            <<" := "
            <<this->arg1.var->getIDName()
            <<" MUL "
            <<this->arg2.var->getIDName()
            <<std::endl;
        }else if(type == 1){
            std::cout<<this->result.var->getIDName()
            <<" := "
            <<this->arg1.literal
            <<" MUL "
            <<this->arg2.literal<<std::endl;
        }
        else if(type == 2){
            std::cout<<this->result.var->getIDName()
            <<" := ";
            if(this->arg1.var == NULL){
                std::cout<<this->arg1.literal
                <<" MUL "
                <<this->arg2.var->getIDName()<<std::endl;
            }else {
                std::cout<<this->arg1.var->getIDName()
                <<" MUL "
                <<this->arg2.literal<<std::endl;
            }  
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
        }else if(type == 1){
            std::cout<<this->result.var->getIDName()
            <<" := "
            <<this->arg1.literal
            <<" DIV "
            <<this->arg2.literal<<std::endl;
        }
        else if(type == 2){
            std::cout<<this->result.var->getIDName()
            <<" := ";
            if(this->arg1.var == NULL){
                std::cout<<this->arg1.literal
                <<" DIV "
                <<this->arg2.var->getIDName()<<std::endl;
            }else {
                std::cout<<this->arg1.var->getIDName()
                <<" DIV "
                <<this->arg2.literal<<std::endl;
            }  
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
    this->Generate(this->root);
    int len = this->quad_list.size();
    int i=0;
    while(i < len){
        quad_list[i]->printItemInfor();
         i++;
    }
}

Arg InterCode:: Generate(AbstractAstNode* root){
    if(root == NULL){
        std::cout<<"Empty Pointer!"<<std::endl;
        exit(1);
    }
    AbstractAstNode* node = root->getFirstChild();
    std::string node_content = node->getContent();
    switch(node->nodeType){
        case AstNodeType::EXPRESSION: // EXPRESSION
            if(node_content == "Const_Exp"){
                Symbol* sym = new Symbol(node->getFirstChild()->content);
                // temp_list.push_back(sym);
                Arg arg;
                arg.literal = std::stoi(node->getFirstChild()->content);
                return arg;
            }else if(node_content == "ID_Exp"){
                Generate(node->getFirstChild());
            }else if(node_content == "Single_ID"){
                Symbol* sym = new Symbol(node->getFirstChild()->content);
                Arg arg; 
                arg.var = sym;
                // temp_list.push_back(new Symbol(node->getFirstChild()->getContent()));
                return arg;
            }else if(node_content == "Addition"){
                Symbol* re = new Symbol("t"+quad_list.size());
                OpType op = addtion;
                Arg arg1 = Generate(node->getFirstChild());
                Arg arg2 = Generate(node->getFirstChild()->getNextSibling());
                QuadItem* quad;
                if(arg1.var == NULL && arg2.var == NULL){
                    quad = new QuadItem(re, op, arg1.literal, arg2.literal);
                }else if (arg1.var == NULL && arg2.var != NULL){
                    quad = new QuadItem(re, op, arg1.literal, arg2.var);
                }else if (arg1.var != NULL && arg2.var == NULL){
                    quad = new QuadItem(re, op, arg1.var, arg2.literal);
                }else if (arg1.var != NULL && arg2.var != NULL){
                    quad = new QuadItem(re, op, arg1.literal, arg2.literal);
                }
                this->quad_list.push_back(quad);
            }else if(node_content == "Divide"){
                Symbol* re = new Symbol("t"+quad_list.size());
                OpType op = divide;
                Arg arg1 = Generate(node->getFirstChild());
                Arg arg2 = Generate(node->getFirstChild()->getNextSibling());
                QuadItem* quad;
                if(arg1.var == NULL && arg2.var == NULL){
                    quad = new QuadItem(re, op, arg1.literal, arg2.literal);
                }else if (arg1.var == NULL && arg2.var != NULL){
                    quad = new QuadItem(re, op, arg1.literal, arg2.var);
                }else if (arg1.var != NULL && arg2.var == NULL){
                    quad = new QuadItem(re, op, arg1.var, arg2.literal);
                }else if (arg1.var != NULL && arg2.var != NULL){
                    quad = new QuadItem(re, op, arg1.literal, arg2.literal);
                }
                this->quad_list.push_back(quad);
            }
            break;
        default:
            std::cout<<"No such AstNodeType!"<<std::endl; 
        exit(1);
    }
}
