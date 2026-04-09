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
    }

    void print() {

        for (auto node : adj_list) {
            cout << node.first << " : ";
            for (auto nbr : node.second) {
                cout << nbr << " -> ";
            }
            cout << "NULL" << endl;
        }
    }

    bool is_cycle() {

        int V = adj_list.size();

        // going to work same as visited array in other questions
        vector<int> indegree(V, 0);

        queue<int> q;
        int visited = 0;

        // find all indegree
        for (auto node : adj_list) {
            for (auto nbr : adj_list[node.first]) {
                indegree[nbr]++;
            }
        }

        // push nodes in queue having indegree 0
        for (auto node : adj_list) {
            if (indegree[node.first] == 0) {
                q.push(node.first);
            }
        }

        // BFS
        while (!q.empty()) {

            int node = q.front();
            q.pop();
            visited++;

            for (int nbr : adj_list[node]) {
                indegree[nbr]--;
                if (indegree[nbr] == 0) {
                    q.push(nbr);
                }
            }
        }

        return visited != V;
    }

};

int main() {

    Graph g;

    g.add_edge(0, 1);
    g.add_edge(0, 2);
    g.add_edge(1, 2);
    g.add_edge(1, 3);
    g.add_edge(2, 0);
    g.add_edge(2, 3);

    g.print();

    if (g.is_cycle()) {
        cout << "cycle present" << endl;
    }
    else  {
        cout << "cycle is NOT present" << endl;
    }

    return 0;
}