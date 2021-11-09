#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

// 1. Compute the first L fibonacci numbers. Each calculation needs modulo 2^30
//    because the 50000th fibonacci number cannot be stored even in long
//    double, it is so big. Since INT_MAX is 2^31, the summary of previously
//    modulo'd numbers by 2^30 cannot exceed that. Therefore, we do not need to
//    have bigger store and/or casting.
// 
// 2. Go through the arrays executing the lookup and modulos. We can be sure
//    this gives the correct result since modulo 2^30 does not take any
//    information away. E.g. modulo 100 does not take away any information for
//    subsequent modulo 10.

vector<int> solution(vector<int> &A, vector<int> &B)
{
  const int L = A.size();
  vector<int> fibonacci_numbers(L, 1);
  fibonacci_numbers[1] = 2;
  static const int pow_2_30 = pow(2, 30);
  for (int i = 2; i < L; ++i) {
    fibonacci_numbers[i] = (fibonacci_numbers[i - 1] + fibonacci_numbers[i - 2]) % pow_2_30;
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
