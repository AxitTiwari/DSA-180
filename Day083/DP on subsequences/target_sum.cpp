// https://leetcode.com/problems/target-sum/submissions/1959071207

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int f(vector<int>& nums, int target, int i, int sum) {

        if (i == nums.size()) {
            return sum == target ? 1 : 0;
        }

        int add = f(nums, target, i+1, sum+nums[i]);
        int sub = f(nums, target, i+1, sum-nums[i]);

        return add + sub;
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        
        return f(nums, target, 0, 0);
    }
};