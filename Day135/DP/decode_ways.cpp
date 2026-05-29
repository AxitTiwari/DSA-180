// https://leetcode.com/submissions/detail/2015597392/

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int f(int i, int which_step, string &s) {

        if ((which_step == 1 && i == s.length() + 1) || (which_step == 2 && i == s.length() + 2)) {
            return 1;
        }

        if (i > s.length()) return 0;

        if (which_step == 1 && i-1 >= 0 && s[i-1] == '0') {
            return 0;
        }

        if (which_step == 2 && i-2 >= 0 && i-2 < s.length()) {

            char tens_digit = s[i-2];
            char first_digit = s[i-1];

            if (tens_digit > '2' || tens_digit == '0') return 0;

            if (tens_digit == '2' && first_digit >= '7') return 0;
        }

        int one_step = f(i+1, 1, s);

        int two_steps = 0;
        if (i + 2 <= s.length()) {
            two_steps = f(i+2, 2, s);
        }

        return one_step + two_steps;
    }

    int mem(int i, int which_step, string &s, vector<vector<int>> &dp) {

        if ((which_step == 1 && i == s.length() + 1) || (which_step == 2 && i == s.length() + 2)) {

            cout << "step: " << which_step << " : " << i << endl;
            return 1;
        }

        if (which_step == 1 && i-1 >= 0 && s[i-1] == '0') {
            return 0;
        }

        if (which_step == 2 && i-2 >= 0 && i-2 < s.length()) {

            char tens_digit = s[i-2];
            char first_digit = s[i-1];

            if (tens_digit > '2' || tens_digit == '0') return 0;

            if (tens_digit == '2' && first_digit >= '7') return 0;
        }

        if (dp[i][which_step] != -1) return dp[i][which_step];

        int one_step = mem(i+1, 1, s, dp);

        int two_steps = 0;
        if (i + 2 <= s.length()) {
            two_steps = mem(i+2, 2, s, dp);
        }

        return dp[i][which_step] = one_step + two_steps;
    }
public:
    int numDecodings(string s) {

        if (s == "0" || s == "00") return 0;
        
        int which_step = 1;
        // return f(0, which_step, s);

        vector<vector<int>> dp(s.length()+1, vector<int>(3, -1));
        return mem(0, which_step, s, dp);
    }
};