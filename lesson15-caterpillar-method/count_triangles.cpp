#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/*
  1. Sort the array because any arbitrary three indices could be a triangle
     otherwise. It would make it challenging to apply the caterpillar method.

     Also, the best runtime complexity that I could think of was O(N^2), so the
     sorting runtime complexity, O(N * logN) would be dominated by that.

  2. Initialise the indices for the loop. P = 0, Q = 1, R = 2.

  3. We loop through all the valid P values from 0 to N - 2. In each nested
     iteration, we either advance Q, R or both depending on some conditions.
     Alternatively, if we reach the end with R, i.e. R == N, we exit this
     nested loop to try the next P index.

  4. A[Q] + A[R] will always be greater than A[P] since A[R] > A[P].

  5. A[P] + A[R] will always be greater than A[Q] since A[R] > A[Q].

  6. So, the only condition to check is whether A[P] + A[Q] is greater than
     A[R]. If so, we need to increment the triangle counter by some numbers
     since we have just found new valid triangle(s).

     This depends on the distance between Q and R. Simply because a new R
     brings in R - Q combination for triangles. Any Q will do it between R and
     Q. For example, in case of (10, 11, 12, 13, 14, 15), you would get the
     following triangles.

     // (10, 11, 12)
     // (10, 11, 13), (10, 12, 13)
     // (10, 11, 14), (10, 12, 14), (10, 13, 14)
     // (10, 11, 15), (10, 12, 15), (10, 13, 15), (10, 14, 15)

  6. When Q and R are consecutive elements, we need to advance both.

  7. When Q and R are not consecutive elements, we only need to advance Q at
     this stage.

  8. Finally, if R reaches the end, N, we exit the nested loop, and run it
     again for a new P. We need to make sure that Q and R are re-calibrated so
     that P, Q, R are the next consecutive triplet.
  
  The runtime complexity of this algorithm is O(N^2) because the outer loop
  iterates N times and the inner loop also iterates N times in worst case.

  The space complexity is O(1) because we only have some constant space
  allocation, nothing depending on the number of inputs.

 */

int solution(vector<int> &A)
{
  std::sort(A.begin(), A.end());
  const size_t N = A.size();
  int triangles = 0;
  for (size_t P = 0, Q = 1, R = 2; R < N; ++P, Q = P + 1, R = Q + 1) {
    while (R < N) {
      if ((A[P] + A[Q]) > A[R]) { triangles += R - Q; ++R; }
      else if (R == (Q + 1)) { ++Q; ++R; }
      else ++Q;
    }
  }
  return triangles;
}

int main()
{
  // Sorted: 1, 2, 5, 8, 10, 12
  // 5, 8, 10
  // 5, 8, 12
  // 5, 10, 12
  // 8, 10, 12

  // 0 1 2 3  4  5
  // 1 2 5 8 10 12
  // P=1, Q=2, R=5
  // P=1, Q=5, R=8
  // P=1, Q=8, R=10
  // P=1, Q=10, R=12
  // P=1, Q=12, R=N

  // P=2, Q=5, R=8
  // P=2, Q=8, R=10
  // P=2, Q=10, R=12
  // P=2, Q=12, R=N

  // P=5, Q=8, R=10 (1t)
  // P=5, Q=8, R=12 (2t)

  // P=8, Q=10, R=12 (1t)
  vector<int> A1{10, 2, 5, 1, 8, 12};
  cout << "10, 2, 5, 1, 8, 12 => 4: " << solution(A1) << endl;

  // (10, 11, 12), (10, 11, 13), (10, 11, 14), (10, 11, 15)
  // (10, 12, 13), (10, 12, 14), (10, 12, 15)
  // (10, 13, 14), (10, 13, 15)
  // (10, 14, 15)
  //
  // (11, 12, 13), (11, 12, 14), (11, 12, 15)
  // (11, 13, 14), (11, 13, 15)
  // (11, 14, 15)
  //
  // (12, 13, 14), (12, 13, 15)
  // (12, 14, 15)
  //
  // (13, 14, 15)

  // P=10, Q=11, R=12 (1t) -> (10,11,12)
  // P=10, Q=11, R=13 (2t) -> (10,11,13), (10,12,13)
  // P=10, Q=11, R=14 (3t) -> (10,11,14), (10,12,14), (10,13,14)
  // P=10, Q=11, R=15 (4t) -> (10,11,15), (10,12,15), (10,13,15), (10,14,15)
  // P=11, Q=12, R=13 (1t) -> (11,12,13)
  // P=11, Q=12, R=14 (2t) -> (11,12,14), (11,13,14)
  // P=11, Q=12, R=15 (3t) -> (11,12,15), (11,13,15), (11,14,15)
  // P=12, Q=13, R=14 (1t) -> (12,13,14)
  // P=12, Q=13, R=15 (2t) -> (12,13,15), (12,14,15)
  // P=13, Q=14, R=15 (1t) -> (13,14,15)
  vector<int> A2{10, 11, 12, 13, 14, 15};
  cout << "10, 11, 12, 13, 14, 15 => 20: " << solution(A2) << endl;

  vector<int> A3{1, 2, 5, 8, 10, 12, 100};
  cout << "1, 2, 5, 8, 10, 12, 100 => 4: " << solution(A3) << endl;

  // P=10, Q=11, R=12 (1t) -> (10,11,12)
  // P=10, Q=11, R=13 (2t) -> (10,11,13), (10,12,13)
  // P=10, Q=11, R=21
  // P=10, Q=12, R=21 (2t) -> (10,12,21), (10,13,21)
  // P=10, Q=12, R=50
  // P=11, Q=12, R=13 (1t) -> (11,12,13)
  // P=11, Q=12, R=21 (2t) -> (11,12,21), (11,13,21)
  // P=11, Q=12, R=50
  // P=12, Q=13, R=21 (1t) -> (12,23,21)
  // P=12, Q=13, R=50
  // P=13, Q=21, R=50
  // P=21, Q=50, R=N
  vector<int> A4{10, 11, 12, 13, 21, 50};
  cout << "10, 11, 12, 13, 50 => 9: " << solution(A4) << endl;

  return 0;
}
