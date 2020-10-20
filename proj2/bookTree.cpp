#ifndef _BOOK_TREE_H_
#define _BOOK_TREE_H_

#include "bookTree.h"
BookTree::BookTree() { _root = nullptr; }

BookTree::~BookTree() { clear(_root); }

BNode *BookTree::makeSplay(BNode *root, string key) {
    return nullptr;
}

BNode *BookTree::rightRotate(BNode *x) {
    return nullptr;
}

BNode *BookTree::leftRotate(BNode *x) {
    return nullptr;
}

bool BookTree::insert(string key, string author, string text) {
    return true;
}

void BookTree::clear(BNode *root) {
    if (root) {
        clear(root->_left);
        clear(root->_right);
        delete root;
    }
}

int BookTree::findFrequency(string title, string word) {
    return 0;
}

void BookTree::dumpTitle(string title) {
}

int BookTree::searchCount(string title, string word) {
    return 0;
}

int BookTree::getTextTreeHeight(string title) {

    return -1;
}
int BookTree::getWordHeight(string title, string word) {

    return -1;
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