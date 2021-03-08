#include <bits/stdc++.h>
using namespace std;

#define INF 1e9

int required_sum = 5000;
vector<int> coins = {3,41,7,11};
int value[5001] = {};

void initialize() {
    for(int i=1; i<=required_sum; i++) {
        value[i] = INF;
        for(auto c : coins) {
            if(i-c>=0) {
                value[i] = min(value[i], value[i-c]+1);
            }
        }
    }
}

int main() {
    initialize();
    cout << "Minimum number of coins required is " << value[required_sum] << "\n";
}
