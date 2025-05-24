// Nom i cognom: Karim Boujana Marcucci. Grup: F.

#include <vector>
#include <iostream>
#include <chrono>

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
    
    chrono::steady_clock::time_point begin, end; // precisió de milisegons
    string path = "pelis-petit.csv";
    cout << "Carregant MubiesBST..." << endl;
    
    begin = chrono::steady_clock::now();
    MubiesflixBST mainMubiesflix(strategy, path);
    end = chrono::steady_clock::now();
    
    auto t_creation=chrono::duration_cast<chrono::milliseconds>(end-begin).count();
    cout << "Temps de creació: " << t_creation << " ms" << endl;
    
    
}

void test_exercici5(string test_file) {
    
    MubiesflixBST::AdditionStrategy strategy = MubiesflixBST::AFTER_LARGEST_ID;
    chrono::steady_clock::time_point begin, end; // precisió de milisegons
    cout << "Carregant MubiesflixBST..." << endl;
    
    begin = chrono::steady_clock::now();
    MubiesflixBST mainMubiesflix(strategy, test_file);
    end = chrono::steady_clock::now();

    auto t_creation=chrono::duration_cast<chrono::milliseconds>(end-begin).count();
    
    string search_file = "directors-gran.csv";
    cout << "Cercant directors..." << endl;
    
    begin = chrono::steady_clock::now();
    mainMubiesflix.searchDirectorsFromFile(search_file);
    end = chrono::steady_clock::now();
    auto t_search=chrono::duration_cast<chrono::milliseconds>(end-begin).count();
    
    cout << "Temps de creació: " << t_creation << " ms" << endl;
    cout << "Temps de cerca: " << t_search << " ms" << endl;

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

    // Haremos este do while mientras no elijan la opción 9.
    do {
        option = choose_option(); // Vemos qué elige el usuario.
        // Si no escogen algo válido, se asigna el valor -1 y se le pide que introduzca un valor válido.
        switch (option) {

//Si escogen 1, leemos un fichero.
            case 1:
            {
                string path;
                cout << "Introduce el camino del fichero.\n";
                cin >> path;

                menu_tree.loadFromFile(path);       

            }
                
                break;

//Si escogen 2, mostramos la peli de un director.
            case 2:
            {
                int id;
                cout << "Introduce el ID del director.\n";
                cin >> id;
                menu_tree.showPelisByDirector(id);

                break;
            }

// Si escogen 3, mostramos la valoracion media de un director.
            case 3:
            {

                int id;
                cout << "Introduce el ID del director.\n";
                cin >> id;
                cout << menu_tree.getAverageValoracioOfDirector(id) << endl;

            }
                break;

// Si escogen 4, imprimimos por pantalla la base de datos de k en k elementos.
            case 4:
                menu_tree.showAllPelis();
                break;

// Si escogen 5, imprimimos por pantalla el identificador más grande.
            case 5:
                cout << "Identificador más grande: " << menu_tree.findLargestDirectorId() << endl;
                break;

// Si escogen 6, imprimimos por pantalla el identificador más pequeño no asignado.
            case 6:
                cout << "Identificador más pequeño no asignado: " << menu_tree.findSmallestNotTakenDirectorId() << endl;
                break;

// Si escogen 7, buscaremos añadir una peli a un director.
            case 7:
                menu_tree.addPeli();
                break;

// Si escogen 8, editaremos la estrategia de inserción.
            case 8:
            {
                int strategy_selected = -1;
                cout << "¿Desea introducir después del identificador más grande (0) o el identificador más pequeño (1)?: " << endl;
                while (strategy_selected < 0 || strategy_selected > 1) cin >> strategy_selected;
                
                if (strategy_selected == 0) menu_tree.setStrategy(MubiesflixBST::AFTER_LARGEST_ID);
                else menu_tree.setStrategy(MubiesflixBST::SMALLEST_NOTTAKEN_ID);
                break;
            }
            
// Si escogen cualquier otro valor, señalamos que nos den un valor correcto.
            case -1:
                cout << "Introduce un valor válido (entre 1 y 9)." << endl;
                break;

        }

    } while (option != 9);
}

int main () {
    mainExercici1();
    mainExercici2();

    test_exercici5("pelis-petit.csv");
    test_exercici5("pelis-gran.csv");

    menu();
    return 0;
}