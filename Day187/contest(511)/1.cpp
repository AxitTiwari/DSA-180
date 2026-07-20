// https://leetcode.com/contest/weekly-contest-511/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canReach(vector<int>& start, vector<int>& target) {

        vector<vector<vector<bool>>> visited(
            8,
            vector<vector<bool>> (8, vector<bool> (2, false))
        );

        queue<tuple<int, int, int>> q;
        q.push({start[0], start[1], 0});

        while (!q.empty()) {

            auto [x, y, moves] = q.front();
            q.pop();

            if (x == target[0] and y == target[1] and moves % 2 == 0) return true;

            vector<pair<int, int>> dirs = {{1, 2}, {-1, 2}, {-2, 1}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}};
            for (auto dir : dirs) {
                int new_x = x + dir.first;
                int new_y = y + dir.second;

                if (not_safe(new_x, new_y)) continue;

                bool parity = (moves + 1) % 2;
    
                if (!visited[new_x][new_y][parity]) {
                    visited[new_x][new_y][parity] = true;
                    q.push({new_x, new_y, moves+1});
                }
            } 
        }
        return false;
    }
private:

    bool not_safe(int x, int y) {
        return x < 0 || x >= 8 || y < 0 || y >= 8;
    }
};