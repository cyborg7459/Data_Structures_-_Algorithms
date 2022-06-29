// Description: Infix to postfix works on the basis of priorities. It follows a simple rule - an operator can be added on top of other operator only if it is of greater priority. Hence, before pushing
// operator onto the stack, we remove all operators of greater or equal priority that it

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
