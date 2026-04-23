// https://leetcode.com/problems/minimum-path-sum/submissions/1970519236

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // no need to create sum , keep track it by bottom to top
    int f(vector<vector<int>>& grid, int i, int j) {

        // no path
        if (i >= grid.size() || j >= grid[0].size()) {
            return INT_MAX;
        }

        // destination
        if (i == grid.size()-1 && j == grid[0].size()-1) {
            return grid[i][j];
        }

        int right = f(grid, i, j+1);
        int dowm = f(grid, i+1, j);

        // float sum from bottom to top, instead using a sum variable
        return grid[i][j] + min(right, dowm);
    }

    int memoizaton(vector<vector<int>>& grid, int i, int j, vector<vector<int>> &dp) {

        // no path
        if (i >= grid.size() || j >= grid[0].size()) {
            return INT_MAX;
        }

        // destination
        if (i == grid.size()-1 && j == grid[0].size()-1) {
            return grid[i][j];
        }

        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        int right = memoizaton(grid, i, j+1, dp);
        int dowm = memoizaton(grid, i+1, j, dp);

        return dp[i][j] = grid[i][j] + min(right, dowm);
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        
        // return f(grid, 0, 0);

        vector<vector<int>> dp(grid.size(), vector<int> (grid[0].size(), -1));
        return memoizaton(grid, 0, 0, dp);
    }
};