// PS : Given an array, perform the following 2 steps for all k from 1 to n ;-
 // (a) Find out the minimum element in all k-sized windows in the array, where a window consists of k consecutive elements
 // (b) return the maximum element out of these minimum elements

 // Explanation : See notes for explanation

#include <bits/stdc++.h>
using namespace std;

int leftArr[100001];
int rightArr[100001];
int ans[100001];

vector <int> maxOfMin(int arr[], int n) {
    for(int i=0; i<=n; i++) {
        leftArr[i] = 0;
        rightArr[i] = 0;
        ans[i] = 0;
    }

    stack<pair<int, int>> st;
    for(int i=0; i<n; i++) {
        int t = arr[i];
        while(!st.empty() && st.top().first > t) {
            rightArr[st.top().second] = i+1;
            st.pop();
        }
        st.push({t, i});
    }
    while(!st.empty()) {
        rightArr[st.top().second] = n+1;
        st.pop();
    }

    for(int i=n-1; i>=0; i--) {
        int t = arr[i];
        while(!st.empty() && st.top().first > t) {
            leftArr[st.top().second] = i+1;
            st.pop();
        }
        st.push({t, i});
    }
    while(!st.empty()) {
        leftArr[st.top().second] = 0;
        st.pop();
    }

    for(int i=0; i<n; i++) {
        int t = rightArr[i] - leftArr[i] - 1;
        ans[t] = max(ans[t], arr[i]);
    }

    for(int i=n-1; i>=0; i--)
        ans[i] = max(ans[i], ans[i+1]);

    vector<int> res;
    for(int i=1; i<=n; i++) {
        res.push_back(ans[i]);
    }

    return res;

}

int main() {
    int n = 7;
    int arr[7] = {44,22,55,1,99,91,18};
    vector<int> v = maxOfMin(arr, n);
    for(int t : v)
        cout << t << " ";
}
