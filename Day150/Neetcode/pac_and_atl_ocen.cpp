// https://leetcode.com/problems/pacific-atlantic-water-flow/submissions/2030382557

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {

        // instead of checking for all nodes, check how many are reacable from pac and atl then find intersection of both
        
        int ROWS = heights.size(), COLS = heights[0].size();
        
        vector<vector<bool>> pac(ROWS, vector<bool> (COLS, false));
        vector<vector<bool>> atl(ROWS, vector<bool> (COLS, false));

        for (int c = 0; c < COLS; c++) {
            dfs(0, c, INT_MIN, pac, heights);
            dfs(ROWS-1, c, INT_MIN, atl, heights);
        }

        for (int r = 0; r < ROWS; r++) {
            dfs(r, 0, INT_MIN, pac, heights);
            dfs(r, COLS-1, INT_MIN, atl, heights);
        }

        vector<vector<int>> res;
        for (int r = 0; r < ROWS; r++) {
            for (int c = 0; c < COLS; c++) {

                if (pac[r][c] && atl[r][c]) {
                    res.push_back({r, c});
                }
            }
        }
        return res;
    }

private:
    void dfs(int x, int y, int height, vector<vector<bool>> &ocen, vector<vector<int>>& heights) {

        if (x < 0 || x >= heights.size() || y < 0 || y >= heights[0].size() || ocen[x][y] || heights[x][y] < height) return;

        ocen[x][y] = true;

        dfs(x+1, y, heights[x][y], ocen, heights);
        dfs(x, y+1, heights[x][y], ocen, heights);
        dfs(x-1, y, heights[x][y], ocen, heights);
        dfs(x, y-1, heights[x][y], ocen, heights);
    }

};