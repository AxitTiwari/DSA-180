// https://leetcode.com/problems/target-sum/submissions/2037189094

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        
        return func(0, target, nums);
    }
private:
    map<pair<int, int>, int> dp;
    int func(int i, int amount, vector<int> &nums) {

        if (dp.count({i, amount})) return dp[{i, amount}];

        if (i == nums.size()) return amount == 0 ? 1 : 0;

        int add = func(i+1, amount-nums[i], nums);
        int sub = func(i+1, amount+nums[i], nums);

        return dp[{i, amount}] = add + sub;
    }
};