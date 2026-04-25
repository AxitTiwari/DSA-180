// https://leetcode.com/submissions/detail/1987790931/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool validDigit(int n, int x) {

        bool can_valid = false;
        while (n) {

            if (n >= 0 && n <= 9 && n == x) return false;

            int digit = n % 10;

            if (digit == x) {
                can_valid = true;
            }

            n = n / 10;
        }

        if (can_valid) return true;
        return false;
    }
};