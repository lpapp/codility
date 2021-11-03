#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

using namespace std;

int solution(vector<int> &A)
{
  size_t last_index = A.size() - 1;
  vector<int> first_slice(last_index, 0);
  vector<int> second_slice(last_index, 0);

  int seq_sum = 0;
  int max_sum = 0;
  for (size_t i = 1; i < last_index - 1; ++i) {
    int e = A[i];
    seq_sum = max(e, seq_sum + e);
    max_sum = max(max_sum, seq_sum);
    first_slice[i] = max_sum;
  }

  seq_sum = 0;
  max_sum = 0;
  for (int i = last_index - 1; i > 1; --i) {
    int e = A[i];
    seq_sum = max(e, seq_sum + e);
    max_sum = max(max_sum, seq_sum);
    second_slice[i] = max_sum;
  }

  max_sum = 0;
  for (size_t i = 1; i < last_index - 1; ++i) {
    max_sum = max(max_sum, first_slice[i - 1] + second_slice[i + 1]);
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
  cout << "6, 3, -100, 8, 4, 0, -1, 5 => 15: " << solution(i3) << endl;

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

  vector<int> i13{0, -2, 3, -2, 3, -1};
  cout << "0, -2, 3, -2, 3, -1 => 6: " << solution(i13) << endl;

  vector<int> i14{0, -2, 10, -1, 5, 0};
  cout << "0, -2, 10, -1, 5, 0 => 15: " << solution(i14) << endl;

  vector<int> i15{0, -1, 10, -2, 5, 0};
  cout << "0, -1, 10, -2, 5, 0 => 15: " << solution(i15) << endl;

  vector<int> i16{1, 1, 0, 10, -100, 10, 0};
  cout << " 1 1 0 10 -100 10 0 => 21: " << solution(i16) << endl;

  return 0;
}
