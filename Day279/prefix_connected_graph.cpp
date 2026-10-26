// https://leetcode.com/problems/number-of-prefix-connected-groups/submissions/2176772090

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int prefixConnected(vector<string>& words, int k) {
        
        unordered_map<string, int> mp;
        for (auto word : words) {

            if (word.size() < k) continue;

            string prefix = word.substr(0, k);
            mp[prefix]++;
        }
        
        int connected_grp = 0;
        for (auto &it : mp) {
            if (it.second > 1) connected_grp += 1;
        }
        return connected_grp;
    }
};