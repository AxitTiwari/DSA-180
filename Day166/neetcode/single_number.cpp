// https://leetcode.com/problems/single-number/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
        int ans = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            ans = ans ^ nums[i];
        }
        return ans;
    }
};