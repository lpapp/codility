#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int solution(vector<int> &A)
{
  size_t sizeA = A.size();
  if (sizeA <= 4) { sort(A.begin(), A.end()); }
  else {
    partial_sort(A.rbegin(), A.rbegin() + 3, A.rend(), std::greater<int>());
    partial_sort(A.begin(), A.begin() + 2, A.end() - 3);
  }

  return std::max(A[0] * A[1] * A[sizeA - 1], A[sizeA - 3] * A[sizeA - 2] * A[sizeA - 1]);
}

int main()
{
  vector<int> input1{-3, 1, 2, -2, 5, 6};
  cout << "{-3, 1, 2, -2, 5, 6} => 60: " << solution(input1) << endl;

  vector<int> input2{-1000, -1000, 1000};
  cout << "{-1000, -1000, 1000} => 1000000000: " << solution(input2) << endl;

  vector<int> input3{-10, -2, -4};
  cout << "{-10, -2,-4} => -80: " << solution(input3) << endl;

  vector<int> input4{4, 7, 3, 2, 1, -3, -5};
  cout << "{4, 7, 3, 2, 1, -3, -5} => 105: " << solution(input4) << endl;

  vector<int> input5{-2, -1, -2, -1};
  cout << "{-2, -1, -2, -1} => -2: " << solution(input5) << endl;

  vector<int> input6{-2, -1, 0, -2, -1};
  cout << "{-2, -1, 0, -2, -1} => 0: " << solution(input6) << endl;

  return 0;
}
