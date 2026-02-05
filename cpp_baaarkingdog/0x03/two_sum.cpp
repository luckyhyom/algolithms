#include <bits/stdc++.h>

using namespace std;

int func2(const vector<int>& arr, int N) {
    // vector는 처음 길이를 입력해야한다.
    // v[i] 연산 시 vector의 길이를 체크하는 오버헤드를 없애기 위함이다.
    vector<int> arr_temp(101, 0);

    for (auto i : arr) {
        arr_temp[i]++;
    }

    for (size_t i = 0; i < 50; i++) {
        if (arr_temp[i] > 0 && arr_temp[100 - i] > 0) return 1;
    }

    if (arr_temp[50] < 2) return 1;

    return 0;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cout << func2({1, 52, 48}, 3);
    cout << func2({50, 42}, 2);
    cout << func2({4, 13, 63, 87}, 4);
    return 0;
}