// https://leetcode.com/problems/maximum-product-subarray/submissions/2034960133

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int res = nums[0];
        int cur_min = 1, cur_max = 1;

        for (int num : nums) {

            int tmp = cur_max * num;

            cur_max = max(max(tmp, num*cur_min), num);
            cur_min = min(min(tmp, num*cur_min), num);

            res = max(res, cur_max);
        }
        return res;
    }
};