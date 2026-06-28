// https://leetcode.com/problems/reverse-integer/submissions/2049176518

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        int ans = 0;
        while (x != 0) {

            int digit = x % 10;

            if (ans  > ((long long)INT_MAX - digit) / 10 || ans  < ((long long)INT_MIN - digit) / 10) return 0;

            ans = ans * 10 + digit;
            x = x / 10;
        }
        return ans;
    }
};