// https://leetcode.com/problems/minimum-size-subarray-sum/submissions/2059676905

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        
        int sum = 0, res = INT_MAX;
        int l = 0;
        for (int r = 0; r < nums.size(); r++) {

            sum += nums[r];

            while (sum >= target) {
                res = min(res, r-l+1);
                sum -= nums[l++];
            }
        }

        return res == INT_MAX ? 0 : res;
    }
};