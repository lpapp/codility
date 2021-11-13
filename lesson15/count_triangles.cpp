#include <iostream>
#include <vector>

using namespace std;

/*
  1. Sort the array because any three indices could be a triangle otherwise. It
     would make it challenging to apply the caterpillar method.

     Also, the best runtime complexity that I could think of was O(N^2), so the
     sorting runtime complexity, O(N * logN) would be dominated by that.

  2. Initialise the indices for the loop. P = 0, Q = 1, R =1.

  3. A[Q] + A[R] will always be greater than A[P] since A[R] > A[P].

  4. A[P] + A[R] will always be greater than A[Q] since A[R] > A[Q].

  5. So, the only thing to check is whether A[P] + A[Q] is greater than A[R].
     If so, we need to increment the triangle counter since we have just found
     a valid triangle.

  6. We need to advance R to the right as much as possible to find all the
     possible triangle occurences for the current P and Q values. 

  7. When we have found all the possible R values for the current P and Q
     values, we check whether we need to advance P or Q.

  8. If it is three consecutive elements, we increment both Q and R by one.

  9. If it is not three consecutive elements, then if it is P Q ... R, then
     increment Q.

  10. If it is not tree consecutive element, then if it is P ... Q R, then
      increment P.

 */

int solution(vector<int> &A)
{
  sort(A.begin(), A.end());
  const size_t N = A.size();
  int triangles = 0;
  for (size_t P = 0, Q = 1, R = 2; R < N; ++P, Q = P + 1, R = Q + 1) {
    while (R < N) {
      if ((A[P] + A[Q]) > A[R]) { ++triangles; ++R; }
      else if (R != (Q + 1)) ++Q;
      else { ++R; ++Q; }
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
  vector<int> A1{10, 2, 5, 1, 8, 12};
  cout << "10, 2, 5, 1, 8, 12 => 4: " << solution(A1) << endl;

  vector<int> A2{10, 11, 12, 13, 14, 15};
  cout << "10, 11, 12, 13, 14, 15 => 19: " << solution(A2) << endl;

  vector<int> A3{1, 2, 5, 8, 10, 12, 100};
  cout << "1, 2, 5, 8, 10, 12, 100 => 4: " << solution(A3) << endl;

  return 0;
}
