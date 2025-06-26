#include "Task03LinkedList.h"
#include <iostream>

using namespace std;

int Node::get_data() {
    return data;
}

LinkedList::~LinkedList() {
    ClearList();
}

void LinkedList::AddElement(int value) {
    Node* new_node = new Node(value);
    if (head == nullptr) {
        head = new_node;
    } else {
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = new_node;
    }
}

void LinkedList::InsertBeforeEverySecond(int m) {
    Node* current = head;
    int count = 1;

    while (current != nullptr && current->next != nullptr) {
        if (count % 2 == 1) {
            Node* new_node = new Node(m);
            new_node->next = current->next;
            current->next = new_node;
            current = new_node->next;
        } else {
            current = current->next;
        }
        count++;
    }
}

void LinkedList::PrintList() const {
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

Node* LinkedList::GetLastNode() const {
    Node* current = head;
    while (current != nullptr && current->next != nullptr) {
        current = current->next;
    }
    return current;
}

void LinkedList::ClearList() {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}