#include <iostream>
#include "interCode.cpp"
#include "../symbol_table/symbol.cpp"
using namespace std;

int main(int argc, char** argv){
    OpType op = divide;
    Symbol* x = new Symbol("X");
    Symbol* y = new Symbol("Y");
    Symbol* re = new Symbol("Result");
    QuadItem q1 = QuadItem(re, op, x, y);
    QuadItem q2 = QuadItem(re, op, x, 3);
    q1.printItemInfor();
    q2.printItemInfor();
    return 0;
}