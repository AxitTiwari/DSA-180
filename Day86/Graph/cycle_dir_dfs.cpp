#include <iostream>
#include <vector>
#include <stack>
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
    }

    void print() {

        for (int i = 0; i < adj_list.size(); i++) {
            cout << i << " : ";
            for (int j = 0; j < adj_list[i].size(); j++) {
                cout << adj_list[i][j] << " -> ";
            }
            cout << "NULL" << endl;
        }
    }

    bool dfs(int src, vector<int>& visited, vector<int>& rec_stack) {

        visited[src] = true;
        rec_stack[src] = true;

        for (int nbr : adj_list[src]) {
            if (!visited[nbr]) {
                if (dfs(nbr, visited, rec_stack)) {
                    return true;
                }
            }
            else if (rec_stack[nbr]) {
                return true;
            }
        }

        rec_stack[src] = false;
        return false;
    }

    bool is_cycle() {

        int V = adj_list.size();
        vector<int> visited(V, false);
        vector<int> rec_stack(V, false);

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                if (dfs(i, visited, rec_stack)) {
                    return true;
                }
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
    g.add_edge(1, 3);
    g.add_edge(2, 0);
    g.add_edge(2, 3);

    g.print();

    if (g.is_cycle()) {
        cout << "cycle is present" << endl;
    }
    else {
        cout << "cycle is NOT present" << endl;
    }
    return 0;
}