#include "./complete-binary-tree.cpp"

template <typename T>
class MinHeap : public CompleteBinaryTree<T> {
   public:
    void add(T value) {
        // CompleteBinaryTree<T>::add(value);
        typename CompleteBinaryTree<T>::Node* tem;
        // = this->preorder(this->root);
        // if (isCompleteTree != nullptr) {
        // } else {
        // }
    }

    // CompleteBinaryTree일경우

    /**
     * 일단 현재 구현된 자료구조가 정렬 알고리즘을 구현하기 불리한 구조일수도 있다.
     *
     * add했을 때 정렬하기
     * 1. 새로운 노드가 추가되며 부모 노드와 값을 비교한다.
     * 2. 부모 노드의 데이터 값이 더 크면 모든 데이터를 복사하여 스왑한다.
     * (부모의 부모 포인터가 있다면 데이터 복사 없이 포인터만 스왑 가능하지만 마지막 루트노드에서 자식 노드와 비교하는 것이 좀 복잡할 것 같다.)
     *
     * pop했을 때 정렬하기
     */
    void sortTreeFromLeft(typename CompleteBinaryTree<T>::Node* node, typename CompleteBinaryTree<T>::Node* new_node) {
        if (node == nullptr) {
            return;
        }

        sortTreeFromLeft(node->left);

        if (node->left == nullptr) {
            node->left = new_node;
        }

        if (node->data > node->left->data) {
            T temp_data = node->data;
            node->data = node->left->data;
            node->left->data = temp_data;
        }
    }

    /**
     * 재귀로 트리 순회 시 노드의 갯수만큼 함수 호출이 스택에 쌓이는 것이 아니다. 최대 레벨만큼만 쌓인다. 즉, 각 Leaf 노드에 도착한 시점이 최대이고 이후로 스택에서 제거되기 때문이다.
     * -> 재귀를 통해 전체 노드에 대하여 추가된 역순으로 알고리즘 실행이 불가능하다.
     * -> Queue&Stack 자료구조를 추가해서 BFS로 하면 가능하다.
     * 허나 가장 효율적인건.. 추가된 노드부터 시작하여 수직으로만 비교하는 것
     * 완전히 정렬된 트리면 루트부터 추가된 노드까지 바로 순차적 접근 가능
     * Min Heap 이라면.. 좌우가 아닌 레벨을 기준으로 정렬이 되어있다.
     *
     */
    void sort(CompleteBinaryTree::Node* node) {
        if (node == nullptr) {
            return;
        }
        sort(node->left);
        sort(node->right);
    }
};

int main() {
    MinHeap<int> t;
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