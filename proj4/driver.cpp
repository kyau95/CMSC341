#include <iostream>
#include "hash.h"
#include "car.h"

// Prototype for 16 bit cyclic hash function; implementation is after
// main().
unsigned cyclic_hash16(string key);

int main() {

  // Create a vector of cars to insert in the hash table
  vector<Car> cars;
  cars.push_back(Car("x101", 5, "super car"));
  cars.push_back(Car("x101", 12, "mega car"));
  cars.push_back(Car("x101", 4, "shack of cars"));
  cars.push_back(Car("challenger", 10, "mega car"));
  cars.push_back(Car("challenger", 5, "car world"));
  cars.push_back(Car("stratos", 7, "car world"));
  cars.push_back(Car("stratos", 15, "super car"));
  cars.push_back(Car("stratos", 8, "shack of cars"));
  cars.push_back(Car("challenger", 3, "car joint"));
  cars.push_back(Car("gt500", 3, "shack of cars"));
  cars.push_back(Car("miura", 28, "mega car"));
  cars.push_back(Car("gt500", 11, "super car"));

  // Create the hash table of length 10 using cyclic_hash function
  HashTable<Car> ht(10, cyclic_hash16);

  vector<Car>::iterator itCar;
  for (itCar=cars.begin();itCar!=cars.end();itCar++)
    ht.insert(*itCar);

  cout << "\nDump of ht:\n";
  ht.dump();

  // Extract some orders
  
  Car d;
  vector<string> orders;

  orders.push_back("challenger");
  orders.push_back("miura");
  orders.push_back("gt500");
  orders.push_back("gt500");
  orders.push_back("gt500");

  vector<string>::iterator itString;

    for ( itString=orders.begin();itString!=orders.end();itString++ ) {
    cout << "\nGet next '" << *itString << "' order...\n";
    if ( ht.getNext(*itString, d) ) {
      cout << "  " << d << endl;
    } else {
      cout << "  No " << *itString << " orders!\n";
    }
  }

  cout << endl;

  cout << "\nDump of ht:\n";
  ht.dump();

  // Simple test of copy constructor; also need to test assignment
  // operator!
  cout << "\nCreate copy of hash table, remove two 'stratos' orders, dump both tables...\n";

  HashTable<Car> ht2(ht);

  ht2.getNext("stratos", d);
  ht2.getNext("stratos", d);

  cout << "\nDump of ht:\n";
  ht.dump();

  cout << "\nDump of ht2:\n";
  ht2.dump();
  
  return 0;
}

unsigned cyclic_hash16(string key) {
  unsigned usize = 16;
  unsigned s = 5; // shift by 5
  unsigned h = 0;
  for ( int i = 0; i < key.length(); i++ ){
    h = (( h << s ) | ( h >> (usize - s) ));
    h += key[i];
    h = h & 0xffff;
  }
  return h;
}

