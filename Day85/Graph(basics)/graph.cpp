#include <iostream>
#include <vector>
#include <list>
#include <unordered_map>
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

        // (int) -> [list]
        // 1 : 0 -> 2
        for (auto node : adj_list) {

            cout << node.first << " : ";
            for (auto neighbour : node.second) {
                cout << neighbour << " -> ";
            }
            cout << "NULL" << endl;
        }
    }
};

class GraphMatrix {
private:
    vector<vector<int>> adj_matrix;
public:
    GraphMatrix(int n) {
        adj_matrix = vector<vector<int>> (n, vector<int> (n, 0));
    }

    void add_edge(int src, int dest) {
        adj_matrix[src][dest] = 1;
        adj_matrix[dest][src] = 1;
    }

    void print() {

        int n = adj_matrix.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << adj_matrix[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
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

    GraphMatrix g2(5);

    g2.add_edge(0, 1);
    g2.add_edge(0, 2);
    g2.add_edge(0, 3);
    g2.add_edge(1, 2);
    g2.add_edge(3, 4);

    g2.print();
    return 0;
}