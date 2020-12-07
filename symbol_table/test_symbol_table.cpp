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
    SymbolTable* subScope = new SymbolTable(false, mainScope);
    mainScope->addSymbol(a1);
    mainScope->addSymbol(a2);
    mainScope->addSymbol(a3);
    subScope->addSymbol(a4);
    SymbolTable* subScope2 = mainScope->addChildTable(false);
    subScope2->addSymbol(a5);

    Symbol* re = subScope->findSymbolLocally("a3");
    if(re == NULL){
        cout<<"a3 is not in subScope"<<endl;
    }
    else cout<<"a3 is in subScope"<<endl;

    re = mainScope->findSymbolLocally("a3");
    if(re == NULL){
        cout<<"a3 is not in mainScope local"<<endl;
    }
    else cout<<"a3 is in mainScope local"<<endl;

    re = mainScope->findSymbolLocally("a5");
    if(re == NULL){
        cout<<"a5 is not in mainScope local"<<endl;
    }
    else cout<<"a5 is in mainScope local"<<endl;

    re = subScope2->findSymbolLocally("a5");
    if(re == NULL){
        cout<<"a5 is not in subScope2 local"<<endl;
    }
    else cout<<"a5 is in subScope2 local"<<endl;
    return 0;
}