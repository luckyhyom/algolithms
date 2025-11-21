#include "../linked-list.cpp"

// 문제: 중간에 있는 노드를 제거하기
// 1. 첫번째 노드와 맨 뒤 노드 제거 불가하다.
// 2. index가 길이를 초과하는 값일 경우 예외처리하기
void deleteNode(LinkedList::Node* node) {
    if (node->next == nullptr) {
        return;
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

    deleteNode(ll.get(3));
    ll.retrieve();  // 1,3,4
    return 0;
}
