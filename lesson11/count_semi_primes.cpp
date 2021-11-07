#include <iostream>
#include <vector>

using namespace std;

// 1. Sieve, get primes up to N.
// 2. Get semi-primes up to N.
// 3. Prefix sum to store the number of semi-primes up to a particular index.
// 4. Get the semi prime counts.

vector<int> solution(int N, vector<int> &P, vector<int> &Q)
{
  vector<int> sieve(N, 0);
  for (int prime = 2; prime * prime <= N; ++prime) {
    for (int composite = prime * prime; composite <= N; composite += prime) {
      if (!sieve[composite - 1]) sieve[composite - 1] = prime; 
    }
  }

  vector<int> semi_primes;
  for (int i = 3; i < N; ++i) {
    const int e = sieve[i];
    if (e > 0 && !sieve[i / e]) semi_primes.push_back(i + 1);
  }
  if (semi_primes.empty()) semi_primes.push_back(0);

  vector<int> prefix_sums(N + 1, 0);
  for (int i = 1, spi = 0; i <= N; ++i) {
    prefix_sums[i] = ((semi_primes[spi] != i) ? spi : ++spi);
  }

  int M = P.size();
  vector<int> semi_prime_counts(M, 0);
  for (int i = 0; i < M; ++i) {
    semi_prime_counts[i] = prefix_sums[Q[i]] - prefix_sums[P[i] - 1];
  }

  return semi_prime_counts; 
}

int main()
{
  vector<int> p1{1, 4, 16};
  vector<int> q1{26, 10, 20};
  cout << "26 | 1, 4, 16 | 26, 10, 20 => 10, 4, 0: " << endl;
  vector<int> r1 = solution(26, p1, q1);
  for (auto e : r1)
    cout << e << " ";
  cout << endl; 

  vector<int> p2{1};
  vector<int> q2{1};
  cout << "1 | 1 | 1 => 0: " << endl;
  vector<int> r2 = solution(1, p2, q2);
  for (auto e : r2)
    cout << e << " ";
  cout << endl;

  return 0;
}
