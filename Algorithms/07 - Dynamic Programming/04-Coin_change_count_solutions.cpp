#include <bits/stdc++.h>
using namespace std;

int coinChangeCountSolutions(int req_sum, vector<int> coins, map<int, int> &mp) {
    if(mp.find(req_sum) != mp.end()) return mp[req_sum];
    if(req_sum < 0) return 0;
    if(req_sum == 0) return 1;
    int temp = 0;
    for(int x : coins) {
        temp += coinChangeCountSolutions(req_sum - x, coins, mp);
    }
    mp.insert({req_sum, temp});
    return temp;
}

int main() {
    int required_sum = 17;
    vector<int> available_coins = {2,3,5,7};
    map<int,int> mp;
    cout << coinChangeCountSolutions(required_sum, available_coins, mp);
}
