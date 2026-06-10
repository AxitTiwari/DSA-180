// https://leetcode.com/problems/permutations/submissions/2028223358

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> permute(vector<int>& nums) {
        
        vector<int> per;
        unordered_map<int, bool> used;
        dfs(used, per, nums);
        return res;
    }

private:
    void dfs(unordered_map<int, bool> &used, vector<int> &permutation, vector<int> &nums) {

        if (permutation.size() == nums.size()) {
            res.push_back(permutation);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {

            if (used[i]) continue;

            used[i] = true;

            permutation.push_back(nums[i]);
            dfs(used, permutation, nums);

            used[i] = false;
            permutation.pop_back();
        }
    }
};