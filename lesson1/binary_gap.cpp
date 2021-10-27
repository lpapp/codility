#include <algorithm>
#include <iostream>

int solution(int N)
{
  // Skip initial zeroes.
  while (N > 0 && !(N & 1)) N >>= 1;

  // Skip the first one.
  if (N > 0) N >>= 1;

  uint8_t max_zeroes = 0;
  uint8_t zeroes = 0;

  for (; N > 0; N >>= 1) {
    if (N & 1) {
      // If reaching one, check if max needs updating.
      max_zeroes = std::max(max_zeroes, zeroes);

      // Reset the number of zeroes to start the potentially new sequence.
      zeroes = 0;
    }
    else {
      // Increment the number of zeroes if zero reached.
      ++zeroes;
    }
  }

  return max_zeroes;
}

int main()
{
  std::cout << "9 (2): " << solution(9) << std::endl;
  std::cout << "529 (4): " << solution(529) << std::endl;
  std::cout << "20 (1): " << solution(20) << std::endl;
  std::cout << "15 (0): " << solution(15) << std::endl;
  std::cout << "32 (0): " << solution(32) << std::endl;
  std::cout << "1041 (5): " << solution(1041) << std::endl;
  std::cout << "1 (0): " << solution(0) << std::endl;
  std::cout << "2147483647 (0): " << solution(0) << std::endl;
  return 0;
}
