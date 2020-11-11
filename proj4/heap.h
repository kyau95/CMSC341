// CMSC 341 - Fall 2020 - Project 4
// heap.h
// Templated, vector-based heap implementation

// To work with Heap, the template class T must provide the following:
//  (a) Default constructor
//  (b) priority function (unsigned priority()) MAX HEAP
//  (c) overloaded insertion operator
// To work with Heap *and* HashTable, it also needs:
//  (d) key function (string key())

#ifndef _HEAP_H
#define _HEAP_H

#include <exception>
#include <iostream>
#include <utility>  // swap
#include <vector>

using std::cout;
using std::endl;
using std::range_error;
using std::swap;
using std::vector;

// To work with Heap and HashTable, class T must provide the
// following:
//  (a) Default constructor
//  (b) priority function (unsigned priority())
//  (c) key function (string key())
//  (d) overloaded insertion operator

class Grader;

template <class T>
class Heap {
    friend Grader;

public:
    // Constructor
    Heap();

    // Inline functions: size, empty, used
    unsigned size() const { return _heap.size() - 1; }
    bool empty() const { return _heap.size() <= 1; }
    bool used() const { return _used; }

    // Main heap operations: insert, read, remove
    void insert(const T& object);
    T readTop() const;
    void removeTop();

    // Dump the entire heap
    void dump() const;

    // Root node always has index 1
    static const unsigned ROOT = 1;

private:
    vector<T> _heap;  // Vector-based heap
    bool _used;       // Has the heap ever been used?  Needed for
                      // linear probing.

    // *********************************************
    // Private helper function declarations go here!
    // *********************************************
    
    // Finds the next successor
    int findNext() const;
};

// ***************************************
// Templated function definitions go here!
// ***************************************

template <class T>
void Heap<T>::insert(const T& object) {
    // TODO insert for vector/array based heap
}

template <class T>
T Heap<T>::readTop() const {
    if (_heap.size()) {
        return _heap[0];
    }
    throw range_error("Error: readTop() called on empty heap");
}

template <class T>
void Heap<T>::removeTop() {
    
}

template <class T>
int Heap<T>::findNext() const {
    
}

#endif
