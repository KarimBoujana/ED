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
        MubiesflixHash(string file_path);
        virtual ~MubiesflixHash() {};
        int totalCelles();
        int totalCol();
        int maxCol();
        int factorCarrega(); //percentatge d’espai ocupat al hash
        void addPeli(int director_id, Peli peli);
        vector<Peli> getPeliculasDirector(int director_id);

    private:
        void loadFromFile(string file_path);
        void _insereixPelicula(int director_id, int peli_id, string titol, int durada, float valoracio);

};

MubiesflixHash::MubiesflixHash(string file_path) {

    loadFromFile(file_path);

}

MubiesflixHash::~MubiesflixHash() {};


int MubiesflixHash::totalCelles() {
    return cells();
}

int MubiesflixHash::totalCol() {

    int total = 0;
    for (int i = 0; i < size(); i++) {
        if ()
    }

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

            _insereixPelicula(peliId_int, directorId_int, titol, durada_int, valoracio_float);
                            
        }
    
    }

}

void MubiesflixHash::_insereixPelicula(int director_id, int peli_id, string titol, int durada, float valoracio) {

    Peli peli(director_id, peli_id, titol, durada, valoracio);
    put(director_id, peli);

}



#endif