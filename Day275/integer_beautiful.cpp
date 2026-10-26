// https://leetcode.com/problems/minimum-addition-to-make-integer-beautiful/submissions/2173977373

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long makeIntegerBeautiful(long long n, int target) {
        
        long long res = 0;
        long long mul = 1;
        while (sum_of_digits(n) > target) {
            res += 1LL * mul * (10 - n % 10);
            n = n / 10 + 1;
            mul = mul * 10;
        }
        return res;
    }
private:
    int sum_of_digits(long long tmp) {
        int digit_sum = 0;
        while (tmp > 0) {
            int digit = tmp % 10;
            digit_sum += digit;
            tmp = tmp / 10;
        }
        return digit_sum;
    }
};