#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minRotations(int n, string s) {

        auto dist = [](int a, int b) {
            int diff = abs(a - b);
            return min(diff, 10-diff);
        };

        // original cost
        int base_cost = 0, prev = 0;
        for (char ch : s) {
            int digit = ch - '0';
            base_cost += dist(prev, digit);
            prev = digit;
        }

        // 1 -> 5 -> 0 -> 2 : 1 -> 2 -> 0 -> 5 :: {0 -> 2 unchanged}

        int ans = base_cost;
        int last = s[n-1] - '0';
        for (int k = 0; k < n; k++) {

            int prev_digit = k == 0 ? 0 : s[k-1] - '0';
            int cur_digit = s[k] - '0';

            // 11 - 5 = 6
            int new_cost = base_cost - dist(prev_digit, cur_digit) + dist(prev_digit, last);
            ans = min(ans, new_cost);
        }
        return ans;

    }
};