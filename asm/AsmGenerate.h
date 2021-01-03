#ifndef ASMGENERATOR_H
#define ASMGENERATOR_H
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <map>
#include "./AsmCode.h"
#include "../symbol_table/symbol.h"
#include "../intermidiate_code/interCode.h"
//需要加上funcsymbol
#include "../symbol_table/FuncSymbol.h"
using namespace std;
enum class asmRegister {
    unset = -1,
    eax = 1,
    ebx = 2,
    ecx = 3,
    edx = 4,
    esp = 5,
    ebp = 6
};

class AsmCode {
private:
    std::string codeBuffer;
    std::string transRegister(asmRegister reg);
public:
    AsmCode();
    std::string generateVar(int offset);
    std::string generateInstanceNumber(int value);
    void generateBinaryInstructor(std::string instructor, asmRegister reg1, asmRegister reg2);
    void generateBinaryInstructor(std::string instructor, asmRegister reg, std::string var);
    void generateBinaryInstructor(std::string instructor, std::string var, asmRegister reg);
    void generateBinaryInstructor(std::string instructor, std::string var1, std::string var2);
    void generateUnaryInstructor(std::string instructor, std::string var);
    void generateUnaryInstructor(std::string instructor, asmRegister reg);
    std::string findValueByAddress(asmRegister reg);
    // ADD instructor, add reg1, reg2
    void add(asmRegister reg1, asmRegister reg2);
    // ADD instructor, add reg, var
    void add(asmRegister reg, std::string var);
    void sub(asmRegister reg1, asmRegister reg2);
    void sub(asmRegister reg, std::string var);
    void mov(asmRegister reg1, asmRegister reg2);
    void mov(asmRegister reg, std::string var);
    void mov(std::string var, asmRegister reg);
    void mov(std::string var1, std::string var2);
    void mul(asmRegister reg1, asmRegister reg2);
    void mul(asmRegister reg, std::string var);
    void mul(std::string var1, std::string var2);
    void div(asmRegister reg1, asmRegister reg2);
    void div(asmRegister reg, std::string var);
    void div(std::string var, asmRegister reg);
    void div(std::string var1, std::string var2);
    void asmXor(asmRegister reg1, asmRegister reg2);
    void push(asmRegister reg);
    void push(std::string var);
    void pop(asmRegister reg);
    void label(std::string label);
    void addCode(std::string code);
    
    friend std::ostream& operator<<(std::ostream& os, const AsmCode& asmcode);
    std::string getcodeBuffer(){return codeBuffer;}

};

class AsmGenerate
{
private:
    int eax;
    int ebx;
    int ecx;
    int edx;
    AsmCode asmcode;
    std::string registerUsedVar[6];
    //std::vector<Symbol*> tempVar;
    std::vector<QuadItem*> quad_list;
    std::map<int, int> labelMap;
    SymbolTable* rootTable;
    SymbolTable* currentTable;
    //FuncTable funcTable;
    void releaseRegister(asmRegister reg);
    asmRegister getRegister(std::string var);
    asmRegister findRegister(std::string var);
    void generateSetArg(QuadItem q);
    void generateArithmetic(QuadItem q);
    void generateJump(QuadItem q);
    void generateNeg(QuadItem q);
    void generatePower(QuadItem q);
    void preSetLabel();
    bool isJumpQuad(OpType code);
    void generateprint(QuadItem q);
public:
    Symbol* getoffsetofarray(Symbol* arg);
    inline AsmCode& getAsmCode() { return this->asmcode; }
    //AsmGenerate(std::vector<QuadItem*>quads, std::vector<Symbol*> tempVar, SymbolTable* rootTable, FuncTable funcTable);
    AsmGenerate(std::vector<QuadItem*>quads, SymbolTable* rootTable);
    void generate();
    void printbuffer(){
        std::cout<<"buffer:"<<this->asmcode.getcodeBuffer()<<"\n\n";
    }
};

#endif
