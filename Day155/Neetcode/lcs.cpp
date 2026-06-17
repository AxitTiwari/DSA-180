// https://leetcode.com/problems/longest-common-subsequence/submissions/2036578465

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        
        vector<vector<int>> dp(text1.length(), vector<int> (text2.length(), -1));
        return func(0, 0, text1, text2, dp);
    }
private:
    int func(int i, int j, string &text1, string &text2, vector<vector<int>> &dp) {

        if (i >= text1.length() || j >= text2.length()) return 0;

        if (dp[i][j] != -1) return dp[i][j];

        if (text1[i] == text2[j]) {
            return dp[i][j] = 1 + func(i+1, j+1, text1, text2, dp);
        }
        else {
            return dp[i][j] = max(func(i+1, j, text1, text2, dp), func(i, j+1, text1, text2, dp));
        }
    }
};