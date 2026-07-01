// https://leetcode.com/problems/happy-number/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        
        int slow = n, fast = get_digit_sum(n);
        while (slow != fast) {

            // cout << slow << " : " << fast << endl;

            fast = get_digit_sum(fast);
            fast = get_digit_sum(fast);
            slow = get_digit_sum(slow);

        }

        cout << slow << " : " << fast << endl;
        return fast == 1;
    }
private:
    int get_digit_sum(int n) {

        int sum = 0;
        while (n > 0) {
            int digit = n % 10;
            sum += digit * digit;
            n = n / 10;
        }
        return sum;
    }
};
