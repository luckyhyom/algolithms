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

    void dfs() { dfs(0); }
    void dfs(int index) {
        Node* root = this->nodes[index];
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
    /**
     * - 재귀를 한다.
     * - 출력을 먼저 한다.
     * - 자식 노드를 인자로 넣는다.
     * - nullptr이면 멈춘다.
     *
     * dfs(N node) {
     * if(node = nullptr ) {
     * return
     * }
     * 	cout << node.data;
     *
     * 	child = node.child
     *
     * while(child != nullptr) (
     * 		if(child->next->marked == false)
     *		dfs(child->next)
     * )
     * }
     *
     */
    void dfsRecursion(Node* node) {
        if (node == nullptr) {
            return;
        }
        node->marked = true;
        std::cout << node->data << std::endl;

        typename LinkedList<Node*>::Node* adjacent = node->adjacent.header;
        while (adjacent->next != nullptr) {
            adjacent = adjacent->next;
            if (adjacent->data->marked == false) {
                dfsRecursion(adjacent->data);
            }
        }
    }

    void bfs() {
        Node* root = this->nodes[0];
        Queue<Node*> queue;
        queue.add(root);
        root->marked = true;

        while (queue.isEmpty() == false) {
            std::optional<Node*> optNode = queue.remove();

            if (!optNode.has_value()) {
                continue;
            }

            Node* node = optNode.value();

            // LinkedList 마지막 노드까지 순회할 수 있는 기능 필요
            typename LinkedList<Node*>::Node* adjacent = node->adjacent.header;
            while (adjacent->next != nullptr) {
                adjacent = adjacent->next;
                std::cout << node->data << "'s " << "adjacent.." << adjacent->data->data << std::endl;
                if (adjacent->data->marked == false) {
                    adjacent->data->marked = true;
                    queue.add(adjacent->data);
                }
            }

            std::cout << node->data << std::endl;
        }
    }
};
