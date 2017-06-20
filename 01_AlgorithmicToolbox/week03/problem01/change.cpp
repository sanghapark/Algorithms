#include <iostream>

// Compile
// clang++ -g ./01_AlgorithmicToolbox/week03/problem01/change.cpp -std=c++14

int get_change(int m) {
  //write your code here
  int n = 0;
  while (m > 0) {
    if (m >= 10) {
      n += (m - (m % 10)) / 10;
      m = m % 10;
    } else if (m >= 5) {
      n += (m - (m % 5)) / 5;
      m = m % 5;
    } else {
      n += (m - (m % 1)) / 1;
      m = 0;
    }
  }
  return n;
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
