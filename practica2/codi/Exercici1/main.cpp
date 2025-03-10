/**
 * @author karim boujana.
 */

 #include <iostream>
 #include <vector>
 #include "QueueStatic.h"
 using namespace std;

 //Declaración de métodos.
 int choose_option();

 /**
* Pregunta y retorna la opción elegida por el usuario.
* @return opción elegida.
*/
int choose_option() {

    vector<string> vector_options = {"Inserir element a la QueueStatic", "Treure element de la QueueStatic", "Consultar el primer element de la QueueStatic", "Imprimir tot el contingut de la QueueStatic", "Imprimir les posicions del front i el rear", "Sortir"};
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
    if (respuesta > 6 || respuesta < 0) respuesta = -1;
    
    return respuesta;

}

void casProva1() {

    QueueStatic queue(3);
    queue.enqueue(10);
    queue.enqueue(20);
    queue.printFrontRear();
    queue.enqueue(30);

    try {
        queue.enqueue(40);
    } catch (string e) {
        cout << e << endl;
    }
    
    queue.print();
    queue.printFrontRear();
    queue.dequeue();
    queue.enqueue(50);
    queue.print();
    queue.printFrontRear();

}

void casProva2() {
    
    QueueStatic queue(3);
    queue.enqueue(10);
    queue.getFront();
    queue.enqueue(20);
    queue.enqueue(30);
    queue.print();
    queue.printFrontRear();
    queue.dequeue();
    queue.getFront();
    queue.dequeue();
    queue.printFrontRear();
    queue.dequeue();

    try {
        queue.dequeue();
    } catch (string e) {
        cout << e << endl;
    }
    
    queue.print();
    queue.printFrontRear();

}

int main() {

    casProva1();
    cout << "-----------------------------\n";
    casProva2();
    cout << "-----------------------------\n";

    // Inicializamos las variables pertinentes.
    int option;
    const int MAX_ELEMENTS = 3;
    QueueStatic queue(MAX_ELEMENTS);

    // Haremos este do while mientras no elijan la opción 6.
    do {

        option = choose_option(); // Vemos qué elige el usuario.
        // Si no escogen algo válido, se asigna el valor -1 y se le pide que introduzca un valor válido.
        switch (option) {

//Si escogen 1, añadimos un elemento a la Cola.
            case 1:
                int key;
                cin >> key;

                try {
                    queue.enqueue(key);
                } catch (string e) {
                    cout << e << endl;
                }
                
                break;

// Si escogen 2, eliminamos uno.
            case 2:
                try {
                    queue.dequeue();
                } catch (string e) {
                    cout << e << endl;
                }
            break;

// Si escogen 3, consultamos el primer elemento de la Cola.
            case 3:
                cout << queue.getFront() << endl;
                break;

// Si escogen 4, imprimimos por pantalla toda la Cola.
            case 4:
                queue.print();
                break;

// Si escogen 5, imprimimos las posiciones del front y el rear.
            case 5:
                queue.printFrontRear();
                break;
            
// Si escogen cualquier otro valor, señalamos que nos den un valor correcto.
            case -1:
                cout << "Introduce un valor apropiado." << endl;
                break;

        }

    } while (option != 6);

    return 0;
}