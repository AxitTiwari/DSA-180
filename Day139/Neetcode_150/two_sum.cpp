#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        unordered_map<int, int> second_number;
        for (int i = 0; i < nums.size(); i++) {

            if (second_number.count(target - nums[i])) return {i, second_number[target - nums[i]]};
            second_number[nums[i]] = i;
        }
        return {-1, -1};
    }
};