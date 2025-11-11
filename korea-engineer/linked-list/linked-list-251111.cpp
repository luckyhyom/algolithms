#include <iostream>

class LinkedList {
    class Node {
       public:
        int data;
        Node* next = nullptr;
        Node(int n) : data(n) {}
    };

    Node* header;

   public:
    LinkedList() { header = new Node(0); }

    void append(int n) {
        Node* last = header;
        while (last->next != nullptr) {
            last = last->next;
        }
        last->next = new Node(n);
    }

    void remove(int n) {
        Node* last = header;
        while (last->next != nullptr) {
            if (last->next->data == n) {
                Node* found = last->next;
                last->next = last->next->next;
                delete found;
            } else {
                last = last->next;
            }
        }
    }

    void retrieve() {
        Node* n = header;
        while (n->next != nullptr) {
            std::cout << n->next->data << std::endl;
            n = n->next;
        }
    }

    void removeDups() {
        Node* n = header;

        while (n != nullptr && n->next != nullptr) {
            Node* r = n;
            while (r->next != nullptr) {
                if (n->data == r->next->data) {
                    Node* found = r->next;
                    r->next = r->next->next;
                    delete found;
                } else {
                    r = r->next;
                }
            }
            n = n->next;
        }
    }
};

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
