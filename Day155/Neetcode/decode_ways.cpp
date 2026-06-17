// https://leetcode.com/problems/decode-ways/submissions/2035961989

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        
        vector<int> dp(s.length(), -1);
        return func(0, s, dp);
    }
private:
    int func(int i, string &s, vector<int> &dp) {

        if (i > s.length()) return 0;

        if (i == s.length()) return 1;

        if (dp[i] != -1) return dp[i];

        int one_digit = 0;
        if (s[i] != '0')
            one_digit = func(i+1, s, dp);

        int two_digits = 0;
        if (i < s.length()-1 && s[i] != '0' && s[i] <= '2' && !(s[i] == '2' && s[i+1] > '6'))
            two_digits = func(i+2, s, dp);

        return dp[i] = one_digit + two_digits;
    }
};