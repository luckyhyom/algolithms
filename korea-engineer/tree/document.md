### 완전 이진 트리 (Complete Binary Tree)
**Node 추가 조건**
1. Node를 추가할 때에는 왼쪽 부터 추가한다.
2. Node의 Level이 Top Level보다 낮으면서 Left Node가 없는 경우 새로운 Node를 추가한다.
3. Left Node가 있으면서 Right Node가 없는 경우 새로운 Node를 추가한다.
4. Tree의 모든 Node가 (2)또는 (3)에 해당하지 않을 경우 가장 왼쪽의 마지막 Node에 새로운 Node를 추가한다.


### Min Heap이 Tree 자료구조일 경우
- 정렬되어있지 않은 Tree를 Heap으로 정렬하기 어렵다.
- 따라서 처음 데이터 삽입 시 부터 정렬이 되어야한다.
- 처음부터 하나씩 정렬되며 데이터가 삽입되는 것이 마치 나무처럼 자라나는 느낌이 든다. 그래서 Tree인가..? Tree 존재의 목적은 무엇인가?

```
     *         (1)
     * 	   (4)     (2)
     *   (9) (5) (3)
     *
     * Min Heap일 때
     * 좌측 1 Level의 값 4가 우측 2 Level의 값 3보다 크다.
```