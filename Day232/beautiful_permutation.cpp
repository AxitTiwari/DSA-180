// https://leetcode.com/problems/beautiful-arrangement/submissions/2128728799

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countArrangement(int n) {
        
        vector<int> nums;
        for (int i = 1; i <= n; i++) nums.push_back(i);

        return get_per(nums, 0);
    }
private:
    int get_per(vector<int>& nums, int idx) {

        if (idx >= nums.size()) {
            return 1;
        }

        int res = 0;
        for (int i = idx; i < nums.size(); i++) {

            swap(nums[idx], nums[i]);

            if (nums[idx] % (idx+1) == 0 || (idx+1) % nums[idx] == 0) {

                res += get_per(nums, idx+1);
            }

            swap(nums[idx], nums[i]);
        }
        return res;
    }
};