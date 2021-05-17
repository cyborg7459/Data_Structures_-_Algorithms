// PS : We have to calculate the maximum length of a valid bracket sequence in a given string
// Solution : Create an extra array which keeps marking the indexes that lie in a valid sequence as 1, and all other elements as zero. At the end we just need to find out the longest continuous
// subsequence of 1s in the array, which is easy to find

#include <bits/stdc++.h>
using namespace std;

int maxLength(string S){
    int n = S.length();
    int arr[n] = {};
    stack<pair<char, int>> st;
    for(int i=0; i<n; i++) {
        char c = S[i];
        if(c == '(')
            st.push({c, i});
        else {
            if(!st.empty()) {
                arr[st.top().second] = 1;
                arr[i] = 1;
                st.pop();
            }
        }
    }
    int ans = 0, cur = 0;
    for(int i=0; i<n; i++) {
        if(arr[i] == 1) cur++;
        else {
            ans = max(ans, cur);
            cur = 0;
        }
    }
    ans = max(ans, cur);
    return ans;
}

int main() {
    string s = "(())(((()))";
    cout << maxLength(s);
}
