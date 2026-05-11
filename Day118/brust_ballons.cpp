// https://leetcode.com/problems/burst-balloons/submissions/2000447433

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int mem(int i, int j, vector<int> &nums, vector<vector<int>> &dp) {

        if (i > j) return 0;

        if (dp[i][j] != -1) return dp[i][j];

        int maxi = INT_MIN;
        for (int k = i; k <= j; k++) {

            int coin_kth = nums[i-1] * nums[k] * nums[j+1];

            int coin_left_kth = mem(i, k-1, nums, dp);
            int coin_right_kth = mem(k+1, j, nums, dp);

            int total_coins_kth = coin_left_kth + coin_kth + coin_right_kth;

            maxi = max(maxi, total_coins_kth);
        }
        return dp[i][j] = maxi;
    }
    
public:
    int maxCoins(vector<int>& nums) {

        int n = nums.size();
        
        nums.insert(nums.begin(), 1);
        nums.push_back(1);

        vector<vector<int>> dp(n+1, vector<int> (n+1, -1));
        return mem(1, n, nums, dp);
    }
};

/*
    int f(int i, int j, vector<int> &nums) {

        if (i > j) return 0;

        int maxi = INT_MIN;
        for (int k = i; k <= j; k++) {

            int coin = nums[k-1] * nums[k] * nums[k+1];

            int value = nums[k];
            nums.erase(nums.begin() + k);

            int left_coin = f(i, k-1, nums);
            int right_coin = f(k, j-1, nums);

            nums.insert(nums.begin()+k, value);

            int total_coins = left_coin + coin + right_coin;

            maxi = max(maxi, total_coins);
        }
        return maxi;
    }

*/