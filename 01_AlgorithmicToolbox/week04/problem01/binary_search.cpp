// Compile
// clang++ -g ./01_AlgorithmicToolbox/week04/problem01/binary_search.cpp -std=c++14

#include <iostream>
#include <cassert>
#include <vector>
#include <ctime>

using std::vector;

int binary_search(const vector<int> &a, int x) {
  int left = 0, right = (int)a.size(); 
  //write your code here
  while (left <= right) {
    int pivot = ((right - left) / 2) + left;
    if (x < a[pivot]) {
      right = pivot - 1;
    } else if (x > a[pivot]) {
      left = pivot + 1;
    } else {
      return pivot;
    }
  }
  return -1;
}

int linear_search(const vector<int> &a, int x) {
  for (size_t i = 0; i < a.size(); ++i) {
    if (a[i] == x) return i;
  }
  return -1;
}

int main() {

  srand ( time(NULL) );
  while(true) {
    int n = rand() % 10 + 1;
    vector<int> a(n);
    for (size_t i = 0; i < n; i++) {
      a[i] = i + 1;
    }
    int bi = binary_search(a, n);
    int li = linear_search(a, n);
    if (bi != li) {
      std::cout << "Key: " << n << std::endl;
      for (int i = 0; i < a.size(); i++) {
        std::cout << a[i] << ' ';
      }
      std::cout << std::endl;
      std::cout << "wrong: " << bi << " != " << li << std::endl;;
      break;
    } else {
      std::cout << "good" << std::endl;
    }
  }


  // int n;
  // std::cin >> n;
  // vector<int> a(n);
  // for (size_t i = 0; i < a.size(); i++) {
  //   std::cin >> a[i];
  // }
  // int m;
  // std::cin >> m;
  // vector<int> b(m);
  // for (int i = 0; i < m; ++i) {
  //   std::cin >> b[i];
  // }
  // for (int i = 0; i < m; ++i) {
  //   //replace with the call to binary_search when implemented
  //   // std::cout << linear_search(a, b[i]) << ' ';
  //   std::cout << binary_search(a, b[i]) << ' ';
  // }
}
