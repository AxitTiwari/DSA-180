#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Graph {
private:
    vector<vector<int>> adj_list;
public:

    Graph(int n) {
        adj_list = vector<vector<int>> (n);
    }

    void add_edge(int src, int dest) {
        adj_list[src].push_back(dest);
    }

    void print() {

        for (int i = 0; i < adj_list.size(); i++) {
            cout << i << " : ";
            for (int j = 0; j < adj_list[i].size(); j++) {
                cout << adj_list[i][j] << " ";
            }
            cout << endl;
        }
    }

    void dfs(int node, vector<bool>& visited, stack<int>& s) {

        visited[node] = true;

        for (int nbr : adj_list[node]) {
            if (!visited[nbr]) {
                dfs(nbr, visited, s);
            }
        }

        s.push(node);
    }

    vector<int> topo_sort() {

        int V = adj_list.size();
        vector<bool> visited(V, false);

        stack<int> s;

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                dfs(i, visited, s);
            }
        }

        vector<int> topo;

        while (!s.empty()) {
            topo.push_back(s.top());
            s.pop();
        }

        return topo;
    }
};

int main() {

    Graph g(5);

    g.add_edge(0, 1);
    g.add_edge(1, 2);
    g.add_edge(3, 2);
    g.add_edge(3, 4);

    g.print();

    vector<int> order = g.topo_sort();

    for (int node : order) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}