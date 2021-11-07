#include <iostream>
#include <vector>

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

int solution(vector<int> &A, vector<int> &B)
{
  int Z = A.size();
  int number_of_same_prime_divisors = 0;
  for (int i = 0; i < Z; ++i) {
    int gcd = greatest_common_divisor(A[i], B[i], 1);
    if (gcd % (max(A[i], B[i]) / gcd) == 0) ++number_of_same_prime_divisors;
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

  return 0;
}
