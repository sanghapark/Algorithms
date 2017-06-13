#include <iostream>

// Compile
// clang++ -g ./01_AlgorithmicToolbox/week02/problem02/fibonacci_last_digit.cpp -std=c++14

int get_fibonacci_last_digit_naive(int n) {
    if (n <= 1)
      return n;

    int previous = 0;
    int current  = 1;

    for (int i = 0; i < n - 1; ++i) {
      int tmp_previous = previous;
      previous = current;
      current = (tmp_previous + current) % 10;
    }

    return current;
}

int main() {
  int n;
  std::cin >> n;
  int c = get_fibonacci_last_digit_naive(n);
  std::cout << c << '\n';
}
