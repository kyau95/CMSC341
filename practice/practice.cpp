/**
 * File:        practice.cpp
 * Info:        CPP file for practicing certain concepts, subject to constant
 *              changes.
 */

#include <exception>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class HashTable;

class Bucket {
public:
    Bucket() {
        key = 0;
        value = "";
    }

    Bucket(int key, const string& value)
        : key(key), value(value) {
        }
private:
    friend HashTable;
    int key;
    string value;
    bool used;
};

class HashTable {
public:
    HashTable(int capacity)
        : capacity(capacity) {
        size = 0;
        buckets = new vector<Bucket>[capacity];
    }
    int hash(int key) {
        return (key * 1089 * 1697) % 2147483647;
    }

    void put(int key, string value) {
        // TODO
        Bucket bucket(key, value);
        int index = hash(key) % capacity;
        buckets[index].push_back(bucket);
        ++size;
        // REHASHING PART
        if (size / capacity > 0.9) {
            vector<Bucket>* anotherBucket = new vector<Bucket>[capacity * 2];
            for (int i = 0; i < buckets[index].size(); ++i) {
                anotherBucket[i] = vector<Bucket>(buckets[i]);
            }
        }
    }

    string get(int key) {
        int index = hash(key) % capacity;
        for (int i = 0; i < buckets[index].size(); ++i) {
            if (buckets[index][i].key == key) {
                return buckets[index][i].value;
            }
        }
        throw domain_error("Oopsie Daisy");
    }

private:
    int size;
    int capacity;
    vector<Bucket>* buckets;
};

int main() {
    HashTable ht(50);
    ht.put(74, "Something Something");
    ht.put(42, "Dudes and dudettes");
    ht.put(1014, "Allllllrighty then....");
    ht.put(24, "This isn't right?!?!?");
    int keys[]{ 74, 42, 1014, 24 };
    for (int i = 0; i < 4; ++i) {
        cout << "At key " << keys[i] << " the value is: " << ht.get(keys[i]) << endl;
    }
    // int m = 3, n = 5, sum = 0;
    // for (int i = 0; i <= n - m; ++i) {
    //     sum += 1;
    // }
    // cout << sum << endl;
    return 0;
}
