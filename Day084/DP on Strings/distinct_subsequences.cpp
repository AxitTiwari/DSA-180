// https://leetcode.com/problems/distinct-subsequences/submissions/1971139665

#include <bits/stdc++.h>
using namespace std;

// Memory Limit Exceeded <- work on this
class Solution {
private:
    int f(string& s, string& t, int i, string sub) {

        // one subsequece generated
        if (i == s.size()) {
            return sub == t ? 1 : 0;
        }

        int include = f(s, t, i+1, sub+s[i]);
        int exclude = f(s, t, i+1, sub);

        return include + exclude;
    }

    int memoization(string& s, string& t, int i, string sub, 
        map<pair<int, string>, int>& dp
    ) {

        // one subsequece generated
        if (i == s.size()) {
            return sub == t ? 1 : 0;
        }

        pair<int, string> key = {i, sub};
        if (dp.find(key) != dp.end()) {
            return dp[key];
        }

        int include = memoization(s, t, i+1, sub+s[i], dp);
        int exclude = memoization(s, t, i+1, sub, dp);

        return dp[key] = include + exclude;
    }
public:
    int numDistinct(string s, string t) {
        
        // Logic:
        // 1. find all subsequences.
        // 2. compaire them with t and return output

        string subsequence = "";
        // return f(s, t, 0, subsequence);

        map<pair<int, string>, int> dp;
        return memoization(s, t, 0, subsequence, dp);
    }
};