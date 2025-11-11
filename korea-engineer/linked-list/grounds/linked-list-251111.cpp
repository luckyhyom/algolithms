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

        /**
         * 조건문 while (n != nullptr && n->next != nullptr) 에 대하여
         *
         * <논리>
         * 기본적으로 r은 nullptr이 될 수 없다.
         * 이유는 (r = r->next) 대입은, 조건문 (r->next != nullptr) 을 만족한 상태에서만 수행되기
         * 때문이다.
         *
         * 그렇다면 n이 nullptr이 되기 위해서는, r에 대한 알고리즘이
         * n의 조건문 (n->next != nullptr) 에 대하여 무효화 시킬 수 있어야 한다는 것이다.
         *
         * 그것을 증명하면 된다.
         *
         * <증명>
         * 1. r은 항상 마지막 Node까지 이동한다.
         * 2. 마지막 Node의 next는 nullptr이다.
         * 3. n이 마지막에서 두번째 Node에 위치했을 때에 r이 마지막 Node를 제거하면 n과 r은 마지막
         * Node가 된다.
         * 4. 3번의 상황에서 (n = n->next;) 알고리즘을 실행하면 n은 결국 nullptr이 된다.
         */
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
