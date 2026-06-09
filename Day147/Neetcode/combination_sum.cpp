// https://leetcode.com/problems/combination-sum/submissions/2027511270

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    void dfs(int i, int sum, vector<int> &sum_values, vector<vector<int>> &ans, vector<int>& candidates) {

        if (sum < 0) return;

        if (sum == 0) {
            ans.push_back(sum_values);
            return;
        }

        if (i >= candidates.size()) return;

        // include
        sum_values.push_back(candidates[i]);
        dfs(i, sum-candidates[i], sum_values, ans, candidates);
        sum_values.pop_back();

        // exclude
        dfs(i+1, sum, sum_values, ans, candidates);
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        vector<int> sum_values;
        vector<vector<int>> ans;
        dfs(0, target, sum_values, ans, candidates);
        return ans;
    }
};