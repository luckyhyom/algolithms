#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int a, b, c;
    cin >> a >> b >> c;

    int max_val = a;
    int min_val = a;

    if (max_val < b) {
        max_val = b;
    }

    if (max_val < c) {
        max_val = c;
    }

    if (min_val > b) {
        min_val = b;
    }

    if (min_val > c) {
        min_val = c;
    }

    if (a != max_val && a != min_val) {
        cout << min_val << " " << a << " " << max_val;
    } else if (b != max_val && b != min_val) {
        cout << min_val << " " << b << " " << max_val;
    } else if (c != max_val && c != min_val) {
        cout << min_val << " " << c << " " << max_val;
    }

    return 0;
}