// https://leetcode.com/problems/longest-palindromic-substring/submissions/2034714314

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        
        memset(dp, -1, sizeof(dp));

        int maxlen = INT_MIN;
        int starting_i = -1;
        for (int i = 0; i < s.length(); i++) {
            for (int j = 0; j < s.length(); j++) {

                if (solve(i, j, s)) {

                    if (j - i + 1 > maxlen) {
                        maxlen = j - i + 1;
                        starting_i = i;
                    }
                }
            }
        }
        return s.substr(starting_i, maxlen);
    }
private:
    int dp[1001][1001];
    bool solve(int l, int r, string &s) {

        if (l >= r) return true;

        if (dp[l][r] != -1) return dp[l][r];

        if (s[l] == s[r]) return dp[l][r] = solve(l+1, r-1, s);
        return dp[l][r] = false;
    }
};