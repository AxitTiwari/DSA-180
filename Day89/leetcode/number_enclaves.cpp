// https://leetcode.com/problems/number-of-enclaves/submissions/1976490736

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    void dfs(int x, int y, vector<vector<bool>>& is_safe, vector<vector<int>>& grid) {

        is_safe[x][y] = true;

        vector<vector<int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        for (auto d : dir) {
            int new_x = x + d[0];
            int new_y = y + d[1];

            if (new_x >= 0 && new_x < is_safe.size() &&
                new_y >= 0 && new_y < is_safe[0].size() &&
                grid[new_x][new_y] == 1 &&
                !is_safe[new_x][new_y]
            ) {
                dfs(new_x, new_y, is_safe, grid);
            }
        }
    }

public:
    int numEnclaves(vector<vector<int>>& grid) {
        
        vector<vector<bool>> is_safe(grid.size(), vector<bool> (grid[0].size(), false));

        for (int row = 0; row < grid.size(); row++) {

            for (int col = 0; col < grid[0].size(); col++) {

                if ((row == 0 || row == grid.size()-1 ||
                    col == 0 || col == grid[0].size()-1) &&
                    !is_safe[row][col] &&
                    grid[row][col] == 1
                ) {
                    dfs(row, col, is_safe, grid);
                }
            }
        }

        int count = 0;
        for (int i = 0; i < is_safe.size(); i++) {
            for (int j = 0; j < is_safe[0].size(); j++) {

                if (grid[i][j] == 1 && !is_safe[i][j]) {
                    count++;
                }
            }
        }
        return count;
    }
};