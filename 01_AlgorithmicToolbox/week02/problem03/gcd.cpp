#include <iostream>

// Compile
// clang++ -g ./01_AlgorithmicToolbox/week02/problem03/gcd.cpp -std=c++14

int gcd_naive(int a, int b) {
  int current_gcd = 1;
  for (int d = 2; d <= a && d <= b; d++) {
    if (a % d == 0 && b % d == 0) {
      if (d > current_gcd) {
        current_gcd = d;
      }
    }
  }
  return current_gcd;
}

int gcd_euclidean(int a, int b) {
  int bigger = a >= b ? a : b;
  int smaller = a < b ? a : b;
  int remainder = bigger % smaller;
  // std::cout << bigger << " % " << smaller << " = " <<remainder << std::endl;
  if (remainder == 0) {
    return smaller;
  }
  return gcd_euclidean(smaller, remainder);
}

int main() {
  int a, b;
  std::cin >> a >> b;
  // std::cout << gcd_naive(a, b) << std::endl;
  std::cout << gcd_euclidean(a, b) << std::endl;
  return 0;
}
