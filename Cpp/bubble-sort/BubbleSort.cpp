#include <fstream>
#include <iostream>

void Swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

int main() {
  std::ofstream ofile("log.txt");
  for (int size = 0; size < 1000; size++)
  {
    int *arr = new int[size];
    int count = 0;
    for (int i = 0; i < size; i++)
    {
      arr[i] = size - i;
    }

    for (int i = 0; i < size; i++)
    {
      for (int j = 0; j < size-1; j++)
      {
        ++count;
        if(arr[j] > arr[j+1]) {
          Swap(arr[j], arr[j+1]);
        }
      }
    }
    for (int i = 0; i < size; i++)
    {
      std::cout << arr[i] << ',';
    }
    std::cout << '\n' << std::endl;
    ofile << size << "," << count << std::endl;
  }
  return 0;
}