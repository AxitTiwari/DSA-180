// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/submissions/2018131615

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int f(int i, bool buy_sell, vector<int>& prices, vector<vector<int>> &dp) {

        if (i >= prices.size()) {
            return 0;
        }

        if (dp[i][buy_sell] != -1) {
            return dp[i][buy_sell];
        }

        int include, exclude;
        if (buy_sell == 0) {
            include = -prices[i] + f(i+1, 1, prices, dp);
            exclude = f(i+1, 0, prices, dp);

            return dp[i][buy_sell] = max(include, exclude);
        }
        else {
            include = prices[i] + f(i+2, 0, prices, dp);
            exclude = f(i+1, 1, prices, dp);

            return dp[i][buy_sell] = max(include, exclude);
        }
    }

public:
    int maxProfit(vector<int>& prices) {
        
        vector<vector<int>> dp(prices.size(), vector<int> (2, -1));
        return f(0, 0, prices, dp);
    }
};