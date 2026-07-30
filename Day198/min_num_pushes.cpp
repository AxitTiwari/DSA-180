// https://leetcode.com/problems/minimum-number-of-pushes-to-type-word-i/submissions/2087678698

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumPushes(string word) {
        
        int ans = 0;
        for (int i = 0; i < word.length(); i++) ans += (i / 8) + 1;
        return ans;

    }
};