#include <bits/stdc++.h>
using namespace std;

#define INF 1e9

int required_sum = 32;
vector<int> coins = {2,4,5};
int value[35] = {};
int res[35] = {};

int initialize() {
    for(int i=1; i<=required_sum; i++) {
        value[i] = INF;
        for(auto c : coins) {
            if(i-c >= 0 && value[i-c]+1 < value[i]) {
                value[i] = value[i-c] + 1;
                res[i] = c;
            }
        }
    }
}

int main() {
    initialize();
    if(value[required_sum] == INF) cout << "Required sum not possible with the given set of coins\n";
    else {
        cout << value[required_sum] << " coins required for the sum\n";
        int x = required_sum;
        while(res[x] > 0) {
            cout << res[x] << " ";
            x-=res[x];
        }
    }
}
