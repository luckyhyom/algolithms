#include <iostream>

class Queue {
    class Node {
       public:
        int data;
        Node* next;

        Node(int v) : data(v) {}
    };

    Node* head = nullptr;
    Node* tail = nullptr;

   public:
    Queue() {}

    void add(int v) {
        Node* new_node = new Node(v);
        if (head == nullptr) {
            this->head = new_node;
        } else {
            this->tail->next = new_node;
        }
        this->tail = new_node;
    }

    int remove() {
        if (this->head == nullptr) {
            return 0;
        }

        int result = this->head->data;
        Node* temp = this->head;

        this->head = this->head->next;
        delete temp;

        if (this->head == nullptr) {
            this->tail = nullptr;  // add에서 처리하고있긴 하지만 명시성을위해
        }

        return result;
    }

    int peek() {
        if (this->head == nullptr) {
            return 0;
        }
        return this->head->data;
    }

    bool isEmpty() { return this->head != nullptr ? 0 : 1; }
};