// In this version of the problem we can use any of the given weights only 1 time. This approach is highly important and is used in the Knapsack problem. What we do here is that for each weight, we
// run a reverse loop over all the possible values of sum (here we'll take only up till n because we don't need larger values). For each weight if we approach a particular sum which is possible without
// using that weight, then that sum + weight would also be possible. We use reverse loop so as to ensure that we do not use the same weight multiple times

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> weights = {3,4,5,6};
    bool possible[n+1] = {0};
    possible[0] = true;
    for(int i=0; i<weights.size(); i++) {
        for(int x = n; x>=0; x--) {
            if(possible[x] && x + weights[i] <= n) possible[x + weights[i]] = true;
        }
    }
    if(possible[n]) cout << "Yes";
    else cout << "No";
}
