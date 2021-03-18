#include <bits/stdc++.h>
using namespace std;

void coinChangeCountDistinctSolutions(int req_sum, vector<int> coins, set<int> &done, set<vector<int>> &s, vector<int> &res) {
    if(done.find(req_sum) != done.end()) return;
    if(req_sum < 0) return;
    if(req_sum == 0) {
        sort(res.begin(), res.end());
        s.insert(res);
        return;
    };
    for(int x : coins) {
        res.push_back(x);
        coinChangeCountDistinctSolutions(req_sum - x, coins, done, s, res);
        res.pop_back();
    }
    done.insert(req_sum);
    return;
}

int main() {
    int required_sum = 6;
    vector<int> available_coins = {1,3,4};
    set<int> done;
    vector<int> res;
    set<vector<int>> s;
    coinChangeCountDistinctSolutions(required_sum, available_coins, done, s, res);
    cout << s.size();
}
