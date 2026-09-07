// https://leetcode.com/submissions/detail/2133190754/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkValidString(string s) {
        
        int leftMin = 0, leftMax = 0;
        for (char c : s) {

            if (c == '(') {
                leftMin = leftMin + 1;
                leftMax = leftMax + 1;
            }
            else if (c == ')') {
                leftMin = leftMin - 1;
                leftMax = leftMax - 1;
            }
            else {
                leftMin = leftMin - 1;
                leftMax = leftMax + 1;
            }

            if (leftMax < 0) return false;

            if (leftMin < 0) leftMin = 0;
        } 

        return leftMin == 0;
    }
};