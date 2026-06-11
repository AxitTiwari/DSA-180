// https://leetcode.com/problems/max-area-of-island/submissions/2029383264

// check leetcode.....

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        int area = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                
                if (grid[i][j] == 1) {
                    area = max(area, dfs(i, j, grid));
                }
            }
        }
        return area;
    }
private:
    int dfs(int x, int y, vector<vector<int>>& grid) {

        if (x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size() || grid[x][y] == 0) return 0;

        // visited
        grid[x][y] = 0;

        return 1 + 
            dfs(x+1, y, grid) +
            dfs(x, y+1, grid) + 
            dfs(x-1, y, grid) +
            dfs(x, y-1, grid);
    }
};