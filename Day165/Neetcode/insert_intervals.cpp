// https://leetcode.com/problems/insert-interval/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        
        vector<vector<int>> res;

        for (int i = 0; i < intervals.size(); i++) {
            auto interval = intervals[i];

            // push newInterval and remaing intervals
            if (newInterval[1] < interval[0]) {
                res.push_back(newInterval);

                // Add all remaining intervals
                res.insert(res.end(), intervals.begin() + i, intervals.end());

                return res;
            } // push interval
            else if (newInterval[0] > interval[1]) {
                res.push_back(interval);
            }
            else { // overlapping case
                newInterval = {min(newInterval[0], interval[0]), max(newInterval[1], interval[1])};
            }
        }

        res.push_back(newInterval);
        return res;
    }
};
