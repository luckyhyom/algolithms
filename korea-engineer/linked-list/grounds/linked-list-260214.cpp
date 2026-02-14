#include <bits/stdc++.h>

using namespace std;

class Node {
   public:
    int data = 0;
    Node* next = nullptr;
    Node(int data) : data(data) {}

    void add(int data) {
        if (this->next == nullptr) {
            this->next = new Node(data);
            return;
        }

        Node* next = this->next;

        while (next->next != nullptr) {
            next = next->next;
        }

        next->next = new Node(data);
    }

    void print() {
        Node* node = this;
        while (node != nullptr) {
            cout << node->data << " ";
            node = node->next;
        }
    }
};

// header가 없으면?

int main() {
    Node n1(1);
    n1.add(2);
    n1.add(3);
    n1.print();
    return 0;
}