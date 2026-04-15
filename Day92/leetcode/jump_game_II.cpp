// https://leetcode.com/problems/jump-game-ii/submissions/1978884006 

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    
    // [2,3,1,1,4]
    int f(int index, int jump, vector<int>& nums) {

        if (index >= nums.size()-1) return jump;

        int mini = INT_MAX;
        for (int i = 1; i <= nums[index]; i++) {
            mini = min(mini, f(index + i, jump+1, nums));
        }
        return mini;
    }

    int mem(int index, int jump, vector<int>& nums, vector<vector<int>>& dp) {

        if (index >= nums.size()-1) return jump;

        if (dp[index][jump] != -1) return dp[index][jump];

        int mini = INT_MAX;
        for (int i = 1; i <= nums[index]; i++) {
            mini = min(mini, mem(index + i, jump+1, nums, dp));
        }
        return dp[index][jump] = mini;
    }

    int greedy(vector<int>& nums) {
        
        int jumps = 0, l = 0, r = 0;

        int n = nums.size();
        while (r < n-1) {

            int longest_jump = 0;
            for (int i = l; i <= r; i++) {
                longest_jump = max(longest_jump, i + nums[i]);
            }
            l = r + 1;
            r = longest_jump;
            jumps++;
        }
        return jumps;
    }
public:
    int jump(vector<int>& nums) {
        
        // return f(0, 0, nums);

        // vector<vector<int>> dp(nums.size()+1, vector<int> (nums.size()+1, -1));
        // return mem(0, 0, nums, dp);

        return greedy(nums);
    }
};