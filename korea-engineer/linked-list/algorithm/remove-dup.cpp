#include "../linked-list.cpp"

// two pointer
void removeDups(LinkedList* ll) {
    LinkedList::Node* a = ll->get(1);
    while (a != nullptr) {
        LinkedList::Node* b = a;
        while (b->next != nullptr) {
            if (b->next->data == a->data) {
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
    ll.append(1);
    ll.retrieve();
    ll.removeDups();
    ll.retrieve();
    return 0;
}