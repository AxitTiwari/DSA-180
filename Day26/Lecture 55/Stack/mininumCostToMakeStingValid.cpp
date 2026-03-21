#include <bits/stdc++.h> 
using namespace std;

int findMinimumCost(string str) {
  // Write your code here

    // {{{}
    // s = {{

    // odd length -> return -1
    if (str.length() & 1) {
      return -1;
    }

    stack<char> s;
    for (int i = 0; i < str.length(); i++) {

      char ch = str[i];
      if (ch == '{') {
        s.push(ch);
      }
      else {

        // trim valid wala part 
        if (!s.empty() && s.top() == '{') {
          s.pop();
        }
        else {
          s.push(ch);
        }
      }
    }

    // now stack either contains invalid expression or is empty
    int a = 0, b = 0;
    while (!s.empty()) {

      if (s.top() == '{') {
        b++;
      }
      else {
        a++;
      }
      s.pop();
    }

    int ans = (a+1)/2 + (b+1)/2;
    return ans;
}