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
        void printFrontRear(); // imprimir valores del front y el rear
    
    private:
        Node<Type>* _first;
        Node<Type>* _last;

}

template <class Type>
QueueLinked<Type>::QueueLinked() {

    Node<Type>* _first = Node<Type>* _last = new Node<Type>();

}

template <class Type>
void QueueLinked<Type>::enqueue(const Type key) {

    Node<Type> nodo = new Node<Type>();
    _last*.setNext(&nodo);
    _last = &nodo;

}

template <class Type>
void QueueLinked<Type>::dequeue() {

    Node<Type> nodo = new Node<Type>();
    _last*.setNext(&nodo);
    _last = &nodo;

}

#endif