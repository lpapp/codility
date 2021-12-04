#include <iostream>
#include <vector>

using namespace std;

/*
  1. Binary search over the C elements
  2. For each iteration, create a prefix sums of nails up the current binary
     search iterations. This will require two steps:
     a. Count the occurences of nail positions in C.
     b. Create the proper prefix sums about the available nails at a
        particular index.
  3. If there is no nail in a plank range, then a nail cannot be found there,
     so there cannot be a solution for the task.
  4. If there is no solution in that consecutive array, we need to look for a
     longer range.
  5. If there is a solution in that consecutive sequence, we need to look for
     a smaller range.
  6. The binary search goes on until we eventually find the smallest range.

  The runtime complexity of the binary search is log(M) since we are bisecting
  a range of M. The runtime complexity of the inner iteration comes from three
  loops:

    a. O(Mid), where mid < M. So, this is O(M) in worst case.
    b. O(2M), which is O(M) as we can leave the constant.
    c. O(N), going through the number of elements in A and B.

  Therefore, the runtime complexity of the inner loop is M + N.

  The overall runtime complexity of the algorithm is therefore O(log(M) * (M +
  N)).

  The overall space complexity is O(2 * M) for the prefix sums, so essentially
  O(M).
*/

bool check(vector<int> &A, vector<int> &B, vector<int> &C, int mid)
{
  const int M = C.size();
  vector<int> prefix_sums(2 * M + 1, 0);
  for (int i = 0; i < mid; ++i) ++prefix_sums[C[i]];
  for (size_t i = 1; i < prefix_sums.size(); ++i) prefix_sums[i] += prefix_sums[i - 1];
  for (size_t i = 0; i < A.size(); ++i) if (prefix_sums[B[i]] == prefix_sums[A[i] - 1]) return false;
  return true;
}

int solution(vector<int> &A, vector<int> &B, vector<int> &C)
{
  int start = 1;
  int end = C.size();
  int min_nails = -1;
  while (start <= end) {
    const int mid = (start + end) / 2;
    if (check(A, B, C, mid)) { end = mid - 1; min_nails = mid; }
    else start = mid + 1;
  }
  return min_nails;
}

int main()
{
  // => mid = 3, prefix_sums for [4, 6, 7]
  vector<int> A1{1, 4, 5, 8};
  vector<int> B1{4, 5, 9, 10};
  vector<int> C1{4, 6, 7, 10, 2};
  cout << "1, 4, 5, 8 - 4, 5, 9, 10 - 4, 6, 7, 10, 2 => 4: " << solution(A1, B1, C1) << endl;

  return 0;
}
