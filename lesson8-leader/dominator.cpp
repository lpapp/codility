#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int solution(vector<int> &A)
{
  stack<int> s;
  for (const int e : A) {
    if (s.empty() || s.top() == e) s.push(e);
    else if (s.top() != e) s.pop();
  }

  int candidate = s.size() ? s.top() : -1;
  
  size_t count = 0;
  size_t di = 0;

  for (size_t i = 0; i < A.size(); ++i) {
    if (A[i] == candidate) { ++count; di = i; }
  }

  return (count > (A.size() / 2)) ? di : -1;
}

int main()
{
  vector<int> i1{3, 4, 3, 2, 3, -1, 3, 3};
  cout << "3, 4, 3, 2, 3, -1, 3, 3 => 7: " << solution(i1) << endl;

  vector<int> i2{1, 2, 3, 4, 5};
  cout << "1, 2, 3, 4, 5 => -1: " << solution(i2) << endl;
  return 0;
}
