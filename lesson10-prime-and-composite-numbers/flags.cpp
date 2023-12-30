#include <algorithm>
#include <iostream>
#include <vector>

// 1. Get all the peaks O(n), maximum ~n/2
// 2. Get the distance between first and last peaks
// 3. Start from the highest flag numbers downwards to the lowest.
// 4. For each flag number, check how many flags one can place by:
//    a. distance / flag number (best case) < flag number, try lower flag
//       number
//    b. distance / flag number => flag number, check for all peak pairs
//       whether condition met. 

using namespace std;

int solution(vector<int> &A)
{
  size_t sizeA = A.size();
  size_t min_peak = 0;
  size_t max_peak = 0;
  vector<bool> hash(sizeA, false);
  for (size_t i = 1; i < sizeA - 1; ++i) {
    const int e = A[i];
    if (e > A[i - 1] && e > A[i + 1]) hash[i] = true;
  }

  vector<int> hash_next(sizeA, 0);
  for (int i = sizeA - 2; i >= 0; --i) {
    hash_next[i] = hash[i] ? i : hash_next[i + 1];
  }

  int max_flags = 0;
  for (size_t i = 1; (i - 1) * i <= sizeA; ++i) {
    int flags = 0;
    for (size_t j = 0; j < sizeA && flags < i; ++flags, j += i) {
      j = hash_next[j];
      if (!j) break;
    }

    max_flags = max(max_flags, flags);
  }

  return max_flags;
}

int main()
{
  // sizeA = 12
  // 1 5 3 4 3 4  1  2  3  4  6  2
  // 0 1 0 1 0 1  0  0  0  0  1  0
  // 1 1 3 3 5 5 10 10 10 10 10  0

  vector<int> i1{1, 5, 3, 4, 3, 4, 1, 2, 3, 4, 6, 2};
  cout << "1, 5, 3, 4, 3, 4, 1, 2, 3, 4, 6, 2 => 3: " << solution(i1) << endl;
  return 0;
}
