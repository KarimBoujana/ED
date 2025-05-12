/**
 * @author karim boujana.
 */

 #include <iostream>
 #include <vector>
 #include <fstream>
 #include "Peli.h"
 #include "QueueLinked.h"
 using namespace std;

 //Declaración de métodos.
 int choose_option();

 /**
* Pregunta y retorna la opción elegida por el usuario.
* @return opción elegida.
*/

int choose_option() {

    vector<string> vector_options = {"Llegir un fitxer amb les entrades de les pelis", "Eliminar una peli", "Inserir n entrades de pelis des de teclat (0 per finalitzar)", "Imprimir per pantalla la cua de pelis", "Sortir"};
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
    if (respuesta > 5 || respuesta < 0) respuesta = -1;
    
    return respuesta;

}


int main() {

    int option;
    QueueLinked<Peli> pelis;

    // Haremos este do while mientras no elijan la opción 5.
    do {

        option = choose_option(); // Vemos qué elige el usuario.
        // Si no escogen algo válido, se asigna el valor -1 y se le pide que introduzca un valor válido.
        switch (option) {

//Si escogen 1, leemos un fichero.
            case 1:
            {
                string path = "llista_pelis.txt"; // todo hacerlo dinamico.
              /*cout << "Introduce el camino del fichero.\n";
                cin >> cami; */

                ifstream file(path);

                if (file.is_open()) { 

                    string peliId;
                    string directorId;
                    string titol;
                    string durada;
                    string valoracio;

                    getline(file, peliId, '\n');
                    peliId = "";

                    while (file.good()) {
                        cout << "----------------------------------\n";
                        getline(file, peliId, '|');
                        int peliId_int = stoi(peliId);

                        getline(file, directorId, '|');
                        int directorId_int = stoi(directorId);

                        getline(file, titol, '|');
                        getline(file, durada, '|');
                        int durada_int = stoi(durada);

                        getline(file, valoracio);
                        float valoracio_float = stof(valoracio);

                        Peli peli(peliId_int, directorId_int, titol, durada_int, valoracio_float);
                        pelis.enqueue(peli);

                    }          
                                       
                }                

            }
                
                break;

// Si escogen 2, eliminamos una peli.
            case 2:

                try {
                    pelis.dequeue();
                } catch (string e) {
                    cout << e << endl;
                }
            
                break;

// Si escogen 3, introduciremos n películas hasta que nos digan basta.
            case 3:
            {

                int n = 1;
                int peliId;
                int directorId;
                string titol;
                int durada;
                float valoracio;

                do 
                {
                    
                    cout << "Introdueix el id de la peli: ";
                    cin >> peliId;

                    cout << "Introdueix el id del director: ";
                    cin >> directorId;


                    cout << "Introdueix el títol de la peli: ";
                    cin.ignore();
                    getline(cin, titol);

                    cout << "Introdueix la durada de la peli: ";
                    cin >> durada;

                    cout << "Introdueix la valoració de la peli: ";
                    cin >> valoracio;

                    Peli peli(peliId, directorId, titol, durada, valoracio);

                    pelis.enqueue(peli);

                    cout << "Vols introduir més pelis? (0 per finalitzar): ";
                    cin >> n;


                } while(n != 0);
                
            }
                break;

// Si escogen 4, imprimimos por pantalla toda la Cola.
            case 4:
                pelis.print();
                break;
            
// Si escogen cualquier otro valor, señalamos que nos den un valor correcto.
            case -1:
                cout << "Introdueix un valor vàlid." << endl;
                break;

        }

    } while (option != 5);

    return 0;
}