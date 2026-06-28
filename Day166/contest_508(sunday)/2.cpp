#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> filterOccupiedIntervals(vector<vector<int>>& occupiedIntervals, int freeStart, int freeEnd) {

        sort(occupiedIntervals.begin(), occupiedIntervals.end());

        // merge intervals
        vector<vector<int>> res;

        vector<int> prevInterval = {occupiedIntervals[0][0], occupiedIntervals[0][1]};
        for (int i = 1; i < occupiedIntervals.size(); i++) {

            auto &interval = occupiedIntervals[i];

            if (interval[0] <= prevInterval[1] + 1) {
                prevInterval[1] = max(prevInterval[1], interval[1]);
            }
            else {
                res.push_back(prevInterval);
                prevInterval = interval;
            }
        }

        res.push_back(prevInterval);

        vector<vector<int>> ans;
        for (int i = 0; i < res.size(); i++) {

            auto &interval = res[i];

            int l = interval[0];
            int r = interval[1];

            if (r < freeStart || l > freeEnd) {
                ans.push_back(interval);
                continue;
            }

            if (l < freeStart) {
                ans.push_back({l, freeStart-1});
            }

            if (r > freeEnd) {
                ans.push_back({freeEnd+1, r});
            }
        }
        return ans;
    }
};