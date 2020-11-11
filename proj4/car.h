// CMSC 341 - Fall 2020 - Project 4
// car.h
// Simple class for use with Heap and HashTable classes

// To work with Heap and HashTable, a class must provide the
// following:
//  (a) Default constructor
//  (b) priority function (unsigned priority())
//  (c) key function (string key())
//  (d) overloaded insertion operator

#ifndef _CAR_H
#define _CAR_H

#include <iostream>
#include <string>

using std::string;
using std::ostream;
class Car{
    public:

    // Constructor.  Default is a "plain" donut, priority 0, and empty
    // customer string.
    Car(string key = "x", unsigned pri = 0, string dealer = "") {
        _key = key;
        _pri = pri;
        _dealer = dealer;
    }

    // Required.  Returns priority of a car order.
    unsigned priority() const {
        return _pri;
    }

    // Required.  Returns key (car type) of a car order.
    string key() const {
        return _key;
    }

    // Overloaded insertion operator
    friend ostream& operator<<(ostream& sout, const Car &d );
    private:
    string _key;         // car model
    unsigned _pri;       // order priority (dealer performance)
    string _dealer;      // dealer information
};

// Overloaded insertion operator.  Prints car type (key), priority,
// and dealer information.
ostream& operator<<(ostream& sout, const Car &d ) {
  sout << d._key << " (priority " << d._pri << ", "
       << d._dealer << ")";
  return sout;
}
#endif