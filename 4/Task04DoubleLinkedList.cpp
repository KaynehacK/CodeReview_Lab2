#include "Task04DoubleLinkedList.h"

#include <iostream>

using namespace std;

DoubleLinkedList::~DoubleLinkedList() {
    if (!head) return;

    Node* current = head;
    while (true) {
        Node* temp = current;
        current = current->next;
        delete temp;
        if (current == head) break;
    }
}

void DoubleLinkedList::PushBack(int value) {
    Node* new_node = new Node(value);
    if (!head) {
        head = new_node;
        new_node->next = new_node;
        new_node->prev = new_node;
    } else {
        Node* tail = head->prev;
        tail->next = new_node;
        new_node->prev = tail;
        new_node->next = head;
        head->prev = new_node;
    }
}

void DoubleLinkedList::PrintList() const {
    if (!head) {
        cout << "Список пуст" << endl;
        return;
    }

    Node* current = head;
    while (true) {
        cout << current->data << " ";
        current = current->next;
        if (current == head) break;
    }
    cout << endl;
}

DoubleLinkedList::Node* DoubleLinkedList::DeleteNode(Node* node) {
    if (!node) return nullptr;

    if (node->next == node && node->prev == node) {
        if (node == head) head = nullptr;
        delete node;
        return nullptr;
    }

    Node* next_node = node->next;
    node->prev->next = node->next;
    node->next->prev = node->prev;

    if (node == head) head = next_node;

    delete node;
    return next_node;
}

DoubleLinkedList::Node* DoubleLinkedList::RemoveNodesWithEqualNeighbors() {
    if (!head) return nullptr;

    bool deletion_occurred;
    do {
        deletion_occurred = false;
        if (!head || head->next == head) break;

        Node* start = head;
        Node* current = head;
        bool completed_cycle = false;

        while (!completed_cycle) {
            int left_data = current->prev->data;
            int right_data = current->next->data;

            if (left_data == right_data) {
                deletion_occurred = true;
                Node* next_node = current->next;
                if (current == head) head = next_node;
                current = DeleteNode(current);
                if (!current) return nullptr;
                start = head;
                continue;
            } else {
                current = current->next;
            }

            if (current == start) completed_cycle = true;
        }
    } while (deletion_occurred);

    if (!head) return nullptr;
    return head->prev;
}