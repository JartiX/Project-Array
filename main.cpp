#include "Array/Array.h"
#include <iostream>
#include <time.h>
#include <fstream>
using namespace std;

int answer(int N, int k) {
  Array arr(N);
  int index = 0;
  
  for (int i = 1; i <= N; i++) {
    arr.insert(i);
  }

  while (arr.getSize() > 1) {
    index = (index + k - 1) % arr.getSize();
    arr.remove(index);
  }
  return arr[0];
}
int main() {
  int arr[7] = {1000, 5000, 10000, 50000, 100000, 500000, 1000000};
  int k = 2;
  time_t start, end, diff;
  ofstream myfile("readme.md");
  
  myfile << "# Project-Array" << endl;
  myfile << "## Для всех тестов взято значение k=2" << endl;
  myfile << "| N | Ответ | Время рассчета |" << endl;
  myfile << "|-|-|-|" << endl;
  
  for (int i = 0; i < 7; i++) {
    time(&start);
    int a = answer(arr[i], k);
    time(&end);
    
    diff = end - start;
    
    cout << "Survivor: " << a << " Time taken: " << diff << " seconds" << endl;
    myfile << "|" << i << " | " << a << " | " << diff << "|" << endl;
  }
  
  myfile.close();

  return 0;
}