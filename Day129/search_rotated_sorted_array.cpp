// https://leetcode.com/problems/search-in-rotated-sorted-array/submissions/2010079182

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        int n = nums.size() - 1;

        int last_num = nums[n];

        int start = 0, end = n;
        while (start <= end) {

            int mid = start + (end - start) / 2;

            cout << mid << endl;

            if (nums[mid] == target) {
                return mid;
            }
            // left part
            else if (nums[start] <= nums[mid]) {
                if (target >= nums[start] && target < nums[mid]) {
                    end = mid - 1;
                }
                else {
                    start = mid + 1;
                }
            }
            // right part
            else {
                if (target > nums[mid] && target <= nums[end]) {
                    start = mid + 1;
                }
                else {
                    end = mid - 1;
                }
            }
        }
        return -1;
    }
};