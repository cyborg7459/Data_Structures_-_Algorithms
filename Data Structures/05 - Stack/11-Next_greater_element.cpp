// Problem : For a given array of numbers, for each number print the next element which is strictly greater than that number, else print -1
// Solution : Store the numbers in a stack, if the stack top is greater than number, push the number into the stack. If it is smaller, it means that that number is the next greater number to the element on the
// stack top, hence save those values in an array or whatever data structure seems suitable. Keep popping as long as the stack top is smaller than that number. At the end, all those numbers which remain in the
// stack will have -1 as the result

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v;
    for(int i=0; i<n; i++) {
        int x;
        cin >> x;
        v.push_back(x);
    }
    stack<pair<int, int>> st;
    vector<pair<pair<int, int>, int>> res;
    for(int i=0; i<n; i++) {
        int num = v[i];
        if(st.empty() || num < st.top().first)
            st.push({num , i});
        else {
            while(!st.empty() && st.top().first < num) {
                pair<int, int> p = st.top();
                st.pop();
                res.push_back({p, num});
            }
            st.push({num, i});
        }
    }
    while(!st.empty()) {
        pair<int, int> p = st.top();
        st.pop();
        res.push_back({p, -1});
    }
    sort(res.begin(), res.end(), [](auto p1, auto p2) {
        return p1.first.second < p2.first.second;
    });
    for(int i=0; i<n; i++)
        cout << res[i].first.first << " : " << res[i].second << "\n";
}
