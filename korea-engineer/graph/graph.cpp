#include <iostream>

/**
 * Graph가 Node를 하나 가지고 있고..
 * 
 * 1. 시작 노드를 마음대로 정할 수 있는건가? 처음에 정해놓고.. 다르면 찾아서 시작해야하는거겠지?
 * 
 * 2. Node를 추가하는 방법은?
 * - A와 B,C,D 연결, C에 E연결.. -> 이름은 변수로? 혹은 멤버변수?
 * 
 */


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

template <typename T>
class Queue {
    class Node {
    public:
        T data;
        Node* next;
        // Note: Reference 복습
        Node(const T data): data(data), next(nullptr) {}
    };
    Node *first;
    Node *last;

    public:
        Queue() : first(nullptr), last(nullptr) {}   // ← 추가: 초기화
        void add(T data) {
            Node *newNode = new Node(data);
            // 첫번째 node일 경우 last의 next는 설정하지 않는다.
            if(this->first == nullptr) {
                this->first = newNode;
                this->last = newNode;
                return;
            }

            /**
             * Note: 이 두 라인의 순서가 바뀌면 안된다. 방어로직을 짤 수 있을까?
             */
            this->last->next = newNode;
            this->last = newNode;
        }

        /**
         * first를 바로 다음 Node로 교체해야한다.
         * Node가 자신의 앞, 뒤 Node를 알고 있다면 Queue가 모든 Node를 알고 있지 않아도 된다.
         * 
         * Note:
         *  Node의 개수가 고정되어 있지 않다.
         */
        void remove() {
            if (this->first == nullptr) { throw "Queue is already Empty."; }
            Node* old = this->first;
            this->first = this->first->next;
            if (this->first == nullptr) this->last = nullptr; // 마지막 제거 시 정리
            delete old;
        }

        T peek() {
            if (this->first == nullptr) { throw "Queue is Empty"; }
            return this->first->data;
        }

        bool isEmpty() {
            return this->first == nullptr;
        }
};


class Graph {
    class Node {
        int data;
        LinkedList<Node*> adjacent;
    };

    public:
    
    /**
     * Q1. 요소를 어떻게 추가하지?
     * 
     * A) 임의의 요소에 추가 A,B,C가 있을때 B에 D를 추가하고싶다..
     * B) 요소 추가 시 자동 정렬
     * 
     * Q2. node가 root로서 1개면 tree, node가 list로 정의되어있으면 그래프?
     * 
     */
    void add() {

    }

    void BFS() {

    }
};

/**
 * node는 edge를 여러개 가질 수 있다.
 */

int main () {
    return 0;
}