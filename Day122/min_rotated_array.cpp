// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/submissions/2003945148

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        
        int n = nums.size() - 1;
        int joint = nums[n];

        int start = 0;
        int end = n;
        while (start < end) {

            int mid = start + (end - start) / 2;

            if (nums[mid] > joint) {
                start = mid + 1;
            }
            else {
                end = mid;
            }
        }
        return nums[start];
    }
};