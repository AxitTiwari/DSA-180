// https://leetcode.com/problems/maximum-sum-of-distinct-subarrays-with-length-k/submissions/2058015611

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        
        long long res = 0, sum = 0;

        int l = 0;
        unordered_set<int> cnt;
        for (int r = 0; r < nums.size(); r++) {

            while (cnt.find(nums[r]) != cnt.end() || cnt.size() == k) {
                cnt.erase(nums[l]);
                sum -= nums[l];
                l++;
            }

            sum += nums[r];
            cnt.insert(nums[r]);

            if (cnt.size() == k) {
                res = max(res, sum);
            }
        }
        return res;
    }
};