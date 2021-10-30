#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int solution(vector<int> &A)
{
  size_t sizeA = A.size();
  sort(A.begin(), A.end());
  return std::max(A[0] * A[1] * A[sizeA - 1], A[sizeA - 3] * A[sizeA - 2] * A[sizeA - 1]);
}

int main()
{
  vector<int> input1{-3, 1, 2, -2, 5, 6};
  cout << "{-3, 1, 2, -2, 5, 6} => 60: " << solution(input1) << endl;

  vector<int> input2{-1000, -1000, 1000};
  cout << "{-1000, -1000, 1000} => 1000000000: " << solution(input2) << endl;
  return 0;
}
