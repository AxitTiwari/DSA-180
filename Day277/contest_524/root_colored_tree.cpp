#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    unordered_map<int, list<int>> tree;
    int findColoredRoot(vector<vector<int>>& edges, string colors) {

        for (auto edge: edges) {
            tree[edge[0]].push_back(edge[1]);
            tree[edge[1]].push_back(edge[0]);
        }

        for (int i = 0; i < tree.size(); i++) {
            if (is_root(i, colors)) return i;
        }
        return -1;
    }
private:
    char next_color(char color) {
        if (color == 'R') return 'B';
        if (color == 'B') return 'W';
        return 'R';
    }
    
    bool is_root(int root, string& colors) {

        queue<int> q;
        q.push(root);

        unordered_set<int> seen;
        while (!q.empty()) {

            int node = q.front();
            q.pop();

            seen.insert(node);

            int childrens = 0;
            for (auto nbr : tree[node]) {

                if (seen.count(nbr)) continue;

                seen.insert(nbr);
                childrens++;

                if (colors[nbr] != next_color(colors[node])) return false;
                
                q.push(nbr);
            }

            if (childrens > 2) return false;
        }
        return true;
    }
};