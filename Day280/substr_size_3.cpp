// https://leetcode.com/problems/substrings-of-size-three-with-distinct-characters/submissions/2177824316

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countGoodSubstrings(string s) {
    
        int res = 0;
        for (int i = 0; i + 2 < s.length(); i++) {

            unordered_set<char> seen;
            seen.insert(s[i]);
            seen.insert(s[i+1]);
            seen.insert(s[i+2]);

            if (seen.size() == 3) res++;
        }
        return res;
    }
};