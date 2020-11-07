#include "bookTree.h"
#include <random>
#include <vector>
using namespace std;

int main() {
//     BookTree aTree;
//     aTree.loadData("/home/mky/Desktop/341/proj2/data.txt");
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
//    WordTree tree;
//    vector<string> values{"may", "i", "have", "your", "attention", "please", "will",
//                          "the", "real", "slim", "shady", "please", "stand", "up"};
//    for (const auto& s : values) {
//        tree.insert(s);
//    }
    BNode node("never gonna give you up", "rick astley",
                "never gonna give you up never gonna let you down never gonna run around and desert you");
    cout << node.findFrequency("never");
    node._tree.dump();
    return 0;
}