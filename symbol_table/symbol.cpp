#include "symbol.h"
#include <queue>
#include "../abstract_syntax_tree/AstNode.h"

Symbol::Symbol(){
    this->idName = "";
    this->idType = SymbolType::integer;
    this->width = 4;
    this->value= "0";
}

Symbol::Symbol(std::string name, SymbolType type, int width, std::string init_value){
    this->idName = name;
    this->idType = type;
    this->width = width;
    this->value = init_value;
}


SymbolTable:: SymbolTable(bool isFunc){
    this->isFunctionTable = isFunc;
    this->firstChildTable = NULL;
    this->nextSiblingTable = NULL;
    this->parentTable = NULL;
    this->baseTable = NULL;
    this->offset = 0;
    if(isFunc){
        symbolArray = new std::vector<Symbol* >();
        argArray = new std::vector<Symbol*>();
    }
}
SymbolTable:: SymbolTable(bool isFunc, SymbolTable* parent){
    this->isFunctionTable = isFunc;
    this->firstChildTable = NULL;
    this->nextSiblingTable = NULL;
    this->parentTable = parent;
    this->offset = 0;
    SymbolTable* temp = this;
    while(!temp->isFunctionTable){
        temp = temp->parentTable;
    }
    this->baseTable = temp;
    if(isFunc){
        symbolArray = new std::vector<Symbol* >();
        argArray = new std::vector<Symbol*>();
    }

}

Symbol* SymbolTable:: findSymbolLocally(const std::string name){
    std::unordered_map<std::string, Symbol*>::iterator iter;
    iter = this->SymbolMap.find(name);
    if(iter != this->SymbolMap.end()){
        return iter->second;
    }
    else 
        return NULL;
}

bool SymbolTable:: addSymbol(Symbol* symbol){
    if(this->findSymbolLocally(symbol->getIDName()) == NULL){
        this->SymbolMap[symbol->getIDName()] = symbol;
        this->symbolNumber ++;
        return true;
    }
    return false;
}

Symbol* SymbolTable:: findSymbolGlobally(std::string name){
    SymbolTable* temp = this;
    while(temp != NULL){
        Symbol* result = temp->findSymbolLocally(name);
        if(result == NULL){
            temp = temp->parentTable;
        }else return result;
    }
    std::cout<<"Error: "<<"id "<<name<<" is not defined"<<std::endl;
    exit(1);
    return NULL;
}

SymbolTable* SymbolTable:: addChildTable(bool isFunc){
    SymbolTable* child = new SymbolTable(isFunc);
    child->setParentTable(this);
    // cout<<"Create Child Table and add parent"<<endl;
    if (this->firstChildTable == NULL){
        this->firstChildTable = child;
    }else {
        SymbolTable* temp = this->firstChildTable;
        while(temp->nextSiblingTable != NULL){
            temp = temp->nextSiblingTable;
        }
        temp->addNextSiblingTable(child);
    }
    return child;
}

void SymbolTable:: addNextSiblingTable(SymbolTable* ns){
    this->nextSiblingTable = ns;
    ns->parentTable = this->parentTable;
}

// void buildSymbolTableTree(AbstractAstNode* node, SymbolTable* table){
//    AbstractAstNode* child = node->getFirstChild();
//    while(child!=NULL){
//        AstNodeType child_type = child->getAstNodeType();
//        std::string child_content = child->getContent();
//         if (child_type == AstNodeType::ID){
//             Symbol* s = new Symbol(child_content, SymbolType::integer);
//             table->addSymbol(s);
//         }
//         else if(child_type == AstNodeType::BODY){
//             SymbolTable* subTable = table->addChildTable(false); 
//             buildSymbolTableTree(child, subTable);
//         }
//        child = child->getNextSibling();
//    }

// }

