// https://www.acmicpc.net/problem/2577
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a, b, c;
    vector<int> arr(10, 0);
    int value;

    cin >> a >> b >> c;
    value = a * b * c;

    while (value > 0) {
        arr[value % 10]++;
        value /= 10;
    }

    for (size_t i = 0; i < arr.size(); i++) {
        cout << arr[i] << "\n";
    }

    return 0;
}