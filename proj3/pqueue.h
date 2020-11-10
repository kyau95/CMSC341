// CMSC 341 - Fall 2020 - Project 3
// PQueue: an ER triage queue using a skew heap and function pointers

#ifndef _PQUEUE_H
#define _PQUEUE_H
#include <exception>
#include <iostream>
#include <string>
using namespace std;

class Grader;  // forward declaration (for grading purposes)
class PQueue;//forward declaration
// Triage parameters, min and max values
const int MINTR = 1;
const int MAXTR = 5;
const int MINTEMP = 30;
const int MAXTEMP = 42;
const int MINOX = 70;
const int MAXOX = 101;
const int MINRR = 5;
const int MAXRR = 40;
const int MINHR = 35;
const int MAXHR = 140;
const int MINBP = 70;
const int MAXBP = 160;

//
// patient class
//
class Patient {
public:
    friend class Grader; // for grading purposes
     // Default constructor
    Patient() {
        _patient = ""; _triage = 5; _temperature = 37; _oxygen = 100;
        _RR = 20; _HR = 70; _BP = 100;
    }

    // Alternative constructor
    Patient(string name, int triage, int temp, int ox, int rr, int hr, int bp) {
        if ((triage < MINTR || triage > MAXTR) || (temp < MINTEMP || temp > MAXTEMP) ||
            (ox < MINOX || ox > MAXOX) || (rr < MINRR || rr > MAXRR) || (hr < MINHR ||
            hr > MAXHR) || (bp < MINBP || bp > MAXBP))
            throw out_of_range("Bad value to Patient constructor.");

        _patient = name; _triage = triage; _temperature = temp; _oxygen = ox;
        _RR = rr; _HR = hr; _BP = bp;
    }

    string getPatient() const { return _patient; }
    int getTriage() const { return _triage; }
    int getTemperature() const { return _temperature; }
    int getOxygen() const { return _oxygen; }
    int getRR() const { return _RR; }
    int getHR() const { return _HR; }
    int getBP() const { return _BP; }

private:
    string _patient;
    int _triage; // 1-5, this is assigned by health technician or nurse
    int _temperature; // body temperature, celsius
    int _oxygen; // level of oxygen saturation (SpO2), percentage
    int _RR; // Respiratory Rate, per minute
    int _HR; // Heart Rate, per minute
    int _BP; // Blood Pressure
};

class Node {
public:
    friend class Grader; // for grading purposes
    friend class PQueue;
    Node(Patient patient) {
        _patient = patient;
        _right = nullptr;
        _left = nullptr;
    }
    Patient getPatient() const { return _patient; }

private:
    Patient _patient;   // patient information
    Node *_right;       // right child
    Node *_left;        // left child
};

// Overloaded insertion operators for Patient and Node
ostream& operator<<(ostream& sout, const Patient& patient);
ostream& operator<<(ostream& sout, const Node& node);

// Priority function pointer type
typedef int (*prifn_t)(const Patient&);  

class PQueue {
public:
    friend class Grader; // for grading purposes
  
    // Constructor.  Create a queue with given priority function.
    PQueue(prifn_t priFn);
    
    // Destructor
    ~PQueue();

    // Copy constructor
    PQueue(const PQueue& rhs);

    // Assignment Operator
    PQueue& operator=(const PQueue& rhs);
  
    // Add a patient to the queue
    void insertPatient(const Patient& input);

    // Extract the highest priority patient
    Patient getNextPatient();

    // Merge two queues
    void mergeWithQueue(PQueue& rhs);

    // Remove all patients from the queue
    void clear();
  
    // Return number of patients in queue
    int numPatients() const;
  
    // Print the queue using preorder traversal.  Although the first patient
    // printed should have the highest priority, the remaining patients will
    // not necessarily be in priority order.
    void printPatientQueue() const;

    // Get the current priority function.
    prifn_t getPriorityFn() const;

    // Set a new priority function. Must rebuild the heap!!!
    void setPriorityFn(prifn_t priFn);
  
    // Dump the heap.  For debugging purposes.
    void dump() const;

private:
    Node *_heap;       // Pointer to root of skew heap
    int _size;         // Current size of the heap
  
    // Function pointer; function to compute priority
    prifn_t priority;

    /******************************************
    * Private function declarations go here! *
    ******************************************/

   // Auxillary function for public clean()
    void clearAux(Node* node); 

    // Auxillary merge function to combine two heaps
    Node* mergeAux(Node* heap1, Node* heap2);

    // Helper function for public dump()
    void inorder(Node* node) const;

    // Helper for public printPatientQueue()
    void printPatientAux(Node* node) const; 

    // Helper function for copying heap 
    Node* copyHeap(Node* node);
};
#endif // _PQUEUE_H
