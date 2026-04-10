#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    unordered_map<int, list<int>> adj_list;

    void create_graph(int numCourses, vector<vector<int>>& prerequisites) {

        for (auto row : prerequisites) {
            adj_list[row[1]].push_back(row[0]);
            adj_list[row[0]];
        }
    }

    bool dfs(int node, unordered_map<int, bool>& visited, stack<int>& s, vector<bool>& rec_stack) {

        visited[node] = true;
        rec_stack[node] = true;

        for (auto nbr : adj_list[node]) {

            if (rec_stack[nbr]) return true;

            if (!visited[nbr]) {
                if (dfs(nbr, visited, s, rec_stack)) return true;
            }
        }

        s.push(node);
        rec_stack[node] = false;

        return false;
    }

public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {

        create_graph(numCourses, prerequisites);

        unordered_map<int, bool> visited;
        vector<int> result;
        stack<int> s;

        vector<bool> rec_stack(numCourses, false);

        for (int i = 0; i < numCourses; i++) {
            if (!visited[i]) {
                if (dfs(i, visited, s, rec_stack)) return {};
            }
        }

        while (!s.empty()) {

            int node = s.top();
            s.pop();

            result.push_back(node);
        }
        return result;
    } 
};