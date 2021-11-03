#include <iostream>

using namespace std;

int solution(int N)
{
  int factors = 0;
  int64_t i = 1;
  for (; i * i < N; ++i) {
    if (N % i == 0) factors += 2;
  }

  if (i * i == N) ++factors;

  return factors;
}

int main()
{
  cout << "24 => 8: " << solution(24) << endl;
  cout << "2147483647 => 2: " << solution(2147483647) << endl;
}
