#include <iostream>

class LinkedList {
   public:
    class Node {
       public:
        int data;
        Node* next = nullptr;
        Node(int data) : data(data) {}
    };

    Node* head = nullptr;

    LinkedList() { head = new Node(0); }

    void append(int n) {
        Node* node = this->head;
        while (node->next != nullptr) {
            node = node->next;
        }

        node->next = new Node(n);
    }

    void remove(int n) {
        Node* node = this->head;
        while (node->next != nullptr) {
            if (node->next->data == n) {
                Node* found = node->next;
                node->next = node->next->next;
                delete found;
            } else {
                node = node->next;
            }
        }
    }

    void retrieve() {
        Node* node = this->head;
        while (node->next != nullptr) {
            std::cout << node->next->data << std::endl;  // h -> 1 -> 2 -> 3
            node = node->next;
        }
    }

    LinkedList::Node* get(int index) {
        Node* node = this->head;
        for (size_t i = 0; i < index; i++) {
            node = node->next;
        }
        return node;
    }
};

int main() {
    LinkedList ll;
    ll.append(1);
    ll.append(2);
    ll.append(3);
    ll.append(4);
    ll.retrieve();

    std::cout << ll.get(3)->data << std::endl;  // 3

    ll.remove(3);
    ll.retrieve();
    return 0;
}