#include <bits/stdc++.h>
using namespace std;

bool canSum(int n, vector<int> &v, map<int, bool>&mp, vector<int> &res) {
    if(n==0) {
        for(int i=0; i < res.size(); i++)
            cout << res[i] << " ";
        cout << "\n";
        return true;
    }
    if(n < 0) {
        return false;
    }
    if(mp.find(n) != mp.end()) {
        return mp[n];
    }
    bool b = false;
    for(auto x : v) {
        res.push_back(x);
        b = b || canSum(n-x, v, mp, res);
        res.pop_back();
    }
    mp[n] = b;
    return b;
}

int main() {
    long long reqSum = 10441;
    vector <int> v = {7,4,3};
    vector <int> res;
    map<int, bool> mp;
    if(!canSum(reqSum, v, mp, res))
        cout << "Not possible";
}
