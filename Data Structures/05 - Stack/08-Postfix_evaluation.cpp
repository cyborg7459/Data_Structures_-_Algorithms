#include <bits/stdc++.h>
using namespace std;

display(stack<int> st) {
    while(!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    cout << "\n";
}

int main() {
    string s;
    cin >> s;
    stack <int> st;
    for(int i=0; i<s.length(); i++) {
        char c = s[i];
        int t = c;
        if(t>47 && t<58)
            st.push(t-48);
        else {
            int b = st.top();
            st.pop();
            int a = st.top();
            st.pop();
            int res{};
            if(c == '+')
                res = a+b;
            else if(c == '-')
                res = a-b;
            else if(c == '*')
                res = a*b;
            else
                res = a/b;
            st.push(res);
        }
    }
    cout << st.top() << "\n";
}
