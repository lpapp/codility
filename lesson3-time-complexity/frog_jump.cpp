#include <iostream>

int solution(int X, int Y, int D)
{
  int distance = Y - X;
  // std::cout << "Distance: " << distance << std::endl;
  if (!distance) {
    return 0;
  }

  return (distance - 1) / D + 1;
}

int main()
{
  std::cout << "(10, 85, 30) -> (3): " << solution(10, 85, 30) << std::endl;
  std::cout << "(1, 1, 1) -> (0): " << solution(1, 1, 1) << std::endl;
  std::cout << "(1 000 000 000, 1 000 000 000, 1 000 000 000) -> (0): " << solution(1000000000, 1000000000, 1000000000) << std::endl;
	return 0;
}
