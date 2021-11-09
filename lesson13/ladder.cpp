#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

vector<int> solution(vector<int> &A, vector<int> &B)
{
  const int L = A.size();
  vector<int> fibonacci_numbers(L, 1);
  fibonacci_numbers[1] = 2;
  for (int i = 2; i < L; ++i) {
    fibonacci_numbers[i] = (fibonacci_numbers[i - 1] + fibonacci_numbers[i - 2]) % static_cast<int>(pow(2, 30));
  }

  vector<int> consecutive_answers(L, 0);
  for (int i = 0; i < L; ++i) {
    consecutive_answers[i] = fibonacci_numbers[A[i] - 1] % static_cast<int>(pow(2, B[i]));
  }

  return consecutive_answers;
}

int main()
{
  vector<int> A1{4, 4, 5, 5, 1};
  vector<int> B1{3, 2, 4, 3, 1};
  cout << "4, 4, 5, 5, 1 - 3, 2, 4, 3, 1 => 5, 1, 8, 0, 1: \n";

  vector<int> R1 = solution(A1, B1);
  for (const int e : R1) cout << e << " ";
  cout << endl;

  return 0;
}
