// https://leetcode.com/problems/edit-distance/submissions/1971165321

#include <bits/stdc++.h>    
using namespace std;

class Solution {
private:
    int f(string& word1, string& word2, int i, int j) {
        
        if (i >= word1.length() && j >= word2.length()) {
            return 0;
        }

        if (i == word1.length() && j != word2.length()) {
            return word2.length() - j;
        }

        if (i != word1.length() && j == word2.length()) {
            return word1.length() - i;
        }

        if (word1[i] == word2[j]) {
            return f(word1, word2, i+1, j+1);
        }
        else {

            return 1 + min(
                f(word1, word2, i, j+1),
                min(f(word1, word2, i+1, j), f(word1, word2, i+1, j+1))
            );
        }
    }

    int mem(string& word1, string& word2, int i, int j, vector<vector<int>>& dp) {
        
        if (i >= word1.length() && j >= word2.length()) {
            return 0;
        }

        if (i == word1.length() && j != word2.length()) {
            return word2.length() - j;
        }

        if (i != word1.length() && j == word2.length()) {
            return word1.length() - i;
        }

        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        if (word1[i] == word2[j]) {
            return dp[i][j] = mem(word1, word2, i+1, j+1, dp);
        }
        else {

            return dp[i][j] = 1 + min(
                mem(word1, word2, i, j+1, dp),
                min(mem(word1, word2, i+1, j, dp), mem(word1, word2, i+1, j+1, dp))
            );
        }
    }

public:
    int minDistance(string word1, string word2) {

        // return f(word1, word2, 0, 0);

        vector<vector<int>> dp(word1.length(), vector<int> (word2.length(), -1));
        return mem(word1, word2, 0, 0, dp);
    }
};