// https://leetcode.com/problems/k-closest-points-to-origin/submissions/2026324339

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
        priority_queue<pair<int, pair<int, int>>> pq;
        for (auto point : points) {

            int x = point[0];
            int y = point[1];

            int dist = (x * x) + (y * y);
            if (pq.size() < k) {
                pq.push({dist, {x, y}});
            }
            else {
                if (pq.top().first > dist) {
                    pq.pop();
                    pq.push({dist, {x, y}});
                }
            }
        }

        vector<vector<int>> ans;
        while (!pq.empty()) {

            auto data = pq.top();
            pq.pop();

            int x = data.second.first;
            int y = data.second.second;

            ans.push_back({x, y});
        }
        return ans;
    }
};