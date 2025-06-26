#ifndef LAB2_TASK03LINKEDLIST_H
#define LAB2_TASK03LINKEDLIST_H

#include <iostream>

class Node {
    private:
        int data;
        Node* next;
        friend class LinkedList;

    public:
        Node(int value) : data(value), next(nullptr) {}
        get_data();
};

class LinkedList {
    private:
        Node* head;

    public:
        LinkedList() : head(nullptr) {}
        ~LinkedList();

        void AddElement(int value);
        void InsertBeforeEverySecond(int m);
        void PrintList() const;
        Node* GetLastNode() const;
        void ClearList();
};

#endif //LAB2_TASK03LINKEDLIST_H
