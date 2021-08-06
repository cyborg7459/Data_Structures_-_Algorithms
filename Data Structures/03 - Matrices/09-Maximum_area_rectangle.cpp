// PS : Given a binary matrix, find the largest size of rectangle that can be made using only 1s
// Explanation : The given problem can be solved using maximum rectangle area in historgram technique (see this question in stacks). For each row, we assume the elements to be the base of historgram.
// If the element is zero then the height of bar would be zero, else it would be 1 + arr[i-1][j] (We can do this in 1-D array since we operate on rows one at a time)
// Now for each row, apply the histogram area algorithm technique to find the maximum area, and keep maximzing the answer using this max value

#include <bits/stdc++.h>
using namespace std;

int maxArea(int M[500][500], int n, int m) {
    int ans = 0;
    int arr[m] = {};
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(M[i][j] == 0) arr[j] = 0;
            else arr[j]++;
        }
        int l[m], r[m];
        stack<pair<int, int>> st;
        st.push({arr[0], 0});
        for(int j=1; j<m; j++) {
            int num = arr[j];
            while(!st.empty() && st.top().first > num) {
                r[st.top().second] = j;
                st.pop();
            }
            st.push({num, j});
        }
        while(!st.empty()) {
            r[st.top().second] = m;
            st.pop();
        }
        st.push({arr[m-1], m-1});
        for(int j=m-2; j>=0; j--) {
            int num = arr[j];
            while(!st.empty() && st.top().first > num) {
                l[st.top().second] = j;
                st.pop();
            }
            st.push({num, j});
        }
        while(!st.empty()) {
            l[st.top().second] = -1;
            st.pop();
        }
        int sz[m];
        for(int j=0; j<m; j++) {
            sz[j] = arr[j] * (r[j] - l[j] - 1);
            ans = max(ans, sz[j]);
        }
    }
    return ans;
}

int main() {
    int n, m;
    cin >> n >> m;
    int arr[500][500];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }
    cout << maxArea(arr, n, m);
}
