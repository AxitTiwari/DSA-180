// https://leetcode.com/problems/continuous-subarray-sum/submissions/2060195112

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        
        int sum = 0;
        unordered_map<int, int> get_index;
        get_index[0] = -1;
        for (int i = 0; i < nums.size(); i++) {

            sum += nums[i];

            if (get_index.find(sum%k) != get_index.end()) {

                if (i - get_index[sum%k] > 1) return true;
            }
            // **imp
            else get_index[sum%k] = i;
        }
        return false;
    }
};