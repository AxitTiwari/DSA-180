// https://leetcode.com/problems/find-missing-elements/submissions/2094311695

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        
        unordered_set<int> have;
        int min = INT_MAX, max = INT_MIN;
        for (int num: nums) {
            have.insert(num);
            min = min < num ? min : num;
            max = max > num ? max : num;
        }

        vector<int> res;
        for (int num = min; num <= max; num++) {

            if (have.find(num) != have.end()) continue;
            res.push_back(num);
        }
        return res;
    }
};