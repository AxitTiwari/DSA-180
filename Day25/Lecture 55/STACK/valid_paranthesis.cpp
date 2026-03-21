#include <bits/stdc++.h>
using namespace std; 

bool isValidParenthesis(string str)
{
    // Write your code here.

    stack<char> s;

    for (int i = 0; i < str.length(); i++) {

        char ch = str[i];

        if (ch == '(' || ch == '{' || ch == '[') {
            s.push(ch);
        }
        else {

            if (!s.empty()) {

                char top = s.top();

                if ((top == '(' && ch == ')') || 
                    (top == '{' && ch == '}') || 
                    (top == '[' && ch == ']')) {

                    s.pop();
                }

                else {
                    return false;
                }
            }
            else {
                return false;
            }
        }
    }

    if (s.empty()) {
        return true;
    }
    else {
        return false;
    }
}