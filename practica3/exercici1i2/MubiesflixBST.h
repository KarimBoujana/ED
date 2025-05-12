#include <iostream>
#include <fstream>
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
        const int k = 2;
        void showAllPelisR(NODEtree<int, Peli>* n, vector<int> director_ids) const;

};

MubiesflixBST::MubiesflixBST(AdditionStrategy addition_strategy) {
    this->addition_strategy = addition_strategy;
};

MubiesflixBST::MubiesflixBST(AdditionStrategy addition_strategy, string file_path) {
    this->addition_strategy = addition_strategy;
    this->file_path = file_path;
};

MubiesflixBST::MubiesflixBST (const MubiesflixBST & orig) {

    this->addition_strategy = orig.addition_strategy;
    BSTtree(orig);

}

MubiesflixBST::~MubiesflixBST () {
}

void MubiesflixBST::loadFromFile(string file_path) {

    ifstream file(file_path);

                if (file.is_open()) { 

                    string peliId;
                    string directorId;
                    string titol;
                    string durada;
                    string valoracio;

                    while (file.good()) {
                        cout << "----------------------------------\n";
                        getline(file, peliId, '|');
                        int peliId_int = stoi(peliId);

                        getline(file, directorId, '|');
                        int directorId_int = stoi(directorId);

                        getline(file, titol, '|');
                        getline(file, durada, '|');
                        int durada_int = stoi(durada);

                        getline(file, valoracio);
                        float valoracio_float = stof(valoracio);

                        Peli peli(peliId_int, directorId_int, titol, durada_int, valoracio_float);

                        switch(addition_strategy) {
                            case AFTER_LARGEST_ID:
                                insert(findLargestDirectorId()+2, peli);
                                break;
                    
                            case SMALLEST_NOTTAKEN_ID:
                                insert(findSmallestNotTakenDirectorId(), peli);
                                break;

                    }          
                                       
                }
            }

}

void MubiesflixBST::showAllPelis() const {

    if (empty()) cout << "Base de datos vacía." << endl;

    else {

        int directors_to_show = k;
        bool stop = false;
        char answer = 'y';

        vector<int> director_ids;
        showAllPelisR(root, director_ids);
    
        for (int i = 0 ; !stop && i < director_ids.size() && i < directors_to_show ; i++) {
    
            cout << "Director: " << director_ids.at(i) << endl;
            cout << "===" << endl;
            showPelisByDirector(director_ids.at(i));            

            if (i == directors_to_show -1) {

                cout << "Vols veure les següents " << k << "directors? ";
                cin >> answer;
                if (answer == 'n') stop = true;
                else directors_to_show += k;                

            }

        }

    }
    
}

void MubiesflixBST::showAllPelisR(NODEtree<int, Peli>* n, vector<int> directores) const {
    
    if (empty()) {cout << "Base de datos vacía."; return;}
    if (n->hasLeft()) printInorder(n->getLeft());
    directores.push_back(n->getKey());
    if (n->hasRight()) printInorder(n->getRight());

}

void MubiesflixBST::showPelisByDirector(int director_id) const {

    if (empty()) throw string("Base de datos vacia.");
    
    int counter = 1;

    // Search lanzará runtime_error si no se encuentra al director buscado.
    for (Peli peli : search(director_id)->getValues()) {

        cout << "Pel·lícula " << counter <<":" << peli.getPeliId() << peli.getTitol() << peli.getDurada() << peli.getValoracio() << endl;
        counter++;
    }

}

float MubiesflixBST::getAverageValoracioOfDirector(int director_id) const {

    if (empty()) throw string("Base de datos vacia.");
    
    int counter = 0;
    float suma = 0;

    // Search lanzará runtime_error si no se encuentra al director buscado.
    for (Peli peli : search(director_id)->getValues()) {

        counter++;
        suma += peli.getValoracio();
    }

    if (counter == 0) return 0;
    else return suma/counter;

}

int MubiesflixBST::findLargestDirectorId() const {

    NODEtree<int, Peli> * aux = root;
    while (aux->hasRight()) aux = aux->getRight();

    return aux->getKey();

}

int MubiesflixBST::findSmallestNotTakenDirectorId() const {
    // TODO: nuria te necesito
}

void MubiesflixBST::addPeli() {
    int director_id = -1;
    int option = -1;

    cout << "¿Desea introducir manualmente el ID del director (0) o generarlo automáticamente (1)?: " << endl;
    while (option < -1 && option > 1) cin >> option;
    
    if (option == 0) {
        cout << "Introduce el ID: ";
        cin >> director_id;
    } 
    
    else {
        cout << "¿Desea introducir después del identificador más grande (0) o el identificador más pequeño (1)?: " << endl;
        while (option < -1 && option > 1) cin >> option;
        if (option == 0) addition_strategy = AFTER_LARGEST_ID;
        else addition_strategy = SMALLEST_NOTTAKEN_ID;
    }

    int peliId;
    int directorId;
    string titol;
    int durada;
    float valoracio;

    cout << "Introdueix el títol de la peli: ";
    cin.ignore();
    getline(cin, titol);
    cout << "Introdueix la durada de la peli: ";
    cin >> durada;
    cout << "Introdueix la valoració de la peli: ";
    cin >> valoracio;
    Peli peli(peliId, directorId, titol, durada, valoracio);

    if (director_id >= 0) insert(director_id, peli);
    else switch(addition_strategy) {
        case AFTER_LARGEST_ID:
            insert(findLargestDirectorId()+2, peli);
            break;

        case SMALLEST_NOTTAKEN_ID:
            insert(findSmallestNotTakenDirectorId(), peli);
            break;

    }



}
