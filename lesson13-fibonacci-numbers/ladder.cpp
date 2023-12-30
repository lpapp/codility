#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

// Examples:
// N=1 => 1: 1
// N=2 => 2: 11, 2
// N=3 => 3: 111, 12, 21
// N=4 => 5: 1111, 22, 121, 112, 211
// N=5 => 8: 11111, 221, 122, 212, 1112, 1121, 1211, 2111

// The fibonacci logic can be proved by induction. Induct not just on one step,
// but on the past two steps, in the same way that fibonacci numbers are
// defined. The base cases are n=1 and n=2.
// Two options: either go up one or two.
// N can be obtained by append 2 at the end (or prepend at the front) for each
// N-2 possibilities, and 1 for each N-1 possibilities. The concatenation of
// the two lists then corresponds to the plus sign in the fibonacci sequence.

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
