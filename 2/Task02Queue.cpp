#include "Task02Queue.h"
#include <iostream>
#include <cstdlib>

using namespace std;

Queue::~Queue() {
    while (!IsEmpty()) {
        Dequeue();
    }
}

void Queue::Enqueue(int value) {
    Node* new_node = new Node(value);
    if (!new_node) {
        cerr << "Ошибка выделения памяти" << endl;
        exit(EXIT_FAILURE);
    }

    if (last) {
        last->next = new_node;
    } else {
        front = new_node;
    }
    last = new_node;
}

int Queue::Dequeue() {
    if (IsEmpty()) {
        cerr << "Попытка извлечь элемент из пустой очереди" << endl;
        return -1;
    }

    Node* temp = front;
    int value = temp->data;
    front = front->next;

    if (!front) {
        last = nullptr;
    }

    delete temp;
    return value;
}

bool Queue::IsEmpty() const {
    return front == nullptr;
}

void Queue::Print() const {
    Node* current = front;
    while (current) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

void Queue::PrintAddresses() const {
    cout << "Адрес начала очереди: " << front;
    if (front) {
        cout << ", значение: " << front->data;
    }
    cout << endl;

    cout << "Адрес конца очереди: " << last;
    if (last) {
        cout << ", значение: " << last->data;
    }
    cout << endl;
}

int Queue::get_front_value() const {
    if (IsEmpty()) {
        cerr << "Очередь пуста" << endl;
        return -1;
    }
    return front->data;
}

int Queue::get_last_value() const {
    if (IsEmpty()) {
        cerr << "Очередь пуста" << endl;
        return -1;
    }
    return last->data;
}