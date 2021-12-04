#include <cassert>
#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(string &S, vector<int> &P, vector<int> &Q)
{
  unordered_map<char, int> charHash{{'A', 1}, {'C', 2}, {'G', 3}, {'T', 4}};

  size_t sizeS = S.size();
  vector<vector<int>> prefix_sums(4, vector<int>(sizeS, 0));

  ++prefix_sums[charHash[S[0]] - 1][0];
  for (size_t i = 1; i < sizeS; ++i) {
    for (size_t j = 0; j < 4; ++j) {
      prefix_sums[j][i] = prefix_sums[j][i-1];
    }

    ++prefix_sums[charHash[S[i]] - 1][i];
  }

  size_t sizeP = P.size();
  vector<int> result(sizeP, 0);
  for (size_t i = 0; i < sizeP; ++i) {
    int pi = P[i];
    int qi = Q[i];

    if (pi == qi) {
      result[i] = charHash[S[pi]];
    }
    else {
      for (size_t j = 0; j < 4; ++j) {
        int start_sum = pi ? prefix_sums[j][pi - 1] : 0;
        if ((prefix_sums[j][qi] - start_sum) > 0) {
          result[i] = j + 1;
          break;
        }
      }
    }
  }

  return result;
}

int main()
{
  string S1 = "CAGCCTA";
  vector<int> P1{2, 5, 0};
  vector<int> Q1{4, 5, 6};
  vector<int> E1{2, 4, 1};
  cout << "{2, 4, 1}: ";
  for (const int e : solution(S1, P1, Q1))
    cout << e << " ";
  cout << endl;

  string S2 = "AC";
  vector<int> P2{0, 0, 1};
  vector<int> Q2{0, 1, 1};
  vector<int> E2{1, 1, 2};
  cout << "{1, 1, 2}: ";
  for (const int e : solution(S2, P2, Q2))
    cout << e << " ";
  cout << endl;

  string S3 = "AGGT";
  vector<int> P3{0, 1, 2, 3};
  vector<int> Q3{0, 1, 2, 3};
  vector<int> E3{1, 3, 3, 4};
  cout << "{1, 3, 3, 4}: ";
  for (const int e : solution(S3, P3, Q3))
    cout << e << " ";
  cout << endl;

  // assert(solution(S1, P1, Q1) == E1);
  return 0;
}
