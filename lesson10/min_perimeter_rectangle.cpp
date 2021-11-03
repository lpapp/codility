#include <iostream>

using namespace std;

int solution(int N)
{
  int64_t i = 1;
  int min_perimeter = (1 + N) * 2;
  for (; i * i <= N; ++i) {
    if (N % i == 0) {
      int perimeter = 2 * (i + N/i);
      if (perimeter < min_perimeter) {
        min_perimeter = perimeter;
      }
    }
  }

  return min_perimeter;
}

int main()
{
  cout << "30 => 22: " << solution(30) << endl;
  cout << "1 => 4: " << solution(1) << endl;
  cout << "1000000000 => 40000: " << solution(100000000) << endl;

  return 0;
}
