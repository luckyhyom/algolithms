/**
 * @date 250907
 */

#include <iostream>

class Node {
    public:
    int data;
    Node* next = nullptr;
    Node(int data): data(data) {}
    void addNext(Node *node) {
        next = node;
    }
};

int main() {
    Node* head = new Node(1);
    Node* b = new Node(2);
    Node* c = new Node(3);
    head->addNext(b);
    head->addNext(c);
    std::cout << head->next->data << std::endl;
    return 0;
}