// https://leetcode.com/problems/find-pivot-index/submissions/2060106464

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {

        int n = nums.size();
        
        int total = 0;
        for (auto &num : nums) {
            total += num;
        }

        int sum = 0;
        for (int i = 0; i < n; i++) {

            int left_sum = sum;
            int right_sum = total - (sum + nums[i]);

            if (left_sum == right_sum) return i; 

            sum += nums[i];
        }
        return -1;
    }
};