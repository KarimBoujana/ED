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
        void setValue(const vector<Value>& vector);    
        void setParent(const NODEtree* parent);
        void setLeft(const NODEtree* left);
        void setRight(const NODEtree* right);

        /* Consultors */
        const Key& getKey() const;
        const vector<Value>& getValue() const;
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
        bool operator==(const NODETree<Key,Value>& node) const;

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
    parent = left = right = values = nullptr;

}

template <class Key, class Value>
NODEtree<Key, Value>::NODEtree(const NODEtree<Key,Value>& orig) {

    NODEtree node;
    node.setKey(orig.getKey());
    node.setValue(orig.getValue());


}

template <class Key, class Value>
NODEtree<Key, Value>::~NODEtree() {
    //Destructor. todo: destruir
}


// Modificadores.
template <class Key, class Value>
void NODEtree<Key, Value>::setKey(const Key&) {

    this->key = key;

}

template <class Key, class Value>
void NODEtree<Key, Value>::setValue(const vector<Value>& vector) {

    this->values = vector;

}

template <class Key, class Value>
void NODEtree<Key, Value>::setParent(const NODEtree* parent) {

    this->parent = parent;

}

template <class Key, class Value>
void NODEtree<Key, Value>::setLeft(const NODEtree* left) {

    this->left = left;

}

template <class Key, class Value>
void NODEtree<Key, Value>::setRight(const NODEtree* right) {

    this->right = right;

}


// Consultores.

template <class Key, class Value>
const Key& NODEtree<Key, Value>::getKey() const {

    return key&;

}

template <class Key, class Value>
const vector<Value>& NODEtree<Key, Value>::getValue() const {

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
void NODEtree<Key, Value>::setKey(const Key&) {

    key = Key;

}

template <class Key, class Value>
void NODEtree<Key, Value>::setKey(const Key&) {

    key = Key;

}

template <class Key, class Value>
void NODEtree<Key, Value>::setKey(const Key&) {

    key = Key;

}

template <class Key, class Value>
void NODEtree<Key, Value>::setKey(const Key&) {

    key = Key;

}

template <class Key, class Value>
void NODEtree<Key, Value>::setKey(const Key&) {

    key = Key;

}