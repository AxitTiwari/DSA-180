// https://leetcode.com/problems/valid-parentheses/submissions/2063608265

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        
        stack<char> st;
        for (char c : s) {

            if (is_open(c)) {
                st.push(c);
            }
            else {

                if (st.empty()) return false;

                if (can_pop(st, c)) {
                    st.pop();
                }
                else {
                    return false;
                }
            }
        }
        return st.empty();
    }
private:
    bool is_open(char c) {
        return c == '(' || c == '{' || c == '[';
    }

    bool can_pop(stack<char> &st, char closed) {

        char open = st.top();

        if (open == '(' and closed == ')') return true;

        if (open == '{' and closed == '}') return true;

        if (open == '[' and closed == ']') return true;

        return false;
    }
};