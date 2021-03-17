#include <bits/stdc++.h>
using namespace std;

#define INF 1000000000

int coinChangeSolution(int req_sum, vector<int> coins, map<int, int> &mp, vector<int> &res) {
    if(mp.find(req_sum) != mp.end()) return mp[req_sum];
    if(req_sum < 0) return INF;
    if(req_sum == 0) return 0;
    int best = INF;
    for(int x : coins) {
        int temp = coinChangeSolution(req_sum-x, coins, mp, res);
        if(temp + 1 < best) {
            res[req_sum] = x;
            best = temp + 1;
        }
    }
    mp.insert({req_sum, best});
    return best;
}

int main() {
    int required_sum = 15;
    vector<int> available_coins = {1,2,5,7,8};
    vector<int> res(required_sum+1, 0);
    map<int, int> mp;
    coinChangeSolution(required_sum, available_coins, mp, res);
    while(res[required_sum] > 0) {
        cout << res[required_sum] << " ";
        required_sum-=res[required_sum];
    }
}
