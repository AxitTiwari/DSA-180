// https://leetcode.com/problems/burst-balloons/submissions/2040642516

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        
        int n = nums.size();

        nums.insert(nums.begin(), 1);
        nums.push_back(1);

        vector<vector<int>> dp(nums.size(), vector<int> (nums.size(), -1));
        return func(1, n, nums, dp);
    }
private:
    int func(int i, int j, vector<int> &coins, vector<vector<int>> &dp) {

        if (i > j) return 0;

        if (dp[i][j] != -1) return dp[i][j];

        int ans = INT_MIN;
        for (int k = i; k <= j; k++) {

            int coin = coins[i-1] * coins[k] * coins[j+1];

            int left = func(i, k-1, coins, dp);
            int right = func(k+1, j, coins, dp);

            int total = left + coin + right;

            ans = max(ans, total);
        }
        return dp[i][j] = ans;
    }
};