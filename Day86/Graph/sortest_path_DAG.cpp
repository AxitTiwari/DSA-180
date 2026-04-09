#include <iostream>
#include <unordered_map>
#include <list>
#include <stack>
#include <vector>
#include <climits>
using namespace std;

class Graph {
private:
    unordered_map<int, list<pair<int, int>>> adj_list;
public:
    void add_edge(int src, int dest, int weight) {
        adj_list[src].push_back({dest, weight});
        adj_list[dest];
    }

    void print() {

        for (auto node : adj_list) {
            cout << node.first << " : ";
            for (auto nbr_and_wt : node.second) {
                cout << "[ " << nbr_and_wt.first << ", " << nbr_and_wt.second << " ]";
            }
            cout << endl;
        }
    }

    int size() {
        return adj_list.size();
    }

    void dfs(int node, unordered_map<int, bool>& visited, stack<int>& s) {

        visited[node] = true;

        for (auto nbr_wt : adj_list[node]) {
            if (!visited[nbr_wt.first]) {
                dfs(nbr_wt.first, visited, s);
            }
        }

        s.push(node);
    }

    void topo_sort(unordered_map<int, bool>& visited, stack<int>& s) {

        for (auto node : adj_list) {
            if (!visited[node.first]) {
                dfs(node.first, visited, s);
            }
        }
    }

    void shortest_path(int node, unordered_map<int, int>& dist, stack<int>& s) {

        dist[node] = 0;

        while (!s.empty()) {

            int top_node = s.top();
            s.pop();

            if (dist[top_node] != INT_MAX) {

                for (auto nbr_wt : adj_list[top_node]) {
                    if (dist[top_node] + nbr_wt.second < dist[nbr_wt.first]) {
                        dist[nbr_wt.first] = dist[top_node] + nbr_wt.second;
                    }
                }
            }
        }
    }

    void set_dist(unordered_map<int, int>& dist) {
        for (auto node : adj_list) {
            dist[node.first] = INT_MAX;
        }
    }

    void print_dist(unordered_map<int, int>& dist) {
        for (auto node_wt : dist) {
            cout << node_wt.second << " ";
        }
        cout << endl;
    }

};

int main() {

    Graph g;

    g.add_edge(0, 1, 5);
    g.add_edge(0, 2, 3);
    g.add_edge(1, 3, 6);
    g.add_edge(1, 2, 2);
    g.add_edge(2, 4, 4);
    g.add_edge(2, 5, 2);
    g.add_edge(2, 3, 7);
    g.add_edge(3, 4, -1);
    g.add_edge(4, 5, -2);

    g.print();

    // topological sort
    unordered_map<int, bool> visited;
    stack<int> s;
    g.topo_sort(visited, s);

    int src = 1;
    unordered_map<int, int> dist;

    g.set_dist(dist);

    g.shortest_path(src, dist, s);

    g.print_dist(dist);

    return 0;
}