 // CMSC 341 - Fall 2020 - Project 3
// PQueue: an ER triage queue using a skew heap and function pointers

#include "pqueue.h"

PQueue::PQueue(prifn_t priFn) {
    _heap = nullptr;
    _size = 0;
    priority = priFn;
}

PQueue::~PQueue() { 
    clear(); 
}

PQueue::PQueue(const PQueue& rhs) {
    _heap = nullptr;
    _size = 0;
    priority = nullptr;
    *this = rhs;
}

PQueue& PQueue::operator=(const PQueue& rhs) {
    // Self-assignment check
    if (this == &rhs) { 
        return *this;
    }
    clear();

    // TODO deep copy the tree
    return *this;
}

void PQueue::insertPatient(const Patient& input) {
    if (_heap) {
        Node *newNode = new Node(input);
        _heap = mergeAux(_heap, newNode);
    }
    else {
        _heap = new Node(input);
    }
    ++_size;
}

Node* PQueue::mergeAux(Node* heap1, Node* heap2) {
    Node* temp;
    if (heap1 == nullptr) {
        return heap2;
    }
    if (heap2 == nullptr) {
        return heap1;
    }
    // Calculate the key values
    int priority1 = priority(heap1->_patient);
    int priority2 = priority(heap2->_patient);
    if (priority1 > priority2) { // Make sure heap1 has the smallest priority
        temp = heap1;
        heap1 = heap2;
        heap2 = temp;
    }
    if (heap1->_right == nullptr) { // tack on heap2
        heap1->_right = heap2;
    }
    else { // recursively tack on heap2
        heap1->_right = mergeAux(heap1->_right, heap2);
    }
    temp = heap1->_right;
    heap1->_right = heap1->_left;
    heap1->_left = temp;
    return heap1;
}

Patient PQueue::getNextPatient() {
    if (_size == 0) { throw domain_error("Error: PQueue is empty\n"); }
    // Set a temporary pointer to the current root
    // Merge the left and right subtrees of the heap
    Node* temp = _heap;
    --_size;
    _heap = mergeAux(_heap->_left, _heap->_right);
    return temp->_patient;
}

void PQueue::mergeWithQueue(PQueue& rhs) {
    if (priority != rhs.priority) {
        throw domain_error("Error: Priority functions do not match");
    }
    // TODO fix memory leak, double freeing since rhs nodes are still being
    // pointed to in the
    _heap = mergeAux(_heap, rhs._heap);
    _size += rhs._size;
}

void PQueue::clear() {
    if (_heap) // clear the queue, leave skew heap empty
        clear(_heap);
    _size = 0;
}

void PQueue::clear(Node *node) {
    // Delete in postorder, deletes children before the parent
    if (node) {
        clear(node->_left);
        clear(node->_right);
        delete node;
    }
}

int PQueue::numPatients() const { 
    return _size; 
}

void PQueue::printPatientQueue() const {
    // TODO reference sample output for print format

}

prifn_t PQueue::getPriorityFn() const { 
    return priority; 
}

void PQueue::setPriorityFn(prifn_t priFn) {
    priority = priFn;
    // TODO rebuild the heap afterwards

}

void PQueue::dump() const {
    if (_heap)
        inorder(_heap);
}

void PQueue::inorder(Node *node) const {
    if (node) {
        cout << "(";
        inorder(node->_left);
        cout << priority(node->_patient) << ":" << node->_patient.getPatient();
        inorder(node->_right);
        cout << ")";
    }
}

// ========================= NO TOUCHY =========================
ostream& operator<<(ostream& sout, const Patient& patient) {
    sout << "Patient: " << patient.getPatient() << ", triage: " << patient.getTriage()
         << ", temperature: " << patient.getTemperature() << ", oxygen: " << patient.getOxygen() << ", RR: "
         << patient.getRR() << ", HR: " << patient.getHR() << ", BP: " << patient.getBP();
    return sout;
}

ostream& operator<<(ostream& sout, const Node& node) {
    sout << node.getPatient();
    return sout;
}
