template <typename T>
class MinHeap {
    class Node {
        T data;
        Node* left;
        Node* right;
        Node() {}
    };

    Node* root = nullptr;

    MinHeap() {}

    // 결국 전체적으로 정렬 작업이 이뤄진다. 일단 마지막 노드에 추가하고 부모와 값 비교
    void add(T value) {}

    // 마지막 노드를 루트로 바꾸고 루트부터 자식 노드와 비교 (배열의 중간에 원소를 삽입해서 기존 원소를 밀어내는 것과 유사한 느낌)
    void remove() {}

    T getMin() { return this->root->data; }
}

// 해답을 보면 이해했다고 착각하고 공식처럼 외워버리는 느낌이고..
// 해답을 알기 전에 고민하는 과정이 있어야 원리를 알고 이해할 것 같은 느낌..
// 왜냐하면 문제를 풀려면 원리를 알아야하고, 풀지 못하더라도 내가 막혔던 부분을 인지하고 해답으로 문제가 풀렸을때 어떤 원리인지 생각해볼수밖에 없으니까?