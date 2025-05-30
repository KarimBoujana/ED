// Nom i cognom: Karim Boujana Marcucci. Grup: F.

#ifndef HASHMAP_H
#define HASHMAP_H

#include <vector>
#include <iostream>
#include "LinkedHashEntry.h"
using namespace std;

template <class Key, class Value>
class HashMap {

    public:

        const static int MAX_TABLE = 32957; // Uso los primos : 21997, 11003, 16477, 32957 para las búsquedas con sus porcentajes. Son todos primos.
        HashMap(); // O(1) temporal, O(MAX_TABLE) espacial.
        virtual ~HashMap(); //O(MAX_TABLE*ki) con ki la cantidad de directores distintos asociados a un índice i.
        int getHashCode (int key) const; // O(1)
        void put(const Key& key, const Value& value); // Sea k la cantidad de directores distintos asociados a 
                                                      // un índice particular. O(k+1)
        void print(); // O(MAX_TABLE)
        const bool get(const Key& key) const; // O(1)
        int size() const; // O(1)
        int cells() const; // O(1)
        int collisions() const; // O(1)
        LinkedHashEntry <Key,Value>* getPosition(const Key& element); // O(1)
        LinkedHashEntry<Key,Value>* getCell(int index) const; // O(1)
        

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
    for (LinkedHashEntry<Key,Value>* elem : arrayElems) delete elem; //Como se eliminan recursivamente, con borrar el primero mata la lista.
}


template <class Key, class Value>
void HashMap<Key, Value>::put(const Key &key, const Value &value) {

    //Calculamos su hash, es decir, su posición.
    int position = getHashCode(key);

    //Creamos el nuevo elemento.
    LinkedHashEntry<Key, Value>* new_element = new LinkedHashEntry<Key, Value>(key);
    new_element->setValue(value); //Añadimos el valor.
    mida++; //Actualizamos la cantidad de elementos en la tabla.

    //Si no hay colisión, añadimos libremente.
    if (arrayElems[position] == nullptr) {
        arrayElems[position] = new_element;
        celles++;
        colisioMax = max(0, colisioMax);
    }
    
    // Si hay colision, hacemos que el último de la lista apunte a nuestro nuevo elemento si las llaves son distintas.
    else {

        LinkedHashEntry<Key, Value>* aux = arrayElems[position];
        LinkedHashEntry<Key, Value>* prev = aux;
        int entries_depth = 0;
        bool found = false;
        
        // Busacmos si alguna clave es igual. Si lo son, básicamente termina el código.
        // Añadimos el valor y hemos acabado.
        while (aux != nullptr && !found) {
            
            prev = aux;

            if (aux->getKey() == key) {
                aux->setValue(value);
                found = true;
            }
            
            entries_depth++;
            aux = aux->getNext();
            
        }
        
        // Si no, actualizamos colisión máxima y añadimos el LinkedHashEntry hecho arriba.
        if (!found) {
            colisioMax = max(entries_depth, colisioMax);
            prev->setNext(new_element);
        }

        
        
    }
    
}

template <class Key, class Value>
void HashMap<Key, Value>::print() {
    
    for (int i = 0; i < MAX_TABLE; i++) {

        if (arrayElems[i] == nullptr) cout << i << ". Vacío." << endl;

        else { //Si hay elementos, vamos a cada LinkedHashEntry, y lo toStringeamos.
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
    //Si no lo encontramos, false.
    if (arrayElems[position] == nullptr) return false;
    else {
        //Si la posición del array tiene elementos, buscamos la llave que queremos.
        LinkedHashEntry<Key, Value>* aux = arrayElems[position];
        while (aux != nullptr) {
            aux = aux->getNext();
            //Si la encontramos, la printeamos y retornamos true.
            if (aux->getKey() == key) {
                aux->toString();
                return true;
            }
        } 
    }
    // Si no, tiramos excepcion.
    throw runtime_error("No trobat.");
}

template <class Key, class Value>
int HashMap<Key, Value>::size() const {
    return mida;
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
    return (key % MAX_TABLE + MAX_TABLE) % MAX_TABLE; //Con esto nos aseguramos que es le menor entero positivo.
}

template <class Key, class Value>
LinkedHashEntry <Key,Value>* HashMap<Key, Value>::getPosition(const Key& element) {

    int position = getHashCode(element);
    if (arrayElems[position] == nullptr) return nullptr;
    
    LinkedHashEntry<Key, Value>* aux = arrayElems[position];

    //Misma logica que el anterior.
    while (aux != nullptr) {
        if (aux->getKey() == element) return aux;
        aux = aux->getNext();
    }

    throw runtime_error("Id no encontrada en el HashMap.");

}

template <class Key, class Value>
LinkedHashEntry<Key,Value>* HashMap<Key, Value>::getCell(int index) const {
    if (arrayElems[index] == nullptr) throw runtime_error("Índice vacío.");
    return arrayElems[index];
}

#endif