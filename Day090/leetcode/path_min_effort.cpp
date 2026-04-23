#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        
        int n = heights.size();
        int m = heights[0].size();

        // initialise distance array with infinity
        vector<vector<int>> dist(n, vector<int> (m, 1e9));

        // min-heap (priority, {x, y})
        priority_queue <
            pair<int, pair<int, int>>,
            vector<pair<int, pair<int, int>>>,
            greater<pair<int, pair<int, int>>>
        > pq;

        // push source pos into pq
        pq.push({0, {0, 0}});
        dist[0][0] = 0;

        // all neighbours
        vector<vector<int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        // loop until get minimum effort
        while (!pq.empty()) {

            // visit the node
            auto it = pq.top();
            pq.pop();

            // extract data
            int w = it.first;
            int x = it.second.first;
            int y = it.second.second;

            if (x == n-1 && y == m-1) return dist[x][y];

            // check all neighbours
            for (auto d : dir) {

                int nx = x + d[0];
                int ny = y + d[1];

                // valid cell
                if (
                    nx >= 0 && nx < n &&
                    ny >= 0 && ny < m
                ) {

                    // edge weight
                    int diff_h = abs(heights[x][y] - heights[nx][ny]);

                    // found a shorter path
                    if (dist[nx][ny] > max(diff_h, w)) {

                        dist[nx][ny] = max(diff_h, w);
                        pq.push({dist[nx][ny], {nx, ny}});
                    }
                }
            }
        }
        return -1;
    }
};
