// https://leetcode.com/submissions/detail/2000308559/

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int f(int i, int j, vector<int>& cuts, vector<vector<int>> &dp) {

        if (i > j) return 0;

        if (dp[i][j] != -1) return dp[i][j];

        int mini = INT_MAX;

        // pick each cut value one by one and check which is giving minimum value
        for (int k = i; k <= j; k++) {

            // cost for this kth cut
            int length  = cuts[j+1] - cuts[i-1];

            // independent problem : calucalate entire cost when we start cutting from kth cut
            int left = f(i, k-1, cuts, dp);
            int right = f(k+1, j, cuts, dp);

            // total cost if we start from kth cut
            int cost = length + left + right;
            
            // choose the minimum of all cuts value,
            mini = min(mini, cost);
        }
        return dp[i][j] = mini;
    }

public:
    int minCost(int n, vector<int>& cuts) {

        // MCM

        int n_cuts = cuts.size();
        
        cuts.push_back(0);
        cuts.push_back(n);

        // **imp
        sort(cuts.begin(), cuts.end());

        // partition DP
        vector<vector<int>> dp(n_cuts+1, vector<int> (n_cuts+1, -1));
        return f(1, n_cuts, cuts, dp);
    }
};