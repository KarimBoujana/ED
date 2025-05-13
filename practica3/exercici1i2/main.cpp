#include <vector>
#include <iostream>
#include "BSTtree.h"
#include "NODEtree.h"
#include "MubiesflixBST.h"
using namespace std;

void mainExercici1(){
    BSTtree<int, int> tree1;

    int testKeys[] = {2, 0, 8, 45, 76, 5, 3, 40};
    int testValues[] = {5, 5, 1, 88, 99, 12, 9, 11};

    for (int i = 0; i < 8 ; i++) {
        cout << "Inserta a l'arbre la key " << testKeys[i] << " amb valor " << testValues[i] << endl;
        tree1.insert(testKeys[i], testValues[i]);
    }

    cout << "Preorder = [";
    tree1.printPreorder();
    cout << "]" << endl;
    cout << "Inorder = [";
    tree1.printInorder();
    cout << "]" << endl;
    cout << "Postorder = [";
    tree1.printPostorder();
    cout << "]" << endl; 
    cout << "--> Second largest key is... ";
    tree1.printSecondLargestKey();
    cout << endl;
    
    cout << "FULLES De l'arbre = ";

    list<NODEtree<int,int> *> fulles = tree1.getLeafNodes();
    cout << "{ " ;

    for(NODEtree<int, int>* n: fulles){
    cout << n->getKey() << " ";
    }

    cout << "}" << endl<< endl;

    BSTtree<int, int> tree2(tree1);
    
    tree1.mirrorTree();
    cout << "Inorder = [";
    tree1.printInorder();
    cout << "]" << endl;
}

void mainExercici2(){

    MubiesflixBST::AdditionStrategy strategy = MubiesflixBST::AFTER_LARGEST_ID;
    MubiesflixBST tree1(strategy);

    int testKeys[] = {2, 0, 8, 45, 76, 5, 3, 40};
    int testValues[] = {5, 5, 1, 88, 99, 12, 9, 11};


    tree1.addPeli();
    cout << tree1.findSmallestNotTakenDirectorId() << endl;
    tree1.addPeli();
    cout << tree1.findSmallestNotTakenDirectorId() << endl;
    tree1.addPeli();
    cout << tree1.findSmallestNotTakenDirectorId() << endl;

    
}

int choose_option() {

    vector<string> vector_options = {"Cargar datos de un fichero.", "Mostrar las pelis de un director.", "Valoración media de un director.", "Mostrar todos los directores.", "Identificador más grande.", "Identificador más pequeño no asignado", "Añadir nueva película a un director", "Establecer estrategia de inserción",     "Salir."};
    int respuesta;

    cout << "----------------------------------------\n";
        // Inicializamos un vector con las opciones, y lo iteramos.
        for (int i = 1; i <= vector_options.size(); i++) {

            cout << i << ". " << vector_options.at(i-1) << endl;

        }
    cout << "----------------------------------------\n";

    // Se guarda la respuesta.
    cin >> respuesta;

    //Si es válida, se admite. En caso contrario, se le asigna el valor -1.
    if (respuesta > vector_options.size() || respuesta < 0) respuesta = -1;
    
    return respuesta;

}

void menu() {
    int option;
    MubiesflixBST::AdditionStrategy strategy = MubiesflixBST::AFTER_LARGEST_ID;
    MubiesflixBST menu_tree(strategy);

    // Haremos este do while mientras no elijan la opción 5.
    do {
        option = choose_option(); // Vemos qué elige el usuario.
        // Si no escogen algo válido, se asigna el valor -1 y se le pide que introduzca un valor válido.
        switch (option) {

//Si escogen 1, leemos un fichero.
            case 1:
            {
                string path = "pelis-cas_de_prova.csv"; // TODO: hacerlo dinamico.
              /*cout << "Introduce el camino del fichero.\n";
                cin >> cami;*/

                menu_tree.loadFromFile(path);       

            }
                
                break;

// Si escogen 2, eliminamos una peli.
            case 2:

                
            
                break;

// Si escogen 3, introduciremos n películas hasta que nos digan basta.
            case 3:
            {
                
            }
                break;

// Si escogen 4, imprimimos por pantalla toda la Cola.
            case 4:
                break;
            
// Si escogen cualquier otro valor, señalamos que nos den un valor correcto.
            case -1:
                cout << "Introdueix un valor vàlid." << endl;
                break;

        }

    } while (option != 9);
}

int main () {
    // mainExercici1();
    mainExercici2();
    // menu();
    return 0;
}