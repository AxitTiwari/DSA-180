#include <iostream>
#include <unordered_map>
#include <list>
#include <vector>
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

    bool bfs(int node, unordered_map<int, int>& color) {

        queue<int> q;

        q.push(node);
        color[node] = 0;

        while (!q.empty()) {
            int front_node = q.front();
            q.pop();

            for (auto nbr : adj_list[front_node]) {

                if (color[nbr] == -1) {

                    color[nbr] = 1 - color[front_node];
                    q.push(nbr);
                }
                else if (color[nbr] == color[front_node]) {
                    return true;
                }
            }
        }
        return false;
    }

    bool is_bipartite() {

        unordered_map<int, int> color;

        for (auto node : adj_list) {
            color[node.first] = -1;
        }

        for (auto node : adj_list) {
            if (color[node.first] == -1) {
                if (bfs(node.first, color)) return false;
            }
        }
        return true;
    }
};

int main() {

    Graph g;

    g.add_edge(1, 2);
    g.add_edge(2, 3);
    g.add_edge(2, 6);
    g.add_edge(3, 4);
    g.add_edge(4, 7);
    g.add_edge(4, 5);
    g.add_edge(6, 5);
    g.add_edge(7, 8);

    g.print();

    if (g.is_bipartite()) {
        cout << "Bipartite" << endl;
    }
    else {
        cout << "NOT a bipartite" << endl;
    }

    return 0;
}