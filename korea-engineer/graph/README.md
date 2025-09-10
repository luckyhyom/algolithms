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

### Node를 검색하는 방법