#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        
        if (grid[0][0] == 1) {
            return -1;
        }

        queue<pair<pair<int, int>, int>> q; // ((i, j), nodes)
        q.push({{0, 0}, 1});

        int ans = 0;
        vector<vector<int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

        vector<vector<bool>> vis(grid.size(), vector<bool> (grid[0].size(), false));
        vis[0][0] = true;

        while (!q.empty()) {

            int i = q.front().first.first;
            int j = q.front().first.second;
            int nodes = q.front().second;
            q.pop();

            ans = ans > nodes ? ans : nodes;

            if (i == grid.size()-1 && j == grid[0].size()-1) break;

            for (auto d : dir) {

                int new_i = i + d[0];
                int new_j = j + d[1];

                if (
                    new_i >= 0 && new_i < grid.size() &&
                    new_j >= 0 && new_j < grid[0].size() &&
                    grid[new_i][new_j] == 0 &&
                    !vis[new_i][new_j]
                ) {
                    vis[new_i][new_j] = true;
                    q.push({{new_i, new_j}, nodes+1});
                }
            }
        }

        if (vis[grid.size()-1][grid[0].size()-1]) {
            return ans;
        }
        return -1;
    }
};