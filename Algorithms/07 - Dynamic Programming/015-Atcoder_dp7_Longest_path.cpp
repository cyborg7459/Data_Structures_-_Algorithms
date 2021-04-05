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

int longestPath(int cur, map<int, vector<int>> &mp, vector<int> &dp) {
	if(mp[cur].size() == 0) return 0;
	if(dp[cur] != -1) return dp[cur];
	int ans = -1;
	loop(i, mp[cur].size()) {
		ans = max(ans, longestPath(mp[cur][i], mp, dp));
	}
	dp[cur] = 1+ans;
	return dp[cur];
}

void solve() {
	int n, m;
	cin >> n >> m;
	map<int, vector<int>> mp;
	vector<int> dp(n+1, -1);
	loop(i, n) mp.insert({i+1, {}});
	loop(i, m) {
		int a, b;
		cin >> a >> b;
		mp[a].pb(b);
	}
	int res = -1;
	loop(i, n) {
		res = max(res, longestPath(i+1, mp, dp));
	}
	o(res);
}

signed main()
{
    fast;
    int q = 1;
//	cin >> q;
    while(q--)
        solve();
}
