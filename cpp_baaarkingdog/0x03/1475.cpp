
// https://www.acmicpc.net/problem/1475
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int room_number = 0, max_val = 0;
    int arr[10] = {};

    cin >> room_number;

    while (room_number > 0) {
        arr[room_number % 10]++;
        room_number /= 10;
    }

    for (size_t i = 0; i < 10; i++) {
        if (i == 6 || i == 9) continue;
        if (max_val < arr[i]) max_val = arr[i];
    }

    cout << std::max(max_val, (arr[6] + arr[9] + 1) / 2);

    return 0;
}