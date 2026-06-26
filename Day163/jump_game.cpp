// https://leetcode.com/problems/jump-game/submissions/2041854679

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        
        // greedy;
        
        int n = nums.size()-1;

        int goal = n;

        for (int i = n-1; i >= 0; i--) {

            if (i + nums[i] >= goal) {
                goal = i;
            }
        }
        return goal == 0;
    }
};
