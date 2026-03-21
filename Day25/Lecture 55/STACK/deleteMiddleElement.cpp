#include <bits/stdc++.h> 
using namespace std;

void solve(stack<int>& inputStack, int count, int size) {

   // middle reached then pop that element and return
   if (count == size/2) {
      inputStack.pop();
      return;
   }

   //strore the element then pop it until middle is reached
   int num = inputStack.top();
   inputStack.pop();

   // call until base case is not activated
   solve(inputStack, count+1, size);

   // backpropogate and push all the reaming upper elements in stack
   inputStack.push(num);
}

void deleteMiddle(stack<int>&inputStack, int N){
	
   // Write your code here
   int count = 0;
   solve(inputStack, count, N);
}