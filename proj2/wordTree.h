#include <iostream>
#include <sstream>
#include <string>
using namespace std;

class Grader;  //for grading purposes

class Node {  //stores a word from the text
public:
    friend class Grader;  //for grading purposes
    friend class WordTree;
    Node(const string &v) : _value(v),
                            _left(nullptr),
                            _right(nullptr),
                            _height(0),
                            _count(0),
                            _parent(nullptr) {}
    void printValue() {
        if (this != nullptr)
            cout << _value << endl;
        else
            cout << "NULL" << endl;
    }
    int getFrequency() { return _count; }  //returns number of occurrences of the word
    int getHeight() { return _height; }
    string getValue() { return _value; }
    // Test purposes only
    Node *getRight() { return _right; }
    Node *getLeft() { return _left; }

private:
    string _value;  //the word in this node
    Node *_left;
    Node *_right;
    Node *_parent;
    int _height;
    int _count;  //stores number of occurrences for the word at this node
};

class WordTree {
public:
    friend class Grader;  //for grading purposes
    WordTree() : _root(nullptr) {};
    ~WordTree();
    void insert(const string &element);  //insert, rebalance, update heights
    Node *find(const string &element);
    void dump(std::ostream &ostr = std::cout);
    int searchCount(string word);    //returns the number of operations for a search
    int getRootHeight();             //returns height of tree
    int getNodeHeight(string word);  //returns height of a node with key value word
    /****************************************************************
     * your public member functions start here
     * *************************************************************/
    Node *getRoot() const { return _root; };
    /****************************************************************
     * your public member functions end here
     * *************************************************************/
    Node *_root;
private:
    Node *insert(const string &element, Node *&aNode);  //insert helper function
    void inOrder(Node *aNode, std::ostream &ostr);      //inOrder helper
    Node *find(Node *aNode, const string &element);     //find helper
    void clearTree(Node *aNode);                        //helper called by destructor
    void updateHeight(Node *aNode);
    int checkBalance(Node *aNode);
    Node *reBalance(Node *aNode);
    int searchCountHelp(Node *aNode, string word, int counter);
    int getNodeHeightHelp(Node *aNode, string word);
    Node *leftRotation(Node *aNode);
    Node *rightRotation(Node *aNode);
    /****************************************************************
     * your private member functions start here
     * *************************************************************/
    Node *leftRightRotation(Node *aNode);
    Node *rightLeftRotation(Node *aNode);
    /****************************************************************
     * your private member functions end here
     * *************************************************************/
};