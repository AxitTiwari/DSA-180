// https://leetcode.com/problems/critical-connections-in-a-network/submissions/1978093342

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

class Solution {
private:
    int timer = 1;

    void dfs(int node, int parent, vector<bool>& vis, vector<vector<int>>& adj, 
        int tin[], int low[], vector<vector<int>>& bridges
    ) {

        vis[node] = true;
        tin[node] = low[node] = timer++;

        for (auto it : adj[node]) {

            if (it == parent) continue;

            if (!vis[it]) {

                dfs(it, node, vis, adj, tin, low, bridges);

                low[node] = min(low[node], low[it]);

                if (low[it] > tin[node]) {
                    bridges.push_back({it, node});
                }
            }
            else {
                low[node] = min(low[node], low[it]);
            }
        }
    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        
        // create the graph
        vector<vector<int>> adj(n);
        for (auto it : connections) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        vector<bool> vis(n, false);
        int tin[n];
        int low[n];
        vector<vector<int>> bridges;
        dfs(0, -1, vis, adj, tin, low, bridges);
        return bridges;
    }
};