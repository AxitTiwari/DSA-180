
// https://leetcode.com/problems/count-islands-with-total-value-divisible-by-k/submissions/2182116782

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        
        int res = 0;
        vector<vector<int>> visited(
            grid.size(),
            vector<int> (grid[0].size(), 0)
        );

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {

                if (visited[i][j] == 1 || grid[i][j] == 0) continue;

                if (divisible_by_k(i, j, grid, visited) % k == 0) res++;
            }
        }
        return res;
    }
private:
    long long divisible_by_k(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& visited) {

        visited[i][j] = 1;

        vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
        long long res = grid[i][j];
        for (auto dir : dirs) {

            int new_i = i + dir.first, new_j = j + dir.second;

            if (new_i < 0 || new_i >= grid.size() || new_j < 0 || new_j >= grid[0].size() || visited[new_i][new_j] != 0 || grid[new_i][new_j] == 0) continue;

            res += 1LL * divisible_by_k(new_i, new_j, grid, visited);
        }
        return res;
    }
};