#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int alphabet[26] = {
        0,
    };

    char s[101] = {
        // 0으로 초기화하지 않으면 메모리에 남아있던 값이 들어가게된다.
        0,
    };

    cin >> s;

    // char 자료형 데이터는 연산자를 만나면 int 자료형으로 해석된다.
    for (size_t i = 0; s[i] != '\0'; ++i) {
        if (s[i] >= 'a' && s[i] <= 'z') {
            alphabet[s[i] - 'a']++;
        }
    }

    for (size_t i = 0; i < 26; i++) {
        cout << alphabet[i] << " ";
    }

    return 0;
}