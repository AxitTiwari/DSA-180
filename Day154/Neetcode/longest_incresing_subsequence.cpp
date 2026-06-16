// https://leetcode.com/problems/longest-increasing-subsequence/submissions/2035405760

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        
        vector<vector<int>> dp(nums.size()+1, vector<int> (nums.size()+1, -1));
        nums.insert(nums.begin(), INT_MIN);
        return func(1, 0, nums, dp);
    }
private:
    int func(int cur, int prev, vector<int> &nums, vector<vector<int>> &dp) {

        if (cur >= nums.size()) return 0;

        if (dp[cur][prev] != -1) return dp[cur][prev];

        int take = 0;
        if (nums[prev] < nums[cur]) {
            take = 1 + func(cur+1, cur, nums, dp);
        }

        int not_take = func(cur+1, prev, nums, dp);

        return dp[cur][prev] = max(take, not_take);
    }
};