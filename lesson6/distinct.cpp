#include <iostream>
#include <vector>

using namespace std;

int solution(vector<int> &A)
{
  if (A.empty()) {
    return 0;
  }

  int unique_counter = 1;
  sort(A.begin(), A.end());

  for (size_t i = 1; i < A.size(); ++i) {
    if (A[i] != A[i - 1]) ++unique_counter;
  }

  return unique_counter;
}

int main()
{
  vector<int> input1{2, 1, 1, 2, 3, 1};
  cout << "2, 1, 1, 2, 3, 1 => 3: " << solution(input1) << endl;

  vector<int> input2{};
  cout << "{} => 0: " << solution(input2) << endl;

  return 0;
}
