// https://leetcode.com/problems/find-the-safest-path-in-a-grid/?envType=daily-question&envId=2026-07-01

#include <bits/stdc++.h>
using namespace std;

// optise this, this is bad approach
class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {

        if (grid[0][0] == 1) return 0;
        
        vector<pair<int, int>> thiefs;
        store_thiefs(grid, thiefs);

        return backtrack(0, 0, grid, thiefs);
    }
private:

    // **imp
    int backtrack(int r, int c, vector<vector<int>>& grid, vector<pair<int, int>> &thiefs) {

        if (r == grid.size()-1 && c == grid.size()-1) {
            return dis(r, c, thiefs);
        }

        int original_value = grid[r][c];
        grid[r][c] = -1;

        int cur = dis(r, c, thiefs);

        int ans = INT_MIN;

        vector<pair<int, int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        for (auto &[i, j] : dir) {
            int new_r = r + i;
            int new_c = c + j;

            if (not_safe(new_r, new_c, grid)) continue;

            // super important (just think about this line, how it is working) <<== super simple also
            ans = max(ans, min(cur, backtrack(new_r, new_c, grid, thiefs))); 
        }

        grid[r][c] = original_value;
        return ans;
    }

    int dis(int x, int y, vector<pair<int, int>> &thiefs) {

        if (thiefs.size() == 0) return 0;

        int ans = INT_MAX;
        for (auto &[r, c] : thiefs) {
            int d = abs(r - x) + abs(c - y);
            ans = min(ans, d);
        }
        return ans;
    }

    bool not_safe(int x, int y, vector<vector<int>>& grid) {

        return x < 0 || x >= grid.size() || y < 0 || y >= grid.size() || grid[x][y] == -1;
    }

    void store_thiefs(vector<vector<int>>& grid, vector<pair<int, int>> &thiefs) {

        int n = grid.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {

                if (grid[i][j] == 1) {
                    thiefs.push_back({i, j});
                }
            }
        }
    }
};