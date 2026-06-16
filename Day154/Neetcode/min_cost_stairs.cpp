// https://leetcode.com/problems/min-cost-climbing-stairs/submissions/2034626906

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        
        vector<int> dp1(cost.size(), -1);
        vector<int> dp2(cost.size(), -1);
        return min(func(0, cost, dp1), func(1, cost, dp2));
    }
private:
    int func(int cur_stair, vector<int> &cost, vector<int> &dp) {

        if (cur_stair >= cost.size()) return 0;

        if (dp[cur_stair] != -1) return dp[cur_stair];

        int first = func(cur_stair+1, cost, dp) + cost[cur_stair];
        int second = func(cur_stair+2, cost, dp) + cost[cur_stair];

        return dp[cur_stair] = min(first, second);
    }
};