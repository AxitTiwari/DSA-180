// https://leetcode.com/problems/generate-parentheses/submissions/2015244756

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    void f(string &p, int count_left, int count_right, int pair_count, vector<string> &ans) {

        if (count_left + count_right == 2 * pair_count) {
            ans.push_back(p);
            return;
        }

        if (count_left < pair_count) {
            p = p + '(';
            f(p, count_left+1, count_right, pair_count, ans);
            p.pop_back();
        }
        if (count_right < count_left) {
            p = p + ')';
            f(p, count_left, count_right+1, pair_count, ans);
            p.pop_back();
        }
    }

    void mem(string &p, int count_left, int count_right, int pair_count, vector<string> &ans, 
        vector<vector<string>> &dp
    ) {

        if (count_left + count_right == 2 * pair_count) {
            ans.push_back(p);
            dp[count_left][count_right] = p;
            return;
        }

        if (dp[count_left][count_right] != "-") {
            ans.push_back(dp[count_left][count_right]);
            return;
        }

        if (count_left < pair_count) {
            p = p + '(';
            mem(p, count_left+1, count_right, pair_count, ans, dp);
            p.pop_back();
        }
        if (count_right < count_left) {
            p = p + ')';
            mem(p, count_left, count_right+1, pair_count, ans, dp);
            p.pop_back();
        }
    }

public:
    vector<string> generateParenthesis(int n) {
        
        vector<string> ans;
        string parentheses = "";

        // f(parentheses, 0, 0, n, ans);
        // return ans;

        vector<vector<string>> dp(n+1, vector<string>(n+1, "-"));
        mem(parentheses, 0, 0, n, ans, dp);
        return ans;
    }
};