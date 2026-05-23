// https://leetcode.com/submissions/detail/2010328407/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool check(vector<int>& nums) {
        
        int n = nums.size() - 1;
        int pair = 0;
        for (int i = 1; i <= n; i++) {

            if (nums[i-1] > nums[i]) {
                pair++;
            }
        }
        if (nums[n] > nums[0]) {
            pair++;
        }
        return pair <= 1;
    }
};