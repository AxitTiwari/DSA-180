#include <iostream>
#include <unordered_map>
#include <list>
#include <set>
#include <vector>
#include <climits>
using namespace std;

class Graph {
private:
    unordered_map<int, list<pair<int, int>>> adj_list;
public:
    void add_edge(int src, int dest, int wt) {
        adj_list[src].push_back({dest, wt});
        adj_list[dest].push_back({src, wt});
    }

    void print() {

        cout << "Graph: " << endl;
        for (auto node : adj_list) {
            cout << node.first << " : ";
            for (auto nbr_and_wt : adj_list[node.first]) {
                cout << " [" << nbr_and_wt.first << ", " << nbr_and_wt.second << "]";
            }
            cout << endl;
        }
    }

    unordered_map<int, int> dijkstra_shortest_path(int src) {

        unordered_map<int, int> dist;
        for (auto node : adj_list) {
            dist[node.first] = INT_MAX;
        }

        set<pair<int, int>> s; // (dist, nbr)

        dist[src] = 0;
        s.insert({0, src}); // get minimum according to dist

        while (!s.empty()) {

            auto it = s.begin();
            
            pair<int, int> dist_and_node = *it;
            int node = dist_and_node.second;
            int dis = dist_and_node.first;

            s.erase(it);

            for (auto nbr_and_wt : adj_list[node]) {

                if (dist[node] + nbr_and_wt.second < dist[nbr_and_wt.first]) {

                    dist[nbr_and_wt.first] = dist[node] + nbr_and_wt.second;

                    s.insert({dist[nbr_and_wt.first], nbr_and_wt.first});
                }
            }
        }

        return dist;
    }
};

int main() {

    Graph g;

    g.add_edge(0, 1, 5);
    g.add_edge(0, 2, 8);
    g.add_edge(1, 2, 9);
    g.add_edge(1, 3, 2);
    g.add_edge(2, 3, 6);

    g.print();

    unordered_map<int, int> dist = g.dijkstra_shortest_path(0);

    for (auto node : dist) {
        cout << node.first << " -> " << node.second << endl;
    }

    return 0;
}