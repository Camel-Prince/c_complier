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
    case mod:
        if(type == 3){
            std::cout<<this->result.var->getIDName()
            <<" := "
            <<this->arg1.var->getIDName()
            <<" MOD "
            <<this->arg2.var->getIDName()
            <<std::endl;
        }
        break;
    case power:
        if(type == 3){
            std::cout<<this->result.var->getIDName()
            <<" := "
            <<this->arg1.var->getIDName()
            <<" POW "
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

void InterCode:: Generate(AbstractAstNode* node) {
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
                    // child->printNodeInfo();
                    while(child != NULL){
                        std::cout<<"Gen "<<child->content<<std::endl;
                        Generate(child);
                        child = child->getNextSibling();
                    }
                }
        break;
        case static_cast<int>(AstNodeType::STATEMENT ):{
            if(node_content == "Single_Block"){
                AbstractAstNode* child = node->getFirstChild();
                    // child->printNodeInfo();
                    while(child != NULL){
                        std::cout<<"Gen "<<child->content<<std::endl;
                        Generate(child);
                        child = child->getNextSibling();
                    }
            }
        //     if(node_content == "Some_Block" || node_content == "Single_Block"){
        //        AbstractAstNode* child = node->getFirstChild();
        //             while(child != NULL){
        //                 std::cout<<"Gen "<<child->content<<std::endl;
        //                 Generate(child);
        //                 child = child->getNextSibling();
        //             }
        //     }else if (node_content == "Some_Stmt"){
        //         AbstractAstNode* child = node->getFirstChild();
        //             while(child != NULL){
        //                 std::cout<<"Gen "<<child->content<<std::endl;
        //                 Generate(child);
        //                 child = child->getNextSibling();
        //             }
        //     }else if(node_content == "Def_Stmt"){
        //         AbstractAstNode* child = node->getFirstChild();
        //             while(child != NULL){
        //                 std::cout<<"Gen "<<child->content<<std::endl;
        //                 Generate(child);
        //                 child = child->getNextSibling();
        //             }
        //     }else if(node_content == "Exp_Stmt"){
        //         std::cout<<"Gen "<<node->content<<std::endl;
        //         Exp_Stmt_Generate(node->getFirstChild());
        // }

        }
        break;
        case static_cast<int>(AstNodeType::DEFINITION ):{
            if (node_content == "Def_Func_Body_Block"){
                AbstractAstNode* child = node->getFirstChild();
                    while(child != NULL){
                        std::cout<<"Gen "<<child->content<<std::endl;
                        Generate(child);
                        child = child->getNextSibling();
                    }
            }else if(node_content == "Func_NParam"){
                AbstractAstNode* child = node->getFirstChild();
                    while(child != NULL){
                        std::cout<<"Gen "<<child->content<<std::endl;
                        Generate(child);
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
                        Generate(child);
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
                        Generate(child);
                        child = child->getNextSibling();
                    }
                }
        break;
        case static_cast<int>(AstNodeType::BODY):
                {
                    if(node->getParent()->getFirstChild()->getNextSibling()->getFirstChild()->content == "main"){
                        // 进入了main 函数的body：
                        SymbolTable* symbol_table = new SymbolTable(false);
                        Body_Generate(node, symbol_table);
                        // Symbol* a = symbol_table->findSymbolLocally("a");
                        // Symbol* b = symbol_table->findSymbolLocally("b");
                        // if(a != NULL && b != NULL){
                        //     std::cout<<"Add a,b into main Body!"<<std::endl;
                        // }
                    }
                    // AbstractAstNode* child = node->getFirstChild();
                    // // child->printNodeInfo();
                    // while(child != NULL){
                    //     std::cout<<"Gen "<<child->content<<std::endl;
                    //     Generate(child);
                    //     child = child->getNextSibling();
                    // }
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
                // Symbol* re = new Symbol(node->getFirstChild()->content);
                return re;
            }
        }
            break;
        case static_cast<int>(AstNodeType::OPERATION):{
            if(node_content == "Parentheses"){
                // node->getFirstChild()->printNodeInfo();
                Symbol* re = Exp_Stmt_Generate(node->getFirstChild(), symbol_table);
                return re;
            }
            // 注意，先generate完子节点， 再生成result的tempVar；
            Symbol* arg1 = Exp_Stmt_Generate(node->getFirstChild(), symbol_table);
            Symbol* arg2 = Exp_Stmt_Generate(node->getFirstChild()->getNextSibling(), symbol_table);
            Symbol* re = new Symbol("t"+std::to_string(quad_list.size()), SymbolType::temp_var, 4);
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
            if (arg1 != NULL && arg2 != NULL){
                quad = new QuadItem(re, op, arg1, arg2);
            }
            this->quad_list.push_back(quad);
            // std::cout<<"quad_list Size: "<<quad_list.size()<<std::endl;
            return re;
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
                symbol_table->addSymbol(re);
                return re;
            }else if(node_content == "ID_Exp"){
                Symbol* re = Exp_Stmt_Generate(node->getFirstChild(), symbol_table);
                return re;
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
            if(node_content == "Exp_Stmt"){
                Exp_Stmt_Generate(node->getFirstChild(), symbol_table);
            }else if(node_content == "Some_Stmt" || node_content == "Def_Stmt"){
                AbstractAstNode* child = node->getFirstChild();
                while(child != NULL){
                        std::cout<<"Body_Gen "<<child->content<<std::endl;
                        Body_Generate(child, symbol_table);
                        child = child->getNextSibling();
                    }
            }
        }
        break;

        case static_cast<int>(AstNodeType:: DEFINITION): {
            if(node_content == "Def_Var"){
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
            }else if(node_content == "Def_Single_Var"){
                AbstractAstNode* child = node->getFirstChild();
                // SymbolType symbol_type;
                // int symbol_width;
                AbstractAstNode* mod_node = node->getParent()->getFirstChild();
                if (child->content == "Var_ASSIGN"){
                    std::string var_name;
                    std::string const_value;
                    var_name = child->getFirstChild()->getFirstChild()->content;
                    const_value = child->getFirstChild()->getNextSibling()->getFirstChild()->content;
                    Symbol* var = new Symbol(var_name, SymbolType:: var, 4, const_value);
                    symbol_table->addSymbol(var);
                    std::cout<<"Add Symbol "<<var_name<<" into SymbolTable!"<<std::endl;
                }else {
                    // TBD
                }
            }
        }
        break;

        default:
            std::cout<<"No such AstNodeType!"<<std::endl; 
            exit(1);
        break;
    }

}