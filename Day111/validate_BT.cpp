// https://leetcode.com/problems/validate-binary-tree-nodes/submissions/1994949062

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool solve(int n, vector<int>& leftChild, vector<int>& rightChild) {

        vector<int> indegree(n, 0);
        unordered_map<int, bool> node_used;
        for (int i = 0; i < n; i++) {

            if (leftChild[i] != -1) {
               indegree[leftChild[i]]++;
               node_used[leftChild[i]] = true;
            }
            
            if (rightChild[i] != -1) {
                indegree[rightChild[i]]++;
                node_used[rightChild[i]] = true;
            }
        }

        int root = -1;
        for (int i = 0; i < indegree.size(); i++) {
            if (indegree[i] == 0) {

                if (root != -1) return false;
                root = i;
            }

            if (indegree[i] > 1) return false;
        }

        if (root == -1) return false;

        node_used[root] = true;
        for (int i = 0; i < n; i++) {
            if (!node_used[i]) {
                return false;
            }
        }

        queue<int> q;
        q.push(root);

        int size = 0;
        while (!q.empty()) {

            int node = q.front();
            q.pop();

            if (leftChild[node] != -1) {
                q.push(leftChild[node]);
            }
            if (rightChild[node] != -1) {
                q.push(rightChild[node]);
            }
            size++;
        }
        return size == n;
    }

public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        
        // annoying
        return solve(n, leftChild, rightChild);

        // unordered_map<int, bool> node_used;

        // lets find root that is not 0, by calculating indegress
        // node_used[0] = true;

        // for (int i = 0; i < n; i++) {

        //     if (leftChild[i] != -1) {

        //         if (node_used[leftChild[i]])  return false;
        //         node_used[leftChild[i]] = true;
        //     }
            
        //     if (rightChild[i] != -1) {

        //         if (node_used[rightChild[i]]) return false;
        //         node_used[rightChild[i]] = true;
        //     }
        // }

        // for (int node = 0; node < n; node++) {
        //     if (!node_used[node]) return false;
        // }
        // return true;
    }
};