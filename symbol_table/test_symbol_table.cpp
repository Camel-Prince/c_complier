#include "symbol.h"
#include "symbol.cpp"
#include <iostream>
#include <string>
using namespace std;

int main(){
    Symbol* a1 = new Symbol("a1", SymbolType::integer);
    Symbol* a2 = new Symbol(string("a2"), SymbolType::integer);
    Symbol* a3 = new Symbol(string("a3"), SymbolType::integer);
    Symbol* a4 = new Symbol(string("a4"), SymbolType::integer);
    Symbol* a5 = new Symbol(string("a5"), SymbolType::integer);
    SymbolTable* mainScope = new SymbolTable(true, NULL);
    SymbolTable* subScope = mainScope->addChildTable(false);
    mainScope->addSymbol(a1);
    mainScope->addSymbol(a2);
    mainScope->addSymbol(a3);
    subScope->addSymbol(a4);
    SymbolTable* subScope2 = mainScope->addChildTable(false);
    subScope2->addSymbol(a5);
    SymbolTable* fa = subScope->getParentTable();
    if(subScope2 == subScope->getNextSiblingTable()){
        cout<<"subs is sibling of sub"<<endl;
    }
    if(subScope->getNextSiblingTable()->findSymbolLocally("a5")){
        cout<<"RIGHT!"<<endl;
    }
    return 0;
}