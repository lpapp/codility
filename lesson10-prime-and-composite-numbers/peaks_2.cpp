#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// 1. Build a hash for the peaks.
// 2. Build a hash for the following peaks.
// 3. Go through the possible group sizes. This could be optimised by
//    calculating the max distance between peak pairs. As diff / 2 is the
//    minimum group size to try. Also, by only going through divisors.
// 4. For each group size, check if the number of elements can be divided by
//    the group size without remainder. If not, skip.
// 5. Check if the next peak is in the current or next group, if not quit. Get
//    next peak from the previously built hash.
// 6. Check this for each peak.
// 7. If all peaks allocated correctly (minimum one peak per group), adjust the
//    maximum number of groups.

int solution(vector<int> &A)
{
  const int sizeA = A.size();
  vector<bool> hash(sizeA, false);
  for (int i = 1; i < sizeA - 1; ++i) {
    const int e = A[i];
    if (e > A[i - 1] && e > A[i + 1]) hash[i] = true;
  }

  vector<int> hash_next(sizeA, 0);
  for (int i = sizeA - 2; i >= 0; --i) {
    hash_next[i] = hash[i] ? i : hash_next[i + 1];
  }

  int max_number_of_groups = 0;
  for (int divisor = 1; divisor * divisor <= sizeA; ++divisor) {
    if (sizeA % divisor != 0) continue;
    const int complement_divisor = sizeA / divisor;
    vector<int> divisors{divisor};
    if (divisor != complement_divisor) divisors.push_back(complement_divisor);
    for (const int group_size : divisors) {
      if (group_size == 1) continue;
      int number_of_groups = sizeA / group_size;
      int group_index = 0;
      for (int peak_index = 0; peak_index < sizeA; peak_index = group_index * group_size) {
        peak_index = hash_next[peak_index];
        if (!peak_index) break;
        int lower_range = group_index * group_size;
        int upper_range = lower_range + group_size - 1;
        if (peak_index > upper_range) {
          break;
        }
        ++group_index;
      }

      if (number_of_groups == group_index) {
        max_number_of_groups = max(max_number_of_groups, number_of_groups);
      }
    }
  }

  return max_number_of_groups;
}

int main()
{
  vector<int> i1{1, 2, 3, 4, 3, 4, 1, 2, 3, 4, 6, 2};
  cout << "1, 2, 3, 4, 3, 4, 1, 2, 3, 4, 6, 2 => 3: " << solution(i1) << endl;

  vector<int> i2{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
  cout << "1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 => 0: " << solution(i2) << endl;

  vector<int> i3{1, 3, 2, 1};
  cout << "1, 3, 2, 1 => 1: " << solution(i3) << endl;

  return 0;
}
