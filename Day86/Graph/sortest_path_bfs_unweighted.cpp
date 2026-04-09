#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Graph {
private:
    vector<vector<int>> adj_list;
public: 
    Graph (int V) {
        adj_list = vector<vector<int>> (V);
    }

    void add_edge(int src, int dest) {
        adj_list[src].push_back(dest);
        adj_list[dest].push_back(src);
    }

    void print() {

        for (int i = 0; i < adj_list.size(); i++) {
            cout << i << " : ";
            for (int j = 0; j < adj_list[i].size(); j++) {
                int nbr = adj_list[i][j];
                cout << nbr << " -> ";
            }
            cout << endl;
        }
    }

    vector<int> find_path(int start, int end) {

        int V = adj_list.size();

        vector<bool> visited(V, false);
        vector<int> parent(V);
        queue<int> q;

        q.push(start);
        visited[start] = true;
        parent[start] = -1;

        while (!q.empty()) {

            int node = q.front();
            q.pop();

            for (int nbr : adj_list[node]) {
                
                if (!visited[nbr]) {
                    visited[nbr] = true;
                    q.push(nbr);

                    parent[nbr] = node;
                }
            }
        }

        vector<int> path;
        while (end != start) {

            path.push_back(end);
            end = parent[end];
        }
        path.push_back(start);

        reverse(path.begin(), path.end());

        return path;
    }
};

int main() {


    Graph g(5);

    g.add_edge(0, 1);
    g.add_edge(1, 2);
    g.add_edge(2, 3);
    g.add_edge(3, 4);

    g.print();

    vector<int> path = g.find_path(0, 4);
    for (auto node : path) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}