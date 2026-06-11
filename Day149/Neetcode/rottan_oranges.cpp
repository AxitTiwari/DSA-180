// https://leetcode.com/problems/rotting-oranges/submissions/2029914244

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        queue<tuple<int, int, int>> q;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {

                if (grid[i][j] == 2) q.push({i, j, 0});
            }
        }

        int time = 0;
        while (!q.empty()) {

            auto [x, y, t] = q.front();
            q.pop();

            time = max(time, t);

            vector<pair<int, int>> dir = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

            for (auto &[i, j] : dir) {

                int new_x = x + i;
                int new_y = y + j;

                if (!is_safe(new_x, new_y, grid)) continue;
                
                grid[new_x][new_y] = 2;
                q.push({new_x, new_y, t+1});
            }
        }

        bool left_fresh = count(grid);

        return left_fresh? -1 : time; 
    }

private:

    bool count(vector<vector<int>>& grid) {

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {

                if (grid[i][j] == 1) return true;
            }
        }
        return false;
    }

    bool is_safe(int x, int y, vector<vector<int>>& grid) {

        return x >= 0 &&
           y >= 0 &&
           x < grid.size() &&
           y < grid[0].size() &&
           grid[x][y] == 1;
    }
};