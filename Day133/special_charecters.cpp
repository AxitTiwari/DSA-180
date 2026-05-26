// https://leetcode.com/problems/count-the-number-of-special-characters-i/submissions/2013821083

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfSpecialChars(string word) {
        
        unordered_map<char, bool> lowercase;
        unordered_map<char, bool> uppercase;

        for (auto w : word) {

            if (w >= 'a' && w <= 'z') {
                lowercase[w] = true;
            }

            if (w >= 'A' && w <= 'Z') {
                uppercase[w] = true;
            }
        }

        int count = 0;
        for (auto it : uppercase) {

            if (lowercase[it.first - 'A' + 'a']) {
                count++;
            }
        }
        return count;

    }
};