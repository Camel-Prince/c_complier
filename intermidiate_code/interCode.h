#ifndef _INTERCODE_H
#define _INTERCODE_H

#include <iostream>
#include <vector>
#include "../symbol_table/symbol.h"
#include "../abstract_syntax_tree/AstNode.h"

enum  OpType{
    addtion = 1,
    substract,
    multiply,
    divide,
    logic_and,
    logic_or,
    logic_not,
    uminus, // 负号
    label,
};
union Arg{
   int literal;
   Symbol* var;
};


class QuadItem {
private:
    Arg result;
    OpType op;
    Arg arg1;
    Arg arg2;
    int quad_item_type;
public: 
    QuadItem(Symbol* result, OpType op, int arg1, int arg2);
    QuadItem(Symbol* result, OpType op, Symbol* arg1, int arg2);
    QuadItem(Symbol* result, OpType op, int arg1, Symbol* arg2);
    QuadItem(Symbol* result, OpType op, Symbol* arg1, Symbol* arg2);
    QuadItem(Symbol* result, OpType op, int arg1);
    QuadItem(Symbol* result, OpType op, Symbol* arg1);
    void printItemInfor();
};

class InterCode {
private: 
    AbstractAstNode* root;
    std::vector<QuadItem* > quad_list;
    SymbolTable* rootTable;
    std::vector<Symbol* >temp_list;
public:
    InterCode();
    // 从ast生成中间代码；
    InterCode(AbstractAstNode* root);
    Arg Generate(AbstractAstNode* node);
    void Root_Generate();
    void addItem(QuadItem* item);
    void showList();
};

#endif