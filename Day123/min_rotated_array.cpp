// https://leetcode.com/submissions/detail/2004218129/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {

        int n = nums.size() - 1;

        int start = 0;
        int end = n;
        while (start < end) {

            int mid = start + (end - start) / 2;

            // right side
            if (nums[mid] > nums[end]) {
                start = mid + 1;
            }
            else if (nums[mid] < nums[end]){
                end = mid;
            }
            else {
                // reduce search space
                end -= 1;
            }
            cout << nums[mid] << endl;
        }
        return nums[start];
    }
};