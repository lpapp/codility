#include <iostream>
#include <vector>

using namespace std;

/*
  1. If the inputs are empty, return zero as there is no segment available.
  2. If the inputs are not empty, there is at least one non-overlapping
     segment, the first one. Set the end of this from the B inputs as the
     current end. 
  3. The current end is used to to compare the A values against. The A value of
     the next acceptable A-B needs to be greater than the current end to be
     able to add it to the non-overlapping segments.
  4. When it is so, increment the counter and set the end of the current A-B
     pair as the current end for subsequent comparison.
  5. Iterate until we reach the end of the pairs.

  The runtime complexity of this solution is O(N) because we go through the
  pairs in the loop.

  The space complexity of this solution is O(1) because we only allocate
  constant memory for solving the task, independently from the number of inputs.
 */

int solution(vector<int> &A, vector<int> &B)
{
  if (A.empty()) return 0;
  const int N = A.size();
  int max_nonoverlapping_segments = 1;
  for (int i = 1, end = B.front(); i < N; ++i) {
    if (A[i] > end) { ++max_nonoverlapping_segments; end = B[i]; }
  }
  return max_nonoverlapping_segments;
}

int main()
{
  vector<int> A1{1, 3, 7, 9, 9};
  vector<int> B1{5, 6, 8, 9, 10};
  cout << "1, 3, 7, 9, 9 - 5, 6, 8, 9, 10 => 3: " << solution(A1, B1) << endl;
  return 0;
}
