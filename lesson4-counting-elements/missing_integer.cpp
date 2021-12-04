#include <iostream>
#include <vector>

int solution(std::vector<int> &A)
{
  std::vector<bool> hash(1000000, false);
  for (const int e : A) {
    if (e > 0) {
       hash[e] = true;
    }
  }

  for (size_t i = 1; i < hash.size(); ++i) {
    if (!hash[i]) {
      return i;
    }
  }

  return A.size();
}

int main()
{
  std::vector<int> input1{1, 3, 6, 4, 1, 2};
  std::cout << "{1, 3, 6, 4, 1, 2} => 5: " << solution(input1) << std::endl;

  std::vector<int> input2{1, 2, 3};
  std::cout << "{1, 2, 3} => 4: " << solution(input2) << std::endl;

  std::vector<int> input3{-1, -3};
  std::cout << "{-1, -3} => 1: " << solution(input3) << std::endl;

  return 0;
}
