// PS : Given a number, we have to remove 'K' characters in such a way that the number which remains is the minimum possible
// Explanation : The number can be made minimum by minimizing the starting digits (not just the first digit) as much as possible. For that, what we can do is have a stack, and as long as the value
// of K allows, keep popping off larger digits to bring smaller digits into front. We do this at the front because the place value of these digits is higher and minimizing them would have a greater
// effect. After we've traversed through and the value of K is still not zero, then remove the digits from the end, because by now, the remaining number has digits in ascending order and removing from
// the start would increase the value of the number. In the last step, we also have to remove any leading zeroes

#include <bits/stdc++.h>
using namespace std;

string removeKdigits(string S, int K) {
    int n = S.length();
    stack<char> st;
    for(int i=0; i<n; i++) {
        if(K==0 || st.empty() || S[i] > st.top())
            st.push(S[i]);
        else {
            while(K>0 && !st.empty() && S[i] < st.top()) {
                st.pop();
                K--;
            }
            st.push(S[i]);
        }
    }
    while(K--)
        st.pop();
    string res;
    while(!st.empty()) {
        res.push_back(st.top());
        st.pop();
    }
    reverse(res.begin(), res.end());
    while(res.size() > 0 && res[0] == '0')
        res.erase(res.begin());
    if(res.size() == 0)
        return "0";
    return res;
}

int main() {
    cout << removeKdigits("522519284520724558604323249825", 6);
}
