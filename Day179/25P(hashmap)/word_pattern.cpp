// https://leetcode.com/problems/word-pattern/submissions/2063528262

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        
        // create a array of strings.
        stringstream ss(s);

        vector<string> words;
        string word;
        while (ss >> word) {
            words.push_back(word);
        }

        if (words.size() != pattern.length()) return false;

        unordered_map<char, string> mp;
        for (int i = 0; i < words.size(); i++) {

            char key = pattern[i];
            string value = words[i];

            // key is present
            if (mp.find(key) != mp.end()) {

                if (mp[key] != value) return false;
            }
            else {

                // if value is already present
                for (auto &it : mp) {
                    if (it.second == value) return false;
                }

                // otherwise add key : value
                mp[key] = value;
            }
        }
        return true;
    }
};