// https://leetcode.com/problems/search-in-rotated-sorted-array/submissions/2062563212

#include <bits/stdc++.h>
using namespace std;

// kasam se aaj samjh hu eshe aachhe se...
class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        int s = 0, e = nums.size() - 1;
        while (s <= e) {

            int m = s + (e - s) / 2;

            if (nums[m] == target) return m;

            // **imp : check window first
            if (nums[s] <= nums[m]) {
                // left part is sorted

                if (nums[m] >= target && target >= nums[s]) {
                    e = m - 1;
                }
                else {
                    s = m + 1;
                }
            }
            else {

                // right part is sorted
                if (nums[m] <= target && target <= nums[e]) {
                    s = m + 1;
                }
                else {
                    e = m - 1;
                }
            }
        }
        return -1;
    }
};