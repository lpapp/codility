#include <iostream>
#include <vector>

std::vector<int> solution(int N, std::vector<int> &A)
{
  int max = 0;
  int seq_max = 0;
  std::vector<int> result(N, 0);

  for (const int e : A) {
    if (e == N + 1) {
      max = seq_max;
    }
    else {
     int index = e - 1;
     if (max > result[index]) result[index] = max;
     ++result[index];
     if (result[index] > seq_max) seq_max = result[index];
    }
  }

  for (int& e : result) {
    if (max > e) e = max;
  }

  return result;
}

int main()
{
  std::vector<int> input1{3, 4, 4, 6, 1, 4, 4};
  std::vector<int> result1 = solution(5, input1);

  std::cout << "{3, 4, 4, 6, 1, 4, 4} => {3, 2, 2, 4, 2}: ";
  for (const int e : result1) {
    std::cout << e << " ";
  }
  std::cout << std::endl;

  std::vector<int> input2{1, 2, 1, 2, 1, 2};
  std::vector<int> result2 = solution(1, input2);

  std::cout << "{1, 1, 1} => {3}: ";
  for (const int e : result2) {
    std::cout << e << " ";
  }
  std::cout << std::endl;

  /* std::vector<int> input3{1, 1, 1, 1, 1, 1};
  std::vector<int> result3 = solution(100000, input3);

  std::cout << "{1, 1, 1, 1, 1, 1} => {6}: ";
  for (const int e : result3) {
    std::cout << e << " ";
  }
  std::cout << std::endl; */

  return 0;
}

