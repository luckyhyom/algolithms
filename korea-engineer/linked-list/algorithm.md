### 중복된 값을 가진 Node 모두 제거하기
- runner 포인터를 만들어 순회하며 제거한다.
  - [투포인터 알고리즘](https://www.geeksforgeeks.org/dsa/two-pointers-technique/)
- (참고)
```cpp
if(..) {
    ...
    node->next = node->next->next;
} else {
    node = node->next;
}
```

### 끝에서 k 번째 node 검색
[재귀](https://www.geeksforgeeks.org/dsa/introduction-to-recursion-2/)를 사용한다.

### Singly Linked List에서 현재 Node를 제거하기
- 다음 Node의 데이터를 현재 Node에 복사 후 다음 Node를 제거한다.
- Array에서 중간 요소를 제거할 때와 동일한 메커니즘

### x를 기준으로 작은 것은 왼쪽, 큰 것은 오른쪽으로 나누기
- LinkedList를 두개 사용한다.
- LinkedList에 있는 데이터를 외부에서 다루기 위해 데이터를 반환해야한다. (현재까지는 로그만 출력함)

> node->next = nullptr;  // node가 마지막 node가 되어야하는 경우 next를 nullptr로 만들어야한다.