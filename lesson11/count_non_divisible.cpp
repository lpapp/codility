#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

// 1. Check the max element in A to spare spaces rather than sizeA * 2
// 2. Build a hash of the occurences in A.
// 3. Add {1, num} as divisors to all numbers.
// 4. Add all other divisors to all numbers.
// 5. Go through each number in A. Check how many times the divisors occur in A.
// 6. The non-divisors will be the length of A minus the found divisors.

vector<int> solution(vector<int> &A)
{
  const int sizeA = A.size();
  const int max_elem = *max_element(A.cbegin(), A.cend());
  vector<int> hash(max_elem, 0);
  vector<unordered_set<int>> divisors_hash(max_elem, unordered_set<int>{});
  for (const int e : A) {
    ++hash[e - 1];
    divisors_hash[e - 1].insert({1, e});
  }

  for (int i = 2; i * i <= max_elem; ++i) {
    for (int k = i; k <= max_elem; k += i) {
      if (hash[k - 1]) divisors_hash[k - 1].insert({i, k / i});
    }
  }

  vector<int> non_divisors(sizeA, 0);
  for (int i = 0; i < sizeA; ++i) {
    const int e = A[i];
    int divisor_count = 0;
    for (const int divisor : divisors_hash[e - 1]) {
      divisor_count += hash[divisor - 1];
    }
    non_divisors[i] = sizeA - divisor_count;
  }

  return non_divisors;
}

int main()
{
  vector<int> i1{3, 1, 2, 3, 6};
  cout << "3, 1, 2, 3, 6 => 2, 4, 3, 2, 0: ";
  for (const int e: solution(i1)) cout << e << " ";
  cout << endl;

  return 0;
}
