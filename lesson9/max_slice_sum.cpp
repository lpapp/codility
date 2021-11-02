#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

using namespace std;

int solution(vector<int> &A)
{
  int max_sum = INT_MIN;
  int seq_sum = 0;

  for (const int e : A) {
    int sum = seq_sum + e;
    max_sum = max(max_sum, sum);
    seq_sum = max(0, sum);
  }

  return max_sum;
}

int main()
{
  vector<int> i1{3, 2, -6, 4, 0};
  cout << "3, 2, -6, 4, 0 => 5: " << solution(i1) << endl;

  vector<int> i2{-10};
  cout << "-10 => -10: " << solution(i2) << endl;

  return 0;
}
