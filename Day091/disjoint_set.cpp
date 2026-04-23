#include <iostream>
#include <vector>
using namespace std;

class DisjointSet {
private:
    vector<int> rank, parent, size;
public:
    DisjointSet(int n) {

        rank.resize(n+1, 0);
        parent.resize(n+1);
        size.resize(n+1);

        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int find_parent(int node) {

        if (node == parent[node]) {
            return node;
        }
        return parent[node] = find_parent(parent[node]);
    }

    void union_by_rank(int u, int v) {

        int parent_u = find_parent(u);
        int parent_v = find_parent(v);

        // same component
        if (parent_u == parent_v) return;

        if (rank[parent_u] < rank[parent_v]) {
            parent[parent_u] = parent_v;
        }
        else if (rank[parent_u] > rank[parent_v]) {
            parent[parent_v] = parent_u;
        }
        else {
            parent[parent_v] = parent_u;
            rank[parent_u]++;
        }
    }

    void union_by_size(int u, int v) {

        int parent_u = find_parent(u);
        int parent_v = find_parent(v);

        // same component
        if (parent_u == parent_v) return;

        if (size[parent_u] < size[parent_v]) {
            parent[parent_u] = parent_v;
            size[parent_v] += size[parent_u];
        }
        else {
            parent[parent_v] = parent_u;
            size[parent_u] += size[parent_v];
        }
    }
};

int main () {

    // union by size
    DisjointSet ds(7);

    ds.union_by_size(1, 2);
    ds.union_by_size(2, 3);
    ds.union_by_size(4, 5);
    ds.union_by_size(6, 7);
    ds.union_by_size(5, 6);

    if (ds.find_parent(3) == ds.find_parent(7)) {
        cout << "same" << endl;
    }
    else cout << "not same" << endl;

    ds.union_by_size(3, 7);

    if (ds.find_parent(3) == ds.find_parent(7)) {
        cout << "same" << endl;
    }
    else cout << "not same" << endl;

    // union by rank
    DisjointSet ds1(7);

    ds1.union_by_rank(1, 2);
    ds1.union_by_rank(2, 3);
    ds1.union_by_rank(4, 5);
    ds1.union_by_rank(6, 7);
    ds1.union_by_rank(5, 6);

    if (ds1.find_parent(3) == ds1.find_parent(7)) {
        cout << "same" << endl;
    }
    else cout << "not same" << endl;

    ds1.union_by_rank(3, 7);

    if (ds1.find_parent(3) == ds1.find_parent(7)) {
        cout << "same" << endl;
    }
    else cout << "not same" << endl;

    return 0;
}