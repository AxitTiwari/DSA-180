// https://leetcode.com/problems/path-with-minimum-effort/submissions/2078192273

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {

        int r = heights.size(), c = heights[0].size();
        
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
        pq.push({0, 0, 0});

        vector<vector<int>> dist(r, vector<int> (c, INT_MAX));

        while (!pq.empty()) {

            auto [effort, x, y] = pq.top();
            pq.pop();

            if (x == r-1 and y == c-1) return effort;

            vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
            for (auto &dir : dirs) {

                int new_x = x + dir.first;
                int new_y = y + dir.second;

                if (new_x < 0 || new_y < 0 || new_x >= r || new_y >= c) continue;

                int new_effort = max(effort, abs(heights[new_x][new_y] - heights[x][y]));

                if (dist[new_x][new_y] > new_effort) {
                    pq.push({new_effort, new_x, new_y});
                    dist[new_x][new_y] = new_effort;
                }
            }
        }
        return -1;
    }
};