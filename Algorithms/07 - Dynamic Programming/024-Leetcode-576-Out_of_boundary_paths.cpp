// PS : https://leetcode.com/problems/out-of-boundary-paths/
// Explanation : There is an additional base case of n < 0 because of the limit. Thus, if number of turns remaining is zero and we make another move, then n becomes < 0 and zero is
// returned hence the condition is taken care of. Now the remaining part is simple, if the ball reaches outside, then return 1, else move it in all 4 directions.

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define nl "\n"
#define int long long
#define loop(i,n) for(long long i=0;i<n;i++)
#define print(x) {for(auto t : x)\
                            cout << t << " ";\
                            cout << "\n";}
#define all(x) x.begin(), x.end()
#define o(x) cout << x << "\n"
#define fast ios_base::sync_with_stdio(false);\
                     cin.tie(NULL);
#define INF 1000000007

int findPaths(int i, int j, int r, int c, int n, map<pair<pair<int, int>, int>, long long> &mp) {
	if(n < 0) return 0;
	if(i == r || j == c || i == -1 || j == -1) return 1;
	if(mp.find({{i,j},n}) != mp.end()) return mp[{{i,j}, n}];
	long long ans = 0;
	ans += findPaths(i+1, j, r, c, n-1, mp);
	ans %= INF;
	ans += findPaths(i-1, j, r, c, n-1, mp);
	ans %= INF;
	ans += findPaths(i, j+1, r, c, n-1, mp);
	ans %= INF;
	ans += findPaths(i, j-1, r, c, n-1, mp);
	ans %= INF;
	mp[{{i,j}, n}] = ans;
	return ans;
}

void solve() {
	map<pair<pair<int, int>, int>, long long> mp;
	cout << findPaths(0,0,2,2,2,mp) << nl;
}

signed main()
{
    fast;
    int q = 1;
    while(q--)
        solve();
}
