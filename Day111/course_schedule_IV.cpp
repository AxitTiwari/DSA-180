// 1462. Course Schedule IV

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    unordered_map<int, list<int>> graph;

    bool dfs(int s, int d, unordered_map<int, bool>& visited) {

        visited[s] = true;

        if (s == d) return true;

        for (auto nbr : graph[s]) {
            if (!visited[nbr]) {
                if (dfs(nbr, d, visited)) {
                    return true;
                }
            }
        }
        return false;
    }

    void add_edge(int u, int v) {
        graph[u].push_back(v);
        graph[v];
    }

    bool is_path(int src, int dest) {

        unordered_map<int, bool> visited;
        return dfs(src, dest, visited);
    }

public:
    vector<bool> checkIfPrerequisite(int numCourses, 
        vector<vector<int>>& prerequisites, 
        vector<vector<int>>& queries
    ) {

        if (prerequisites.empty()) {
            return vector<bool> (queries.size(), false);
        }

        // create graph
        for (auto p : prerequisites) {
            add_edge(p[0], p[1]);
        }

        vector<bool> ans;
        for (auto q : queries) {

            if (is_path(q[0], q[1])) {
                ans.push_back(true);
            }
            else {
                ans.push_back(false);
            }
        }
        return ans;
    }
};