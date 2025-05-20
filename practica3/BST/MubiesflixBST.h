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
        void setStrategy(AdditionStrategy addition_strategy); // he tenido que crearla para alterar la estrategia según la opción 8.
        int searchDirectorsFromFile(string file_path) const;

    private:
        AdditionStrategy addition_strategy;
        /* Metodes auxiliars, definiu-los aquí sota */
        const int k = 2;
        void showAllPelisR(NODEtree<int, Peli>* n, vector<int>& director_ids) const;
        void findSmallestNotTakenDirectorIdR(NODEtree<int, Peli>* n, vector<int>& ids) const;

};

MubiesflixBST::MubiesflixBST(AdditionStrategy addition_strategy) {
    this->addition_strategy = addition_strategy;
};

MubiesflixBST::MubiesflixBST(AdditionStrategy addition_strategy, string file_path) {
    this->addition_strategy = addition_strategy;
    loadFromFile(file_path);
};

MubiesflixBST::MubiesflixBST(const MubiesflixBST& orig) : BSTtree(orig), addition_strategy(orig.addition_strategy) {
    
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

                    getline(file, peliId); // De esta forma saltamos la primera línea.

                    while (file.good()) {
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

                        insert(directorId_int, peli);
                                       
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
            

            cout << endl << "Director: " << director_ids.at(i) << endl;
            cout << "===" << endl;
            showPelisByDirector(director_ids.at(i));            

            if (i == directors_to_show -1 && i != director_ids.size()-1) {

                cout << "Vols veure les següents " << k << " directors? ";
                cin >> answer;
                if (answer == 'n') stop = true;
                else directors_to_show += k;                

            }

        }

    }
    
}

void MubiesflixBST::showAllPelisR(NODEtree<int, Peli>* n, vector<int>& directores) const {
    
    if (empty()) {cout << "Base de datos vacía."; return;}
    if (n->hasLeft()) showAllPelisR(n->getLeft(), directores);
    directores.push_back(n->getKey());
    if (n->hasRight()) showAllPelisR(n->getRight(), directores);

}

void MubiesflixBST::showPelisByDirector(int director_id) const {

    if (empty()) throw string("Base de datos vacia.");
    
    int counter = 1;

    // Search lanzará runtime_error si no se encuentra al director buscado.
    for (Peli peli : search(director_id)->getValues()) {

        cout << "Pel·lícula " << counter <<": " << peli.getPeliId() << " " << peli.getTitol() << " " << peli.getDurada() << " " << peli.getValoracio() << " " << endl;
        counter++;
    }
    cout << "\n";

}

float MubiesflixBST::getAverageValoracioOfDirector(int director_id) const {

    if (empty()) throw string("Base de datos vacia.");
    
    int counter = 0;
    float suma = 0;

    try {
        
        // Search lanzará runtime_error si no se encuentra al director buscado.
        for (Peli peli : search(director_id)->getValues()) {
    
            counter++;
            suma += peli.getValoracio();
        }

    } catch(runtime_error e) {
        cout << e.what() << endl;
    }


    if (counter == 0) return 0;
    else return suma/counter;

}

int MubiesflixBST::findLargestDirectorId() const {

    if (empty()) return 0;
    NODEtree<int, Peli> * aux = root;
    while (aux->hasRight()) aux = aux->getRight();

    return aux->getKey();

}

int MubiesflixBST::findSmallestNotTakenDirectorId() const {
    
    if (empty()) return 1;

    vector<int> ids;
    findSmallestNotTakenDirectorIdR(root, ids);

    if (ids.size() > 1) {

        // Si el primero no es 1, devolvemos 1.
        if (ids.at(0) != 1) return 1;

        // Si la diferencia entre alguno es mayor que uno, devolvemos el más pequeño más 1.
        for (int i = 1; i < ids.size(); i++) {

            if (ids.at(i) - ids.at(i-1) > 1) return ids.at(i-1)+1;
            
        }
        // Si no encontramos ningun valor con alguna diferencia mayor que 1, el más pequeño es el más grande más uno.
        return ids.back()+1;

    }
    else return ids.at(0) > 1 ? 1 : 2;


}

void MubiesflixBST::findSmallestNotTakenDirectorIdR(NODEtree<int, Peli>* n, vector<int>& ids) const {
    
    if (n->hasLeft()) findSmallestNotTakenDirectorIdR(n->getLeft(), ids);
    ids.push_back(n->getKey());
    if (n->hasRight()) findSmallestNotTakenDirectorIdR(n->getRight(), ids);

}

void MubiesflixBST::addPeli() {
    int director_id = -1;
    int option = -1;

    cout << "¿Desea introducir manualmente el ID del director (0) o generarlo automáticamente (1)?: " << endl;
    while (option < 0 || option > 1) {
        cin >> option;
    }
    
    if (option == 0) {
        cout << "Introduce el ID: ";
        cin >> director_id;
    }

    int peliId;
    int directorId;
    string titol;
    int durada;
    float valoracio;

    cout << "Introdueix el id de la peli: ";
    cin >> peliId;
    cout << "Introdueix el títol de la peli: ";
    cin.ignore();
    getline(cin, titol);
    cout << "Introdueix la durada de la peli: ";
    cin >> durada;
    cout << "Introdueix la valoració de la peli: ";
    cin >> valoracio;
    Peli peli(peliId, director_id, titol, durada, valoracio);

    if (director_id >= 0) insert(director_id, peli);

    else switch(addition_strategy) {
        case AFTER_LARGEST_ID:
            insert(findLargestDirectorId()+1, peli);
            break;

        case SMALLEST_NOTTAKEN_ID:
            insert(findSmallestNotTakenDirectorId(), peli);
            break;

    }



}

void MubiesflixBST::setStrategy(AdditionStrategy addition_strategy) {
    this->addition_strategy = addition_strategy;
}

int MubiesflixBST::searchDirectorsFromFile(string file_path) const {

    fstream file(file_path);
    int count = 0;

    while(file.good()) {

        try {
            int id;
            file >> id;
            if (search(id)) count++;
        } catch(runtime_error e) {
            cout << e.what() << endl;
        }

    }

    return count;

}