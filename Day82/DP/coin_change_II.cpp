#include <bits/stdc++.h>
using namespace std;

// DP on subsequences

class Solution {
private:
    int f(vector<int>& coins, int amount, int i) {

        if (amount == 0) {
            return 1;
        }

        if (i == coins.size()) {
            return 0;
        }

        // pick this coin
        int include = 0;
        if (coins[i] <= amount) {
            include = f(coins, amount-coins[i], i);
        }

        // do not pick this coin move at next coin
        int exclude = f(coins, amount, i+1);

        // cout << include << " " << exclude << endl;
        return include + exclude;
    }

    int memoization(vector<int>& coins, int amount, int i, vector<vector<int>>& dp) {

        if (amount == 0) {
            return 1;
        }

        if (i == coins.size()) {
            return 0;
        }

        if (dp[i][amount] != -1) {
            return dp[i][amount];
        }

        // pick this coin
        int include = 0;
        if (coins[i] <= amount) {
            include = memoization(coins, amount-coins[i], i, dp);
        }

        // do not pick this coin move at next coin
        int exclude = memoization(coins, amount, i+1, dp);

        // cout << include << " " << exclude << endl;
        return dp[i][amount] = include + exclude;
    }

    // int tabulation(vector<int>& coins, int amount) {

    //     vector<vector<long long>> dp(coins.size()+1, vector<long long> (amount+1, 0));

    //     for (int i = 0; i <= coins.size(); i++) {
    //         dp[i][0] = 1;
    //     }

    //     for (int i = coins.size()-1; i >= 0; i--) {

    //         for (int a = 0; a <= amount; a++) {

    //             long long include = 0;
    //             if (coins[i] <= a) {
    //                 include = dp[i][a-coins[i]];
    //             }

    //             long long exclude = dp[i+1][a];

    //             dp[i][a] = include + exclude;
    //         }
    //     }
    //     return (int)dp[0][amount];
    // }

public:
    int change(int amount, vector<int>& coins) {
        
        if (amount < 0) return 0;

        // return f(coins, amount, 0);

        vector<vector<int>> dp(coins.size(), vector<int> (amount+1, -1));
        return memoization(coins, amount, 0, dp);

        // return tabulation(coins, amount);
    }
};