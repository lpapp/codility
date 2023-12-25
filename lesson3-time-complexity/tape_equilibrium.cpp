#include <cmath>
#include <cstdlib>
#include <limits>
#include <iostream>
#include <vector>

int solution(std::vector<int> &A)
{
  int sum = 0;
  for (const int e : A) sum += e;

  int min = std::numeric_limits<int>::max();
  int left = 0;
  const std::size_t len = A.size() - 1;
  for (std::size_t i = 0; i < len; ++i) {
    left += A[i];
    const int right = sum - left;
    const int diff = left - right;
    const int abs_diff = std::abs(diff);
    if (abs_diff < min) min = abs_diff; 
  }

  return min;
}

int main()
{
  std::vector<int> input1{3, 1, 2, 4, 3};
  std::cout << "{3, 1, 2, 4, 3} => 1: " << solution(input1) << std::endl;

  return 0;
}
