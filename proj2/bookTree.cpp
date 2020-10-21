#ifndef _BOOK_TREE_H_
#define _BOOK_TREE_H_

#include "bookTree.h"
BookTree::BookTree() { _root = nullptr; }

BookTree::~BookTree() { clear(_root); }

BNode *BookTree::makeSplay(BNode *root, string key) {

    return nullptr;
}

BNode *BookTree::rightRotate(BNode *x) {
    BNode *parent_temp = x->_parent;
    BNode *pivot = x->_left;
    x->_left = pivot->_right;
    if (pivot->_right) {
        pivot->_right->_parent = x;
    }
    pivot->_right = x;
    x->_parent = pivot;
    pivot->_parent = parent_temp;
    if (parent_temp) {
        if (parent_temp->_left == x) {
            parent_temp->_left = pivot;
        }
        else {
            parent_temp->_right = pivot;
        }
    }
    return pivot;
}

BNode *BookTree::leftRotate(BNode *x) {
    BNode *parent_temp = x->_parent;
    BNode *pivot = x->_right;
    x->_right = pivot->_left;
    if (pivot->_left) {
        pivot->_left->_parent = x;
    }
    pivot->_left = x;
    x->_parent = pivot;
    pivot->_parent = parent_temp;
    if (parent_temp) {
        if (parent_temp->_right == x) {
            parent_temp->_right = pivot;
        }
        else {
            parent_temp->_left = pivot;
        }
    }
    return pivot;
}

bool BookTree::insert(string key, string author, string text) {
    if (_root) {
        return insertHelper(_root, key, author, text);
    }
    else {
        _root = new BNode(key, author, text);
    }
    return true;
}

bool BookTree::insertHelper(BNode *node, string key, string author, string text) {
    if (key < _root->_key) {
        return insertHelper(node->_left, key, author, text);
    }
    else if (key > _root->_key) {
        return insertHelper(node->_right, key, author, text);
    }
    else {
        return false;
    }
}

void BookTree::clear(BNode *root) {
    if (root) {
        clear(root->_left);
        clear(root->_right);
        delete root;
    }
}

BNode *BookTree::find(string title, string word) {
    if (_root) {
        return findHelper(_root, title, word);
    }
    else {
        return nullptr;
    }
}

BNode *BookTree::findHelper(BNode *node, string title, string word) {
    if (node->_key == title) {
        Node *word_node = node->_tree.find(word);
        return word_node ? node : nullptr; // if word_node is not nullptr, word exists in the wordTree
    }
    else if (title < node->_key) {
        return findHelper(node->_left, title, word);
    }
    else if (title > node->_key) {
        return findHelper(node->_left, title, word);
    }
    else {
        return nullptr;
    }
}

int BookTree::findFrequency(string title, string word) {
    if (_root) {
        return findFrequencyHelper(_root, title, word);
    }
    else {
        return 0;
    }
}

int BookTree::findFrequencyHelper(BNode *node, string title, string word) {
    if (node->_key == title) {
        return node->findFrequency(word);
    }
    else if (title < node->_key) {
        return findFrequencyHelper(node->_left, title, word);
    }
    else if (title > node->_key) {
        return findFrequencyHelper(node->_left, title, word);
    }
    else {
        return 0;
    }
}

void BookTree::dumpTitle(string title) {
    if (_root) {

    }
}

int BookTree::searchCount(string title, string word) {
    if (_root) {
        return searchCountHelper(_root, title, word);
    }
    return 0;
}

int BookTree::searchCountHelper(BNode *node, string title, string word) {
    if (title == node->_key) {
        return node->_tree.searchCount(word);
    }
    else if (title < node->_key) {
        return searchCountHelper(node->_left, title, word);
    }
    else {
        return searchCountHelper(node->_right, title, word);
    }
}

int BookTree::getTextTreeHeight(string title) {
    if (_root) {
        return getTextTreeHeightHelper(_root, title);
    }
    return -1;
}

int BookTree::getTextTreeHeightHelper(BNode *node, string title) {
    if (title == node->_key) {
        return node->_tree.getRootHeight();
    }
    else if (title < node->_key) {
        return getTextTreeHeightHelper(node->_left, title);
    }
    else {
        return getTextTreeHeightHelper(node->_right, title);
    }
}

int BookTree::getWordHeight(string title, string word) {
    if (_root) {
        return getWordHeightHelper(_root, title, word);
    }
    return -1;
}

int BookTree::getWordHeightHelper(BNode *node, string title, string word) {
    if (title == node->_key) {
        return node->_tree.getNodeHeight(word);
    }
    else if (title < node->_key) {
        return getWordHeightHelper(node->_left, title, word);
    }
    else {
        return getWordHeightHelper(node->_right, title, word);
    }
}

// ========================= NO TOUCHY =========================
string BookTree::getRootKey() {
    /***********************************
     *      Do not modify
     * ********************************/
    return _root->_key;
}

void BookTree::loadData(string dataFile) {
    /***********************************
     *      This function is implemented
     *      to help you. You should't need
     *      to modify it.
     * ********************************/
    //read the entire file at once
    std::ifstream t(dataFile);
    std::stringstream buffer;
    buffer << t.rdbuf();

    //time to parse the information
    string titleDelimiter = "<==>";
    string itemsDeleimiter = "<=>";
    string s = buffer.str();
    size_t pos = 0;
    string token;
    while ((pos = s.find(titleDelimiter)) != string::npos) {
        token = s.substr(0, pos);  //token is complete data for one title
        //get the title
        int tempPos = token.find(itemsDeleimiter);
        string title = token.substr(0, tempPos);
        //convert title to lower case
        std::transform(title.begin(), title.end(), title.begin(), ::tolower);
        token.erase(0, tempPos + itemsDeleimiter.length() + 1);
        //get the author
        tempPos = token.find(itemsDeleimiter);
        string author = token.substr(0, tempPos);
        //convert author to lower case
        std::transform(author.begin(), author.end(), author.begin(), ::tolower);
        token.erase(0, tempPos + itemsDeleimiter.length() + 1);
        //get the text
        string text = token.substr(0, token.length() - 1);  //remove last newline
        //clean up the text, remove all non-alphanumeric characters
        for (std::string::iterator iter = text.begin(); iter != text.end();) {
            if (!std::isalnum(*iter) && *iter != ' ')
                iter = text.erase(iter);
            else
                ++iter;  // not erased, increment iterator
        }
        //convert text to lower case
        std::transform(text.begin(), text.end(), text.begin(), ::tolower);

        insert(title, author, text);

        //move to info for the next title
        s.erase(0, pos + titleDelimiter.length() + 1);
    }
}

void BookTree::inorderHelp(BNode *root, bool verbose) const {
    /***********************************
     *      Do not modify
     * ********************************/
    if (root != nullptr) {
        if (verbose) {
            cout << "(";
            inorderHelp(root->_left, verbose);
            cout << root->_key << ":" << root->_author;
            root->_tree.dump();
            inorderHelp(root->_right, verbose);
            cout << ")";
        }
        else {
            inorderHelp(root->_left, verbose);
            cout << root->_key;
            inorderHelp(root->_right, verbose);
        }
    }
}

void BookTree::dump(bool verbose) const {
    /***********************************
     *      Do not modify
     * ********************************/
    inorderHelp(_root, verbose);
}

#endif // _BOOK_TREE_H_