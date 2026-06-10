// https://leetcode.com/problems/subsets-ii/submissions/2028269023

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    void print(vector<int> &num) {

        for (int n : num) {
            cout << n << " ";
        }
        cout << endl;
    }
    
    void func(int i, vector<int> &subset, vector<vector<int>> &ans, vector<int> &nums) {

        // print(subset);

        if (i >= nums.size()) {
            ans.push_back(subset);
            return;
        }

        // include
        subset.push_back(nums[i]);
        func(i+1, subset, ans, nums);
        
        subset.pop_back();

        // exclude
        while (i+1 < nums.size() && nums[i] == nums[i+1]) i++;
        func(i+1, subset, ans, nums);
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        sort(nums.begin(), nums.end());
        
        vector<vector<int>> ans;
        vector<int> subset;
        func(0, subset, ans, nums);
        return ans;
    }
};
