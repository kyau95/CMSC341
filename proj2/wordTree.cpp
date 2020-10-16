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
    Node *y = aNode->_right;
    Node *temp = y->_left;

    y->_left = aNode;
    aNode->_right = temp;

    updateHeight(aNode);
    updateHeight(y);

    return y;
}

Node *WordTree::rightRotation(Node *aNode) {
    Node *x = aNode->_left;
    Node *temp = x->_right;

    x->_right = aNode;
    aNode->_left = temp;

    updateHeight(aNode);
    updateHeight(x);

    return x;
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
        insert(element, _root);
    }
    else {
        _root = new Node(element);
        _root->_count = 1;
    }
}

Node *WordTree::insert(const string &element, Node *&aNode) {
    if (element == aNode->_value) {
        ++aNode->_count;
    }
    else if (element < aNode->_value) {
        if (aNode->_left) {
            aNode->_left->_parent = insert(element, aNode->_left);
        }
        else {
            aNode->_left = new Node(element);
            aNode->_left->_parent = aNode;
        }
    }
    else {
        if (aNode->_right) {
            aNode->_right->_parent = insert(element, aNode->_right);
        }
        else {
            aNode->_right = new Node(element);
            aNode->_right->_parent = aNode;
        }
    }

    // Need to check for rebalancing for each potential cases, LL, RR, LR, RL
    int balance_factor = checkBalance(aNode);

    return aNode;
}

int WordTree::searchCount(string word) {
    if (_root) {
        return searchCountHelp(_root, word);
    }
    else {
        return 0;
    }
}

int WordTree::searchCountHelp(Node *aNode, string word, int counter) {
    return 0;
}

int WordTree::getRootHeight() {
    return _root->_height;
}

int WordTree::getNodeHeight(string word) {
    if (_root) {
        return getNodeHeightHelp(_root, word);
    }
    else {
        return 0;
    }
}

int WordTree::getNodeHeightHelp(Node *aNode, string word) {
    if (word < aNode->_value) {
        if (aNode->_left) {
            return getNodeHeightHelp(aNode->_left, word);
        }
        else {
            return -1;
        }
    }
    else {
        if (aNode->_right) {
            return getNodeHeightHelp(aNode->_right, word);
        }
        else {
            return -1;
        }
    }
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