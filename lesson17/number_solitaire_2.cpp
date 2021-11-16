#include <iostream>
#include <vector>

using namespace std;

/*
  1. Create a hash for the max sums. We only need to store the element within
     reach, so the last 6 elements. This is because the dice can only go back
     so much.
  2. Initialise this with the first element in the array for simplicity since
     the first element in this hash equals to the first element of the inputs.
  3. Then go through the elements from the second element.
  4. For each iteration, check the previous positions, depending on the range
     of the dice. Also, consider clipping it to the last 6 elements.
  5. Pick up the maximum value from the previous values.
  6. Return the max sum of the last element at the end.

  The runtime complexity of this dynamic programming solution is O(N) since we
  go through element in the inputs. If we consider the dice range K, then this
  would be O(N * K).

  The space complexity is O(K) because we have a hash for each element in the
  inputs. This could even be considered constant O(1) if we consider the number
  of dice faces constant.
 */

int solution(vector<int> &A)
{
  const int N = A.size();
  constexpr int K = 6;
  vector<int> max_sums(K, A[0]);
  for (int i = 1; i < N; ++i) {
    int sum_index = i % K;
    // cout << "SUM INDEX: " << sum_index << endl;
    int max_sum = max_sums[(sum_index + K - 1) % K] + A[i];
    for (int die_index = 2; die_index <= min(i, K); ++die_index) {
      const int curr_sum = max_sums[(sum_index + K - die_index) % K] + A[i];
      // cout << "PREV INDEX: " << prev_index << endl;
      // cout << "MAX_SUMS[PREV_INDEX]: " << max_sums[prev_index] << endl;
      // cout << "MAX_SUMS[INDEX]: " << max_sums[sum_index] << endl;
      if (curr_sum > max_sum) max_sum = curr_sum;
    }
    max_sums[sum_index] = max_sum;
    // cout << "MAX_SUMS[INDEX]: " << max_sums[sum_index] << endl;
  }
  return max_sums[(N - 1) % K];
}

int main()
{
  vector<int> A1{1, -2, 0, 9, -1, -2};
  cout << "1, -2, 0, 9, -1, -2 => 8: " << solution(A1) << endl;

  vector<int> A2{-1, -2};
  cout << "-1, -2 => -3: " << solution(A2) << endl;

  vector<int> A3{-2, 5, 1};
  cout << "-2, 5, 1 => 4: " << solution(A3) << endl;

  vector<int> A4{1, -2, 0, 9, -1, -2, -1, -2};
  cout << "1, -2, 0, 9, -1, -2, -1, -2 => 8: " << solution(A4) << endl;

  vector<int> A5{1, -2, 0, 9, -1, -1, -1, -2, -1, -2};
  cout << "1, -2, 0, 9, -1, -1, -1, -2, -1, -2 => 8: " << solution(A5) << endl;

  vector<int> A6{9, -1, -1, -1, -2, -1, -2};
  cout << "9, -1, -1, -1, -2, -1, -2 => 7: " << solution(A6) << endl;

  return 0;
}
