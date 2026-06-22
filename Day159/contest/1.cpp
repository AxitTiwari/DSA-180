// https://leetcode.com/contest/weekly-contest-507/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDistance(string moves) {

        int l = 0, r = 0, d = 0, u = 0;
        int cnt = 0;
        for (char move : moves) {

            if (move == 'L') l++;

            if (move == 'R') r++;

            if (move == 'U') u++;

            if (move == 'D') d++;

            if (move == '_') cnt++;
        }

        return abs(l - r) + abs(u - d) + cnt;
    }
};