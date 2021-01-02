#ifndef _INTERCODE_H
#define _INTERCODE_H
#include<list>
#include <iostream>
#include <vector>
#include<stack>
#include "../symbol_table/symbol.h"
#include "../abstract_syntax_tree/AstNode.h"

enum  OpType{
    addtion = 1,
    substract,
    multiply,
    divide,
    mod,
    power,
    assign,
    logic_and,
    logic_or,
    logic_not,
    uminus, // 负号
    label,
    JUMP,
    JUMP_LT,
    JUMP_LE,
    JUMP_GT,
    JUMP_GE,
    JUMP_EQ,
    JUMP_NE,
    RETURN_OP,
    PRINT,
    SCAN,
    // array_assign,

};
union Arg{
   int target;
   Symbol* var;
};


class QuadItem {
public: 
    Arg result;
    OpType op;
    Arg arg1;
    Arg arg2;
    int quad_item_type;
    QuadItem(int result,OpType op);
    QuadItem(Symbol* result, OpType op, int arg1, int arg2);
    QuadItem(Symbol* result, OpType op, Symbol* arg1, int arg2);
    QuadItem(Symbol* result, OpType op, int arg1, Symbol* arg2);
    QuadItem(Symbol* result, OpType op, Symbol* arg1, Symbol* arg2);
    QuadItem(Symbol* result, OpType op, int arg1);  //assign const to var;
    QuadItem(Symbol* result, OpType op, Symbol* arg1); //assign var to var;
    QuadItem(int result, OpType op, Symbol* arg1, int arg2);
    QuadItem(int result, OpType op, int arg1, Symbol* arg2);
    QuadItem(int result, OpType op, int arg1, int arg2);
    QuadItem(int result,OpType op, Symbol* arg1, Symbol* arg2);    
    QuadItem(int result, OpType op, int arg1);
    QuadItem(Symbol* result, OpType op);
    void printItemInfor(int i);
    
    //functions for backpatch
    inline void backpatch(int target) { this->result.target = target; };

    inline OpType getOpType() { return this->op; }
    inline int getItemType() { return this->quad_item_type; }
    inline Arg getArg(int index)
    {
        if (index == 1)
            return this->arg1;
        else if (index == 2)
            return this->arg2;
        else if (index == 3)
            return this->result;
    }

};

class InterCode {
private: 
    AbstractAstNode* root;
    std::vector<QuadItem* > quad_list;
    SymbolTable* rootTable;
    std::vector<Symbol* >temp_list;
    std::stack<int>logic;
    std::stack<std::list<int> > trueList;
    std::stack<std::list<int> > falseList;

public:
    InterCode();
    // 从ast生成中间代码；
    InterCode(AbstractAstNode* root);
    Symbol* Exp_Stmt_Generate(AbstractAstNode* node, SymbolTable* symbol_table);
    SymbolTable* Body_Generate(AbstractAstNode* node, SymbolTable* symbol_table);
    void Generate(AbstractAstNode* node, SymbolTable* symbol_tabl);
    void Root_Generate();
    int getFalseJump(int i);
    void addItem(QuadItem* item);
    void showList();
    // 3 func for patch
    std::list<int> *makelist(int index);
    std::list<int> *merge(std::list<int> *list1, std::list<int> *list2);
    void backpatch(std::list<int> *backList, int target);
    std::vector<QuadItem* > getQuadlist(){return quad_list;}
    SymbolTable* getTable(){return rootTable;}

};

#endif
