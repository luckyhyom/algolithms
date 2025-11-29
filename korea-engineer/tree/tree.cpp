#include <iostream>

template <typename T>
class Tree {
   public:
    class Node {
       public:
        T data;
        Node* left;
        Node* right;
        Node(T data) : data(data) {}
    };

    Node* root = nullptr;

    Tree() {}

    void setRoot(Node* node) { this->root = node; }

    Node* getRoot() { return this->root; }

    Node* makeNode(Node* left, T value, Node* right) {
        Node* node = new Node(value);
        node->left = left;
        node->right = right;
        return node;
    }

    void inorder(Node* node) {
        if (node == nullptr) {
            return;
        }
        inorder(node->left);
        std::cout << node->data << std::endl;
        inorder(node->right);
    }

    void preorder(Node* node) {
        if (node == nullptr) {
            return;
        }
        std::cout << node->data << std::endl;
        preorder(node->left);
        preorder(node->right);
    }

    void postorder(Node* node) {
        if (node == nullptr) {
            return;
        }
        postorder(node->left);
        postorder(node->right);
        std::cout << node->data << std::endl;
    }
};

/**
 *     1
 *   2   3
 * 4  5
 *
 * Inorder (Left, Root, Right): 4 2 5 1 3
 * Preorder (Root, Left, Right): 1 2 4 5 3
 * Postorder (Left, Right, Root): 4 5 2 3 1
 */
int main() {
    Tree<int> t;
    Tree<int>::Node* n4 = t.makeNode(nullptr, 4, nullptr);
    Tree<int>::Node* n5 = t.makeNode(nullptr, 5, nullptr);
    Tree<int>::Node* n2 = t.makeNode(n4, 2, n5);
    Tree<int>::Node* n3 = t.makeNode(nullptr, 3, nullptr);
    Tree<int>::Node* n1 = t.makeNode(n2, 1, n3);

    t.setRoot(n1);
    t.inorder(t.getRoot());
    t.preorder(t.getRoot());
    t.postorder(t.getRoot());

    return 0;
}

/**
 * 영상에서 코드 구현까지 봐버려서..
 * 노트에 그려보며 이해 하려고 하긴했는데
 * 스스로 처음부터 생각하지 않아서 제대로 이해 못했을 것 같은 느낌이다.
 *
 * 1. 설명 이해
 * 2. 알고리즘 구현 (재귀)
 * 3. Node는 어떤식으로 생성해야할지
 *
 * 근데 이해 못했으면 언젠가는 막힐거고 그때 가서 다시 이해하면 되겠지 뭐..
 */