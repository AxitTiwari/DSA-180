// https://leetcode.com/problems/longest-increasing-path-in-a-matrix/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        
        int ans = 0;

        vector<vector<bool>> visited(matrix.size(), vector<bool> (matrix[0].size(), false));
        vector<vector<int>> dp(matrix.size(), vector<int> (matrix[0].size(), -1));
        
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                ans = max(ans, func(i, j, matrix, visited, dp));
            }
        }
        return ans + 1;
    }

private:
    int func(int x, int y, vector<vector<int>> &matrix, vector<vector<bool>> &visited, vector<vector<int>> &dp) {

        if (dp[x][y] != -1) return dp[x][y];

        visited[x][y] = true;

        int ans = 0;
        vector<pair<int, int>> dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        for (auto &[r, c] : dirs) {

            int new_x = x + r;
            int new_y = y + c;

            if (is_safe(new_x, new_y, matrix, visited)) {

                if (matrix[x][y] < matrix[new_x][new_y])
                    ans = max(ans, 1 + func(new_x, new_y, matrix, visited, dp));
            }
        }
        visited[x][y] = false;
        return dp[x][y] = ans;
    }

    bool is_safe(int x, int y, vector<vector<int>> &matrix, vector<vector<bool>> &visited) {
        return !(x < 0 || y < 0 || x >= matrix.size() || y >= matrix[0].size() || visited[x][y]);
    }
};
