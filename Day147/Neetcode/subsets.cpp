// https://leetcode.com/problems/subsets/submissions/2027485249

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    void func(int i, vector<int> &subset, vector<vector<int>> &ans, vector<int> &nums) {

        if (i >= nums.size()) {
            ans.push_back(subset);
            return;
        }

        // include
        subset.push_back(nums[i]);
        func(i+1, subset, ans, nums);
        subset.pop_back();

        // exclude
        func(i+1, subset, ans, nums);
    }

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<vector<int>> ans;
        vector<int> subset;
        func(0, subset, ans, nums);
        return ans;
    }
};