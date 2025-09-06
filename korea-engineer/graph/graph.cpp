#include "../algolithms-1/korea-engineer/queue/queue.cpp"

/**
 * Graph가 Node를 하나 가지고 있고..
 * 
 * 1. 시작 노드를 마음대로 정할 수 있는건가? 처음에 정해놓고.. 다르면 찾아서 시작해야하는거겠지?
 * 
 * 2. Node를 추가하는 방법은?
 * - A와 B,C,D 연결, C에 E연결.. -> 이름은 변수로? 혹은 멤버변수?
 * 
 */




class Graph {
    class Node {
        /**
         * @brief
         * 이름..?
         */
        int data;

        /**
         * Node가 몇개일지 모르므로 List로 선언
         */
        Node *adjacent; // LinkedList<Node*> adjacent;
    };

    Node* first;

    void add(Node* new_node, Node* target) {
        Node* a;
        Node* b;
        Node* c;
        Node* d;
        Node* e;

        a->adjacent = b;
        a->adjacent = c;
        a->adjacent = d;
        c->adjacent = e;
        //new_node
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