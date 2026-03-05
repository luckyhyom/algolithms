// std::list 사용법을 몰라서 한참 헤멨다. 직접 구현한 것만 사용하다보니.. 익숙치 않다.
// cpp 사용법은 공부하지 말고 빨리빨리 검색해서 넘어가자.

#include <bits/stdc++.h>

using namespace std;

struct Node {
    char* text = nullptr;
    bool isCursor = false;
};

void add(list<Node*>& l, list<Node*>::iterator& cursor, char c) {
    Node* newNode = new Node();
    newNode->text = new char(c);
    l.insert(cursor, newNode);
}

// list에 Next가 없는게 문제다. => 직접 구현하던게 구식임 (node->next) 📌
// iterator는 포인터다. 📌
void left(list<Node*>& l, list<Node*>::iterator& cursor) {
    if (cursor == l.begin()) return;
    l.splice(std::prev(cursor), l, cursor);
}

void right(list<Node*>& l, list<Node*>::iterator& cursor) {
    if (cursor == l.end()) return;
    l.splice(cursor, l, std::next(cursor));
}

void erase(list<Node*>& l, list<Node*>::iterator& cursor) {
    if (cursor == l.begin()) return;
    l.erase(std::prev(cursor));
}

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

    list<Node*> text;
    Node* _cursor = new Node();
    _cursor->isCursor = true;
    text.push_back(_cursor);

    list<Node*>::iterator cursor = text.begin();

    for (size_t i = 0; i < text_temp.size(); i++) {
        add(text, cursor, text_temp[i]);
        // Node* node = new Node();
        // node->text = new char(text_temp[i]);
        // text.push_back(node);
    }

    /**
     * abcd|
     * P x
     * L
     * P y
     *
     * 텍스트가 저장된 자료구조의 문제다.
     * 배열은 중간 삽입시 메모리를 전체 재할당한다.
     * 연결리스트로 수정하자.
     *
     * 연결리스트랑 포인터 사용법 또 까먹었다 ㅎ 아주 쉽게 한단계씩 풀어나가자.. 재활 필요하다..
     */
    // add(list<Node*>& l, list<Node*>::iterator cursor, char c) {
    while (commands.empty() == false) {
        string command = commands.front();
        if (command[0] == 'P') {
            add(text, cursor, command[2]);
        } else if (command[0] == 'L') {
            left(text, cursor);
        } else if (command[0] == 'D') {
            right(text, cursor);
        } else if (command[0] == 'B') {
            erase(text, cursor);
        }
        commands.pop_front();
    }

    for (auto&& i : text) {
        if (i->text) cout << *i->text;
    }

    return 0;
}