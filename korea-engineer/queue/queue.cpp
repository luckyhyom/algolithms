#include <iostream>
#include <optional>

template <typename T>
class Queue {
    class Node {
       public:
        T data;
        Node* next;

        Node(T v) : data(v) {}
    };

    Node* head = nullptr;
    Node* tail = nullptr;

   public:
    Queue() {}

    void add(T v) {
        Node* new_node = new Node(v);
        if (head == nullptr) {
            this->head = new_node;
        } else {
            this->tail->next = new_node;
        }
        this->tail = new_node;
    }

    std::optional<T> remove() {
        if (this->head == nullptr) {
            return nullptr;
        }

        T result = this->head->data;
        Node* temp = this->head;

        this->head = this->head->next;
        delete temp;

        if (this->head == nullptr) {
            this->tail = nullptr;  // add에서 처리하고있긴 하지만 명시성을위해
        }

        return result;
    }

    std::optional<T> peek() {
        if (this->head == nullptr) {
            return nullptr;
        }
        return this->head->data;
    }

    bool isEmpty() { return this->head != nullptr ? 0 : 1; }
};