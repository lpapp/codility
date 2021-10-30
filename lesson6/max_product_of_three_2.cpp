#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int solution(vector<int> &A)
{
  int e0 = A[0];
  int last1 = e0;
  int last2 = 0;
  int last3 = 0;
  int e1 = A[1];
  int e2 = A[2];

  if (e1 > last1) { last2 = last1; last1 = e1; }
  else { last2 = e1; }

  if (e2 > last1) { last3 = last2; last2 = last1; last1 = e2; }
  else if (e2 > last2) { last3 = last2; last2 = e2; }
  else { last3 = e2; }

  int last_neg1 = 0;
  int last_neg2 = 0;
  if (e0 < 0) last_neg1 = e0;

  if (e1 < 0) {
    if (e1 < last_neg1) {last_neg2 = last_neg1; last_neg1 = e1; }
    else {last_neg2 = e1; }
  }

  if (e2 < 0) {
    if (e2 < last_neg1) {last_neg2 = last_neg1; last_neg1 = e1; }
    else if (e2 < last_neg2) {last_neg2 = e2; }
  }

  size_t sizeA = A.size();
  for (size_t i = 3; i < sizeA; ++i) {
    int e = A[i];
    if (A[i] < 0) {
      if (e < last_neg1) { last_neg2 = last_neg1; last_neg1 = e; }
      else if (e < last_neg2) last_neg2 = e;
    }
    else {
      if (e > last1) { last3 = last2; last2 = last1; last1 = e; }
      else if (e > last2) { last3 = last2; last2 = e; }
      else if (e > last3) { last3 = e; }
    }
  }

  return std::max(last_neg1 * last_neg2 * last1, last1 * last2 * last3);
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
  return 0;
}
