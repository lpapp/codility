#include <iostream>
#include <climits>
#include <unordered_map>
#include <vector>

using namespace std;

int solution(vector<int> &A)
{
  unordered_map<int, int> h;
  for (const int e : A) {
    ++h[e];
  }

  unordered_map<int, int> h2;
  int max = INT_MIN;
  int equi_leaders = 0;
  size_t sizeA = A.size();
  for (size_t i = 0; i < sizeA; ++i) {
    const int e = A[i];
    ++h2[e];
    if (h2[e] >= h2[max]) {
      max = e;
    }

    const bool seq1_leader = h2[max] > ((i + 1) / 2);
    const bool seq2_leader = (h[max] - h2[max]) > ((sizeA - 1 - i)  / 2);
    if (seq1_leader && seq2_leader) ++equi_leaders;
  }

  return equi_leaders;
}

int main()
{
  vector<int> i1{4, 3, 4, 4, 4, 2};
  cout << "4, 3, 4, 4, 4, 2 => 2: " << solution(i1) << endl;

  vector<int> i2{1, 2, 3, 4, 5, 6};
  cout << "1, 2, 3, 4, 5, 6 => 0: " << solution(i2) << endl;

  vector<int> i3{1, 2, 1, 1, 2, 1};
  cout << "1, 2, 1, 1, 2, 1 => 3: " << solution(i3) << endl;

  vector<int> i4{4, 4, 2, 5, 3, 4, 4, 4};
  cout << "4, 4, 2, 5, 3, 4, 4, 4 => 3: " << solution(i4) << endl;

  return 0;
}
