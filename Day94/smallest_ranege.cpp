// https://leetcode.com/submissions/detail/1980518484/

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    int row;
    int col;

    Node(int data, int r, int c) {
        this->data = data;
        row = r;
        col = c;
    }
};

class compare {
public:

    // compare two nodes by there data values
    bool operator()(Node* first, Node* second) {
        return first->data > second->data;
    }
};

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& a) {
        
        int k = a.size();

        priority_queue<Node*, vector<Node*>, compare> minHeap;

        int mini = INT_MAX;
        int maxi = INT_MIN;

        // push first k elements into minheap,
        // with keep track of min/ max element
        for (int i = 0; i < k; i++) {

            mini = min(mini, a[i][0]);
            maxi = max(maxi, a[i][0]);
            minHeap.push(new Node(a[i][0], i, 0));
        }

        // calculate the range
        int start = mini, end = maxi;

        // keep traversing until heap is not empty,
        while (!minHeap.empty()) {
            Node* tmp = minHeap.top();
            minHeap.pop();

            mini = tmp->data;

            // update start and end only when you get a better range then them
            if (maxi - mini < end - start) {
                start = mini;
                end = maxi;
            }

            // if next element of list having smallest element(for now) (in heap),
            // exists then add it to heap,
            if (tmp->col + 1 < a[tmp->row].size()) {
                maxi = max(maxi, a[tmp->row][tmp->col+1]);
                minHeap.push(new Node(a[tmp->row][tmp->col+1], tmp->row, tmp->col+1));
            }
            // if length of list exceeds, break
            else {
                break;
            }
        }

        vector<int> ans = {start, end};
        return ans;
    }
};