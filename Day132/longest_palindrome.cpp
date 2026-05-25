// https://leetcode.com/problems/longest-palindrome/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestPalindrome(string s) {
        
        unordered_map<char, int> count;
        for (auto num : s) {
            count[num]++;
        }

        int cnt = 0;
        bool odd_case = false;
        for (auto &it : count) {

            if (it.second % 2 == 0) {
                cnt += it.second;
            }
            else {
                odd_case = true;
                cnt += it.second - 1;
            }
        }

        return odd_case ? cnt + 1 : cnt;
    }
};