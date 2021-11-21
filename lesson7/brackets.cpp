#include <iostream>
#include <stack>
#include <string>

using namespace std;

int solution(string &S)
{
  stack<char> st;

  for (const auto c : S) {
    if (st.empty()) st.push(c);
    else if (c == '}' and st.top() == '{') st.pop();
    else if (c == ']' and st.top() == '[') st.pop();
    else if (c == ')' and st.top() == '(') st.pop();
    else st.push(c);
  }

  return st.empty() ? 1 : 0;
}

int main()
{
  string i1 = "{[()()]}";
  cout << "{[()()]} => 1: " << solution(i1) << endl;

  string i2 = "([)()]";
  cout << "([)()] => 0: " << solution(i2) << endl;

  string i3 = "()[()]";
  cout << "()[()] => 1: " << solution(i3) << endl;

  string i4 = "{({})}[]()";
  cout << "{()}() => 1: " << solution(i4) << endl;

  string i5 = "{({})}[]()";
  cout << "{()}() => 1: " << solution(i5) << endl;

  string i6 = "}{";
  cout << "}{ => 0: " << solution(i6) << endl;

  return 0;
}
