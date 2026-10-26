// https://leetcode.com/problems/subarrays-distinct-element-sum-of-squares-i/submissions/2172589913

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int sumCounts(vector<int>& nums) {
        
        int res = 0;
        for (int i = 0; i < nums.size(); i++) {
            int score = 0;
            unordered_set<int> seen;

            for (int j = i; j < nums.size(); j++) {

                if (!seen.count(nums[j])) score += 1;;

                seen.insert(nums[j]);
                res += score * score;
            }
        }
        return res;
    }
};