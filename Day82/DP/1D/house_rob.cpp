// https://leetcode.com/problems/house-robber/submissions/1969840228

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int f(vector<int> &nums, int index) {

        if (index >= nums.size()) {
            return 0;
        }

        int rob = nums[index] + f(nums, index+2);
        int not_rob = f(nums, index+1);

        return max(rob, not_rob);
    }

    int memoization(vector<int> &nums, int index, vector<int>& dp) {

        if (index >= nums.size()) {
            return 0;
        }

        if (dp[index] != -1) {
            return dp[index];
        }

        int rob = nums[index] + memoization(nums, index+2, dp);
        int not_rob = memoization(nums, index+1, dp);

        return dp[index] = max(rob, not_rob);
    }

    int tabulation(vector<int> &nums) {

        vector<int> dp(nums.size()+2, 0);

        for (int i = nums.size()-1; i >= 0; i--) {

            int rob = nums[i] + dp[i+2];
            int not_rob = dp[i+1];

            dp[i] = max(rob, not_rob);
        }
        return dp[0];
    }

    int solve(vector<int> &nums) {
        /* "space optimisarion (dp)" */
        
        int size_nums = nums.size();

        int prev2 = 0;
        int prev1 = nums[0];

        for (int i = 1; i < size_nums; i++) {

            int include = prev2 + nums[i];
            int exclude = prev1 + 0;

            int ans = max(include, exclude);

            prev2 = prev1;
            prev1 = ans;
        }

        return prev1;
    }
public:
    int rob(vector<int>& nums) {
        
        // return solve(nums);

        // return f(nums, 0);

        vector<int> dp(nums.size(), -1);
        // return memoization(nums, 0, dp);

        return tabulation(nums);
    }
};