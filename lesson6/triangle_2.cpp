#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// 1 2 3 5 8 13 21 34 55 89 144 233 Fibonacci
// Negative values do not matter, after 50 values, reach 2^31
// We could also use radix sort for O(N)

int solution(vector<int> &A)
{
  size_t sizeA = A.size();
  if (sizeA < 3) return 0;

  vector<int> aux;

  for (size_t i = 0; i < A.size(); ++i) {
    if (A[i] > 0) {
      aux.push_back(A[i]);
      if (aux.size() > 50) return 1;
    }
  }

  sort(aux.begin(), aux.end());

  for (size_t i = 2; i < aux.size(); ++i) {
    if (int64_t(aux[i - 2]) + aux[i - 1] > aux[i]) {
      return 1;
    }
  }
 
  return 0;
}

int main()
{
  vector<int> input1{10, 2, 5, 1, 8, 20};
  cout << "10, 2, 5, 1, 8, 20 => 1: " << solution(input1) << endl;

  vector<int> input2{10, 50, 5, 1};
  cout << "10, 50, 5, 1 => 0: " << solution(input2) << endl;

  vector<int> input3{};
  cout << "{} => 0: " << solution(input3) << endl;

  vector<int> input4{1};
  cout << "{1} => 0: " << solution(input4) << endl;

  vector<int> input5{1, 2};
  cout << "{1, 2} => 0: " << solution(input5) << endl;

  vector<int> input6{2147483645, 2147483646, 2147483647};
  cout << "{2147483645, 2147483646, 2147483647} => 1: " << solution(input6) << endl;

  vector<int> input7{-2147483647, -2147483646, -2147483645};
  cout << "{-2147483645, -2147483646, -2147483647} => 0: " << solution(input7) << endl;
  return 0;
}
