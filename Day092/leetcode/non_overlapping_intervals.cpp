// https://leetcode.com/problems/non-overlapping-intervals/submissions/1979297242

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // inverse of N meetings in a room
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b) {
            return a[1] < b[1];
        });

        int count = 0;

        int last_end_time = intervals[0][1];
        for (int i = 1; i < intervals.size(); i++) {

            if (intervals[i][0] >= last_end_time) {
                count += 1;
                last_end_time = intervals[i][1];
            }
        }
        return intervals.size() - count - 1;
    }
};