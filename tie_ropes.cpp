#include <iostream>
#include <vector>

using namespace std;

/*
  1. Apply the greedy algorithm by going through the inputs.
  2. Start from zero max ropes.
  3. Initialise the rope length to zero.
  4. In each iteration, increase the current rope length.
  5. Once we reach or exceed the desired number, reset the current rope length
     to zero to start finding the new sequence.
  6. At the same time, increase the max rope counter.
  7. When we reach the end of the inputs, exit the loop and return the result.

  The runtime complexity is O(N) because we go through each element in the
  inputs.

  The space complexity is O(1) because we only allocate constant extra space,
  independently from the number of inputs.
 */

int solution(int K, vector<int> &A)
{
  int max_ropes = 0;
  for (int i = 0, rope_length = 0; i < A.size(); ++i) {
    rope_length += A[i];
    if (rope_length >= K) { ++max_ropes; rope_length = 0; }
  }
  return max_ropes;
}

int main()
{
  vector<int> A1{1, 2, 3, 4, 1, 1, 3};
  cout << "1, 2, 3, 4, 1, 1, 3 | 4 => 3: " << solution(4, A1) << endl;

  vector<int> A2{1};
  cout << "1 | 1 => 1: " << solution(1, A2) << endl;

  return 0;
}
