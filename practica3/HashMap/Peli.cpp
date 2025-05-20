#include <string>
#include <vector>
#include <iostream>
#include "Peli.h"

using namespace std;

Peli::Peli(int peliId, int directorId, string titol, int durada, float valoracio) {
    this->peliId = peliId;
    this->directorId = directorId;
    this->titol = titol;
    this->durada = durada;
    this->valoracio = valoracio;
}

Peli::Peli() {
    this->peliId = 0;
    this->directorId =0;
    this->titol = "";
    this->durada = 0;
    this->valoracio = 0.0f;
}

//Destructor
Peli::~Peli() {}

int Peli::getPeliId() {
    return this->peliId;
}

int Peli::getDirectorId() {
    return this->directorId;
}

string Peli::getTitol() {
    return this->titol;
}

int Peli::getDurada() {
    return this->durada;
}

float Peli::getValoracio() {
    return this->valoracio;
}

void Peli::print() {
    cout << "Peli ID: " << this->peliId << endl;
    cout << "Director ID: " << this->directorId << endl;
    cout << "Titol: " << this->titol << endl;
    cout << "Durada: " << this->durada << endl;
    cout << "Valoracio: " << this->valoracio << endl;
}


string Peli::toString() const {
    return "Peli ID: " + to_string(this->peliId) + "\nDirector ID: " + to_string(this->directorId) + "\nTitol: " + this->titol + "\nDurada: " + to_string(this->durada) + "\nValoracio: " + to_string(this->valoracio) + "\n\n";
}

std::ostream& operator<<(std::ostream& os, const Peli& obj) {
    os << obj.toString();
    return os;
}