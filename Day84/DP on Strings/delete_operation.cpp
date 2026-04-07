// https://leetcode.com/problems/delete-operation-for-two-strings/submissions/1971123551

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int f(string& word1, string& word2, int i, int j) {

        // Base Case
        if (i >= word1.length() && j >= word2.length()) {
            return 0;
        }

        // one string is over: delete remaing chars from other one
        if (i == word1.length() && j != word2.length()) {
            return word2.length() - j;
        }

        if (i != word1.length() && j == word2.length()) {
            return word1.length() - i;
        }

        // Body
        if (word1[i] == word2[j]) {
            return f(word1, word2, i+1, j+1);
        }
        else {

            // deleting one element
            return 1 + min(
                f(word1, word2, i+1, j),
                f(word1, word2, i, j+1)
            );
        }
    }

    int mem(string& word1, string& word2, int i, int j, vector<vector<int>>& dp) {

        // Base Case
        if (i >= word1.length() && j >= word2.length()) {
            return 0;
        }

        // one string is over: delete remaing chars from other one
        if (i == word1.length() && j != word2.length()) {
            return word2.length() - j;
        }

        if (i != word1.length() && j == word2.length()) {
            return word1.length() - i;
        }

        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        // Body
        if (word1[i] == word2[j]) {
            return dp[i][j] = mem(word1, word2, i+1, j+1, dp);
        }
        else {

            // deleting one element
            return dp[i][j] = 1 + min(
                mem(word1, word2, i+1, j, dp),
                mem(word1, word2, i, j+1, dp)
            );
        }
    }
public:
    int minDistance(string word1, string word2) {
        
        // return f(word1, word2, 0, 0);

        vector<vector<int>> dp(word1.length()+1, vector<int> (word2.length()+1, -1));
        return mem(word1, word2, 0, 0, dp);
    }
};