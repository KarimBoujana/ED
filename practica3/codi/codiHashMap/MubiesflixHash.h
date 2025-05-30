// Nom i cognom: Karim Boujana Marcucci. Grup: F.

#ifndef MUBIESFLIXHASH_H
#define MUBIESFLIXHASH_H

#include <vector>
#include <string>
#include <iostream>
#include <fstream>

#include "HashMap.h"
#include "Peli.h"

class MubiesflixHash: public HashMap<int,Peli> {

    public:
        MubiesflixHash(string file_path);// O(m) temporal, con m la cantidad de películas en el fichero, O(MAX_TABLE) espacial.
        virtual ~MubiesflixHash() {}; //O(MAX_TABLE*ki) con ki la cantidad de directores distintos asociados a un índice i.
        int totalCelles(); // O(1)
        int totalCol(); // O(1)
        int maxCol(); // O(1)
        int factorCarrega(); //percentatge d’espai ocupat al hash // O(1)
        void addPeli(int director_id, Peli peli); // Sea k la cantidad de directores distintos asociados a 
                                                  // un índice particular. O(k+1)
        vector<Peli> getPeliculasDirector(int director_id); // Sea k la cantidad de directores distintos asociados a 
                                                            // un índice particular. O(k+1)
        int searchDirectorsFromFile(string file_path) const; //O(j) con j la cantidad de ids en el fichero.

    private:
        void loadFromFile(string file_path); 
        // Sea k la cantidad de directores distintos asociados a 
        // un índice particular y j la cantidad de películas en el fichero. O(j*(k+1))
        void _insereixPelicula(int director_id, int peli_id, string titol, int durada, float valoracio); 
        // Sea k la cantidad de directores distintos asociados a 
        // un índice particular. O(k+1)

};

MubiesflixHash::MubiesflixHash(string file_path) {

    loadFromFile(file_path);

}

int MubiesflixHash::totalCelles() {
    return cells();
}

int MubiesflixHash::totalCol() {
    return size() - cells();
}

int MubiesflixHash::maxCol() {
    return collisions();
}

int MubiesflixHash::factorCarrega() {
    // Total de elementos / cantidad de celdas dentro de la tabla.
    return (size()/MAX_TABLE)*100;
}

void MubiesflixHash::addPeli(int director_id, Peli peli) {
    put(director_id, peli);
}

vector<Peli> MubiesflixHash::getPeliculasDirector(int director_id) {

    LinkedHashEntry<int, Peli>* aux = getPosition(director_id);

    while (aux != nullptr) {

        if (aux->getKey() == director_id) return aux->getValue();
        aux = aux->getNext();

    }

    throw runtime_error("Director no trobado.");

}

int MubiesflixHash::searchDirectorsFromFile(string file_path) const {
    
    fstream file(file_path);
    int count = 0;

    while(file.good()) {

        try {
            int id;
            file >> id;
            if (get(id)) count++;
        } catch(runtime_error e) {
            cout << e.what() << endl;
        }
    }

    return count;

}

void MubiesflixHash::loadFromFile(string file_path) {

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

            _insereixPelicula(directorId_int, peliId_int, titol, durada_int, valoracio_float);
                            
        }
    
    }

}

void MubiesflixHash::_insereixPelicula(int director_id, int peli_id, string titol, int durada, float valoracio) {

    Peli peli(peli_id, director_id, titol, durada, valoracio);
    put(director_id, peli);

}



#endif