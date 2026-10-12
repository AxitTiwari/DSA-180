// https://leetcode.com/submissions/detail/2164532253/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minAddToMakeValid(string s) {
        
        int mini = 0;

        stack<char> st;
        for (char ch : s) {

            if (ch == '(') {
                st.push('(');
                continue;
            }

            if (st.empty()) {
                mini += 1;
            }
            else {
                st.pop();
            }
        }
        return mini + st.size();
    }
};