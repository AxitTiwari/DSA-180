// https://leetcode.com/submissions/detail/2166554342/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeOuterParentheses(string s) {
        
        string ans;

        int cnt = 0;
        for (int i = 0; i < s.length(); i++) {

            if (s[i] == '(') {
                if (cnt > 0) ans += '(';

                cnt++;
            }
            else {
                cnt--;

                if (cnt > 0) ans += ')';
            }
        }
        return ans;
    }
};