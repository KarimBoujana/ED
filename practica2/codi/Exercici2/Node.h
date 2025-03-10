#ifdef Node_h
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
        void setNext(const Node<Type>*)

}

template <class Type>
C

#endif