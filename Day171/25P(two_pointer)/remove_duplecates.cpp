// https://leetcode.com/problems/remove-duplicates-from-sorted-array/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        int k = 1, n = nums.size();

        int j = 1;
        for (int i = 0; i < n; i++) {

            while (j < n && nums[i] == nums[j]) j++;

            if (j >= n) continue;
        
            nums[i+1] = nums[j];
            k += 1;
        }
        return k;
    }
};