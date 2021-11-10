#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

int check(vector<int>& A, int largest_sum)
{
  int sum = 0;
  int count = 0;
  for (size_t i = 0; i < A.size(); ++i) {
    const int e = A[i];
    if ((sum + e) > largest_sum) { sum = 0; ++count; }
    sum += e;
  }

  return count;
}

int solution(int K, int /*M*/, vector<int> &A)
{
  int start = *max_element(A.begin(), A.end());
  int end = accumulate(A.begin(), A.end(), 0);
  while (start <= end) {
    int mid = (start + end) / 2;
    if (check(A, mid) < K) end = mid - 1;
    else start = mid + 1;
  }
  return start;
}

int main()
{
  vector<int> i1{2, 1, 5, 1, 2, 2, 2};
  cout << "2, 1, 5, 1, 2, 2, 2 | 3 | 5 => 6: " << solution(3, 5, i1) << endl;

  // max: 6
  // sum: 21
  // -> E.g. try 12: {4 3} {6, 2, 1} {5}
  // -> E.g. try 8: {4 3} {6, 2} {1 5}
  // -> E.g. try 7: {4 3} {6} {2, 1} {5}
  vector<int> i2{4, 3, 6, 2, 1, 5};
  cout << "2, 1, 5, 1, 2, 2, 2 | 3 | 6 => 8: " << solution(3, 6, i2) << endl;

  // max: 1
  // sum: 8
  // -> 4
  // {1 1 1 1} {1 1 1 1}
  // -> 3
  // {1 1 1} {1 1 1} {1 1}
  // -> 2
  // {1 1} {1 1} {1 1} {1 1}
  vector<int> i3{1, 1, 1, 1, 1, 1, 1, 1};
  cout << "1, 1, 1, 1, 1, 1, 1, 1 | 4 | 6 => 2: " << solution(4, 1, i3) << endl;
}
