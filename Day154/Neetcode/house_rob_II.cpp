// https://leetcode.com/problems/house-robber-ii/submissions/2034653194

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {

        if (nums.size() == 1) return nums[0];
        
        vector<int> num1;
        for (int i = 0; i < nums.size()-1; i++) num1.push_back(nums[i]);

        vector<int> num2;
        for (int i = 1; i < nums.size(); i++) num2.push_back(nums[i]);

        vector<int> dp1(nums.size(), -1);
        vector<int> dp2(nums.size(), -1);
        return max(func(0, num1, dp1), func(0, num2, dp2));
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