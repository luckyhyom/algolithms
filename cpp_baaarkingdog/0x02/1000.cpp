#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);  // C 표준 입출력(stdio)과 C++ 스트림(iostream) 간의 동기화를 해제한다. (기본적으로 cin/cout ↔ scanf/printf는 같은 버퍼를 공유하도록 동기화)
    cin.tie(0);               // cin이 입력을 수행하기 전에 자동으로 cout.flush()를 호출하지 않도록 한다. 즉, 출력 버퍼를 자동으로 비워주지 않도록 한다.

    int A, B;
    cin >> A >> B;
    cout << A + B;
    return 0;
}