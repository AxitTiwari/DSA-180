

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> lastVisitedCell(vector<vector<char>>& grid) {

        int m = grid.size(), n = grid[0].size();

        vector<vector<int>> visited(m, vector<int> (n, 0));

        solve(0, 0, grid, visited, m, n);
        return res;
    }
private:
    vector<int> res;
    void solve(int i, int j, vector<vector<char>>& grid, vector<vector<int>>& visited, int m, int n) {

        visited[i][j] = 1;

        int new_i, new_j;
        if (grid[i][j] == 'L') {
            new_i = i, new_j = j-1;
        }
        else if (grid[i][j] == 'R') {
            new_i = i, new_j = j+1;
        }
        else if (grid[i][j] == 'U') {
            new_i = i - 1, new_j = j;
        }
        else {
            new_i = i + 1, new_j = j;
        }

        if (new_i < 0 || new_i >= m || new_j < 0 || new_j >= n || visited[new_i][new_j]) {
            res.push_back(i);
            res.push_back(j);
            return;
        }

        solve(new_i, new_j, grid, visited, m, n);
    }

};