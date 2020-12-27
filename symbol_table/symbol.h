#ifndef _SYMBOL_H
#define _SYMBOL_H

# include <iostream>
# include <vector>
# include <unordered_map>
# include "../abstract_syntax_tree/AstNode.h"
enum class SymbolType {
    integer = 1,
    var,
    temp_var,
    pointer,
    array,
    boolean,
    Void,
    function_name,
};

class Symbol {
private:
    std::string idName;
    SymbolType idType;
    int width;
    std::string value;
public:
    Symbol();
    Symbol(std::string name, SymbolType type = SymbolType::var, int width = 4, std::string init_value = "0");
    inline std::string getIDName(){return this->idName;}
    inline SymbolType &getSymbolType(){return this->idType;}
    inline int getWidth(){return this->width;}
    inline void setWidth(int width){this->width = width;}
    inline void showSymbolInfor(){
        std::cout<<"Symbol Name: "<<this->idName
                 <<"\tSymbol Addr: "<<this
                 <<"\tSymbol vale: "<<this->value
                 <<"\twitdth: "<<this->width
                 <<"\tSymbol Type: "<<static_cast<int>(this->idType)<<std::endl;
    }
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
    int offset;
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
    inline int getOffset(){return this->offset;}
    inline int setOffset(int increament){this->offset += increament; }
    SymbolTable* addChildTable(bool isFunc);
    void addNextSiblingTable(SymbolTable* ns);
    Symbol* findSymbolGlobally(const std::string name);

};

//search an ast and build a symbol_table_tree whose root is target;
// void buildSymbolTableTree(AbstractAstNode* node, SymbolTable* target);

#endif