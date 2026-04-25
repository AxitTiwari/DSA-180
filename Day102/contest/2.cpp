// https://leetcode.com/submissions/detail/1987812925/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int compareBitonicSums(vector<int>& nums) {

        long long int first_arr = 0;
        long long int second_arr = 0;

        // [1,3,2,1]
        
        long long int prev = INT_MIN;
        bool include_peak = true;
        for (auto num : nums) {

            if (num > prev) {
                first_arr += num;
            }
            else {
                second_arr = include_peak ? second_arr + num + prev : second_arr + num;
                include_peak = false;
            }
            prev = num;
        }

        return (first_arr > second_arr ? 0: (first_arr < second_arr ? 1 : -1));
    }
};