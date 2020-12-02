#include <iostream>
#include "AstNode.cpp"
using namespace std;
int main(){
    cout<<"Test AstNode"<<endl;
    AbstractAstNode root = AbstractAstNode();
    AbstractAstNode L10 = AbstractAstNode();
    AbstractAstNode L11 = AbstractAstNode();
    AbstractAstNode L20 = AbstractAstNode();
    AbstractAstNode L21 = AbstractAstNode();
    AbstractAstNode L22 = AbstractAstNode();
    AbstractAstNode L23 = AbstractAstNode();
    AbstractAstNode L30 = AbstractAstNode();
    root.addFirstChild(&L10);
    L10.addNextSibling(&L11);
    L10.addFirstChild(&L20);
    L20.addNextSibling(&L21);
    L11.addFirstChild(&L22);
    L22.addNextSibling(&L23);
    L23.addFirstChild(&L30);
    AbstractAstNode new_Root = AbstractAstNode();
    new_Root.addFirstChild(&root);
//    cout<<"Root Depth: "<<root.getDepth()<<endl;
//    cout<<"L10 Depth: "<<L10.getDepth()<<endl;
//    cout<<"L11 Depth: "<<L11.getDepth()<<endl;
//    cout<<"L20 Depth: "<<L20.getDepth()<<endl;
//    cout<<"L21 Depth: "<<L21.getDepth()<<endl;
//    cout<<"L22 Depth: "<<L22.getDepth()<<endl;
//    cout<<"L23 Depth: "<<L23.getDepth()<<endl;
//    cout<<"L30 Depth: "<<L30.getDepth()<<endl;
    // new_Root.printNodeInfo();
    printAst(&new_Root);
    return 0;
}


