// https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/submissions/2067547678

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        
        priority_queue<int> max_heap;
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix.size(); j++) {

                max_heap.push(matrix[i][j]);

                if (max_heap.size() > k) max_heap.pop();
            }
        }
        return max_heap.top();
    }
};