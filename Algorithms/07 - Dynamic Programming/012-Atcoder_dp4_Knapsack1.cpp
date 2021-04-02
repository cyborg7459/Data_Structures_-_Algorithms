#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, capacity;
    cin >> n >> capacity;
    pair<int, long long> weights[n], dp[capacity+1] = {};
    for(int i=0; i<n; i++) {
        int w, v;
        cin >> w >> v;
        weights[i] = {w, v};
    }
    dp[0] = {1, 0};
    for(int i=0; i<n; i++) {
        for(int x = capacity; x>=0; x--) {
            if(dp[x].first == 1 && x + weights[i].first <= capacity) {
                dp[x + weights[i].first].first = 1;
                dp[x + weights[i].first].second = max(dp[x + weights[i].first].second, dp[x].second + weights[i].second);
            }
        }
    }
    long long mx = -1;
    for(int i=0; i<=capacity; i++) {
        // cout << i << " : " << dp[i].first << " , " << dp[i].second << "\n";
        if(dp[i].first == 1)
            mx = max(mx, dp[i].second);
    }
    cout << mx << "\n";
}
