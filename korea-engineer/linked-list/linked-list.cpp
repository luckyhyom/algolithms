#include <iostream>
/**
 * Linked List 자료 구조
 * 
 * 용도
 * 1. 정적 배열(Array)과 다르게 저장 가능한 원소의 개수가 고정되어있지 않다.
 * 2. 동적 배열(Vector)의 삽입 삭제에 대한 오버헤드 문제를 해결한다.
 *  - 배열(Array,Vector)은 물리적으로, 메모리 주소가 연속적으로 이어져있다.
 *      - 원소를 추가할 경우 해당 위치부터 마지막까지의 모든 원소가 위치 재할당이 이루어진다.
 * 
 * Node라는 자료를 정의한다.
 * Node라는 자료에 대하여 아래의 인터페이스를 제공해야한다.
 * 1. 데이터 추가
 * 2. 데이터 검색
 * 3. 데이터 수정
 * 4. 데이터 제거
 */

class Node {
    public:
    int data;
    Node* next = nullptr;
    Node(int data): data(data) {}

    void addNext(Node *node) {
        next = node;
    }
};

class LinkedList {
    int data;
};

int main() {
    Node* head = new Node(1);
    Node* b = new Node(2);
    Node* c = new Node(3);
    head->addNext(b);
    b->addNext(c);
    std::cout << a->next->data << std::endl;
    return 0;
}