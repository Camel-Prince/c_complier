#ifndef _ASTNODE_H
#define _ASTNODE_H

#include <iostream>
enum class AstNodeType 
{
    ROOT,
    EXPRESSION,
    CONST_INT,
    OPERATION,
    STATEMENT,
    LOOP,
    SELECT,

};


class AbstractAstNode {
private:
    AstNodeType nodeType;
    AbstractAstNode *parent;
    AbstractAstNode *firstChild;
    AbstractAstNode *nextSibling;
    int depth;
    std::string content;

public:
    AbstractAstNode();
    AbstractAstNode(AstNodeType nodeType, char* content = NULL);
    void addFirstChild(AbstractAstNode* node);
    void addNextSibling(AbstractAstNode* node);
    // void setParent(AbstractAstNode* node);
    inline AbstractAstNode* getParent();
    inline AbstractAstNode* getFirstChild();
    inline AbstractAstNode* getNextSibling();
    inline std::string getContent();
    inline AstNodeType getAstNodeType();
    inline int getDepth();
    inline void setDepth(int newDepth);
    bool isVisited = false;
    void printNodeInfo();
};
void printAst(AbstractAstNode* Root);
void updateSubAstDepth(AbstractAstNode* subRoot); // 当某一节点的depth被跟更新时调用该函数来更新子节点和兄弟节点；
#endif