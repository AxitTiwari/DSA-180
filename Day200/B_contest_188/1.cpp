// https://leetcode.com/contest/biweekly-contest-188/problems/count-valid-prefixes/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countValidPrefixes(string s) {

        int res = 0;
        
        int zero_count = 0, one_count = 0;
        for (char ch : s) {
            if (ch == '0') zero_count++;
            else           one_count++;

            if (abs(zero_count - one_count) <= 1) res++;
        }

        return res;
    }
};