#ifndef LAB2_TASK04DOUBLELINKEDLIST_H
#define LAB2_TASK04DOUBLELINKEDLIST_H

#include <iostream>

class DoubleLinkedList {
    public:
        struct Node {
            int data;
            Node* next;
            Node* prev;
            Node(int val) : data(val), next(nullptr), prev(nullptr) {}
        };

    private:
        Node* head;

    public:
        DoubleLinkedList() : head(nullptr) {}
        ~DoubleLinkedList();

        void PushBack(int value);
        void PrintList() const;
        Node* DeleteNode(Node* node);
        Node* RemoveNodesWithEqualNeighbors();
};

#endif //LAB2_TASK04DOUBLELINKEDLIST_H
