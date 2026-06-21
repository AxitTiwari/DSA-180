// https://leetcode.com/problems/distinct-subsequences/submissions/2039967288

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numDistinct(string s, string t) {
        
        vector<vector<int>> dp(s.length(), vector<int> (t.length(), -1));
        return func(0, 0, s, t, dp);
    }
private:
    int func(int i, int j, string &s, string &t, vector<vector<int>> &dp) {

        if (j == t.length()) return 1;

        if (i == s.length()) return 0;

        if (dp[i][j] != -1) return dp[i][j];

        if (s[i] == t[j]) {

            int one_way = func(i+1, j+1, s, t, dp);
            int other_way = func(i+1, j, s, t, dp);

            return dp[i][j] = one_way + other_way;
        }
        else {
            return dp[i][j] = func(i+1, j, s, t, dp);
        }
    }
};
