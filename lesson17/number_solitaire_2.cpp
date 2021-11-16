#include <iostream>
#include <vector>

using namespace std;

/*
  1. Create a hash for the max sums. We only need to store the elements within
     reach, so the last 6 elements. This is because the dice can only go back
     so much.
  2. Initialise the hash with the first element in the array for simplicity
     since the first element in this hash equals to the first element of the
     inputs.
  3. Then go through the input elements from the second element.
  4. For each iteration, find the maximum values from the last 6 indices. Add
      the current value to that to get the current max sum.
  6. When we reach the end of the inputs, exit the loop.
  7. Return the max sum of the last element calculated. For this, we need
     clipping with module due to the space optimisation

  The runtime complexity of this dynamic programming solution is O(N) since we
  go through element in the inputs. If we consider the dice range K, then this
  would be O(N * K).

  The space complexity is O(K) because we have a hash for each element in the
  inputs. This could even be considered constant O(1) if we consider the number
  of dice faces constant.
 */

int solution(vector<int> &A)
{
  vector<int> max_sums(6, A[0]);
  for (size_t i = 1; i < A.size(); ++i) max_sums[i % max_sums.size()] = *max_element(max_sums.cbegin(), max_sums.cend()) + A[i];
  return max_sums[(A.size() - 1) % max_sums.size()];
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
