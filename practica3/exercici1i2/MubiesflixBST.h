#include <iostream>
#include <string>
#include "BSTtree.h"
#include "Peli.h"
using namespace std;

class MubiesflixBST : protected BSTtree<int, Peli> {

    public:
        enum AdditionStrategy { AFTER_LARGEST_ID, SMALLEST_NOTTAKEN_ID };
        MubiesflixBST(AdditionStrategy addition_strategy);
        MubiesflixBST (AdditionStrategy addition_strategy, string file_path);
        MubiesflixBST (const MubiesflixBST & orig);
        virtual ~MubiesflixBST ();
        void loadFromFile(string file_path);
        void showAllPelis() const;
        void showPelisByDirector(int director_id) const;
        float getAverageValoracioOfDirector(int director_id) const;
        int findLargestDirectorId() const;
        int findSmallestNotTakenDirectorId() const;
        void addPeli();

    private:
        AdditionStrategy addition_strategy;
        /* Metodes auxiliars, definiu-los aquí sota */
        string file_path;
};

MubiesflixBST::MubiesflixBST(AdditionStrategy addition_strategy) {
    this->addition_strategy = addition_strategy;
};

MubiesflixBST::MubiesflixBST(AdditionStrategy addition_strategy, string file_path) {
    this->addition_strategy = addition_strategy;
    this->file_path = file_path;
};

MubiesflixBST::MubiesflixBST (const MubiesflixBST & orig) {

    //TODO: hacer copia de la estructura

}

MubiesflixBST::~MubiesflixBST () {
    //TODO: destruir
}

void MubiesflixBST::loadFromFile(string file_path) {

}

void MubiesflixBST::showAllPelis() const {

}

void MubiesflixBST::showPelisByDirector(int director_id) const {

    cout << "Pel·lícula " << 1 <<":" << peli_id1 << titol1 << durada1 << valoracio1 << endl;

}

float MubiesflixBST::getAverageValoracioOfDirector(int director_id) const {

}

int MubiesflixBST::findLargestDirectorId() const {

}

int MubiesflixBST::findSmallestNotTakenDirectorId() const {

}

void MubiesflixBST::addPeli() {

}
