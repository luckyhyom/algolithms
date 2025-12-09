#include <iostream>
#include <list>
#include <string>

/**
 * 템플릿 매개변수가 원시 타입일 때와 구조체 일 때 따로 만들어야하나?
 * 1. 매개변수 자료형이 T*이면 원시 타입은 인자로 사용하기 어렵다. func(&1)
 * 2. 원시 타입마다 다 만들어줘야하나?
 */
template <typename T>
class LinkedList {
   public:
    class Node {
        Node() : data() { this->next = nullptr; }

       public:
        Node(T n) : data(n) { this->next = nullptr; }
        T data;
        Node* next;

        static Node* CreateNode() { return new Node(); }
        void append(Node* n) { this->next = n; }
    };

    Node* header;
    Node* currentNode;

    LinkedList() {
        header = Node::CreateNode();
        currentNode = header;
    }

    void append(T n) {
        Node* last = header;
        while (last->next != nullptr) {
            last = last->next;
        }
        Node* created = new Node(n);
        last->append(created);
    }

    void append(Node* n) {
        Node* last = header;
        while (last->next != nullptr) {
            last = last->next;
        }
        last->append(n);
    }

    void remove(T n) {
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

    void reset() {
        std::cout << "Reset Linked List.." << std::endl;
        Node* n = header;
        while (n != nullptr && n->next != nullptr) {
            Node* deleted = n->next;
            n->next = n->next->next;
            delete deleted;
        }
    }

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

    bool includes(T target) {
        Node* last = this->header;
        while (last->next) {
            last = last->next;
            if (last->data == target) {
                return true;
            }
        }
        return false;
    }

    int getCount() {
        int count = 0;
        Node* last = this->header;
        while (last->next) {
            last = last->next;
            count++;
        }
        return count;
    }
};

// int main() {
//     // LinkedList<std::string> ll;
//     LinkedList<int> ll;
//     ll.append(1);
//     ll.append(2);
//     ll.append(3);
//     ll.append(4);
//     ll.retrieve();

//    return 0;
//}
