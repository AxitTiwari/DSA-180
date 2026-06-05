// https://leetcode.com/problems/find-the-duplicate-number/submissions/2023018308

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        int slow = 0, fast = 0;
        while (true) {
            slow = nums[slow];
            fast = nums[nums[fast]];

            // cout << slow << " : " << fast << endl;

            if (slow == fast) break;
        }

        int cur = 0;
        while (true) {

            cur = nums[cur];
            slow = nums[slow];

            // cout << cur << " -> " << slow << endl; 

            if (slow == cur) return slow;
        }
        return -1;
    }
};