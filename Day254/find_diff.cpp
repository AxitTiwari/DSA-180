// https://leetcode.com/problems/find-the-difference/submissions/2153206686/?envType=problem-list-v2&envId=string

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    char findTheDifference(string s, string t) {
        
        unordered_map<char, int> mp;
        for (char ch : s) mp[ch]++;

        for (char ch : t) {

            if (mp.find(ch) != mp.end() && mp[ch] > 0) {
                mp[ch]--;
                continue;
            }

            return ch;
        }
        return '#';
    }
};