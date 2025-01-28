#include <iostream>


bool CheckSorted(int* a, int len) {
  for (int i = 0; i < len - 1; i++) {
    if (a[i] < a[i+1]) return false;
  }
  return true;
}

void MySort(int& a, int& b) {
  if(a < b) {
    int temp = a;
    a = b;
    b = temp;
  }
}

int main() {
  for (int k = 0; k < 3; k++) {
    for (int j = 0; j < 3; j++) {
      for (int i = 0; i < 3; i++){
        int arr[3] = { i, j, k};
        //int size = sizeof(arr) / sizeof(arr[0]);
        int size = 3;

        for (int e = 0; e < size; e++) {
          std::cout << arr[e] << " " << std::flush;
        }
        
        std::cout << '\n' << std::flush;

        // 정렬
        //MySort(arr[0], arr[1]);
        //MySort(arr[0], arr[2]);
        //MySort(arr[1], arr[2]);

        for (int i = 0; i < 3; i++) {
          for (int j = i+1; j < 3; j++) {
            MySort(arr[i], arr[j]);
          }
        }
        

        for (int e = 0; e < size; e++) {
          std::cout << arr[e] << " " << std::flush;
        }

        std::cout << std::boolalpha;
        std::cout << CheckSorted(arr, size); // 정렬 여부 확인
        std::cout << std::endl;
      }
    }
  }
  
}

/**
temp 없이 swap하기

a = 1
b = 2

a = a + b
b = a - b
a = a - b
 */