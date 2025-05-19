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
        Peli(int, int, string, int, float);
        Peli();
        ~Peli();
        int getPeliId();
        int getDirectorId();
        string getTitol();
        int getDurada();
        float getValoracio();
        void print();
        string toString() const;
        friend std::ostream& operator<<(std::ostream& os, const Peli& obj);
        
};

#endif // PELI_H