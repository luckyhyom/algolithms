#include <iostream>

#include "../linked-list.cpp"

int getLength(LinkedList::Node* node) {
    if (node == nullptr) {
        return 0;
    }
    int result = 1;
    while (node->next != nullptr) {
        ++result;
        node = node->next;
    }
    return result;
}

LinkedList::Node* getIntersection(LinkedList::Node* l1, LinkedList::Node* l2) {
    int len1 = getLength(l1);
    int len2 = getLength(l2);

    if (len1 > len2) {
        // remove
        for (size_t i = 0; i < len1 - len2; i++) {
            LinkedList::Node* temp = l1->next;
            l1->data = l1->next->data;
            l1->next = l1->next->next;
            delete temp;
        }
    } else {
        // remove
        for (size_t i = 0; i < len2 - len1; i++) {
            LinkedList::Node* temp = l2->next;
            l2->data = l2->next->data;
            l2->next = l2->next->next;
            delete temp;
        }
    }

    while (l1 != nullptr) {
        if (l1 == l2) {
            return l1;
        }
        l1 = l1->next;
        l2 = l2->next;
    }

    return nullptr;
}

int main() {
    LinkedList ll;
    LinkedList ll2;
    ll.append(1);
    ll.append(2);
    ll.append(3);
    ll.append(4);
    ll.append(5);

    ll2.append(6);
    ll2.append(7);
    ll2.append(ll.get(3));

    /**
     * ll: 1->2->3->4->5
     * l2: 6->7->3->4->5
     *
     * 1->2-
     * 		 \
     * 		  -->3->4->5
     * 		 /
     * 6->7-
     */

    LinkedList::Node* interection = getIntersection(ll.get(1), ll2.get(1));
    LinkedList result;
    result.append(interection);
    result.retrieve();
}