#include <chrono>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <random>

#include "pqueue.h"

using namespace std;
using namespace chrono;

int priorityFn1(const Patient& patient);
int priorityFn2(const Patient& patient);

// Tests inserting many patients into the queue
// and then clearing, making sure the heap is empty
void testClearEmptiesPQueue();

// Tests catching a domain error when attempting to
// call getNextPatient on an empty PQueue
void testGetNextPatientEmptyPQueue();

// Test merging with another PQueue and it leaves rhs empty
void testMergeWithQueueRhsEmpty();

// Test self-merging, will throw domain error
void testMergeWithQueueSelf();

// Tests merging with two PQueues of different priorityFns
// will throw domain error
void testMergeWithQueueDifferentPriorityFns();

// Tests getNextPatient will properly update the size of the heap
void testNumPatientsUpdated();

// Tests the copy constructor and if they have different node references
void testCopyConstructor();

// Tests if the program does not crash when doing setPriorityFn
void testSetPriority();

// Tests the insertion execution time
// Testing for O(logn) time
void testExecutionTime();
void insert(int x);



// GLOBALS FOR TESTING
// Ranges based on pqueue.h min const mins and maxes
mt19937 rgen(random_device{}());
uniform_int_distribution<int> TR_DIST(1, 5);
uniform_int_distribution<int> TEMP_DIST(30, 42);
uniform_int_distribution<int> OX_DIST(70, 101);
uniform_int_distribution<int> RR_DIST(5, 40);
uniform_int_distribution<int> HR_DIST(35, 140);
uniform_int_distribution<int> BP_DIST(70, 160);

int main() {
    testClearEmptiesPQueue();
    testGetNextPatientEmptyPQueue();
    testMergeWithQueueRhsEmpty();
    testMergeWithQueueSelf();
    testNumPatientsUpdated();
    testCopyConstructor();
    testSetPriority();
    testExecutionTime();
    return 0;
}

int priorityFn1(const Patient& patient) {
    int pri = 5;
    if ((patient.getOxygen() < 80 && (patient.getRR() > 35 || patient.getRR() < 8)) ||
        (patient.getHR() > 130 && patient.getBP() < 80))
        pri = 1;
    else if (((patient.getOxygen() >= 80 && patient.getOxygen() <= 89) &&
              (patient.getRR() >= 31 && patient.getRR() <= 35)) ||
             (patient.getTemperature() >= 40 || patient.getTemperature() <= 32))
        pri = 2;
    else if ((patient.getOxygen() >= 90 && patient.getOxygen() <= 94) &&
             (patient.getRR() >= 26 && patient.getRR() <= 30))
        pri = 3;
    else if ((patient.getOxygen() >= 95 && patient.getOxygen() <= 97) &&
             (patient.getRR() >= 21 && patient.getRR() <= 25))
        pri = 4;
    else
        pri = 5;
    return pri;
}

int priorityFn2(const Patient& patient) {
    // Priority only based on triage
    // Triage is set by a health care professional
    return patient.getTriage();
}

void testClearEmptiesPQueue() {
    PQueue p(priorityFn1);
    for (int i = 0; i < 10000; ++i) {
        Patient patient;
        p.insertPatient(patient);
    }
    p.clear();
    cout << (p.numPatients() == 0 ? "testClearEmptyPQueue() passed\n" 
        : "testClearEmptyPQueue() failed\n");
}

void testGetNextPatientEmptyPQueue() {
    try {
        PQueue p(priorityFn2);
        Patient temp = p.getNextPatient();
        cout << "testGetNextPatientEmptyPQueue() failed\n";
    }
    catch (domain_error& e) {
        cout << "testGetNextPatientEmptyPQueue() passed\n";
    }
}

void testMergeWithQueueRhsEmpty() {
    PQueue pqueue1(priorityFn2);
    PQueue pqueue2(priorityFn2);
    for (int i = 0; i < 1000; ++i) {
        Patient patient1;
        Patient patient2;
        pqueue1.insertPatient(patient1);
        pqueue2.insertPatient(patient2);
    }
    pqueue1.mergeWithQueue(pqueue2);
    cout << (pqueue2.numPatients() == 0 ? "testMergeWithQueueRhsEmpty() passed\n"
        : "testMergeWithQueueRhsEmpty() failed\n");
}

