#ifndef _WORD_TREE_H_
#define _WORD_TREE_H_

#include "wordTree.h"

WordTree::~WordTree() {
    clearTree(_root);
}

void WordTree::updateHeight(Node *aNode) {
    // Height is the height of the deepest subtree + 1
    //              2 o
    //               / \
    //            1 o   o
    //               \
    //              0 o
    int left_height = aNode && aNode->_left ?
                      aNode->_left->_height : 0;
    int right_height = aNode && aNode->_right ?
                       aNode->_right->_height : 0;
    aNode->_height = max(left_height, right_height) + 1;
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
    if (aNode) {
        if (element < aNode->_value) { // Case when moving to the left of BST
            return find(aNode->_left, element);
        }
        else if (element > aNode->_value) { // Case when moving to the right of BST
            return find(aNode->_right, element);
        }
        else { // Case when value is found
            return aNode;
        }
    }
    return nullptr;
}

Node *WordTree::find(const string &element) {
    if (_root) {
        return find(_root, element);
    }
    return nullptr;
}

Node *WordTree::leftRotation(Node *aNode) {
    Node *parent_temp = aNode->_parent;
    Node *pivot = aNode->_right;
    aNode->_right = pivot->_left;
    if (pivot->_left) {
        pivot->_left->_parent = aNode;
    }
    pivot->_left = aNode;
    aNode->_parent = pivot;
    pivot->_parent = parent_temp;
    if (parent_temp) {
        if (parent_temp->_right == aNode) {
            parent_temp->_right = pivot;
        }
        else {
            parent_temp->_left = pivot;
        }
    }
    updateHeight(aNode);
    updateHeight(pivot);
    return pivot;
}

Node *WordTree::rightRotation(Node *aNode) {
    Node *parent_temp = aNode->_parent;
    Node *pivot = aNode->_left;
    aNode->_left = pivot->_right;
    if (pivot->_right) {
        pivot->_right->_parent = aNode;
    }
    pivot->_right = aNode;
    aNode->_parent = pivot;
    pivot->_parent = parent_temp;
    if (parent_temp) {
        if (parent_temp->_left == aNode) {
            parent_temp->_left = pivot;
        }
        else {
            parent_temp->_right = pivot;
        }
    }
    updateHeight(aNode);
    updateHeight(pivot);
    return pivot;
}

Node *WordTree::leftRightRotation(Node *aNode) {
    leftRotation(aNode->_left);
    rightRotation(aNode);
    return aNode;
}

Node *WordTree::rightLeftRotation(Node *aNode) {
    rightRotation(aNode->_right);
    leftRotation(aNode);
    return aNode;
}

int WordTree::checkBalance(Node *aNode) {
    // Formula: left subtree height - right subtree height
    int left_height = aNode && aNode->_left ?
                      aNode->_left->_height : 0;
    int right_height = aNode && aNode->_right ?
                       aNode->_right->_height : 0;
    return left_height - right_height;
}

Node *WordTree::reBalance(Node *aNode) {
    int balance_factor = checkBalance(aNode); // initial balance calculation
    if (balance_factor < -1) { // implies right side imbalanced
        if (checkBalance(aNode->_right) > 0) {
            rightLeftRotation(aNode);
        }
        else {
            leftRotation(aNode);
        }
    }
    else if (balance_factor > 1) {
        if (checkBalance(aNode->_left) < 0) {
            leftRightRotation(aNode);
        }
        else {
            rightRotation(aNode);
        }
    }
    if (aNode->_parent == nullptr) { // reached the root node, terminate
        _root = aNode;
        return aNode;
    }
    else {
        return reBalance(aNode->_parent);
    }
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
    // Perform normal insertion then check for rebalancing
    if (element == aNode->_value) {
        ++aNode->_count;
        return aNode;
    }
    else if (element < aNode->_value) {
        if (aNode->_left) {
            insert(element, aNode->_left);
        }
        else {
            aNode->_left = new Node(element);
            aNode->_left->_parent = aNode;
        }
    }
    else {
        if (aNode->_right) {
            insert(element, aNode->_right);
        }
        else {
            aNode->_right = new Node(element);
            aNode->_right->_parent = aNode;
        }
    }
    updateHeight(aNode);
    return reBalance(aNode);
}

int WordTree::searchCount(string word) {
    // initialize a counter variable to hold the number of searched nodes
    int counter = 0;
    if (_root) {
        return searchCountHelp(_root, word, counter);
    }
    else {
        return counter;
    }
}

int WordTree::searchCountHelp(Node *aNode, string word, int counter) {
    if (aNode) {
        if (word < aNode->_value) { // Word value is less than current value, move left
            return searchCountHelp(aNode->_left, word, ++counter);
        }
        else if (word > aNode->_value) { // Word value is greater than current value, move right
            return searchCountHelp(aNode->_right, word, ++counter);
        }
        else { // Found the word, return the number of steps
            return counter;
        }
    }
    return counter;
}

int WordTree::getRootHeight() { return (_root) ? _root->_height : -1; }

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

#endif // _WORD_TREE_H_