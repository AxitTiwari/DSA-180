// https://leetcode.com/problems/longest-palindromic-subsequence/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
private:
    int f(string& s, string& rev_s, int i, int j) {

        if (i >= s.length() || j >= rev_s.length()) {
            return 0;
        }

        // case 1: 
        if (s[i] == rev_s[j]) {
            return 1 + f(s, rev_s, i+1, j+1);
        } 
        else { // case 2

            // two choices:
            int include = f(s, rev_s, i+1, j);
            int exclude = f(s, rev_s, i, j+1);

            return max(include, exclude);
        }
    }

    int memoization(string& s, string& rev_s, int i, int j, vector<vector<int>> &dp) {

        if (i >= s.length() || j >= rev_s.length()) {
            return 0;
        }

        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        // case 1: 
        if (s[i] == rev_s[j]) {
            return dp[i][j] = 1 + memoization(s, rev_s, i+1, j+1, dp);
        } 
        else { // case 2

            // two choices:
            int include = memoization(s, rev_s, i+1, j, dp);
            int exclude = memoization(s, rev_s, i, j+1, dp);

            return dp[i][j] = max(include, exclude);
        }
    }
public:
    int longestPalindromeSubseq(string s) {
        
        // 1. reverse the string
        string rev_s = s;
        reverse(rev_s.begin(), rev_s.end());

        // 2. find LCS (s, rev_s)
        // return f(s, rev_s, 0, 0);

        vector<vector<int>> dp(s.length()+1, vector<int> (s.length()+1, -1));
        return memoization(s, rev_s, 0, 0, dp);
    }
};
