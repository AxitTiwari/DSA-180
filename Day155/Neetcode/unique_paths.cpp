// https://leetcode.com/problems/unique-paths/submissions/2036512218

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        
        vector<vector<int>> dp(m, vector<int> (n, -1));
        return func(0, 0, m, n, dp);
    }
private:
    int func(int x, int y, int m, int n, vector<vector<int>> &dp) {

        if (x >= m || y >= n) return 0;

        if (x == m-1 && y == n-1) return 1;

        if (dp[x][y] != -1) return dp[x][y];

        int right = func(x, y+1, m, n, dp);
        int down = func(x+1, y, m, n, dp);

        return dp[x][y] = right + down;
    }
};