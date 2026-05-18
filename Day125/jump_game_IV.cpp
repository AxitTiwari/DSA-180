// https://leetcode.com/problems/jump-game-iv/submissions/2006584572

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    void add_edge(int u, int v, unordered_map<int, list<int>> &graph, vector<int>& arr) {

        if (v >= 0 && v < arr.size())
            graph[u].push_back(v);
    }

    int bfs(unordered_map<int, vector<int>> &graph, vector<int> &arr) {

        unordered_map<int, bool> visited;
        queue<pair<int, int>> q;

        q.push({0, 0});
        visited[0] = true;
        while (!q.empty()) {

            auto [node, dis] = q.front();
            q.pop();

            if (node == arr.size()-1) {
                return dis;
            }

            if (node+1 < arr.size() && !visited[node+1]) {
                q.push({node+1, dis+1});
            }

            if (node-1 >= 0 && !visited[node-1]) {
                q.push({node-1, dis+1});
            }

            for (auto nbr : graph[arr[node]]) {
                if (!visited[nbr]) {
                    visited[nbr] = true;
                    q.push({nbr, dis+1});
                }
            }
            graph.erase(arr[node]);
        }
        return INT_MAX;
    }

public:
    int minJumps(vector<int>& arr) {

        unordered_map<int, vector<int>> map;
        for (int i = 0; i < arr.size(); i++) {
            map[arr[i]].push_back(i);
        }
        
        // unordered_map<int, list<int>> graph;
        // for (int i = 0; i < arr.size(); i++) {
        //     add_edge(i, i+1, graph, arr);
        //     add_edge(i, i-1, graph, arr);

        //     for (auto j : map[arr[i]]) {

        //         if (j != i)
        //             add_edge(i, j, graph, arr);
        //     }
        // }

        return bfs(map, arr);
    }
};