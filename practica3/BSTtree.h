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
        NODEtree<Key,Value>* insert(const Key& k, const Value& value);
        const vector<Value>& valuesOf(const Key& k) const;
        void printPreorder(const NODEtree<Key,Value>* n = nullptr) const;
        void printInorder(const NODEtree<Key,Value>* n = nullptr) const;
        void printPostorder(const NODEtree<Key,Value>* n = nullptr) const;
        void printSecondLargestKey() const;
        void mirrorTree();
        list<NODEtree<Key, Value>*> getLeafNodes() const;

    protected:

        NODEtree<Key,Value>* root;
        NODEtree<Key,Value>* search(const Key& k) const;

    private:

        int _size;
        /* Mètodes auxiliars definiu aquí els que necessiteu */

        list<NODEtree<Key, Value>*> getLeafNodesR(const NODEtree<Key,Value>* n = nullptr) const;
};

template <class Key, class Value>
BSTtree<Key, Value>::BSTtree() {
    _size = 0;
}

template <class Key, class Value>
BSTtree<Key, Value>::BSTtree(const BSTtree<Key, Value>& orig) {

}

template <class Key, class Value>
BSTtree<Key, Value>::~BSTtree() {
    
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

}

template <class Key, class Value>
void BSTtree<Key, Value>::printPreorder(const NODEtree<Key,Value>* n = nullptr) const {
    
    if (n != nullptr) {

        cout << n->getKey() << ", ";
        if (!n->isExternal()) {
            printPreorder(n->getLeft());
            printPreorder(n->getRight());
        }

    }

}

template <class Key, class Value>
void BSTtree<Key, Value>::printInorder(const NODEtree<Key,Value>* n = nullptr) const {

    if (n != nullptr) {

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
void BSTtree<Key, Value>::printPostorder(const NODEtree<Key,Value>* n = nullptr) const {

    if (n != nullptr) {

        if (!n->isExternal()) {
            printPreorder(n->getLeft());
            printPreorder(n->getRight());
        }
        cout << n->getKey() << ", ";

    }

}

template <class Key, class Value>
void BSTtree<Key, Value>::printSecondLargestKey() const {



}

template <class Key, class Value>
void BSTtree<Key, Value>::mirrorTree() {

}

template <class Key, class Value>
list<NODEtree<Key, Value>*> BSTtree<Key, Value>::getLeafNodes() const {

    return getLeafNodesR(root);

}

template <class Key, class Value>
list<NODEtree<Key, Value>*> BSTtree<Key, Value>::getLeafNodesR(const NODEtree<Key,Value>* n = nullptr) const {

    // TODO: pulir lo qe sea que sea esto
    if (n != nullptr) {

        list<NODEtree<Key, Value>*> new_list = new list<NODEtree<Key, Value>*>();

        if (!n->isExternal()) {
            getLeafNodes(n->getLeft());
        } else {
            new_list.push_back()
        }

    
        getLeafNodes(n->getRight());

    }


}

#endif