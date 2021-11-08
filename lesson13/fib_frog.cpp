#include <iostream>
#include <vector>

using namespace std;

int solution(vector<int> &A)
{
  int N = A.size(); 
  vector<int> fibonacci_numbers{0, 1};
  while (fibonacci_numbers.back() <= 100000) {
    fibonacci_numbers.push_back(fibonacci_numbers.back() + fibonacci_numbers[fibonacci_numbers.size() - 2]);
  }

  vector<int> min_jumps(N, 100001);
  for (int i = 0; i < N; ++i) {
    if (!A[i]) continue;
    for (const int fn : fibonacci_numbers) {
      int ni = i + fn;
      if (ni < N and A[ni] and min_jumps[ni]) min_jumps[ni]  = min(min_jumps[ni], min_jumps[i] + 1);
    }
  }

  return min_jumps[N-1] == 100001 ? -1 : min_jumps[N-1];
}

int main()
{
  vector<int> i1{0, 0, 0, 1, 1, 0, 1, 0, 0, 0, 0};
  cout << "0, 0, 0, 1, 1, 0, 1, 0, 0, 0, 0 => 3: " << solution(i1) << endl;

  vector<int> i2{0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0};
  cout << "0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0 => 2: " << solution(i2) << endl;

  vector<int> i3{0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0};
  cout << "0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0 => 2: " << solution(i3) << endl;
  return 0;
}
