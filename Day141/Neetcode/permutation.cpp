// https://leetcode.com/problems/permutation-in-string/submissions/2020786401

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool is_equal(vector<int> &count, vector<int> &window) {

        for (int i = 0; i < 26; i++) {
            if (count[i] != window[i]) {
                return false;
            }
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        
        if (s1.length() > s2.length()) return false;

        vector<int> count(26, 0);
        for (int i = 0; i < s1.length(); i++) {
            count[s1[i]-'a']++;
        }

        vector<int> window(26, 0);
        for (int i = 0; i < s1.length(); i++) {
            window[s2[i]-'a']++;
        }

        if (is_equal(count, window)) return true;

        int window_size = s1.length();
        for (int i = window_size; i < s2.length(); i++) {

            window[s2[i-window_size]-'a']--;

            window[s2[i]-'a']++;

            if (is_equal(count, window)) return true;

        }
        return false;
    }
};