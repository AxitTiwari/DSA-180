// https://leetcode.com/problems/course-schedule/submissions/2030442032

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    unordered_map<int, list<int>> graph;

    void add_edge(int u, int v) {
        graph[u].push_back(v);
    }

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        for (auto c : prerequisites) {
            add_edge(c[1], c[0]);
        }
        
        vector<int> indegree(numCourses, 0);
        for (auto node : graph) {

            for (auto nbr : node.second) {
                indegree[nbr]++;
            }
        }

        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        stack<int> topo;
        while (!q.empty()) {

            int node = q.front();
            q.pop();

            topo.push(node);

            for (auto nbr : graph[node]) {
                indegree[nbr]--;

                if (indegree[nbr] == 0) {
                    q.push(nbr);
                }
            }
        }

        return topo.size() == numCourses;
    }
};