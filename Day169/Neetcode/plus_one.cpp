// https://leetcode.com/problems/plus-one/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        
        reverse(digits.begin(), digits.end());
        
        int carry = 1;
        for (int &digit : digits) {

            int sum = digit + carry;

            digit = (sum) % 10;
            carry = (sum) / 10;
        }

        if (carry > 0) {
            digits.push_back(carry);
        }

        reverse(digits.begin(), digits.end());
        return digits;
    }
};