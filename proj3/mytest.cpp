#include <iostream>
#include <cassert>
#include "pqueue.h"

using namespace std;

int priorityFn1(const Patient&patient) {
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

int priorityFn2(const Patient&patient) {
    // Priority only based on triage
    // Triage is set by a health care professional
    return patient.getTriage();
}

int main() {
    PQueue p(priorityFn1);

    Patient patient1("Sam", 1, 37, 79,  36, 133, 75);
    Patient patient2("Liz", 5, 37, 98, 26,  70, 100);
    Patient patient3("Nick", 2, 37, 85, 34, 125, 85);
    Patient patient4("Eva", 4, 37, 95,  22, 115, 95);
    
    p.insertPatient(patient3);
    p.insertPatient(patient1);
    p.insertPatient(patient2);
    p.insertPatient(patient4);

    cout << endl;
    p.dump();
    cout << endl;
	return 0;
}
