/**
 * 컨테이너 없이 노드만 구현한다.
 * 현재 버전에서는 첫번째 노드는 제거하지 않는다.
 * 다른 객체가 첫번째 노드를 가지고 있을 경우에 문제가 되기 때문이다.
 */

class Node {
 public:
  int data;
  Node next;

  Node(int data) : data(data) {};
  void add(int data);
  void remove(int data);
  void retrieve();
}