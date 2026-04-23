#include <bits/stdc++.h>
using namespace std;    

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;

        queue<pair<pair<int, int>, int>> q; // {{i, j}, time}
        vector<vector<bool>> visited(m, vector<bool> (n, false));

        for (int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                
                if (grid[i][j] == 2) {
                    q.push({{i, j}, 0});
                    visited[i][j] = true;
                }
            }
        }

        while (!q.empty()) {

            int i = q.front().first.first;
            int j = q.front().first.second;
            int time = q.front().second;
            q.pop();

            ans = max(ans, time);

            if (i-1 >= 0 && !visited[i-1][j] && grid[i-1][j] == 1) {
                q.push({{i-1, j}, time+1});
                visited[i-1][j] = true;
            }

            if (j+1 < n && !visited[i][j+1] && grid[i][j+1] == 1) {
                q.push({{i, j+1}, time+1});
                visited[i][j+1] = true;
            }

            if (j-1 >= 0 && !visited[i][j-1] && grid[i][j-1] == 1) {
                q.push({{i, j-1}, time+1});
                visited[i][j-1] = true;
            }

            if (i+1 < m && !visited[i+1][j] && grid[i+1][j] == 1) {
                q.push({{i+1, j}, time+1});
                visited[i+1][j] = true;
            }
        }

        for (int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                
                if (grid[i][j] == 1 && !visited[i][j]) {
                    return -1;
                }
            }
        }
        return ans;
    }
};