#include <iostream>
#include <cassert>
#include <vector>
#include "bookTree.h"

using namespace std;

void wordTree_test_searchCount_word_found();
void wordTree_test_searchCount_no_word_found();
void wordTree_test_updateHeight_height_updated();
void wordTree_test_find_word_found();
void wordTree_test_find_no_word_found();
void wordTree_test_right_rotation();
void wordTree_test_left_rotation();
void wordTree_test_left_right_rotation();
void wordTree_test_right_left_rotation();

void bNode_test_findFrequency_word_exists();
void bNode_test_findFrequency_word_does_not_exist();
void bNode_test_searchCount_word_exists();
void bNode_test_searchCount_word_does_not_exist();
void bNode_test_getTextTreeHeight();
void bNode_test_getTextTreeHeight_empty();
void bNode_test_getNodeHeight_word_exists();
void bNode_test_getNodeHeight_word_does_not_exist();

void bookTree_test_insert();
void bookTree_test_findFrequency_title_exists();
void bookTree_test_findFrequency_title_does_not_exist();
void bookTree_test_findFrequency_word_exists();
void bookTree_test_findFrequency_word_does_not_exist();
void bookTree_test_searchCount_word_exists();
void bookTree_test_searchCount_word_does_not_exist();


int main() {
    cout << "Running tests\n\n";

    wordTree_test_searchCount_word_found();
//    wordTree_test_searchCount_no_word_found();
//    wordTree_test_updateHeight_height_updated();
    wordTree_test_find_word_found();
    wordTree_test_find_no_word_found();
//    wordTree_test_right_rotation();
//    wordTree_test_left_rotation();
//    wordTree_test_left_right_rotation();
//    wordTree_test_right_left_rotation();

    bNode_test_findFrequency_word_exists();
    bNode_test_findFrequency_word_does_not_exist();
    bNode_test_searchCount_word_exists();
    bNode_test_searchCount_word_does_not_exist();
    bNode_test_getTextTreeHeight();
    bNode_test_getTextTreeHeight_empty();
    bNode_test_getNodeHeight_word_exists();
    bNode_test_getNodeHeight_word_does_not_exist();

    return 0;
}

void wordTree_test_searchCount_word_found() {
    WordTree tree;
    vector<string> values{"hold", "me", "hold", "me", "hold", "me", "hold", "me",
                          "feels", "so", "holy", "holy", "holy", "holy"};
    for (const auto& s : values) {
        tree.insert(s);
    }
    assert(tree.searchCount("feels") == 1);
    assert(tree.searchCount("hold") == 0); // becomes the new root
    assert(tree.searchCount("holy") == 2); // new leaf nodes
    assert(tree.searchCount("me") == 1);
    assert(tree.searchCount("so") == 2); // new leaf nodes
    cout << "wordTree_test_searchCount_word_found() passed\n";
}

void wordTree_test_searchCount_no_word_found() {
    WordTree tree;
    vector<string> values{"may", "i", "have", "your", "attention", "please", "will",
                          "the", "real", "slim", "shady", "please", "stand", "up"};
    for (const auto& s : values) {
        tree.insert(s);
    }
    assert(tree.searchCount("marshall") == 3);
    assert(tree.searchCount("mathers") == 3);
    cout << "wordTree_test_searchCount_no_word_found() passed\n";
}

void wordTree_test_updateHeight_height_updated() {
    WordTree tree;
    vector<string> values{"makin", "my" ,"way", "downtown", "walkin", "fast",
                          "faces", "pass", "and", "im", "homebound"};
    for (const auto& s : values) {
        tree.insert(s);
    }
    // The word "makin" should be rotated all the way to the bottom after all insertions
    assert(tree.getNodeHeight("makin") == 0);
    assert(tree.getNodeHeight("my") == 3);
    assert(tree.getNodeHeight("way") == 0);
    assert(tree.getNodeHeight("downtown") == 1);
    assert(tree.getNodeHeight("walkin") == 1);
    assert(tree.getNodeHeight("fast") == 2);
    assert(tree.getNodeHeight("faces") == 0);
    assert(tree.getNodeHeight("pass") == 0);
    assert(tree.getNodeHeight("and") == 0);
    assert(tree.getNodeHeight("im") == 1);
    assert(tree.getNodeHeight("homebound") == 0);
    cout << "wordTree_test_updateHeight_height_updated() passed\n";
}

void wordTree_test_find_word_found() {
    WordTree tree;
    vector<string> values{"hit", "me", "baby", "one", "more", "time"};
    for (const auto& s : values) {
        tree.insert(s);
    }
    assert(tree.find("time") != nullptr);
    cout << "wordTree_test_searchCount_word_found() passed\n";
}

