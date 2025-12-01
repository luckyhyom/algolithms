### 완전 이진 트리 (Complete Binary Tree)
**Node 추가 조건**
1. Node를 추가할 때에는 왼쪽 부터 추가한다.
2. Node의 Level이 Top Level보다 낮으면서 Left Node가 없는 경우 새로운 Node를 추가한다.
3. Left Node가 있으면서 Right Node가 없는 경우 새로운 Node를 추가한다.
4. Tree의 모든 Node가 (2)또는 (3)에 해당하지 않을 경우 가장 왼쪽의 마지막 Node에 새로운 Node를 추가한다.