// https://leetcode.com/problems/jump-game/submissions/1978565649

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        
        int max_ind = 0;
        for (int i = 0; i < nums.size(); i++) {

            if (max_ind < i) return false;

            max_ind = max(max_ind, i + nums[i]);
        }
        return true;
    }
};