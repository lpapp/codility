#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

// 1. Find the maximum element in the input array. We could also use M, but M
//    does not necessarily occur. A smaller number could be the maximum, so it
//    is slight optimisation.
// 2. Calculate the sum of the input array. This would be the maximum largest
//     sum.
// 3. Apply binary search, where the start is the maximum element and the end
//    is the sum. The minimum largest sum would be in this range.
// 4. For each trial, check whether we can squeeze the elements into fewer
//    blocks than the block number requested. If it is fewer, it is okay because
//    we can use empty blocks. If it is equal, that is also acceptable.
//    However, it is greater, then we can conclude that the tried minimum
//    largest sum needs to be higher to allow individual blocks to be larger to
//    reduce the block count.
// 5. One general principle can be observed above that the more fairly we
//    distribute the sums of the blocks, the largest will become the minimum
//    possible. For this, we need to squeeze as many elements into an individual
//    block as possible.
// 6. If the number of blocks for a tried minimum largest sum is smaller than
//    the expected block count, then we can try a slightly smaller minimum
//    largest sum, otherwise we have to try a bit greater until we eventually
//    find the best number.
//
// As far as runtime complexity goes, the solution is O(n*log(N*M)) because the
// binary search is logarithmic. The sum can be N number of times the maximum
// element M at worst, which results in an N*M range to bisect with binary
// search. The inner iteration will go through all the elements, so that is N
// times. Therefore, it is O(N*log(N*M)) which is equivalent to O(N*log(N+M).

int check(vector<int>& A, int largest_sum)
{
  int sum = 0;
  int count = 0;
  for (size_t i = 0; i < A.size(); ++i) {
    const int e = A[i];
    if ((sum + e) > largest_sum) { sum = 0; ++count; }
    sum += e;
  }

  return count;
}

int solution(int K, int /*M*/, vector<int> &A)
{
  int start = *max_element(A.begin(), A.end());
  int end = accumulate(A.begin(), A.end(), 0);
  while (start <= end) {
    int mid = (start + end) / 2;
    if (check(A, mid) < K) end = mid - 1;
    else start = mid + 1;
  }
  return start;
}

int main()
{
  vector<int> i1{2, 1, 5, 1, 2, 2, 2};
  cout << "2, 1, 5, 1, 2, 2, 2 | 3 | 5 => 6: " << solution(3, 5, i1) << endl;

  // max: 6
  // sum: 21
  // -> E.g. try 12: {4 3} {6, 2, 1} {5}
  // -> E.g. try 8: {4 3} {6, 2} {1 5}
  // -> E.g. try 7: {4 3} {6} {2, 1} {5}
  vector<int> i2{4, 3, 6, 2, 1, 5};
  cout << "2, 1, 5, 1, 2, 2, 2 | 3 | 6 => 8: " << solution(3, 6, i2) << endl;

  // max: 1
  // sum: 8
  // -> 4
  // {1 1 1 1} {1 1 1 1}
  // -> 3
  // {1 1 1} {1 1 1} {1 1}
  // -> 2
  // {1 1} {1 1} {1 1} {1 1}
  vector<int> i3{1, 1, 1, 1, 1, 1, 1, 1};
  cout << "1, 1, 1, 1, 1, 1, 1, 1 | 4 | 6 => 2: " << solution(4, 1, i3) << endl;
}
