#ifndef LAB2_TASK02QUEUE_H
#define LAB2_TASK02QUEUE_H

#include <iostream>

struct Node {
    int data;
    Node* next;
    Node(int d) : data(d), next(nullptr) {}
};

class Queue {
    private:
        Node* front;
        Node* last;

    public:
        Queue() : front(nullptr), last(nullptr) {}
        ~Queue();

        void Enqueue(int value);
        int Dequeue();
        bool IsEmpty() const;
        void Print() const;
        void PrintAddresses() const;
        int get_front_value() const;
        int get_last_value() const;
};

#endif //LAB2_TASK02QUEUE_H
