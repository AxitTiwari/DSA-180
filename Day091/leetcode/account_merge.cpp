#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
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

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        
        int n = accounts.size();

        // create a disjoint set of size n
        DisjointSet ds(n);

        // Step 1: map all mails to a number and add all of them to disjoint set also
        // create maping and disjoint set
        unordered_map<string, int> map_mail_node;
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < accounts[i].size(); j++) {
                
                // get all mails one by one for person 'i'
                string mail = accounts[i][j];

                // if mail is not already in map
                if (map_mail_node.find(mail) == map_mail_node.end()) {

                    // map it with number i
                    map_mail_node[mail] = i;
                }
                else {

                    // already in map -> add it to disjoint set
                    ds.union_by_size(i, map_mail_node[mail]);
                }
            }
        }

        // Step 2: group all mails according to their mapping number
        vector<string> mergered_mail[n]; // [ 0 : ["abc@", "as@"], 1 : ["dhb@"]]
        for (auto it : map_mail_node) {

            string mail = it.first;
            int node = ds.find_parent(it.second);
            mergered_mail[node].push_back(mail);
        }

        // Step 3:
        vector<vector<string>> ans;

        for (int i = 0; i < n; i++) {

            // skip numbers with no mails strored -> (ye kisi ke chid hai, disjoint set me)
            if (mergered_mail[i].size() == 0) continue;

            // sort all mails, -----required to return
            sort(mergered_mail[i].begin(), mergered_mail[i].end());

            vector<string> temp;

            // push name first
            temp.push_back(accounts[i][0]);

            // go for all mails
            for (auto it : mergered_mail[i]) {
                temp.push_back(it);
            }

            // push name + all sorted mails
            ans.push_back(temp);
        }

        return ans;
    }
};