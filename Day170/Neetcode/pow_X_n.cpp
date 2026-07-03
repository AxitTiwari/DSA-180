// https://leetcode.com/problems/powx-n/submissions/2053437675

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double myPow(double x, int n) {

        if (n == 0) return double(1);
        
        unordered_map<int, double> dp;
        return func(x, n, dp);
    }
private:
    double func(double x, int n, unordered_map<int, double> &dp) {

        if (n == 1 || n == -1) {
            return n > 0 ? x : 1 / x;
        }

        if (dp.count(n)) return dp[n];

        double first_half = n > 0 ? (n & 1 ? x * func(x, n/2, dp) : func(x, n/2, dp)) : (n & 1 ? 1/x * func(x, n/2, dp) : func(x, n/2, dp));
        double second_half = func(x, n/2, dp);

        return dp[n] = first_half * second_half;
    }
};
