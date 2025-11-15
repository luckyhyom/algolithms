#include <iostream>

#include "../linked-list.cpp"

/**
 * 결과 값 2473 구한다음
 * 0.1 곱한 후 소수점을 더하고 소수점 제거 반복
 * 언제까지? total이 0이거나 0보다 작을 때 까지
 */
LinkedList* sum_v1(LinkedList* ll, LinkedList* ll2) {
    LinkedList* result = new LinkedList();

    LinkedList::Node* first = ll->get(1);
    LinkedList::Node* second = ll2->get(1);

    double total = 0;
    int digit = 1;
    while (first != nullptr) {
        std::cout << "digit: " << digit << std::endl;
        total += first->data * digit;
        first = first->next;
        digit *= 10;
    }

    digit = 1;
    while (second != nullptr) {
        total += second->data * digit;
        second = second->next;
        digit *= 10;
    }

    while (total > 0) {
        total *= 0.1;
        int temp = total;
        int n = (total - temp) * 10;
        result->append(n);
        total = temp;
    }

    return result;
}

/**
 * 1. 길이
 * 2. 자릿수
 * 3. 자릿수 초과할 경우 다음으로 넘기기
 */
LinkedList* sum_v2(LinkedList* ll, LinkedList* ll2) {
    LinkedList* result = new LinkedList();
    LinkedList::Node* first = ll->get(1);
    LinkedList::Node* second = ll2->get(1);

    int length = 0;

    int length1 = 0;
    while (first != nullptr) {
        first = first->next;
        ++length1;
    }

    int length2 = 0;
    while (second != nullptr) {
        second = second->next;
        ++length2;
    }

    if (length1 > length2) {
        length = length1;
    } else {
        length = length2;
    }

    first = ll->get(1);
    second = ll2->get(1);

    int digit = 1;
    int temp = 0;
    for (size_t i = 0; i < length; ++i) {
        int r = temp;
        if (first != nullptr) {
            r += first->data * digit;
            first = first->next;
        }
        if (second != nullptr) {
            r += second->data * digit;
            second = second->next;
        }

        std::cout << r << std::endl;

        int nextDigit = digit * 10;
        if (r >= nextDigit) {
            temp = nextDigit;
            result->append((r - nextDigit) / digit);
        } else {
            result->append(r / digit);
            temp = 0;
        }

        digit = nextDigit;
    }

    return result;
}

LinkedList* sum_v3(LinkedList::Node* n1, LinkedList::Node* n2, int c) {
    if (n1 == nullptr && n2 == nullptr && c == 0) {
        return nullptr;
    }

    LinkedList::Node* next1 = nullptr;
    LinkedList::Node* next2 = nullptr;
    int a = 0;
    int b = 0;

    if (n1 != nullptr) {
        a = n1->data;
        next1 = n1->next;
    }

    if (n2 != nullptr) {
        b = n2->data;
        next2 = n2->next;
    }

    int sum = a + b + c;
    int result;
    if (sum >= 10) {
        c = 1;
        result = sum - 10;
    } else {
        result = sum;
        c = 0;
    }

    LinkedList* ll = new LinkedList();
    ll->append(result);

    LinkedList* l2 = sum_v3(next1, next2, c);
    if (l2 != nullptr) {
        ll->append(l2->get(1));
    }

    return ll;
}
/**
 * LL에는 값이 1의 자리부터 순차적으로 들어있다.
 * 1200이면 0021
 *
 * 이러한 LL 두개를 더하는 알고리즘
 */
int main() {
    LinkedList ll;

    // 1234
    ll.append(4);
    ll.append(3);
    ll.append(2);
    ll.append(1);

    // 1239
    LinkedList ll2;
    ll2.append(9);
    ll2.append(3);
    ll2.append(2);
    ll2.append(1);

    // 1234 + 1239 = 2473
    LinkedList* result = sum_v1(&ll, &ll2);
    result->retrieve();

    LinkedList* result2 = sum_v2(&ll, &ll2);
    result2->retrieve();

    LinkedList ll3;
    ll3.append(5);
    ll3.append(6);
    ll3.append(7);
    ll3.append(2);

    LinkedList ll4;
    ll4.append(6);
    ll4.append(3);
    ll4.append(2);
    ll4.append(1);
    ll4.append(5);

    LinkedList* sum3 = sum_v3(ll3.get(1), ll4.get(1), 0);  // 54001
    std::cout << "FUCK" << std::endl;
    sum3->retrieve();
}