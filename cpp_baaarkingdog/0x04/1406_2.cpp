#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string input;
    cin >> input;

    list<char> text;
    for (auto&& i : input) {
        text.push_back(i);
    }

    list<char>::iterator cursor = text.end();

    int count;
    cin >> count;

    while (count--) {  // 카운트 📌
        char command;
        cin >> command;
        if (command == 'P') {
            char c;
            cin >> c;  // getline을 사용하지 않고 cin을 두번 사용한다. 📌
            text.insert(cursor, c);
        } else if (command == 'L') {
            if (cursor != text.begin()) cursor--;
        } else if (command == 'D') {
            if (cursor != text.end()) cursor++;
        } else if (command == 'B') {
            if (cursor != text.begin()) {
                cursor--;
                cursor = text.erase(cursor);  // 삭제된 노드의 다음 노드를 가리키는 iterator를 반환한다. 📌
            }
        }
    }

    for (auto&& i : text) {
        cout << i;
    }

    return 0;
}