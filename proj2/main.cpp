#include "bookTree.h"
#include <random>
using namespace std;

int main() {
    //     BookTree aTree;
    //     aTree.loadData("data.txt");
    //     cout << "Frequency of tinsmith in The Wonderful Wizard of Oz: " << endl;
    //     cout << "\t" << aTree.findFrequency("the wonderful wizard of oz", "tinsmith") << endl
    //          << endl;
    //     cout << "Count of search operation for tinsmith in The Wonderful Wizard of Oz: " << endl;
    //     cout << "\t" << aTree.searchCount("the wonderful wizard of oz", "tinsmith") << endl
    //          << endl;
    //     cout << "Height of the node containing tinsmith in The Wonderful Wizard of Oz: " << endl;
    //     cout << "\t" << aTree.getWordHeight("the wonderful wizard of oz", "tinsmith") << endl
    //          << endl;
    //     cout << "Height of word tree for The Wonderful Wizard of Oz: " << endl;
    //     cout << "\t" << aTree.getTextTreeHeight("the wonderful wizard of oz") << endl
    //          << endl;
    //     cout << "Dumping the word tree for The Wonderful Wizard of Oz:" << endl
    //          << endl;
    //     aTree.dumpTitle("the wonderful wizard of oz");
    //     cout << endl;
    WordTree w_tree;
    string test_arr[]{"mango", "carrot", "bird", "tree", "fire", "bird", "orange", "banana", "pear", "apple", "tire"};
    for (int i = 0; i < 11; ++i) {
        w_tree.insert(test_arr[i]);
    }
    cout << "current\t\tparent\t\theight\n";
    w_tree.dump();
    cout << endl;
    w_tree.inorder();
    cout << "\nAfter rotation\n";
    w_tree.inorder();
    return 0;
}