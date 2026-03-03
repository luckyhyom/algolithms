
/**
 * L : 커서를 왼쪽으로 한 칸 옮김 (커서가 문장의 맨 앞이면 무시됨)
 * D : 커서를 오른쪽으로 한 칸 옮김 (커서가 문장의 맨 뒤이면 무시됨)
 * B : 커서 왼쪽의 문자를 지운다.
 * P $: 문자를 커서 왼쪽에 추가한다.
 *
 * 문제 쪼개기
 * 1. 텍스트 저장하기 ✅
 * 2. 명령어 저장하기 ✅
 * 		- 공백을 입력받기 위해 getline 사용
 * 3. 명령어 실행시키기 ✅
 */

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string text;
    int count = 0;
    std::list<string> commands;

    cin >> text >> count;
    cin.ignore();

    for (size_t i = 0; i < count; i++) {
        string command;
        getline(cin, command);
        commands.push_back(command);
    }

    /**
     * abcd|
     * P x
     * L
     * P y
     */
    int cursor = text.size();
    while (commands.empty() == false) {
        string command = commands.front();
        if (command[0] == 'P') {
            text.insert(text.begin() + cursor, command[2]);
            if (cursor < text.size()) {
                ++cursor;
            }
        } else if (command[0] == 'L') {
            if (cursor > 0) {
                --cursor;
            }
        } else if (command[0] == 'D') {
            if (cursor < text.size()) {
                ++cursor;
            }
        } else if (command[0] == 'B') {
            if (cursor > 0) {
                text.erase(cursor - 1, 1);
                --cursor;
            }
        }
        commands.pop_front();
    }

    cout << text;

    return 0;
}