void testMergeWithQueueSelf() {
    try {
        PQueue p(priorityFn1);
        for (int i = 0; i < 100; ++i) {
            Patient patient;
            p.insertPatient(patient);
        }
        p.mergeWithQueue(p);
        // Didn't throw domain error
        cout << "testMergeWithQueueSelf() failed\n";
    }
    catch (domain_error& e) {
        cout << "testMergeWithQueueSelf() passed\n";
    }
}

void testMergeWithQueueDifferentPriorityFns() {
    try {
        PQueue p(priorityFn1);
        for (int i = 0; i < 5; ++i) {
            Patient patient;
            p.insertPatient(patient);
        }
        PQueue q(priorityFn2);
        p.mergeWithQueue(q);
        cout <<"testMergeWithQueueDifferentPriorityFns() failed\n";
    }
    catch (domain_error& e) {
        cout <<"testMergeWithQueueDifferentPriorityFns() passed\n";
    }
}

void testNumPatientsUpdated() {
    PQueue pqueue(priorityFn2);
    for (int i = 0; i < 100; ++i) {
        Patient patient;
        pqueue.insertPatient(patient);
    }
    pqueue.getNextPatient();
    cout << (pqueue.numPatients() == 99 ? "testNumPatientsUpdated() passed\n" 
        : "testNumPatientsUpdated() failed\n");
}

void testCopyConstructor() {
    PQueue original(priorityFn1);
    
    for (int i = 0; i < 100; ++i) {
        int tr = TR_DIST(rgen);
        int temp = TEMP_DIST(rgen);
        int ox = OX_DIST(rgen);
        int rr = RR_DIST(rgen);
        int hr = HR_DIST(rgen);
        int bp = BP_DIST(rgen);
        Patient test("Tester", tr, temp, ox, rr, hr, bp);
        original.insertPatient(test);
    }
    // Make copy 
    PQueue copy(original);
    // Remove node from original queue, copy should not be affected
    original.getNextPatient();
    Patient orgPatient = original.getNextPatient();
    Patient copyPatient = copy.getNextPatient(); 
    if (&orgPatient != &copyPatient) {
        cout << "testCopyConstructor() passed\n";
    }
    else {
        cout << "testCopyConstructor() failed\n";
    }
}

void testSetPriority() {
    PQueue pqueue(priorityFn1);
    for (int i = 0; i < 100000; ++i) {
        int tr = TR_DIST(rgen);
        int temp = TEMP_DIST(rgen);
        int ox = OX_DIST(rgen);
        int rr = RR_DIST(rgen);
        int hr = HR_DIST(rgen);
        int bp = BP_DIST(rgen);
        Patient test("Tester", tr, temp, ox, rr, hr, bp);
        pqueue.insertPatient(test);
    }
    pqueue.setPriorityFn(priorityFn2);

}

void testExecutionTime() {
    int numPatients[]{ 10000, 20000, 40000, 80000, 160000, 320000, 640000 };
    for (int i = 0; i < 7; ++i) {
        auto start = high_resolution_clock::now();
        insert(numPatients[i]);
        auto stop = high_resolution_clock::now();
        double duration = duration_cast<nanoseconds>(stop - start).count();
        duration *= 1e-9;
        cout << "Test inserting " << numPatients[i] << " patients: "
             << duration << setprecision(9) << " seconds" << endl; 
    }    
}

void insert(int x) {
    PQueue pqueue(priorityFn1);
    for (int i = 0; i < x; ++i) {
        int tr = TR_DIST(rgen);
        int temp = TEMP_DIST(rgen);
        int ox = OX_DIST(rgen);
        int rr = RR_DIST(rgen);
        int hr = HR_DIST(rgen);
        int bp = BP_DIST(rgen);
        Patient test("Tester", tr, temp, ox, rr, hr, bp);
        pqueue.insertPatient(test);
    }
}