// https://leetcode.com/problems/wildcard-matching/submissions/1971379833

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool f(string& s, string& p, int i, int j) {

        if (i >= s.length() && j >= s.length()) {
            return true;
        }

        if (i == s.length()-1 && j != p.length()) {

            for (int k = j; k < p.length(); k++) {
                if (p[k] != '*') {
                    return false;
                }
            }
            return true;
        }

        if (s[i] == p[j] || p[j] == '?') {
            return f(s, p, i+1, j+1);
        }
        else {

            if (p[j] == '*') {

                return f(s, p, i+1, j) || f(s, p, i+1, j+1);
            }
            else {
                return false;
            }
        }
    }

    int mem(string& s, string& p, int i, int j, vector<vector<int>>& dp) {

        if (i < 0 && j < 0) {
            return 1;
        }

        if (j < 0 && i >= 0) {
            return 0;
        }

        if (i < 0 && j >= 0) {

            for (int k = j; k >= 0; k--) {
                if (p[k] != '*') {
                    return 0;
                }
            }
            return 1;
        }

        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        if (s[i] == p[j] || p[j] == '?') {
            return mem(s, p, i-1, j-1, dp);
        }
        else {

            if (p[j] == '*') {

                return dp[i][j] = (mem(s, p, i-1, j, dp) || mem(s, p, i-1, j-1, dp)
                    || mem(s, p, i, j-1, dp)
                );
            }
            else {
                return dp[i][j] = 0;
            }
        }
    }

public:
    bool isMatch(string s, string p) {
        
        // return f(s, p, 0, 0);

        int m = s.length()-1;
        int n = p.length()-1;
        vector<vector<int>> dp(s.length()+1, vector<int> (p.length()+1, -1));
        return mem(s, p, m, n, dp);
    }
};