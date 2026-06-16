// https://leetcode.com/problems/palindromic-substrings/submissions/2034740051

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countSubstrings(string s) {
        
        memset(dp, -1, sizeof(dp));

        int cnt = 0;
        for (int i = 0; i < s.length(); i++) {
            for (int j = i; j < s.length(); j++) {

                if (solve(i, j, s)) {

                    cnt++;
                }
            }
        }
        return cnt;
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