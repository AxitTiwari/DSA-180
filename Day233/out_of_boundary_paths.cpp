// https://leetcode.com/submissions/detail/2129203165/

#include <bits/stdc++.h>
using namespace std;

int MOD = 1e9 + 7;

class Solution {
    int dp[51][51][51];

public:

    Solution() {
        memset(dp, -1, sizeof(dp));
    }

    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        
        if (maxMove < 0) return 0;

        // cout << startRow << " " << startColumn << endl;

        if (startRow < 0 || startRow >= m ||startColumn < 0 || startColumn >= n) return 1;

        if (dp[maxMove][startRow][startColumn] != -1) return dp[maxMove][startRow][startColumn];

        return dp[maxMove][startRow][startColumn] =
            (
                (1LL) * (findPaths(m, n, maxMove-1, startRow-1, startColumn) % MOD) +
                (1LL) * (findPaths(m, n, maxMove-1, startRow+1, startColumn) % MOD) +
                (1LL) * (findPaths(m, n, maxMove-1, startRow, startColumn-1) % MOD) +
                (1LL) * (findPaths(m, n, maxMove-1, startRow, startColumn+1) % MOD)
        ) % MOD;
    }
};