#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    stack <char> st;
    map <char, pair<int,int>> mp = {{'+',{1,2}}, {'-',{1,2}}, {'*',{3,4}}, {'/',{3,4}}, {'^', {6,5}}, {'(', {7,0}}, {')', {0, -1}}};
    for(int i=0; i<s.length(); i++) {
        char c = s[i];
        if(mp.find(c)==mp.end())
            cout << c;
        else if(st.empty() || mp[st.top()].second < mp[c].first)
            st.push(c);
        else if(mp[st.top()].second == mp[c].first)
            st.pop();
        else if(mp[st.top()].second > mp[c].first) {
            while(mp[st.top()].second > mp[c].first) {
                cout << st.top();
                st.pop();
                if(st.empty())
                    break;
                else if(mp[st.top()].second == mp[c].first) {
                    st.pop();
                    break;
                }
            }
            if(c != ')')
                st.push(c);
        }
    }
    while(!st.empty()) {
        cout << st.top();
        st.pop();
    }
}
