// https://leetcode.com/problems/jump-game-ii/submissions/2042318024

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        
        // BFS: (shortest path using BFS)
        
        int n = nums.size() - 1;

        int l = 0, r = 0;
        int res = 0;

        while (r < n) {

            int farthest = 0;
            for (int i = l; i <= r; i++) {
                farthest = max(farthest, i + nums[i]);
            }

            l = r + 1;
            r = farthest;

            res += 1;
        }
        return res;
    }
};
