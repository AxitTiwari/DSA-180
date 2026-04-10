
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    void dfs(pair<int, int> node, vector<vector<bool>>& visited, vector<vector<char>>& grid) {

        int x = node.first;
        int y = node.second;

        if (x < 0 || y < 0 || x == grid.size() || y == grid[0].size() || visited[x][y] || grid[x][y] == '0') {
            return;
        }

        visited[x][y] = true;

        dfs({x-1, y}, visited, grid);
        dfs({x+1, y}, visited, grid);
        dfs({x, y-1}, visited, grid);
        dfs({x, y+1}, visited, grid);
    }

    int numIslands(vector<vector<char>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>> visited(n, vector<bool> (m, false));

        int islands = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1' && !visited[i][j]) {

                    pair<int, int> node = {i, j};
                    dfs(node, visited, grid);
                    islands++;
                }
            }
        }

        return islands;
    }
};