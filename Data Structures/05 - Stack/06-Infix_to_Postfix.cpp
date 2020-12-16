#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    stack <char> st;
    map <char, int> mp = {{'+',1}, {'-',1}, {'*',2}, {'/',2}};
    for(int i=0; i<s.length(); i++) {
        char c = s[i];
        if(mp.find(c)==mp.end())
            mp[c] = 3;
        if(st.empty() || mp[st.top()]<mp[c])
            st.push(c);
        else if(mp[st.top()] >= mp[c]) {
            while(mp[st.top()] >= mp[c]) {
                cout << st.top();
                st.pop();
                if(st.empty())
                    break;
            }
            st.push(c);
        }
    }
    while(!st.empty()) {
        cout << st.top();
        st.pop();
    }
}
