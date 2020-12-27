#include "./FuncSymbol.h"

int FuncTable::num = 0;

FuncSymbol::FuncSymbol(AbstractAstNode* func) {
    if (func->getAstNodeType() != AstNodeType::defFunc) {
        throw "Error AST Node type! Must be ASTNodeType::defFunc!";
        return;
    }
    DefFunASTNode* defFunc = (DefFunASTNode*)func;
    this->funcName = defFunc->getContent();
    this->keyName = defFunc->getContent();
    AbstractAstNode* t = defFunc->getArgList();
    while (t) {
        DefVarASTNode* var = (DefVarASTNode*)t;
        this->typeList.push_back(var->getSymbolType());
        if (var->getSymbolType() == symbolType::integer) {
            this->keyName += "_i";
        } else if (var->getSymbolType() == symbolType::pointer) {
            this->keyName += "_p";
        }
        totalArgOffset += 4;
        t = t->getNextSibling();
    }   
}

FuncSymbol::FuncSymbol(std::string funcName, std::vector<SymbolType> typeList, SymbolType rev) {
    this->funcName = funcName;
    this->keyName = funcName;
    this->revType = rev;
    this->typeList = typeList;
    for (size_t i = 0; i < typeList.size(); i++) {
        if (typeList[i] == SymbolType::integer) this->keyName += "_i";
        else if (typeList[i] == SymbolType::pointer) this->keyName += "_p";
    }
}

bool FuncSymbol::operator== (const FuncSymbol& another) {
    return this->keyName == another.keyName; 
}

FuncTable::FuncTable() { 
    // Add build-in function
    std::vector<SymbolType> type;
    type.push_back(SymbolType::integer);
    FuncSymbol* func = new FuncSymbol("print_int", type, SymbolType::Void);
    funcHashTable[func->getKeyName()] = func;
    func = new FuncSymbol("read_int", type, SymbolType::Void);
    funcHashTable[func->getKeyName()] = func;
}

bool FuncTable::addFunction(FuncSymbol* func) {
    if (this->findFunction(func->getKeyName())) {
        return false;
    } else {
        this->funcHashTable[func->getKeyName()] = func;
        return true;
    }
}

bool FuncTable::addFunction(AbstractAstNode* funcAST) {
    FuncSymbol* func = new FuncSymbol(funcAST);
    return this->addFunction(func);
}

FuncSymbol* FuncTable::findFunction(std::string keyName) {
    std::unordered_map<std::string, FuncSymbol*>::iterator iter;
    iter = this->funcHashTable.find(keyName);
    if (iter != this->funcHashTable.end()) return iter->second;
    else return NULL;
}
