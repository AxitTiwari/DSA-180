// https://leetcode.com/problems/non-overlapping-intervals/submissions/2047592853

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {

        sort(intervals.begin(), intervals.end());
        
        int prevEnd = intervals[0][1];

        int cnt = 0;
        for (int i = 1; i < intervals.size(); i++) {

            auto &interval = intervals[i];
            int start = interval[0];
            int end = interval[1];

            if (start >= prevEnd) {
                prevEnd = end;
            }
            else {
                prevEnd = min(end, prevEnd);
                cnt++;
            }
        }
        return cnt;
    }
};