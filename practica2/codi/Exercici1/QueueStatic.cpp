#include "QueueStatic.h"
#include <iostream>
#include <string>
using namespace std;

/**
 * Constructor de la clase QueueStatic.
 * Inicializa la cola con un tamaño máximo dado.
 * 
 * @param max_size Tamaño máximo de la cola.
 */
QueueStatic::QueueStatic(const int max_size) {
    _first = 0;
    _last = 0;
    _num_elements = 0;
    _content = new int[max_size];
    _max_elements = max_size;
}

/**
 * Destructor de la clase QueueStatic.
 * Libera la memoria reservada para el array de elementos.
 */
QueueStatic::~QueueStatic() {
    delete[] _content;
}

/**
 * Añade un elemento a la cola.
 * 
 * @param key Elemento a añadir.
 * @throws string Si la cola está llena.
 */
void QueueStatic::enqueue(const int key) {
    if (isFull()) {
        throw string("EXCEPTION: L'estructura està plena");
    } else {
        _num_elements++;
        _content[_first] = key;
        _first = (_first + 1) % _max_elements; // Avanza _first de forma circular.
    }
}

/**
 * Elimina un elemento de la cola.
 * 
 * @throws string Si la cola está vacía.
 */
void QueueStatic::dequeue() {
    if (isEmpty()) {
        throw string("EXCEPTION: L'estructura està buida");
    } else {
        _last = (_last + 1) % _max_elements; // Avanza _last de forma circular.
        _num_elements--;
    }
}

/**
 * Comprueba si la cola está vacía.
 * 
 * @return true Si la cola está vacía.
 * @return false Si la cola no está vacía.
 */
bool QueueStatic::isEmpty() {
    return _num_elements == 0;
}

/**
 * Comprueba si la cola está llena.
 * 
 * @return true Si la cola está llena.
 * @return false Si la cola no está llena.
 */
bool QueueStatic::isFull() {
    return _num_elements == _max_elements;
}

/**
 * Imprime los elementos de la cola.
 * Muestra los elementos en formato [elemento1, elemento2, ...].
 */
void QueueStatic::print() {
    cout << "[";

    for (int i = 0; i < _num_elements; i++) {
        if (i != _num_elements - 1) {
            cout << _content[(_last + i) % _max_elements] << ", ";
        } else {
            cout << _content[(_last + i) % _max_elements];
        }
    }

    cout << "]\n";
}

/**
 * Obtiene el elemento en el frente de la cola.
 * 
 * @return const int Elemento en el frente de la cola.
 */
const int QueueStatic::getFront() {
    return _content[_last]; // Devuelve el elemento en el frente de la cola.
}

/**
 * Imprime las posiciones del frente y el final de la cola.
 * Muestra los índices _last (frente) y _first (final).
 */
void QueueStatic::printFrontRear() {
    cout << "Front: " << _last << ", Rear: " << _first << endl;
}