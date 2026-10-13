// https://leetcode.com/submissions/detail/2170718719/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < 0) nums[i] = -1 * nums[i]; 
        }
        
        sort(nums.begin(), nums.end());

        long long res = 0;
        int l = 0, r = nums.size()-1;
        while (l < r) {
            res += (nums[r] * nums[r] - nums[l] * nums[l]);
            cout << res << "";
            l++, r--;
        }

        if (nums.size() % 2 != 0) res += nums[r] * nums[r];
        return res;
    }
};