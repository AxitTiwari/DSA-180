// https://leetcode.com/problems/sort-characters-by-frequency/submissions/1987387449

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        
        unordered_map<char, int> frq_count;

        for (auto ch : s) {
            frq_count[ch]++;
        }

        priority_queue<pair<int, char>> max_heap;
        for (auto it : frq_count) {
            max_heap.push({it.second, it.first});
        }

        string ans;
        while (!max_heap.empty()) {
            ans += string(max_heap.top().first, max_heap.top().second);
            max_heap.pop();
        }
        return ans;
    }
};