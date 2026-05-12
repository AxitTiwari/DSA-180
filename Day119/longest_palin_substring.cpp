// https://leetcode.com/problems/longest-palindromic-substring/submissions/2001476544

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:

    bool is_palindrome(int i, int j, string &s) {

        while (i <= j) {
            if (s[i] != s[j]) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }

    string f(int i, int j, string &s, vector<vector<string>> &dp) {

        if (i > j) return "";

        if (i == j) return string(1, s[i]);

        if (dp[i][j] != "-") return dp[i][j];

        if (is_palindrome(i, j, s)) {
            return dp[i][j] = s.substr(i, j - i + 1);
        }
        else {

            string s1 = f(i+1, j, s, dp);
            string s2 = f(i, j-1, s, dp);

            return dp[i][j] = s1.length() > s2.length() ? s1 : s2;
        }
    }

    string space_optimised(string &s) {

        int n = s.length();
        vector<vector<bool>> dp(n, vector<bool> (n, false));

        int start = 0;
        int max_len = 1;

        for (int i = 0; i < n; i++) {
            dp[i][i] = true;
        }

        for (int i = 0; i < n-1; i++) {

            if (s[i] == s[i+1]) {
                dp[i][i+1] = true;
                start = i;
                max_len = 2;
            }
        }

        for (int len = 3; len <= n; len++) {
            for (int i = 0; i <= n - len; i++) {

                int j = i + len - 1;

                if (s[i] == s[j] && dp[i + 1][j - 1]) {

                    dp[i][j] = true;

                    start = i;
                    max_len = len;
                }
            }
        }
        return s.substr(start, max_len);
    }

public:
    string longestPalindrome(string s) {

        // vector<vector<string>> dp(s.length(), vector<string> (s.length(), "-"));
        // string longest_substr = f(0, s.length()-1, s, dp);
        // return longest_substr;

        return space_optimised(s);
    }
};