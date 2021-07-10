// PS : The filepath is given and our task is to simplify it, i.e. write the shortest path that would end up at the same destination from the same source
// Explanation : For this we need to use stacks. Each string between a pair of / / forms one segment of the path. If this segment is ".", then we need to do nothing because we stay in the same
// directory. If segment is ".." then we need to go one directory back. If stack is not empty, it means we have come from the previus directory, so simply pop the top. Else where, push the segment
// on stack. Now reverse the stack using a second stack, and finally print the strings one after the other with a '/' in between
// We push a '/' at the end of A because we wish to consume a segment at the end of the string (it is not surrounded by the / and would be skipped otherwise)

#include <bits/stdc++.h>
using namespace std;

string solve(string A) {
    A.push_back('/');
    string temp = "", ans;
    stack<string> st;
    for(char c : A) {
        if(c == '/') {
            if(temp.length() > 0) {
                if(temp == ".") {}
                else if(temp == "..") {
                    if(!st.empty()) st.pop();
                }
                else st.push(temp);
            }
            temp = "";
        }
        else {
            temp.push_back(c);
        }
    }
    stack<string> st1;
    while(!st.empty()) {
        st1.push(st.top());
        st.pop();
    }
    while(!st1.empty()) {
        ans.push_back('/');
        ans += st1.top();

        st1.pop();
    }
    if(ans == "") return "/";
    return ans;
}

int main() {
        string s = "..////a/./b/../../c/././././";
        string ans = solve(s);
        cout << ans;
}
