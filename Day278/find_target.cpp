// https://leetcode.com/problems/find-target-indices-after-sorting-array/submissions/2175861324

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        
        vector<int> cnt(101, 0);
        for (int i = 0; i < nums.size(); i++) {
            cnt[nums[i]]++;
        }

        int num_element = 0, i;
        for (i = 0; i != target; i++) {
            // cout << i << " ";
            num_element += cnt[i];
        }

        // cout << i;

        vector<int> res;
        for (int j = 0; j < cnt[i]; j++) {
            res.push_back(num_element);
            num_element++;
        }

        return res; 
    }
};