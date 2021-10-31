#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

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
