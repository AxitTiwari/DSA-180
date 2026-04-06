// https://leetcode.com/problems/triangle/submissions/1970545687

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int f(vector<vector<int>>& triangle, int i, int j) {

        // on last row
        if (i == triangle.size()-1) {
            return triangle[i][j];
        }

        int move1 = f(triangle, i+1, j);
        int move2 = f(triangle, i+1, j+1);

        return triangle[i][j] + min(move1, move2);
    }

    int memoization(vector<vector<int>>& triangle, int i, int j, vector<vector<int>>& dp) {

        // on last row
        if (i == triangle.size()-1) {
            return triangle[i][j];
        }

        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        int move1 = memoization(triangle, i+1, j, dp);
        int move2 = memoization(triangle, i+1, j+1, dp);

        return dp[i][j] = triangle[i][j] + min(move1, move2);
    }

    int tabulation(vector<vector<int>>& triangle) {

        int m = triangle.size();

        vector<vector<int>> dp(m);
        for (int i = 0; i < m; i++) {
            dp[i] = vector<int>(triangle[i].size(), -1);
        }

        // base case
        for (int i = 0; i < triangle[m-1].size(); i++) {
            dp[m-1][i] = triangle[m-1][i];
        }

        for (int i = m-2; i >= 0; i--) {
            for (int j = 0; j < triangle[i].size(); j++) {

                int move1 = dp[i+1][j];
                int move2 = dp[i+1][j+1];

                dp[i][j] = triangle[i][j] + min(move1, move2);
            }
        }
        return dp[0][0];
    }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        
        // return f(triangle, 0, 0);

        int m = triangle.size();

        vector<vector<int>> dp(m);
        for (int i = 0; i < m; i++) {
            dp[i] = vector<int>(triangle[i].size(), -1);
        }

        // return memoization(triangle, 0, 0, dp);

        return tabulation(triangle);
    }
};