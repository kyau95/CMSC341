/**
 * File:        hw4.cpp
 * Author:      Kevin Yau
 * Date:        11/16/20
 * Info:        https://docs.google.com/document/d/1r1wn0NLdOiFvIED3-slxySKdBbnxxm2H4D_1xzYEmoI/edit
 */

#include <iostream>

using namespace std;

class HashTable;

typedef int (*hashFn)(int); // for clarity's sake

class Bucket {
public:
    Bucket(int key, int value) : key(key), value(value) {
        valid = true;
    }
    Bucket() {}
private:
    friend HashTable;
    bool valid = false; // set to false if no data stored here, true otherwise
    int key;
    int value;
};

class HashTable {
public:
    HashTable(int (*hash)(int), int (*collisionHash)(int))
        : hash(hash), collisionHash(collisionHash) {
        // add code here
        capacity = 11;
        array = new Bucket[capacity]{Bucket()};
    }

    void rehash() {
        // implement (For reference: Prof solution is ~15 lines)
    }

    void put(int key, int value) {
        // implement (For reference: Prof solution is ~10 lines)
        int index = hash(key);
        if (array[index].valid == false) { // make sure that the space is free
            array[index] = Bucket(key, value);
        }
    }

    int get(int key) {
        // implement (For reference: Prof solution is ~5 lines)

        return key;
    }

private:
    hashFn hash;
    hashFn collisionHash;
    int capacity;
    Bucket* array;
};

int mad(int key) {
    return key * 1234 + 4321;
}

int mad2(int key) {
    return key * 2345 + 4567;
}

int main() {
    HashTable table(&mad, &mad2);
    for (int i = 0; i < 1000; ++i) {
        table.put(i * 11, 1000-i);
    }
    cout << table.get(450 * 11) << endl;    // prints 550
}
