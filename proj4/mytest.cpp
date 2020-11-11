#include <chrono>
#include <ctime>
#include <exception>
#include <iostream>

#include "car.h"
#include "hash.h"

unsigned cyclic_hash16(string key) {
    unsigned usize = 16;
    unsigned s = 5;  // shift by 5
    unsigned h = 0;
    for (int i = 0; i < key.length(); i++) {
        h = ((h << s) | (h >> (usize - s)));
        h += key[i];
        h = h & 0xffff;
    }
    return h;
}

int main() {
    cout << "Hello World!\n";
}