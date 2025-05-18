#ifndef HASHMAP_H
#define HASHMAP_H

#include <vector>
#include <iostream>
#include "LinkedHashEntry.h"
using namespace std;

template <class Key, class Value>
class HashMap {

    public:

        const static int MAX_TABLE = 7; // Definir a ?? el valor que necessiteu
        HashMap();
        virtual ~HashMap();
        int getHashCode (int key) const;
        void put(const Key& key, const Value& value);
        void print();
        const bool get(const Key& key) const;
        int size() const;
        int cells() const;
        int collisions() const;
        LinkedHashEntry <Key,Value>* getPosition(const Key& element);
        LinkedHashEntry<Key,Value>* getCell(int index) const;

    private:

        LinkedHashEntry<Key,Value>* arrayElems[MAX_TABLE] = {}; // taula de hash
        int mida; // Nombre d’elements dins del HashMap
        int celles; // Nombre de cel·les ocupades del HashMap
        int colisioMax; // Profunditat màxima d’una cel·la a tot el HashMap
};

template <class Key, class Value>
HashMap<Key, Value>::HashMap() {
    LinkedHashEntry<Key,Value>* arrayElems[MAX_TABLE] = {};
    mida = celles = colisioMax = 0;
}

template <class Key, class Value>
HashMap<Key, Value>::~HashMap() {
    mida = celles = colisioMax = 0;
    for (LinkedHashEntry<Key,Value>* elem : arrayElems) delete elem;
}


template <class Key, class Value>
void HashMap<Key, Value>::put(const Key &key, const Value &value) {

    int position = getHashCode(key);
    LinkedHashEntry<Key, Value>* new_element = new LinkedHashEntry<Key, Value>(key);
    new_element->setValue(value);
    mida++;

    //Si no hay colisión, añadimos libremente.
    if (arrayElems[position] == nullptr) {
        arrayElems[position] = new_element;
        celles++;
        colisioMax = max(0, colisioMax);
    }
    
    // Si hay colision, hacemos que el último de la lista apunte a nuestro nuevo elemento.
    else {

        LinkedHashEntry<Key, Value>* aux = arrayElems[position];
        int entries_depth = 0;
        
        while (aux->getNext() != nullptr) {
            entries_depth++;
            aux = aux->getNext();
        }
        
        aux->setNext(new_element);
        
        colisioMax = max(entries_depth, colisioMax);
        
    }
    
}

template <class Key, class Value>
void HashMap<Key, Value>::print() {
    
    for (int i = 0; i < MAX_TABLE; i++) {

        if (arrayElems[i] == nullptr) cout << i << ". Vacío." << endl;

        else {
            cout << i << ". ";
            LinkedHashEntry<Key, Value>* aux = arrayElems[i];
            while (aux != nullptr) {
                aux->toString();
                aux = aux->getNext();
            }
            cout << endl;
        }

    }

}

template <class Key, class Value>
const bool HashMap<Key, Value>::get(const Key &key) const {
    
    int position = getHashCode(key);
    if (arrayElems[position] == nullptr) return false;
    else {
        LinkedHashEntry<Key, Value>* aux = arrayElems[position];
        while (aux != nullptr) {
            aux->toString();
            aux = aux->getNext();
        } 
        
    }
    return true;
}

template <class Key, class Value>
int HashMap<Key, Value>::size() const {
    return MAX_TABLE;
}

template <class Key, class Value>
int HashMap<Key, Value>::cells() const {
    return celles;
}

template <class Key, class Value>
int HashMap<Key, Value>::collisions() const {
    return colisioMax;
}

template <class Key, class Value>
int HashMap<Key, Value>::getHashCode(int key) const {
    return key % MAX_TABLE;
}

template <class Key, class Value>
LinkedHashEntry <Key,Value>* HashMap<Key, Value>::getPosition(const Key& element) {

    int position = getHashCode(element);
    if (arrayElems[position] == NULL) throw runtime_error("No encontrado.");
    
    LinkedHashEntry<Key, Value>* aux = arrayElems[position];

    while (aux != nullptr) {
        aux->toString();
        if (aux->getKey() == element) return aux;
        aux = aux->getNext();
    }

    throw runtime_error("Para esta posición no hay elementos con esta llave.");

}

template <class Key, class Value>
LinkedHashEntry<Key,Value>* HashMap<Key, Value>::getCell(int index) const {
    if (arrayElems[index] == nullptr) throw runtime_error("Índice vacío.");
    return arrayElems[index];
}

#endif