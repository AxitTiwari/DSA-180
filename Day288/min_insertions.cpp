// https://leetcode.com/problems/minimum-insertions-to-balance-a-parentheses-string/description/?envType=daily-question&envId=2026-10-09

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minInsertions(string s) {
        
        int res = 0;
        int open = 0;
        for (int i = 0; i < s.length(); i++) {

            if (s[i] == '(') {
                open++;
            }
            else {

                if (i+1 < s.length() && s[i+1] == ')') {
                    i++;
                }
                else {
                    res++;
                }

                if (open > 0) {
                    open--;
                }
                else {
                    res++;
                }
            }
        }
        return res + open * 2;
    }
};