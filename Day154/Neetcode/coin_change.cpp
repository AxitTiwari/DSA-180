// https://leetcode.com/problems/coin-change/submissions/2034925344

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        
        vector<vector<int>> dp(coins.size(), vector<int> (amount+1, -1));
        int ans = func(0, amount, coins, dp);
        return ans == INT_MAX ? -1 : ans;
    }
private:
    int func(int i, int amount, vector<int> &coins, vector<vector<int>> &dp) {

        if (amount == 0) return 0;

        if (amount < 0 || i >= coins.size()) return INT_MAX;

        if (dp[i][amount] != -1) return dp[i][amount];

        int include = func(i, amount-coins[i], coins, dp);
        int exclude = func(i+1, amount, coins, dp);

        include = include == INT_MAX ? INT_MAX : include + 1;
        exclude = exclude == INT_MAX ? INT_MAX : exclude;

        return dp[i][amount] = min(include, exclude);
    }
};