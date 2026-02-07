
// https://www.acmicpc.net/problem/1475
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int room_number;
    int arr[10] = {};

    cin >> room_number;

    while (room_number > 0) {
        arr[room_number % 10]++;
        room_number /= 10;
    }

    int value = std::round((arr[6] + arr[9]) / 2.0);  // (int+int)/double
    arr[6] = value;
    arr[9] = 0;

    int max = 0;
    for (size_t i = 0; i < 10; i++) {
        if (max < arr[i]) max = arr[i];
    }

    cout << max;

    return 0;
}