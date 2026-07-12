// https://leetcode.com/problems/valid-anagram/submissions/2063542956

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        
        unordered_map<char, int> cntS;
        unordered_map<char, int> cntT;

        for (int i = 0; i < s.length(); i++) {
            cntS[s[i]] += 1;
        }

        for (int i = 0; i < t.length(); i++) {
            cntT[t[i]] += 1;
        }

        for (char k = 'a'; k <= 'z'; k++) {
            if (cntS[k] != cntT[k]) return false;
        }
        return true;
    }
};