void wordTree_test_find_no_word_found() {
    WordTree tree;
    vector<string> values{"this", "is", "the", "end", "my", "only", "friend", "the", "end"};
    for (const auto& s : values) {
        tree.insert(s);
    }
    assert(tree.find("beginning") == nullptr);
    cout << ("wordTree_test_searchCount_no_word_found() passed\n");
}

void wordTree_test_right_rotation() {
    WordTree tree;
    vector<string> values{"all", "bananas", "crazy"};
    for (const auto& s : values) {
        tree.insert(s);
    }
    assert(tree.getRoot()->getValue() == "bananas");
    assert(tree.getRoot()->getLeft()->getValue() == "all");
    assert(tree.getRoot()->getRight()->getValue() == "crazy");
    cout << "wordTree_test_right_rotation() passed\n";
}

void wordTree_test_left_rotation() {
    WordTree tree;
    vector<string> values{"zany", "yaks", "weird"};
    for (const auto& s : values) {
        tree.insert(s);
    }
    assert(tree.getRoot()->getValue() == "yaks");
    assert(tree.getRoot()->getRight()->getValue() == "zany");
    assert(tree.getRoot()->getLeft()->getValue() == "weird");
    cout << "wordTree_left_rotation() passed\n";
}

void wordTree_test_left_right_rotation() {
    WordTree tree;
    vector<string> values{"crazy", "apples", "barricading"};
    for (const auto& s : values) {
        tree.insert(s);
    }
    assert(tree.getRoot()->getValue() == "barricading");
    assert(tree.getRoot()->getRight()->getValue() == "crazy");
    assert(tree.getRoot()->getLeft()->getValue() == "apples");
    cout << "wordTree_test_left_right_rotation() passed\n";
}

void wordTree_test_right_left_rotation() {
    WordTree tree;
    vector<string> values{"angry", "chonky", "bats"};
    for (const auto& s : values) {
        tree.insert(s);
    }
    assert(tree.getRoot()->getValue() == "bats");
    assert(tree.getRoot()->getRight()->getValue() == "chonky");
    assert(tree.getRoot()->getLeft()->getValue() == "angry");
    cout << "wordTree_test_right_left_rotation() passed\n";
}

void bNode_test_findFrequency_word_exists() {
    BNode node("Never Gonna Give You Up", "Rick Astley",
    "never gonna give you up never gonna let you down never gonna run around and desert you");
    assert(node.findFrequency("never") == 3);
    cout << "bNode_test_findFrequency_word_exists() \n";
}

void bNode_test_findFrequency_word_does_not_exist() {
    BNode node("never gonna give you up", "rick astely",
        "were no strangers to love you know the rules and so do i");
    assert(node.findFrequency("never") == 0);
    cout << "bNode_test_findFrequency_word_does_not_exist() \n";
}

void bNode_test_searchCount_word_exists() {
    BNode node("never gonna give you up", "rick astely",
               "were no strangers to love you know the rules and so do i");
    assert(node.searchCount("were") == 0);
    cout << "bNode_test_searchCount_word_exists() passed\n";
}

void bNode_test_searchCount_word_does_not_exist() {
    BNode node("never gonna give you up", "rick astely",
               "were no strangers to love you know the rules and so do i");
    assert(node.searchCount("a") == 4);
    cout << "bNode_test_searchCount_word_does_not_exist() passed\n";
}

void bNode_test_getTextTreeHeight() {
    BNode node("never gonna give you up", "rick astely",
               "were no strangers to love you know the rules and so do i");
    assert(node.getTextTreeHeight() == 3);
    cout << "bNode_test_getTextTreeHeight() passed\n";
}

void bNode_test_getTextTreeHeight_empty() {
    BNode node("never gonna give you up", "rick astely","");
    assert(node.getTextTreeHeight() == 0);
    cout << "bNode_test_getTextTreeHeight_empty() passed\n";
}

void bNode_test_getNodeHeight_word_exists() {
    BNode node("never gonna give you up", "rick astely",
               "were no strangers to love you know the rules and so do i");
    assert(node.getNodeHeight("i") == 0);
    cout << "bNode_test_getNodeHeight_word_exists() passed\n";
}

void bNode_test_getNodeHeight_word_does_not_exist() {
    BNode node("never gonna give you up", "rick astely",
               "were no strangers to love you know the rules and so do i");
    assert(node.getNodeHeight("nonexistential") == -1);
    cout << "bNode_test_getNodeHeight_word_does_not_exist() passed\n";
}

void bookTree_test_findFrequency_title_exists() {

}

void bookTree_test_findFrequency_title_does_not_exist() {

}

void bookTree_test_findFrequency_word_exists() {

}

void bookTree_test_findFrequency_word_does_not_exist() {

}

void bookTree_test_searchCount_word_exists() {

}

void bookTree_test_searchCount_word_does_not_exist() {

}
