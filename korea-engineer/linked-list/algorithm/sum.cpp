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

    int result = c;
    if (n1 != nullptr) {
        result += n1->data;
    }
    if (n2 != nullptr) {
        result += n2->data;
    }

    c = result >= 10 ? 1 : 0;
    result = result % 10;

    LinkedList* ll = new LinkedList();
    ll->append(result);

    LinkedList* l2 = sum_v3(n1 != nullptr ? n1->next : nullptr, n2 != nullptr ? n2->next : nullptr, c);
    if (l2 != nullptr) {
        ll->append(l2->get(1));
    }

    return ll;
}

int getLength(LinkedList::Node* node) {
    if (node == nullptr) {
        return 0;
    }
    int result = 1;
    while (node->next != nullptr) {
        ++result;
        node = node->next;
    }
    return result;
}

LinkedList::Node* insertBefore(LinkedList::Node* node, int value) {
    LinkedList::Node* result = new LinkedList::Node(value, 0);
    if (node != nullptr) {
        result->append(node);
    }
    return result;
}

LinkedList::Node* LPadList(LinkedList::Node* node, int length) {
    for (size_t i = 0; i < length; i++) {
        node = insertBefore(node, 0);
    }
    return node;
}

/**
 * 1. 각 리스트의 길이를 구한다.
 * 2. 길이가 짧은 리스트의 길이를 동일하게 설정한다.
 * 3. 맨 마지막 노드부터 더한다.
 * 4. carry를 저장하기위한 포인터 변수 필요하다.
 * 5. result(매개변수)는 왜필요하지?
 */
LinkedList* sum_v4_a(LinkedList::Node* n1, LinkedList::Node* n2, int* c) {
    if (n1 == nullptr) {
        return new LinkedList();
    }
    LinkedList* result = sum_v4_a(n1->next, n2->next, c);
    int sum = n1->data + n2->data + *c;
    *c = sum >= 10 ? 1 : 0;
    int value = sum % 10;
    LinkedList::Node* node = insertBefore(result->get(1), value);
    LinkedList* r = new LinkedList();
    r->append(node);

    // head의 next 즉, 첫번째 node를 현재로서는 바꾸기 어렵네. head를 수정해야하는데 그것에 접근할 수 없으니
    return r;
}

LinkedList* sum_v4(LinkedList::Node* n1, LinkedList::Node* n2) {
    // 재귀는 언제 돌리지, 얘는 반복실행될 필요 없을 것 같은데.
    int n1L = getLength(n1);
    int n2L = getLength(n2);

    if (n1L > n2L) {
        n2 = LPadList(n2, n1L - n2L);
    } else if (n2L > n1L) {
        n1 = LPadList(n1, n2L - n1L);
    }
    int c = 0;
    LinkedList* result = new LinkedList();
    LinkedList* list = sum_v4_a(n1, n2, &c);
    if (c == 1) {
        result->append(1);
    }
    result->append(list->get(1));
    return result;
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

    ll.reset();
    ll2.reset();

    ll.append(5);
    ll.append(6);
    ll.append(7);
    ll.append(2);

    ll2.append(6);
    ll2.append(3);
    ll2.append(2);
    ll2.append(1);
    ll2.append(5);

    LinkedList* sum3 = sum_v3(ll.get(1), ll2.get(1), 0);  // 54001
    sum3->retrieve();

    ll.reset();
    ll2.reset();

    ll.append(9);
    ll.append(1);
    ll.append(9);

    ll2.append(8);
    ll2.append(4);
    LinkedList* sum4 = sum_v4(ll.get(1), ll2.get(1));  // 54001
    sum4->retrieve();
}