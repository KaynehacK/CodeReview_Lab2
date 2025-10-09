#ifndef LAB2_TASK01STACK_H
#define LAB2_TASK01STACK_H

#include <iostream>

class TNode {
    private:
        int data;
        TNode* next;

    public:
        TNode(int d) : data(d), next(nullptr) {}
        friend class Stack;
};

class Stack {
    private:
        TNode* top;

    public:
        Stack() : top(nullptr) {}
        void push(int d);
        void pop();
        void Show() const;
        void ShowAddress() const;
        int get() const;
        bool IsEmpty() const;
};

#endif //LAB2_TASK01STACK_H
