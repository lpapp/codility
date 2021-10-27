#include <iostream>
#include <vector>

std::vector<int> solution(std::vector<int> &A, int K)
{
  uint8_t size_A = A.size();
  if (!size_A) {
    return std::vector<int>{};
  }

  // This could overflow, so count the modulo. Shifting more than the size of
  // array is equal to shifting - size of array, etc.
  uint8_t shift = K % size_A;


  std::vector<int> result;
  // Cycle what needs cycling from the right side to the left.
  for (size_t i = 0; i < shift; ++i) {
    result.push_back(A[size_A - shift + i]);
  }

  // Shift the beginning of the array towards the right without overflow.
  for (size_t i = 0; i < size_A - shift; ++i) {
    result.push_back(A[i]);
  }

  return result;
}

int main()
{
  // 1, 2, 3, 4 => (1) => 4 1 2 3 
  // 1, 2, 3, 4 => (2) => 3 4 1 2
  // 1, 2, 3, 4 => (3) => 2 3 4 1

  std::vector<int> input1{3, 8, 9, 7, 6};
  auto result1 = solution(input1, 3); 
  std::cout << "[3, 8, 9, 7, 6] (3) => [9, 7, 6, 3, 8]: ";
  for (const auto i : result1) {
    std::cout << i << " ";
  }
  std::cout << std::endl;

  std::vector<int> input2{3, 8, 9, 7, 6};
  auto result2 = solution(input2, 1); 
  std::cout << "[3, 8, 9, 7, 6] (1) => [6, 3, 8, 9, 7]: ";
  for (const auto i : result2) {
    std::cout << i << " ";
  }
  std::cout << std::endl;

  std::vector<int> input3{0, 0, 0};
  auto result3 = solution(input3, 1); 
  std::cout << "[0, 0, 0] (1) => [0, 0, 0]: ";
  for (const auto i : result3) {
    std::cout << i << " ";
  }
  std::cout << std::endl;


  std::vector<int> input4{1, 2, 3, 4};
  auto result4 = solution(input4, 4); 
  std::cout << "[1, 2, 3, 4] (4) => [1, 2, 3, 4]: ";
  for (const auto i : result4) {
    std::cout << i << " ";
  }
  std::cout << std::endl;

  std::vector<int> input5{};
  auto result5 = solution(input5, 100); 
  std::cout << "[] (100) => []: ";
  for (const auto i : result5) {
    std::cout << i << " ";
  }
  std::cout << std::endl;

  return 0;
}
