// Nom i cognom: Karim Boujana Marcucci. Grup: F.

#include <vector>
#include <iostream>
#include <string>
#include <chrono>

#include "LinkedHashEntry.h"
#include "MubiesflixHash.h"
#include "HashMap.h"
#include "Peli.h"

using namespace std;

void test1_hashmap(){

    HashMap<int,int> map;
    int testArray[] = { 6, 21, 24, 45, 13, 20, 25 };

    std::vector<int> values;

    for (int i = 0; i < 7; i++) {

        cout << "Inserta al mapa " << testArray[i] << endl;
        values.push_back(i);

        for (int v : values) {
            map.put(testArray[i], v);
        }

    }

    map.print();
    cout << "get(0)" << endl;
    cout << map.get(0) << endl;
    cout << "get(6)" << endl;
    cout << map.get(6) << endl;
    cout << "Size of the map: " << map.size() << endl;
    cout << "Cells on the map " << map.cells() << " elements " << endl;
    cout << "MaxColisions on the map " << map.collisions() << " elements " << endl;
}

void test2_MubiesflixHash(){}

void test_exercici5(string test_file) {

    chrono::steady_clock::time_point begin, end; // precisió de milisegons
    cout << "Carregant MubiesflixHash..." << endl;
    
    begin = chrono::steady_clock::now();
    MubiesflixHash mainMubiesflix(test_file);
    end = chrono::steady_clock::now();

    auto t_creation=chrono::duration_cast<chrono::milliseconds>(end-begin).count();
    
    cout << "\n--- Test 1: getPeliculasDirector(1) ---" << endl;
    vector<Peli> pelisDir1 = mainMubiesflix.getPeliculasDirector(1);
    for (Peli& p : pelisDir1) {
        p.print();
        cout << endl;
    }
    
    string search_file = "directors-gran.csv";
    cout << "Cercant directors..." << endl;
    
    begin = chrono::steady_clock::now();
    mainMubiesflix.searchDirectorsFromFile(search_file);
    end = chrono::steady_clock::now();
    auto t_search=chrono::duration_cast<chrono::milliseconds>(end-begin).count();
    
    cout << "Temps de creació: " << t_creation << " ms" << endl;
    cout << "Temps de cerca: " << t_search << " ms" << endl;

}

int main() {
    cout << "\n\n------ Test1 HashMap ------" << endl;
    test1_hashmap(); // correspond al test de l’exercici 3 
    cout << "\n\n------ Test2 MubiesflixHash ------" << endl;
    test2_MubiesflixHash();
    cout << "\n\n------ Test3 MubiesflixHash ------" << endl; 
    test_exercici5("pelis-petit.csv");
    test_exercici5("pelis-gran.csv");
    return 0;
}