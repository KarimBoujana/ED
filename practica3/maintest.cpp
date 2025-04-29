#include <vector>
#include <string>
#include <iostream>
#include "NODEtree.h"

using namespace std;

int main() {

    int a = 12, b = 13;
    NODEtree<int, int> pepe(a);
    pepe.insertValue(b);
    cout << pepe.getValues().at(0) << endl;

    NODEtree<int, int> pepe_copiado(pepe);
    cout << pepe_copiado.getKey() << endl;

    pepe.setLeft(&pepe_copiado);
    pepe_copiado.setParent(&pepe);
    cout << (pepe_copiado == pepe) << endl;
    return 0;
}
