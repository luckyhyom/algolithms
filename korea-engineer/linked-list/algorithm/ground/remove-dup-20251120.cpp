#include "../../linked-list.cpp"

// two pointer
void removeDups(LinkedList* ll) {
    LinkedList::Node* a = ll->get(1);
    while (a != nullptr) {
        LinkedList::Node* b = a;
        while (b->next != nullptr) {
            if (b->next->data == a->data) {
                // 이 부분 순서가 진짜 헷갈리네
                // runner는 검증 완료된 노드이고, runner의 다음 노드와 비교해야된다. 검증되면 runner는 다음 노드로 이동.
                LinkedList::Node* temp = b->next;
                b->next = b->next->next;
                delete temp;
            } else {
                b = b->next;
            }
        }
        a = a->next;
    }
}

int main() {
    LinkedList ll;
    ll.append(1);
    ll.append(2);
    ll.append(2);
    ll.append(3);
    ll.append(4);
    ll.append(4);
    ll.append(4);
    ll.retrieve();
    ll.removeDups();
    ll.retrieve();
    return 0;
}