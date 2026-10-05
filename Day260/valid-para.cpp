// https://leetcode.com/submissions/detail/2159505203/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        
        stack<char> st;
        for (auto ch : s) {

            if (ch == '(' || ch == '{' || ch == '[') st.push(ch);

            else {

                if (!is_valid(ch, st))
                    return false;
                
                st.pop();
            }
        }

        return st.empty();
    }
private:
    bool is_valid(char ch, stack<char>& st) { return !st.empty() && ((ch == ')' && st.top() == '(') || (ch == '}' && st.top() == '{') || (ch == ']' && st.top() == '[')) ;}
};