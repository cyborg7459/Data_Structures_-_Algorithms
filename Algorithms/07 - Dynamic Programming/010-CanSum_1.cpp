// In this version of the problem we can use any of the given weights any number of times. There is no limit

#include <bits/stdc++.h>
using namespace std;

bool isPossible(int sum, vector<int> &weights, vector<int> &dp) {
    if(sum == 0) return true;
    if(sum < 0) return false;
    if(dp[sum] != -1) return dp[sum];
    bool b = false;
    for(int i = 0; i < weights.size(); i++) {
        b = (b || isPossible(sum - weights[i], weights, dp));
        if(b) break;
    }
    dp[sum] = b;
    return b;
}

int main() {
    int n;
    cin >> n;
    vector<int> dp(n+1, -1);
    vector<int> weights = {3,4,5,6};
    if(isPossible(n, weights, dp)) cout << "Yes\n";
    else cout << "No\n";
}
