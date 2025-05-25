// Nom i cognom: Karim Boujana Marcucci. Grup: F.

#ifndef PELI_H
#define PELI_H

#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Peli {

    private:
        int peliId;
        int directorId;
        string titol;
        int durada;
        float valoracio;

    public:
        Peli(int, int, string, int, float); // O(1)
        Peli(); // O(1)
        ~Peli(); // O(1)
        int getPeliId(); // O(1)
        int getDirectorId(); // O(1)
        string getTitol(); // O(1)
        int getDurada(); // O(1)
        float getValoracio(); // O(1)
        void print(); // O(1)
        string toString() const; // O(1)
        friend std::ostream& operator<<(std::ostream& os, const Peli& obj); // O(1)
        
};

#endif // PELI_H