// https://leetcode.com/problems/top-k-frequent-words/submissions/1991195748

#include <bits/stdc++.h>
using namespace std;

struct Compare {
    bool operator()(pair<int, string>& a, pair<int, string>& b) {
        if (a.first == b.first) {
            return a.second < b.second;  // lexicographically smaller first 
        }
        return a.first > b.first;  // smaller count first
    }
};

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        
        // store the count
        unordered_map<string, int> map_str_count;
        for (auto word : words) {
            map_str_count[word]++;
        }

        // heap -> get k frequent words
        priority_queue<pair<int, string>, vector<pair<int, string>>, Compare> min_heap;
        for (auto it : map_str_count) {

            // first k elements
            if (min_heap.size() < k) {
                min_heap.push({it.second, it.first});
            }
            else {

                // check after kth count
                // if (k == 1 && min_heap.top().first == it.second) {

                //     if (min_heap.top().second > it.first) {
                //         min_heap.pop();
                //         min_heap.push({it.second, it.first});
                //     }
                // }
                if (min_heap.top().first < it.second) {
                    min_heap.pop();
                    min_heap.push({it.second, it.first});
                }
                else if (min_heap.top().first == it.second && min_heap.top().second > it.first) {
                    min_heap.pop();
                    min_heap.push({it.second, it.first});
                }
            }
        }

        /*
            'i'         ->   2
            'love'      ->   2
            'leetcode'  ->   1
            'coding'    ->   1
             k = 1
        */

        vector<string> ans;
        while (!min_heap.empty()) {

            auto it = min_heap.top();
            ans.push_back(it.second);
            min_heap.pop();
        }

        // // O(nlogn)
        reverse(ans.begin(), ans.end());
        return ans;
    }
};