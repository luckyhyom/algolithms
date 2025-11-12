#include <iostream>

class LinkedList {
    class Node {
        Node(int n, int id) : data(n), id(id) {}

       public:
        int data;
        Node* next;
        int id;

        static Node* CreateNode() { return new Node(0, 0); }
        void append(int n) { this->next = new Node(n, id + 1); }
    };

    Node* header;

   public:
    LinkedList() { header = Node::CreateNode(); }

    void append(int n) {
        Node* last = header;
        while (last->next != nullptr) {
            last = last->next;
        }
        last->append(n);
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
        Node* last = header;
        std::cout << "HEAD -> ";
        while (last->next != nullptr) {
            std::cout << last->next->data << " -> ";
            last = last->next;
        }
        std::cout << "END" << std::endl;
    }

    void removeDups() {
        Node* n = header->next;
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

    void printKthFromEnd(int k) {
        int count = 0;
        kthFromEnd(header->next, k, &count);
    }

    void deleteNode(int index) {
        Node* n = header;
        int length = 0;
        while (n != nullptr && n->next != nullptr) {
            ++length;
            n = n->next;
        }

        if (index > length) {
            return;
        }

        Node* found = header;
        for (size_t i = 0; i < index; i++) {
            found = found->next;
        }

        Node* target = found->next;
        found->data = found->next->data;
        found->next = found->next->next;
        delete target;
    }

    void reset() {
        std::cout << "Reset Linked List.." << std::endl;
        Node* n = header;
        while (n != nullptr && n->next != nullptr) {
            Node* deleted = n->next;
            n->next = n->next->next;
            delete deleted;
        }
    }

   private:
    Node* kthFromEnd(Node* node, int k, int* count) {
        Node* result = nullptr;
        if (node != nullptr && node->next != nullptr) {
            result = kthFromEnd(node->next, k, count);
            if (result != nullptr) {
                return result;
            }
        }

        ++(*count);
        if (*count == k) {
            std::cout << node->data << std::endl;
            result = node;
        } else {
            result = nullptr;
        }

        return result;
    }
};

int main() {
    LinkedList ll;
    ll.append(1);
    ll.append(2);
    ll.append(3);
    ll.append(4);
    ll.printKthFromEnd(1);  // 4
    ll.printKthFromEnd(2);  // 3
    ll.printKthFromEnd(3);  // 2
    ll.printKthFromEnd(4);  // 1
    ll.retrieve();

    ll.reset();
    ll.append(1);
    ll.append(2);
    ll.append(3);
    ll.append(4);
    int index = 2;
    ll.deleteNode(index);
    ll.retrieve();  // 1,3,4

    return 0;
}
