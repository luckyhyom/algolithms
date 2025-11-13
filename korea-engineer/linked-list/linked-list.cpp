#include <iostream>

class LinkedList {
   public:
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
    Node* currentNode;

    LinkedList() {
        header = Node::CreateNode();
        currentNode = header;
    }

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

    bool next() {
        if (currentNode != nullptr && currentNode->next != nullptr) {
            currentNode = currentNode->next;
            return true;
        } else {
            return false;
        }
    };

    Node* get(int index) {
        Node* result = header;
        for (size_t i = 0; i < index; i++) {
            result = result->next;
            if (result == nullptr) {
                std::cout << "get method return nullptr" << std::endl;
            }
        }
        return result;
    }

    void resetToHead() { currentNode = header; }

    int getData() {
        if (currentNode != nullptr) {
            return currentNode->data;
        }
        return 0;
    };

    void partition(int x) {
        Node* node = header;
        LinkedList* lager = new LinkedList();
        while (node != nullptr && node->next != nullptr) {
            if (node->next->data >= x) {
                lager->append(node->next->data);

                Node* deleted = node->next;
                node->next = node->next->next;
                delete deleted;
            } else {
                node = node->next;
            }
        }

        /**
         * Node 혹은 data를 순차적으로 외부에 반환해야한다. 📌
         */
        lager->resetToHead();
        while (lager->next() != false) {
            this->append(lager->getData());
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

    ll.reset();
    ll.append(8);
    ll.append(5);
    ll.append(2);
    ll.append(7);
    ll.append(3);
    ll.append(4);
    ll.retrieve();
    ll.partition(5);
    ll.retrieve();  // 2,3,4,5,8,7

    LinkedList::Node* n1 = ll.get(2);  // 3
    std::cout << n1->data << std::endl;
    LinkedList::Node* n2 = ll.get(3);  // 4
    std::cout << n2->data << std::endl;

    return 0;
}
