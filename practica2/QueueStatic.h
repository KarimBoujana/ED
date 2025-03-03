#ifndef QUEUESTATIC_H
#define QUEUESTATIC_H

class QueueStatic {
    public:
        QueueStatic(const int max_size);
        virtual ~QueueStatic();
        void enqueue(const int key);
        void dequeue();
        bool isFull();
        bool isEmpty();
        void print();
        const int getFront();
        void printFrontRear();

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


    - La variable _max_elements és necessària en el cas de ser una cua no circular? Per a què utilitzem aquesta variable per les cues circulars?
*/