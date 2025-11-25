#include "../linked-list.cpp"

LinkedList::Node* findLoopEntry(LinkedList* ll) {
    LinkedList::Node* s = ll->get(1);
    LinkedList::Node* f = ll->get(1);

    bool isLoop = 0;
    while (s->next != nullptr || f->next != nullptr) {
        s = s->next;
        f = f->next->next;
        if (s == f) {
            isLoop = 1;
            break;
        }
    }

    if (isLoop == 0) {
        return nullptr;
    }

    s = ll->get(1);

    while (s != f) {
        s = s->next;
        f = f->next;
    }

    return s;
}

int main() {
    LinkedList l1;
    l1.append(1);
    l1.append(2);
    l1.append(3);
    l1.append(4);
    l1.append(5);
    l1.append(6);
    l1.append(7);
    l1.append(8);
    l1.append(9);
    l1.append(l1.get(3));  // loop = 3

    std::cout << findLoopEntry(&l1)->data << std::endl;

    return 0;
}