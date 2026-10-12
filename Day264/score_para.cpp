// https://leetcode.com/submissions/detail/2164523564/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int scoreOfParentheses(string s) {
        
        stack<int> st;
        for (auto ch : s) {

            if (ch == '(') {
                st.push(-1);
                continue;
            }

            int value = st.top();
            st.pop();

            if (value == -1) {
                st.push(1);
                continue;
            }

            int tmp = 0;
            while (!st.empty() && value != -1) {
                tmp += 2 * value;
                value = st.top();
                st.pop();
            }

            // cout << tmp << " " ;
            st.push(tmp);
        } 

        int score = 0;
        while (!st.empty()) {

            int value = st.top();
            st.pop();

            // cout << value << endl;

            if (value == -1) continue;

            score += value;
        }
        return score;
    }
};