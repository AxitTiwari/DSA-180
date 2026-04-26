
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findValidElements(vector<int>& nums) {

        if (nums.size() == 0) return {};

        int n = nums.size() - 1;
        
        vector<int> ans;
        ans.push_back(nums[0]);

        if (nums.size() == 1) return ans;

        // [1,2,4,2,3,2]
        for (int i = 1; i < n; i++) {

            bool is_valid = true;
            
            // left part
            for (int j = 0; j < i; j++) {

                // not strictly increasing
                if (nums[i] <= nums[j]) is_valid = false;
            }

            if (!is_valid) {

                // right part
                is_valid = true;
                for (int j = i + 1; j <= n; j++) {

                    if (nums[i] <= nums[j]) is_valid = false;
                }
            }

            if (is_valid) ans.push_back(nums[i]);
        }

        ans.push_back(nums[n]);

        return ans;
    }
};