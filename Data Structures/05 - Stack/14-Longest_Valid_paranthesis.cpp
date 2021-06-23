// PS : We have to calculate the maximum length of a valid bracket sequence in a given string
// Solution : Checks the array once from the left, and then from the right for the number of right-opening brackets and the number of left-opening brackets and updating the value
// of ans as soon as a valid sequence is obtained

#include <bits/stdc++.h>
using namespace std;

int maxLength(string s){
    int l=0, r=0;
    int ans = 0;
    for(int i=0; i<s.length(); i++) {
        if(s[i]=='(')
            l++;
        else
            r++;
        if(l == r)
            ans = max(ans, 2*r);
        if(r > l) {
            l = 0;
            r = 0;
        }
    }
    l = 0;
    r = 0;
    for(int i=s.length()-1; i>=0; i--) {
        if(s[i] == '(')
            l++;
        else
            r++;
        if(l == r)
            ans = max(ans, 2*r);
        if(l > r) {
            l = 0;
            r = 0;
        }
    }
    return ans;
}

int main() {
    string s = "(())(((()))";
    cout << maxLength(s);
}
