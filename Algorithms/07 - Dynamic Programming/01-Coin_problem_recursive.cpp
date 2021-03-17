#include <bits/stdc++.h>
using namespace std;

#define INF 1000000000

int coinChange(int req_sum, vector<int> coins, map<int, int> &mp) {
    if(mp.find(req_sum) != mp.end()) return mp[req_sum];
    if(req_sum < 0) return INF;
    if(req_sum == 0) return 0;
    int best = INF;
    for(int x : coins) {
        best = min(best, coinChange(req_sum - x, coins, mp) + 1);
    }
    mp.insert({req_sum, best});
    return best;
}

int main() {
    int required_sum = 4;
    map<int, int> mp;
    vector<int> available_coins = {3,5,8};
    int ans = coinChange(required_sum, available_coins, mp);
    if(ans == INF)
        cout << "Given sum is not possible with the coins available";
    else
        cout << "Minimun " << ans << " coins are needed";
}
