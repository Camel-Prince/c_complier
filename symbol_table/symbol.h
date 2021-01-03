#ifndef _SYMBOL_H
#define _SYMBOL_H

# include <iostream>
# include <vector>
# include <unordered_map>
# include "../abstract_syntax_tree/AstNode.h"
enum class SymbolType {
    integer = 1,
    var = 2,
    temp_var = 3,
    pointer = 4,
    array = 5,
    boolean,
    Void,
    function_name,
};

class Symbol {
private:
    std::string idName;
    SymbolType idType;
    int width;
    int sym_offset;
    std::string value;
    bool isUsed;
public:
    Symbol();
    Symbol(std::string name, SymbolType type = SymbolType::var, int width = 4, std::string init_value = "0");
    inline std::string getIDName(){return this->idName;}
    inline SymbolType &getSymbolType(){return this->idType;}
    inline int getWidth(){return this->width;}
    inline void setWidth(int width){this->width = width;}
    inline int getSymOffset(){return this->sym_offset;}
    inline void setSymOffset(int offset){this->sym_offset = offset;}
    inline void showSymbolInfor(){
        std::cout<<"Symbol Name: "<<this->idName
                 <<"\tSymbol Addr: "<<this
                 <<"\tSymbol vale: "<<this->value
                 <<"\tSymbol offset: "<<this->sym_offset
                 <<"\twitdth: "<<this->width
                 <<"\tSymbol Type: "<<static_cast<int>(this->idType)
                 <<"\tisUsed: "<<this->isUsed
                 <<std::endl;
    }
    inline void setIsUsed(){this->isUsed = true;}
    inline bool getIsUsed(){return this->isUsed ;}
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
    int total_offset;
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
    inline int getOffset(){return this->total_offset;}
    inline int setOffset(int new_offset){this->total_offset = new_offset; }
    SymbolTable* addChildTable(bool isFunc);
    void addNextSiblingTable(SymbolTable* ns);
    Symbol* findSymbolGlobally(const std::string name);
    inline void showSymbols(){
        std::cout << "SymbolMap contains:\n";
        for ( auto it = SymbolMap.begin(); it != SymbolMap.end(); ++it )
        {
            std::cout << " " << it->first << ":" ;it->second->showSymbolInfor();
        }
        std::cout << std::endl;
    }

};

//search an ast and build a symbol_table_tree whose root is target;
// void buildSymbolTableTree(AbstractAstNode* node, SymbolTable* target);

#endif