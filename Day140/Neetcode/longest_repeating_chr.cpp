// https://leetcode.com/problems/longest-repeating-character-replacement/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        
        int max_size = 0;
        unordered_map<char, int> count;

        int l = 0;
        for (int r = 0; r < s.length(); r++) {

            count[s[r]]++;

            int max_count_in_window = 0;
            for (char i = 'A'; i <= 'Z'; i++) {
                max_count_in_window = max(max_count_in_window, count[i]);
            }

            if ((r - l + 1) - max_count_in_window > k) {
                count[s[l]]--;
                l++;
            }

            max_size = max(max_size, r - l + 1);
        }
        return max_size;
    }
};