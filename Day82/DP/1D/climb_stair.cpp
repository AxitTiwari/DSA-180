// https://leetcode.com/problems/climbing-stairs/

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int f(int n) {

        if (n == 0) {
            return 1;
        }

        if (n < 0) {
            return 0;
        }

        int one_step = f(n-1);
        int two_step = f(n-2);

        return one_step + two_step;
    }

    int memoization(int n, vector<int>& dp) {

        if (n == 0) {
            return 1;
        }

        if (n < 0) {
            return 0;
        }

        if (dp[n] != -1) {
            return dp[n];
        }

        int one_step = memoization(n-1, dp);
        int two_step = memoization(n-2, dp);

        return dp[n] = one_step + two_step;
    }

    int tabulation(int n) {

        vector<int> dp(n+1, 0);

        dp[0] = 1;

        for (int i = 1; i <= n; i++) {

            int one_step = dp[i-1];

            int two_step = 0;
            if (i-2 >= 0)
                two_step = dp[i-2];

            dp[i] = one_step + two_step;
        }
        return dp[n];
    }

    int space_optimisation(int n) {

        int prev2 = 1;
        int prev1 = 1;

        for (int i = 2; i <= n; i++) {

            int curr = prev1 + prev2;

            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
public:
    int climbStairs(int n) {

        if (n == 0) return 1;
        
        // return f(n);

        vector<int> dp(n+1, -1);
        // return memoization(n, dp);

        // return tabulation(n);

        return space_optimisation(n);
    }
};