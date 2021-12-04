#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

int solution(vector<int> &A)
{
  unordered_set<int> s;

  // Go through the vector
  for (const auto i : A) {
    if (s.count(i)) {
      // If already seen, remove
      s.erase(i);
    }
    else {
      // If not yet seen, or seen, but removed, add
      s.insert(i);
    }
  }

  // We will eventually end up with one element in the set, so return that.
  return *s.begin();
}

int main()
{
  vector<int> input1{9, 3, 9, 3, 9, 7, 9};
  cout << "9, 3, 9, 3, 9, 7, 9 => 7: " << solution(input1) << std::endl;

  return 0;
}
