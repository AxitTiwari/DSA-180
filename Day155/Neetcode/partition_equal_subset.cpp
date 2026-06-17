// https://leetcode.com/problems/partition-equal-subset-sum/submissions/2035894691

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {

        int total = 0;
        for (int num : nums) {
            total += num;
        }

        if (total & 1) return false;

        int target = total / 2;

        vector<vector<int>> dp(nums.size(), vector<int> (target+1, -1));
        return func(0, target, nums, dp);
    }
private:
    bool func(int i, int target, vector<int> &nums, vector<vector<int>> &dp) {

        if (i >= nums.size() || target < 0) {
            return target == 0;
        }

        if (dp[i][target] != -1) return dp[i][target];

        bool include = func(i+1, target-nums[i], nums, dp);
        bool exclude = func(i+1, target, nums, dp);

        return dp[i][target] = include || exclude;
    }
};