#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

int solution(int X, vector<int> &A)
{
  unordered_set<int> numbers;
  for (size_t i = 1; i <= X; ++i) {
    numbers.insert(i);
  }

  for (size_t i = 0; i < A.size(); ++i) {
    numbers.erase(A[i]);
    if (numbers.empty()) {
       return i;
    }
  }

  return -1;
}

int main()
{
  vector<int> input1{1, 3, 1, 4, 2, 3, 5, 4};
  cout << "{1, 3, 1, 4, 2, 3, 5, 4} => 6: " << solution(5, input1) << endl;

  vector<int> input2{1};
  cout << "{1} => -1: " << solution(5, input2) << std::endl;

  return 0;
}
