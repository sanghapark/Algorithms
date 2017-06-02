#include <cstdlib>
#include <iostream>
#include <vector>

using std::vector;
using std::cin;
using std::cout;

// Compile
// clang++ -g ./01_AlgorithmicToolbox/week01/problem02/stresstest.cpp -std=c++14

int64_t MaxPairwiseProduct(const vector<int64_t>& numbers) {
  int64_t result = 0;
  int n = numbers.size();
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      if (numbers[i] * numbers[j] > result) {
        result = numbers[i] * numbers[j];
      }
    }
  }
  return result;
}

int64_t MaxPairwiseProductFast(const vector<int64_t>& numbers) {
  int64_t max1 = 0;
  int64_t max2 = 0;
  int n = numbers.size();
  for (int i = 0; i < n; i++) {
    int64_t number = numbers[i];
    if (number > max1) {
      max2 = max1;
      max1 = number;
    } else if (number > max2) {
      max2 = number;
    }
  }
  return max1 * max2;
}

int main() {

  // Stress Test
  while(true) {
    int n = rand() % 10 + 2;
    cout << n << "\n";
    vector<int64_t> a;
    for (int i = 0; i < n; i++) {
      a.push_back(rand() % 100000);
    }
    for (int i = 0; i < n; i++) {
      cout << a[i] << ' ';
    }
    cout << "\n";
    int64_t res1 = MaxPairwiseProduct(a);
    int64_t res2 = MaxPairwiseProductFast(a);
    if (res1 != res2) {
      cout << "Wrong answer: " << res1 << ' ' << res2 << "\n";
      break;
    } else {
      cout << "OK\n";
    }
  }

  int64_t n;
  cin >> n;
  vector<int64_t> numbers(n);
  for (int i = 0; i < n; ++i) {
      cin >> numbers[i];
  }

  int64_t result = MaxPairwiseProductFast(numbers);
  cout << result << "\n";
  return 0;
}
