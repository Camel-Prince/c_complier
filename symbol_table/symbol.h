#ifndef _SYMBOL_H
#define _SYMBOL_H

# include <iostream>
# include <vector>
# include <unordered_map>
# include "../abstract_syntax_tree/AstNode.h"
enum class SymbolType {
    integer = 1,
    function,
    pointer,
    boolean,
    Void,
    array
};

class Symbol {
private:
    std::string idName;
    SymbolType idType;
public:
    Symbol();
    Symbol(std::string name, SymbolType type = SymbolType::integer);
    inline std::string getIDName(){return this->idName;};
    inline SymbolType &getSymbolType(){return this->idType;};
};


// a symbolTable correspond to a scop; function-scope and other-wrapped-in-scopes;
class SymbolTable {
public:
    //symbol map 
    std::unordered_map <std::string, Symbol*> SymbolMap;
    //vector pointers for function-table
    std::vector <Symbol*> *symbolArray;
    std::vector <Symbol*> *argArray;
    //relational tables;
    SymbolTable* parentTable;
    SymbolTable* firstChildTable;
    SymbolTable* nextSiblingTable;
    bool isFunctionTable;
    int symbolNumber; // symbol numbers in baseTable;
    //the function table this table is embedded in 
    SymbolTable* baseTable;
    //find in its 
    Symbol* findSymbolLocally(const std::string name);
    bool addSymbol(Symbol* symbol);


    SymbolTable(bool isFunc);
    SymbolTable(bool isFunc, SymbolTable* parentTable);
    inline SymbolTable* getParentTable(){return this->parentTable;}
    inline SymbolTable* getfirstChildTable(){return this->firstChildTable;}
    inline SymbolTable* getNextSiblingTable(){return this->nextSiblingTable;}
    inline int getSymbolNumber(){return this->symbolNumber;}
    inline void setParentTable(SymbolTable* parentTable){this->parentTable = parentTable;}
    SymbolTable* addChildTable(bool isFunc);
    void addNextSiblingTable(SymbolTable* ns);
    Symbol* findSymbolGlobally(const std::string name);

};

//search an ast and build a symbol_table_tree whose root is target;
// void buildSymbolTableTree(AbstractAstNode* node, SymbolTable* target);

#endif