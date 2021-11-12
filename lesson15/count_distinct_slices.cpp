#include <iostream>
#include <vector>

using namespace std;

/*
  1. Notice that the minimum amount of distinct slices is N because each element
     is a distinct one-item slice.
  2. Start the back index from the first element.
  3. Start the front index from the second element.
  4. Start the iteration loop and iterate until front reaches the end.
  5. If back equals to front, advance back until it reaches front, since there
     is no distinct slices here apart from the one-item slices.
  6. If back does not equal to front, but front is the last element, update the
     counter to include the index differences. E.g. {1, 2} would result in +1.
      Finally, exit the loop to 3 for this.
  7. Front is not the last element, but it does not equal to back. Update the
     counter with the index differences.
  8. If the next front item equal to the current, update back to the current
     index.

*/

int solution(int M, vector<int> &A)
{
  int N = A.size();
  int distinct_slices = N;
  for (int back = 0, front = 1; front < N; ++front) {
    if (A[back] == A[front]) ++back;
    else if (front == N - 1) distinct_slices += (front - back);
    else if (A[front] != A[front + 1]) distinct_slices += (front - back);
    else if (A[front] == A[front + 1]) { distinct_slices += (front - back); back = front; }

    if (distinct_slices > 1000000000) return 1000000000;
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

  return 0;
}
