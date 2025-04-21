#include <bits/stdc++.h>

// O(n)
int func1(int N) {
  int result = 0;
  for (size_t i = 0; i <= N; i++)
  {
    if(i % 3 == 0 || i % 5 == 0) result += i;
  }
  
  return result;
}

// O(n^2)
int func2(int arr[], int N) {
  for (size_t i = 0; i < N; i++) {
    for (size_t j = i+1; j < N; j++) {
      int result = arr[i] + arr[j];
      if(result == 100) return 1;
    }
  }
  return 0;
}

int main() {
  std::cout << func1(16) << std::endl;
  std::cout << func1(34567) << std::endl;
  std::cout << func1(27639) << std::endl;

  int arr1[] = {1, 52, 48};
  int arr2[] = {50, 42};
  int arr3[] = {4, 13, 63, 87};
  std::cout << func2(arr1, 3) << std::endl;
  std::cout << func2(arr2, 2) << std::endl;
  std::cout << func2(arr3, 4) << std::endl;
}