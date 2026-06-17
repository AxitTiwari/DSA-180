// https://leetcode.com/problems/word-break/submissions/2036094394

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        
        string ans = "";
        vector <int> dp(s.length(), -1);
        return func(0, s, wordDict, dp);
    }
private:
    bool func(int start_idx, string &s, vector<string> &wordDict, vector <int> &dp) {

        if (start_idx >= s.length()) return true;

        if (dp[start_idx] != -1) return dp[start_idx];

        for (int i = 0; i < wordDict.size(); i++) {

            if (s.compare(start_idx, wordDict[i].length(), wordDict[i]) == 0) {

                if (func(start_idx+wordDict[i].length(), s, wordDict, dp)) {
                    return dp[start_idx] = true;
                }
            }
        }
        return dp[start_idx] = false;
    }
};