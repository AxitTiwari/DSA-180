// https://leetcode.com/problems/combination-sum-ii/

// go to leetcode for some more better somution.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

        sort(candidates.begin(), candidates.end());
        
        vector<int> sum_of_values;
        vector<vector<int>> ans;
        dfs(0, target, sum_of_values, ans, candidates);
        return ans;
    }
    
private:
    void dfs(int i, int target, vector<int> &sum_of_values, vector<vector<int>> &ans, vector<int>& candidates) {

        if (target == 0) {
            ans.push_back(sum_of_values);
            return;
        }

        for (int j = i; j < candidates.size(); j++) {

            if (target - candidates[j] < 0) break;

            if (j > i && candidates[j] == candidates[j-1]) continue;

            sum_of_values.push_back(candidates[j]);

            dfs(j+1, target-candidates[j], sum_of_values, ans, candidates);

            sum_of_values.pop_back();
        }
    }
};
