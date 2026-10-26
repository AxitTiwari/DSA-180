#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {

        long long res = 0;
        long long len = 0;
        for (auto num : nums) {

            if (num >= minK && num <= maxK) {
                len += 1;
                res += len;
            }
            else {
                len = 0;
            }
        }
        return res;
    }
};