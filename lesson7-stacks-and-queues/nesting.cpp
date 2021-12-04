#include <iostream>
#include <stack>
#include <string>

using namespace std;

int solution(string &S)
{
  stack<char> st;                                                               
                                                                                
  for (const auto c : S) {                                                      
    if (c == ')' && !st.empty() && st.top() == '(') st.pop();                             
    else st.push(c);                                                            
  }                                                                             
                                                                                
  return st.empty() ? 1 : 0;
}

int main()
{
  string i1 = "(()(())())";                            
  cout << "(()(())()) => 1: " << solution(i1) << endl;

  string i2 = "())";                            
  cout << "()) => 0: " << solution(i2) << endl;

  return 0;
}
