// https://leetcode.com/problems/missing-number/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        
        int n = nums.size();

        int sum_of_nums = 0;
        for (int &num : nums) {
            sum_of_nums += num;
        }
        
        int actual_sum = n * (n + 1) / 2;

        return abs(sum_of_nums - actual_sum);
    }
};