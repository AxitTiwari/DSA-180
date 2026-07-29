// https://leetcode.com/problems/evaluate-division/submissions/2086485061

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        
        unordered_map<string, unordered_map<string, double>> gr = buildGraph(equations, values);

        vector<double> ans;
        for (auto querie : queries) {

            string divident = querie[0];
            string divisor = querie[1];

            if (gr.find(divident) == gr.end() || gr.find(divisor) == gr.end()) {
                ans.push_back(-1.0);
            }
            else {
                unordered_set<string> vis;

                double res = -1, temp = 1;
                dfs(divident, divisor, gr, vis, res, temp);
                ans.push_back(res);
            }
        }
        return ans;
    }

private:

    unordered_map<string, unordered_map<string, double>> buildGraph(vector<vector<string>>& equations, vector<double>& values) {

        unordered_map<string, unordered_map<string, double>> gr;

        for (int i = 0; i < equations.size(); i++) {

            string divident = equations[i][0];
            string divisor = equations[i][1];

            double w = values[i];

            gr[divident][divisor] = w;
            gr[divisor][divident] = 1 / w;
        }
        return gr;
    }

    void dfs(string node, string des, unordered_map<string, unordered_map<string, double>>& gr, unordered_set<string>& vis, double& res, double tmp) {

        if (vis.find(node) != vis.end()) return;

        if (node == des) {
            res = tmp;
            return;
        }

        vis.insert(node);

        for (auto n : gr[node]) {
            dfs(n.first, des, gr, vis, res, tmp*n.second);
        }
    }
};