#include <iostream>

/**
 * 컨테이너 없이 노드만 구현한다.
 * 현재 버전에서는 첫번째 노드는 제거하지 않는다.
 * 다른 객체가 첫번째 노드를 가지고 있을 경우에 문제가 되기 때문이다.
 *
 * Linked List의 존재 목적: 길이가 정해지지 않은 동적 데이터 관리
 */

class Node {
 public:
  int data;
  Node *next = nullptr;

  Node(int d) : data(d) {};

  void append(int d) {
    Node *n = this;
    Node *end = new Node(d);

    while (n->next != nullptr) {
      n = n->next;
    }
    n->next = end;
  };

  void remove(int d) {
    Node *n = this;

    while (n->next != nullptr) {
      if (n->next->data == d) {
        Node *found = n->next;
        n->next = n->next->next;
        delete found;
      } else {
        n = n->next;
      }
    }
  };

  void retrieve() {
    Node *n = this;
    while (n->next != nullptr) {
      std::cout << n->data << std::endl;
      n = n->next;
    }
    std::cout << n->data << std::endl;
  };
};

int main() {
  Node *head = new Node(1);
  head->append(2);
  head->append(3);
  head->append(4);
  head->retrieve();
  head->remove(2);
  head->remove(3);
  head->retrieve();
  return 0;
}