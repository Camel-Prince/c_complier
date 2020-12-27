#ifndef _ASTNODE_H
#define _ASTNODE_H

#include <iostream>
enum class AstNodeType 
{
    ROOT = 0,
    ID,
    EXPRESSION,
    CONST_INT,
    OPERATION,
    STATEMENT,
    DEFINITION,
    MODIFY,
    CALL, 
    POINTER,
    ARRAY,
    ADDRESS,
    BODY
};


class AbstractAstNode {
private:
    
    AbstractAstNode *parent;
    AbstractAstNode *firstChild;
    AbstractAstNode *nextSibling;
    int depth;
    

public:
    std::string content;
    AstNodeType nodeType;
    AbstractAstNode();
    AbstractAstNode(AstNodeType nodeType, char* content = NULL);
    void addFirstChild(AbstractAstNode* node);
    void addNextSibling(AbstractAstNode* node);
    inline AbstractAstNode* getParent();
    inline AbstractAstNode* getFirstChild();
    inline AbstractAstNode* getNextSibling();
    inline AbstractAstNode* getLastSiblingNode(); 
    inline std::string getContent();
    inline AstNodeType getAstNodeType();
    inline std::string getNodeTypeName();
    inline int getDepth();
    inline void setDepth(int newDepth);
    bool isVisited = false;
    void printNodeInfo();
};
void printAst(AbstractAstNode* Root);
void updateSubAstDepth(AbstractAstNode* subRoot); // 当某一节点的depth被跟更新时调用该函数来更新子节点和兄弟节点；
AbstractAstNode* getIDNameFromSingleDefStmt(AbstractAstNode* def_stmt);
#endif