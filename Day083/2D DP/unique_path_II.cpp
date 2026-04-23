// https://leetcode.com/problems/unique-paths-ii/submissions/1970488708

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int f(vector<vector<int>>& obstacleGrid, int i, int j) {

        if (i >= obstacleGrid.size() || j >= obstacleGrid[0].size()) {
            return 0;
        }

        if (obstacleGrid[i][j] == 1) {
            return 0;
        }

        if (obstacleGrid[i][j] != 1 && i == obstacleGrid.size()-1 && j == obstacleGrid[0].size()-1) {
            return 1;
        }

        int right = f(obstacleGrid, i, j+1);
        int down = f(obstacleGrid, i+1, j);

        return right + down;
    }

    int memoization(vector<vector<int>>& obstacleGrid, int i, int j, vector<vector<int>> &dp) {

        if (i >= obstacleGrid.size() || j >= obstacleGrid[0].size()) {
            return 0;
        }

        if (obstacleGrid[i][j] == 1) {
            return 0;
        }

        if (obstacleGrid[i][j] != 1 && i == obstacleGrid.size()-1 && j == obstacleGrid[0].size()-1) {
            return 1;
        }

        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        int right = memoization(obstacleGrid, i, j+1, dp);
        int down = memoization(obstacleGrid, i+1, j, dp);

        return dp[i][j] = right + down;
    }

    int tabulation(vector<vector<int>>& obstacleGrid) {

        int m = obstacleGrid.size(), n = obstacleGrid[0].size();

        vector<vector<long long>> dp(m+1, vector<long long> (n+1, 0));
        dp[m-1][n-1] = (obstacleGrid[m-1][n-1] == 0);

        for (int i = m-1; i >= 0; i--) {
            for (int j = n-1; j >= 0; j--) {

                if (obstacleGrid[i][j] == 1) {
                    dp[i][j] = 0;
                    continue;
                }

                if (i == m-1 && j == n-1) continue;

                long long right = dp[i][j+1];
                long long down = dp[i+1][j];

                dp[i][j] = right + down;
            }
        }
        return dp[0][0];
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        
        // no path
        if (obstacleGrid[0][0] == 1) {
            return 0;
        }

        // return f(obstacleGrid, 0, 0);

        vector<vector<int>> dp(obstacleGrid.size(), vector<int> (obstacleGrid[0].size(), -1));
        // return memoization(obstacleGrid, 0, 0, dp);

        return tabulation(obstacleGrid);
    }
};