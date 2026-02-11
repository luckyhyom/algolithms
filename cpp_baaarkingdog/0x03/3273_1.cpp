#include <bits/stdc++.h>

using namespace std;

// 사용자 지정 배열 최대 길이 100000 -> 필요 없을 것 같은데 함정인가?
// 배열에 있는 자연수 최댓값 1000000
// i+j = x의 최댓값 2000000
int main() {
    int arr[1000001] = {0};
    int n, x, result_count = 0;

    cin >> n;

    for (size_t i = 0; i < n; i++) { /* code */
        int type_int = 0;
        cin >> type_int;
        arr[type_int]++;
    }

    cin >> x;

    for (size_t i = 0; i < n; i++) {
        ㄴ if (arr[i] != 0 && arr[x - i] != 0) { result_count++; }
    }

    cout << result_count;

    return 0;
}