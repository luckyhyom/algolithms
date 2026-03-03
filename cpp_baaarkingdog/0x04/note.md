### BOJ - 1406
1. 커맨드를 어떻게 토큰화시킬까? 어떻게 커맨드를 입력받아 순회할 수 있을까?
- 공백을 구분자로 하기에는 Command "P" 때문에 어렵다. (불가능하진 않다.)

2. vector<string>(500000, '') 의 공간 할당은 가능한가?
- vector는 동적 배열이기 때문에 크기에 제한은 없다. (컴퓨터, 혹은 알고리즘 문제 제약이 있을 경우 제외)
 
3. string가 가진 최소 크기(24~32bytes) 때문에 커맨드를 vector<string>에 입력 받는 것과, string 하나에 받는 것의 차이가 약 커맨드 갯수 * (23~32) 만큼의 차이가 생긴다.


결론: vector<char>를 사용한다.

```cpp
list<char> text; // 양방향
node* cursor = 'c'; // 커서의 포인터를 저장후 바로 접근한다.
vector<char>(1500000, 0) command;

for (int i = 0; i < (M*3); i++) {
    if(command[i] == 'L') {
        // 커서를 왼쪽으로
        if(cursor.left == nullptr) {
            continue;
        } else {
            node* c_left = cursor.left;
            node* c_right = cursor.right;
            node* left = cursor.left;

            cursor.left = left.left;
            cursor.right = c_left;
            
            left.left = left.right;
            left.right = c_right;
        }
    }
    else if(command[i] == 'D') {
        // 커서를 오른쪽으로
        if(cursor.right == nullptr) {
            continue;
        } else {
            node* c_left = cursor.left;
            node* c_right = cursor.right;
            node* right = cursor.right;
ABC
            cursor.left = cursor.right;
            cursor.right = right.right; // cursor.right = right.rgiht일 때, right.right가 바뀌면?
            
            // cursor.right와  right.right는 같은 값을 가지고 있는 변수일뿐이다. (주소를 복사 대입한 것)
            right.right = right.left;
            right.left = c_left;
        }
    }
    else if(command[i] == 'B') {
        // 왼쪽 글자를 지운다.
    }
    else if(command[i] == 'P') {
        // 다다음 문자를 커서 왼쪽에 추가한다.
    }
    else if(command[i] == ' ') {
        // 스킵
    }
}

```