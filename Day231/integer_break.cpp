// https://leetcode.com/submissions/detail/2126834838/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int integerBreak(int n) {
        
        vector<int> integers;
        for (int i = 1; i < n; i++) {
            integers.push_back(i);
        }

        vector<int> dp(n+1, -1);
        return f(n, integers, dp);
    }
private:
    int f(int n, vector<int>& integers, vector<int>& dp) {

        if (n == 0) return 1;

        if (dp[n] != -1) return dp[n];

        int ans = INT_MIN;
        for (int i : integers) {

            if (i > n) continue;

            ans = max(f(n-i, integers, dp)*i, ans);
        }
        return dp[n] = ans;
    }
};