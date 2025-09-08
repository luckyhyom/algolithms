#include <iostream>


class LinkedList {
    class Node {
        public:
        int data;
        Node* next = nullptr;
        Node(int data): data(data) {}
    };

    Node *head = nullptr;
    Node *currentNode = nullptr;
    public:
    LinkedList() {};

    void add(int data) {
        if(head == nullptr) {
            head = new Node(data);
            currentNode = head;
        } else {
            Node* nextNode = head;

            while (nextNode->next != nullptr) {
                nextNode = nextNode->next;
            }

            nextNode->next = new Node(data);
        }
    }

    // 계속 현재 위치의 원소를 기억해야하는건가? 아니면 head만 조회해서 사용하나?
    LinkedList* next() {
        if(currentNode == nullptr) {
            currentNode = head;
            return this;
        }
        currentNode = currentNode->next;
        return this;
    }

    int getValue() {
        if(currentNode == nullptr) {
            return 0;
        }
        return currentNode->data;
    }
};

int main() {
    LinkedList linkedList; 
    linkedList.add(1);
    linkedList.add(2);
    linkedList.add(3);

    std::cout << linkedList.getValue() << std::endl; // 1

    linkedList.next();
    std::cout << linkedList.getValue() << std::endl; // 2

    linkedList.next();
    std::cout << linkedList.getValue() << std::endl; // 3

    linkedList.next();
    std::cout << linkedList.getValue() << std::endl; // 0

    int data = linkedList.next()->next()->next()->getValue();
    std::cout << data << std::endl; // 3
    return 0;
}