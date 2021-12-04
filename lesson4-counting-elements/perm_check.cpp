#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

int solution(vector<int> &A)
{
  unordered_set<int> numbers;
  size_t max = 0;
  for (const int e : A) {
    numbers.insert(e);
    if (e > max) max = e;
  }

  return ((numbers.size() == A.size() && max == A.size()) ? 1 : 0);
}

int main()
{
  vector<int> input1{4, 1, 3, 2};
  cout << "{4, 1, 3, 2} => 1: " << solution(input1) << endl;

  vector<int> input2{4, 1, 3};
  cout << "{4, 1, 3} => 0: " << solution(input2) << endl;

  return 0;
}
