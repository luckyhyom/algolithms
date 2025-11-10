#include <iostream>

class LinkList {
  class Node {
   public:
    Node(int n) { data = n; };
    int data;
    Node *next = nullptr;
  };

  Node *header;  // note: nullptr 하지 않으면 쓰레기 값 할당 됨

 public:
  LinkList() {
    header = new Node(0);
  };  // note: header를 교체할지 고정할지는 자유다. "딱히 지금은 고민할 필요
      // 없는듯"
  // add: 추가하다, append: 붙이다.
  void append(int n) {
    Node *last = header;
    while (last->next != nullptr) {
      last = last->next;
    }
    last->next = new Node(n);
  }
  void remove(int n) {
    Node *last = header;
    while (last->next != nullptr) {
      if (last->next->data == n) {
        Node *found = last->next;
        last->next = last->next->next;
        delete found;
      } else {
        last = last->next;
      }
    }
  }
  void retrieve() {
    Node *last = header;
    while (last->next != nullptr) {
      std::cout << last->next->data << std::endl;
      last = last->next;
    }
  }
};

int main() {
  LinkList ll;
  ll.append(1);
  ll.append(2);
  ll.append(3);
  ll.append(4);
  ll.retrieve();
  ll.remove(3);
  ll.retrieve();
  ll.remove(1);
  ll.retrieve();
  return 0;
}