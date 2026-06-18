// https://leetcode.com/problems/coin-change-ii/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        
        vector<vector<int>> dp(coins.size(), vector<int> (amount+1, -1));
        return func(0, amount, coins, dp);
    }
private:
    int func(int start_idx, int amount, vector<int> &coins, vector<vector<int>> &dp) {

        if (start_idx >= coins.size() || amount < 0) return 0;

        if (amount == 0) return 1;

        if (dp[start_idx][amount] != -1) return dp[start_idx][amount];

        int combinations = 0;
        for (int i = start_idx; i < coins.size(); i++) {
            combinations += func(i, amount-coins[i], coins, dp);
        }
        return dp[start_idx][amount] = combinations;
    }
};
