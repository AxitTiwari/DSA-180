// https://leetcode.com/problems/interleaving-string/submissions/2037223563

// also done in day 136.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        
        vector<vector<int>> dp(s1.length()+1, vector<int> (s2.length()+1, -1));
        return func(0, 0, s1, s2, s3, dp);
    }
    
private:
    bool func(int i, int j, string &s1, string &s2, string &s3, vector<vector<int>> &dp) {

        if (i >= s1.length() && j >= s2.length() && i+j == s3.length()) return true;

        if (i+j >= s3.length()) return false;

        if (dp[i][j] != -1) return dp[i][j];

        if (s1[i] == s3[i+j]) {
            if (func(i+1, j, s1, s2, s3, dp)) return dp[i][j] = true;
        }

        if (s2[j] == s3[i+j]) {
            if (func(i, j+1, s1, s2, s3, dp)) return dp[i][j] = true;
        }
        return dp[i][j] = false;
    }
};
