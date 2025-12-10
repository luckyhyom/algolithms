#include <vector>

#include "../../linked-list/linked-list.cpp"
#include "../../queue/queue.cpp"
#include "../../stack/stack.cpp"

template <typename T>
class Graph {
   public:
    class Node {
       public:
        T data;
        bool marked;
        LinkedList<Node*> adjacent;
        Node(T data) {
            this->data = data;
            this->marked = false;
        }
    };

    std::vector<Node*> nodes;

    Graph(int n) {
        for (size_t i = 0; i < n; i++) {
            nodes.push_back(new Node(i));
        }
    }

    void addEdge(int id1, int id2) {
        Node* n1 = nodes[id1];
        Node* n2 = nodes[id2];

        if (n1->adjacent.includes(n2) == false) {
            n1->adjacent.append(n2);
        }

        if (n2->adjacent.includes(n1) == false) {
            n2->adjacent.append(n1);
        }
    }

    void dfs() {
        Node* root = nodes[0];
        Stack<Node*> stack;
        stack.push(root);
        root->marked = true;
        while (stack.isEmpty() == false) {
            Node* poped = stack.pop();
            typename LinkedList<Node*>::Node* adjacent = poped->adjacent.header;
            while (adjacent->next != nullptr) {
                adjacent = adjacent->next;
                std::cout << poped->data << "'s " << "adjacent.." << adjacent->data->data << std::endl;
                if (adjacent->data->marked == false) {
                    adjacent->data->marked = true;
                    stack.push(adjacent->data);
                }
            }
            std::cout << poped->data << std::endl;
        }

        std::cout << " " << std::endl;
    }
};

/**
 *   0
 *  /
 * 1 -- 3    7
 * |  / | \ /
 * | /  |  5
 * 2 -- 4    \
 *            6 - 8
 */
int main() {
    Graph<int> g = Graph<int>(9);
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
    g.dfs();
}