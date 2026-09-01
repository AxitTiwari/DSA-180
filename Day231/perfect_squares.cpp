// https://leetcode.com/problems/perfect-squares/submissions/2126702329

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numSquares(int n) {
        
        vector<int> perfect_squares;
        for (int i = 1; i*i <= n; i++) perfect_squares.push_back(i*i);

        vector<int> dp(n+1, -1);

        return f(n, perfect_squares, dp);
    }
private:
    int f(int n, vector<int>& perfect_squares, vector<int>& dp) {

        if (n == 0) return 0;

        if (dp[n] != -1) return dp[n];

        int ans = INT_MAX;
        for (int s : perfect_squares) {

            if (s > n) continue;

            ans = min(f(n-s, perfect_squares, dp) + 1, ans);
        }
        return dp[n] = ans;
    }
};