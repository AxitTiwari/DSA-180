// https://leetcode.com/submissions/detail/1986895378/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        
        unordered_map<int, int> map_elements;

        for (int num : nums) {
            map_elements[num]++;
        }

        vector<int> ans;
        for (auto num_count : map_elements) {

            if (num_count.second > nums.size() / 3) {
                ans.push_back(num_count.first);
            }
        }
        return ans;
    }
};