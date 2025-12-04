#include "./complete-binary-tree.cpp"

template <typename T>
class MinHeap : public CompleteBinaryTree<T> {
   public:
    void add(T value) {
        CompleteBinaryTree<T>::add(value);
        this->sort(this->root);
    }

    /**
     * 재귀로 트리 순회 시 노드의 갯수만큼 함수 호출이 스택에 쌓이는 것이 아니다. 최대 레벨만큼만 쌓인다. 즉, 각 Leaf 노드에 도착한 시점이 최대이고 이후로 스택에서 제거되기 때문이다.
     * -> 재귀를 통해 전체 노드에 대하여 추가된 역순으로 알고리즘 실행이 불가능하다.
     * -> Queue&Stack 자료구조를 추가해서 BFS로 하면 가능하다.
     * 허나 가장 효율적인건.. 추가된 노드부터 시작하여 수직으로만 비교하는 것
     * 좌/우 정렬된 트리(BST)면 루트부터 추가된 노드까지 바로 순차적 접근 가능
     * Min Heap은 좌/우가 아닌 레벨을 기준으로 정렬이 되어있다.
     *
     * Postorder 순서로 조회해야 순서로 조회해야한다.
     * 루트 노드와 자식 노드의 값 비교 연산이 마지막에 이루어져야한다. (자식 노드들이 최종 정렬된 값이어야하므로.)
     */
    void sort(typename CompleteBinaryTree<T>::Node* node) {
        if (node == nullptr) {
            return;
        }
        sort(node->left);
        sort(node->right);

        if (node->left != nullptr) {
            if (node->data > node->left->data) {
                T temp = node->data;
                node->data = node->left->data;
                node->left->data = temp;
            }
        }

        if (node->right != nullptr) {
            if (node->data > node->right->data) {
                T temp = node->data;
                node->data = node->right->data;
                node->right->data = temp;
            }
        }
    }

    /**
     * 우와 Tree 구조로 min heap을 구현하려니까 엄청 번거롭네!
     * pop하려면 마지막에 추가된 노드를 조회해야하는데 마지막에 추가된 노드를 조회하는게 간단하지 않네!
     */
    T pop() {
        typename CompleteBinaryTree<T>::Node* left = this->root->left;
        typename CompleteBinaryTree<T>::Node* right = this->root->right;
        T result = this->root->data;

        typename CompleteBinaryTree<T>::Node* last_parent = this->getInsertionParent(this->root);
        typename CompleteBinaryTree<T>::Node* last_node = this->getInsertionParent(this->root);
        if (last_parent->right != nullptr) {
        }

        return 0;
    }
};

int main() {
    MinHeap<int> t;
    t.add(10);
    t.add(3);
    t.add(2);
    t.add(4);
    t.add(5);
    t.add(1);
    t.printPreorder(t.root);

    // std::cout << t.top_level << std::endl;
    return 0;
}