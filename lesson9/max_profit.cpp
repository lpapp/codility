#include <iostream>
#include <vector>

using namespace std;

int solution(vector<int> &A)
{
  int min_e = A.empty() ? 0 : A.front();
  int max_sum = 0;

  for (const int e : A) {
    int diff = e - min_e;
    if (diff > max_sum) max_sum = diff;
    if (diff < 0) min_e = e;
  }

  return max_sum;
}

int main()
{
  vector<int> i1{23171, 21011, 21123, 21366, 21013, 21367};
  cout << "23171, 21011, 21123, 21366, 21013, 21367 => 356: " << solution(i1) << endl;
  return 0;
}
