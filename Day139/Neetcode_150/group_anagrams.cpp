#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        unordered_map<string, vector<string>> map;
        for (auto &str : strs) {

            vector<int> freq(26, 0);
            for (int i = 0; i < str.length(); i++) {
                freq[str[i]-'a']++;
            }

            string key;
            for (int i = 0; i < 26; i++) {
                key += freq[i];
            }

            map[key].push_back(str);
        }

        vector<vector<string>> ans;
        int i = 0;
        for (auto &[it, lst] : map) {

            ans.push_back(lst);
        }
        return ans;
    }
};