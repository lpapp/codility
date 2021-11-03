#include <iostream>
#include <vector>

using namespace std;

vector<int> solution(vector<int> &A, int K)
{
  uint8_t sizeA = A.size();
  if (!sizeA) {
    return vector<int>{};
  }

  // This could overflow, so count the modulo. Shifting more than the size of
  // array is equal to shifting - size of array, etc.
  uint8_t shift = K % sizeA;


  vector<int> result;
  result.reserve(sizeA);
  // Cycle what needs cycling from the right side to the left.
  for (size_t i = 0; i < shift; ++i) {
    result.push_back(A[sizeA - shift + i]);
  }

  // Shift the beginning of the array towards the right without overflow.
  for (size_t i = 0; i < sizeA - shift; ++i) {
    result.push_back(A[i]);
  }

  return result;
}

int main()
{
  // 1, 2, 3, 4 => (1) => 4 1 2 3 
  // 1, 2, 3, 4 => (2) => 3 4 1 2
  // 1, 2, 3, 4 => (3) => 2 3 4 1

  vector<int> input1{3, 8, 9, 7, 6};
  auto result1 = solution(input1, 3); 
  cout << "[3, 8, 9, 7, 6] (3) => [9, 7, 6, 3, 8]: ";
  for (const auto i : result1) {
    cout << i << " ";
  }
  cout << endl;

  vector<int> input2{3, 8, 9, 7, 6};
  auto result2 = solution(input2, 1); 
  cout << "[3, 8, 9, 7, 6] (1) => [6, 3, 8, 9, 7]: ";
  for (const auto i : result2) {
    cout << i << " ";
  }
  cout << endl;

  vector<int> input3{0, 0, 0};
  auto result3 = solution(input3, 1); 
  cout << "[0, 0, 0] (1) => [0, 0, 0]: ";
  for (const auto i : result3) {
    cout << i << " ";
  }
  cout << endl;


  vector<int> input4{1, 2, 3, 4};
  auto result4 = solution(input4, 4); 
  cout << "[1, 2, 3, 4] (4) => [1, 2, 3, 4]: ";
  for (const auto i : result4) {
    cout << i << " ";
  }
  cout << endl;

  vector<int> input5{};
  auto result5 = solution(input5, 100); 
  cout << "[] (100) => []: ";
  for (const auto i : result5) {
    cout << i << " ";
  }
  cout << endl;

  return 0;
}
