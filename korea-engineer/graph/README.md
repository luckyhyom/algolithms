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