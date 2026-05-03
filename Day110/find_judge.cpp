// https://leetcode.com/problems/find-the-town-judge/submissions/1994158568

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    unordered_map<int, list<int>> graph;

    void add_edge(int u, int v) {
        graph[u].push_back(v);
        graph[v];
    }
public:
    int findJudge(int n, vector<vector<int>>& trust) {

        if (trust.empty()) return n == 1 ? 1 : -1;

        // celebrity problem
        for (int i = 0; i < trust.size(); i++) {
            
            int u = trust[i][0];
            int v = trust[i][1];
            add_edge(u, v);
        }

        unordered_map<int, int> indegree;
        for (auto parent : graph) {

            for (auto n : parent.second) {
                indegree[n]++;
            }
        }

        for (auto node : graph) {

            if (node.second.size() == 0 && indegree[node.first] == n-1) {

                return node.first;
            }
        }

        return -1;
    }
};