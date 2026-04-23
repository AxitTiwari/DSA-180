#include <iostream>
#include <vector>
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
        adj_list[dest].push_back(src);
    }

    void print() {

        cout << "Graph: " << endl;
        for (int i = 0; i < adj_list.size(); i++) {
            cout << i << " : ";
            for (int j = 0; j < adj_list[i].size(); j++) {
                cout << adj_list[i][j] << " ";
            }
            cout << endl;
        }
    }

    bool dfs(int src, int parent, vector<int> &visited) {

        // make node visited
        visited[src] = true;

        // visit all neighbours
        for (int nbr : adj_list[src]) {

            // any new node -> visit it
            if (!visited[nbr]) {

                // visit src node nbr, and return true instantly if you found a cycle, otherwise check for all cases
                if (dfs(nbr, src, visited)) {
                    return true;
                }
            }
            else if (nbr != parent){ // already visited, and not the parent of src node -> cycle
                return true;
            }
        }
    }

    bool is_cycle() {

        // number of nodes
        int V = adj_list.size();

        vector<int> visited(V, false);
        
        for (int u = 0; u < V; u++) {
            if (!visited[u]) {
                if (dfs(u, -1, visited))
                    return true;
            }
        }
        return false;
    }
};

int main() {

    Graph g(4);

    g.add_edge(0, 1);
    g.add_edge(0, 2);
    g.add_edge(1, 2);
    g.add_edge(2, 3);

    g.print();

    if (g.is_cycle()) {
        cout << "graph contains a cycle" << endl;
    }
    else {
        cout << "no cycle" << endl;
    }

    Graph g1(4);

    g1.add_edge(0, 1);
    g1.add_edge(1, 2);
    g1.add_edge(2, 3);

    g1.print();

    if (g1.is_cycle()) {
        cout << "graph contains a cycle" << endl;
    }
    else {
        cout << "no cycle" << endl;
    }

    return 0;
}