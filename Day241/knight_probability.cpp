// https://leetcode.com/problems/knight-probability-in-chessboard/submissions/2138332864

#include <bits/stdc++.h>
using namespace std;

int dx[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dy[8] = {-1, 1, -2, 2, -2, 2, -1, 1};

class Solution {
public:
    double knightProbability(int n, int k, int row, int column) {
        
        vector<vector<vector<int>>> dp(
            k+1,
            vector<vector<int>>(
                n+1,
                vector<int>(n, -1)
            )
        );
        return solve(n, k, row, column, dp);
    }
private:
    double solve(int n, int k, int r, int c, vector<vector<vector<int>>>& dp) {

        if (r < 0 || r >= n || c < 0 || c >= n) return 0.0;

        if (k == 0) return 1.0;

        if (dp[k][r][c] != -1) return dp[k][r][c];

        double res = 0.0;
        for (int i = 0; i < 8; i++) {
            res += solve(n, k-1, r+dx[i], c+dy[i], dp) / 8.0;
            // cout << res << endl;
        }
        
        return dp[k][r][c] = res;
    }

};