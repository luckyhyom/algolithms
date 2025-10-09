### Node를 인터페이스에 노출시켜야하는가?
1. Node가 가진 데이터가 기본 자료형이 아닌 구조체인 경우는?
2. 만약 노출시킨다면 이름 중복의 문제는? (GraphNode, QueueNode 라고 이름 지어야하나?)
   > -> namespace 사용
3. Node를 노출하지 않는 경우, 

### Pain Point
> Node의 다음 요소를 조회했으나 Node가 아닌 List가 반환된다.

```cpp
class List {}
class Node {}

int main() {
    List *list;
    Node list->getValue(); // Node를 대입했다.
    node->next(); // Node의 다음 요소를 조회했으나 Node가 아닌 List가 반환된다.
}
```

> 메서드 작명의 문제인가 인터페이스 설계의 문제인가?