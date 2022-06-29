// Question: https://leetcode.com/problems/basic-calculator-ii/
// Explanation: For the given question, we simply need to calculate the postfix expression of the given arithmetic expression and then evaluate. A minor tweak here comes when we have to handle
// numbers having more that single digit. Hence we use $ character to demarcate between individual numbers during creation and then the evaluation of the postfix expression

#include <bits/stdc++.h>
using namespace std;

map<char, int> priority = {{'+', 1}, {'-', 1}, {'/', 2}, {'*', 2}};
int calculate(string s) {
    string postfix = "";
    stack<char> st;
    for(char c : s) {
        if(c == ' ') continue;
        if(priority.find(c) == priority.end()) postfix.push_back(c);
        else {
            postfix.push_back('$');
            while(!st.empty() && priority[st.top()] >= priority[c]) {
                postfix.push_back(st.top());
                st.pop();
            }
            st.push(c);
        }
    }
    postfix.push_back('$');
    while(!st.empty()) {
        postfix.push_back(st.top());
        st.pop();
    }

    stack<int> st1;
    string curnum = "";
    for(char c : postfix) {
        int t = c - '0';
        if(c=='$') {
            int num = stoi(curnum);
            st1.push(num);
            curnum = "";
        }
        else if(t<0 || t>9) {
            int num1 = st1.top();
            st1.pop();
            int num2 = st1.top();
            st1.pop();
            if(c=='/') st1.push(num2/num1);
            else if(c=='*') st1.push(num2*num1);
            else if(c=='+') st1.push(num2+num1);
            else st1.push(num2-num1);
        }
        else curnum.push_back(c);
    }

    return st1.top();
}

int main() {
  string expression = "32+44*29-12";
  int res = calculate(expression);
  cout << res;
}
