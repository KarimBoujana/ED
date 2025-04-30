#ifndef NODETREE_H
#define NODETREE_H
#include <vector>

using namespace std;

template <class Key, class Value>
class NODEtree {

    public:

        NODEtree(const Key& key);
        NODEtree(const NODEtree<Key,Value>& orig);
        virtual ~NODEtree();

        /* Modificadors */
        void setKey(const Key& key);
        void setValues(const vector<Value>& vector);    
        void setParent(NODEtree* parent);
        void setLeft(NODEtree* left);
        void setRight(NODEtree* right);

        /* Consultors */
        const Key& getKey() const;
        const vector<Value>& getValues() const;
        const NODEtree* getParent() const;
        const NODEtree* getLeft() const;
        const NODEtree* getRight() const;

        // Declareu-hi aquí els consultors (getters) dels atributs que manquen
        /* Operacions */
        bool isRoot() const;
        bool hasLeft() const;
        bool hasRight() const;
        bool isExternal() const;
        void insertValue(const Value& v);
        int depth() const;
        int height() const;
        bool operator==(const NODEtree<Key,Value>& node) const;

    private:
        Key key;
        vector<Value> values;
        NODEtree* parent;
        NODEtree* left;
        NODEtree* right;

};

// Iniciadores.
template <class Key, class Value>
NODEtree<Key, Value>::NODEtree(const Key& key) {

    this->key = key;
    values = vector<Value>();
    parent = left = right = nullptr;

}

template <class Key, class Value>
NODEtree<Key, Value>::NODEtree(const NODEtree<Key,Value>& orig) {

    this->key = orig.getKey();
    this->values = orig.getValues();
    parent = left = right = nullptr;

}

template <class Key, class Value>
NODEtree<Key, Value>::~NODEtree() {
    //TODO: destruir
}


// Modificadores.
template <class Key, class Value>
void NODEtree<Key, Value>::setKey(const Key&) {

    this->key = key;

}

template <class Key, class Value>
void NODEtree<Key, Value>::setValues(const vector<Value>& values) {

    this->values = values;

}

template <class Key, class Value>
void NODEtree<Key, Value>::setParent(NODEtree* parent) {

    this->parent = parent;

}

template <class Key, class Value>
void NODEtree<Key, Value>::setLeft(NODEtree* left) {

    this->left = left;

}

template <class Key, class Value>
void NODEtree<Key, Value>::setRight(NODEtree* right) {

    this->right = right;

}


// Consultores.

template <class Key, class Value>
const Key& NODEtree<Key, Value>::getKey() const {

    return key;

}

template <class Key, class Value>
const vector<Value>& NODEtree<Key, Value>::getValues() const {

    return values;

}

template <class Key, class Value>
const NODEtree<Key, Value>* NODEtree<Key, Value>::getParent() const {

    return parent;

}

template <class Key, class Value>
const NODEtree<Key, Value>* NODEtree<Key, Value>::getLeft() const {

    return left;

}

template <class Key, class Value>
const NODEtree<Key, Value>* NODEtree<Key, Value>::getRight() const {

    return right;

}


// OPERACIONS
template <class Key, class Value>
bool NODEtree<Key, Value>::isRoot() const {

    return parent == nullptr;

}

template <class Key, class Value>
bool NODEtree<Key, Value>::hasLeft() const {

    return left != nullptr;

}

template <class Key, class Value>
bool NODEtree<Key, Value>::hasRight() const {

    return right != nullptr;

}

template <class Key, class Value>
bool NODEtree<Key, Value>::isExternal() const {

    return !hasLeft() && !hasRight();

}

template <class Key, class Value>
void NODEtree<Key, Value>::insertValue(const Value& v) {
    values.push_back(v);
}

template <class Key, class Value>
int NODEtree<Key, Value>::depth() const {

    if (isRoot()) return 0;
    return parent->depth() + 1;

}

template <class Key, class Value>
int NODEtree<Key, Value>::height() const {

    return depth()+1;

}


template <class Key, class Value>
bool NODEtree<Key, Value>::operator==(const NODEtree<Key,Value>& node) const {

    return key.equals(node.getKey()) && values.equals(node.getValues);

}

#endif