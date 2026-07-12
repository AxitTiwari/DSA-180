// https://leetcode.com/contest/weekly-contest-510/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int secondsBetweenTimes(string startTime, string endTime) {

        stringstream ss1(startTime);
        string temp;
        vector<int> sec1;

        while (getline(ss1, temp, ':')) {
            sec1.push_back(stoi(temp));
        }

        stringstream ss2(endTime);
        vector<int> sec2;

        while (getline(ss2, temp, ':')) {
            sec2.push_back(stoi(temp));
        }

        int h1 = sec1[0], m1 = sec1[1], s1 = sec1[2];
        int h2 = sec2[0], m2 = sec2[1], s2 = sec2[2];

        int total_time1 = h1 * 3600 + m1 * 60 + s1;
        int total_time2 = h2 * 3600 + m2 * 60 + s2;

        return total_time2 - total_time1;
    }
};