#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/*
  Base idea from: https://codility.com/media/train/solution-min-abs-sum.pdf
  with some constant optimisation.

  1. Calculate the maximum absolute element of the inputs.
  2. Calculate the absolute sum of the inputs.
  3. Count the number of occurrence of each number in the inputs. Store the
     results in a vector hash.
  4. Go through each possible input (ignoring signs via abs) if they had
     occurred. Skip those that do not occur.
  5. For each occurring input, goes through all possible sums possible with
     this occuring input. It is a slight constant optimisation to go only up to
     half of the possible sums.
  6. For each sum that has been made before checking the current input, set the
     occurrence count of the current input.
  7. Check for each potential sum equal to or greater than the current input
     whether this input has already been used before. And only if the current
     sum had not been made yet. Update the values at the current sum
     accordingly. We do not need to check for potential sums less than the
     current input in this iteration, since it is evident that it has not been
     used before.
  8. The above nested loop will fill in each possible sum with a value greater
     than -1.
  9. Go through this possible sum hash again to look for the closest sum to
     half that is possible to make. Eventually, the min abs sum will be the
     difference of this from the half multiplied by two as the difference will
     be added up in both groups as the difference from the median.

  The runtime complexity of this algorithm is O(N * max(abs(A)) ^ 2), or simply
  O(N * M ^ 2). That is because the outer loop is iterating M times and the
  inner loop is iterating sum times. The sum is basically N * M in worst case.
  Therefore, it is O(M * N * M).

  The space complexity of this solution is O(N * M) because we allocate a hash
  of M items for the counts and a hash of S items for the sums. S is N * M
  again.
 */

int solution(vector<int> &A)
{
  int M = 0, S = 0;
  for (const int e : A) { M = max(abs(e), M); S += abs(e); }
  vector<int> counts(M + 1, 0);
  for (const int e : A) { ++counts[abs(e)]; }
  vector<int> sums(S + 1, -1);
  sums[0] = 0;
  for (int ci = 1; ci < counts.size(); ++ci) {
    if (!counts[ci]) continue;
    for (int si = 0; si < S / 2 + 1; ++si) {
      if (sums[si] >= 0) sums[si] = counts[ci];
      else if (si >= ci and sums[si - ci] > 0) sums[si] = sums[si - ci] - 1;
    }
  } 

  int min_abs_sum = S;
  for (int i = S / 2; i >= 0; --i) if (sums[i] >= 0) return S - 2 * i;
  return min_abs_sum;
}

int main()
{
  // M: 5, S: 10
  // counts: 0: 0, 1: 1, 2: 2, 3: 0, 4: 0, 5: 1
  // sums: 0, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1
  // sums: 1,  0, -1, -1, -1, -1, -1, -1, -1, -1, -1 (1: 1)
  // sums: 2,  2,  1,  1, 0, 0, -1, -1, -1, -1, -1 (2: 2)
  // sums: 1,  1,  1,  1, 1, 1, -1, -1, -1, -1, 0 (5: 1)
  // 10 - 2 * 5 = 0
  vector<int> A1{1, 5, 2, -2};
  cout << "1, 5, 2, -2 => 0: " << solution(A1) << endl;

  vector<int> A2;
  cout << "{} => 0: " << solution(A2) << endl;
  return 0;
}
