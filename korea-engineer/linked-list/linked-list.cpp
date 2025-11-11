#include "linked-list.h"

#include <iostream>

class LinkedList {
    class Node {
       public:
        int data;
        Node* next = nullptr;
        Node(int n) : data(n) {}
    };

    Node* header;

   public:
    LinkedList() { header = new Node(0); }

    void append(int n) {
        Node* last = header;
        while (last->next != nullptr) {
            last = last->next;
        }
        last->next = new Node(n);
    }

    void remove(int n) {
        Node* last = header;
        while (last->next != nullptr) {
            if (last->next->data == n) {
                Node* found = last->next;
                last->next = last->next->next;
                delete found;
            } else {
                last = last->next;
            }
        }
    }

    void retrieve() {
        Node* n = header;
        while (n->next != nullptr) {
            std::cout << n->next->data << std::endl;
            n = n->next;
        }
    }

    void removeDups() {
        Node* n = header;

        while (n != nullptr && n->next != nullptr) {
            Node* r = n;
            while (r->next != nullptr) {
                if (n->data == r->next->data) {
                    Node* found = r->next;
                    r->next = r->next->next;
                    delete found;
                } else {
                    r = r->next;
                }
            }
            n = n->next;
        }
    }

    void printKthFromEnd(int n) {
        if (n <= 0) {
            std::cout << "n shoud be lager than 0" << std::endl;
            return;
        }

        int count = 0;
        Node* result = kthFromEnd(header->next, n, &count);
        if (result == nullptr) {
            std::cout << "No Result" << std::endl;
        }
    }

   private:
    Node* kthFromEnd(Node* node, int n, int* count) {
        Node* result;
        if (node->next != nullptr) {
            result = kthFromEnd(node->next, n, count);

            if (result != nullptr) {
                return result;
            }
        }

        ++(*count);
        if (n == *count) {
            std::cout << node->data << std::endl;
            result = node;
        } else {
            result = nullptr;
        }

        return result;
    }
};

int main() {
    LinkedList ll;
    ll.append(1);
    ll.append(2);
    ll.append(3);
    ll.append(4);

    ll.printKthFromEnd(1);  // 4
    ll.printKthFromEnd(2);  // 3
    ll.printKthFromEnd(3);  // 2
    ll.printKthFromEnd(4);  // 1
    ll.printKthFromEnd(5);  // No Result
    ll.printKthFromEnd(0);  // n shoud be lager than 0
    return 0;
}
