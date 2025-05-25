// Nom i cognom: Karim Boujana Marcucci. Grup: F.

#ifndef NODETREE_H
#define NODETREE_H
#include <vector>

using namespace std;

template <class Key, class Value>
class NODEtree {

    public:

        // Consideremos n la cantidad de nodos.
        NODEtree(const Key& key); // O(1)
        NODEtree(const NODEtree<Key,Value>& orig); // O(1)
        virtual ~NODEtree(); // O(n), ya que eliminaremos todos los nodos si se llama desde la root.

        /* Modificadors */
        void setKey(const Key& key); // O(1)
        void setValues(const Value &values); // O(1)
        void setParent(NODEtree* parent); // O(1)
        void setLeft(NODEtree* left); // O(1)
        void setRight(NODEtree* right); // O(1)

        /* Consultors */
        const Key& getKey() const; // O(1)
        const vector<Value>& getValues() const; // O(1)
        NODEtree* getParent() const; // O(1)
        const NODEtree* getLeft() const; // O(1)
        const NODEtree* getRight() const; // O(1)
        NODEtree<Key, Value>* getLeft(); // O(1)
        NODEtree<Key, Value>* getRight();  // O(1)


        // Declareu-hi aquí els consultors (getters) dels atributs que manquen
        /* Operacions */
        bool isRoot() const; // O(1)
        bool hasLeft() const; // O(1)
        bool hasRight() const; // O(1)
        bool isExternal() const; // O(1)
        void insertValue(const Value& v); // O(1)
        int depth() const; //O(n) degenera a lista.
        int height() const; // O(1)
        bool operator==(const NODEtree<Key,Value>& node) const; // O(1)

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
    delete left;
    delete right;
}


// Modificadores.
template <class Key, class Value>
void NODEtree<Key, Value>::setKey(const Key&) {

    this->key = key;

}

template <class Key, class Value>
void NODEtree<Key, Value>::setValues(const Value& values) {

    vector<Value> valores;
    valores.push_back(values);
    this->values = valores;

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
NODEtree<Key, Value>* NODEtree<Key, Value>::getParent() const {

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

template <class Key, class Value>
NODEtree<Key, Value>* NODEtree<Key, Value>::getLeft() {

    return left;

}

template <class Key, class Value>
NODEtree<Key, Value>* NODEtree<Key, Value>::getRight() {

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

    return left == nullptr && right == nullptr;

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

#endif // NODETREE_H