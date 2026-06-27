// https://leetcode.com/problems/valid-parenthesis-string/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkValidString(string s) {
        
        memset(dp, -1, sizeof(dp));
        return func(0, 0, s);
    }
private:

    int dp[101][101];
    bool func(int i, int open, string &s) {

        if (i >= s.length()) {
            
            return open == 0;
        }

        if (dp[i][open] != -1) return dp[i][open];

        if (s[i] == '(') {
            return dp[i][open] = func(i+1, open+1, s);
        }
        else if (s[i] == ')' and open >= 1) {

            return dp[i][open] = func(i+1, open-1, s);
        }
        else {

            if (s[i] == ')') return false;

            bool a = func(i+1, open+1, s);

            bool b = open <= 0 ? false : func(i+1, open-1, s);

            bool c = func(i+1, open, s);

            return dp[i][open] = a or b or c;
        }
    }
};


/*
// GREEDY ALGORITHM
bool checkValidString(string s) {
        
        int leftMin = 0, leftMax = 0;
        for (char c : s) {

            if (c == '(') {
                leftMin = leftMin + 1;
                leftMax = leftMax + 1;
            }
            else if (c == ')') {
                leftMin = leftMin - 1;
                leftMax = leftMax - 1;
            }
            else {
                leftMin = leftMin - 1;
                leftMax = leftMax + 1;
            }

            if (leftMax < 0) return false;

            if (leftMin < 0) leftMin = 0;
        } 

        return leftMin == 0;
    }
*/