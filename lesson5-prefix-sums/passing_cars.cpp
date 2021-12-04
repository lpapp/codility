#include <iostream>
#include <vector>

int solution(std::vector<int> &A)
{
  int zero_count = 0;
  uint64_t passing_cars = 0;

  for (const int e : A) {
    if (!e) {
      ++zero_count;
    }
    else {
      passing_cars += zero_count;
    }
  }

  return passing_cars > 1000000000 ? -1 : passing_cars;
}

int main()
{
  std::vector<int> input1{0, 1, 0, 1, 1};
  std::cout << "{0, 1, 0, 1, 1} => 5: " << solution(input1) << std::endl;

  std::vector<int> input2(50000, 0);
  input2.insert(input2.end(), 50000, 1);
  std::cout << "{0, 0 .... 1, 1} => -1: " << solution(input2) << std::endl;

  std::vector<int> input3{0};
  std::cout << "{0} => 0: " << solution(input3) << std::endl;

  std::vector<int> input4{1};
  std::cout << "{1} => 0: " << solution(input4) << std::endl;
  return 0;
}
