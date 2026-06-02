#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        // hard

        unordered_set<int> group;
        for (auto num : nums) {
            group.insert(num);
        }

        int ans = 0;
        for (auto num : group) {

            // not the starting point of any group
            if (group.find(num-1) != group.end()) {
                continue;
            }

            int len = 1;
            while (group.find(num+len) != group.end()) {
                len++;
            }

            ans = max(ans, len);
        }
        return ans;
    }
};