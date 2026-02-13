#include <bits/stdc++.h>

using namespace std;

// 1. 배열을 함수 밖으로 뺍니다. (전역 변수) 📌
// 자동으로 0으로 초기화되며, 스택 오버플로우 걱정이 없습니다.
int arr[2000001];
int checked[2000001];
int typed_int[1000001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, x = 0;
    int result_count = 0;

    cin >> n;

    if (n > 100000) {
        cout << 0;
        return 0;
    }

    for (size_t i = 0; i < n; i++) {
        int type_int = 0;
        cin >> type_int;
        arr[type_int]++;
        typed_int[i] = type_int;
    }

    cin >> x;

    if (x >= 2000000) {
        cout << 0;
        return 0;
    }

    // 199 = 100 + 99
    // 199 - 99

    for (size_t i = 0; i < n; i++) {
        // 음수 방지 📌
        if ((x - typed_int[i]) < 0) continue;
        if (arr[x - typed_int[i]] > 0 && checked[typed_int[i]] == 0 && checked[x - typed_int[i]] == 0) {
            // x/2 케이스 방지 📌 (x가 10일 때 그 절반의 값인 5는 두 수의 합이 아니므로 제외한다.)
            if (typed_int[i] == x - typed_int[i]) continue;
            result_count++;
            checked[typed_int[i]]++;
            checked[x - typed_int[i]]++;
        }
    }

    cout << result_count;

    return 0;
}