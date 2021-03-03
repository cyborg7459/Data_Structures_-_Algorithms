// PROBLEM : Given an array of numbers denoting the stock prices for n days, calculate for each days the number of days immediately preceeding it that have stock prices equal to or less than that of that day
// This problem can be solved using a stack. The first element's stock span value will obviously be 1. Now after that number, for each number we check the stack and keep popping the elements as long as they are lte the
// given number. For this, we store the index in stack and use price[idx] to compare the stock price on day idx. How this helps is that for the suppose we found out stock span for element 4, then elemnt 5 will have surely
// not have stock span value in between the 4th element and the day with stock price greater than 4th. This is because if day 5 price is less then it's answer is 4 only, and if more, then all those elements which were smaller
// than 4 wouldn't have mattered anyway. Hence, the popped off elements are no longer required in any way. Thus, we can solve in O(n)

#include <bits/stdc++.h>
using namespace std;

vector <int> getSpan(vector<int> v, int n) {
    std::vector<int> res;
    stack<int> st;
    st.push(0);
    res.push_back(1);
    for(int i=1; i<n; i++) {
        while(!st.empty() && v[st.top()] <= v[i])
            st.pop();
        if(st.empty())
            res.push_back(i+1);
        else
            res.push_back(i-st.top());
        st.push(i);
    }
    return res;
}

int main() {
    std::vector<int> v = {100, 80, 60, 70, 60, 75, 85};
    std::vector<int> v1 = getSpan(v, v.size());
    for(auto t : v1)
        cout << t << " ";
    cout << "\n";
}
