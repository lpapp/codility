#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

using namespace std;

// Go through all slices calculating their sum
// But this time without the min element added to the sum
// So, we need to maintain the minimum element somehow in each slice.
// This minimum element needs to exclude the first and last indices because of
// this:
// A triplet (X, Y, Z), such that 0 ≤ X < Y < Z < N, is called a double slice.
// The sum of double slice (X, Y, Z) is the total of A[X + 1] + A[X + 2] + ... + A[Y − 1] + A[Y + 1] + A[Y + 2] + ... + A[Z − 1].


int solution(vector<int> &A)
{
  int seq_sum = 0;
  int min_e = A[1];
  int max_sum = seq_sum;
  size_t last_index = A.size() - 1;

  for (size_t i = 2; i < last_index; ++i) {
    const int e = A[i];

    seq_sum = max(e, seq_sum + e);
    cout << "SEQ_SUM: " << seq_sum << endl;
    max_sum = max(max_sum, seq_sum);

    if (seq_sum >= e) {
      if (e < min_e) {
        seq_sum += min_e - e;
        cout << "SEQ_SUM 2: " << seq_sum << endl;
        max_sum = max(max_sum, seq_sum);
        min_e = e;
      }
    }
    else {
      seq_sum = A[i];
      ++i;
      if (i < last_index) {
        min_e = A[i];
      }
    }
  }

  return max_sum;
}

int main()
{
  vector<int> i1{3, 2, 6, -1, 4, 5, -1, 2};
  cout << "3, 2, 6, -1, 4, 5, -1, 2 => 17: " << solution(i1) << endl;

  vector<int> i2{3, 2, -100, 3, 4, -1, 5, 0};
  cout << "3, 2, -100, 3, 4, -1, 5, 0 => 13: " << solution(i2) << endl;

  vector<int> i3{6, 3, -100, -50, 8, 4, 0, -1, 5};
  cout << "6, 3, -100, 8, 4, 0, -1, 5 => 12: " << solution(i3) << endl;

  vector<int> i4{1, 2, 3, 4, 5, 6};
  cout << "1, 2, 3, 4, 5, 6 => 12: " << solution(i4) << endl;

  vector<int> i5{-1, -2, -3, -4, -5, -6};
  cout << "-1, -2, -3, -4, -5, -6 => 0: " << solution(i5) << endl;

  vector<int> i6{5, 5, 5};
  cout << "5, 5, 5 => 0: " << solution(i6) << endl;

  vector<int> i7{5, 17, 0, 3};
  cout << "5, 17, 0, 3 => 17: " << solution(i7) << endl;

  vector<int> i8{5, 0, 1, 0, 5};
  cout << "5, 0, 1, 0, 5 => 1: " << solution(i8) << endl;

  vector<int> i9{0, 10, -5, -2, 0};
  cout << "0, 10, -5, -2, 0 => 10: " << solution(i9) << endl;

  vector<int> i10{6, 1, 5, 6, 4, 2, 9, 4};
  cout << "6, 1, 5, 6, 4, 2, 9, 4 => 26: " << solution(i10) << endl;

  vector<int> i11{5, 0, 17, 3};
  cout << "5, 0, 17, 3 => 17: " << solution(i11) << endl;

  // 1, -1, 1 (X=1, Y=3, Z=5)
  vector<int> i12{0, -1, 1, -1, 1, -1};
  cout << "0, -1, 1, -1, 1, -1 => 2: " << solution(i12) << endl;

  return 0;
}
