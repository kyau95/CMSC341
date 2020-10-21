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
    Node *temp = aNode->_right;
    aNode->_right = temp->_left;
    if (temp->_left) {
        temp->_left->_parent = aNode;
    }
    temp->_parent = aNode->_parent;
    if (aNode->_parent == nullptr) {
        _root = temp;
    }
    else {
        if (aNode == aNode->_parent->_left) {
            aNode->_parent->_left = temp;
        }
        else {
            aNode->_parent->_right = temp;
        }
    }
    temp->_left = aNode;
    aNode->_parent = temp;
    updateHeight(aNode);
    updateHeight(temp);

    return temp;
}

Node *WordTree::rightRotation(Node *aNode) {
    Node *temp = aNode->_left;
    aNode->_left = temp->_right;
    if (temp->_right) {
        temp->_right->_parent = aNode;
    }
    temp->_parent = aNode->_parent;
    if (aNode->_parent == nullptr) {
        _root = temp;
    }
    else if (aNode == aNode->_parent->_right) {
        aNode->_parent->_right = temp;
    }
    else {
        aNode->_parent->_left = temp;
    }
    temp->_right = aNode;
    aNode->_parent = temp;

    // Update the height after rotation
    updateHeight(aNode);
    updateHeight(temp);

    return temp;
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
    // Four cases, single rotations (LL and RR) and double rotations (LR and RL);
    int balance_factor = checkBalance(aNode);
    if (balance_factor < -1) {
        if (checkBalance(aNode->_right) > 1) {
            aNode->_right = rightRotation(aNode->_right);
            aNode = leftRotation(aNode);
        }
        else {
            aNode = leftRotation(aNode);
        }
    }
    else if (balance_factor > 1) {
        if (checkBalance(aNode->_left) < -1) {
            aNode->_left = leftRotation(aNode->_left);
            aNode = rightRotation(aNode);
        }
        else {
            aNode = rightRotation(aNode);
        }
    }
    return aNode;
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
    }
    else if (element < aNode->_value) {
        if (aNode->_left) {
            aNode->_left = insert(element, aNode->_left);
        }
        else {
            aNode->_left = new Node(element);
            aNode->_left->_parent = aNode;
        }
    }
    else {
        if (aNode->_right) {
            aNode->_right = insert(element, aNode->_right);
        }
        else {
            aNode->_right = new Node(element);
            aNode->_right->_parent = aNode;
        }
    }
    updateHeight(aNode);

    // Need to check for rebalancing for each potential cases, LL, RR, LR, RL
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

void WordTree::showValueAndParentValue() const {
    showValueAndParentValueHelper(_root);
}

void WordTree::showValueAndParentValueHelper(Node *node) const {
    if (node) {
        showValueAndParentValueHelper(node->_left);
        cout << node->_value << "\t\t" <<
            ((node->_parent) ? node->_parent->_value : "NULL") << "\t\t" << node->getHeight() << '\n';
        showValueAndParentValueHelper(node->_right);
    }
}

#endif // _WORD_TREE_H_