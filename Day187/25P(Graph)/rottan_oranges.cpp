// https://leetcode.com/problems/rotting-oranges/submissions/2073602653

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        queue<tuple<int, int, int>> q;
        int fresh_oranges = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j, 0});
                }

                if (grid[i][j] == 1) fresh_oranges++;
            }
        }

        int res = 0;
        while (!q.empty()) {

            auto [x, y, t] = q.front();
            q.pop();

            res = t;

            vector<pair<int, int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
            for (auto &[i, j] : dir) {
                int new_x = x + i;
                int new_y = y + j;

                if (not_safe(new_x, new_y, grid)) continue;

                fresh_oranges--;
                grid[new_x][new_y] = 2;

                q.push({new_x, new_y, t+1});
            }
        }
        return fresh_oranges == 0 ? res : -1;
    }
private:
    bool not_safe(int x, int y, vector<vector<int>> &grid) {
        return x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size() || grid[x][y] != 1;
    }
};