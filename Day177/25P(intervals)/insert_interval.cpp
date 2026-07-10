// https://leetcode.com/problems/insert-interval/submissions/2061349233

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {

        vector<vector<int>> res;
        
        int n = intervals.size();

        for (int i = 0; i < n; i++) {

            auto &interval = intervals[i];

            if (interval[1] < newInterval[0]) {
                res.push_back(interval);
            }
            else if (interval[0] > newInterval[1]) {
                res.push_back(newInterval);
                res.insert(res.end(), intervals.begin()+i, intervals.end());
                return res;
            }
            else {
                newInterval = {min(newInterval[0], interval[0]), max(newInterval[1], interval[1])};
            }
        }
        res.push_back(newInterval);
        return res;
    }
};