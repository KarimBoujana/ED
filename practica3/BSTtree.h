#ifndef BSTTREE_H
#define BSTTREE_H

#include <vector>
#include <list>
#include <iostream>

#include "NODEtree.h"

using namespace std;


template <class Key, class Value>
class BSTtree {

    public:

        BSTtree();
        BSTtree(const BSTtree<Key, Value>& orig);
        virtual ~BSTtree();
        bool empty() const;
        int size() const;
        int height() const;
        NODEtree<Key, Value>* insert(const Key &k, const Value &value);
        const vector<Value>& valuesOf(const Key& k) const;
        void printPreorder(const NODEtree<Key,Value>* n = nullptr) const;
        void printInorder(const NODEtree<Key,Value>* n = nullptr) const;
        void printPostorder(const NODEtree<Key,Value>* n = nullptr) const;
        void printSecondLargestKey() const;
        void mirrorTree();
        list<NODEtree<Key, Value> *> getLeafNodes() const;
        
        protected:
        
        NODEtree<Key,Value>* root;
        NODEtree<Key,Value>* search(const Key& k) const;
        
        private:
        
        int _size;
        /* Mètodes auxiliars definiu aquí els que necessiteu */
        void mirrorTreeR(NODEtree<Key, Value> *n);
        void printSecondLargestKeyR(const NODEtree<Key, Value> *n) const;
        void copiaR(const NODEtree<Key, Value>* n);
        void eliminaR(NODEtree<Key, Value>* n);
        int heightR(const NODEtree<Key, Value>* n) const;
        void getLeafNodesR(const NODEtree<Key, Value> *n, list<NODEtree<Key, Value> *> &lista) const;

};

template <class Key, class Value>
BSTtree<Key, Value>::BSTtree() {
    _size = 0;
}

template <class Key, class Value>
BSTtree<Key, Value>::BSTtree(const BSTtree<Key, Value>& orig) {

    if (!orig.empty()) {
        root = nullptr;
        copiaR(orig.root);
        _size = orig._size; 
    }

}

template <class Key, class Value>
void BSTtree<Key, Value>::copiaR(const NODEtree<Key, Value>* n) {

    if (n != nullptr) {
        insert(n->getKey(), n->getValues());
        copiaR(n->getLeft());
        copiaR(n->getRight());
    }

}

template <class Key, class Value>
BSTtree<Key, Value>::~BSTtree() {
    
    if (!empty()) eliminaR(root);
    root = nullptr;
    _size = 0;

}

template <class Key, class Value>
void BSTtree<Key, Value>::eliminaR(NODEtree<Key, Value>* n) {

    if (n != nullptr) {
        eliminaR(n->getLeft());
        eliminaR(n->getRight());
        delete n;
    }

}

template <class Key, class Value>
bool BSTtree<Key, Value>::empty() const {

    return _size == 0;

}

template <class Key, class Value>
int BSTtree<Key, Value>::size() const {

    return _size;

}

template <class Key, class Value>
int BSTtree<Key, Value>::height() const {

    if (empty()) return -1;
    else return heightR(root);
    
}

template <class Key, class Value>
int BSTtree<Key, Value>::heightR(const NODEtree<Key, Value>* n) const {

    if (n == nullptr || n->isExternal()) return 0;
    else return 1 + max(heightR(n->getRight()), heightR(n->getLeft()));

}

template <class Key, class Value>
NODEtree<Key,Value>* BSTtree<Key, Value>::insert(const Key& k, const Value& value) {

    if (empty()) {
        root = new NODEtree<Key, Value>(k);
        root->setValues(value);
        return root;

    } else {

        NODEtree<Key, Value> * aux = root;
        NODEtree<Key, Value> * parent = nullptr;
        while (aux != nullptr && !aux->isExternal()) {

            parent = aux;

            if (aux->getKey() == k) {
                aux->setValues(value);
                return aux;
            }

            if (aux->getKey() > k) aux = aux->getLeft();
            else aux = aux->getRight();
        }


        _size++;
        NODEtree<Key, Value>* new_node = new NODEtree<Key, Value>(k);
        new_node->setValues(value);
        new_node->setParent(parent);

        if (parent->getKey() > k) {
            parent->setLeft(new_node);
        } else {
            parent->setRight(new_node);
        }

        return new_node;
        

    }

}
         
