#include "wordTree.h"

WordTree::~WordTree() {
    clearTree(_root);
}

void WordTree::updateHeight(Node *aNode) {
    if (aNode) {
        if (aNode->_left && aNode->_right) {
            aNode->_height = max(aNode->_left->_height, aNode->_right->_height) + 1;
        }
        else if (aNode->_left) {
            aNode->_height = aNode->_left->_height + 1;
        }   
        else if (aNode->_right) {
            aNode->_height = aNode->_right->_height + 1;
        }
        else {
            aNode->_height = 0;
        }
    }
}

void WordTree::clearTree(Node *aNode) {
    // Recursively deletes down the tree
    if (aNode) {
        clearTree(aNode->_left);
        clearTree(aNode->_right);
        delete aNode;
    }
}

Node *WordTree::find(Node *aNode, const string &element) {
    
    return nullptr;
}

Node *WordTree::find(const string &element) {
    if (_root) {
        return find(_root, element);
    }
    else {
        return nullptr;
    }
}

Node *WordTree::leftRotation(Node *aNode) {
    return nullptr;
}

Node *WordTree::rightRotation(Node *aNode) {
    return nullptr;
}

int WordTree::checkBalance(Node *aNode) {
    if (aNode) {
        if (aNode->_left && aNode->_right) {
            return aNode->_left->_height - aNode->_right->_height;
        }
        else if (aNode->_left && !aNode->_right) {
            return aNode->_left->_height;
        }
        else if (aNode->_right && !aNode->_left) {
            return aNode->_right->_height;
        }
    }
    return 0;
}

Node *WordTree::reBalance(Node *aNode) {

    return nullptr;
}

void WordTree::insert(const string &element) {
    if (_root) {

    }
    else {
        _root = new Node(element);
        _root->_count = 1;
    }
}

Node *WordTree::insert(const string &element, Node *&aNode) {
    
    return aNode;
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
    
    return -1;
}

int WordTree::getNodeHeightHelp(Node *aNode, string word) {
    return 0;
}

// ========================= NO TOUCHY =========================
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

void WordTree::dump(std::ostream &ostr) {
    /***********************************
     *      Do not modify
     * ********************************/
    inOrder(_root, ostr);
}