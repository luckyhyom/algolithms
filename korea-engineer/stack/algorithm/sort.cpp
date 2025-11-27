#include "../stack.cpp"

Stack* sort(Stack* s1) {
    Stack* s2 = new Stack();
    s2->push(s1->pop());

    while (s1->isEmpty() != true) {
        int x = s1->pop();
        int y = s2->pop();

        if (x >= y) {
            s2->push(y);
            s2->push(x);
        } else {
            int z = y;
            while (z > x || s2->isEmpty() != true) {
                s1->push(z);
                z = s2->pop();
            }
            s2->push(z);
            s2->push(x);
        }
    }

    return s2;
}

int main() {
    Stack s;
    s.push(3);
    s.push(5);
    s.push(1);
    s.push(6);

    s = *(sort(&s));

    while (s.isEmpty() != true) {
        std::cout << s.pop() << std::endl;
    }

    return 0;
}