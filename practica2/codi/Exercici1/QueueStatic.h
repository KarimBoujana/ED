#ifndef QUEUESTATIC_H
#define QUEUESTATIC_H

class QueueStatic {
    public:
        QueueStatic(const int max_size); //hecho
        virtual ~QueueStatic(); //TODO:CONSTRUCTOR.
        void enqueue(const int key); //hecho
        void dequeue(); //hecho
        bool isFull(); //hecho
        bool isEmpty(); //hecho
        void print(); //hecho
        const int getFront(); //hecho
        void printFrontRear(); //hecho

    private:
        int _max_elements;
        int _num_elements;
        int _first;
        int _last;
        int* _content;
};

#endif /* QUEUESTATIC_H */

/*
    - Quina condició hem d’imposar en una cua estàtica no circular per comprovar si està plena?
        Aquesta condició és suficient en el cas de ser circular?

        Si la cola no es circular, solo debemos ver que _first == _max_elements, pues significa que hay menos elementos que el máximo.
        No sería suficiente en el caso de ser circular. Pongamos un array de cinco elementos, y sea F el índice respectivo, 0 es vacío y 1 con un elemento:
        [(F), 0, 0, 0, 0], según el cálculo anterior es correcto, pues toda la lista está vacía, y F != 5, y por tanto no está llena.
        Sin embargo [1 (F), 1, 1, 1, 1] está llena, y debido a la implementación circulas, F acaban en el mismo índice. Si hacemos el mismo cálculo,
        tenemos que F != 5, y concluiríamos que no está llena.

    - La variable _max_elements és necessària en el cas de ser una cua no circular? Per a què utilitzem aquesta variable per les cues circulars?
        Sí, lo necesitamos para comprobar que _first == _max_elements.
        En las colas circulares lo necesitamos para comprobar si _num_elements == _max_elements, en cuyo caso está llena.


*/