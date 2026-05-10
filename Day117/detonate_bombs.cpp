// https://leetcode.com/problems/detonate-the-maximum-bombs/submissions/1999582105

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    void add_edge(int i, int j, unordered_map<int, list<int>>& graph) {
        graph[i].push_back(j);
    }

    int dfs(int node, unordered_map<int, list<int>>& graph, 
        unordered_map<int, bool>& visited
    ) {

        visited[node] = true;

        int ans = 1;
        for (auto nbr : graph[node]) {

            if (!visited[nbr]) {
                ans += dfs(nbr, graph, visited);
            }
        }
        return ans;
    }

public:
    int maximumDetonation(vector<vector<int>>& bombs) {

        unordered_map<int, list<int>> graph;
        for (int i = 0; i < bombs.size(); i++) {

            int u_x = bombs[i][0];
            int u_y = bombs[i][1];
            int u_r = bombs[i][2];

            for (int j = 0; j < bombs.size(); j++) {

                if (i == j) continue;

                int v_x = bombs[j][0];
                int v_y = bombs[j][1];
                int v_r = bombs[j][2];

                // calulate distance
                long long dx = 1LL * u_x - v_x;
                long long dy = 1LL * u_y - v_y;

                long long dist = dx * dx + dy * dy;
                long long r_sq = 1LL * u_r * u_r;

                if (r_sq >= dist) {
                    add_edge(i, j, graph);
                }
            }
        }

        int ans = 1;
        for (int i = 0; i < bombs.size(); i++) {

            unordered_map<int, bool> visited;
            ans = max(ans, dfs(i, graph, visited));
        }
        return ans;
    }
};