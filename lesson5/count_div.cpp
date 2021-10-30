#include <iostream>
#include <vector>

int solution(int A, int B, int K)
{
  int remainder = A % K;
  int range_start = remainder ? A + (K - remainder) : A;
  int add = 1;
  if (range_start > B) { range_start = B - 1; add = 0; }
  int range = B - range_start;
  return range / K + add;
}

int main()
{
  std::cout << "6, 11, 2 => 3: " << solution(6, 11, 2) << std::endl;
  std::cout << "6, 10, 2 => 3: " << solution(6, 11, 2) << std::endl;
  std::cout << "11, 345, 17 => 20: " << solution(11, 345, 17) << std::endl;
  std::cout << "28, 345, 17 => 19: " << solution(28, 345, 17) << std::endl;
  std::cout << "0, 0, 2000000000 => 1: " << solution(0, 0, 2000000000) << std::endl;
  std::cout << "1, 1999999999, 2000000000 => 0: " << solution(1, 1999999999, 2000000000) << std::endl;
  return 0;
}
