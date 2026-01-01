#include <iostream>
#include <vector>

/**
 * Q. 정렬된 배열을 Binary Search Tree로 만드시오
 */
class Tree {
   public:
    class Node {
       public:
        int data;
        Node* left = nullptr;
        Node* right = nullptr;
        Node(int data) : data(data) {}
    };

    Node* root = nullptr;

    Tree() {}

    void makeTree(std::vector<int> a) { this->root = makeTreeR(a, 0, a.size() - 1); }

    Node* makeTreeR(std::vector<int> a, int start, int end) {
        if (start > end) {
            return nullptr;
        }

        int mid = (start + end) / 2;  // 중간 값 계산식!
        Node* node = new Node(a[mid]);
        node->left = makeTreeR(a, start, mid - 1);
        node->right = makeTreeR(a, mid + 1, end);

        return node;
    }

    void search(Node* node, int n) {
        if (node == nullptr) {
            std::cout << "not find!" << std::endl;
        }
        if (node->data > n) {
            std::cout << "Data is smaller than " << node->data << std::endl;
            search(node->left, n);
        } else if (node->data < n) {
            std::cout << "Data is bigger than " << node->data << std::endl;
            search(node->right, n);
        } else if (node->data == n) {
            std::cout << node->data << ".. data found!" << std::endl;
        } else {
            std::cout << "not find!" << std::endl;
        }
    }
};

/**
 * [0,1,2,3,4,5,6,7,8,9]
 *
 * 트리
 *            4
 *       1          7
 *     0   2      5    8
 *           3      6    9
 */
int main() {
    Tree t;
    std::vector<int> arr(10);
    int v = 0;

    // 배열에 0~9까지 값을 채우기
    for (auto&& i : arr) {
        i = v;
        v++;
    }

    t.makeTree(arr);
    t.search(t.root, 7);
    return 0;
}