#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long weightedSum(vector<int>& parent, vector<int>& nums) {

        int n = parent.size();

        vector<vector<int>> children(n);
        for (int i = 1; i < n; i++) {
            children[parent[i]].push_back(i);
        }

        long long h = 1;

        vector<long long> depth(parent.size(), 0);
        depth[0] = 1;

        queue<int> q;
        q.push(0);

        while (!q.empty()) {

            int node = q.front();
            q.pop();

            for (int child : children[node]) {
                depth[child] = depth[node] + 1;

                h = max(h, depth[child]);

                q.push(child);
            }
        }
        
        long long sum = 0;
        for (int i = 0; i < parent.size(); i++) {

            long long d = depth[i];
            
            sum += nums[i] * (h - d + 1);
            // cout << nums[i] << " * " << "( " << h << " - " << d << " + " << " 1 )" << endl;
        }
        return sum;
    }
};