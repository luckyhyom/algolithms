#include <iostream>
#include <optional>


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
    // currentNode가 nullptr일 경우 마지막 Node라는 의미다.
    LinkedList* next() {
        if(currentNode == nullptr) {
            return this;
        }
        currentNode = currentNode->next;
        return this;
    }

    // currentNode가 마지막 node에 도달하였을 경우 처음 Node로 초기화한다.
    LinkedList* setToHead() {
        currentNode = head;
        return this;
    }

    // std::optional 대신 pointer를 활용한다.
    T* getValue() {
        if(currentNode == nullptr) {
            return nullptr;
        }
        return &currentNode->data;
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
        public:
        int data;
        LinkedList<Node*> adjacent; // Node can be connected another nodes
        Node(int data): data(data) {
            adjacent = LinkedList<Node*>();
        };
    };

    LinkedList<Node*> nodes = LinkedList<Node*>();

    public:

    Graph(int nodes_lenth) {}

    void addEdge(int a, int b) {
        Node* node;
        Node* find_a = nullptr;
        Node* find_b = nullptr;
        if(nodes.getValue() != nullptr) {
            node = *(nodes.getValue()); // subtask 1) head Node를 조회할 수 있도록 개선할 것? 애초에 데이터만 조회가 가능한가..
        } else {
            find_a = new Node(a);
            nodes.add(find_a);
        }

        // 1. a를 검색한다.
        while (node != nullptr) {
            if(node->data == a) {
                find_a = node;
                break;
            }

            if(nodes.next()->getValue() != nullptr) {
                node = *(nodes.getValue()); // subtask) nullptr이므로 접근하면 오류 발생, 더 나은 코드는?
            } else {
                node = nullptr;
            }
        }

        node = *nodes.setToHead()->getValue();
        // 1-1. a가 없으면 a를 생성 후 리스트에 추가한다.
        if(find_a == nullptr) {
            find_a = new Node(a);
            nodes.add(find_a);
        }

        // 3. b를 검색한다.
        while (node != nullptr) {
            if(node->data == b) {
                find_b = node;
                break;
            }
            if(nodes.next()->getValue() != nullptr) {
                node = *(nodes.getValue());
            } else {
                node = nullptr;
            }
        }

        // 3-1. b가 없으면 b를 생성 후 리스트에 추가한다.
        if(find_b == nullptr) {
            find_b = new Node(b);
            nodes.add(find_b);
        }

        // 5. a와 b를 연결한다.
        find_a->adjacent.add(find_b);
        find_b->adjacent.add(find_a);

        // reset current node
        nodes.setToHead();
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
    Graph* g = new Graph(9);
    g->addEdge(0, 1);
    g->addEdge(1, 2);
    g->addEdge(1, 3);
    g->addEdge(2, 4);
    g->addEdge(2, 3);
    g->addEdge(3, 4);
    g->addEdge(3, 5);
    g->addEdge(5, 6);
    g->addEdge(5, 7);
    g->addEdge(6, 8);
    g->bfs(0);
    g->bfs(3);
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