#include <iostream>

using namespace std;

int greatest_common_divisor(int a, int b, int multiplier)
{
  if (a == b) return a * multiplier;
  else if (!(a & 1) and !(b & 1)) return greatest_common_divisor(a / 2, b / 2, 2 * multiplier);
  else if (!(a & 1)) return greatest_common_divisor(a / 2, b, multiplier);
  else if (!(b & 1)) return greatest_common_divisor(a, b / 2, multiplier);
  else if (a > b) return greatest_common_divisor(a - b, b, multiplier);
  else return greatest_common_divisor(a, b - a, multiplier);
  return 1;
}

int solution(int N, int M)
{
  return N / greatest_common_divisor(N, M, 1);
}

int main()
{
  cout << "10 4 => 5: " << solution(10, 4) << endl;
  return 0;
}
