// https://neetcode.io/problems/meeting-schedule/history?list=neetcode150&submissionIndex=1

#include <bits/stdc++.h>
using namespace std;
class Interval {
public:
    int start, end;
    Interval(int start, int end) {
        this->start = start;
        this->end = end;
    }
};

class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        
        sort(intervals.begin(), intervals.end(), [](Interval &a, Interval &b) {
            return a.start < b.start;
        });

        int end = intervals[0].end;
        for (int i = 1; i < intervals.size(); i++) {

            if (end <= intervals[i].start) {
                end = intervals[i].end;
            }
            else {
                return false;
            }
        }
        return true;
    }
};
