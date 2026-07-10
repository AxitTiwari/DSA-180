// https://leetcode.com/problems/merge-intervals/submissions/2061314728

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        sort(intervals.begin(), intervals.end());

        vector<vector<int>> res;
        
        int n = intervals.size();

        vector<int> prev = intervals[0];
        for (auto &interval : intervals) {

            if (interval[0] > prev[1]) {
                res.push_back(prev);
                prev = interval;
            }
            else {
                prev = {min(prev[0], interval[0]), max(prev[1], interval[1])};
            }
        }
        res.push_back(prev);
        return res;
    }
};