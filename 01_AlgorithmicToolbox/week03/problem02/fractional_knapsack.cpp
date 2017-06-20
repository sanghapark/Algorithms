// Compile
// clang++ -g ./01_AlgorithmicToolbox/week03/problem02/fractional_knapsack.cpp -std=c++14

#include <iostream>
#include <vector>

using std::vector;

int find_max_unit_value_index(vector<int> weights, vector<int>values) {
  int index = -1;
  double max_unit_value = 0;
  for(int i = 0; i < weights.size(); i++) {
    double unit_value = (double)values[i] / (double)weights[i];
    if (unit_value > max_unit_value) {
      max_unit_value = unit_value;
      index = i;
    }
  }
  return index;
}

double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
  double value = 0.0;

  // write your code here
  while (capacity > 0 && weights.size() > 0) {
    int max_unit_index = find_max_unit_value_index(weights, values);
    if (max_unit_index < 0) {
      return value;
    }
    if (capacity < weights[max_unit_index]) {
      value += ((double)values[max_unit_index] / (double)weights[max_unit_index] * (double)capacity);
      capacity = 0;
    } else {
      value += (double)values[max_unit_index];
      capacity -= weights[max_unit_index];
      weights.erase(weights.begin() + max_unit_index);
      values.erase(values.begin() + max_unit_index);
    }
  }
  return value;
}



int main() {
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  std::cout.precision(10);
  std::cout << optimal_value << std::endl;
  return 0;
}
