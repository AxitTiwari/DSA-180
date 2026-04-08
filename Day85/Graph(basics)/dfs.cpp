#include <iostream>
#include <vector>
#include <list>
#include <unordered_map>
using namespace std;

class Graph {
protected:
    unordered_map<int, list<int>> adj_list;
public:
    void add_edge(int src, int dest) {
        adj_list[src].push_back(dest);
        adj_list[dest].push_back(src);
    }

    void print() {

        cout << "Graph: " << endl;
        for (auto node : adj_list) {
            cout << node.first << " : ";
            for (auto nbr : node.second) {
                cout << nbr << " -> ";
            }
            cout << endl;
        }
        cout << endl;
    }

    void dfs(int src, unordered_map<int, bool>& visited, vector<int>& layer) {

        visited[src] = true;
        layer.push_back(src);

        for (auto nbr : adj_list[src]) {

            if (!visited[nbr]) {
                dfs(nbr, visited, layer);
            }
        }
    }

    vector<vector<int>> dfs_list() {

        unordered_map<int, bool> visited;

        vector<vector<int>> ans;
        for (auto node : adj_list) {
            int i = node.first;
            if (!visited[i]) {
                vector<int> layer;
                dfs(i, visited, layer);
                ans.push_back(layer);
            }
        }
        return ans;
    }
};

int main() {

    Graph g;

    // creating graph
    g.add_edge(0, 1);
    g.add_edge(0, 2);
    g.add_edge(0, 3);
    g.add_edge(1, 2);
    g.add_edge(3, 4);

    g.print();

    vector<vector<int>> traversal = g.dfs_list();

    for (int i = 0; i < traversal.size(); i++) {
        for (int j = 0; j < traversal[i].size(); j++) {
            cout << traversal[i][j] << " ";
        }
        cout << endl;
    }

    cout << traversal.size() << endl;
    return 0;
}