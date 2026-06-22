// https://leetcode.com/problems/regular-expression-matching/submissions/2041691855

// done ///.......

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        
        vector<vector<int>> dp(s.length(), vector<int> (p.length(), -1));
        return func(0, 0, s, p, dp);
    }
private:
    bool func(int i, int j, string &s, string &p, vector<vector<int>> &dp) {

        if (i == s.length() && j < p.length()-1 && p[j+1] == '*') {
            return func(i, j+2, s, p, dp);
        }

        if (i == s.length() && j == p.length()) return true;

        if (i == s.length() || j == p.length()) return false;

        if (dp[i][j] != -1) return dp[i][j];
        
        if (j < p.length()-1 && p[j+1] == '*') {

            if (s[i] == p[j] || p[j] == '.') {
                return dp[i][j] = func(i+1, j, s, p, dp) || func(i+1, j+2, s, p, dp) || func(i, j+2, s, p, dp);
            }
            else {
                return dp[i][j] = func(i, j+2, s, p, dp);
            }
        }
        else {

            if (s[i] == p[j] || p[j] == '.') {
                return dp[i][j] = func(i+1, j+1, s, p, dp);
            }
        }
        return false;
    }
};