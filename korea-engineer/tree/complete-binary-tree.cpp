#include <iostream>

template <typename T>
class CompleteBinaryTree {
   public:
    class Node {
       public:
        T data;
        Node* left;
        Node* right;
        int level;
        Node(T value) {
            this->left = nullptr;
            this->right = nullptr;
            this->data = value;
        }
    };

    Node* root = nullptr;
    int top_level = 0;

    CompleteBinaryTree() {}

    /**
     * 마지막 노드에 추가하고 부모와 값 비교하며 전체 정렬
     * ---
     * 완전 이진 트리 (Complete Binary Tree..)
     * A Inorder로 왼쪽부터 검사하면서 최고 레벨보다 레벨이 낮은데 왼쪽 노드가 없으면 추가
     * B 왼쪽 노드가 있는데 오른쪽 노드가 없으면 추가
     * C 만약 Perfect Binary Tree라면?
     * 		- 왼쪽에서 생성 못하고 (A,B 만족 못함)
     * 		- 오른쪽에서 생성 못하고 (A,B 만족 못함)
     * 		- 다음 라인으로 넘어오면 PBT!
     * D 최고 레벨은 새로운 노드가 생길 때 갱신
     */
    void add(T value) {
        if (this->root == nullptr) {
            this->root = new Node(value);
            this->root->level = 0;
            return;
        }

        Node* last_node = this->getLast(this->root);
        this->addChild(last_node, value);
    }

    void addChild(Node* node, T value) {
        Node* new_node = new Node(value);
        new_node->level = node->level + 1;
        if (node->left == nullptr) {
            node->left = new_node;
        } else {
            node->right = new_node;
        }

        // D) 최고 레벨은 새로운 노드가 생길 때 갱신
        top_level = new_node->level;
    }

    Node* getLast(Node* node) {
        Node* n = preorder(node);
        if (n != nullptr) {
            return n;
        }

        /**
         * C) 만약 Perfect Binary Tree라면?
         *  - 왼쪽에서 생성 못하고 (A,B 만족 못함)
         * 	- 오른쪽에서 생성 못하고 (A,B 만족 못함)
         * 	- 다음 라인으로 넘어오면 PBT!
         */
        return getLeftTail(node);
    }

    Node* getLeftTail(Node* node) {
        if (node->left == nullptr) {
            return node;
        }
        return getLeftTail(node->left);
    }

    Node* preorder(Node* node) {
        if (node == nullptr) {
            return nullptr;
        }

        // A) Inorder로 왼쪽부터 검사하면서 최고 레벨보다 레벨이 낮은데 왼쪽 노드가 없으면 추가
        if (node->level < this->top_level && node->left == nullptr) {
            return node;
        }

        // B) 왼쪽 노드가 있는데 오른쪽 노드가 없으면 추가
        if (node->left != nullptr && node->right == nullptr) {
            return node;
        }

        // 왼쪽 노드의 마지막 노드 탐색
        Node* left_node = preorder(node->left);
        if (left_node != nullptr) {
            return left_node;
        }

        // 왼쪽 노드의 끝에서 올라가며 오른쪽 노드 탐색
        Node* right_node = preorder(node->right);
        if (right_node != nullptr) {
            return right_node;
        }

        return nullptr;
    }

    void printPreorder(Node* node) {
        if (node == nullptr) {
            return;
        }
        std::cout << node->data << std::endl;
        printPreorder(node->left);
        printPreorder(node->right);
    }

    // 마지막 노드를 루트로 바꾸고 루트부터 자식 노드와 비교 (배열의 중간에 원소를 삽입해서 기존 원소를 밀어내는 것과 유사한 느낌)
};

int main() {
    CompleteBinaryTree<int> t;
    t.add(1);
    t.add(2);
    t.add(3);
    t.add(4);
    t.add(5);
    t.add(6);
    t.printPreorder(t.root);
    /**
     * 완전 트리라면..
     *        (1)
     *    (2)     (3)
     *  (4) (5) (6)
     *
     * 출력 순서는.. 124536
     */

    std::cout << t.top_level << std::endl;
    return 0;
}