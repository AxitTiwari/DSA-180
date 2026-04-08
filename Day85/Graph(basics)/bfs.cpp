#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class BFS {
public:

    vector<int> bfs(int src, vector<bool> &visited, vector<vector<int>>& adj_list) {

        queue<int> q;

        q.push(src);
        visited[src] = true;

        vector<int> output;

        while (!q.empty()) {

            int node = q.front();
            output.push_back(node);
            q.pop();

            for (auto nbr : adj_list[node]) {

                if (!visited[nbr]) {
                    visited[nbr] = true;
                    q.push(nbr);
                }
            }
        }
        return output;
    }

    vector<vector<int>> bfs_list(vector<vector<int>> adj_list) {

        int V = adj_list.size();
        vector<bool> visited (V, false);

        vector<vector<int>> traversal;

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                vector<int> ans = bfs(i, visited, adj_list);
                traversal.push_back(ans);
            }
        }

        return traversal;
    }
};

int main() {

    // changed the way i stored it, to get familiar with all possible type to store this
    vector<vector<int>> adj_list(5);

    adj_list[0] = {1, 2, 3};
    adj_list[1] = {0, 2};
    adj_list[2] = {1, 0};
    adj_list[3] = {0, 4};
    adj_list[4] = {3};

    cout << "Graph: " << endl;
    for (int i = 0; i < 5; i++) {
        cout << i << " : ";
        vector<int> neighbours = adj_list[i];
        for (auto nbr : neighbours) {
            cout << nbr << " ";
        }
        cout << endl;
    }
    cout << endl;

    BFS t;
    vector<vector<int>> result = t.bfs_list(adj_list);

    cout << "BFS: " << endl;
    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[0].size(); j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}