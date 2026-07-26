#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestInteger(int n, int s) {

        // exceeding the limit
        if (s > 9 * n) return -1;

        if (s == 0) return 0;

        int ans = 0;
        for (int i = 0; i < n; i++) {

            int digit = min(9, s);
            ans = ans * 10 + digit;
            s -= digit;
        }
        return ans;
    }
};