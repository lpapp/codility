#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

int solution(std::vector<int> &A)
{
  std::unordered_map<int, int> hash_map;

  // Go through the vector
  for (const auto i : A) {
    if (hash_map.count(i)) {
      // If already seen, remove
      hash_map.erase(i);
    }
    else {
      // If not yet seen, or seen, but removed, add
      hash_map[i] = 1;
    }
  }

  // We will eventually end up with one element in the hash map, so return the
  // key of that.
  return hash_map.begin()->first;
}

int main()
{
  std::vector<int> input1{9, 3, 9, 3, 9, 7, 9};

  std::cout << "{9, 3, 9, 3, 9, 7, 9} (7): " << solution(input1) << std::endl;

  return 0;
}
