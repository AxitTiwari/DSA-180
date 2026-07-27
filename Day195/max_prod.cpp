// https://leetcode.com/problems/maximum-product-of-two-elements-in-an-array/submissions/2083749468
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int n = nums.size() - 1;

        sort(nums.begin(), nums.end());
        return (nums[n] - 1) * (nums[n-1] - 1);
    }
};