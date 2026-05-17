// https://leetcode.com/problems/jump-game-iii/submissions/2005133914

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool f(vector<int>& arr, int start, unordered_map<int, bool> &visited) {

        if (arr[start] == 0) {
            return true;
        }

        if (start < 0 || start >= arr.size()) return false;

        visited[start] = true;

        // cout << start << endl;

        bool forward = false;
        int forward_i = start + arr[start];
        if (forward_i >= 0 && (forward_i < arr.size()) && !visited[forward_i])
            forward = f(arr, forward_i, visited);
        
        bool backward = false;
        int backward_i = start - arr[start];
        if ((backward_i >= 0) && (backward_i < arr.size()) && !visited[backward_i])
            backward = f(arr, backward_i, visited);

        return forward || backward;
    }
public:
    bool canReach(vector<int>& arr, int start) {
        
        unordered_map<int, bool> visited;
        return f(arr, start, visited);
    }
};