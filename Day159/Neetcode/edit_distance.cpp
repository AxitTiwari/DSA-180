// https://leetcode.com/problems/edit-distance/submissions/2040593780

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        
        vector<vector<int>> dp(word1.length(), vector<int> (word2.length(), -1));
        return func(0, 0, word1, word2, dp);
    }
private:
    int func(int i, int j, string &word1, string &word2, vector<vector<int>> &dp) {

        if (i == word1.length() && j == word2.length()) return 0;

        if (i == word1.length()) return word2.length() - j;

        if (j == word2.length()) return word1.length() - i;

        if (dp[i][j] != -1) return dp[i][j];

        int ans;
        if (word1[i] == word2[j]) ans = func(i+1, j+1, word1, word2, dp);
        else {

            int insert  = 1 + func(i, j+1, word1, word2, dp);
            int del     = 1 + func(i+1, j, word1, word2, dp);
            int replace = 1 + func(i+1, j+1, word1, word2, dp);

            ans = min(insert, min(del, replace));
        }
        return dp[i][j] = ans;
    }
};
