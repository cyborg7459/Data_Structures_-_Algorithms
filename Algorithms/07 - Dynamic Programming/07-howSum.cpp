#include <bits/stdc++.h>
using namespace std;

int cnt = 0;
bool canSum(int n, vector<int> &v, map<int, bool>&mp, vector<int> &res) {
    res.push_back(n);
    if(n==0) {
        for(int i=0; i<res.size()-1; i++) {
            cout << res[i] - res[i+1] << " ";
        }
        cout << "\n";
        return true;
    }
    if(n < 0) {
        res.pop_back();
        return false;
    }
    if(mp.find(n) != mp.end()) return mp[n];
    cnt++;
    bool b = false;
    for(auto x : v) {
        b = b || canSum(n-x, v, mp, res);
    }
    mp[n] = b;
    res.pop_back();
    return b;
}

int main() {
    long long reqSum = 11;
    vector <int> v = {3,4,5};
    vector <int> res;
    map<int, bool> mp;
    if(canSum(reqSum, v, mp, res))
        cout << "Yes";
    else
        cout << "No";
}
