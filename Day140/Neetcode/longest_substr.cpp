// https://leetcode.com/problems/longest-substring-without-repeating-characters/submissions/2019750301

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int max_len = 0;

        unordered_map<char, int> mp;
        
        int left = 0;
        for (int right = 0; right < s.length(); right++) {

            if (mp.count(s[right])) {

                // ##imp
                left = max(left, mp[s[right]] + 1);

            }

            mp[s[right]] = right;
            max_len = max(max_len, right - left + 1);
        }
        return max_len;
    }
};