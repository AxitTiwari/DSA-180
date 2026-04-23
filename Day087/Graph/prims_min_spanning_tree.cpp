#include <iostream>
#include <unordered_map>
#include <list>
#include <vector>
#include <queue>
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

    vector<pair<pair<int, int>, int>> min_spanning_tree(int start) {

        unordered_map<int, int> keys;
        unordered_map<int, bool> mst;
        unordered_map<int, int> parent;

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq; // {key, node}

        for (auto node : adj_list) {

            keys[node.first] = INT_MAX;
            mst[node.first] = false;
            parent[node.first] = -1;
        }

        keys[start] = 0;
        pq.push({0, start});

        while (!pq.empty()) {

            pair<int, int> top = pq.top();
            pq.pop();
            
            int wt = top.first;
            int node = top.second;

            if (mst[node]) continue;

            mst[node] = true;

            for (auto nbr_and_wt : adj_list[node]) {

                if (!mst[nbr_and_wt.first] && nbr_and_wt.second < keys[nbr_and_wt.first]) {

                    keys[nbr_and_wt.first] = nbr_and_wt.second;
                    parent[nbr_and_wt.first] = node;

                    pq.push({keys[nbr_and_wt.first], nbr_and_wt.first});
                }
            }
        }

        vector<pair<pair<int, int>, int>> result;

        for (auto p : parent) {
            if (p.second != -1) {

                int node = p.first;
                int parent = p.second;

                int wt = keys[node];

                result.push_back({{node, parent}, wt});
            }
        }

        return result;
    }
};

int main() {

    Graph g;

    g.add_edge(0, 1, 2);
    g.add_edge(0, 3, 6);
    g.add_edge(1, 4, 5);
    g.add_edge(1, 2, 3);
    g.print();

    vector<pair<pair<int, int>, int>> result = g.min_spanning_tree(0);

    for (int i = 0; i < result.size(); i++) {
        cout << result[i].first.first << ", " << result[i].first.second << " : " << result[i].second << endl;
    }

    return 0;
}