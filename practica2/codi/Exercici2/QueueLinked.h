#ifdef QueueLinked_h
#define QueueLinked_h

#include<iostream>
#include "Node.h"

using namespace std;

template<class Type>
class QueueLinked {
    public:
        QueueLinked();
        QueueLinked(const QueueLinked<Type>& q);
        ~QueueLinked();
        bool isEmpty();
        void print();
        void enqueue(const Type key);
        void dequeue();
        const Type getFront();
        void printFrontRear(); 
    
    private:
        Node<Type>* _first;
        Node<Type>* _last;

}

template <class Type>
QueueLinked<Type>::QueueLinked() {

    _first = nullptr;
    _last = nullptr;

}

template <class Type>
QueueLinked<Type>::QueueLinked(const QueueLinked<Type>& q) {

    if (q.isEmpty()) {
        _first = nullptr;
        _last = nullptr;
    } else {
        _first = _last = &q;

        while (_last != nullptr) {
            _last = _last->getNext();

        }
    }

}

template <class Type>
QueueLinked<Type>::~QueueLinked() {

    Node<Type>* aux = _first;
    Node<Type>* aux2 = _first->getNext();

    while (aux2 != nullptr) {
        delete aux;
        aux = aux2;
        aux2 = aux2->getNext();
    }

    delete aux;
    aux = aux2 = _first = _last = nullptr;

}

template <class Type>
bool QueueLinked<Type>::isEmpty() {
    return _first == nullptr;
}

template <class Type>
void QueueLinked<Type>::print() {

    if (this->isEmpty) {
        cout << "Cola vacía." << endl;
    } else {
        Node<Type>* aux = _first;
        cout << "[" << aux->getElement();

        while (aux != nullptr) {
            aux = aux->getNext();
            cout << ", " << aux->getElement();
        }
        
        cout << "]" << endl;
    }

}

template <class Type>
void QueueLinked<Type>::enqueue(const Type key) {

    if (this->isEmpty()) {
        
        Node<Type> node = new Node<Type>(key);
        _first = _last = &node;

    } else {

        Node<Type> nodo = new Node<Type>(key);
        _last->setNext(&nodo);
        _last = &nodo;

    }

    

}

template <class Type>
void QueueLinked<Type>::dequeue() {

    if (this->isEmpty()) {

        throw string("La cola está vacía.")

    } else if (_first->getNext() == nullptr) {

        Node<Type>* aux = _first;
        _first = nullptr;
        _last = nullptr;
        delete aux;
        num_elements--;

    } else {

        Node<Type>* aux = _first->getNext();
        delete _first;
        _first = aux;
        aux = nullptr;
        num_elements--;

    }

}

template <class Type>
Type QueueLinked<Type>::getFront() {
    return _first->getElement(); 
}

template <class Type>
void QueueLinked<Type>::printFrontRear() {
    cout << "Front: " << _first->getElement() << ", rear: " << _last->getElement() << "." << endl;
}

#endif