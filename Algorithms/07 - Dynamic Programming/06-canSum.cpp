// IMPORTANT : The given implementation has 2 different optimizations - The first one is the basic memoization used in dynamic programming using the map data structure. The second optimization is at the step
// b = b || canSum(...) step. If b is already true by this moment, then by the nature of how OR operator is implemented in C++, the function is not called. This also reduces the number of function calls
// by a large extent

#include <bits/stdc++.h>
using namespace std;

int cnt = 0;
bool canSum(int n, vector<int> &v, map<int, bool>&mp) {
    if(n==0) return true;
    if(n < 0) return false;
    if(mp.find(n) != mp.end()) return mp[n];
    cnt++;
    bool b = false;
    for(auto x : v) {
        b = b || canSum(n-x, v, mp);
    }
    mp[n] = b;
    return b;
}

int main() {
    long long reqSum = 50;
    vector <int> v = {3,4,5,7};
    map<int, bool> mp;
    if(canSum(reqSum, v, mp))
        cout << "Yes";
    else
        cout << "No";
    cout << "\nRecursive calls : " << cnt << "\n";
}
