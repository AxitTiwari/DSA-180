// https://leetcode.com/problems/interleaving-string/submissions/2016094550

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool f(int i, int j, int k, string &s1, string &s2, string &s3, vector<vector<vector<int>>> &dp) {

        if (k >= s3.length() && i >= s1.length() && j >= s2.length()) return true;

        if (k >= s3.length()) return false;

        if (dp[i][j][k] != -1) {
            return dp[i][j][k];
        }

        bool left = false;
        if (i < s1.length() && s1[i] == s3[k]) {
            left = f(i+1, j, k+1, s1, s2, s3, dp);
        }

        bool right = false;
        if (j < s2.length() && s2[j] == s3[k]) {
            right = f(i, j+1, k+1, s1, s2, s3, dp);
        }

        return dp[i][j][k] = left || right;
    }

public:
    bool isInterleave(string s1, string s2, string s3) {
        
        vector<vector<vector<int>>> dp(s1.length()+1, vector<vector<int>> (s2.length()+1, vector<int> (s3.length()+1, -1)));
        return f(0, 0, 0, s1, s2, s3, dp);
    }
};