#include <fstream>

void Sort(int& a, int& b) {
  if(a < b) {
    int temp = a;
    a = b;
    b = temp;
  }
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
      for (int j = i+1; j < size; j++)
      {
        ++count;
        Sort(arr[i], arr[j]);
      }
    }
    ofile << size << "," << count << std::endl;
  }
  return 0;
}