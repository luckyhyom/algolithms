### Node를 저장할 컨테이너

```cpp
<typename T>
class LinkedList {};
class Node {
    int data;
    LinkedList<Node*> adjacent;
};
```

LinkedList대신 정적인 크기의 Array를 사용할수도 있다.


```cpp
class Node {
    int data;
    Node *adjacent[5];
};
```

> 자료형과 astroc, 변수명, 등의 위치가 헷갈린다.

### Node를 추가하는 방법
```cpp
/**
 * 요소를 추가하는 방법
 * A) 링크드 리스트에 입력된 순서대로 저장 후 연결
 * - add(A, B);
 * - add(B, C);
 * - add(C, A);
 * 
 * B) 링크드 리스트에 저장할 때 정렬해서 저장
 * 
 * Q2. Tree has only one node as root. Graph has many nodes in list as member ?
 */
void addEdge(int a, int b) {
```

### Node를 검색하는 방법


> [!Note]
> 1. Graph에서 시작 Node를 검색할 때는 Brute Force를 사용
> 2. 시작 Node에서 bfs/dfs로 검색
> 3. Graph의 bfs, dfs는 단순히 하나의 Node를 검색하는 것이 아니라 해당 Node와 다른 Node간의 관계를 검색하는 것이다. (맞나?)