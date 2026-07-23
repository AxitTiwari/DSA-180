// https://leetcode.com/problems/node-with-highest-edge-score/submissions/2077789955

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int edgeScore(vector<int>& edges) {
        
        unordered_map<int, long long> edge_score;
        for (int i = 0; i < edges.size(); i++) {
            edge_score[edges[i]] += i;
        }

        int res = -1;
        long long cnt = 0;
        for (auto &[node, count] : edge_score) {

            if (cnt == count) res = min(res, node);

            if (cnt < count) {
                res = node;
                cnt = count;
            }
        }
        return res;
    }
};