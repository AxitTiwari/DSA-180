
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countDigitOccurrences(vector<int>& nums, int digit) {

        int count = 0;
        for (int num : nums) {

            while (num > 0) {
                int last_digit = num % 10;

                if (last_digit == digit) {
                    count++;
                }
                num = num / 10;
            }
        }
        return count;
    }
};