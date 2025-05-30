
// Nom i cognom: Karim Boujana Marcucci. Grup: F.
#ifndef LINKEDHASHENTRY_H
#define LINKEDHASHENTRY_H

#include <vector>
#include <string>
#include <iostream>
using namespace std;

template <class Key, class Value>
class LinkedHashEntry {

    private:
        Key key;
        vector<Value> values;
        LinkedHashEntry* next;

    public:

    //Sea n la cantidad de nodos enlazados uno tras otro.
        LinkedHashEntry(Key key); // O(1)
        ~LinkedHashEntry(); //O(n)
        Key getKey(); // O(1)
        vector<Value>& getValue(); // O(1)
        void setValue(const Value& value); // O(1)
        LinkedHashEntry *getNext(); // O(1)
        void setNext(LinkedHashEntry *next); // O(1)
        void toString() const; // O(1)

};

template <class Key, class Value>
LinkedHashEntry<Key, Value>::LinkedHashEntry (Key key) {
    this->key = key;
    next = nullptr;
}

template <class Key, class Value>
LinkedHashEntry<Key, Value>::~LinkedHashEntry() {

    //Vamos eliminando recusrivamente. Como es una lista en una sola dirección, basta con eliminar hacia adelante.
    if (getNext() != nullptr) delete getNext();

}

template <class Key, class Value>
Key LinkedHashEntry<Key, Value>::getKey() {
    return key;
}

template <class Key, class Value>
vector<Value>& LinkedHashEntry<Key, Value>::getValue() {
    return values;
}

template <class Key, class Value>
void LinkedHashEntry<Key, Value>::setValue(const Value &value) {

    // Se llama setValue pero actúa como add.
    this->values.push_back(value);

}

template <class Key, class Value>
LinkedHashEntry<Key, Value>* LinkedHashEntry<Key, Value>::getNext() {
    return next;
}

template <class Key, class Value>
void LinkedHashEntry<Key, Value>::setNext(LinkedHashEntry<Key, Value>* next) {
    this->next = next;
}

template <class Key, class Value>
void LinkedHashEntry<Key, Value>::toString() const {
    //toString de toda la vida, vamos.
    cout << "Key: " << key << ". Value: ";
    for (int i = 0; i < values.size(); i++) {
        if (i == values.size()-1) cout << values.at(i);
        else cout << values.at(i) << ", ";
    }
    cout << "\n";
}

#endif