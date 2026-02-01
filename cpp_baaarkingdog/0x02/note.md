1. 공백을 기준으로 자르고(split)
2. 문자열을 숫자로 치환
3. 순차적으로 배열에 입력
- std::string은 자료형 치환이 자동으로 되나?
- std::cin, std::stringstream 차이
- 입력버퍼는 직접 열고 닫아야하나? while(std::cin >> value) {...};
- 버퍼 비우기 - Enter 입력 시 버퍼에 개행문자가 남는다.

-----

1. cin >> 는 공백 문자(스페이스, 탭, 개행)를 구분자로 하여 입력 버퍼의 데이터를 토큰 단위로 소비한다.
2. cin은 operator>>를 오버로딩하여 객체 자신을 반환하므로 연속 호출이 가능하다.
3. 입력 버퍼에 소비할 데이터가 없을 경우 스트림이 블로킹되며 입력 대기 상태가 된다.

```cpp
// Authored by : BaaaaaaaaaaarkingDog
// Co-authored by : -
// http://boj.kr/b140362e3257436a8d4b19ef50dad9c2
#include <bits/stdc++.h>
using namespace std;

int n, x, a[10005];
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> x;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++)
        if (a[i] < x) cout << a[i] << ' ';
}
```


```cpp
// stringstream은 공백과 개행을 기준으로 토큰 단위로 읽힌다.

while(ss >> value) { ... }
```

---
기본적으로 cin/cout ↔ scanf/printf는 같은 버퍼를 공유하도록 동기화

```cpp
ios::sync_with_stdio(false);  
// C stdio와 C++ iostream 간의 동기화를 해제하여 입출력 성능을 향상시킨다.

cin.tie(nullptr);             
// cin 사용 시 cout.flush()를 자동으로 호출하지 않도록 하여 불필요한 flush를 방지한다.
```

왜 BOJ에선 문제 없나?

BOJ 스타일 코드:
```cpp
cin >> n;
cout << n;
```
- 출력 전에 입력 안내 메시지 없음
- 마지막에 한 번에 출력
- 프로그램 종료 시 자동 flush