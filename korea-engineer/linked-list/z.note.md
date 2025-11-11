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

1. LinkedList라는 컨테이너를 Node위에 덧씌워 관리함으로 인해 헷갈리는 부분이 있는 것 같은데, 그것이 무엇인지 명확하게 알았으면 좋겠다.
2. 그리고 LinkedList라는 컨테이너를 만드는 목적을 명확하게 알자
3. 지금 이것을 학습하는 이유는? 프로그래밍의 가장 기본이 되는 지식이며 흥미가 없지 않기 때문이다.

### 포인터

> last와 this->header->next는 다른 개체다.
> 할당되는 메모리 주소가 다르며 값만 공유할 수 있을 뿐이다.

```cpp
  // ❌
  void append(int n) {
    Node *last = this->header->next;
    while (last != nullptr) {
      last = last->next;
    }
    last = new Node(n);
  }
```

### 인터페이스와 테스트코드 추가하기
링크드 리스트를 매번 새로 구현하다보니까 기능 검증이 필요하다.
일단은 그냥 main에서 대충 테스트