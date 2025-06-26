#include "Task01Stack.h"
#include <iostream>
#include <cstdlib>

using namespace std;

void Stack::push(int d) {
    TNode* new_node = new TNode(d);
    if (!new_node) {
        cerr << "Ошибка выделения памяти" << endl;
        exit(EXIT_FAILURE);
    }
    new_node->next = top;
    top = new_node;
}

void Stack::pop() {
    if (IsEmpty()) {
        cerr << "Попытка извлечь элемент из пустого стека" << endl;
        return;
    }
    TNode* temp = top;
    top = top->next;
    delete temp;
}

void Stack::Show() const {
    TNode* current = top;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

void Stack::ShowAddress() const {
    cout << "Адрес вершины стека: " << top << endl;
}

int Stack::get() const {
    if (IsEmpty()) {
        cerr << "Стек пуст" << endl;
        return -1;
    }
    return top->data;
}

bool Stack::IsEmpty() const {
    return top == nullptr;
}