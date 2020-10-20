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
//    string arr[]{"m", "w", "j", "c", "d", "s", "n", "i", "t", "h", "v", "g", "k", "u", "r"};
//    for (int i = 0; i < 15; ++i) {
//        w_tree.insert(arr[i]);
//    }
    w_tree.insert("m");
    w_tree.insert("w");
    w_tree.insert("j");
    w_tree.insert("c");
    w_tree.insert("d");

    w_tree.inorder();
    return 0;
}