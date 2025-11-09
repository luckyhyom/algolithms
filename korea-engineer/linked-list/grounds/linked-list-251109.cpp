#include <iostream>

class LinkedList {
  class Node {
   public:
    int data;
    Node *next = nullptr;
    Node(int n) : data(n) {};
  };

  Node *header;

 public:
  LinkedList() { header = new Node(0); }

  void append(int n) {
    Node *last = this->header;
    while (last->next != nullptr) {
      last = last->next;
    }
    last->next = new Node(n);
  }

  void remove(int n) {
    Node *standard = this->header;
    while (standard != nullptr && standard->next != nullptr) {
      if (standard->next->data == n) {
        Node *foundNode = standard->next;
        standard->next = foundNode->next;
        delete foundNode;
      } else {
        standard = standard->next;
      }
    }
  }

  void retrieve() {
    Node *last = this->header->next;
    while (last != nullptr) {
      std::cout << last->data << std::endl;
      last = last->next;
      // if it would be nullptr, doesn't need to print.
    }
  }
};

int main() {
  LinkedList *linkedList = new LinkedList();
  linkedList->append(2);
  linkedList->append(3);
  linkedList->append(4);
  linkedList->retrieve();
  linkedList->remove(2);
  linkedList->remove(3);
  linkedList->retrieve();
  return 0;
}