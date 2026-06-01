// https://leetcode.com/contest/weekly-contest-504/problems/maximum-number-of-items-from-sale-i/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int func(int i, vector<vector<int>>& items, int budget, unordered_map<int, pair<int, bool>> &free_copies,
            vector<vector<int>> &dp
    ) {

        if (budget == 0) {
            return 0;
        }

        if (dp[i][budget] != -1) {
            return dp[i][budget];
        }

        // string key = to_string(i) + "|" + to_string(budget);

        // if (dp.count(key)) {
        //     return dp[key];
        // }

        int ans = 0;
        for (int j = i; j < items.size(); j++) {

            int free_copy = 0;
            bool was_true = false;
            if (free_copies[j].second) {
                free_copy = free_copies[j].first;
                free_copies[j].second = false;
                was_true = true;
            }

            if (budget - items[j][1] >= 0)
                ans = max(ans, 1 + func(j, items, budget - items[j][1], free_copies, dp) + free_copy);

            if (was_true) {
                free_copies[j].second = true;
            }
        }
        // cout << "i: " << i << endl;
        // cout << "ans: " << ans << endl;
        return dp[i][budget] = ans;
    }
    
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {

        unordered_map<int, pair<int, bool>> free_copies;
        for (int i = 0; i < items.size(); i++) {
            for (int j = 0; j < items.size(); j++) {

                if (i != j) {

                    if (items[j][0] % items[i][0] == 0) {
                        free_copies[i] = {free_copies[i].first + 1, true};
                    }
                }
            }
        }

        // unordered_map<string, int> dp;
        vector<vector<int>> dp(items.size(), vector<int> (budget+1, -1));
        return func(0, items, budget, free_copies, dp);
    }
};