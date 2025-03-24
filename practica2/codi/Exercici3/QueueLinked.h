#ifndef QueueLinked_h
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

};

template <class Type>
QueueLinked<Type>::QueueLinked() {

    _first = nullptr;
    _last = nullptr;
    cout << "Estructura creada" << endl;

}

template <class Type>
QueueLinked<Type>::QueueLinked(const QueueLinked<Type>& q) {

    _first = _last = nullptr;

    if (!q.isEmpty()) {

        Node<Type>* current = q._first;

        while(current != nullptr) {

            this->enqueue(current->getElement());
            current = current->getNext(); 
            
        }
        
    }

    cout << "Estructura copiada" << endl;

}

template <class Type>
QueueLinked<Type>::~QueueLinked() {

    if (!this->isEmpty()) {

        Node<Type>* aux = _first;
        Node<Type>* aux2 = _first->getNext();

        while (aux2 != nullptr) {
            delete aux;
            aux = aux2;
            aux2 = aux2->getNext();
        }

        delete aux;
        aux = aux2 = _first = _last = nullptr;
        cout << "Estructura destruida" << endl; 
        
    }

}

template <class Type>
bool QueueLinked<Type>::isEmpty() {
    return _first == nullptr;
}

template <class Type>
void QueueLinked<Type>::print() {

    if (this->isEmpty()) {
        cout << "Pelis: []" << endl;
    } else {
        Node<Type>* aux = _first;
        cout << "Pelis: [" << (aux->getElement()).toString();

        while (aux->getNext() != nullptr) {
            aux = aux->getNext();
            cout << ", " << (aux->getElement()).toString();
        }
        
        cout << "]" << endl;
    }

}

template <class Type>
void QueueLinked<Type>::enqueue(const Type key) {

    if (this->isEmpty()) {
        
        Node<Type>* node = new Node<Type>(key);
        _first = _last = node;
        cout << "Element " << key << " agregat" << endl;

    } else {

        Node<Type>* node = new Node<Type>(key);
        _last->setNext(node);
        _last = node;
        cout << "Element " << key << " agregat" << endl;

    }

}

template <class Type>
void QueueLinked<Type>::dequeue() {

    if (this->isEmpty()) {

        throw string("EXCEPTION: No hi ha pelis.");

    } else if (_first->getNext() == nullptr) {


        Node<Type>* aux = _first;
        _first = nullptr;
        _last = nullptr;

        cout << "Element " << aux->getElement() << " eliminat" << endl;
        delete aux;


    } else {

        Node<Type>* aux = _first->getNext();
        cout << "Element " << _first->getElement() << " eliminat" << endl;
        delete _first;
        _first = aux;
        aux = nullptr;

    }

}

template <class Type>
const Type QueueLinked<Type>::getFront() {
    if (this->isEmpty()) {
        throw string("La cola está vacía.");
    } else {
        return _first->getElement();
    }
}

template <class Type>
void QueueLinked<Type>::printFrontRear() {
    if (this->isEmpty()) {
        throw string("La cola está vacía.");
    } else {
        cout << "Front: " << _first->getElement() << ", rear: " << _last->getElement() << "." << endl;
    }
}

#endif