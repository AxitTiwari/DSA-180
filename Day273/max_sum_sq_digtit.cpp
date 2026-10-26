// https://leetcode.com/problems/maximize-sum-of-squares-of-digits/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string maxSumOfSquares(int num, int sum) {

        string res = "";
        for (int i = 0; i < num; i++) {

            int digit_sum = 0;
            for (int digit = 9; digit >= 0; digit--) {
                if (digit + digit_sum <= sum) {
                    digit_sum += digit;
                    res += digit + '0';
                    sum -= digit;
                    break;
                }
            }
        }

        if (sum != 0) return "";

        return res;
        
        // int n = f(num, sum, 0);

        // // cout << n;

        // if (n == INT_MIN) return "";

        // return to_string(n);
    }

    Solution() {
        first_visit = true;
    }

private:
    bool first_visit;
    int f(int num, int sum, int n) {

        if (num == 0 && sum == 0) {
            return n;
        }

        if (num == 0 || sum == 0) return INT_MIN;

        int res = INT_MIN;
        for (int i = 0; i <= 9; i++) {

            if (first_visit) {
                first_visit = false;
                continue;
            }

            res = max(res, f(num-1, sum-i, 10*n+i));

            cout << i << ": " << res << endl;
        }

        cout  << res << endl;
        return res;
    }
};