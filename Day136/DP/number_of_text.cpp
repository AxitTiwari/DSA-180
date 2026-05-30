// https://leetcode.com/problems/count-number-of-texts/submissions/2016074679

#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;

class Solution {
private:

    bool is_safe(int i, char ch) {

        if (ch == '7' || ch == '9') {
            return i < 4;
        }
        return i < 3;
    }

    int f(int idx, int len, string &pressedKeys, vector<vector<int>> &dp) {

        if (idx == pressedKeys.length()-1) return 1;

        if (dp[idx][len] != -1) return dp[idx][len];

        int left = f(idx+1, 0, pressedKeys, dp);
        int right = 0;
        if (idx < pressedKeys.length()-1) {

            if (pressedKeys[idx] == pressedKeys[idx+1] && is_safe(len+1, pressedKeys[idx])) {
                right = f(idx+1, len+1, pressedKeys, dp);
            }
        }
        return dp[idx][len] = (left + right) % MOD;
    }
    
public:
    int countTexts(string pressedKeys) {
        
        vector<vector<int>> dp(pressedKeys.length(), vector<int> (5, -1));
        return f(0, 0, pressedKeys, dp);
    }
};