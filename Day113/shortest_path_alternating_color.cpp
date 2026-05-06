// https://leetcode.com/submissions/detail/1996331226/

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    void add_edge(int u, int v, int color, unordered_map<int, list<pair<int, int>>>& graph) {
        graph[u].push_back({v, color});
        graph[v];
    }

    vector<int> bfs(int node, int color, unordered_map<int, list<pair<int, int>>>& graph,
        vector<int>& answer,
        vector<vector<bool>>& visited
    ) {

        queue<pair<int, pair<int, int>>> q;
        q.push({node, {0, color}});

        answer[0] = 0;

        while (!q.empty()) {

            auto [n, p] = q.front();
            auto [d, c] = p;
            q.pop();

            for (auto [nbr, nbr_c] : graph[n]) {

                if ((c == -1 || nbr_c != c) && !visited[nbr][nbr_c]) {

                    if (answer[nbr] == -1) {
                        answer[nbr] = d + 1;
                    }

                    visited[nbr][nbr_c] = true;

                    q.push({nbr, {d+1, nbr_c}});
                }
            }
        }
        return answer;
    }

public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        
        // create the graph : with colored edges
        unordered_map<int, list<pair<int, int>>> graph; // (src, (dest, color)) , 0 : red
        for (int i = 0; i < redEdges.size(); i++) {
            add_edge(redEdges[i][0], redEdges[i][1], 0, graph);
        }

        for (int i = 0; i < blueEdges.size(); i++) {
            add_edge(blueEdges[i][0], blueEdges[i][1], 1, graph);
        }

        vector<vector<bool>> visited(n, vector<bool> (2, false)); // b/c od self loop
        vector<int> answer(n, -1);

        bfs(0, -1, graph, answer, visited);
        return answer;
    }
};