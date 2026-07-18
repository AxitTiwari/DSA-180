// https://leetcode.com/contest/biweekly-contest-187/ranking/?region=global_v2

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minAdjacentSwaps(vector<int>& nums, int a, int b) {

        const int MOD = 1e9;

        long long ans = 0;

        int m_count = 0;
        for (int num : nums) {

            if (num >= a and num <= b) m_count++;
            else if (num < a){
                ans += m_count;
            }
        }

        int r_count = 0;
        for (int num : nums) {

            if (num > b) r_count++;
            else if (num < a){
                ans += r_count;
            }
        }

        r_count = 0;
        for (int num : nums) {
            if (num > b) r_count++;
            else if (num >= a and num <= b) {
                ans += r_count;
            }
        }
        return ans % MOD;
    }
};