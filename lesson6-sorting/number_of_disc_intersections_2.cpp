#include <iostream>
#include <vector>

using namespace std;

// O(n) time complexity, O(n) space complexity.
// Build the starting and ending points of the discs. Basically, find out in
// the range of 0...n-1, how many opening and closing there are. The negative
// values and greater than n-1 do not contribute to the end result. Therefore,
// we can truncate the long range to 0...n-1
// We can essentially check all intersections within this range, so find the
// earlier point within this range when the circle is opened.
// Same with closing, find index + radius, or n-1 if index + radius is greater
// than n-1. So, we get the closing point within this range.
// Then, keep track of the currently opened circles at any index.
// For each new opening in a position, increment the intersections with the
// currently opened circles before. But also, count the intersections amongst
// each other opened at that particular index.
// We also need to decrement the open counter when reaching circle endings.

int solution(vector<int> &A)
{
  int sizeA = A.size();
  vector<int> starts(sizeA, 0);
  vector<int> ends(sizeA, 0);

  for (int i = 0, li = sizeA - 1; i < sizeA; ++i) {
    int e = A[i];

    int si = (i > e) ? (i - e) : 0;
    ++starts[si];

    int ei = ((li - i) > e) ? (i + e) : li;
    ++ends[ei];
  }

  int open_count = 0;
  int intersections = 0;
  for (size_t i = 0; i < sizeA; ++i) {
    if (starts[i] > 0) {
      intersections += open_count * starts[i];
      intersections += starts[i] * (starts[i] - 1) / 2;
      if (intersections > 10000000) return -1;
      open_count += starts[i];
    }
    open_count -= ends[i];
  }

  return intersections;
}

int main()
{
  vector<int> i1{1, 5, 2, 1, 4, 0};
  cout << "{1, 5, 2, 1, 4, 0} => 11: " << solution(i1) << endl;

  vector<int> i2{1, 2147483647, 0};
  cout << "{1, 2147483647, 0} => 2: " << solution(i2) << endl;

  return 0;
}
