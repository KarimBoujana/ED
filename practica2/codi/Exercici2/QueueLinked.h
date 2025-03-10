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

#endif