#include <iostream>
#include <vector>

int solution(std::vector<int> &A)
{
  size_t max = A.size() + 2;
  std::vector<bool> hash(max, false);
  for (const auto i : A) {
    hash[i] = true;
  }

  for (size_t i = 1; i < max; ++i) {
    if (hash[i] == false) {
      return i;
    }
  }

  return 0;
}

int main()
{
  std::vector<int> input1{2, 3, 1, 5};
  std::cout << "{2, 3, 1, 5} => 4: " << solution(input1) << std::endl;

  std::vector<int> input2{};
  std::cout << "{} => 1: " << solution(input2) << std::endl;
	return 0;
}
