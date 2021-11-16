include <iostream>
#include <vector>

using namespace std;

/*
  1. Create a hash for the max sums at each index.
  2. Initialise this with the first element in the array for simplicity since
      the first element in this hash equals to the first element of the inputs.
  3. Then go through the elements from the second element.
  4. 
 */

int solution(vector<int> &A)
{
  const int N = A.size();
  vector<int> max_sums(N, A[0]);
  for (int i = 1; i < N; ++i) {
    max_sums[i] = A[i] + max_sums[i - 1];
    for (int die_index = 2; die_index < 6; ++die_index) {
      const int prev_index = i - die_index;
      if (prev_index >= 0 and max_sums[prev_index] + A[i] > max_sums[i])
        max_sums[i] = max_sums[prev_index] + A[i];
    }
  }
  return max_sums[N - 1];
}

int main()
{
  vector<int> A1{1, -2, 0, 9, -1, -2};
  cout << "1, -2, 0, 9, -1, -2 => 8: " << solution(A1) << endl;

  vector<int> A2{-1, -2};
  cout << "-1, -2 => -3: " << solution(A2) << endl;

  vector<int> A3{-2, 5, 1};
  cout << "-2, 5, 1 => 4: " << solution(A3) << endl;

  return 0;
}
