// https://leetcode.com/submissions/detail/2158816155/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        
        vector<int> seq;
        solve(1, k, n, seq);
        return res;
    }
private:
    vector<vector<int>> res;
    void solve(int idx, int k, int n, vector<int>& seq) {

        if (k == 0 && n == 0) {
            res.push_back(seq);
            return;
        }

        if (k < 0 || n < 0) return;

        for (int i = idx; i <= 9; i++) {
            seq.push_back(i);
            solve(i+1, k-1, n-i, seq);
            seq.pop_back();
        }
    }
};