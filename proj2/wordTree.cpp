#include "wordTree.h"

WordTree::~WordTree() {
    clearTree(_root);
}

void WordTree::updateHeight(Node *aNode) {
    // Formula: |Height of left subtree - Height of right subtree|
    
}

void WordTree::clearTree(Node *aNode) {
    if (aNode) {
        clearTree(aNode->_left);
        clearTree(aNode->_right);
        delete aNode;
    }
}

void WordTree::inOrder(Node *aNode, std::ostream &ostr) {
    /***********************************
     *      Do not modify
     * ********************************/
    if (aNode != nullptr) {
        ostr << "[";
        inOrder(aNode->_left, ostr);
        ostr << aNode->_value << ":" << aNode->_count << ":" << aNode->_height;
        inOrder(aNode->_right, ostr);
        ostr << "]";
    }
}

Node *WordTree::find(Node *aNode, const string &element) {
    return nullptr;
}
Node *WordTree::find(const string &element) {
}

Node *WordTree::leftRotation(Node *aNode) {
    return nullptr;
}

Node *WordTree::rightRotation(Node *aNode) {
    return nullptr;
}

int WordTree::checkBalance(Node *aNode) {
    return 0;
}

Node *WordTree::reBalance(Node *aNode) {
    return nullptr;
}

void WordTree::insert(const string &element) {
}

Node *WordTree::insert(const string &element, Node *&aNode) {
    return nullptr;
}

void WordTree::dump(std::ostream &ostr) {
    /***********************************
     *      Do not modify
     * ********************************/
    inOrder(_root, ostr);
}

int WordTree::searchCount(string word) {
    return 0;
}

int WordTree::searchCountHelp(Node *aNode, string word, int counter) {
    return 0;
}

int WordTree::getRootHeight() {
    return 0;
}

int WordTree::getNodeHeight(string word) {
    return 0;
}

int WordTree::getNodeHeightHelp(Node *aNode, string word) {
    return 0;
}