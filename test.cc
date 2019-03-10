#include <iostream>
#include <stack>
using namespace std;
class Parenthesis {
public:
    bool chkParenthesis(string A, int n) {
        // write code here
        stack<char> s;
        for (size_t i = 0; i < n; i++) {
            if (A[i] == '{' || A[i] == '[' || A[i] == '(') {
                if (A[i] == '{') {
                    if (!s.empty() && s.top() == '[' || s.top() == '(') {
                        return false;
                    }
                    s.push(A[i]);
                }
                else if (A[i] == '[') {
                    if (!s.empty() && s.top() == '(') {
                        return false;
                    }
                    s.push(A[i]);
                }
                else {
                    s.push(A[i]);
                }
            }else if (A[i] == '}' || A[i] == ']' || A[i] == ')'){
                if (A[i] == '}') {
                    if (!s.empty() && s.top() != '}') {
                        return false;
                    }else {
                      if (!s.empty())
                        s.pop();
                    }
                }
                else if (A[i] == ']') {
                  if (!s.empty() && s.top() != '[') {
                       return false; 
                   }else {
                      if (!s.empty())
                       s.pop();
                   }
                }
                else if (A[i] == ')') {
                   if (!s.empty() && s.top() != '(') {
                       return false; 
                   }else {
                       if (!s.empty())
                       s.pop();
                   }
                }
            }
            else {
                return false;
            }
        }
        if (!s.empty()) {
            return false;
        }
        return true;
    }
};
int main()
{
    string A = "()a()()";
    Parenthesis p;
    cout << p.chkParenthesis(A, A.size()) << endl;
    return 0;
}
