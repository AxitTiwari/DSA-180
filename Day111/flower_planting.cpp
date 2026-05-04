// https://leetcode.com/problems/flower-planting-with-no-adjacent/submissions/1994770660

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    void add_edge(int u, int v, vector<vector<int>>& graph) {
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {

        // not easy

        vector<vector<int>> graph(n+1);
        vector<int> answer(n+1, 0);
        
        // create graph
        for (auto path : paths) {
            add_edge(path[0], path[1], graph);
        }

        for (auto node = 1; node <= n; node++) {

            // avialable type
            bool used_type[5] = {false};

            // find the color which can be used for node
            for (auto nbr : graph[node]) {
                used_type[answer[nbr]] = true;
            }

            // from smallest to end check which color can be used
            for (int type = 1; type <= 4; type++) {
                if (!used_type[type]) {
                    answer[node] = type;
                    break;
                }
            }
        }

        // remove 1st wala index
        return vector<int> (answer.begin()+1, answer.end());
    }
};