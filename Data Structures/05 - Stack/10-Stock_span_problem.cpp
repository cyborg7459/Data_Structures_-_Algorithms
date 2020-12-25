#include <bits/stdc++.h>
using namespace std;

vector <int> getSpan(vector<int> v, int n) {
    std::vector<int> res;
    stack<int> st;
    st.push(0);
    res.push_back(1);
    for(int i=1; i<n; i++) {
        while(!st.empty() && v[st.top()] < v[i])
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
