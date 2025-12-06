#include <vector>

#include "../../linked-list/linked-list.cpp"
#include "../../queue/queue.cpp"

/**
 * CRUD
 *
 * Create
 * - 선택한 노드에 노드 추가
 *
 * Read
 * - 전체 순회
 *
 *
 * Node를 링크드리스트에..
 *
 * 1-2-3-4
 *
 * n-n-n-n
 *
 *
 * n-
 *
 *
 * data
 * n-n-n-n-n
 * data
 * n-n
 */

template <typename T>
class Graph {
   public:
    class Node {
       public:
        T data;

        /**
         * 머리에 그려지는 그래프의 간선
         *     o
         * 	   |
         * o - o - o
         *    / \
         *  o     o
         *
         * 링크드 리스트
         * o - o - o
         *
         * 그래서 뭔가 선형처럼 느껴짐..
         * 그러나 트리의 경우에도 두개의 node 포인터를 가지고있고, 이를 선형 데이터에 담아두어도 됨
         *
         * 링크드 리스트를 이용하여 만든 그래프의 실제 모양
         *
         *
         * 배열에 노드를 나열하고 링크드리스트로 관계를 표현한다. 리스트의 순서는 상관없다.
         * (a,c 사이에 간선은 1개이지만 실제로는 b를 조회해야 c를 조회할 수 있다.)
         *
         *        Array
         *[ a   b   c   d   e  f ]
         *  |   |   |   |   |
         *  b   d   o   o   o
         *  |   |   |   |   |
         *  c   e   o   o   o
         *
         *
         * a  -  b  -  c
         *       |  \
         *       d  -  e
         *             |
         *             f
         */
        LinkedList<Node*> adjacent;  // 그냥 node* next로 안하는 이유는.. 링크드리스트의 메서드때문에
        Node(T data) : data(data) {}
    };

    Node* node;

    Graph() { this->node = new Node(0); }

    void add(Node* n) { node->nodes.push_back(n) }
};

int main() {
    Graph<int> g;
    Graph<int>::Node* n1 = new Graph<int>::Node(1);
    Graph<int>::Node* n2 = new Graph<int>::Node(2);
    Graph<int>::Node* n3 = new Graph<int>::Node(3);
    Graph<int>::Node* n4 = new Graph<int>::Node(4);
    Graph<int>::Node* n5 = new Graph<int>::Node(5);
    Graph<int>::Node* n6 = new Graph<int>::Node(6);

    n1->nodes.push_back(1);
}