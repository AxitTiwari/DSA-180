
#include <bits/stdc++.h>    
using namespace std;

class Solution {
private:
    int recursion(vector<int>& coins, int amount) {

        if (amount == 0) {
            return 0;
        }

        if (amount < 0) {
            return INT_MAX;
        }

        int count = INT_MAX;
        for (int i = 0; i < coins.size(); i++) {

            int run = recursion(coins, amount-coins[i]);

            // cout << run << endl;

            if (run != INT_MAX)
                count = min(count, 1 + run);
        }

        // cout << count << endl;

        if (count != INT_MAX) {
            // cout << count << endl;
            return count;
        }
        return -1;
    }

    int memoization(vector<int>& coins, int amount, vector<int>& dp) {

        if (amount == 0) {
            return 0;
        }

        if (amount < 0) {
            return INT_MAX;
        }

        if (dp[amount] != -1) {
            return dp[amount];
        }

        int count = INT_MAX;
        for (int i = 0; i < coins.size(); i++) {

            int res = memoization(coins, amount-coins[i], dp);
            if (res != INT_MAX)
                count = min(count, 1 + res);
        }
        return dp[amount] = count;
    }

    int tabulation(vector<int>& coins, int amount) {

        // ** HW **
    }

public:
    int coinChange(vector<int>& coins, int amount) {

        if (amount == 0) return 0;
        
        // return recursion(coins, amount);

        vector<int> dp(amount+1, -1);

        int ans = memoization(coins, amount, dp);
        return (ans == INT_MAX) ? -1 : ans;
    }
};