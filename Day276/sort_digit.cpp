// https://leetcode.com/problems/minimum-swaps-to-sort-by-digit-sum/submissions/2174761055

#include <bits/stdc++.h>    
using namespace std;

class Solution {
public:
    int minSwaps(vector<int>& nums) {
        
        vector<int> tmp = nums;

        auto sum_of_digits = [](int n) {
            int sum = 0;
            while (n > 0) {
                sum += n % 10;
                n /= 10;
            }
            return sum;
        };

        auto lambda = [&](int num1, int num2) {

            int d_sum1 = sum_of_digits(num1);
            int d_sum2 = sum_of_digits(num2);

            if (d_sum1 != d_sum2) return d_sum1 < d_sum2;

            return num1 < num2;
        };
        sort(tmp.begin(), tmp.end(), lambda);

        unordered_map<int, int> idx_num;
        for (int i = 0; i < nums.size(); i++) idx_num[nums[i]] = i;

        int swaps = 0;
        for (int i = 0; i < nums.size(); i++) {

            if (nums[i] == tmp[i]) continue;

            int n_i = idx_num[tmp[i]];

            swap(nums[i], nums[n_i]);

            idx_num[nums[i]] = i;
            idx_num[nums[n_i]] = n_i;

            swaps++;
        }
        return swaps;
    }
};