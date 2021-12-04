#include <iostream>
#include <vector>

using namespace std;

/*
  1. Notice that the minimum amount of distinct slices is N because each element
     is a distinct one-item slice.
  2. Start the back index from the first element.
  3. Start the front index from the first element.
  4. Advance the front until we find a duplicate in the sequence.
  5. In each iteration, increment the counter with the necessary amount, this
     is the difference between front and back.
  6. If we reach the maximum counts at any iteration, just return immediately
     for slight optimisation.
  7. In each iteration of the sequence, record the elements that have occurred.
  8. Once we have found a duplicate, advance the back index one ahead of the
     duplicate.
  9. While we advance the back index, clear all the occurred elements since we
     start a new slice beyond those elements.

  The runtime complexity of this solution is O(N) since we go through each
  element.

  The space complexity of this solution is O(M) because we have a hash to store
  the occurred elements in the sequences. The maximum element of this hash is M.
*/

int solution(int M, vector<int> &A)
{
  int N = A.size();
  int distinct_slices = N;
  vector<bool> seq_hash(M + 1, false);
  for (int back = 0, front = 0; front < N; ++back) {
    while (front < N and !seq_hash[A[front]]) { distinct_slices += front - back; if (distinct_slices > 1000000000) return 1000000000; seq_hash[A[front++]] = true; }
    while (front < N and back < N and A[back] != A[front]) seq_hash[A[back++]] = false;
    seq_hash[A[back]] = false;
  }

  return distinct_slices;
}

int main()
{
  vector<int> A1{3, 4, 5, 5, 2};
  cout << "3, 4, 5, 5, 2 | 6 => 9: " << solution(6, A1) << endl;

  // (0, 0), (0, 1), (1, 1), (1, 2), (0, 2), (2, 2), (2, 3), (1, 3), (0, 3),
  // (3, 3)
  // (0, 1), (1, 2), (0, 2), (2, 3), (1, 3), (0, 3),
  vector<int> A2{1, 2, 3, 4};
  cout << "1, 2, 3, 4 | 4 => 10: " << solution(4, A2) << endl;

  // (0, 0), (1, 1), (2, 2), (3, 3), (2, 3)
  vector<int> A3{3, 3, 3, 4};
  cout << "3, 3, 3, 4 | 5 => 5: " << solution(5, A3) << endl;

  // (0, 0), (0, 1), (1, 1), (1, 2), (0, 2), (2, 2), (2, 3), (1, 3), (0, 3),
  // (3, 3), (4, 4)
  vector<int> A4{1, 2, 3, 4, 4};
  cout << "1, 2, 3, 4, 4 | 5 => 11: " << solution(5, A4) << endl;

  // (0, 0), (0, 1), (1, 1), (2, 2), (3, 3), (3, 4), (4, 4)
  vector<int> A5{1, 2, 2, 2, 4};
  cout << "1, 2, 2, 2, 4 | 5 => 7: " << solution(5, A5) << endl;

  vector<int> A6{1};
  cout << "1 | 5 => 1: " << solution(5, A6) << endl;

  vector<int> A7{1, 2};
  cout << "1, 2 | 5 => 3: " << solution(5, A7) << endl;

  vector<int> A8{2, 2};
  cout << "2, 2 | 5 => 2: " << solution(5, A8) << endl;

  vector<int> A9{1, 2, 2};
  cout << "1, 2, 2 | 5 => 4: " << solution(5, A9) << endl;

  vector<int> A10{1, 2, 1};
  cout << "1, 2, 1 | 5 => 5: " << solution(5, A10) << endl;

  vector<int> A11{1, 1, 2, 1};
  cout << "1, 1, 2, 1 | 6 => 6: " << solution(5, A11) << endl;

  vector<int> A12{0, 1, 2, 0, 1};
  cout << "0, 1, 2, 0, 1 | 3 => 12: " << solution(5, A12) << endl;

  vector<int> A13{0, 1, 2, 1};
  cout << "0, 1, 2, 1 | 3 => 8: " << solution(3, A13) << endl;

  vector<int> A14{0, 1, 2, 3, 2, 1};
  cout << "0, 1, 2, 3, 2, 1 | 3 => 15: " << solution(3, A14) << endl;

  return 0;
}
