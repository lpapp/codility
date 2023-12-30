#include <iostream>
#include <vector>

using namespace std;

// 1. Count the greatest common divisor.
// 2. Divide each number with that repeatedly until you either get:
//    a. one gcd
//    a. one number
// 3. Increase the count if you get number one rather than one gcd.

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

int solution(vector<int> &A, vector<int> &B)
{
  int Z = A.size();
  int number_of_same_prime_divisors = 0;
  for (int i = 0; i < Z; ++i) {
    int ai = A[i];
    int bi = B[i];
    int gcd = greatest_common_divisor(ai, bi, 1);
    int agcd = gcd, bgcd = gcd;
    for (ai /= agcd; ai != 1 and agcd != 1; ai /= agcd) agcd = greatest_common_divisor(ai, agcd, 1);
    for (bi /= bgcd; bi != 1 and bgcd != 1; bi /= bgcd) bgcd = greatest_common_divisor(bi, bgcd, 1);
    if (ai == 1 and bi == 1) ++number_of_same_prime_divisors; 
  }

  return number_of_same_prime_divisors;
}

int main()
{
  vector<int> A1{15, 10, 3};
  vector<int> B1{75, 30, 5};
  cout << "15, 10, 3 - 75, 30, 5 => 1: " << solution(A1, B1) << endl;

  vector<int> A2{2, 1, 2};
  vector<int> B2{1, 2, 2};
  cout << "2, 1, 2 - 1, 2, 2 => 1: " << solution(A2, B2) << endl;

  vector<int> A3{15, 10, 3};
  vector<int> B3{375, 30, 5};
  cout << "15, 10, 3 - 375, 30, 5 => 1: " << solution(A3, B3) << endl;

  vector<int> A4{45, 10, 3};
  vector<int> B4{75, 30, 5};
  cout << "45, 10, 3 - 75, 30, 5 => 1: " << solution(A4, B4) << endl;

  vector<int> A5{15, 20, 3};
  vector<int> B5{75, 30, 5};
  cout << "15, 20, 3 - 75, 30, 5 => 1: " << solution(A5, B5) << endl;

  return 0;
}
