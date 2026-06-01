// https://leetcode.com/problems/word-break/submissions/2017849889

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    unordered_map<string, bool> dp;
    bool func(string &ans, string &s, vector<string>& wordDict) {

        // cout << ans << endl;

        if (ans == s) return true;

        if (dp.count(ans)) {
            return dp[ans];
        }

        if (ans.length() > s.length()) return false;

        for (int i = 0; i < wordDict.size(); i++) {

            ans =  ans + wordDict[i];

            if (s.compare(0, ans.size(), ans) == 0) {
                if (func(ans, s, wordDict)) {
                    ans.erase(ans.size() - wordDict[i].size());
                    return dp[ans] = true;
                }
            }
            ans.erase(ans.size() - wordDict[i].size());
        }
        return dp[ans] = false;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        
        string ans;
        return func(ans, s, wordDict);
    }
};