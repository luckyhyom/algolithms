#include "../linked-list.cpp"

void printKthFromEnd(LinkedList::Node* node, int k, int* count) {
    if (node->next != nullptr) {
        printKthFromEnd(node->next, k, count);
    }

    ++(*count);
    if (*count == k) {
        std::cout << node->data << std::endl;
    }
}

int main() {
    LinkedList ll;
    ll.append(1);
    ll.append(2);
    ll.append(3);
    ll.append(4);

    int count = 0;
    printKthFromEnd(ll.get(1), 1, &count);  // 4
    count = 0;
    printKthFromEnd(ll.get(1), 2, &count);  // 3
    count = 0;
    printKthFromEnd(ll.get(1), 3, &count);  // 2
    count = 0;
    printKthFromEnd(ll.get(1), 4, &count);  // 1
    return 0;
}
