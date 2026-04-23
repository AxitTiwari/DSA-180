#include <iostream>
#include <unordered_map>
#include <list>
#include <vector>
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

    void dfs(int node, int parent, int timer, unordered_map<int, bool>& visited, unordered_map<int, int>& dis, unordered_map<int, int>& low, vector<vector<int>>& result) {

        visited[node] = true;
        
        dis[node] = low[node] = timer++;

        for (auto nbr : adj_list[node]) {

            if (nbr == parent) continue;

            if (!visited[nbr]) {
                dfs(nbr, node, timer, visited, dis, low, result);

                low[node] = min(low[node], low[nbr]);

                if (low[nbr] > dis[node]) {
                    vector<int> ans;
                    ans.push_back(node);
                    ans.push_back(nbr);
                    result.push_back(ans);
                }
            }
            else {
                low[node] = min(low[node], dis[nbr]); // cycle
            }
        }
    }

    vector<vector<int>> find_bridges() {

        unordered_map<int, bool> visited;
        unordered_map<int, int> dis;
        unordered_map<int, int> low;

        for (auto node : adj_list) {
            dis[node.first] = -1;
            low[node.first] = -1;
        }

        int timer = 0;
        vector<vector<int>> result;

        for (auto node : adj_list) {
            if (!visited[node.first]) {
                dfs(node.first, -1, timer, visited, dis, low, result);
            }
        }
        return result;
    }
};

int main() {

    Graph g;

    g.add_edge(0, 1);
    g.add_edge(0, 2);
    g.add_edge(0, 3);
    g.add_edge(1, 2);
    g.add_edge(3, 4);

    g.print();

    vector<vector<int>> result = g.find_bridges();

    cout << "Bridges in the graph are: " << endl;
    for (auto bridge : result) {
        cout << bridge[0] << " - " << bridge[1] << endl;
    }
    
    return 0;
}