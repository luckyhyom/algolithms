#include <iostream>

class Queue {
   public:
    class Node {
       public:
        int data;
        Node* next;
        Node(int data) : data(data), next(nullptr) {}
    };

    // front는 처음에 초기화하여 고정해야하는가? ❌
    Node* front;
    Node* rear;

    Queue() {
        front = nullptr;
        rear = nullptr;
    }

    void eunqueue(int value) {
        if (this->front == nullptr) {
            this->front = rear = new Node(value);
            return;
        }

        // rear 변수를 활용하여 마지막 노드를 찾는 순회 과정 생략
        rear->next = new Node(value);
        rear = rear->next;
    }

    int dequeue() {
        Node* temp = this->front;
        this->front = temp->next;
        int result = temp->data;
        delete temp;
        return result;
    }

    void print() {
        Node* temp = this->front;
        while (temp != nullptr) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }
};

int main() {
    Queue q;
    q.eunqueue(1);
    q.eunqueue(2);
    q.eunqueue(3);
    q.print();
    q.dequeue();
    q.print();
    q.dequeue();
    q.print();
    q.dequeue();
    q.print();
    return 0;
}