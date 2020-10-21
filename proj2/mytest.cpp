#include <iostream>
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

int main() {
    cout << "Running tests\n\n";

    wordTree_test_searchCount_word_found();
    wordTree_test_searchCount_no_word_found();
    wordTree_test_updateHeight_height_updated();
    wordTree_test_find_word_found();
    wordTree_test_find_no_word_found();
    wordTree_test_right_rotation();
    wordTree_test_left_rotation();
    wordTree_test_left_right_rotation();
    wordTree_test_right_left_rotation();


    return 0;
}