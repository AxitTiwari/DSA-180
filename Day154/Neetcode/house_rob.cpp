// https://leetcode.com/problems/house-robber/submissions/2034636865

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        
        vector<int> dp(nums.size(), -1);
        return func(0, nums, dp);
    }
private:
    int func(int cur_house, vector<int> &nums, vector<int> &dp) {

        if (cur_house >= nums.size()) return 0;

        if (dp[cur_house] != -1) return dp[cur_house];

        int include = func(cur_house+2, nums, dp) + nums[cur_house];
        int exclude = func(cur_house+1, nums, dp);

        return dp[cur_house] = max(include, exclude);
    }
};