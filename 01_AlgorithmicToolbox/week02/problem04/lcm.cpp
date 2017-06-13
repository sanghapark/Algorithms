#include <iostream>

// Compile
// clang++ -g ./01_AlgorithmicToolbox/week02/problem04/lcm.cpp -std=c++14

long long gcd_euclidean(long long a, long long b) {
  long long bigger = a >= b ? a : b;
  long long smaller = a < b ? a : b;
  long long remainder = bigger % smaller;
  // std::cout << bigger << " % " << smaller << " = " <<remainder << std::endl;
  if (remainder == 0) {
    return smaller;
  }
  return gcd_euclidean(smaller, remainder);
}


long long lcm_naive(int a, int b) {
  for (long l = 1; l <= (long long) a * b; ++l)
    if (l % a == 0 && l % b == 0)
      return l;

  return (long long) a * b;
}

long long lcm(long long a, long long b) {
  long long gcd = gcd_euclidean(a , b);
  return (a*b) / gcd;
}

int main() {
  long long a, b;
  std::cin >> a >> b;
  // std::cout << lcm_naive(a, b) << std::endl;
  std::cout << lcm(a, b) << std::endl;
  return 0;
}
