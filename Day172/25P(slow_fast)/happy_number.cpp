// https://leetcode.com/problems/happy-number/submissions/2055641404

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        
        int slow = n, fast = num_digit_sum(n);
        
        while (slow != fast) slow = num_digit_sum(slow), fast = num_digit_sum(num_digit_sum(fast));

        return slow == 1;
    }
private:
    int num_digit_sum(int n) {
        
        int sum = 0;
        while (n > 0) {
            int digit = n % 10;
            sum += digit * digit;
            n = n / 10;
        }
        return sum;
    }
};