// https://leetcode.com/problems/search-in-rotated-sorted-array/submissions/2022229981

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        int s = 0, e = nums.size() - 1;
        while (s <= e) {

            int m = s + (e - s) / 2;

            cout << m << endl;

            if (nums[m] == target) return m;

            if (nums[s] <= nums[m]) {
                
                if (nums[m] > target && nums[s] <= target) {
                    e = m - 1;
                }
                else {
                    s = m + 1;
                }
            }
            else {
                
                if (nums[m] < target && nums[e] >= target) {
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