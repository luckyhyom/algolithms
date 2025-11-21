#include "../linked-list.cpp"

// 1. 맨 뒤 노드 제거 불가
// 2. index가 길이를 초과하는 값일 경우 예외처리
void deleteNode(LinkedList::Node* node, int index) {
    for (size_t i = 1; i < index; i++) {
        if (node->next == nullptr) {
            return;
        }
        node = node->next;
    }
    LinkedList::Node* temp = node->next;
    node->data = node->next->data;
    node->next = node->next->next;
    delete temp;
}

int main() {
    LinkedList ll;
    ll.append(1);
    ll.append(2);
    ll.append(3);
    ll.append(4);
    ll.retrieve();  // 1,2,3,4

    int index = 2;
    deleteNode(ll.get(1), index);
    ll.retrieve();  // 1,3,4
    return 0;
}
