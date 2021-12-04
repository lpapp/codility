#include <iostream>
#include <vector>

using namespace std;

// 1. Build up the fibonacci numbers up to jump size (other bank)
// 2. Set the min jumps to 1 for fibonacci leaves as they can be reached with a
//    single jump.
// 3. Go through each leaves.
// 4. Calculate the minimum jumps for the next leaf. Update it if it is more
//    than the current leaf minimum jumps count + 1.

int solution(vector<int> &A)
{
  int N = A.size();
  if (N < 3) return 1;

  vector<int> fibonacci_numbers{1, 2};
  int jump_size = N + 1;
  for (int fn = 3; fn <= jump_size; fn = fibonacci_numbers.back() + fibonacci_numbers[fibonacci_numbers.size() - 2]) {
    fibonacci_numbers.push_back(fn);
  }

  if (fibonacci_numbers.back() == jump_size) return 1;

  vector<int> min_jumps(jump_size, jump_size);
  for (const int fn : fibonacci_numbers) {
    const int i = fn - 1;
    if (A[i]) min_jumps[i] = 1;
  }

  for (int i = 0; i < N; ++i) {
    if (!A[i]) continue;
    for (const int fn : fibonacci_numbers) {
      int ni = i + fn;
      if (ni > jump_size) break;
      if ((ni < N and A[ni]) or (A[i] and ni == N)) {
        min_jumps[ni] = min(min_jumps[ni], min_jumps[i] + 1);
      }
    }
  }

  return min_jumps[N] == jump_size ? -1 : min_jumps[N];
}

int main()
{
  vector<int> i1{0, 0, 0, 1, 1, 0, 1, 0, 0, 0, 0};
  cout << "0, 0, 0, 1, 1, 0, 1, 0, 0, 0, 0 => 3: " << solution(i1) << endl;

  vector<int> i2{0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0};
  cout << "0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0 => 2: " << solution(i2) << endl;

  vector<int> i3{0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0};
  cout << "0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0 => 2: " << solution(i3) << endl;

  vector<int> i4{};
  cout << "[] => 1: " << solution(i4) << endl;

  vector<int> i5{};
  cout << "[0] => 1: " << solution(i5) << endl;

  vector<int> i6{};
  cout << "[0, 0] => 1: " << solution(i6) << endl;

  vector<int> i7{0, 0, 0};
  cout << "[0, 0, 0] => -1: " << solution(i7) << endl;

  vector<int> i8{1, 1, 1};
  cout << "[1, 1, 1] => 2: " << solution(i8) << endl;

  return 0;
}
