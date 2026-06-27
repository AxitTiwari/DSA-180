// https://leetcode.com/problems/partition-labels/submissions/2046437607

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string s) {
        
        unordered_map<int, pair<int, int>> get_index; // ({first, last} index)
        for (int i = 0; i < s.length(); i++) {

            if (get_index.count(s[i])) {
                get_index[s[i]].second = i;
                continue;
            }

            get_index[s[i]] = {i, i};
        }

        vector<int> ans;

        int l = 0, r = 0;
        while (l < s.length()) {

            auto &[first, last] = get_index[s[l]];
            for (int j = first; j <= last; j++) {

                if (get_index[s[j]].second > last) {
                    last = get_index[s[j]].second;
                }
            }
            r = last;

            ans.push_back(r - l + 1);

            l = r + 1;
        }
        return ans;
    }
};