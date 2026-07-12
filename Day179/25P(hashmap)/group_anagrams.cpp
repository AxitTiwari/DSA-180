// https://leetcode.com/problems/group-anagrams/submissions/2063559498

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        unordered_map<string, vector<string>> mp;
        for (auto &str : strs) {

            string tmp = str;
            sort(tmp.begin(), tmp.end());
            mp[tmp].push_back(str);
        }

        vector<vector<string>> res;
        for (auto &[key, value] : mp) {
            res.push_back(value);
        }
        return res;
    }
};