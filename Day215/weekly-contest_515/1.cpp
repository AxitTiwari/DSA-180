// https://leetcode.com/contest/weekly-contest-515/problems/nearest-available-drone/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int nearestDrone(vector<vector<int>>& drones, vector<int>& target) {

        int res = -1, idx = 0;
        int m_dist = INT_MAX;
        for (auto drone : drones) {

            int x = drone[0], y = drone[1], r = drone[2];
            int dist = abs(x - target[0]) + abs(y - target[1]);

            if (r >= dist && dist < m_dist) {
                res = idx;
                m_dist = dist;
            }
            idx++;
        }
        return res;
    }
};