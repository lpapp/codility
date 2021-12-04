#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int solution(vector<int> &H)
{
  size_t sizeH = H.size();
  stack<int> s;
  int min_block = 0;
  for (size_t i = 0; i < sizeH; ++i) {
    int e = H[i];
    if (s.empty() || e > s.top()) s.push(e);
    else {
      while (!s.empty() && e <= s.top()) {
        if (e < s.top()) ++min_block;
        s.pop();
      }
      s.push(e);
    }
  }

  min_block += s.size();
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
