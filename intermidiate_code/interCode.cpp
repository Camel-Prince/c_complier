#include "interCode.h"
#include <typeinfo>
#include <sstream>
#include <string>
#include<list>

/***
 * 
 * 以下quad_item_type为1-3的为：
 * result为变量；
 * op为双目运算符；
 * ***/
// 常量运算后赋值给变量；
//content:
//1. 3backpatch
//2. zlywhile

// 变量和变量运算后赋值给变量
QuadItem:: QuadItem(Symbol* result, OpType op, Symbol* arg1, Symbol* arg2){
   this->result.var = result;
   this->op = op;
   this->arg1.var = arg1;
   this->arg2.var = arg2;
   //?3 may not right
   this->quad_item_type = 3;
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
    this->quad_item_type = 4;
}
QuadItem::QuadItem(int result,OpType op)
{
    this->op = op;
    this->arg1.var = NULL;
    this->arg2.var = NULL;
    this->result.target = result;
    this->quad_item_type = 5;
}
QuadItem::QuadItem(int result,OpType op, Symbol* arg1, Symbol* arg2)
{
    this->op = op;
    this->arg1.var = arg1;
    this->arg2.var = arg2;
    this->result.target = result;
    this->quad_item_type = 6;
}

/**
 * 
 * 打印出一个四元式；根据op、arg1/2以及result的类型类确定输出格式；
 * 
*/
void QuadItem:: printItemInfor(int i,int j,int len){
    OpType op_type = this->op;
    int type = this->quad_item_type;
    switch (op)
    {
    case addtion:
        if(type == 3){
            std::cout<<"L"
            <<i+1
            <<":  "
            <<this->result.var->getIDName()
            <<" := "
            <<this->arg1.var->getIDName()
            <<" ADD "
            <<this->arg2.var->getIDName()
            <<std::endl;
        }
        break;
    case substract:
        if(type == 3){
            std::cout<<"L"
            <<i+1
            <<":  "
            <<this->result.var->getIDName()
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
            std::cout<<"L"
            <<i+1
            <<":  "
            <<this->result.var->getIDName()
            <<" := "
            <<this->arg1.var->getIDName()
            <<" MUL "
            <<this->arg2.var->getIDName()
            <<std::endl;
        }
        break;
    case divide:
        if(type == 3){
            std::cout<<"L"
            <<i+1
            <<":  "
            <<this->result.var->getIDName()
            <<" := "
            <<this->arg1.var->getIDName()
            <<" DIV "
            <<this->arg2.var->getIDName()
            <<std::endl;
        }
        break;
    case mod:
        if(type == 3){
            std::cout<<"L"
            <<i+1
            <<":  "
            <<this->result.var->getIDName()
            <<" := "
            <<this->arg1.var->getIDName()
            <<" MOD "
            <<this->arg2.var->getIDName()
            <<std::endl;
        }
        break;
    case power:
        if(type == 3){
            std::cout<<"L"
            <<i+1
            <<":  "
            <<this->result.var->getIDName()
            <<" := "
            <<this->arg1.var->getIDName()
            <<" POW "
            <<this->arg2.var->getIDName()
            <<std::endl;
        }
        break;
    case assign:
        std::cout<<"L"
        <<i+1
        <<":  "
        <<this->result.var->getIDName()
        <<" := "
        <<this->arg1.var->getIDName()
        <<std::endl;
    break;
    case JUMP_LT:
        std::cout<<"if "
        <<this->arg1.var->getIDName()
        <<" < "
        <<this->arg2.var->getIDName()
        <<" goto "
        <<"L"
        <<this->result.target+1
        <<std::endl;
        std::cout<<"goto "
        <<"L"<<j
        <<std::endl;
    break;
    case JUMP_LE:
        std::cout<<"if "
        <<this->arg1.var->getIDName()
        <<" <= "
        <<this->arg2.var->getIDName()
        <<" goto "
        <<"L"
        <<this->result.target+1
        <<std::endl;
        std::cout<<"goto "
        <<"L"<<j
        <<std::endl;
    break;
    case JUMP_GT:
        std::cout<<"if "
        <<this->arg1.var->getIDName()
        <<" > "
        <<this->arg2.var->getIDName()
        <<" goto "
        <<"L"
        <<this->result.target+1
        <<std::endl;
        std::cout<<"goto "
        <<"L"<<j
        <<std::endl;
    break;
    case JUMP_GE:
        std::cout<<"if "
        <<this->arg1.var->getIDName()
        <<" >= "
        <<this->arg2.var->getIDName()
        <<" goto "
        <<"L"
        <<this->result.target+1
        <<std::endl;
        std::cout<<"goto "
        <<"L"<<j
        <<std::endl;
    break;
    case JUMP_EQ:
        std::cout<<"if "
        <<this->arg1.var->getIDName()
        <<" == "
        <<this->arg2.var->getIDName()
        <<" goto "
        <<"L"
        <<this->result.target+1
        <<std::endl;
        std::cout<<"goto "
        <<"L"<<j
        <<std::endl;
    break;
    case JUMP_NE:
        std::cout<<"if "
        <<this->arg1.var->getIDName()
        <<" != "
        <<this->arg2.var->getIDName()
        <<" goto "
        <<"L"
        <<this->result.target+1
        <<std::endl;
        std::cout<<"goto "
        <<"L"<<j
        <<std::endl;
    break;

    default:
        break;
    }
}

