// https://leetcode.com/problems/maximum-subarray/submissions/1982769963

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        int ans = INT_MIN;
        int cur_sum = 0;
        for (int i = 0; i < nums.size(); i++) {

            cur_sum = max(nums[i], cur_sum + nums[i]);
            ans = max(ans, cur_sum);
        }
        return ans;
    }
private:
    void dfs(int i, int cur_sum, int &ans, vector<int> &nums) {

        if (i == nums.size()) return ;

        cur_sum = max(nums[i], cur_sum + nums[i]);
        ans = max(ans, cur_sum);

        dfs(i+1, cur_sum, ans, nums);
    }
};
