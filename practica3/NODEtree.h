template <class Key, class Value>
class NODEtree {

    public:
        NODEtree(const Key& key);
        NODEtree(const NODEtree<Key,Value>& orig);
        virtual ~NODEtree();
        /* Modificadors */
        void setKey();
        void setValue();        
        // Declareu-hi aquí els modificadors (setters) dels atributs que manquen
        /* Consultors */
        const Key& getKey() const;
        const vector<Value>& getValue() const;
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

template <class Key, class Value>
NODEtree<Key, Value>::NODEtree(const Key& key) {

    this->key = key;
    parent = left = right = values = nullptr;

}

template <class Key, class Value>
NODEtree<Key, Value>::NODEtree(const NODEtree<Key,Value>& orig) {


}

template <class Key, class Value>
NODEtree<Key, Value>::NODEtree(const NODEtree<Key,Value>& orig) {


}

template <class Key, class Value>
NODEtree<Key, Value>::NODEtree(const NODEtree<Key,Value>& orig) {


}

template <class Key, class Value>
NODEtree<Key, Value>::NODEtree(const NODEtree<Key,Value>& orig) {


}