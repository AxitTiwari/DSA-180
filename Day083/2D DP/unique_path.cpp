// https://leetcode.com/problems/unique-paths/submissions/1970498816

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int f(vector<vector<int>>& grid, int i, int j) {

        if (i >= grid.size() || j >= grid[0].size()) {
            return 0;
        }

        if (i == grid.size()-1 && j == grid[0].size()-1) {
            return 1;
        }

        int right = f(grid, i, j+1);
        int down = f(grid, i+1, j);

        return right + down;
    }

    int memoization(vector<vector<int>>& grid, int i, int j, vector<vector<int>>& dp) {

        if (i >= grid.size() || j >= grid[0].size()) {
            return 0;
        }

        if (i == grid.size()-1 && j == grid[0].size()-1) {
            return 1;
        }

        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        int right = memoization(grid, i, j+1, dp);
        int down = memoization(grid, i+1, j, dp);

        return dp[i][j] = right + down;
    }

public:
    int uniquePaths(int m, int n) {

        // create the grid
        vector<vector<int>> grid(m, vector<int> (n, 0));

        // return f(grid, 0, 0);

        vector<vector<int>> dp(m, vector<int> (n, -1));
        return memoization(grid, 0, 0, dp);
        
    }
};