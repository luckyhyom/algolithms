/**
 * 한 쪽은 넣기만 하고, 한쪽은 꺼내기만 한다.
 * FIFO: First In First Out
 */

#include <iostream>




template <typename T>
class Queue {
    class Node {
    public:
        T data;
        Node* next;
        // Note: Reference 복습
        Node(const T data): data(data), next(nullptr) {}
    };
    Node *first;
    Node *last;

    public:
        Queue() : first(nullptr), last(nullptr) {}   // ← 추가: 초기화
        void add(T data) {
            Node *newNode = new Node(data);
            // 첫번째 node일 경우 last의 next는 설정하지 않는다.
            if(this->first == nullptr) {
                this->first = newNode;
                this->last = newNode;
                return;
            }

            /**
             * Note: 이 두 라인의 순서가 바뀌면 안된다. 방어로직을 짤 수 있을까?
             */
            this->last->next = newNode;
            this->last = newNode;
        }

        /**
         * first를 바로 다음 Node로 교체해야한다.
         * Node가 자신의 앞, 뒤 Node를 알고 있다면 Queue가 모든 Node를 알고 있지 않아도 된다.
         * 
         * Note:
         *  Node의 개수가 고정되어 있지 않다.
         */
        void remove() {
            if (this->first == nullptr) { throw "Queue is already Empty."; }
            Node* old = this->first;
            this->first = this->first->next;
            if (this->first == nullptr) this->last = nullptr; // 마지막 제거 시 정리
            delete old;
        }

        T peek() {
            if (this->first == nullptr) { throw "Queue is Empty"; }
            return this->first->data;
        }

        bool isEmpty() {
            return this->first == nullptr;
        }
};




int main() {
    Queue<int> *q = new Queue<int>();
    q->add(1);
    q->add(2);
    q->add(3);
    q->add(4);

    q->remove();
    q->remove();
    std::cout << q->peek() << std::endl;
    q->remove();
    std::cout << std::boolalpha << q->isEmpty() << std::endl;
    q->remove();
    std::cout << std::boolalpha << q->isEmpty() << std::endl;
    
    return 0;
}