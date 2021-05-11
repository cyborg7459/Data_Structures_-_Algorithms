#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF 1000000007

int longestPath(int start, map<int, vector<int>> &mp, vector<int> &dp) {
	if(dp[start] != -1) return dp[start];
	if(mp[start].size() == 0) return 1;
	int best = 0;
	for(auto t : mp[start])
		best = max(best, 1 + longestPath(t, mp, dp));
	dp[start] = best;
	return best;
}

signed main()
{
	int n, m;
	cin >> n >> m;
	map <int, vector<int>> mp;
	for(int i=1; i<=n; i++)
		mp.insert({i, {}});
	for(int i=0; i<m; i++) {
		int a, b;
		cin >> a >> b;
		mp[a].push_back(b);
	}
	vector<int> dp(n+1, -1);
	int ans = 0;
	for(int i=1; i<n+1; i++) {
		ans = max(ans, longestPath(i, mp, dp));
	}
	cout << ans-1 << "\n";
}
