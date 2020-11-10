#include <cassert>
#include <ctime>
#include <iostream>
#include <random>

#include "pqueue.h"

using namespace std;

int priorityFn1(const Patient& patient);
int priorityFn2(const Patient& patient);

// Tests inserting many patients into the queue
// and then clearing, making sure the heap is empty
void testClearEmptiesPQueue();

// Tests catching a domain error when attempting to
// call getNextPatient on an empty PQueue
void testGetNextPatientEmptyPQueue();

// 
void testGetNextPatientCorrectMin();
void testMergeWithQueueRhsEmpty();
void testMergeWithQueueSelf();
void testMergeWithQueueDifferentPriorityFns();
void testNumPatientsUpdated();
void testCopyConstructor();
void testSelfAssignment();
void testSetPriority();
void testInsertion();

// GLOBALS FOR TESTING
// Ranges based on pqueue.h min const mins and maxes
random_device device;
mt19937 rgen(device());
uniform_int_distribution<int> TR_DIST(1, 5);
uniform_int_distribution<int> TEMP_DIST(30, 42);
uniform_int_distribution<int> OX_DIST(70, 101);
uniform_int_distribution<int> RR_DIST(1, 5);
uniform_int_distribution<int> HR_DIST(35, 140);
uniform_int_distribution<int> BP_DIST(70, 160);

int main() {
    testClearEmptiesPQueue();
    testGetNextPatientEmptyPQueue();
    testGetNextPatientCorrectMin();
    testMergeWithQueueRhsEmpty();
    testMergeWithQueueSelf();
    testNumPatientsUpdated();
    testCopyConstructor();
    testSelfAssignment();
    testSetPriority();
    testInsertion();
    
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

void testGetNextPatientCorrectMin() {

}

void testMergeWithQueueRhsEmpty() {

}

void testMergeWithQueueSelf() {
    try {
        PQueue p(priorityFn1);
        PQueue q(priorityFn1);
    }
    catch (domain_error& e) {

    }
}

void testMergeWithQueueDifferentPriorityFns() {
    try {
        PQueue p(priorityFn1);
        PQueue q(priorityFn2);
    }
    catch (domain_error& e) {

    }
}

void testNumPatientsUpdated() {

}

void testCopyConstructor() {

}

void testSelfAssignment() {

}

void testSetPriority() {

}

void testInsertion() {

}