int InterCode:: getFalseJump(int i){
    if(i <this->quad_list.size()-1){
        return this->quad_list[i+1]->result.target+1;
    }
    return i+2;
    
}

InterCode:: InterCode(){

}

InterCode:: InterCode(AbstractAstNode* root){
    this->root = root;
    this->rootTable = new SymbolTable(true);
}

void InterCode:: Root_Generate(){
    std::cout<<"Gen "<<root->content<<std::endl;
    Generate(this->root);
    int len = this->quad_list.size();
    std::cout<<"========="<<quad_list.size()<<"=========="<<std::endl;
    int i=0;
    while(i < len){
        quad_list[i]->printItemInfor(i,getFalseJump(i),len);
        Symbol* arg1 = quad_list[i]->arg1.var;
        Symbol* arg2 = quad_list[i]->arg2.var;
        // if(arg1 != NULL)quad_list[i]->arg1.var->showSymbolInfor();
        // if(arg2 != NULL)quad_list[i]->arg2.var->showSymbolInfor();
        i++;
    }
    std::cout<<"L"<<len+1<<":  ";
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
        case static_cast<int>(AstNodeType::STATEMENT ):
        {
            if(node_content == "Single_Block")
            {
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
        
        //zlywhile
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
                    // 未定义使用的错误在findSymbolGlobally中定义；
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
            }else if(node_content == "Addition" ||
                node_content == "Substraction" ||
                node_content == "Multiply" || 
                node_content == "Divide" || 
                node_content == "Mod" || 
                node_content == "Power"){
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
                }else {
                    std::cout<<"Error!"<<std::endl;
                    exit(1);
                }
                this->quad_list.push_back(quad);
                // std::cout<<"quad_list Size: "<<quad_list.size()<<std::endl;
                return re;
            } else if(node_content == "Assign"){
                OpType op = assign;
                std::cout<<"=========assign=========="<<std::endl;
                Symbol* re = Exp_Stmt_Generate(node->getFirstChild(), symbol_table);
                std::cout<<"========="<<re->getIDName()<<"=========="<<std::endl;
                Symbol* arg1 = Exp_Stmt_Generate(node->getFirstChild()->getNextSibling(), symbol_table);
                std::cout<<"========="<<arg1->getIDName()<<"=========="<<std::endl;
                QuadItem* quad;
                if( re != NULL && arg1 != NULL){
                    quad = new QuadItem(re, op, arg1);
                }else {
                    std::cout<<"Error!"<<std::endl;
                    exit(1);
                }
                this->quad_list.push_back(quad);
                std::cout<<"quad_list Size: "<<quad_list.size()<<std::endl;
                return re;
            } else if(node_content == "EQ_OP" ||
                node_content == "NE_OP" ||
                node_content == "GT_OP" ||
                node_content == "LT_OP" ||
                node_content == "GE_OP" ||
                node_content == "LE_OP" ){
                Symbol* arg1 = Exp_Stmt_Generate(node->getFirstChild(), symbol_table);
                std::cout<<"========="<<arg1->getIDName()<<"=========="<<std::endl; 
                Symbol* arg2 = Exp_Stmt_Generate(node->getFirstChild()->getNextSibling(), symbol_table); 
                std::cout<<"========="<<arg2->getIDName()<<"=========="<<std::endl; 
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
                if (arg1 != NULL && arg2 != NULL){
                    QuadItem *T = new QuadItem(int(NULL),op,arg1,arg2);
                    // std::cout<<"*****************"<<std::endl;
                    //T->printItemInfor();
                    QuadItem *F = new QuadItem(int(NULL),OpType::JUMP);
                    // std::cout<<"*****************"<<std::endl;
                    std::list<int> trueL; 
                    int len = quad_list.size();
                    // std::cout<<"========="<<len<<"=========="<<std::endl; 
                    trueL.push_back(len);
                    this->quad_list.push_back(T);
                    std::list<int> falseL; 
                    len = quad_list.size();
                    falseL.push_back(len);
                    // std::cout<<"========="<<len<<"=========="<<std::endl; 
                    this->quad_list.push_back(F);
                    trueList.push(trueL);
                    falseList.push(falseL);
                }else {
                    std::cout<<"Error!"<<std::endl;
                    exit(1);
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
                // std::cout<<"+++++++++"<<start<<"++++++++++++"<<std::endl;
                Exp_Stmt_Generate(child, symbol_table);
                std::list<int> JudgeTrue = trueList.top();                
                std::list<int> JudgeFalse = falseList.top();
                trueList.pop();
                falseList.pop();
                backpatch(&JudgeTrue, JudgeTrue.back() + 2);
                while (child != NULL){
                    SymbolTable* while_symbol_table = new SymbolTable(false);
                    while_symbol_table->setParentTable(symbol_table);
                    if (symbol_table->firstChildTable == NULL){
                        symbol_table->firstChildTable = while_symbol_table;
                        std::cout<<"ADD AS FirstChild"<<std::endl;
                    }else {
                        SymbolTable* temp = symbol_table->firstChildTable;
                        while(temp->nextSiblingTable != NULL){
                            temp = temp->nextSiblingTable;
                        }
                        std::cout<<"ADD AS LastSibling"<<std::endl;
                    temp->addNextSiblingTable(symbol_table);
                    }
                    Body_Generate(child,while_symbol_table);
                    child = child->getNextSibling();
                }
                QuadItem *temp = new QuadItem(start,OpType::JUMP);
                this->quad_list.push_back(temp);
                int end = quad_list.size();
                backpatch(&JudgeFalse, end);
            }
            else if(node_content == "For_Def_SEMI_Exp_SEMI_Exp"){
                AbstractAstNode *child=node->getFirstChild();
                SymbolTable *childTable = symbol_table->addChildTable(false);
                //definition
                Exp_Stmt_Generate(node->getFirstChild(), childTable);
                int start = quad_list.size();
                //first operation
                Exp_Stmt_Generate(node->getFirstChild()->getNextSibling(), childTable);
                std::list<int> JudgeTrue = trueList.top();
                std::list<int> JudgeFalse = falseList.top();
                trueList.pop();
                falseList.pop();
                backpatch(&JudgeTrue, JudgeTrue.back() + 2);
                while (child != NULL)
                {
                    Exp_Stmt_Generate(child, childTable);
                    child = child->getNextSibling();
                }
                //statement
                Body_Generate(node->getFirstChild()->getNextSibling()->getNextSibling()->getNextSibling(), childTable);
                QuadItem *temp = new QuadItem(start,OpType::JUMP);
                this->quad_list.push_back(temp);
                int end = quad_list.size();
                backpatch(&JudgeFalse, end);
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
                }else if(child->content == "Var_ONLY"){
                    std::string var_name;
                    var_name = child->getFirstChild()->getFirstChild()->content;
                    Symbol* var = new Symbol(var_name, SymbolType:: var, 4);
                    symbol_table->addSymbol(var);
                    std::cout<<"Add Symbol "<<var_name<<" into SymbolTable!"<<std::endl;
                    // TBD
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
    // std::cout<<"========="<<*(backList->begin())<<"=========="<<std::endl;
    // std::cout<<"========="<<*(backList->end())<<"=========="<<std::endl;
    // std::cout<<"========="<<target<<"=========="<<std::endl;
    for (it = backList->begin(); it != backList->end(); it++)
    {
        quad_list[*it]->backpatch(target);
    }
    return;
}