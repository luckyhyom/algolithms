#include <bits/stdc++.h>
using namespace std;

/**
 *
 * 10 20 30
 *
 * (1)
 * temp: 30
 * 10 20 30 40
 *
 * (2)
 * temp: 30
 * 10 20 20 40
 * (40을 temp에 저장하고 temp에 있던 값으로 대체해야함)
 *
 * (3)
 * temp: 30
 * 10 20 20
 *
 *
 * temp: 30
 * 10 20 20 0
 *
 * temp: 30
 * 10 20 20 30
 */

void insert(int idx, int num, int arr[], int& len) {
    // (1) 길이를 1 더한다.
    ++len;

    // (2) 배열의 끝에서부터 순회한다.
    for (size_t i = len; i > idx; --i) {
        // (3) 앞 원소의 값을 현재 위치에 복사한다.
        arr[i] = arr[i - 1];
    }

    // (4) arr[idx]에 추가할 값을 저장
    arr[idx] = num;
}

void erase(int idx, int arr[], int& len) {
    // (1) 길이를 1 줄인다.
    --len;
    //  (2) idx 부터 순회한다.
    for (size_t i = idx; i < len; i++) {
        // (3) i번째 원소에 다음 원소의 값을 복사한다.
        arr[i] = arr[i + 1];
    }
}

void printArr(int arr[], int& len) {
    for (int i = 0; i < len; i++) cout << arr[i] << ' ';
    cout << "\n\n";
}

void insert_test() {
    cout << "***** insert_test *****\n";
    int arr[10] = {10, 20, 30};
    int len = 3;
    insert(3, 40, arr, len);  // 10 20 30 40
    printArr(arr, len);
    insert(1, 50, arr, len);  // 10 50 20 30 40
    printArr(arr, len);
    insert(0, 15, arr, len);  // 15 10 50 20 30 40
    printArr(arr, len);
}

void erase_test() {
    cout << "***** erase_test *****\n";
    int arr[10] = {10, 50, 40, 30, 70, 20};
    int len = 6;
    erase(4, arr, len);  // 10 50 40 30 20
    printArr(arr, len);
    erase(1, arr, len);  // 10 40 30 20
    printArr(arr, len);
    erase(3, arr, len);  // 10 40 30
    printArr(arr, len);
}

int main(void) {
    insert_test();
    erase_test();
}