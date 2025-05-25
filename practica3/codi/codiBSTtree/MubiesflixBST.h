// Nom i cognom: Karim Boujana Marcucci. Grup: F.

#include <iostream>
#include <fstream>
#include <string>
#include "BSTtree.h"
#include "Peli.h"
using namespace std;

class MubiesflixBST : protected BSTtree<int, Peli> {

    public:
    //Sea n la cantidad de directores.
        enum AdditionStrategy { AFTER_LARGEST_ID, SMALLEST_NOTTAKEN_ID };
        MubiesflixBST(AdditionStrategy addition_strategy); // O(1)
        MubiesflixBST (AdditionStrategy addition_strategy, string file_path); // O(m*n), con m la cantidad de películas en el fichero.
        MubiesflixBST (const MubiesflixBST & orig); //O(n^2), ya que haremos n inserciones de tiempo n.
        virtual ~MubiesflixBST (); //O(n)
        void loadFromFile(string file_path); // O(m*n), con m la cantidad de películas en el fichero.
        void showAllPelis() const; //O(n)
        void showPelisByDirector(int director_id) const; //O(n+k), con k la cantidad de películas asociadas a un director.
        float getAverageValoracioOfDirector(int director_id) const; //O(n+k)
        int findLargestDirectorId() const; //O(n)
        int findSmallestNotTakenDirectorId() const; //O(n)
        void addPeli(); //O(n), puesto que la inserción puede tardar como mucho n.
        void setStrategy(AdditionStrategy addition_strategy); // he tenido que crearla para alterar la estrategia según la opción 8. // O(1)
        int searchDirectorsFromFile(string file_path) const; //O(j*n) con j la cantidad de ids en el fichero.

    private:
        AdditionStrategy addition_strategy;
        /* Metodes auxiliars, definiu-los aquí sota */
        const int k = 2;
        void showAllPelisR(NODEtree<int, Peli>* n, vector<int>& director_ids) const; //O(n)
        void findSmallestNotTakenDirectorIdR(NODEtree<int, Peli>* n, vector<int>& ids) const; //O(n)

};

MubiesflixBST::MubiesflixBST(AdditionStrategy addition_strategy) {
    this->addition_strategy = addition_strategy;
};

MubiesflixBST::MubiesflixBST(AdditionStrategy addition_strategy, string file_path) {
    this->addition_strategy = addition_strategy;
    loadFromFile(file_path);
};

MubiesflixBST::MubiesflixBST(const MubiesflixBST& orig) : BSTtree(orig), addition_strategy(orig.addition_strategy) {
    // Constructor copia heredado.
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
            

            //Tenemos tres condiciones:
            // 1. Que nos digan parar.
            // 2. Llegar al final del array.
            // 3. Mostrar k películas.
            cout << endl << "Director: " << director_ids.at(i) << endl;
            cout << "===" << endl;
            showPelisByDirector(director_ids.at(i));            

            // Particularmente, no preguntaremos si ya hemos acabado con todas las pelis del array.
            if (i == directors_to_show -1 && i != director_ids.size()-1) {

                cout << "Vols veure les següents " << k << " directors? ";
                cin >> answer;
                while (cin.fail() || answer != 's' || answer != 'n') {
                    cout << "Entrada no valida." << endl;
                    cin >> answer;
                    cin.clear();
                    cin.ignore(100000, '\n');
                }
                if (answer == 'n') stop = true;
                else directors_to_show += k;                

            }

        }

    }
    
}

void MubiesflixBST::showAllPelisR(NODEtree<int, Peli>* n, vector<int>& directores) const {
    
    //Este método recursivo recibe un vector de directores y lo rellena con todos los directores posibles en inorder.
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

    //Derecha del todo.
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
    while (cin.fail()) {
        cout << "Entrada no valida." << endl;
        cin >> option;
        cin.clear();
        cin.ignore(100000, '\n');
    }
    
    if (option == 0) {
        cout << "Introduce el ID: ";
        cin >> director_id;
        while (cin.fail()) {
            cout << "Entrada no valida." << endl;
            cin >> director_id;
            cin.clear();
            cin.ignore(100000, '\n');
        }
    }

    int peliId;
    int directorId;
    string titol;
    int durada;
    float valoracio;

    cout << "Introdueix el id de la peli: ";
    cin >> peliId;

    while (cin.fail()) {
            cout << "Entrada no valida." << endl;
            cin >> peliId;
            cin.clear();
            cin.ignore(100000, '\n');
        }
    
    cout << "Introdueix el títol de la peli: ";
    cin.ignore();
    getline(cin, titol);
    
    while (cin.fail()) {
        cout << "Entrada no valida." << endl;
        getline(cin, titol);
        cin.clear();
        cin.ignore(100000, '\n');
        }
        
    cout << "Introdueix la durada de la peli: ";
    cin >> durada;

    while (cin.fail()) {
        cout << "Entrada no valida." << endl;
        cin >> durada;
        cin.clear();
        cin.ignore(100000, '\n');
    }

    cout << "Introdueix la valoració de la peli: ";
    cin >> valoracio;

    while (cin.fail()) {
        cout << "Entrada no valida." << endl;
        cin >> valoracio;
        cin.clear();
        cin.ignore(100000, '\n');
    }

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