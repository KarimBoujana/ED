#ifndef Node_h
#define Node_h

using namespace std;

template<class Type>
class Node {
    private:
        Type element;
        Node<Type>* next;

    public:
        Node<Type>(Type element);
        Type getElement();
        Node<Type>* getNext();
        void setNext(const Node<Type>*);

};

template <class Type>
Node<Type>::Node(Type element) {

    this->element = element;
    next = nullptr;

} 

template <class Type>
Type Node<Type>::getElement() {
    return element;
}

template <class Type>
Node<Type>* Node<Type>::getNext() {
    return next;
}

template <class Type>
void Node<Type>::setNext(const Node<Type>* next) {
    this->next = const_cast<Node<Type>*>(next);
}

#endif