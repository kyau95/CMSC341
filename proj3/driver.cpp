// CMSC 341 - Fall 2020 - Project 3
// driver.cpp: sample driver for the PQueue class.

#include "pqueue.h"
// Priority functions compute an integer priority for a patient.  Internal
// computations may be floating point, but must return an integer.

int priorityFn1(const Patient &patient);
int priorityFn2(const Patient &patient);

int main() {
    // Create a patient queue with capacity five and priority function
    // priorityFn1()
    
    PQueue queue1(priorityFn1);
    PQueue queue2(priorityFn1);

    // Create some test jobs and insert them into the queue
    //Patient(string name, int triage, int temp, int ox, int rr, int hr, int bp)
    Patient patient1("Sam", 1, 37, 79, 36, 133, 75);
    Patient patient2("Liz", 5, 37, 98, 26, 70, 100);
    Patient patient3("Nick", 2, 37, 85, 34, 125, 85);
    Patient patient4("Eva", 4, 37, 95, 22, 115, 95);
    
    queue1.insertPatient(patient3);
    queue1.insertPatient(patient1);
    queue1.insertPatient(patient2);
    queue1.insertPatient(patient4);
    
    std::cout << "\nqueue1 dump after inserting 4 patients (Nick, Sam, Liz, Eva):" << std::endl;
    queue1.dump();

    Patient patient5("John", 3, 39, 91, 27, 115, 110);
    Patient patient6("Mia", 3, 33, 93, 28, 118, 98);

    queue2.insertPatient(patient5);
    queue2.insertPatient(patient6);
    
    std::cout << "\nqueue2 dump after inserting 2 patients (John, Mia):" << std::endl;
    queue2.dump();
    cout << endl;
    queue1.mergeWithQueue(queue2);

    // Print the queue, change priority function, print again, change
    // again, print again.  Changing the priority function should cause
    // the heap to be rebuilt.

    std::cout << std::endl << "Contents of queue1 after merging with queue2:\n";
    queue1.printPatientQueue();
    // std::cout << "\nDump queue1 after merging with queue2:\n";
    // queue1.dump();

    queue1.setPriorityFn(priorityFn2);
    
    std::cout << std::endl << "Contents of queue1 after changing the priority function to priorityFn2:\n";
    queue1.printPatientQueue();
    cout << "queue1 _size after printPatientQueue(): " << queue1.numPatients() <<endl;
    std::cout << "\nDump queue1 after changing the priority function to priorityFn2:\n";
    queue1.dump();
    cout << "queue1 _size after dump(): " << queue1.numPatients() <<endl;

    queue1.setPriorityFn(priorityFn1);
    
    std::cout << std::endl << "Contents of queue1 after changing the priority function back to priorityFn1:\n";
    queue1.printPatientQueue();
    std::cout << "\nDump queue1 after changing the priority function back to priorityFn1:\n";
    queue1.dump();

    // // Remove and print jobs in priority order
    std::cout << "\nFinal queue1 in priority order:\n";
    while (queue1.numPatients() > 0) {
        Patient patient = queue1.getNextPatient();
        std::cout << "[" << priorityFn1(patient) << "] " << patient << std::endl;
    }
    return 0;
}

int priorityFn1(const Patient &patient) {
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

int priorityFn2(const Patient &patient) {
    // Priority only based on triage
    // Triage is set by a health care professional
    return patient.getTriage(); 
}
