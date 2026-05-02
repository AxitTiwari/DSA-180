// https://leetcode.com/problems/possible-bipartition/submissions/1992996572

#include <bits/stdc++.h>
using namespace std;

class MySolution {
private:
    bool bfs(int node, vector<vector<int>>& graph, unordered_map<int, int>& color) {

        queue<int> q;
        q.push(node);
        color[node] = 0;

        while (!q.empty()) {

            int cur_node = q.front();
            q.pop();

            for (auto nbr : graph[cur_node]) {

                if (color[nbr] == -1) {
                    color[nbr] = 1 - color[cur_node];
                    q.push(nbr);
                }
                else if (color[nbr] == color[cur_node]) {
                    return false;
                }
            }
        }
        return true;
    }

public:
    bool is_bipartite(vector<vector<int>>& graph) {

        unordered_map<int, int> color;
        for (int i = 0; i < graph.size(); i++) {
            color[i] = -1;
        }

        for (int i = 0; i < graph.size(); i++) {

            if (color[i] == -1) {

                // if not a bipartite then only immediatly return false
                if (!(bfs(i, graph, color))) {
                    return false;
                }
            }
        }
        return true;
    }
};

class Solution {
private:
    MySolution obj;
    vector<vector<int>> graph;

    void create_graph(int n, vector<vector<int>>& dislikes) {

        graph.resize(n+1);

        for (auto it : dislikes) {

            int u = it[0];
            int v = it[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
    }
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        
        // edge -> find out that how to create graph

        // one way is connect all them together who dislikes each othe so that we can group them easily
        /*
            dislikes = [[1,2],[1,3],[2,4]]

            (0)1 --- 2 (1)
                |      \
                |       \
            (1)3         4(0)

            --> true
        */

        // build graph
        create_graph(n, dislikes);
        return obj.is_bipartite(graph);
    }
};

// by Disjoint Set Union (DSU) or Union-Find
/*
class DisjointSet {
private:
    vector<int> rank, parent;
public:
    DisjointSet(int n) {

        rank.resize(n+1, 0);
        parent.resize(n+1);

        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int find_parent(int node) {

        if (node == parent[node]) {
            return node;
        }
        return parent[node] = find_parent(parent[node]);
    }

    void union_by_rank(int u, int v) {

        int parent_u = find_parent(u);
        int parent_v = find_parent(v);

        // same component
        if (parent_u == parent_v) return;

        if (rank[parent_u] < rank[parent_v]) {
            parent[parent_u] = parent_v;
        }
        else if (rank[parent_u] > rank[parent_v]) {
            parent[parent_v] = parent_u;
        }
        else {
            parent[parent_v] = parent_u;
            rank[parent_u]++;
        }
    }
};

class Solution {
private:
    vector<vector<int>> graph;

    void create_graph(int n, vector<vector<int>>& dislikes) {

        graph.resize(n+1);

        for (auto it : dislikes) {

            int u = it[0];
            int v = it[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
    }
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        
        // edge -> find out that how to create graph

        // one way is connect all them together who dislikes each othe so that we can group them easily
        // 
        //     dislikes = [[1,2],[1,3],[2,4]]

        //     (0)1 --- 2 (1)
        //         |      \
        //         |       \
        //     (1)3         4(0)

        //     --> true
        // 

        // build graph
        create_graph(n, dislikes);

        DisjointSet ds(n+1);

        for (int u = 1; u <= n; u++) {

            for (auto v : graph[u]) {

                // u dislikes v, so should be in different group
                if (ds.find_parent(u) == ds.find_parent(v)) {
                    return false;
                }
            }

            for (int i = 1; i < graph[u].size(); i++) {
                ds.union_by_rank(graph[u][0], graph[u][i]);
            }
        }
        return true;
    }
};
*/