#include "QueueStatic.h"
#include <iostream>
using namespace std;


QueueStatic::QueueStatic(const int max_size) {
    
    _first = 0;
    _content = new int[max_size];
    _max_elements = max_size;
    
}

void QueueStatic::enqueue(const int key) {

    if (isFull()) {
        //TODO: HACER EXCEPCIÓN.
    }

    _content[_first] = key;
    _first = (_first+1) % _max_elements;

}

void QueueStatic::dequeue() {

    if (isEmpty()) {
        //TODO: HACER EXCEPCIÓN.
    }
    _last = (_last+1) % _max_elements;

}

bool QueueStatic::isEmpty() {

    return (_num_elements == 0) ?  true : false;
    
}

bool QueueStatic::isFull() {

    return (_num_elements == _max_elements) ? true : false;

}

void QueueStatic::print() {

    cout << "[";

    for (int i = _last; i < _num_elements; (i++) %_max_elements) {

        if (i != _num_elements -1) {
            cout << _content[i] << ", ";
        } 
        else {
            cout << _content[i];
        }
    }

    cout << "]";

}

const int QueueStatic::getFront() {
    return _last;
}

void QueueStatic::printFrontRear() {
    cout << "Front: " << _last << ", Rear: " << _first << endl; 
}