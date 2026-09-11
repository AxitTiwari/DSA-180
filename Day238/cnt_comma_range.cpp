// https://leetcode.com/submissions/detail/2135280649/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countCommas(int n) {

        int temp = n;
        int digit = 0;
        while (temp > 0) {
            temp = temp / 10;
            digit++;
        }

        if (digit > 3) {
            return n - 999;
        }
        return 0;
    }
};