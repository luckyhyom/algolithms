#include <iostream>


template <typename T>
class LinkedList {
    class Node {
        public:
        T data;
        Node* next = nullptr;
        Node(T data): data(data) {}
    };

    Node *head = nullptr;
    Node *currentNode = nullptr;
    public:
    LinkedList() {};

    void add(T data) {
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

    LinkedList* next() {
        if(currentNode == nullptr) {
            currentNode = head;
            return this;
        }
        currentNode = currentNode->next;
        return this;
    }

    T getValue() {
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
        LinkedList<Node*> adjacent; // Node can be connected another nodes
    };

    LinkedList<Node*> nodes = new LinkedList<Node*>();

    public:

    Graph(int nodes_lenth) {}

    /**
     * How to add element
     * A) 
     * - add(A, B);
     * - add(B, C);
     * - add(C, A);
     * 
     * B) Sort
     * - add(A)
     * - add(B)
     * - add(C)
     * 
     * Q2. Tree has only one node as root. Graph has many nodes in list as member ?
     */

    // Task 1. 중복 검사를 위해 bfs 먼저 구현해야한다.
    void addEdge(int a, int b) {
        // 1. a를 검색한다.
        // 1-1. a가 없으면 a를 생성 후 리스트에 추가한다.
        // 3. b를 검색한다.
        // 3-1. b가 없으면 b를 생성 후 리스트에 추가한다.
        // 5. a와 b를 연결한다.
    }


    // Note: 작업을 중간에 멈추더라도 최소한 정리는 해야된다. 풀려는 문제가 뭐였고 중간 과정의 문제를 명확하게 정의해야한다! 정리를 해놔야 작업을 이어서 할 수 있고 기억에도 남는다. 그리고 글로 적어야 정리가 된다.
    
    // Task 2.
    void bfs(int a = 0) {
        // 매개변수와 같은 값을 가진 노드를 조회한다.

        // 해당 노드를 enqueue

        // 큐에서 노드 하나를 pop하고 프린트

        // pop한 노드의 인접 노드를 enqueue

        // 큐에서 노드 하나를 pop하고 프린트

        // pop한 노드의 인접 노드를 enqueue
    }
};

/**
 * node는 edge를 여러개 가질 수 있다.
 */

int main () {
    // interface 힌트 얻기 - 연결할 두개의 요소를 인자로 입력한다.
    Graph g = new Graph(9);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(3, 5);
    g.addEdge(5, 6);
    g.addEdge(5, 7);
    g.addEdge(6, 8);
    g.bfs(0);
    g.bfs(3);
    return 0;
}

/**
 * BFS(0)
 * 0 1 2 3 4 5 6 7 8
 * 
 * ------------------
 * 
 * BFS(3)
 * 3 1 2 4 5 0 6 7 8
 */