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
};

template <class Key, class Value>
BSTtree<::BSTtree() {
    _size = 0;
}