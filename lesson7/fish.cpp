#include <iostream>
#include <stack>
#include <vector>

using namespace std;

// 1. All fish flowing upstream survivors
// 2. Push all fish flowing downstream unto the stack
// 3. Check fish flowing upstream how many fish flowing downstream it can eat
//   a. if all, it is a survivor. Count all fish flowing upstream as survivors.
//      Repeat 2.
//   b. if not all and gets eaten by a fish flowing from upstream to
//      downstream, repeat 2.
// 4. At any point where we have examined all fishes, add stack size to
// survivors and return.

int solution(vector<int> &A, vector<int> &B)
{
  int survivors = 0;
  size_t sizeA = A.size();
  size_t i = 0;

  for (; i < sizeA && !B[i]; ++i, ++survivors);
  if (i == sizeA) return survivors;

  stack<int> st;
  while (1) {
    for (; i < sizeA && B[i]; ++i) st.push(i);
    if (i == sizeA) break;

    while (A[st.top()] < A[i]) {
      st.pop();
      if (st.empty()) {
        for (; i < sizeA && !B[i]; ++i, ++survivors);
        if (i == sizeA) return survivors;
        --i;
        break;
      }
    }
    ++i;
  }

  survivors += st.size();
  return survivors;
}

int main()
{
  vector<int> A1{4, 3, 2, 1, 5};
  vector<int> B1{0, 1, 0, 0, 0};
  cout << "{4, 3, 2, 1, 5}, {0, 1, 0, 0, 0} => 2: " << solution(A1, B1) << endl;

  vector<int> A2;
  for (size_t i = 0; i < 100000; ++i) {
    A2.push_back(i);
  }
  vector<int> B2(100000, 0);
  cout << "{0 1 3, 4, ... 99999}, {0, 0, 0, 0, ..., 0} => 100000: " << solution(A2, B2) << endl;

  vector<int> A3;
  for (size_t i = 0; i < 100000; ++i) {
    A3.push_back(i);
  }
  vector<int> B3(100000, 1);
  cout << "{0 1 3, 4, ... 99999}, {1, 1, 1, 1, ..., 1} => 100000: " << solution(A3, B3) << endl; 

  vector<int> A4{1, 2, 3, 4, 5, 6};
  vector<int> B4{0, 0, 0, 1, 1, 1};
  cout << "{1, 2, 3, 4, 5, 6}, {0, 0, 0, 1, 1, 1} => 6: " << solution(A4, B4) << endl;

  vector<int> A5{1, 3, 2, 4, 6, 4};
  vector<int> B5{1, 0, 1, 0, 1, 0};
  cout << "{1, 3, 2, 4, 6, 4}, {1, 0, 1, 0, 1, 0} => 3: " << solution(A5, B5) << endl;

  vector<int> A6{6, 5, 4, 3, 100, 1};
  vector<int> B6{1, 0, 1, 1, 0, 1};
  cout << "{6, 5, 4, 3, 100, 1}, {1, 0, 1, 1, 0, 1} => 2: " << solution(A6, B6) << endl;
  return 0;
}
