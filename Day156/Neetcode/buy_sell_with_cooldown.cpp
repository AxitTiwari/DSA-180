// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/submissions/2037097227

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        vector<vector<int>> dp(prices.size(), vector<int> (2, -1));
        return func(0, true, prices, dp);
    }
private:
    int func(int cur_day, bool is_buy, vector<int> &prices, vector<vector<int>> &dp) {

        if (cur_day >= prices.size()) return 0;

        if (dp[cur_day][is_buy] != -1) return dp[cur_day][is_buy];

        if (is_buy) {

            return dp[cur_day][is_buy] = max(
                -prices[cur_day] + func(cur_day+1, false, prices, dp),
                func(cur_day+1, true, prices, dp)
            );
        }
        else {

            return dp[cur_day][is_buy] = max(
                prices[cur_day] + func(cur_day+2, true, prices, dp),
                func(cur_day+1, false, prices, dp)
            );
        }
    }
};