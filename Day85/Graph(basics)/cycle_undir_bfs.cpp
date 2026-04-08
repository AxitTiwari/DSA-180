#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include <queue>
using namespace std;

class Graph {
private:
    unordered_map<int, list<int>> adj_list;
public:
    void add_edge(int src, int dest) {
        adj_list[src].push_back(dest);
        adj_list[dest].push_back(src);
    }

    void print() {

        for (auto node : adj_list) {
            cout << node.first << " : ";
            for (auto nbr : node.second) {
                cout << nbr << " -> ";
            }
            cout << endl;
        }
    }

    bool bfs(int src, unordered_map<int, bool>& visited) {

        queue<pair<int, int>> q;

        q.push({src, -1});
        visited[src] = true;

        while (!q.empty()) {

            int node = q.front().first;
            int parent = q.front().second;

            for (auto nbr : adj_list[node]) {
                if (!visited[nbr]) {
                    visited[nbr] = true;
                    q.push({nbr, node});
                }
                else if (nbr != parent) {
                    return true;
                }
            }
        }
        return false;
    }

    bool is_cycle() {

        unordered_map<int, bool> visited;

        for (auto node : adj_list) {
            if (!visited[node.first]) {
                if (bfs(node.first, visited)) {
                    return true;
                }
            }
        }
        return false;
    }
};

int main() {

    Graph g;

    g.add_edge(0, 1);
    g.add_edge(0, 2);
    g.add_edge(1, 2);
    g.add_edge(2, 3);

    g.print();

    cout << g.is_cycle() << endl;
    return 0;
}