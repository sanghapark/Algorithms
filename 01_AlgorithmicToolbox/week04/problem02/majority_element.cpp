// Compile
// clang++ -g ./01_AlgorithmicToolbox/week04/problem02/majority_element.cpp -std=c++14

#include <algorithm>
#include <iostream>
#include <vector>
#include <ctime>

using std::vector;

int naive(const vector<int> &a) {
  for (int i = 0; i < a.size(); i++) {
    int item = a[i];
    int count = 0;
    for (int j = 0; j < a.size(); j++) {
      if (a[j] == item) {
        count++;
      }
    }
    if (count > a.size() / 2) {
      return i;
    }
  }
  return -1;
}


int get_majority_element(vector<int> &a, int left, int right) {
  if (left == right) return -1;
  if (left + 1 == right) return a[left];
  std::sort(a.begin(), a.end());
  int count = 1;
  for (int i = 1; i < a.size(); i++) {
    if(a[i] != a[i-1])
      count = 1;
    else
      count++;
    
    if (count > a.size()/2)
      return count;
  }
  return -1;
}

int main() {
  // ** Stress TEST **
  // srand ( time(NULL) );
  // while(true) {
  //   int n = rand() % 100000 + 1;
  //   vector<int> a(n);
  //   for (size_t i = 0; i < n; i++) {
  //     a[i] = rand() % 1000000000 + 1;
  //   }
  //   bool maj = get_majority_element(a, 0, a.size()) != -1;
  //   bool nai = naive(a) != -1;
  //   if (maj != nai) {
  //     std::cout << "wrong: " << maj << " != " << nai << std::endl;;
  //     std::cout << a.size() << std::endl;
  //     for (int i = 0; i < a.size(); i++) {
  //       std::cout << i << ": " << a[i] << std::endl;
  //     }
  //     std::cout <<  get_majority_element(a, 0, a.size()) << std::endl;
  //     std::cout <<  naive(a) << std::endl;
  //     break;
  //   } else {
  //     std::cout << "good" << std::endl;
  //   }
  //   a.clear();
  // }

  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  std::cout << (get_majority_element(a, 0, a.size()) != -1) << '\n';
}
