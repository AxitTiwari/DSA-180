#include <bits/stdc++.h> 
using namespace std;

class Node {
public:
    int data;
    int row;
    int col;

    Node (int data, int row, int col) {
        this->data = data;
        this->row = row;
        this->col = col;
    }
};

class compare {
public:

    // compare two nodes by there data values
    bool operator()(Node* first, Node* second) {
        return first->data > second->data;
    }
};


vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    // build a min heap
    priority_queue<Node*, vector<Node*>, compare> minHeap;

    // insert all first k elements of all arrays into heap
    for (int i = 0; i < k; i++) {
        Node* tmp = new Node(kArrays[i][0], i, 0);
        minHeap.push(tmp);
    }

    vector<int> ans;

    // step 2: first pop element from minHeap,
    // push element in the minHeap, that is next in the array
    while (!minHeap.empty()) {
        Node* tmp = minHeap.top();
        minHeap.pop();

        // push element in ans
        ans.push_back(tmp->data);

        // exract the position of the element, i.e row and col
        int row = tmp->row;
        int col = tmp->col;

        // check if (row, col+1) exits, if then push
        if (col+1 < kArrays[row].size()) {
            Node* next = new Node(kArrays[row][col+1], row, col+1);
            minHeap.push(next);
        }
    } 
    return ans;
}
