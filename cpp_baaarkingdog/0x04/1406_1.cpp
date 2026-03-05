
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string text_temp;
    int count = 0;
    std::list<string> commands;

    cin >> text_temp >> count;
    cin.ignore();

    for (size_t i = 0; i < count; i++) {
        string command;
        getline(cin, command);
        commands.push_back(command);
    }

    list<char> text;
    list<char>::iterator cursor = text.end();

    for (size_t i = 0; i < text_temp.size(); i++) {
        text.insert(cursor, text_temp[i]);
    }

    while (commands.empty() == false) {
        string command = commands.front();
        if (command[0] == 'P') {
            text.insert(cursor, command[2]);
        } else if (command[0] == 'L') {
            if (cursor != text.begin()) {
                text.splice(std::prev(cursor), text, cursor);
            }
        } else if (command[0] == 'D') {
            if (std::next(cursor) != text.end()) {
                text.splice(cursor, text, std::next(cursor));
            }
        } else if (command[0] == 'B') {
            if (cursor != text.begin()) {
                text.erase(std::prev(cursor));
            }
        }
        commands.pop_front();
    }

    for (auto&& i : text) {
        cout << i;
    }

    return 0;
}