#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

int solution(std::vector<int> &A)
{
  std::set<int> numbers;
  size_t max = 0;
  for (const int e : A) {
    numbers.insert(e);
    if (e > max) max = e;
  }

  return ((numbers.size() == A.size() && max == A.size()) ? 1 : 0);
}

int main()
{
  std::vector<int> input1{4, 1, 3, 2};
  std::cout << "{4, 1, 3, 2} => 1: " << solution(input1) << std::endl;

  std::vector<int> input2{4, 1, 3};
  std::cout << "{4, 1, 3} => 1: " << solution(input2) << std::endl;

  return 0;
}
