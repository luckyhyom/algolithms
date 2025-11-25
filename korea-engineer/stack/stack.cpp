#include <iostream>

class Stack {
    // Node는 자료구조의 최소 단위의 요소이다. 인터페이스, 알고리즘에 따라 자료구조가 정의된다.
    class Node {
       public:
        int data;
        Node* next = nullptr;
        Node(int n) : data(n) {};
    };

    Node* head = nullptr;  // head는 진입점으로서 항상 필요하다.
    Node* top = nullptr;

   public:
    Stack() { this->head = new Node(0); }

    int pop() {
        if (this->top == nullptr) {
            return 0;
        }

        int result = this->top->data;
        Node* temp = this->top;
        this->top = this->top->next;
        delete temp;

        return result;
    }

    // *기존 노드를 새로운 노드의 다음 노드로 설정
    void push(int value) {
        Node* temp = this->top;
        this->top = new Node(value);
        this->top->next = temp;
    }

    int peek() {
        if (this->top == nullptr) {
            return 0;
        }
        return this->top->data;
    }

    bool isEmpty() { return this->top != nullptr ? 0 : 1; }
};

int main() {
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);

    std::cout << s.pop() << std::endl;
    std::cout << s.pop() << std::endl;
    std::cout << s.pop() << std::endl;
    std::cout << s.peek() << std::endl;
    std::cout << std::boolalpha << s.isEmpty() << std::endl;
    std::cout << s.pop() << std::endl;
    std::cout << s.isEmpty() << std::endl;
}