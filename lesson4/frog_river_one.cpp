#include <iostream>
#include <set>
#include <vector>

int solution(int X, std::vector<int> &A)
{
  std::set<int> numbers;
  for (size_t i = 1; i <= X; ++i)
  {
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
  std::vector<int> input1{1, 3, 1, 4, 2, 3, 5, 4};
  std::cout << "{1, 3, 1, 4, 2, 3, 5, 4} => 6: " << solution(5, input1) << std::endl;

  std::vector<int> input2{1};
  std::cout << "{1} => -1: " << solution(5, input2) << std::endl;

  return 0;
}
