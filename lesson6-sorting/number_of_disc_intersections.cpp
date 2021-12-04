#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// O(n*logn) time complexity, O(n) space complexity.
// Build the starting and ending points of the discs.
// Order these two separate lists. The points are now disjointed.
// Go through these two lists, and pick a point from the opening list if the
// next item is less than or equal to the closing.
// Every time we open a new disc, check how many are open and increment the
// intersections with that much. When we pick a closing point, decrement the
// currently opened circles by one. When reaching the end of the starting
// points, we can quit. There is no more discs left to check for.

int solution(vector<int> &A)
{
  size_t sizeA = A.size();
  vector<int64_t> starts(sizeA, 0);
  vector<int64_t> ends(sizeA, 0);
  for (size_t i = 0; i < sizeA; ++i) {
    starts[i] = i - A[i];
    ends[i] = i + A[i];
  }

  sort(starts.begin(), starts.end());
  sort(ends.begin(), ends.end());

  size_t ei = 0;
  size_t open_count = 0;
  int intersections = 0;
  size_t si = 0;
  while (si < sizeA) {
    if (starts[si] <= ends[ei]) {
      intersections += open_count;
      if (intersections > 10000000) return -1;
      ++open_count;
      ++si;
    }
    else {
      --open_count;
      ++ei;
    }
  }

  return intersections;
}

int main()
{
  vector<int> i1{1, 5, 2, 1, 4, 0};
  cout << "{1, 5, 2, 1, 4, 0} => 11: " << solution(i1) << endl;
  return 0;
}
