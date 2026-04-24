// https://leetcode.com/problems/intersection-of-two-arrays/submissions/1987190935 

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        
        unordered_map<int, bool> num_exits;
        for (int num : nums1) {

            num_exits[num] = true;
        }

        vector<int> ans;
        for (int num : nums2) {

            if (num_exits[num]) {
                ans.push_back(num);
                num_exits[num] = false;
            }
        }
        return ans;
    }
};