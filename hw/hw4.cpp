/**
 * File:        hw4.cpp
 * Author:      Kevin Yau
 * Date:        11/16/20
 * Info:        https://docs.google.com/document/d/1r1wn0NLdOiFvIED3-slxySKdBbnxxm2H4D_1xzYEmoI/edit
 */

#include <iostream>

using namespace std;

class HashTable;

typedef int (*hashFn)(int);  // for clarity's sake

class Bucket {
public:
    Bucket(int key, int value) : key(key), value(value) {
        valid = true;
    }
    Bucket() : key(0), value(0) {}

private:
    friend HashTable;
    bool valid = false;  // set to false if no data stored here, true otherwise
    int key;
    int value;
};

class HashTable {
public:
    HashTable(int (*hash)(int), int (*collisionHash)(int)) :
        _hash(hash), _collisionHash(collisionHash) {
        // add code here
        size = 0;
        capacity = 11;
        array = new Bucket[capacity]{ Bucket() };
    }

    ~HashTable() { delete[] array; }

    void rehash() {
        int newCapacity = capacity * 2;
        Bucket* newArray = new Bucket[newCapacity]{ Bucket() };
        for (int i = 0; i < capacity; ++i) {
            if (array[i].valid) {   // existing bucket is found
                Bucket curr = array[i]; 
                int idx = _hash(curr.key);
                int j = 0;

                // repeat put steps with newCapacity
                // buckets need to be deep copied
                if (newArray[idx % newCapacity].valid) {
                    int cIdx = _collisionHash(curr.key);
                    while (newArray[(idx + j * cIdx) % newCapacity].valid) {
                        ++j;
                    }
                    newArray[(idx + j * cIdx) % newCapacity] = Bucket(curr.key, curr.value);
                }
                else {
                    newArray[idx % newCapacity] = Bucket(curr.key, curr.value);
                }
            }
        }
        delete[] array; // remove all old array data
        array = newArray;   // assign member array to the newArray
        capacity = newCapacity; // don't forget to assign the newCapacity like I did
    }

    void put(int key, int value) {
        Bucket bucket(key, value);
        int idx = _hash(key),
            i = 0;  // (H(key) + i * H2(key)), H first hash, H2 2nd hash
        if (array[idx % capacity].valid) {  // collision occurred, need 2nd hash
            int collisionIdx = _collisionHash(key);
            // collisions continue to happen, make it stop
            while (array[(idx + i * collisionIdx) % capacity].valid) {
                ++i;
            }
            array[(idx + i * collisionIdx) % capacity] = bucket;
        } else {
            array[idx % capacity] = bucket;
        }
        ++size;
        // check load factor if it exceeds 0.6
        double lambda = static_cast<double>(size) / capacity;
        if (lambda > MAX_LOAD_FACTOR) {
            rehash();
        }
    }

    int get(int key) {
        for (int i = 0; i < capacity; ++i) {
            // has to be a valid bucket
            if (array[i].valid && array[i].key == key) {
                return array[i].value;
            }
        }
        throw domain_error("Oops"); // throw exception if key not found
    }

private:
    // load factor = (size / capacity), if load factor > 0.6 -> call rehash()
    const double MAX_LOAD_FACTOR = 0.6;
    int size;   // tracks the current number of elements in hashtable
    hashFn _hash;   // store first hash function
    hashFn _collisionHash;  // store second hash function
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
