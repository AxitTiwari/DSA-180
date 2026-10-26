// https://leetcode.com/problems/minimum-deletions-to-make-array-sharp/submissions/2174992220

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minDeletions(vector<int>& nums) {

        int min_del = 0;
        for (int i = 0; i < nums.size()-1; i++) {
            if (nums[i] == nums[i+1]) {
                min_del += 1;
            }
        }
        return min_del;
    }
};