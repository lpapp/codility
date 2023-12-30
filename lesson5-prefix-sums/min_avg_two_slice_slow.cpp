#include <iostream>
#include <vector>

using namespace std;

int solution(vector<int> &A)
{
  size_t sizePrefix = A.size() + 1;
  vector<int64_t> prefix_sums(sizePrefix, 0);
  for (size_t i = 1; i < sizePrefix; ++i) {
    prefix_sums[i] = prefix_sums[i - 1] + A[i - 1];
  }

  int min_avg_index = 0;
  double min_avg = 10000;

  for (size_t i = 1; i < sizePrefix - 1; ++i) {
    for (size_t j = i + 1; j < sizePrefix; ++j) {
      double slice_avg = static_cast<double>(prefix_sums[j] - prefix_sums[i - 1]) / (j - i + 1);

      if (slice_avg < min_avg) {
        min_avg = slice_avg;
        min_avg_index = i - 1;
      }
    }
  }

  return min_avg_index;
}

int main()
{
  vector<int> input1{4, 2, 2, 5, 1, 5, 8};
  cout << "4, 2, 2, 5, 1, 5, 8 => 1: " << solution(input1) << endl;

  vector<int> input2{-3, -5, -8, -4, -10};
  cout << "-3, -5, -8, -4, -10 => 2: " << solution(input2) << endl;

  vector<int> input3{4, 2, 2, 5, 1, 1};
  cout << "4, 2, 2, 5, 1, 1 => 4: " << solution(input3) << endl;

  return 0;
}
