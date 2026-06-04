// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/submissions/2022019942

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        
        int n = nums.size() - 1;
        
        int _min = nums[0];

        int s = 1, e = n;
        while (s <= e) {

            int m = s + (e - s) / 2;

            _min = min(_min, nums[m]);

            if (nums[m] > nums[n]) {
                s = m + 1;
            }
            else {
                e = m -1;
            }
        }
        return _min;
    }
};