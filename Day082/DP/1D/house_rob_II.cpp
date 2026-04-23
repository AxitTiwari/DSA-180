// https://leetcode.com/problems/house-robber-ii/submissions/1969876883

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

        for (int index = nums.size()-1; index >= 0; index--) {

            int rob = nums[index] + dp[index+2];
            int not_rob = dp[index+1];

            dp[index] = max(rob, not_rob);
        }
        return dp[0];
    }


    // space optimisation
    int solve(vector<int> &nums) {

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
        
        int n = nums.size();

        if (n == 1) return nums[0];
        
        vector<int> first, second;
        for (int i = 0; i < n; i++) {

            if (i != n-1) {
                // all val execpt last one
                first.push_back(nums[i]);
            }

            if (i != 0) {
                // all values except first one
                second.push_back(nums[i]);
            }
        }

        // return max(solve(first, 0), solve(second, 0));

        // return max(f(first, 0), f(second, 0));

        vector<int> dp1(nums.size(), -1);
        vector<int> dp2(nums.size(), -1);
        // return max(memoization(first, 0, dp1), memoization(second, 0, dp2));

        return max(tabulation(first), tabulation(second));
    }
};