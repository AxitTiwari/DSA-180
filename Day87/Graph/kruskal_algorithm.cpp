#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(vector<int> a, vector<int> b) {
    return a[2] < b[2]; // weight
}

void make_set(vector<int>& parent, vector<int>& rank, int n) {

    for (int node = 1; node <= n; node++) {

        parent[node] = node;
        rank[node] = 0;
    }
}

int find_parent(int node, vector<int>& parent) {

    if (parent[node] == node) {
        return node;
    }

    // find parent with path compressor
    return node = find_parent(parent[node], parent);
}

void union_set(int u, int v, vector<int>& parent, vector<int>& rank) {

    u = find_parent(u, parent);
    v = find_parent(v, parent);

    if (rank[u] < rank[v]) {

        parent[u] = v;
    }
    else if (rank[u] > rank[v]) {
        parent[v] = u;
    }
    else {

        parent[v] = u;
        rank[v]++;
    }
}

int main() {

    vector<vector<int>> edges = {
        {1, 2, 2},
        {1, 4, 1},
        {1, 5, 4},
        {2, 3, 3},
        {2, 4, 3},
        {2, 6, 7},
        {3, 4, 5},
        {3, 6, 8},
        {4, 5, 9}
    };

    int n = 6;

    // sort the edges
    sort(edges.begin(), edges.end(), cmp);

    vector<int> parent(n);
    vector<int> rank(n);

    // inisialise parent and rank, (set)
    make_set(parent, rank, n);

    vector<vector<int>> mst;

    int min_wt = 0;
    for (int row = 0; row < edges.size(); row++) {

        int u = find_parent(edges[row][0], parent);
        int v = find_parent(edges[row][1], parent);
        int wt = edges[row][2];

        if (u != v) {

            min_wt += wt;
            union_set(u, v, parent, rank);

            mst.push_back(edges[row]);
        }
    }

    cout << "min weight of spanning tree: " << min_wt << endl;

    for (auto value : mst) {
        for (int data : value) {
            cout << data << " - ";
        }
        cout << endl;
    }


    return 0;
}