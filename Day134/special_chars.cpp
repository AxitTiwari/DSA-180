// https://leetcode.com/problems/count-the-number-of-special-characters-ii/submissions/2014744173

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfSpecialChars(string word) {
        
        unordered_map<char, int> lowercase;
        unordered_map<char, int> uppercase;

        for (int i = 0; i < word.length(); i++) {
            if (islower(word[i])) {
                lowercase[word[i]] = i;
            }
            else {

                if (uppercase.find(word[i]) == uppercase.end())
                    uppercase[word[i]] = i;
            }
        }

        int count = 0;
        for (char ch = 'A'; ch <= 'Z'; ch++) {

            char lower = ch + 32;

            if (uppercase.find(ch) != uppercase.end() &&
                lowercase.find(lower) != lowercase.end() &&
                lowercase[lower] < uppercase[ch]) {
                
                count++;
            }
        }
        return count;
    }
};