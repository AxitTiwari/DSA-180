// https://leetcode.com/problems/group-anagrams/submissions/1989556175

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        unordered_map<string, vector<string>> map_word_with_anagrams;

        for (int i = 0; i < strs.size(); i++) {

            // create a key, for every word
            string temp = strs[i];
            sort(temp.begin(), temp.end());

            // map key
            map_word_with_anagrams[temp].push_back(strs[i]);

            // for (int j = i+1; j < strs.size(); j++) {

            //     string new_word = s[j];
            //     sort(new_word.begin(), new_word.end());

            //     if (new_word == temp)
            //         map_word_with_anagrams[temp].push_back(s[j]);
            // }
        }

        vector<vector<string>> ans(map_word_with_anagrams.size());
        int i = 0;
        for (auto it : map_word_with_anagrams) {

            for (auto word : it.second) {
                ans[i].push_back(word);
            }
            i++;
        }
        return ans;
    }
};