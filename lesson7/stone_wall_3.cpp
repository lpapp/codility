#include <iostream>
#include <deque>
#include <vector>

// Basic theory: minimum number of blocks equals to the different sizes.
// Same disjointed slices count +1
// Slices with same edges count -1
// So, we can spare blocks in two cases:
// 1. First and last of a slice are the same height
// 2. Consecutive blocks are the same height.

// 1. Go through equal heights, make them 1 block.
// 2.

using namespace std;

int solution(vector<int> &H)
{
  size_t sizeH = H.size();
  deque<int> q;
  int min_block = 0;
  for (size_t i = 0; i < sizeH; ++i) {
    int e = H[i];
    if (q.empty()) q.push_back(e);
    else if (e == q.back()) continue;
    else if (e > q.front()) q.push_back(e);
    else if (e < q.front()) {
      q.pop_front();
      ++min_block;
      if (!q.empty() && q.front() == q.back()) {
        q.pop_front();
        if (!q.empty()) q.pop_back();
        ++min_block;
        while (!q.empty()) {
          if (q.front() == q.back() && q.size() > 1) q.pop_back();
          q.pop_front();
          ++min_block;
        }
      }
      q.push_back(e);
    }
    else if (e == q.front()) {
      q.pop_front();
      ++min_block;
      while (!q.empty()) {
        if (q.front() == q.back() && q.size() > 1) q.pop_back();
        q.pop_front();
        ++min_block;
      }
    }
  }

  min_block += q.size();
  return min_block;
}

int main()
{
  vector<int> i1{8, 8, 5, 7, 9, 8, 7, 4, 8};
  cout << "{8, 8, 5, 7, 9, 8, 7, 4, 8} => 7: " << solution(i1) << endl;

  //   X
  // X X X
  // X X X X
  vector<int> i2{2, 3, 2, 1};
  cout << "{2, 3, 2, 1} => 3: " << solution(i2) << endl;

  vector<int> i3{1, 1, 1};
  cout << "{1, 1, 1} => 1: " << solution(i3) << endl;

  //     X X
  //   X X X X
  // X X X X X X
  vector<int> i4{1, 2, 3, 3, 2, 1};
  cout << "{1, 2, 3, 3, 2, 1} => 3: " << solution(i4) << endl;

  //           X
  //       X   X
  //     X X X X
  //   X X X X X
  // X X X X X X
  vector<int> i5{1, 2, 3, 4, 3, 5};
  cout << "{1, 2, 3, 4, 3, 5} => 5: " << solution(i5) << endl;

  return 0;
}
