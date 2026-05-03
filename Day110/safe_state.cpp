// https://leetcode.com/problems/find-eventual-safe-states/submissions/1994335518

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    unordered_map<int, bool> outdegree;

    bool dfs(int node, unordered_map<int, bool>& visited, unordered_map<int, bool>& rec_stack,
         vector<vector<int>>& graph
    ) {

        visited[node] = true;
        rec_stack[node] = true;

        // terminal node
        if (outdegree[node] == 0) {

            rec_stack[node] = false;
            // visited[node] = false; // backtrack not required,,
            return true;
        }

        for (auto nbr : graph[node]) {

            if (!visited[nbr]) {
                if (!(dfs(nbr, visited, rec_stack, graph))) {
                    return false;
                }
            }
            else if (rec_stack[nbr]) {
                return false;
            }
        }

        rec_stack[node] = false;
        return true;
    }

public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        
        int i = 0;
        for (auto node : graph) {
            outdegree[i++] = node.size();
        }

        vector<int> ans;

        // imp
        unordered_map<int, bool> visited;
        unordered_map<int, bool> rec_stack;

        for (int node = 0; node < graph.size(); node++) {

            if (dfs(node, visited, rec_stack, graph)) {
                ans.push_back(node);
            }
        }
        return ans;
    }
};