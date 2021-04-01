// In this version of the problem we can use any of the given weights only 1 time

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
