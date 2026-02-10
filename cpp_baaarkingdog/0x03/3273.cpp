#include <bits/stdc++.h>

using namespace std;

int main() {
    int siz;
    int target;
    int result_count = 0;

    cin >> siz;
    std::vector<int> arr(siz, 0);
    for (size_t i = 0; i < arr.size(); ++i) {
        cin >> arr[i];
    }
    cin >> target;

    for (size_t i = 0; i < arr.size() - 1; ++i) {  // (A)를 size만큼 반복
        for (size_t j = 0; j < arr.size() - 1; ++j) {
            if (arr[j] > arr[j + 1]) {  // (A) 현재 값이 다음 값보다 크다면 다음으로 이동.. 맨 끝에서부터 큰 수가 채워진다.
                int temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
            }
        }
    }

    // 검색
    int left = 0;
    int right = arr.size() - 1;

    while (left < right) {
        int sum = arr[left] + arr[right];
        if (sum == target) {
            ++result_count;
            ++left;
            --right;
        } else if (sum > target) {
            --right;
        } else if (sum < target) {
            ++left;
        }
    }

    cout << result_count;

    return 0;
}

// 5 12 7 10 9 1 2 3 11

/**
 * 정렬 알고리즘
 * (brute force, merge sort, ...)
 *
 * 검색 알고리즘
 * 1) ni + nj의 결과가 x보다 크면 j를 -1한다.
 * 2) ni + nj의 결과가 x보다 작으면 i를 +1 한다.
 * 3) ni + nj의 결과가 x이면 i는 +1, j는 -1 한다.
 */