template <class Key, class Value>
const vector<Value>& BSTtree<Key, Value>::valuesOf(const Key& k) const {
    return search(k)->getValues();
}

template <class Key, class Value>
void BSTtree<Key, Value>::printPreorder(const NODEtree<Key,Value>* n) const {
    
    if (empty()) cout << "Arbol vacío." << endl;
    else if (n != nullptr) {

        cout << n->getKey() << ", ";
        if (!n->isExternal()) {
            printPreorder(n->getLeft());
            printPreorder(n->getRight());
        }

    }

}

template <class Key, class Value>
void BSTtree<Key, Value>::printInorder(const NODEtree<Key,Value>* n) const {

    if (empty()) cout << "Arbol vacío." << endl;
    else if (n != nullptr) {

        if (!n->isExternal()) {
            printPreorder(n->getLeft());
        }

        cout << n->getKey() << ", ";

        if (!n->isExternal()) {
            printPreorder(n->getRight());
        }

    }

}

template <class Key, class Value>
void BSTtree<Key, Value>::printPostorder(const NODEtree<Key,Value>* n) const {

    if (empty()) cout << "Arbol vacío." << endl;
    else if (n != nullptr) {

        if (!n->isExternal()) {
            printPreorder(n->getLeft());
            printPreorder(n->getRight());
        }
        cout << n->getKey() << ", ";

    }

}

template <class Key, class Value>
void BSTtree<Key, Value>::printSecondLargestKey() const {

    if (empty()) throw runtime_error("Arbol vacío.");
    else if (_size == 1) throw runtime_error("Solo hay un nodo.");
    else {
        printSecondLargestKeyR(root);
    }

}

template <class Key, class Value>
void BSTtree<Key, Value>::printSecondLargestKeyR(const NODEtree<Key,Value>* n) const {
    
    if (n == nullptr) throw runtime_error("Puntero nulo");
    if (n->hasRight()) printSecondLargestKeyR(n->getRight()); 
    else {
        // Nuestro caso base es estar en el nodo más a la derecha del árbol, pues este tendrá la key más grande.
        // Si tiene un nodo a la izquierda, será mayor que el padre del más derecho, pues está a la derecha del mismo, pero menor que le nodo.
        // Si no lo tiene, el padre es el segundo mayor. Y como este método se llama tras comprobar que existan al menos dos nodos, entonces siempre habrá un padre.
        if (n->hasLeft()) cout << n->getLeft()->getKey() << endl; 
        else cout << n->getParent()->getKey() << endl;
    }

}

template <class Key, class Value>
void BSTtree<Key, Value>::mirrorTree() {

    mirrorTreeR(root);

}

template <class Key, class Value>
void BSTtree<Key, Value>::mirrorTreeR(NODEtree<Key,Value>* n) {

    if(n != nullptr && !n->isExternal()) {
        NODEtree<Key,Value>* temp = n->getLeft();
        n->setLeft(n->getRight());
        n->setRight(temp);
        temp = nullptr;

        mirrorTreeR(n->getLeft());
        mirrorTreeR(n->getRight());

    }
    
}

template <class Key, class Value>
list<NODEtree<Key, Value>*> BSTtree<Key, Value>::getLeafNodes() const {

    list<NODEtree<Key, Value>*> new_list = new list<NODEtree<Key, Value>*>();
    getLeafNodesR(root, new_list);
    return new_list;

}

template <class Key, class Value>
void BSTtree<Key, Value>::getLeafNodesR(const NODEtree<Key,Value>* n, list<NODEtree<Key, Value>*>& lista) const {

    if (n != nullptr) {

        getLeafNodesInOrderR(n->getLeft(), lista);  
        if (n->isExternal()) lista.push_back(n);  
        getLeafNodesInOrderR(n->getRight(), lista);

    }

}

template <class Key, class Value>
NODEtree<Key, Value>* BSTtree<Key, Value>::search(const Key &k) const {

    if (empty()) throw runtime_error("Árbol vacío.");
    else {

        NODEtree<Key, Value>* aux = root;

        while (aux != nullptr) {

            if (aux->getKey() > k) aux = aux->getLeft();
            else if (aux->getKey() < k) aux = aux->getRight();
            else return aux;

        }

        throw runtime_error("No encontrado.");

    }
    
}


#endif