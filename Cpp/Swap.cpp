#include <iostream>

void mySwap(int& a, int& b) {
  int temp = a;
  a = b;
  b = temp;
}

/*
  1. 주소끼리 스왑도 가능 (이중 포인터일 경우)
  2. *a = *b -> a접시에 있는 물건을 b접시의 물건으로 바꿔줘
*/
void mySwap(int* a, int* b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

bool checkSorted(int a, int b) {
  return (a <= b);
}

void sort_desc(int* list, int length) {
  for (int i = 0; i < length; i++) {
    // 포인터는 고정
    int* max = &list[i];
    for (int j = i; j < length; j++) {
      if (*max < list[j]) { 
        // 값만 치환한다.
        mySwap(*max, list[j]); 
      }
    }
  }
}

int main() {
  // swap
  {
    int a = 3;
    int b = 2;
    std::cout << a << " " << b << std::endl;
    mySwap(a, b);
    std::cout << a << " " << b << std::endl;
  }

  // sorting
  {
    int arr[2] = {0, 0};
    for (int i = 0; i < 5; i++) {
      for (int j = 0; j < 5; j++) {
        arr[0] = i;
        arr[1] = j;
        std::cout << std::boolalpha;
        std::cout << arr[0] << "," << arr[1] << " -> " << checkSorted(arr[0], arr[1]) << std::endl;
      }
    }
    for (int i = 0; i < 5; i++) {
      for (int j = 0; j < 5; j++) {
        arr[0] = i;
        arr[1] = j;
        if(arr[0] > arr[1]) {
          mySwap(arr[0], arr[1]);
        }
        std::cout << std::boolalpha;
        std::cout << arr[0] << "," << arr[1] << " -> " << checkSorted(arr[0], arr[1]) << std::endl;
      }
    }
  }

  // sorting
  {
    int arr[3] = {1, 2, 3};
    for (int i = 0; i < 3; i++) {
      std::cout << arr[i] << std::endl;
    }
    sort_desc(arr, 3);
    for (int i = 0; i < 3; i++) {
      std::cout << arr[i] << std::endl;
    }
  }

  return 0;
}