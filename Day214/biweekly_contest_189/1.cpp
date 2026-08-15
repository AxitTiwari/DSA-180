// https://leetcode.com/contest/biweekly-contest-189/problems/elevator-requests-i/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int elevatorRequests(int n, vector<int>& requests) {

        int total_t = 0;
        int cur_floor = 0;
        for (int req : requests) {

            int t = abs(cur_floor - req);
            cur_floor = req;

            total_t += t;
        }
        return total_t;
    }
};