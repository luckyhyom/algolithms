### Graph 내부 구조
배열 + 링크드 리스트로 구현되어있다.
[ A B C D ]
  | | | |
  B C D A
  |   | |
  C   A B


```cpp
class Graph {
   public:
    class Node {
       public:
        T data;
        bool marked;
        LinkedList<Node*> adjacent; // 각 노드가 가진 간선 (연결리스트)
        ...
    };

    std::vector<Node*> nodes; // 모든 노드가 있는 배열
    ...
};
```