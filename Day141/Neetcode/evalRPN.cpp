// https://leetcode.com/problems/evaluate-reverse-polish-notation/submissions/2020860363

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:

    bool is_operator(string &token) {

        return token == "+" || token == "-" || token == "*" || token == "/";
    }

    int evaluate(int n1, int n2, string opr) {

        if (opr == "+") return n1 + n2;

        if (opr == "-") return n2 - n1;

        if (opr == "*") return n1 * n2;

        return n2 / n1;
    }

    int convert_to_num(string num) {

        return stoi(num);
    }

public:
    int evalRPN(vector<string>& tokens) {
        
        stack<int> s;
        for (string token : tokens) {

            if (is_operator(token)) {

                int num1 = s.top();
                s.pop();

                int num2 = s.top();
                s.pop();

                int result = evaluate(num1, num2, token);
                s.push(result);

                continue;
            }

            int num = convert_to_num(token);
            s.push(num);
        }
        return s.top();
    }
};