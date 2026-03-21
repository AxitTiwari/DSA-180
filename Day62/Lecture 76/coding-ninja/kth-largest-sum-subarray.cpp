#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;
int getKthLargest(vector<int> &arr, int k)
{
	priority_queue<int, vector<int>, greater<int>> minHeap;

	for (int i = 0; i < arr.size(); i++) {

		int sum = 0;
		for (int j = i; j < arr.size(); j++) {

			sum += arr[j];

            // put first k sum in min heap
			if (minHeap.size() < k) {
				minHeap.push(sum);
			}
			else {
                // now we have k sum in min heap, we will check if current sum is greater than minimum sum in min heap,
                // if yes then we will pop minimum sum and push current sum in min heap
				if (sum > minHeap.top()) {
					minHeap.pop();
					minHeap.push(sum);
				}
			}
		}
	}
	return minHeap.top();
}