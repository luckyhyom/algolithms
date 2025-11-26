#include "../../stack/stack.cpp"

class QueueByStack {
    Stack* s1;
    Stack* s2;

   public:
    QueueByStack() {
        s1 = new Stack();
        s2 = new Stack();
    }

    void add(int v) { s1->push(v); }

    int remove() {
        if (s2->isEmpty()) {
            while (s1->isEmpty() != true) {
                s2->push(s1->pop());
            }
        }
        return s2->pop();
    }

    int peek() {
        if (s2->isEmpty()) {
            while (s1->isEmpty() != true) {
                s2->push(s1->pop());
            }
        }
        return s2->peek();
    }

    bool isEmpty() {
        if (s2->isEmpty()) {
            while (s1->isEmpty() != true) {
                s2->push(s1->pop());
            }
        }
        return s2->peek() == 0 ? 1 : 0;
    }
};

int main() {
    QueueByStack q;
    q.add(1);
    q.add(2);
    q.add(3);
    q.add(4);

    std::cout << q.remove() << std::endl;
    std::cout << q.remove() << std::endl;
    std::cout << q.remove() << std::endl;
    std::cout << q.peek() << std::endl;
    std::cout << std::boolalpha << q.isEmpty() << std::endl;
    std::cout << q.remove() << std::endl;
    std::cout << q.isEmpty() << std::endl;

    q.add(1);
    std::cout << q.remove() << std::endl;

    return 0;
}