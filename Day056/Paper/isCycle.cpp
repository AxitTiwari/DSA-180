#include <unordered_map>
#include <list>
#include <queue>
#include <bits/stdc++.h>

using namespace std;

bool isCyclicBFS(int node, unordered_map<int, list<int>> adj, unordered_map<int, bool> visited) {

    unordered_map<int, int> parent;
    parent[node] = -1;
    visited[node] = true;
    queue<int> q;
    q.push(node);

    while (!q.empty()) {
        int front = q.front();
        q.pop();

        for (auto neighbour : adj[front]) {
            if (visited[neighbour] && parent[front] != neighbour) {
                return true;
            }
            else if (!visited[neighbour]) {
                q.push(neighbour);
                visited[neighbour] = true;
                parent[neighbour] = front;
            }
        }
    }
    return false;
}

string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    // Write your code here.

    // adjacency list
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < edges.size(); i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // to handle disconnected components
    unordered_map<int, bool> visited;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            bool ans = isCyclicBFS(i, adj, visited);
            if (ans) return "Yes";
        }
    }

    return "No";
}
