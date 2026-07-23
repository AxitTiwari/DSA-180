#include <bits/stdc++.h>
using namespace std;

// bro do not attemp this ever now!!!!!!!

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {

        if (heights.size() == 1 and heights[0].size() == 1) return 0;
        
        vector<vector<bool>> visited(heights.size(), vector<bool> (heights[0].size(), false));
        return dfs(0, 0, INT_MIN, heights, visited);
    }
private:
    
    int dfs(int x, int y, int effort, vector<vector<int>>& heights, vector<vector<bool>>& visited) {

        // cout << x << " " << y << " : " << heights[x][y] << endl;

        if (x == heights.size()-1 and y == heights[0].size()-1) {
            return effort;
        }

        visited[x][y] = true;

        int ans = INT_MAX;
        vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
        for (auto &dir : dirs) {
            int new_x = x + dir.first;
            int new_y = y + dir.second;

            if (not_safe(new_x, new_y, heights, visited)) continue;

            // effort = max(effort, abs(heights[x][y] - heights[new_x][new_y]));
            // cout << effort << " ";
            // cout << ans;

            ans = min(dfs(new_x, new_y, max(effort, abs(heights[x][y] - heights[new_x][new_y])), heights, visited), ans);
        }

        // cout << x << " " << y << ": " << ans << endl;
        visited[x][y] = false;
        return ans;
    }

    bool not_safe(int x, int y, vector<vector<int>>& heights, vector<vector<bool>>& visited) {
        return x < 0 || x >= heights.size() || y < 0 || y >= heights[0].size() || visited[x][y] == true;
    }
};