#include <iostream>
#include <vector>

using namespace std;

/*
  Caterpillar mathod

  1. Set the back index to the left end.
  2. Set the front index to the right end.
  3. Skip duplicated values at any point on both ends.
  4. If the absolute value on the left is greater than the absolute value on
     the right, then increase the back index.
  5. If the absolute value on the right is greater than the absolute value on
     the left, then decrease the front index.
  6. If the absolute value on the right equals to the absolute value on the
     left, then increase the back index and decrease the front index.
  7. Continue this until we have processed all the elements. This will happen
     when the last element is processed. This is in worst case when the back
     and front indices have the same value and/or element. Handle this final
     element and then exit the iteration.
  
  The runtime complexity is O(N) since we go through over each element in the
  input array.

  The space complexity is O(1) because we do not have any additional array or
  set, like we would have with the trivial unordered_set solution. So, whilst
  this approach maintains the same runtime complexity, the space complexity is
  more efficient.

*/

int solution(vector<int> &A)
{
  int N = A.size();
  int distinct_abs_values = 0;
  for (int back = 0, front = N - 1; back <= front; ++distinct_abs_values) {
    while (back < N - 1 and A[back] == A[back + 1]) ++back;
    while (front > 0 and A[front] == A[front - 1]) --front;

    const uint64_t eb = abs(A[back]);
    const uint64_t ef = abs(A[front]);

    if (eb > ef) ++back; 
    else if (eb < ef) --front;
    else if (eb == ef) { ++back; --front; }
  }

  return distinct_abs_values; 
}

int main()
{
  vector<int> A1{-5, -3, -1, 0, 3, 6};
  cout << "-5, -3, -1, 0, 3, 6 => 5: " << solution(A1) << endl;

  vector<int> A2{0};
  cout << "0 => 1: " << solution(A2) << endl;

  vector<int> A3{-2147483648, -1, 0, 1};
  cout << "-2147483648, -1, 0, 1 => 3: " << solution(A3) << endl;

  return 0;
}
