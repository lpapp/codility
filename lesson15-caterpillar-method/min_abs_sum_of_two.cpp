#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/*
  1. Sort the array because otherwise we would need to check any two arbitrary
     indices. That brute-force solution would result in O(N ^ 2) runtime
     complexity.

  2. We initialise the min abs sum to something higher than the possible value
     in the arrays. 

  3. Apply the caterpillar method by having front and back indices.

  4. In every iteration, update the min abs sum as and when needed.

  5. There two special cases:
    a. all values are zero or positive. We could return A[front] * 2 early.
    b. all values are negative or zero. We could return A[back] * 2 early.

    In both cases, we could return early, however, it would result in a bit
    more code, so I personally avoid that. In the above cases, we can still go
    through the array without degrading the overall runtime complexity. In these
    cases, it also does not matter how we go through the array with regards to
    the result, so I just go through the array in one way in both cases. But
    the code will be shared with the third case.

  6. In the third case, where the array, and thereby the sorted array, contains
     both negative and positive values, we try to keep the sum of front and
     back to zero since this when the abs sum value is minimised. In other
     words, we try to keep the balance between the negative and positive
     numbers by keeping their distance to the minimum.

  7. Therefore, if the sum of front and back are less than zero, then we know
     that the negative front value is greater than the positive back value. As
     a direct consequence of that, we need to advance the front index.

  8. If the sum of front and back are equal to zero, then we found the smallest
     min abs sum that is ever possible. The absolute value cannot be less than
     zero. Whilst I could return at this point in the code for some constant
     optimisation, I do not do so to keep the code the minimal and also
     functional.

  9. If the sum of front and back are greater than zero, then we know that the
     negative front value is less than the positive back value. As a direct
     consequence of that, we need to decrease the index.

  10. We loop until the front and back indices meet, but we handle the case
      when they are equal since according to the task specification, the same
      index can be used twice for the absolute sum.

  The runtime complexity of this solution is O(N * logN) because the sorting of
  the array is O(N * logN) and the loop is O(N) since we go through every
  element. Therefore, the sorting runtime complexity dominates the loop.

  The space complexity is O(1) because we only allocate constant space
  independently from the number of inputs. The sorting is done in place.
*/

int solution(vector<int> &A)
{
  const int N = A.size();
  sort(A.begin(), A.end());
  int min_abs_sum_of_two = INT_MAX;
  for (int front = 0, back = N - 1; front <= back;) {
    const int ef = A[front];
    const int eb = A[back];
    min_abs_sum_of_two = min(min_abs_sum_of_two, abs(ef + eb));
    if (ef + eb < 0) ++front; else --back;
  }
  return min_abs_sum_of_two;
}

int main()
{
  // -3, 1, 4
  vector<int> A1{1, 4, -3};
  cout << "1, 4, -3: => 1: " << solution(A1) << endl;

  // -10, -8, 3, 4, 5
  vector<int> A2{-8, 4, 5, -10, 3};
  cout << "-8, 4, 5, -10, 3: => 3: " << solution(A2) << endl;

  return 0;
}
