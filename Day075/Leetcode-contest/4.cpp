#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // DFS to check if path exists and track parity
    bool dfs(int node, int target, vector<vector<pair<int,int>>> &adj, 
             vector<int> &vis, int curr_parity, int &found_parity) {

        // found a path
        if (node == target) {
            found_parity = curr_parity;
            return true;
        }

        // mark node as visited
        vis[node] = 1;

        // check for neighbours
        for (auto &nbr : adj[node]) {
            int next = nbr.first;
            int wt = nbr.second;

            if (!vis[next]) {

                // 0 ^ even -> even, 1 ^ even -> odd
                // 0 ^ odd -> odd,   1 ^ odd  -> even
                if (dfs(next, target, adj, vis, curr_parity ^ wt, found_parity)) {
                    return true;
                }
            }
        }
        return false;
    }

    int numberOfEdgesAdded(int n, vector<vector<int>>& edges) {

        vector<vector<pair<int,int>>> adj(n);
        int count = 0;

        for (auto &e : edges) {
            int u = e[0], v = e[1], w = e[2];

            // visited array for DFS
            vector<int> vis(n, 0);

            // track the weight : even or odd
            int path_parity = -1;

            // Check if u and v already connected, and the weight b/t u and v is 
            // even or odd
            bool has_path = dfs(u, v, adj, vis, 0, path_parity);

            // if another path found to reach u to v: cycle present
            if (has_path) {
                
                // Cycle will form

                // check the weight of the cycle: even or odd
                int is_path_weight_even = path_parity ^ w;
                if (is_path_weight_even == 0) {
                    // EVEN cycle → accept
                    adj[u].push_back({v, w});
                    adj[v].push_back({u, w});
                    count++;
                }
                // else ODD cycle → reject
            } 
            else {
                // No cycle: safe -> continue creating the graph
                adj[u].push_back({v, w});
                adj[v].push_back({u, w});
                count++;
            }
        }
        return count;
    }
};