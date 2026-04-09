#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Graph {
private:
    vector<vector<int>> adj_list;
public:
    Graph(int V) {
        adj_list = vector<vector<int>> (V);
    }

    void add_edge(int src, int dest) {
        adj_list[src].push_back(dest);
    }

    void print() {

        for (int i = 0; i < adj_list.size(); i++) {
            cout << i << " : ";
            for (int j = 0; j < adj_list[i].size(); j++) {
                cout << adj_list[i][j] << " -> ";
            }
            cout << endl;
        }
    }

    vector<int> topo_sort() {

        int V = adj_list.size();
        vector<int> indegree(V, 0);

        queue<int> q;

        for (int i = 0; i < V; i++) {
            for (int j = 0; j < adj_list[i].size(); j++) {
                int nbr = adj_list[i][j];
                indegree[nbr]++;
            }
        }

        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> list;
        while (!q.empty()) {
            int node = q.front();
            q.pop();

            list.push_back(node);

            for (int nbr : adj_list[node]) {
                indegree[nbr]--;
                if (indegree[nbr] == 0) {
                    q.push(nbr);
                }
            }
        }
        return list;
    }
};

int main () {

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
