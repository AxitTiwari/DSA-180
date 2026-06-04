// https://leetcode.com/problems/valid-parentheses/submissions/1911434093

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool is_open(char bracket) {return bracket == '(' || bracket == '{' || bracket == '[';}

    bool can_pop(stack<char> &s, char bracket) {

        if (s.empty()) return false;

        if (s.top() == '(' && bracket == ')') return true;
        if (s.top() == '{' && bracket == '}') return true;
        if (s.top() == '[' && bracket == ']') return true;
        return false;
    }

public:
    bool isValid(string s) {
        
        stack<char> brackets;
        for (char bracket : s) {

            if (is_open(bracket)) {
                brackets.push(bracket);
            }

            else {
                if (!can_pop(brackets, bracket)) {
                    return false;
                }
                brackets.pop();
            }
        }
        return brackets.empty();
    }
};
