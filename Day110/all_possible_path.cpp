// https://leetcode.com/problems/all-paths-from-source-to-target/submissions/1994177274

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    vector<vector<int>> paths;
    
    void dfs(int node, vector<int>& one_path, vector<vector<int>>& graph, 
        unordered_map<int, bool>& visited,
        unordered_map<int, bool>& rec_stack
    ) {

        visited[node] = true;
        rec_stack[node] = true;

        one_path.push_back(node);

        if (node == graph.size()-1) {
            paths.push_back(one_path);

            // backtrack
            one_path.pop_back();
            visited[node] = false;
            return;
        }

        for (auto nbr : graph[node]) {
            
            if (!visited[nbr]) {
                dfs(nbr, one_path, graph, visited, rec_stack);
            }
            else {
                if (!rec_stack[nbr]) {
                    dfs(nbr, one_path, graph, visited, rec_stack);
                }
            }
        }

        // backtrack
        one_path.pop_back();
        rec_stack[node] = false;
    }
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        
        unordered_map<int, bool> visited;
        unordered_map<int, bool> rec_stack;
        vector<int> one_path;

        dfs(0, one_path, graph, visited, rec_stack);

        return paths;
    }
};