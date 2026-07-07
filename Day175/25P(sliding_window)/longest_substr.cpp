// https://leetcode.com/problems/longest-substring-without-repeating-characters/submissions/2059652435

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int l = 0;
        unordered_set<char> seen;

        int res = 0;
        for (int r = 0; r < s.length(); r++) {

            while (!seen.empty() && seen.find(s[r]) != seen.end()) {
                seen.erase(s[l]);
                l++;
            }

            seen.insert(s[r]);
            res = res > seen.size() ? res : seen.size();
        }
        return res;
    }
};