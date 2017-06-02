#include <iostream>
#include <vector>

using std::vector;
using std::cin;
using std::cout;

int64_t MaxPairwiseProduct(const vector<int64_t>& numbers) {
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
    int64_t n;
    cin >> n;
    vector<int64_t> numbers(n);
    for (int i = 0; i < n; ++i) {
        cin >> numbers[i];
    }

    int64_t result = MaxPairwiseProduct(numbers);
    cout << result << "\n";
    return 0;
}
