#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;
    stack <char> st;
    for(int i=0; i<s.length(); i++) {
        if(s[i]=='(')
            st.push('(');
        else if(s[i]==')') {
            if(st.empty()) {
                cout << "Unbalanced\n";
                return 0;
            }
            else {
                st.pop();
            }
        }
    }
    if(st.empty())
        cout << "Balanced\n";
    else
        cout << "Unbalanced\n";;
    return 0;
}
