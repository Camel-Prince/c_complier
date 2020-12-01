#include "AstNode.h"

AbstractAstNode:: AbstractAstNode(){
    this->parent = NULL;
    this->firstChild = NULL;
    this->nextSibling = NULL;
    this->content = "Null Node";
    this->depth = 0;
}

AbstractAstNode:: AbstractAstNode(AstNodeType nodeType, char* content){
    this->parent = NULL;
    this->firstChild = NULL;
    this->nextSibling = NULL;
    this->content = content;
    this->nodeType = nodeType;
    this->depth = 0;
}

AbstractAstNode* AbstractAstNode:: getParent(){
    return this->parent;
}

AbstractAstNode* AbstractAstNode:: getFirstChild(){
    return this->firstChild;
}

AbstractAstNode* AbstractAstNode:: getNextSibling(){
    return this->nextSibling;
}

std::string AbstractAstNode:: getContent(){
    return this->content;
}

int AbstractAstNode:: getDepth(){
    return this->depth;
}

void AbstractAstNode:: setDepth(int newDepth){
    this->depth = newDepth;
}

// addFirstChild 和 addNextSibling 负责调好指针关系；depth的更新全部交给updateSubAstDepth
void AbstractAstNode:: addFirstChild(AbstractAstNode* node){ 
    if(node != NULL) {
        this->firstChild = node;
        node->parent = this;
        AbstractAstNode* sibling = node->nextSibling;
        while(sibling != NULL){
            sibling->parent = this;
            sibling = sibling->nextSibling;
        }
        updateSubAstDepth(node);
    }
    else printf("Param is NULL!\n");
}

void AbstractAstNode:: addNextSibling(AbstractAstNode* node) {
    if(node != NULL){
        this->nextSibling = node;
        node->parent = this->parent;
        updateSubAstDepth(node);
    }
    else printf("Param is NULL!\n");
}


void updateSubAstDepth(AbstractAstNode* subRoot){
    if (subRoot == NULL) return;
    subRoot->setDepth(subRoot->getParent()->getDepth()+1);
    AbstractAstNode* sibling = subRoot->getNextSibling();
    updateSubAstDepth(sibling);
    AbstractAstNode* child = subRoot->getFirstChild();
    updateSubAstDepth(subRoot->getFirstChild());
}
