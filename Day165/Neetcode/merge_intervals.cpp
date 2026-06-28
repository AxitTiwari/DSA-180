// https://leetcode.com/problems/merge-intervals/submissions/2047547612

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        sort(intervals.begin(), intervals.end());
        
        vector<int> newInterval = {intervals[0][0], intervals[0][1]};

        vector<vector<int>> res;
        for (int i = 1; i < intervals.size(); i++) {

            auto &interval = intervals[i];

            if (newInterval[0] > interval[1]) {
                res.push_back(interval);
            }
            else if (newInterval[1] < interval[0]) {
                res.push_back(newInterval);
                newInterval = interval;
            }
            else {
                newInterval = {min(newInterval[0], interval[0]), max(newInterval[1], interval[1])};
            }
        }
        res.push_back(newInterval);
        return res;
    }
};