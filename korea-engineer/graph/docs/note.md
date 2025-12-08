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

### Node를 추가하는 방법
1. Node를 입력 순서와 동일하게 Graph의 배열에 저장 후 노드 연결
2. Node를 정렬해서 Graph의 배열에 저장 후 노드 연결
> [!Note]
> 혹은 노드 연결도 자동으로?
> (정리 중)



### Node를 검색하는 방법
> [!Note]
> 1. Graph에서 시작 Node를 검색할 때는 Brute Force를 사용
> 2. 시작 Node에서 bfs/dfs로 검색
> 3. Graph의 bfs, dfs는 단순히 하나의 Node를 검색하는 것이 아니라 해당 Node와 다른 Node간의 관계를 검색하는 것이다.
>   - Graph가 배열에 모든 Node를 저장하고 있으니 그냥 배열을 Brute Force 방식으로 검색하면 된다고 생각한 것.
>   - "A에서 B"라는 조건이 아닌 그냥 "B"를 찾는 것이라면 배열 순회해서 검색하면 된다.
>
> 4. Tree는 Root Node 한개를 가지는 것에 반해, Graph는 전체 Node를 배열(리스트)에 저장해두며 각 Node는 인접 Node의 정보를 가진다.


### 관계 표현 방법

1. 2차원 배열을 이용한 매트릭스
```md
   a  b  c  d
a  0  1  0  0
b  1  0  0  1
c  0  0  0  1
d  0  1  1  0
```

2. 배열과 링크드리스트를 이용
```
[ a b c d ] # Array
  | | | |   # LinkedList
  b a d b
    |   |
    d   c
```


### 구현
1. Node는 인접 노드에 대한 정보를 가지고 있다.
```cpp
class Node {
    int data;
    LinkedList<Node*> adjacent;
};
```
> [!NOTE]
> LinkedList를 사용하는 이유는 특정 위치의 노드에 접근하지 않고 순차적으로 조회해도 되기 때문이다.
> 또한 조회 로직이 좀더 간단하다.

```cpp
while(node->next != nullptr) {
    node = node->next;
}
```

2. Graph는 Array에 모든 노드를 저장한다.
```cpp
class Graph {
    std::vector<Node*> nodes;
};
```

> [!NOTE]
> 만약 Graph가 노드를 배열에 저장하는 것이 아닌 단일 노드를 진입점으로 가지고있다면?
> 1. 임의의 노드를 조회하기 어려움 (배열은 인덱스로 접근 가능)
> 2. 조회가 어려운 만큼 연결도 복잡해진다. 각 노드를 반복문으로 조회해야함
> 3. 공간복잡도는 O(n)으로서 비교적 낮다.