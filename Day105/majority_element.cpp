// https://leetcode.com/problems/majority-element/submissions/1990402888

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        unordered_map<int, int> map_nun_count;
        for (int num : nums) {
            map_nun_count[num]++;
        }

        int n = nums.size();
        for (auto it : map_nun_count) {

            if (it.second > n / 2) return it.first;
        }

        return -1;
    }
};