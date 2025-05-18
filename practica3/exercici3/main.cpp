#include <vector>
#include <iostream>
#include <string>
#include "LinkedHashEntry.h"
#include "HashMap.h"
using namespace std;

void test_hashmap(){

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

int main() {

    test_hashmap();

    return 0;
}